__asm__ (

".global NWNX_API_START\n"
"NWNX_API_START:\n"
"    nop\n"

#define NWNXLIB_FUNCTION_NO_VERSION_CHECK
#define NWNXLIB_FUNCTION(name, address) \
".global " #name "\n"                   \
#name ":\n"                             \
"movq $0x0000abcd12345678, %rax\n"      \
"addq $" #address ", %rax\n"            \
"pushq %rax\n"                          \
"ret\n"

#include "FunctionsLinux.hpp"

".global NWNX_API_END\n"
"NWNX_API_END:\n"
"    nop\n"

);
