template <typename ... Params>
HooksImpl::ScopedCallbackDispatcher<Params ...>::ScopedCallbackDispatcher(
    const std::vector<uintptr_t>* subscribers,
    Params ... args)
    : m_subscribers(subscribers),
      m_args(std::make_tuple(args ...))
{
    UnpackAndDispatch(Hooks::CallType::BEFORE_ORIGINAL, typename GeneralSequence<sizeof ... (Params)>::SeqType());
}

template <typename ... Params>
HooksImpl::ScopedCallbackDispatcher<Params ...>::~ScopedCallbackDispatcher()
{
    UnpackAndDispatch(Hooks::CallType::AFTER_ORIGINAL, typename GeneralSequence<sizeof ... (Params)>::SeqType());
}

template <typename ... Params>
template <int ... Seq>
void HooksImpl::ScopedCallbackDispatcher<Params ...>::UnpackAndDispatch(Hooks::CallType type, Sequence<Seq ...>)
{
    return DispatchCallbacks(type, m_subscribers, std::get<Seq>(m_args) ...);
}

template <typename Ret, typename ... Params>
struct HooksImpl::FuncPtrHelper<Ret(*)(Params ...)>
{
    using RetType = Ret;
};

template <uintptr_t Address>
Hooking::FunctionHook* HooksImpl::HookLandingHolderDataShared<Address>::s_hook;

template <uintptr_t Address>
std::vector<uintptr_t>* HooksImpl::HookLandingHolderDataShared<Address>::s_subs;

template <>
struct HooksImpl::HookLandingHolderShared<Hooking::CallingConvention::CDecl>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_CDECL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_CDECL(FirstParam arg1, Params ... args))
    {
        std::vector<uintptr_t>* subs = HooksImpl::template HookLandingHolderDataShared<Address>::s_subs;
        Hooking::FunctionHook* hook = HooksImpl::template HookLandingHolderDataShared<Address>::s_hook;
        ScopedCallbackDispatcher<FirstParam, Params ...> scbd(subs, arg1, args ...);
        return hook->CallOriginal<Hooking::CallingConvention::CDecl, Ret>(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderShared<Hooking::CallingConvention::ThisCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_THISCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_THISCALL(FirstParam arg1, Params ... args))
    {
        std::vector<uintptr_t>* subs = HooksImpl::template HookLandingHolderDataShared<Address>::s_subs;
        Hooking::FunctionHook* hook = HooksImpl::template HookLandingHolderDataShared<Address>::s_hook;
        ScopedCallbackDispatcher<FirstParam, Params ...> scbd(subs, arg1, args ...);
        return hook->CallOriginal<Hooking::CallingConvention::ThisCall, Ret>(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderShared<Hooking::CallingConvention::STDCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_STDCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_STDCALL(FirstParam arg1, Params ... args))
    {
        std::vector<uintptr_t>* subs = HooksImpl::template HookLandingHolderDataShared<Address>::s_subs;
        Hooking::FunctionHook* hook = HooksImpl::template HookLandingHolderDataShared<Address>::s_hook;
        ScopedCallbackDispatcher<FirstParam, Params ...> scbd(subs, arg1, args ...);
        return hook->CallOriginal<Hooking::CallingConvention::STDCall, Ret>(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderShared<Hooking::CallingConvention::FastCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_FASTCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_FASTCALL(FirstParam arg1, Params ... args))
    {
        std::vector<uintptr_t>* subs = HooksImpl::template HookLandingHolderDataShared<Address>::s_subs;
        Hooking::FunctionHook* hook = HooksImpl::template HookLandingHolderDataShared<Address>::s_hook;
        ScopedCallbackDispatcher<FirstParam, Params ...> scbd(subs, arg1, args ...);
        return hook->CallOriginal<Hooking::CallingConvention::FastCall, Ret>(arg1, args ...);
    }
};

template <uintptr_t Address>
uintptr_t HooksImpl::HookLandingHolderDataExclusive<Address>::s_addr;

template <>
struct HooksImpl::HookLandingHolderExclusive<Hooking::CallingConvention::CDecl>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_CDECL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_CDECL(FirstParam arg1, Params ... args))
    {
        using FuncPtrType = Ret(*)(FirstParam, Params ...);
        FuncPtrType callback = reinterpret_cast<FuncPtrType>(HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr);
        return callback(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderExclusive<Hooking::CallingConvention::ThisCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_THISCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_THISCALL(FirstParam arg1, Params ... args))
    {
        using FuncPtrType = Ret(*)(FirstParam, Params ...);
        FuncPtrType callback = reinterpret_cast<FuncPtrType>(HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr);
        return callback(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderExclusive<Hooking::CallingConvention::STDCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_STDCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_STDCALL(FirstParam arg1, Params ... args))
    {
        using FuncPtrType = Ret(*)(FirstParam, Params ...);
        FuncPtrType callback = reinterpret_cast<FuncPtrType>(HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr);
        return callback(arg1, args ...);
    }
};

template <>
struct HooksImpl::HookLandingHolderExclusive<Hooking::CallingConvention::FastCall>
{
    template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
    static NWNX_HOOK_LANDING_FASTCALL Ret HookLanding(NWNX_HOOK_LANDING_PARAMETERS_FASTCALL(FirstParam arg1, Params ... args))
    {
        using FuncPtrType = Ret(*)(FirstParam, Params ...);
        FuncPtrType callback = reinterpret_cast<FuncPtrType>(HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr);
        return callback(arg1, args ...);
    }
};

template <typename ... Params>
void HooksImpl::DispatchCallbacks(const Hooks::CallType type,
    const std::vector<uintptr_t>* subscribers,
    Params ... args)
{
    for (auto& callback : *subscribers)
    {
        using FuncPtrType = void(*)(Hooks::CallType, Params ...);
        FuncPtrType callbackPtr = reinterpret_cast<FuncPtrType>(callback);
        callbackPtr(type, args ...);
    }
}
