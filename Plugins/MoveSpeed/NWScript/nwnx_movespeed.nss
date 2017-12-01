#include "nwnx"

// If value = 1, simulate detect mode in terms of movement speed, e.g. force walk always.
// If value = 0, restore default behaviour.
void NWNX_MoveSpeed_SetSimulateDetectMode(object creature, int value);

// If value = 1, cap walk speed to default 100% speed.
// If value = 0, restore default behaviour.
void NWNX_MoveSpeed_SetCapWalkRate(object creature, int value);

void NWNX_MoveSpeed_SetSimulateDetectMode(object creature, int value)
{
    NWNX_PushArgumentInt("NWNX_MoveSpeed", "SIMULATE_DETECT_MODE", value);
    NWNX_PushArgumentObject("NWNX_MoveSpeed", "SIMULATE_DETECT_MODE", creature);
    NWNX_CallFunction("NWNX_MoveSpeed", "SIMULATE_DETECT_MODE");
}

void NWNX_MoveSpeed_SetCapWalkRate(object creature, int value)
{
    NWNX_PushArgumentInt("NWNX_MoveSpeed", "CAP_WALK_RATE", value);
    NWNX_PushArgumentObject("NWNX_MoveSpeed", "CAP_WALK_RATE", creature);
    NWNX_CallFunction("NWNX_MoveSpeed", "CAP_WALK_RATE");
}
