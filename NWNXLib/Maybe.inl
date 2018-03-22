template <typename T>
Maybe<T>::Maybe()
    : m_hasValue(false), m_data()
{ }

template <typename T>
Maybe<T>::Maybe(T const& data)
    : m_hasValue(true), m_data(data)
{ }

template <typename T>
Maybe<T>::Maybe(T&& data)
    : m_hasValue(true), m_data(std::forward<T>(data))
{ }

template <typename T>
T&& Maybe<T>::Extract()
{
    m_hasValue = false;
    return std::move(m_data);
}

template <typename T>
T&& Maybe<T>::Extract(T&& def)
{
    const bool hadValue = m_hasValue;
    m_hasValue = false;
    return hadValue ? std::move(m_data) : std::forward<T>(def);
}
