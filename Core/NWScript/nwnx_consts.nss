/// @ingroup nwnx
/// @addtogroup consts NWNX Constants
/// @brief Provides various NWScript <-> NWNX Constants Translation Table functions
/// @{
/// @file nwnx_consts.nss

/// @brief Translates ANIMATION_LOOPING_* and ANIMATION_FIREFORGET_* constants to their NWNX equivalent.
/// @param nAnimation The nwn animation constant
/// @return The NWNX equivalent of the constant
int NWNX_Consts_TranslateNWScriptAnimation(int nAnimation);

/// @brief Translates OBJECT_TYPE_* constants to their NWNX equivalent.
/// @param nObjectType The nwn object type
/// @return The NWNX equivalent of the constant
int NWNX_Consts_TranslateNWScriptObjectType(int nObjectType);


int NWNX_Consts_TranslateNWScriptAnimation(int nAnimation)
{
    switch (nAnimation)
    {
        case ANIMATION_LOOPING_PAUSE: nAnimation = 0; break;
        case ANIMATION_LOOPING_PAUSE2: nAnimation = 52; break;
        case ANIMATION_LOOPING_LISTEN: nAnimation = 30; break;
        case ANIMATION_LOOPING_MEDITATE: nAnimation = 32; break;
        case ANIMATION_LOOPING_WORSHIP: nAnimation = 33; break;
        case ANIMATION_LOOPING_LOOK_FAR: nAnimation = 48; break;
        case ANIMATION_LOOPING_SIT_CHAIR: nAnimation = 36; break;
        case ANIMATION_LOOPING_SIT_CROSS: nAnimation = 47; break;
        case ANIMATION_LOOPING_TALK_NORMAL: nAnimation = 38; break;
        case ANIMATION_LOOPING_TALK_PLEADING: nAnimation = 39; break;
        case ANIMATION_LOOPING_TALK_FORCEFUL: nAnimation = 40; break;
        case ANIMATION_LOOPING_TALK_LAUGHING: nAnimation = 41; break;
        case ANIMATION_LOOPING_GET_LOW: nAnimation = 59; break;
        case ANIMATION_LOOPING_GET_MID: nAnimation = 60; break;
        case ANIMATION_LOOPING_PAUSE_TIRED: nAnimation = 57; break;
        case ANIMATION_LOOPING_PAUSE_DRUNK: nAnimation = 58; break;
        case ANIMATION_LOOPING_DEAD_FRONT: nAnimation = 6; break;
        case ANIMATION_LOOPING_DEAD_BACK: nAnimation = 8; break;
        case ANIMATION_LOOPING_CONJURE1: nAnimation = 15; break;
        case ANIMATION_LOOPING_CONJURE2: nAnimation = 16; break;
        case ANIMATION_LOOPING_SPASM: nAnimation = 93; break;
        case ANIMATION_LOOPING_CUSTOM1: nAnimation = 97; break;
        case ANIMATION_LOOPING_CUSTOM2: nAnimation = 98; break;
        case ANIMATION_LOOPING_CUSTOM3: nAnimation = 101; break;
        case ANIMATION_LOOPING_CUSTOM4: nAnimation = 102; break;
        case ANIMATION_LOOPING_CUSTOM5: nAnimation = 103; break;
        case ANIMATION_LOOPING_CUSTOM6: nAnimation = 104; break;
        case ANIMATION_LOOPING_CUSTOM7: nAnimation = 105; break;
        case ANIMATION_LOOPING_CUSTOM8: nAnimation = 106; break;
        case ANIMATION_LOOPING_CUSTOM9: nAnimation = 107; break;
        case ANIMATION_LOOPING_CUSTOM10: nAnimation = 108; break;
        case ANIMATION_LOOPING_CUSTOM11: nAnimation = 109; break;
        case ANIMATION_LOOPING_CUSTOM12: nAnimation = 110; break;
        case ANIMATION_LOOPING_CUSTOM13: nAnimation = 111; break;
        case ANIMATION_LOOPING_CUSTOM14: nAnimation = 112; break;
        case ANIMATION_LOOPING_CUSTOM15: nAnimation = 113; break;
        case ANIMATION_LOOPING_CUSTOM16: nAnimation = 114; break;
        case ANIMATION_LOOPING_CUSTOM17: nAnimation = 115; break;
        case ANIMATION_LOOPING_CUSTOM18: nAnimation = 116; break;
        case ANIMATION_LOOPING_CUSTOM19: nAnimation = 117; break;
        case ANIMATION_LOOPING_CUSTOM20: nAnimation = 118; break;
        case ANIMATION_MOUNT1: nAnimation = 119; break;
        case ANIMATION_DISMOUNT1: nAnimation = 120; break;
        case ANIMATION_FIREFORGET_HEAD_TURN_LEFT: nAnimation = 53; break;
        case ANIMATION_FIREFORGET_HEAD_TURN_RIGHT: nAnimation = 54; break;
        case ANIMATION_FIREFORGET_PAUSE_SCRATCH_HEAD: nAnimation = 55; break;
        case ANIMATION_FIREFORGET_PAUSE_BORED: nAnimation = 56; break;
        case ANIMATION_FIREFORGET_SALUTE: nAnimation = 34; break;
        case ANIMATION_FIREFORGET_BOW: nAnimation = 35; break;
        case ANIMATION_FIREFORGET_STEAL: nAnimation = 37; break;
        case ANIMATION_FIREFORGET_GREETING: nAnimation = 29; break;
        case ANIMATION_FIREFORGET_TAUNT: nAnimation = 28; break;
        case ANIMATION_FIREFORGET_VICTORY1: nAnimation = 44; break;
        case ANIMATION_FIREFORGET_VICTORY2: nAnimation = 45; break;
        case ANIMATION_FIREFORGET_VICTORY3: nAnimation = 46; break;
        case ANIMATION_FIREFORGET_READ: nAnimation = 71; break;
        case ANIMATION_FIREFORGET_DRINK: nAnimation = 70; break;
        case ANIMATION_FIREFORGET_DODGE_SIDE: nAnimation = 90; break;
        case ANIMATION_FIREFORGET_DODGE_DUCK: nAnimation = 91; break;
        case ANIMATION_FIREFORGET_SPASM: nAnimation = 23; break;
        default: nAnimation = 0; break;
    }

    return nAnimation;
}

int NWNX_Consts_TranslateNWScriptObjectType(int nObjectType)
{
    switch(nObjectType)
    {
        case OBJECT_TYPE_ALL: nObjectType = 0; break;
        case OBJECT_TYPE_AREA_OF_EFFECT: nObjectType = 11; break;
        case OBJECT_TYPE_CREATURE: nObjectType = 5; break;
        case OBJECT_TYPE_DOOR: nObjectType = 10; break;
        case OBJECT_TYPE_ENCOUNTER: nObjectType = 13; break;
        case OBJECT_TYPE_ITEM: nObjectType = 6; break;
        case OBJECT_TYPE_PLACEABLE: nObjectType = 9; break;
        case OBJECT_TYPE_STORE: nObjectType = 14; break;
        case OBJECT_TYPE_TRIGGER: nObjectType = 7; break;
        case OBJECT_TYPE_WAYPOINT: nObjectType = 12; break;
        default: nObjectType = 0; break;
    }

    return nObjectType;
}
/// @} // End of consts
