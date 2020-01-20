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

#include "Services/Hooks/HooksImpl.inl"
