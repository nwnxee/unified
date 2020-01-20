template <typename ... Params>
HooksImpl::ScopedCallbackDispatcher<Params ...>::ScopedCallbackDispatcher(
    const std::vector<uintptr_t>* subscribers,
    Params ... args)
    : m_subscribers(subscribers),
      m_args(std::make_tuple(args ...))
{
    UnpackAndDispatch(true, typename GeneralSequence<sizeof ... (Params)>::SeqType());
}

template <typename ... Params>
HooksImpl::ScopedCallbackDispatcher<Params ...>::~ScopedCallbackDispatcher()
{
    UnpackAndDispatch(false, typename GeneralSequence<sizeof ... (Params)>::SeqType());
}

template <typename ... Params>
template <int ... Seq>
void HooksImpl::ScopedCallbackDispatcher<Params ...>::UnpackAndDispatch(bool before, Sequence<Seq ...>)
{
    return DispatchCallbacks(before, m_subscribers, std::get<Seq>(m_args) ...);
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

template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
Ret HooksImpl::HookLandingHolderShared::HookLanding(FirstParam arg1, Params ... args)
{
    std::vector<uintptr_t>* subs = HooksImpl::template HookLandingHolderDataShared<Address>::s_subs;
    Hooking::FunctionHook* hook = HooksImpl::template HookLandingHolderDataShared<Address>::s_hook;
    ScopedCallbackDispatcher<FirstParam, Params ...> scbd(subs, arg1, args ...);
    return hook->CallOriginal<Ret>(arg1, args ...);
}


template <uintptr_t Address>
uintptr_t HooksImpl::HookLandingHolderDataExclusive<Address>::s_addr;

template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
Ret HooksImpl::HookLandingHolderExclusive::HookLanding(FirstParam arg1, Params ... args)
{
    using FuncPtrType = Ret(*)(FirstParam, Params ...);
    FuncPtrType callback = reinterpret_cast<FuncPtrType>(HooksImpl::template HookLandingHolderDataExclusive<Address>::s_addr);
    return callback(arg1, args ...);
}

template <typename ... Params>
void HooksImpl::DispatchCallbacks(bool before,
    const std::vector<uintptr_t>* subscribers,
    Params ... args)
{
    for (auto& callback : *subscribers)
    {
        using FuncPtrType = void(*)(bool, Params ...);
        FuncPtrType callbackPtr = reinterpret_cast<FuncPtrType>(callback);
        callbackPtr(before, args ...);
    }
}
