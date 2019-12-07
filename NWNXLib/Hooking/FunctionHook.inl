template <typename Convention, typename Ret, typename ... Params>
typename std::enable_if<std::is_base_of<CallingConvention::CallingConvention, Convention>::value,
Ret>::type FunctionHook::CallOriginal(Params ... args)
{
    using FuncPtrType = decltype(Convention::template PointerValue<Ret, Params ...>());
    FuncPtrType funcPtr = reinterpret_cast<FuncPtrType>(m_trampoline);
    return static_cast<Ret>(funcPtr(args ...));
}
