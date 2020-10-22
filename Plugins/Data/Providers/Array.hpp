#pragma once

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
    static T At(const ObjectID oid, const std::string& tag, const int32_t index);
    static void Clear(const ObjectID oid, const std::string& tag);
    static int32_t Contains(const ObjectID oid, const std::string& tag, const T& element);
    static void Copy(const ObjectID oid, const std::string& tag, const std::string& otherTag);
    static void Erase(const ObjectID oid, const std::string& tag, int32_t index);
    static int32_t Find(const ObjectID oid, const std::string& tag, T&& element);
    static void Insert(const ObjectID oid, const std::string& tag, int32_t index, T&& element);
    static void PushBack(const ObjectID oid, const std::string& tag, T&& element);
    static void Resize(const ObjectID oid, const std::string& tag, int32_t size);
    static void Shuffle(const ObjectID oid, const std::string& tag);
    static int32_t Size(const ObjectID oid, const std::string& tag);
    static void SortAscending(const ObjectID oid, const std::string& tag);
    static void SortDescending(const ObjectID oid, const std::string& tag);
    static void Set(const ObjectID oid, const std::string& tag, int32_t index, T&& element);

private:
    // Maps from object -> { array tag, vector }.
    static std::unordered_map<ObjectID, std::unordered_map<std::string, std::vector<T>>> m_store;
};

class Array
{
public:
    Array(NWNXLib::Services::EventsProxy& events);

private:
    static NWNXLib::Services::Events::ArgumentStack ArrayAt(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayClear(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayContains(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayCopy(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayErase(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayFind(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayInsert(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayPushBack(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayResize(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArrayShuffle(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArraySize(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArraySortAscending(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArraySortDescending(NWNXLib::Services::Events::ArgumentStack&& args);
    static NWNXLib::Services::Events::ArgumentStack ArraySet(NWNXLib::Services::Events::ArgumentStack&& args);

    friend class ArrayImpl<float>;
    friend class ArrayImpl<int32_t>;
    friend class ArrayImpl<ObjectID>;
    friend class ArrayImpl<std::string>;
};

#include "Providers/Array.inl"

}
