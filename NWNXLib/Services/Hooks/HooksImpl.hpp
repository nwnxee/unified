struct HooksImpl
{
    HooksImpl() = delete;

    static Hooks* g_hooks;

    template<int ...>
    struct Sequence
    {
    };

    template<int N, int ... Seq>
    struct GeneralSequence : GeneralSequence<N - 1, N - 1, Seq ...>
    {
    };

    template<int ... Seq>
    struct GeneralSequence<0, Seq ...>
    {
        using SeqType = Sequence<Seq ...>;
    };

    template <typename ... Params>
    struct ScopedCallbackDispatcher
    {
    public:
        ScopedCallbackDispatcher(const std::vector<uintptr_t>* subscribers, Params ... args);
        ~ScopedCallbackDispatcher();

    private:
        template <int ... Seq>
        void UnpackAndDispatch(bool before, Sequence<Seq ...>);

        const std::vector<uintptr_t>* m_subscribers;
        const std::tuple<Params ...> m_args;
    };

    template <typename>
    struct FuncPtrHelper;

    template <uintptr_t Address>
    struct HookLandingHolderDataShared
    {
        static Hooking::FunctionHook* s_hook;
        static std::vector<uintptr_t>* s_subs;
    };

    struct HookLandingHolderShared
    {
        template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
        static Ret HookLanding(FirstParam arg1, Params ... args);
    };

    template <uintptr_t Address>
    struct HookLandingHolderDataExclusive
    {
        static uintptr_t s_addr;
    };

    struct HookLandingHolderExclusive
    {
        template <uintptr_t Address, typename Ret, typename FirstParam, typename ... Params>
        static Ret HookLanding(FirstParam arg1, Params ... args);
    };

private:
    template <typename ... Params>
    static void DispatchCallbacks(bool before,
        const std::vector<uintptr_t>* subscribers,
        Params ... args);
};

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

