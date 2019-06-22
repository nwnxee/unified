#pragma once

#include <cstdint>

namespace NWNXLib {

namespace Platform {

namespace Hooking {

#ifdef __GNU_CC
// This stops the provided register from being used in the current compilation unit.
// This may be necessary for hooks to work in high optimization levels (-O2+), otherwise,
// the compiler will, for example, use fcaller-saves and clobber the EBX register,
// thus causing a seg fault when the caller uses it.
#define NO_CLOBBER(REGISTER) register int __no__clobber__##REGISTER asm (#REGISTER)
#endif

// Calling conventions
//   NWNX_HOOK_PLATFORM_* = Calling convention we should use in function pointers to call this type.
//   NWNX_HOOK_POINTER_* = Calling conventions in platform-specific language.
//   NWNX_HOOK_LANDING_* = Calling covention we should use in landing functions for the hook.
#ifdef _WIN32
    #define NWNX_HOOK_PLATFORM_CDECL __cdecl
    #define NWNX_HOOK_PLATFORM_THISCALL __thiscall
    #define NWNX_HOOK_PLATFORM_STDCALL __stdcall
    #define NWNX_HOOK_PLATFORM_FASTCALL __fastcall

    #define NWNX_HOOK_POINTER_CDECL NWNX_HOOK_PLATFORM_CDECL
    #define NWNX_HOOK_POINTER_THISCALL NWNX_HOOK_PLATFORM_THISCALL
    #define NWNX_HOOK_POINTER_STDCALL NWNX_HOOK_PLATFORM_STDCALL
    #define NWNX_HOOK_POINTER_FASTCALL NWNX_HOOK_PLATFORM_FASTCALL

    #define NWNX_HOOK_LANDING_CDECL NWNX_HOOK_PLATFORM_CDECL
    #define NWNX_HOOK_LANDING_THISCALL NWNX_HOOK_PLATFORM_FASTCALL // THISCALL is simulated by using FASTCALL with a dummy EDX parameter.
    #define NWNX_HOOK_LANDING_STDCALL NWNX_HOOK_PLATFORM_STDCALL
    #define NWNX_HOOK_LANDING_FASTCALL NWNX_HOOK_PLATFORM_FASTCALL
#else
    #define NWNX_HOOK_PLATFORM_CDECL //__attribute__((cdecl))
    #define NWNX_HOOK_PLATFORM_THISCALL //__attribute__((thiscall))
    #define NWNX_HOOK_PLATFORM_STDCALL //__attribute__((stdcall))
    #define NWNX_HOOK_PLATFORM_FASTCALL //__attribute__((fastcall))

    #define NWNX_HOOK_POINTER_CDECL NWNX_HOOK_PLATFORM_CDECL
    #define NWNX_HOOK_POINTER_THISCALL NWNX_HOOK_PLATFORM_CDECL // THISCALL is the same as CDECL on Linux.
    #define NWNX_HOOK_POINTER_STDCALL NWNX_HOOK_PLATFORM_STDCALL
    #define NWNX_HOOK_POINTER_FASTCALL NWNX_HOOK_PLATFORM_FASTCALL

    #define NWNX_HOOK_LANDING_CDECL NWNX_HOOK_PLATFORM_CDECL
    #define NWNX_HOOK_LANDING_THISCALL NWNX_HOOK_PLATFORM_CDECL
    #define NWNX_HOOK_LANDING_STDCALL NWNX_HOOK_PLATFORM_STDCALL
    #define NWNX_HOOK_LANDING_FASTCALL NWNX_HOOK_PLATFORM_FASTCALL
#endif
// End calling conventions

// Hook pointers
#define NWNX_HOOK_POINTER_CALL_CDECL(...) __VA_ARGS__

#ifdef _WIN32
    #define NWNX_HOOK_POINTER_CALL_THISCALL(thisPtr, ...) thisPtr, 0, ##__VA_ARGS__
#else
    #define NWNX_HOOK_POINTER_CALL_THISCALL(thisPtr, ...) thisPtr, ##__VA_ARGS__
#endif

#define NWNX_HOOK_POINTER_CALL_STDCALL(...) __VA_ARGS__
#define NWNX_HOOK_POINTER_CALL_FASTCALL(...) __VA_ARGS__
// End parameters

// Parameters
#define NWNX_HOOK_LANDING_PARAMETERS_CDECL(...) __VA_ARGS__

#ifdef _WIN32
    #define NWNX_HOOK_LANDING_PARAMETERS_THISCALL(thisPtr, ...) thisPtr, int, ##__VA_ARGS__
#else
    #define NWNX_HOOK_LANDING_PARAMETERS_THISCALL(thisPtr, ...) thisPtr, ##__VA_ARGS__
#endif

#define NWNX_HOOK_LANDING_PARAMETERS_STDCALL(...) __VA_ARGS__
#define NWNX_HOOK_LANDING_PARAMETERS_FASTCALL(...) __VA_ARGS__
// End parameters

}

}

}
