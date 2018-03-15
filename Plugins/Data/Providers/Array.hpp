#pragma once

#include "API/Types.hpp"
#include "Common.hpp"
#include "Services/Events/Events.hpp"
#include <algorithm>
#include <string>
#include <random>
#include <unordered_map>
#include <vector>

namespace Data {

template <typename T>
class ArrayImpl
{
public:
    static T At(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, const int32_t index);
    static void Clear(const NWNXLib::API::Types::ObjectID oid, const std::string& tag);
    static int32_t Contains(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, const T& element);
    static void Copy(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, const std::string& otherTag);
    static void Erase(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, int32_t index);
    static int32_t Find(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, T&& element);
    static void Insert(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, int32_t index, T&& element);
    static void PushBack(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, T&& element);
    static void Resize(const NWNXLib::API::Types::ObjectID oid, const std::string& tag, int32_t size);
    static void Shuffle(const NWNXLib::API::Types::ObjectID oid, const std::string& tag);
    static int32_t Size(const NWNXLib::API::Types::ObjectID oid, const std::string& tag);
    static void SortAscending(const NWNXLib::API::Types::ObjectID oid, const std::string& tag);
    static void SortDescending(const NWNXLib::API::Types::ObjectID oid, const std::string& tag);

private:
    // Maps from object -> { array tag, vector }.
    static std::unordered_map<NWNXLib::API::Types::ObjectID, std::unordered_map<std::string, std::vector<T>>> m_store;
};

class Array
{
public:
    Array(NWNXLib::Services::EventsProxy& events);

private:
    static NWNXLib::Services::Events::ArgumentStack OnArrayAt(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayClear(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayContains(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayCopy(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayErase(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayFind(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayInsert(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayPushBack(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayResize(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArrayShuffle(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArraySize(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArraySortAscending(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack OnArraySortDescending(NWNXLib::Services::Events::ArgumentStack&& args);

    friend class ArrayImpl<float>;
    friend class ArrayImpl<int32_t>;
    friend class ArrayImpl<NWNXLib::API::Types::ObjectID>;
    friend class ArrayImpl<std::string>;
};

#include "Providers/Array.inl"

}
