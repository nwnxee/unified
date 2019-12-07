#pragma once

namespace NWNXLib {

namespace Hooking {

namespace CallingConvention {


struct CallingConvention
{
};


struct SystemV : public CallingConvention
{
    template <typename Ret, typename ... Params>
    static Ret(* PlatformValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(* PointerValue())(Params ...);

    template <typename Ret, typename ... Params>
    static Ret(* LandingValue())(Params ...);
};

}

}

}
