#pragma once

#include <utility>

namespace NWNXLib {

template <typename T>
class Maybe
{
public:
    explicit Maybe();
    explicit Maybe(T const& data);
    explicit Maybe(T&& data);

    Maybe(Maybe<T>&& other) = default;
    Maybe<T>& operator=(Maybe<T>&& other) = default;

    // Delete these -- we can't copy.
    Maybe(Maybe<T>& other) = delete;
    Maybe<T>& operator=(Maybe<T> const& other) = delete;

    T&& Extract();
    T&& Extract(T&& def);

    const T& operator*() const { return m_data; }
    const T* operator->() const { return &m_data; }
    operator bool() const { return m_hasValue; }

private:
    bool m_hasValue;
    T m_data;
};

#include "Maybe.inl"

}
