namespace NWNX
{
    [NWNXPlugin(NWNX_Encounter)]
    public class EncounterPlugin
    {
        public const string NWNX_Encounter = "NWNX_Encounter";

        // /< @private
        // / @brief A creature list entry for an encounter.
        // / @brief Get the number of creatures in the encounter list
        // / @param encounter The encounter object.
        // / @return The number of creatures in the encounter list.
        public static int GetNumberOfCreaturesInEncounterList(uint encounter)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "GetNumberOfCreaturesInEncounterList");
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Gets the encounter creature list entry at the specified index
        // / @param encounter The encounter object.
        // / @param index The index of the creature in the encounter list.
        // / @return An NWNX_Encounter_CreatureListEntry.
        public static CreatureListEntry GetEncounterCreatureByIndex(uint encounter, int index)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "GetEncounterCreatureByIndex");
            NWN.Internal.NativeFunctions.nwnxPushInt(index);
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            CreatureListEntry retVal;
            retVal.unique = NWN.Internal.NativeFunctions.nwnxPopInt();
            retVal.challengeRating = NWN.Internal.NativeFunctions.nwnxPopFloat();
            retVal.resref = NWN.Internal.NativeFunctions.nwnxPopString();
            return retVal;
        }

        // / @brief Set the encounter creature list entry at the specified index
        // / @param encounter The encounter object.
        // / @param index The index of the creature in the encounter list.
        // / @param creatureEntry The NWNX_Encounter_CreatureListEntry.
        public static void SetEncounterCreatureByIndex(uint encounter, int index, CreatureListEntry creatureEntry)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "SetEncounterCreatureByIndex");
            NWN.Internal.NativeFunctions.nwnxPushString(creatureEntry.resref);
            NWN.Internal.NativeFunctions.nwnxPushFloat(creatureEntry.challengeRating);
            NWN.Internal.NativeFunctions.nwnxPushInt(creatureEntry.unique);
            NWN.Internal.NativeFunctions.nwnxPushInt(index);
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the faction id of encounter
        // / @param encounter The encounter object.
        // / @return The faction id.
        public static int GetFactionId(uint encounter)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "GetFactionId");
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the faction id of encounter.
        // / @param encounter The encounter object.
        // / @param factionId The faction id.
        public static void SetFactionId(uint encounter, int factionId)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "SetFactionId");
            NWN.Internal.NativeFunctions.nwnxPushInt(factionId);
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get if encounter is player triggered only.
        // / @param encounter The encounter object.
        // / @return TRUE is encounter is player triggered only.
        public static int GetPlayerTriggeredOnly(uint encounter)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "GetPlayerTriggeredOnly");
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set if encounter is player triggered only.
        // / @param encounter The encounter object.
        // / @param playerTriggeredOnly TRUE/FALSE
        public static void SetPlayerTriggeredOnly(uint encounter, int playerTriggeredOnly)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "SetPlayerTriggeredOnly");
            NWN.Internal.NativeFunctions.nwnxPushInt(playerTriggeredOnly);
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @brief Get the reset time of encounter.
        // / @param encounter The encounter object.
        // / @return The seconds the encounter is defined to reset.
        public static int GetResetTime(uint encounter)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "GetResetTime");
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
            return NWN.Internal.NativeFunctions.nwnxPopInt();
        }

        // / @brief Set the reset time of encounter.
        // / @param encounter The encounter object.
        // / @param resetTime The seconds the encounter will reset.
        public static void SetResetTime(uint encounter, int resetTime)
        {
            NWN.Internal.NativeFunctions.nwnxSetFunction(NWNX_Encounter, "SetResetTime");
            NWN.Internal.NativeFunctions.nwnxPushInt(resetTime);
            NWN.Internal.NativeFunctions.nwnxPushObject(encounter);
            NWN.Internal.NativeFunctions.nwnxCallFunction();
        }

        // / @}
    }

        public struct CreatureListEntry
        {
            public string resref;
            public float challengeRating;
            public int unique;
        }
}
