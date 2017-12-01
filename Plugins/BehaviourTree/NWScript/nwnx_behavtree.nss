#include "nwnx"

void NWNX_BehaviourTree_CreateBT(object obj, string name, int childId);
void NWNX_BehaviourTree_ClearBT(object obj, string name);
void NWNX_BehaviourTree_TickBT(object obj, string name);

int NWNX_BehaviourTree_CreateCompositeRandomSelector(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1);

int NWNX_BehaviourTree_CreateCompositeRandomSequence(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1);

int NWNX_BehaviourTree_CreateCompositeSelector(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1);

int NWNX_BehaviourTree_CreateCompositeSequence(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1);

int NWNX_BehaviourTree_CreateDecoratorInvert(int childId);

int NWNX_BehaviourTree_CreateLeafAlwaysFail();
int NWNX_BehaviourTree_CreateLeafAlwaysSucceed();
int NWNX_BehaviourTree_CreateLeafSleep(int durationInMs);

int INTERNAL_CallFuncWithVariadicParams(string func,
    int param1,  int param2,  int param3,  int param4,  int param5,  int param6,  int param7,  int param8,
    int param9,  int param10, int param11, int param12, int param13, int param14, int param15, int param16,
    int param17, int param18, int param19, int param20, int param21, int param22, int param23, int param24,
    int param25, int param26, int param27, int param28, int param29, int param30, int param31, int param32);

int INTERNAL_PushAndIncrementIfValid(string func, int param);

void NWNX_BehaviourTree_CreateBT(object obj, string name, int childId)
{
    NWNX_PushArgumentInt("NWNX_BehaviourTree", "CREATE_BT", childId);
    NWNX_PushArgumentString("NWNX_BehaviourTree", "CREATE_BT", name);
    NWNX_PushArgumentObject("NWNX_BehaviourTree", "CREATE_BT", obj);
    NWNX_CallFunction("NWNX_BehaviourTree", "CREATE_BT");
}

void NWNX_BehaviourTree_ClearBT(object obj, string name)
{
    NWNX_PushArgumentString("NWNX_BehaviourTree", "CLEAR_BT", name);
    NWNX_PushArgumentObject("NWNX_BehaviourTree", "CLEAR_BT", obj);
    NWNX_CallFunction("NWNX_BehaviourTree", "CLEAR_BT");
}

void NWNX_BehaviourTree_TickBT(object obj, string name)
{
    NWNX_PushArgumentString("NWNX_BehaviourTree", "TICK_BT", name);
    NWNX_PushArgumentObject("NWNX_BehaviourTree", "TICK_BT", obj);
    NWNX_CallFunction("NWNX_BehaviourTree", "TICK_BT");
}

int NWNX_BehaviourTree_CreateCompositeRandomSelector(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1)
{
    return INTERNAL_CallFuncWithVariadicParams("CREATE_COMPOSITE_RANDOM_SELECTOR",
        child1,  child2,  child3,  child4,  child5,  child6,  child7,  child8,
        child9,  child10, child11, child12, child13, child14, child15, child16,
        child17, child18, child19, child20, child21, child22, child23, child24,
        child25, child26, child27, child28, child29, child30, child31, child32);
}

int NWNX_BehaviourTree_CreateCompositeRandomSequence(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1)
{
    return INTERNAL_CallFuncWithVariadicParams("CREATE_COMPOSITE_RANDOM_SEQUENCE",
        child1,  child2,  child3,  child4,  child5,  child6,  child7,  child8,
        child9,  child10, child11, child12, child13, child14, child15, child16,
        child17, child18, child19, child20, child21, child22, child23, child24,
        child25, child26, child27, child28, child29, child30, child31, child32);
}

int NWNX_BehaviourTree_CreateCompositeSelector(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1)
{
    return INTERNAL_CallFuncWithVariadicParams("CREATE_COMPOSITE_SELECTOR",
        child1,  child2,  child3,  child4,  child5,  child6,  child7,  child8,
        child9,  child10, child11, child12, child13, child14, child15, child16,
        child17, child18, child19, child20, child21, child22, child23, child24,
        child25, child26, child27, child28, child29, child30, child31, child32);
}

int NWNX_BehaviourTree_CreateCompositeSequence(
    int child1,       int child2  = -1, int child3  = -1, int child4  = -1, int child5  = -1, int child6  = -1, int child7  = -1, int child8  = -1,
    int child9  = -1, int child10 = -1, int child11 = -1, int child12 = -1, int child13 = -1, int child14 = -1, int child15 = -1, int child16 = -1,
    int child17 = -1, int child18 = -1, int child19 = -1, int child20 = -1, int child21 = -1, int child22 = -1, int child23 = -1, int child24 = -1,
    int child25 = -1, int child26 = -1, int child27 = -1, int child28 = -1, int child29 = -1, int child30 = -1, int child31 = -1, int child32 = -1)
{
    return INTERNAL_CallFuncWithVariadicParams("CREATE_COMPOSITE_SEQUENCE",
        child1,  child2,  child3,  child4,  child5,  child6,  child7,  child8,
        child9,  child10, child11, child12, child13, child14, child15, child16,
        child17, child18, child19, child20, child21, child22, child23, child24,
        child25, child26, child27, child28, child29, child30, child31, child32);
}

int NWNX_BehaviourTree_CreateDecoratorInvert(int childId)
{
    NWNX_PushArgumentInt("NWNX_BehaviourTree", "CREATE_DECORATOR_INVERT", childId);
    NWNX_CallFunction("NWNX_BehaviourTree", "CREATE_DECORATOR_INVERT");
    return NWNX_GetReturnValueInt("NWNX_BehaviourTree", "CREATE_DECORATOR_INVERT");
}

int NWNX_BehaviourTree_CreateLeafAlwaysFail()
{
    NWNX_CallFunction("NWNX_BehaviourTree", "CREATE_LEAF_ALWAYS_FAIL");
    return NWNX_GetReturnValueInt("NWNX_BehaviourTree", "CREATE_LEAF_ALWAYS_FAIL");
}

int NWNX_BehaviourTree_CreateLeafAlwaysSucceed()
{
    NWNX_CallFunction("NWNX_BehaviourTree", "CREATE_LEAF_ALWAYS_SUCCEED");
    return NWNX_GetReturnValueInt("NWNX_BehaviourTree", "CREATE_LEAF_ALWAYS_SUCCEED");
}

int NWNX_BehaviourTree_CreateLeafSleep(int durationInMs)
{
    NWNX_PushArgumentInt("NWNX_BehaviourTree", "CREATE_LEAF_SLEEP", durationInMs);
    NWNX_CallFunction("NWNX_BehaviourTree", "CREATE_LEAF_SLEEP");
    return NWNX_GetReturnValueInt("NWNX_BehaviourTree", "CREATE_LEAF_SLEEP");
}

int INTERNAL_CallFuncWithVariadicParams(string func,
    int param1,  int param2,  int param3,  int param4,  int param5,  int param6,  int param7,  int param8,
    int param9,  int param10, int param11, int param12, int param13, int param14, int param15, int param16,
    int param17, int param18, int param19, int param20, int param21, int param22, int param23, int param24,
    int param25, int param26, int param27, int param28, int param29, int param30, int param31, int param32)
{
    int count = 0;

    count += INTERNAL_PushAndIncrementIfValid(func, param32);
    count += INTERNAL_PushAndIncrementIfValid(func, param31);
    count += INTERNAL_PushAndIncrementIfValid(func, param30);
    count += INTERNAL_PushAndIncrementIfValid(func, param29);
    count += INTERNAL_PushAndIncrementIfValid(func, param28);
    count += INTERNAL_PushAndIncrementIfValid(func, param27);
    count += INTERNAL_PushAndIncrementIfValid(func, param26);
    count += INTERNAL_PushAndIncrementIfValid(func, param25);
    count += INTERNAL_PushAndIncrementIfValid(func, param24);
    count += INTERNAL_PushAndIncrementIfValid(func, param23);
    count += INTERNAL_PushAndIncrementIfValid(func, param22);
    count += INTERNAL_PushAndIncrementIfValid(func, param21);
    count += INTERNAL_PushAndIncrementIfValid(func, param20);
    count += INTERNAL_PushAndIncrementIfValid(func, param19);
    count += INTERNAL_PushAndIncrementIfValid(func, param18);
    count += INTERNAL_PushAndIncrementIfValid(func, param17);
    count += INTERNAL_PushAndIncrementIfValid(func, param16);
    count += INTERNAL_PushAndIncrementIfValid(func, param15);
    count += INTERNAL_PushAndIncrementIfValid(func, param14);
    count += INTERNAL_PushAndIncrementIfValid(func, param13);
    count += INTERNAL_PushAndIncrementIfValid(func, param12);
    count += INTERNAL_PushAndIncrementIfValid(func, param11);
    count += INTERNAL_PushAndIncrementIfValid(func, param10);
    count += INTERNAL_PushAndIncrementIfValid(func, param9);
    count += INTERNAL_PushAndIncrementIfValid(func, param8);
    count += INTERNAL_PushAndIncrementIfValid(func, param7);
    count += INTERNAL_PushAndIncrementIfValid(func, param6);
    count += INTERNAL_PushAndIncrementIfValid(func, param5);
    count += INTERNAL_PushAndIncrementIfValid(func, param4);
    count += INTERNAL_PushAndIncrementIfValid(func, param3);
    count += INTERNAL_PushAndIncrementIfValid(func, param2);
    count += INTERNAL_PushAndIncrementIfValid(func, param1);

    NWNX_PushArgumentInt("NWNX_BehaviourTree", func, count);
    NWNX_CallFunction("NWNX_BehaviourTree", func);
    return NWNX_GetReturnValueInt("NWNX_BehaviourTree", func);
}

int INTERNAL_PushAndIncrementIfValid(string func, int param)
{
    if (param != -1)
    {
        NWNX_PushArgumentInt("NWNX_BehaviourTree", func, param);
        return 1;
    }

    return 0;
}
