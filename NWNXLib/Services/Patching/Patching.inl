template <typename Ret, typename ... Params>
void PatchingProxy::PatchWithCall(const uintptr_t address, const uintptr_t toFill, Ret(*funcPtr)(Params ...))
{
    PatchWithCall(address, toFill, reinterpret_cast<uintptr_t>(funcPtr));
}

template <typename ... Params>
void PatchingProxy::PatchWithInstructions(const uintptr_t address, Params ... args)
{
    Patch(address, Platform::Assembly::ChainOperationsFromAddr(address, args ...));
}

template <typename ... Params>
void PatchingProxy::PatchWithInstructionsTrampoline(const uintptr_t address, const uintptr_t toFill,
    Params ... args)
{
    PatchWithTrampoline(address, toFill, Platform::Assembly::ChainOperationsFromAddr(address, args ...));
}

template <typename T>
void PatchingProxy::PatchWithValue(const uintptr_t address, const T& value)
{
    std::vector<uint8_t> data;
    data.resize(sizeof(T));
    memcpy(data.data(), &value, sizeof(T));
    Patch(address, std::move(data));
}
