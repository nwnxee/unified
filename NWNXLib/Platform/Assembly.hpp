#pragma once

#include <cstdint>
#include <vector>

namespace NWNXLib {

namespace Platform {

namespace Assembly {

enum class Register
{
    EAX = 0,
    EBX = 3,
    ECX = 1,
    EDX = 2,
    ESI = 6,
    EDI = 7,
    EBP = 5,
    ESP = 4
};

// An operation describes something that can be converted to assembly.
// This could be an instruction, e.g. 'push ebx'. It could also be an alias, e.g. 'push nth argument'.
struct IOperation
{
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address) const = 0;
};

// An instruction maps 1:1 with assembly instructions.
struct IInstruction : public IOperation
{
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address) const = 0;
};

// 'ADD reg, value8'
struct AddRegImmByteInstruction final : public IInstruction
{
    AddRegImmByteInstruction(const Register reg, const uint8_t value = 0) : m_register(reg), m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const uint8_t m_value;
};

// 'ADD reg, value32'
struct AddRegImmDwordInstruction final : public IInstruction
{
    AddRegImmDwordInstruction(const Register reg, const uint32_t value = 0) : m_register(reg), m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const uint32_t m_value;
};

// 'CALL address'
struct CallRelInstruction final : public IInstruction
{
    CallRelInstruction(const uintptr_t address) : m_address(address) { }

    template <typename Ret, typename ... Params>
    CallRelInstruction(Ret(*func)(Params ...)) : m_address(reinterpret_cast<uintptr_t>(func)) { }

    virtual std::vector<uint8_t> ToBytes(const uintptr_t address) const override;

private:
    const uintptr_t m_address;
};

// 'JMP address'
struct JmpRelInstruction final : public IInstruction
{
    JmpRelInstruction(const uintptr_t address) : m_address(address) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address) const override;

private:
    const uintptr_t m_address;
};

// 'MOV destination, source'
struct MovRegRegInstruction final : public IInstruction
{
    MovRegRegInstruction(const Register destination, const Register source) : m_destination(destination), m_source(source) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_destination;
    const Register m_source;
};

// 'MOV destination, [source]'
struct MovRegRegMemInstruction final : public IInstruction
{
    MovRegRegMemInstruction(const Register destination, const Register source) : m_destination(destination), m_source(source) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_destination;
    const Register m_source;
};

// 'MOV destination, value'
struct MovRegImmInstruction final : public IInstruction
{
    MovRegImmInstruction(const Register destination, const uint32_t value) : m_destination(destination), m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_destination;
    const uint32_t m_value;
};

// 'NOOP'
struct NoopInstruction final : public IInstruction
{
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;
};

// 'POP eax'
struct PopRegInstruction final : public IInstruction
{
    PopRegInstruction(const Register reg) : m_register(reg) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
};

// 'PUSH value'
struct PushImmInstruction final : public IInstruction
{
    PushImmInstruction(const uint32_t value) : m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const uint32_t m_value;
};

// 'PUSH eax'
struct PushRegInstruction final : public IInstruction
{
    PushRegInstruction(const Register reg) : m_register(reg) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
};

// 'PUSH [eax + offset8]'
struct PushRegMemByteInstruction final : public IInstruction
{
    PushRegMemByteInstruction(const Register reg, const int8_t offset = 0) : m_register(reg), m_offset(offset) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const int8_t m_offset;
};

// 'PUSH [eax + offset32]'
struct PushRegMemDwordInstruction final : public IInstruction
{
    PushRegMemDwordInstruction(const Register reg, const int32_t offset = 0) : m_register(reg), m_offset(offset) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const int32_t m_offset;
};

// 'RET'
struct RetInstruction final : public IInstruction
{
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;
};

// 'SUB reg, value8'
struct SubRegImmByteInstruction final : public IInstruction
{
    SubRegImmByteInstruction(const Register reg, const uint8_t value = 0) : m_register(reg), m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const uint8_t m_value;
};

// 'SUB reg, value32'
struct SubRegImmDwordInstruction final : public IInstruction
{
    SubRegImmDwordInstruction(const Register reg, const uint32_t value = 0) : m_register(reg), m_value(value) { }
    virtual std::vector<uint8_t> ToBytes(const uintptr_t address = 0) const override;

private:
    const Register m_register;
    const uint32_t m_value;
};

template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> ChainOperations(First first, Second second, Params ... args);

template <typename First>
std::vector<uint8_t> ChainOperationsFromAddr(const uintptr_t address, First first);

template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> ChainOperationsFromAddr(const uintptr_t address, First first, Second second, Params ... args);

void CorrectRelativeAddresses(const uintptr_t address, const uintptr_t originalAddress, const uintptr_t length);
uintptr_t GetSmallestLengthToFitInstruction(const uintptr_t address, const uintptr_t instLen);
void RewriteGCCThunks(uint8_t* data, uintptr_t originalAddress, uintptr_t length);

#include "Assembly.inl"

}

}

}
