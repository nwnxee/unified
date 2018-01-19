#pragma once

#include <memory>

namespace NWNXLib {

// A ViewPtr is equivalent to a naked pointer.
// It is constructable from a unique_ptr, shared_ptr, or a naked pointer.
// It makes no promises about the state of the owned pointer.
// This class should be used in place of a naked pointer when the intent
// behind the naked pointer is to allow access to a resource without
// conveying any sort of ownership semantics.

template <typename T>
struct ViewPtr final
{
public:
    ViewPtr() : m_ptr(nullptr) { }
    ViewPtr(T* nakedPtr) : m_ptr(nakedPtr) { }
    ViewPtr(const std::unique_ptr<T>& uniquePtr) : m_ptr(uniquePtr.get()) { }
    ViewPtr(const std::shared_ptr<T>& sharedPtr) : m_ptr(sharedPtr.get()) { }

    bool operator==(const ViewPtr<T>& other) { return m_ptr == other.get(); }
    bool operator==(const T* other) { return m_ptr == other; }
    bool operator!=(const ViewPtr<T>& other) { return m_ptr != other.get(); }
    bool operator!=(const T* other) { return m_ptr != other; }
    operator T*() const { return m_ptr;  }
    operator bool() const { return m_ptr != nullptr; }
    T* operator->() const { return m_ptr; }
    T& operator*() const { return *m_ptr; }
    T** operator&() const { return &m_ptr; }

    T* Get() { return m_ptr; }

private:
    T* m_ptr;
};

}
