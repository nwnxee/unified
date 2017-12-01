#include "Hooking/FunctionHook.hpp"
#include "Platform/Assembly.hpp"
#include "Platform/Memory.hpp"
#include <cassert>
#include <cstring>

namespace NWNXLib {

namespace Hooking {

using namespace NWNXLib::Platform;

FunctionHook::FunctionHook(const std::string& hookName, uintptr_t originalFunction,
    uintptr_t newFunction)
    : FunctionHook(hookName, originalFunction, newFunction,
        Assembly::GetSmallestLengthToFitInstruction(originalFunction, MIN_RET_SIZE))
{
}

FunctionHook::FunctionHook(const std::string& hookName, uintptr_t originalFunction,
    uintptr_t newFunction, const RetSizeType length)
    : m_oldFunction(), m_trampoline(), m_length(length)
{
    assert(m_length >= MIN_RET_SIZE && m_length < MAX_LENGTH);

    m_info.hookName = hookName;
    m_info.originalAddr = originalFunction;
    m_info.newAddr = newFunction;

    CopyOriginal();
    ConstructTrampoline();
    Hook();
}

FunctionHook::~FunctionHook()
{
    Restore();
}

uintptr_t FunctionHook::OldFunction() const
{
    return reinterpret_cast<uintptr_t>(m_oldFunction.data());
}

uintptr_t FunctionHook::Trampoline() const
{
    return reinterpret_cast<uintptr_t>(m_trampoline.data());
}

const FunctionHook::Info& FunctionHook::HookInfo() const
{
    return m_info;
}

void FunctionHook::Hook() const
{
    Memory::ProtectAddress(m_info.originalAddr, MAX_LENGTH, Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
    HookFast();
    Memory::ProtectAddress(m_info.originalAddr, MAX_LENGTH, Memory::MemoryProtectionFlags::READ_EXECUTE);
}

void FunctionHook::HookFast() const
{
    auto assembly = Assembly::ChainOperations(Assembly::PushImmInstruction(m_info.newAddr), Assembly::RetInstruction());
    memcpy(reinterpret_cast<uint8_t*>(m_info.originalAddr), assembly.data(), assembly.size());
}

void FunctionHook::Restore() const
{
    Memory::ProtectAddress(m_info.originalAddr, MAX_LENGTH, Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
    RestoreFast();
    Memory::ProtectAddress(m_info.originalAddr, MAX_LENGTH, Memory::MemoryProtectionFlags::READ_EXECUTE);
}

void FunctionHook::RestoreFast() const
{
    // Copy the original function back to where it was.
    memcpy(reinterpret_cast<void*>(m_info.originalAddr), m_oldFunction.data(), MIN_RET_SIZE);
}

void FunctionHook::CopyOriginal()
{
    memcpy(m_oldFunction.data(), reinterpret_cast<uint8_t*>(m_info.originalAddr), m_length);
}

void FunctionHook::ConstructTrampoline()
{
    // Copy the old function into the trampline.
    std::copy(m_oldFunction.begin(), m_oldFunction.end(), m_trampoline.begin());

    // Correct relative addresses.
    Assembly::CorrectRelativeAddresses(reinterpret_cast<uintptr_t>(m_trampoline.data()), m_info.originalAddr, TRAMPOLINE_SIZE);

    // Generate the assembly.
    auto assembly = Assembly::ChainOperations(Assembly::PushImmInstruction(m_info.originalAddr + m_length), Assembly::RetInstruction());

    // Copy the push / ret into the trampoline.
    std::copy(assembly.begin(), assembly.end(), m_trampoline.begin() + m_length);

    // We'll set the trampoline page to executable.
    Memory::ProtectAddress(reinterpret_cast<uintptr_t>(m_trampoline.data()), MAX_LENGTH, Memory::MemoryProtectionFlags::READ_WRITE_EXECUTE);
}

}

}
