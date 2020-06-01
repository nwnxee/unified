#include "nwnx_visibility"
#include "nwnx_test"

void main()
{
    while (TEST("Visibility"))
    {
        ASSERT(IS_TRUE(NWNX_Test_PluginExists("NWNX_Visibility")));

        object oCreature = CreateObject(OBJECT_TYPE_CREATURE, "nw_chicken", GetStartingLocation());
        ASSERT(IS_VALID(oCreature));

        NWNX_Visibility_SetVisibilityOverride(OBJECT_INVALID, oCreature, NWNX_VISIBILITY_DM_ONLY);
        EXPECT(IS_EQUAL_INT(NWNX_Visibility_GetVisibilityOverride(OBJECT_INVALID, oCreature), NWNX_VISIBILITY_DM_ONLY), "{Set/Get}VisibilityOverride (Global)");

        while (TEST("PC"))
        {
            object oPC = GetFirstPC();
            ASSERT(IS_VALID(oPC), "GetFirstPC()");

            NWNX_Visibility_SetVisibilityOverride(oPC, oCreature, NWNX_VISIBILITY_HIDDEN);
            EXPECT(IS_EQUAL_INT(NWNX_Visibility_GetVisibilityOverride(oPC, oCreature), NWNX_VISIBILITY_HIDDEN), "{Set/Get}VisibilityOverride (Personal)");
        }

        DestroyObject(oCreature);
    }
}
