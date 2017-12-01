template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> ChainOperations(First first, Second second, Params ... args)
{
    return ChainOperationsFromAddr<First, Second, Params ...>(0, first, second, args ...);
}

template <typename First>
std::vector<uint8_t> ChainOperationsFromAddr(const uintptr_t address, First first)
{
    return first.ToBytes(address);
}

template <typename First, typename Second, typename ... Params>
std::vector<uint8_t> ChainOperationsFromAddr(const uintptr_t address, First first, Second second, Params ... args)
{
    auto firstData = ChainOperationsFromAddr<First>(address, first);
    auto othersData = ChainOperationsFromAddr<Second, Params ...>(address + firstData.size(), second, args ...);
    firstData.insert(std::end(firstData), std::begin(othersData), std::end(othersData));
    return firstData;
}
