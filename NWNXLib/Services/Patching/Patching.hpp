#pragma once

#include "Platform/Assembly.hpp"
#include "Services/Services.hpp"
#include <cstdint>
#include <cstring>
#include <vector>

namespace NWNXLib {

namespace Services {

class Patching : public ServiceBase
{
public: // Structures
    struct PatchData
    {
        uintptr_t m_address;
        uintptr_t m_length;
        std::vector<uint8_t> m_original;
        std::vector<uint8_t> m_modified;
        std::vector<uint8_t> m_trampoline;
    };

    struct RegistrationToken
    {
        uintptr_t m_address;
        uintptr_t m_length;
    };

public:
    Patching();
    ~Patching();

    // Patches data.size() with the provided data.
    RegistrationToken Patch(const uintptr_t address, std::vector<uint8_t> data);

    // Patches the address with a jmp to a trampoline which contains data.
    // Fills after five bytes (until the next instruction has been reached) up to toFill to noops.
    // After the patch has been executed, a jmp is inserted back to the end of the patch.
    RegistrationToken PatchWithTrampoline(const uintptr_t address, const uintptr_t toFill, std::vector<uint8_t> data);

    void ClearPatch(RegistrationToken&& token);

private:
    std::vector<std::unique_ptr<PatchData>> m_memoryPatches;

    RegistrationToken ApplyPatch(std::unique_ptr<PatchData>&& data);
    void WriteDataToAddress(const uintptr_t address, const std::vector<uint8_t>& data);
};

class PatchingProxy : public ServiceProxy<Patching>
{
public:
    PatchingProxy(Patching& Patching);
    ~PatchingProxy();

    void Patch(const uintptr_t address, const std::vector<uint8_t>& data);
    void PatchWithTrampoline(const uintptr_t address, const uintptr_t toFill, const std::vector<uint8_t>& data);
    void PatchWithNoop(const uintptr_t address, const uintptr_t toFill);
    void PatchWithJmp(const uintptr_t address, const uintptr_t toFill, const uintptr_t targetAddress);

    void PatchWithCall(const uintptr_t address, const uintptr_t toFill, const uintptr_t targetAddress);

    template <typename Ret, typename ... Params>
    void PatchWithCall(const uintptr_t address, const uintptr_t toFill, Ret(*funcPtr)(Params ...));

    template <typename ... Params>
    void PatchWithInstructions(const uintptr_t address, Params ... args);

    template <typename ... Params>
    void PatchWithInstructionsTrampoline(const uintptr_t address, const uintptr_t toFill, Params ... args);

    template <typename T>
    void PatchWithValue(const uintptr_t address, const T& value);

    bool PatchExists(const uintptr_t address);
    void ClearPatch(const uintptr_t address);

private:
    std::vector<Patching::RegistrationToken> m_registrationTokens;

    std::vector<uint8_t> GetNoopToFill(const uintptr_t length);
};

#include "Services/Patching/Patching.inl"

}

}
