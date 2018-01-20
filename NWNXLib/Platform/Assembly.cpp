#include "Platform/Assembly.hpp"
#include "API/Version.hpp"
#include "Platform/ASLR.hpp"
#include "External/BeaEngine/include/BeaEngine.h"
#include <cassert>
#include <cstring>
#include <unordered_map>

namespace {

uintptr_t CalculateRelativeAddress(const uintptr_t from, const uintptr_t to, const uintptr_t instSize)
{
    return to + (0xFFFFFFFF - (from + instSize)) + 1;
}

}

namespace NWNXLib {

namespace Platform {

namespace Assembly {

std::vector<uint8_t> AddRegImmByteInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x83; // ADD r32, imm8
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_register);
    return { opcode, extended, m_value };
}

std::vector<uint8_t> AddRegImmDwordInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x81; // ADD r32, imm32
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    encoded[0] = opcode;
    encoded[1] = extended;
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> CallRelInstruction::ToBytes(const uintptr_t address) const
{
    const uint8_t opcode = 0xE8; // CALL near relative
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    const uintptr_t relAddress = CalculateRelativeAddress(address, m_address, 5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &relAddress, 4);
    return encoded;
}

std::vector<uint8_t> JmpRelInstruction::ToBytes(const uintptr_t address) const
{
    const uint8_t opcode = 0xE9; // JMP near relative
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    const uintptr_t relAddress = CalculateRelativeAddress(address, m_address, 5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &relAddress, 4);
    return encoded;
}

std::vector<uint8_t> MovRegRegInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x89; // MOV r32, r32
    const uint8_t extended = 0xC0 + static_cast<uint8_t>(m_destination) + (static_cast<uint8_t>(m_source) * 8);
    return { opcode, extended };
}

std::vector<uint8_t> MovRegRegMemInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x8B; // MOV r32, r/m32
    const uint8_t extended = (static_cast<uint8_t>(m_destination) * 8) + static_cast<uint8_t>(m_source);
    return { opcode, extended };
}

std::vector<uint8_t> MovRegImmInstruction::ToBytes(const uintptr_t address) const
{
    const uint8_t opcode = 0xB8 + static_cast<uint8_t>(m_destination); // MOV r32, imm32
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> NoopInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x90; // NOOP
    return { opcode };
}

std::vector<uint8_t> PushImmInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x68; // PUSH imm32
    std::vector<uint8_t> encoded;
    encoded.resize(5);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &m_value, 4);
    return encoded;
}

std::vector<uint8_t> PopRegInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x58 /* PUSH r32 */ + static_cast<uint8_t>(m_register);
    return { opcode };
}

std::vector<uint8_t> PushRegInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x50 /* PUSH r32 */ + static_cast<uint8_t>(m_register);
    return { opcode };
}

std::vector<uint8_t> PushRegMemByteInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0xFF; // PUSH r/m32
    const uint8_t extended = 0x70 + static_cast<uint8_t>(m_register);
    return { opcode, extended, *reinterpret_cast<const uint8_t*>(&m_offset) };
}

std::vector<uint8_t> PushRegMemDwordInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0xFF; // PUSH r/m32
    const uint8_t extended = 0xB0 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_offset, 4);
    return encoded;
}

std::vector<uint8_t> RetInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0xC3; // RET
    return { opcode };
}

std::vector<uint8_t> SubRegImmByteInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x83; // SUB r32, imm8
    const uint8_t extended = 0xE8 + static_cast<uint8_t>(m_register);
    return { opcode, extended, m_value };
}

std::vector<uint8_t> SubRegImmDwordInstruction::ToBytes(const uintptr_t) const
{
    const uint8_t opcode = 0x81; // SUB r32, imm32
    const uint8_t extended = 0xE8 + static_cast<uint8_t>(m_register);
    std::vector<uint8_t> encoded;
    encoded.resize(6);
    memcpy(encoded.data(), &opcode, 1);
    memcpy(encoded.data() + 1, &extended, 1);
    memcpy(encoded.data() + 2, &m_value, 4);
    return encoded;
}

void CorrectRelativeAddresses(const uintptr_t address, const uintptr_t originalAddress, const uintptr_t length)
{
    assert(length > 0);

    DISASM disassembler = {};
    disassembler.EIP = address;
    disassembler.VirtualAddr = originalAddress;

    uintptr_t bytesChecked = 0;

    while (bytesChecked < length)
    {
        const int len = Disasm(&disassembler);

        if (len == OUT_OF_BLOCK || len == UNKNOWN_OPCODE || len < 0)
        {
            break;
        }

        const uintptr_t lengthChecked = static_cast<uintptr_t>(len);

        static constexpr uint8_t RELATIVE_CALL = 0xE8;
        static constexpr uint8_t RELATIVE_SHORT_JMP = 0xEB;
        static constexpr uint8_t RELATIVE_JMP = 0xE9;

        switch (disassembler.Instruction.Opcode)
        {
            case RELATIVE_CALL:
            case RELATIVE_JMP:
            {
                uint32_t* offsetAddr = reinterpret_cast<uint32_t*>(address + bytesChecked + 1);
                uintptr_t originalOffset;
                memcpy(&originalOffset, offsetAddr, 4);
                const uintptr_t targetAddress = originalAddress + bytesChecked + lengthChecked + originalOffset;
                const uintptr_t trampolineAddress = reinterpret_cast<uintptr_t>(address + bytesChecked + lengthChecked);
                const uintptr_t newAddress = targetAddress + (0xFFFFFFFF - trampolineAddress) + 1;
                memcpy(offsetAddr, &newAddress, 4);
                break;
            }

            case RELATIVE_SHORT_JMP:
            {
                assert(false); // No short jmp support yet!
                break;
            }
        }

        bytesChecked += lengthChecked;
        disassembler.EIP += lengthChecked;
        disassembler.VirtualAddr += lengthChecked;
    }
}

uintptr_t GetSmallestLengthToFitInstruction(const uintptr_t address, const uintptr_t instLen)
{
    assert(instLen > 0);

    DISASM disassembler = {};
    disassembler.EIP = address;

    uintptr_t bytesChecked = 0;

    while (true)
    {
        const int len = Disasm(&disassembler);

        if (len == OUT_OF_BLOCK || len == UNKNOWN_OPCODE || len < 0)
        {
            return 0;
        }

        const uintptr_t lengthChecked = static_cast<uintptr_t>(len);

        bytesChecked += lengthChecked;

        if (bytesChecked >= instLen)
        {
            return bytesChecked;
        }

        disassembler.EIP += lengthChecked;
    }
}

void RewriteGCCThunks(uint8_t* data, uintptr_t originalAddress, uintptr_t length)
{
    assert(length > 0);

    std::unordered_map<uintptr_t, Register> thunkMap =
    {
        { ASLR::GetRelocatedGlobalAddress(0x0002F825), Register::EAX }, // __x86_get_pc_thunk_ax
        { ASLR::GetRelocatedGlobalAddress(0x000276A0), Register::EBX }, // __x86_get_pc_thunk_bx
        { ASLR::GetRelocatedGlobalAddress(0x0004AC5F), Register::ECX }, // __x86_get_pc_thunk_cx
        { ASLR::GetRelocatedGlobalAddress(0x0003AFC1), Register::EDX }, // __x86_get_pc_thunk_dx
        { ASLR::GetRelocatedGlobalAddress(0x0004AE6B), Register::ESI }, // __x86_get_pc_thunk_si
        { ASLR::GetRelocatedGlobalAddress(0x0005E17E), Register::EDI }  // __x86_get_pc_thunk_di
    }; NWNX_EXPECT_VERSION(8155);

    DISASM disassembler = {};
    disassembler.EIP = reinterpret_cast<uintptr_t>(data);

    uintptr_t bytesChecked = 0;

    while (bytesChecked < length)
    {
        const int len = Disasm(&disassembler);

        if (len == OUT_OF_BLOCK || len == UNKNOWN_OPCODE || len < 0)
        {
            break;
        }

        const uintptr_t lengthChecked = static_cast<uintptr_t>(len);

        static constexpr uint8_t RELATIVE_CALL = 0xE8;

        if (disassembler.Instruction.Opcode == RELATIVE_CALL)
        {
            assert(lengthChecked == 5);

            // The address to the argument of the call instruction.
            uint8_t* offsetAddr = (data + bytesChecked + 1);

            uintptr_t location;
            memcpy(&location, offsetAddr, sizeof(uintptr_t));

            // It's a relative (to next inst) call, so let's account for that.
            location += reinterpret_cast<uintptr_t>(data) + lengthChecked + 1;

            auto thunkRegister = thunkMap.find(location);
            if (thunkRegister != std::end(thunkMap))
            {
                // We're calling a thunk, so replace with a move.
                uintptr_t nextInstAddr = originalAddress + bytesChecked + lengthChecked;
                auto assembly = MovRegImmInstruction(thunkRegister->second, nextInstAddr).ToBytes();
                assert(assembly.size() == 5);

                memcpy(data + bytesChecked, assembly.data(), lengthChecked);
            }
        }

        bytesChecked += lengthChecked;
        disassembler.EIP += lengthChecked;
    }
}

}

}

}
