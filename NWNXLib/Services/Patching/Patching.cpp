#include "Services/Patching/Patching.hpp"
#include "Platform/ASLR.hpp"
#include "Platform/Memory.hpp"

#include <algorithm>

using namespace NWNXLib::Platform;

namespace NWNXLib {

namespace Services {

Patching::Patching()
{
}

Patching::~Patching()
{
    for (auto& patch : m_memoryPatches)
    {
        WriteDataToAddress(patch->m_address, patch->m_original);
    }
}

Patching::RegistrationToken Patching::Patch(const uintptr_t address, std::vector<uint8_t> data)
{
    std::unique_ptr<PatchData> newPatch = std::make_unique<PatchData>();
    newPatch->m_address = address;
    newPatch->m_length = data.size();
    newPatch->m_original.resize(newPatch->m_length);
    uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(address);
    memcpy(newPatch->m_original.data(), reinterpret_cast<void*>(aslrAddress), newPatch->m_length);
    newPatch->m_modified = std::move(data);
    return ApplyPatch(std::move(newPatch));
}

Patching::RegistrationToken Patching::PatchWithTrampoline(const uintptr_t address, const uintptr_t toFill,
    std::vector<uint8_t> data)
{
    static constexpr uintptr_t JMP_LENGTH = 5;
    const uintptr_t patchLen = data.size();

    std::unique_ptr<PatchData> newPatch = std::make_unique<PatchData>();
    newPatch->m_address = address;
    ASSERT(toFill >= JMP_LENGTH);
    newPatch->m_length = toFill;
    newPatch->m_original.resize(newPatch->m_length);

    uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(address);
    memcpy(newPatch->m_original.data(), reinterpret_cast<void*>(aslrAddress), newPatch->m_length);

    newPatch->m_trampoline = std::move(data);
    newPatch->m_trampoline.resize(patchLen + JMP_LENGTH);
    const uintptr_t trampolineAddr = reinterpret_cast<uintptr_t>(newPatch->m_trampoline.data());

    // Set the trampoline to executable.
    Memory::ProtectAddress(trampolineAddr, newPatch->m_trampoline.size(), Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);

    // We've relocated the patch into the trampoline, so let's correct any relative calls which might now be wrong.
    // TODO: This might be wrong. It might need to be address - aslrAddress or the other way around.
    Assembly::CorrectRelativeAddresses(trampolineAddr, aslrAddress, patchLen);

    // Now insert a jmp into the end of the trampoline back to the next free code segment.
    auto jumpBack = Assembly::JmpRelInstruction(newPatch->m_address + newPatch->m_length).ToBytes(trampolineAddr + patchLen);
    memcpy(newPatch->m_trampoline.data() + patchLen, jumpBack.data(), JMP_LENGTH);

    data = Assembly::JmpRelInstruction(trampolineAddr).ToBytes(newPatch->m_address);

    while (data.size() < newPatch->m_length)
    {
        // Fill the rest with noops. This isn't strictly necessary but makes it easier to debug.
        auto noop = Assembly::NoopInstruction().ToBytes();
        data.insert(std::end(data), std::begin(noop), std::end(noop));
    }

    newPatch->m_modified = std::move(data);
    return ApplyPatch(std::move(newPatch));
}

void Patching::ClearPatch(RegistrationToken&& token)
{
    auto patch = std::find_if(std::begin(m_memoryPatches), std::end(m_memoryPatches),
        [&token](const auto& data) -> bool
        {
            return data->m_address == token.m_address && data->m_length == token.m_length;
        }
    );

    if (patch == std::end(m_memoryPatches))
    {
        throw std::runtime_error("Invalid or duplicate patch registration token.");
    }

    WriteDataToAddress((*patch)->m_address, (*patch)->m_original);
    LOG_DEBUG("Cleared patch at address %x", (*patch)->m_address);
    m_memoryPatches.erase(patch);
}

Patching::RegistrationToken Patching::ApplyPatch(std::unique_ptr<PatchData>&& patchData)
{
    const uintptr_t address = patchData->m_address;
    const uintptr_t length = patchData->m_length;

    // So, this one is kinda tricky.
    // We need to determine whether the range address -> address + data.size()
    // exists in a vector of ranges m_address -> m_address + m_length.
    // I think the easiest way to do this, for our purposes, is to enforce that m_memoryPatches
    // is always sorted by address, then we can locate the lowest address which could contain
    // our range, then explore upwards until we're outwith that possible range.
    // A binary search would be fastest for this, but I'm too lazy for that, so it'll just be a linear one.
    for (size_t i = 0; i < m_memoryPatches.size(); ++i)
    {
        PatchData& existingPatch = *m_memoryPatches[i];
        const uintptr_t newStartAddress = address;
        const uintptr_t newEndAddress = newStartAddress + length;
        const uintptr_t existingStartAddress = existingPatch.m_address;
        const uintptr_t existingEndAddress = existingStartAddress + existingPatch.m_length;

        if (newEndAddress < existingStartAddress)
        {
            continue; // We can't overlap this one yet.
        }

        if (existingStartAddress > newEndAddress)
        {
            break; // It isn't possible (since we're sorted) to overlap any more.
        }

        const bool overlapStart = newStartAddress >= existingStartAddress && newStartAddress <= existingEndAddress;
        const bool overlapEnd = newEndAddress >= existingStartAddress && newEndAddress <= existingEndAddress;

        if (overlapStart || overlapEnd)
        {
            throw std::runtime_error("Tried to apply a patch to a memory location which is already patched!");
        }
    }

    WriteDataToAddress(address, patchData->m_modified);
    LOG_DEBUG("Applied patch to address %x", address);
    m_memoryPatches.emplace_back(std::move(patchData));

    std::sort(std::begin(m_memoryPatches), std::end(m_memoryPatches),
        [](const auto& first, const auto& second)
        {
            return first->m_address < second->m_address;
        }
    );

    return { address, length };
}

void Patching::WriteDataToAddress(const uintptr_t address, const std::vector<uint8_t>& data)
{
    uintptr_t aslrAddress = Platform::ASLR::GetRelocatedAddress(address);
    Memory::ProtectAddress(aslrAddress, data.size(), Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
    memcpy(reinterpret_cast<void*>(aslrAddress), data.data(), data.size());
    Memory::ProtectAddress(aslrAddress, data.size(), Memory::MemoryProtectionFlags::READ_EXECUTE);
}

PatchingProxy::PatchingProxy(Patching& patching)
    : ServiceProxy<Patching>(patching)
{
}

PatchingProxy::~PatchingProxy()
{
    for (Patching::RegistrationToken& token : m_registrationTokens)
    {
        m_proxyBase.ClearPatch(std::move(token));
    }
}

void PatchingProxy::Patch(const uintptr_t address, const std::vector<uint8_t>& data)
{
    m_registrationTokens.emplace_back(m_proxyBase.Patch(address, data));
}

void PatchingProxy::PatchWithTrampoline(const uintptr_t address, const uintptr_t toFill, const std::vector<uint8_t>& data)
{
    m_registrationTokens.emplace_back(m_proxyBase.PatchWithTrampoline(address, toFill, data));
}

void PatchingProxy::PatchWithNoop(const uintptr_t address, const uintptr_t toFill)
{
    Patch(address, GetNoopToFill(toFill));
}

void PatchingProxy::PatchWithJmp(const uintptr_t address, const uintptr_t toFill, const uintptr_t targetAddress)
{
    std::vector<uint8_t> jmp = Assembly::JmpRelInstruction(targetAddress).ToBytes(address);

    const intptr_t noopLen = static_cast<intptr_t>(toFill) - static_cast<intptr_t>(jmp.size());
    ASSERT(noopLen >= 0);

    if (noopLen > 0)
    {
        std::vector<uint8_t> noop = GetNoopToFill(static_cast<uint32_t>(noopLen));
        jmp.insert(std::end(jmp), std::begin(noop), std::end(noop));
    }

    Patch(address, std::move(jmp));
}

void PatchingProxy::PatchWithCall(const uintptr_t address, const uintptr_t toFill, const uintptr_t targetAddress)
{
    std::vector<uint8_t> call = Assembly::CallRelInstruction(targetAddress).ToBytes(address);

    const intptr_t noopLen = static_cast<intptr_t>(toFill) - static_cast<intptr_t>(call.size());
    ASSERT(noopLen >= 0);

    if (noopLen > 0)
    {
        std::vector<uint8_t> noop = GetNoopToFill(static_cast<uint32_t>(noopLen));
        call.insert(std::end(call), std::begin(noop), std::end(noop));
    }

    Patch(address, std::move(call));
}

bool PatchingProxy::PatchExists(const uintptr_t address)
{
    auto token = std::find_if(std::begin(m_registrationTokens), std::end(m_registrationTokens),
        [address](const auto& check)
        {
            return check.m_address == address;
        }
    );

    return token != std::end(m_registrationTokens);
}

void PatchingProxy::ClearPatch(const uintptr_t address)
{
    auto token = std::find_if(std::begin(m_registrationTokens), std::end(m_registrationTokens),
        [address](const auto& check)
        {
            return check.m_address == address;
        }
    );

    if (token == std::end(m_registrationTokens))
    {
        throw std::runtime_error("Tried to clear a patch at an unpatched address.");
    }

    m_proxyBase.ClearPatch(std::move(*token));
    m_registrationTokens.erase(token);
}

std::vector<uint8_t> PatchingProxy::GetNoopToFill(const uint32_t length)
{
    ASSERT(length > 0);

    std::vector<uint8_t> noop = Assembly::NoopInstruction().ToBytes();
    ASSERT(noop.size() == 1);

    if (length > 1)
    {
        noop.resize(length);
        std::fill(std::begin(noop) + 1, std::end(noop), noop[0]);
    }

    return noop;
}

}

}
