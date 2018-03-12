#include "Providers/Array.hpp"

using namespace NWNXLib;
using namespace NWNXLib::API;
using namespace NWNXLib::API::Types;
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

Array::Array(EventsProxy& events)
{
    events.RegisterEvent("ARRAY_AT", &Array::OnArrayAt);
    events.RegisterEvent("ARRAY_CLEAR", &Array::OnArrayClear);
    events.RegisterEvent("ARRAY_CONTAINS", &Array::OnArrayContains);
    events.RegisterEvent("ARRAY_COPY", &Array::OnArrayCopy);
    events.RegisterEvent("ARRAY_ERASE", &Array::OnArrayErase);
    events.RegisterEvent("ARRAY_FIND", &Array::OnArrayFind);
    events.RegisterEvent("ARRAY_INSERT", &Array::OnArrayInsert);
    events.RegisterEvent("ARRAY_PUSH_BACK", &Array::OnArrayPushBack);
    events.RegisterEvent("ARRAY_RESIZE", &Array::OnArrayResize);
    events.RegisterEvent("ARRAY_SHUFFLE", &Array::OnArrayShuffle);
    events.RegisterEvent("ARRAY_SIZE", &Array::OnArraySize);
    events.RegisterEvent("ARRAY_SORT_ASCENDING", &Array::OnArraySortAscending);
    events.RegisterEvent("ARRAY_SORT_DESCENDING", &Array::OnArraySortDescending);
}

Events::ArgumentStack Array::OnArrayAt(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    const int32_t index = Events::ExtractArgument<int32_t>(rawArgs);

    Events::ArgumentStack ret;

    switch (args.type)
    {
        case ArrayType::FLOAT: Events::InsertArgument(ret, ArrayImpl<float>::At(args.oid, args.tag, index)); break;
        case ArrayType::INTEGER: Events::InsertArgument(ret, ArrayImpl<int32_t>::At(args.oid, args.tag, index)); break;
        case ArrayType::OBJECT: Events::InsertArgument(ret, ArrayImpl<ObjectID>::At(args.oid, args.tag, index)); break;
        case ArrayType::STRING: Events::InsertArgument(ret, ArrayImpl<std::string>::At(args.oid, args.tag, index)); break;
        default: ASSERT_FAIL(); break;
    }

    return ret;
}

Events::ArgumentStack Array::OnArrayClear(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayContains(Events::ArgumentStack&& rawArgs)
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

    Events::ArgumentStack ret;
    Events::InsertArgument(ret, containsElement ? 1 : 0);
    return ret;
}

Events::ArgumentStack Array::OnArrayCopy(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayErase(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayFind(Events::ArgumentStack&& rawArgs)
{
    const CommonArgs args = ExtractCommonArgs(rawArgs);
    Events::ArgumentStack ret;

    switch (args.type)
    {
        case ArrayType::FLOAT: Events::InsertArgument(ret, ArrayImpl<float>::Find(args.oid, args.tag, Events::ExtractArgument<float>(rawArgs))); break;
        case ArrayType::INTEGER: Events::InsertArgument(ret, ArrayImpl<int32_t>::Find(args.oid, args.tag, Events::ExtractArgument<int32_t>(rawArgs))); break;
        case ArrayType::OBJECT: Events::InsertArgument(ret, ArrayImpl<ObjectID>::Find(args.oid, args.tag, Events::ExtractArgument<ObjectID>(rawArgs))); break;
        case ArrayType::STRING: Events::InsertArgument(ret, ArrayImpl<std::string>::Find(args.oid, args.tag, Events::ExtractArgument<std::string>(rawArgs))); break;
        default: ASSERT_FAIL(); break;
    }

    return ret;
}

Events::ArgumentStack Array::OnArrayInsert(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayPushBack(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayResize(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArrayShuffle(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArraySize(Events::ArgumentStack&& rawArgs)
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

    Events::ArgumentStack ret;
    Events::InsertArgument(ret, size);
    return ret;
}

Events::ArgumentStack Array::OnArraySortAscending(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

Events::ArgumentStack Array::OnArraySortDescending(Events::ArgumentStack&& rawArgs)
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

    return Events::ArgumentStack();
}

}
