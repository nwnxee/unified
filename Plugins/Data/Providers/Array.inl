template <typename T>
std::unordered_map<ObjectID, std::unordered_map<std::string, std::vector<T>>> ArrayImpl<T>::m_store;

template <typename T>
T ArrayImpl<T>::At(const ObjectID oid, const std::string& tag, const int32_t index)
{
    std::vector<T>& collection = m_store[oid][tag];

    const int32_t size = static_cast<int32_t>(collection.size());
      ASSERT_OR_THROW(index < size);
      ASSERT_OR_THROW(index >= 0);

    return collection[static_cast<size_t>(index)];
}

template <typename T>
void ArrayImpl<T>::Clear(const ObjectID oid, const std::string& tag)
{
    m_store[oid][tag].clear();
}

template <typename T>
int32_t ArrayImpl<T>::Contains(const ObjectID oid, const std::string& tag, const T& element)
{
    std::vector<T>& collection = m_store[oid][tag];
    return std::find(std::begin(collection), std::end(collection), element) != std::end(collection) ? 1 : 0;
}

template <typename T>
void ArrayImpl<T>::Copy(const ObjectID oid, const std::string& tag, const std::string& otherTag)
{
    m_store[oid][tag] = m_store[oid][otherTag];
}

template <typename T>
void ArrayImpl<T>::Erase(const ObjectID oid, const std::string& tag, int32_t index)
{
    std::vector<T>& collection = m_store[oid][tag];
      ASSERT_OR_THROW(index < static_cast<int32_t>(collection.size()));
    collection.erase(std::begin(collection) + index);
}

template <typename T>
int32_t ArrayImpl<T>::Find(const ObjectID oid, const std::string& tag, T&& element)
{
    std::vector<T>& collection = m_store[oid][tag];
    auto elem = std::find(std::begin(collection), std::end(collection), element);
    return elem != std::end(collection) ? elem - std::begin(collection) : -1;
}

template <typename T>
void ArrayImpl<T>::Insert(const ObjectID oid, const std::string& tag, int32_t index, T&& element)
{
    std::vector<T>& collection = m_store[oid][tag];
      ASSERT_OR_THROW(index >= 0);
      ASSERT_OR_THROW(index <= static_cast<int32_t>(collection.size()));
    collection.insert(std::begin(collection) + index, std::forward<T>(element));
}

template <typename T>
void ArrayImpl<T>::PushBack(const ObjectID oid, const std::string& tag, T&& element)
{
    m_store[oid][tag].push_back(std::forward<T>(element));
}

template <typename T>
void ArrayImpl<T>::Resize(const ObjectID oid, const std::string& tag, int32_t size)
{
      ASSERT_OR_THROW(size >= 0);
    m_store[oid][tag].resize(static_cast<size_t>(size));
}

template <typename T>
void ArrayImpl<T>::Shuffle(const ObjectID oid, const std::string& tag)
{
    static auto rng = std::default_random_engine(std::random_device{}());
    std::vector<T>& collection = m_store[oid][tag];
    std::shuffle(std::begin(collection), std::end(collection), rng);
}

template <typename T>
int32_t ArrayImpl<T>::Size(const ObjectID oid, const std::string& tag)
{
    return static_cast<int32_t>(m_store[oid][tag].size());
}

template <typename T>
void ArrayImpl<T>::SortAscending(const ObjectID oid, const std::string& tag)
{
    std::vector<T>& collection = m_store[oid][tag];
    std::sort(std::begin(collection), std::end(collection));
}

template <typename T>
void ArrayImpl<T>::SortDescending(const ObjectID oid, const std::string& tag)
{
    std::vector<T>& collection = m_store[oid][tag];
    std::sort(std::rbegin(collection), std::rend(collection));
}

template <typename T>
void ArrayImpl<T>::Set(const ObjectID oid, const std::string& tag, int32_t index, T&& element)
{
    std::vector<T>& collection = m_store[oid][tag];
      ASSERT_OR_THROW(index >= 0);
      ASSERT_OR_THROW(index < static_cast<int32_t>(collection.size()));
    collection[static_cast<size_t>(index)] = std::forward<T>(element);
}
