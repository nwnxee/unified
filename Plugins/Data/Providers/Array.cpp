#include "Providers/Array.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::Services;

namespace Data {

enum class ArrayType
{
    FLOAT = 0,
    INTEGER,
    OBJECT,
    STRING
};

struct CommonArgs
{
    ArrayType type;
    ObjectID oid;
    std::string tag;
};

CommonArgs ExtractCommonArgs(Events::ArgumentStack& args)
{
    ArrayType type = static_cast<ArrayType>(Events::ExtractArgument<int32_t>(args));
    ObjectID oid = Events::ExtractArgument<ObjectID>(args);
    std::string tag = Events::ExtractArgument<std::string>(args);
    return { std::move(type), std::move(oid), std::move(tag) };
}

Array::Array()
{
    Events::RegisterEvent("NWNX_Data", "ArrayAt", &Array::ArrayAt);
    Events::RegisterEvent("NWNX_Data", "ArrayClear", &Array::ArrayClear);
    Events::RegisterEvent("NWNX_Data", "ArrayContains", &Array::ArrayContains);
    Events::RegisterEvent("NWNX_Data", "ArrayCopy", &Array::ArrayCopy);
    Events::RegisterEvent("NWNX_Data", "ArrayErase", &Array::ArrayErase);
    Events::RegisterEvent("NWNX_Data", "ArrayFind", &Array::ArrayFind);
    Events::RegisterEvent("NWNX_Data", "ArrayInsert", &Array::ArrayInsert);
    Events::RegisterEvent("NWNX_Data", "ArrayPushBack", &Array::ArrayPushBack);
    Events::RegisterEvent("NWNX_Data", "ArrayResize", &Array::ArrayResize);
    Events::RegisterEvent("NWNX_Data", "ArrayShuffle", &Array::ArrayShuffle);
    Events::RegisterEvent("NWNX_Data", "ArraySize", &Array::ArraySize);
    Events::RegisterEvent("NWNX_Data", "ArraySortAscending", &Array::ArraySortAscending);
    Events::RegisterEvent("NWNX_Data", "ArraySortDescending", &Array::ArraySortDescending);
    Events::RegisterEvent("NWNX_Data", "ArraySet", &Array::ArraySet);
}

Events::ArgumentStack Array::ArrayAt(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t index = Events::ExtractArgument<int32_t>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT:   return Events::Arguments(ArrayImpl<float>::At(args.oid, args.tag, index));
        case ArrayType::INTEGER: return Events::Arguments(ArrayImpl<int32_t>::At(args.oid, args.tag, index));
        case ArrayType::OBJECT:  return Events::Arguments(ArrayImpl<ObjectID>::At(args.oid, args.tag, index));
        case ArrayType::STRING:  return Events::Arguments(ArrayImpl<std::string>::At(args.oid, args.tag, index));
        default: ASSERT_FAIL();  return Events::Arguments();
    }

}

Events::ArgumentStack Array::ArrayClear(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Clear(args.oid, args.tag); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Clear(args.oid, args.tag); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Clear(args.oid, args.tag); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Clear(args.oid, args.tag); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayContains(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    bool containsElement = false;

    switch (args.type)
    {
        case ArrayType::FLOAT: containsElement = ArrayImpl<float>::Contains(args.oid, args.tag, Events::ExtractArgument<float>(rawArgs)); break;
        case ArrayType::INTEGER: containsElement = ArrayImpl<int32_t>::Contains(args.oid, args.tag, Events::ExtractArgument<int32_t>(rawArgs)); break;
        case ArrayType::OBJECT: containsElement = ArrayImpl<ObjectID>::Contains(args.oid, args.tag, Events::ExtractArgument<ObjectID>(rawArgs)); break;
        case ArrayType::STRING: containsElement = ArrayImpl<std::string>::Contains(args.oid, args.tag, Events::ExtractArgument<std::string>(rawArgs)); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments(containsElement ? 1 : 0);
}

Events::ArgumentStack Array::ArrayCopy(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    std::string otherTag = Events::ExtractArgument<std::string>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Copy(args.oid, args.tag, std::move(otherTag)); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Copy(args.oid, args.tag, std::move(otherTag)); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Copy(args.oid, args.tag, std::move(otherTag)); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Copy(args.oid, args.tag, std::move(otherTag)); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayErase(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t index = Events::ExtractArgument<int32_t>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Erase(args.oid, args.tag, index); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Erase(args.oid, args.tag, index); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Erase(args.oid, args.tag, index); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Erase(args.oid, args.tag, index); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayFind(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT:   return Events::Arguments(ArrayImpl<float>::Find(args.oid, args.tag, Events::ExtractArgument<float>(rawArgs)));
        case ArrayType::INTEGER: return Events::Arguments(ArrayImpl<int32_t>::Find(args.oid, args.tag, Events::ExtractArgument<int32_t>(rawArgs)));
        case ArrayType::OBJECT:  return Events::Arguments(ArrayImpl<ObjectID>::Find(args.oid, args.tag, Events::ExtractArgument<ObjectID>(rawArgs)));
        case ArrayType::STRING:  return Events::Arguments(ArrayImpl<std::string>::Find(args.oid, args.tag, Events::ExtractArgument<std::string>(rawArgs)));
        default: ASSERT_FAIL();  return Events::Arguments();
    }
}

Events::ArgumentStack Array::ArrayInsert(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t index = Events::ExtractArgument<int32_t>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Insert(args.oid, args.tag, index, Events::ExtractArgument<float>(rawArgs)); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Insert(args.oid, args.tag, index, Events::ExtractArgument<int32_t>(rawArgs)); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Insert(args.oid, args.tag, index, Events::ExtractArgument<ObjectID>(rawArgs)); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Insert(args.oid, args.tag, index, Events::ExtractArgument<std::string>(rawArgs)); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayPushBack(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::PushBack(args.oid, args.tag, Events::ExtractArgument<float>(rawArgs)); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::PushBack(args.oid, args.tag, Events::ExtractArgument<int32_t>(rawArgs)); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::PushBack(args.oid, args.tag, Events::ExtractArgument<ObjectID>(rawArgs)); break;
        case ArrayType::STRING: ArrayImpl<std::string>::PushBack(args.oid, args.tag, Events::ExtractArgument<std::string>(rawArgs)); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayResize(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t size = Events::ExtractArgument<int32_t>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Resize(args.oid, args.tag, size); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Resize(args.oid, args.tag, size); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Resize(args.oid, args.tag, size); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Resize(args.oid, args.tag, size); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArrayShuffle(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Shuffle(args.oid, args.tag); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Shuffle(args.oid, args.tag); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Shuffle(args.oid, args.tag); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Shuffle(args.oid, args.tag); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArraySize(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    int32_t size = 0;

    switch (args.type)
    {
        case ArrayType::FLOAT: size = ArrayImpl<float>::Size(args.oid, args.tag); break;
        case ArrayType::INTEGER: size = ArrayImpl<int32_t>::Size(args.oid, args.tag); break;
        case ArrayType::OBJECT: size = ArrayImpl<ObjectID>::Size(args.oid, args.tag); break;
        case ArrayType::STRING: size = ArrayImpl<std::string>::Size(args.oid, args.tag); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments(size);
}

Events::ArgumentStack Array::ArraySortAscending(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::SortAscending(args.oid, args.tag); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::SortAscending(args.oid, args.tag); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::SortAscending(args.oid, args.tag); break;
        case ArrayType::STRING: ArrayImpl<std::string>::SortAscending(args.oid, args.tag); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArraySortDescending(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::SortDescending(args.oid, args.tag); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::SortDescending(args.oid, args.tag); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::SortDescending(args.oid, args.tag); break;
        case ArrayType::STRING: ArrayImpl<std::string>::SortDescending(args.oid, args.tag); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

Events::ArgumentStack Array::ArraySet(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t index = Events::ExtractArgument<int32_t>(rawArgs);

    switch (args.type)
    {
        case ArrayType::FLOAT: ArrayImpl<float>::Set(args.oid, args.tag, index, Events::ExtractArgument<float>(rawArgs)); break;
        case ArrayType::INTEGER: ArrayImpl<int32_t>::Set(args.oid, args.tag, index, Events::ExtractArgument<int32_t>(rawArgs)); break;
        case ArrayType::OBJECT: ArrayImpl<ObjectID>::Set(args.oid, args.tag, index, Events::ExtractArgument<ObjectID>(rawArgs)); break;
        case ArrayType::STRING: ArrayImpl<std::string>::Set(args.oid, args.tag, index, Events::ExtractArgument<std::string>(rawArgs)); break;
        default: ASSERT_FAIL(); break;
    }

    return Events::Arguments();
}

}
