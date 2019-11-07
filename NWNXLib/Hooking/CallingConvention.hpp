#pragma once

#include "Platform/Hooking.hpp"

namespace NWNXLib {

namespace Hooking {

namespace CallingConvention {

// platformValue == I want a function pointer that calls this convention.
// pointerValue  == I want a function pointer that calls this convention while
//                  allowing me to fully specify all parameters.
// landingValue  == I want a function pointer that points to an acceptable
//                  landing function for this type while allowing me to fully
//                  specify all parameters.

struct CallingConvention
{
};

struct CDecl : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_PLATFORM_CDECL * PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_POINTER_CDECL * PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_LANDING_CDECL * LandingValue())(Params ...);
};

struct ThisCall : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_PLATFORM_THISCALL * PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_POINTER_THISCALL * PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_LANDING_THISCALL * LandingValue())(Params ...);
};

struct STDCall : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_PLATFORM_STDCALL * PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_POINTER_STDCALL * PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_LANDING_STDCALL * LandingValue())(Params ...);
};

struct FastCall : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_PLATFORM_FASTCALL * PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_POINTER_FASTCALL * PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_LANDING_FASTCALL * LandingValue())(Params ...);
};

struct SystemV : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_PLATFORM_SYSTEMV * PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_POINTER_SYSTEMV * PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(NWNX_HOOK_LANDING_SYSTEMV * LandingValue())(Params ...);
};

}

}

}
