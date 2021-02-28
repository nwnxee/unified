#pragma once

#include "nwnx.hpp"
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
    Array();

private:
    static NWNXLib::Events::ArgumentStack ArrayAt(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayClear(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayContains(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayCopy(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayErase(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayFind(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayInsert(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayPushBack(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayResize(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArrayShuffle(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArraySize(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArraySortAscending(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArraySortDescending(NWNXLib::Events::ArgumentStack&& args);
    static NWNXLib::Events::ArgumentStack ArraySet(NWNXLib::Events::ArgumentStack&& args);

    friend class ArrayImpl<float>;
    friend class ArrayImpl<int32_t>;
    friend class ArrayImpl<ObjectID>;
    friend class ArrayImpl<std::string>;
};

#include "Providers/Array.inl"

}
