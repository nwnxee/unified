#include "Hooking/FunctionHook.hpp"
#include "Assert.hpp"
#include "External/subhook/subhook.h"
#include <Zycore/Types.h>
#include <Zydis/Zydis.h>
#include <Zycore/Status.h>
namespace NWNXLib {

namespace Hooking {

using namespace NWNXLib::Platform;

int FunctionHook::ZydisDisassemble(void *src, int *reloc_op_offset)
{
    ZydisDecoder decoder;
    ZydisDecoderInit(&decoder, ZYDIS_MACHINE_MODE_LONG_64, ZYDIS_ADDRESS_WIDTH_64);

    ZyanUSize offset = 0;
    const ZyanUSize length = 16;
    ZydisDecodedInstruction instruction;
    if (ZYAN_SUCCESS(ZydisDecoderDecodeBuffer(&decoder, (const ZyanU8*)src + offset,
                                        length - offset, &instruction)))
    {
        if (reloc_op_offset != nullptr && instruction.attributes & ZYDIS_ATTRIB_IS_RELATIVE)
        {
            *reloc_op_offset = instruction.length + 1;
        }
        return instruction.length;
    }
    return 0;
}

FunctionHook::FunctionHook(uintptr_t originalFunction, uintptr_t newFunction)
{
    subhook_set_disasm_handler(ZydisDisassemble);
    m_subhook = subhook_new((void*)originalFunction, (void*)newFunction, SUBHOOK_64BIT_OFFSET);
    ASSERT(m_subhook);
    subhook_install(m_subhook);
    m_trampoline = subhook_get_trampoline(m_subhook);
    ASSERT(m_trampoline);
}

FunctionHook::~FunctionHook()
{
    subhook_remove(m_subhook);
    subhook_free(m_subhook);
}

}

}
