namespace NWN
{
    public partial class NWScript
    {
        public static void AssignCommand(NWN.Object oActionSubject, ActionDelegate aActionToAssign)
        {
            Internal.ClosureAssignCommand(oActionSubject, aActionToAssign);
        }

        public static void DelayCommand(float fSeconds, ActionDelegate aActionToDelay)
        {
            Internal.ClosureDelayCommand(Object.OBJECT_SELF, fSeconds, aActionToDelay);
        }

        public static void ActionDoCommand(ActionDelegate aActionToDelay)
        {
            Internal.ClosureActionDoCommand(Object.OBJECT_SELF, aActionToDelay);
        }


        //  Get an integer between 0 and nMaxInteger-1.
        //  Return value on error: 0
        public static int Random(int nMaxInteger)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMaxInteger);
            NWN.Internal.NativeFunctions.CallBuiltIn(0);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Output sString to the log file.
        public static void PrintString(string sString)
        {
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(1);
        }

        //  Output a formatted float to the log file.
        //  - nWidth should be a value from 0 to 18 inclusive.
        //  - nDecimals should be a value from 0 to 9 inclusive.
        public static void PrintFloat(float fFloat, int nWidth = 18, int nDecimals = 9)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDecimals);
            NWN.Internal.NativeFunctions.StackPushInteger(nWidth);
            NWN.Internal.NativeFunctions.StackPushFloat(fFloat);
            NWN.Internal.NativeFunctions.CallBuiltIn(2);
        }

        //  Convert fFloat into a string.
        //  - nWidth should be a value from 0 to 18 inclusive.
        //  - nDecimals should be a value from 0 to 9 inclusive.
        public static string FloatToString(float fFloat, int nWidth = 18, int nDecimals = 9)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDecimals);
            NWN.Internal.NativeFunctions.StackPushInteger(nWidth);
            NWN.Internal.NativeFunctions.StackPushFloat(fFloat);
            NWN.Internal.NativeFunctions.CallBuiltIn(3);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Output nInteger to the log file.
        public static void PrintInteger(int nInteger)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInteger);
            NWN.Internal.NativeFunctions.CallBuiltIn(4);
        }

        //  Output oObject's ID to the log file.
        public static void PrintObject(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(5);
        }

        //  Assign aActionToAssign to oActionSubject.
        //  * No return value, but if an error occurs, the log file will contain
        //    "AssignCommand failed."
        //    (If the object doesn't exist, nothing happens.)
        //  Delay aActionToDelay by fSeconds.
        //  * No return value, but if an error occurs, the log file will contain
        //    "DelayCommand failed.".
        //  It is suggested that functions which create effects should not be used
        //  as parameters to delayed actions.  Instead, the effect should be created in the
        //  script and then passed into the action.  For example:
        //  effect eDamage = EffectDamage(nDamage, DAMAGE_TYPE_MAGICAL);
        //  DelayCommand(fDelay, ApplyEffectToObject(DURATION_TYPE_INSTANT, eDamage, oTarget);
        //  Make oTarget run sScript and then return execution to the calling script.
        //  If sScript does not specify a compiled script, nothing happens.
        public static void ExecuteScript(string sScript, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sScript);
            NWN.Internal.NativeFunctions.CallBuiltIn(8);
        }

        //  Clear all the actions of the caller.
        //  * No return value, but if an error occurs, the log file will contain
        //    "ClearAllActions failed.".
        //  - nClearCombatState: if true, this will immediately clear the combat state
        //    on a creature, which will stop the combat music and allow them to rest,
        //    engage in dialog, or other actions that they would normally have to wait for.
        public static void ClearAllActions(int nClearCombatState = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nClearCombatState);
            NWN.Internal.NativeFunctions.CallBuiltIn(9);
        }

        //  Cause the caller to face fDirection.
        //  - fDirection is expressed as anticlockwise degrees from Due East.
        //    DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
        //    predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
        public static void SetFacing(float fDirection)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDirection);
            NWN.Internal.NativeFunctions.CallBuiltIn(10);
        }

        //  Set the calendar to the specified date.
        //  - nYear should be from 0 to 32000 inclusive
        //  - nMonth should be from 1 to 12 inclusive
        //  - nDay should be from 1 to 28 inclusive
        //  1) Time can only be advanced forwards; attempting to set the time backwards
        //     will result in no change to the calendar.
        //  2) If values larger than the month or day are specified, they will be wrapped
        //     around and the overflow will be used to advance the next field.
        //     e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
        //     the calender being set to a year of 1352, a month of 9 and a day of 10.
        public static void SetCalendar(int nYear, int nMonth, int nDay)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDay);
            NWN.Internal.NativeFunctions.StackPushInteger(nMonth);
            NWN.Internal.NativeFunctions.StackPushInteger(nYear);
            NWN.Internal.NativeFunctions.CallBuiltIn(11);
        }

        //  Set the time to the time specified.
        //  - nHour should be from 0 to 23 inclusive
        //  - nMinute should be from 0 to 59 inclusive
        //  - nSecond should be from 0 to 59 inclusive
        //  - nMillisecond should be from 0 to 999 inclusive
        //  1) Time can only be advanced forwards; attempting to set the time backwards
        //     will result in the day advancing and then the time being set to that
        //     specified, e.g. if the current hour is 15 and then the hour is set to 3,
        //     the day will be advanced by 1 and the hour will be set to 3.
        //  2) If values larger than the max hour, minute, second or millisecond are
        //     specified, they will be wrapped around and the overflow will be used to
        //     advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
        //     and 10 milliseconds will result in the calendar day being advanced by 2
        //     and the time being set to 18 hours, 10 minutes, 10 milliseconds.
        public static void SetTime(int nHour, int nMinute, int nSecond, int nMillisecond)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMillisecond);
            NWN.Internal.NativeFunctions.StackPushInteger(nSecond);
            NWN.Internal.NativeFunctions.StackPushInteger(nMinute);
            NWN.Internal.NativeFunctions.StackPushInteger(nHour);
            NWN.Internal.NativeFunctions.CallBuiltIn(12);
        }

        //  Get the current calendar year.
        public static int GetCalendarYear()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(13);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current calendar month.
        public static int GetCalendarMonth()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(14);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current calendar day.
        public static int GetCalendarDay()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(15);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current hour.
        public static int GetTimeHour()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(16);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current minute
        public static int GetTimeMinute()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(17);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current second
        public static int GetTimeSecond()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(18);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the current millisecond
        public static int GetTimeMillisecond()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(19);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The action subject will generate a random location near its current location
        //  and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
        //  to call ClearAllActions in order to allow a creature to perform any other action
        //  once ActionRandomWalk has been called.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionRandomWalk failed."
        public static void ActionRandomWalk()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(20);
        }

        //  The action subject will move to lDestination.
        //  - lDestination: The object will move to this location.  If the location is
        //    invalid or a path cannot be found to it, the command does nothing.
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  * No return value, but if an error occurs the log file will contain
        //    "MoveToPoint failed."
        public static void ActionMoveToLocation(NWN.Location lDestination, int bRun = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushLocation(lDestination.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(21);
        }

        //  Cause the action subject to move to a certain distance from oMoveTo.
        //  If there is no path to oMoveTo, this command will do nothing.
        //  - oMoveTo: This is the object we wish the action subject to move to
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  - fRange: This is the desired distance between the action subject and oMoveTo
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionMoveToObject failed."
        public static void ActionMoveToObject(NWN.Object oMoveTo, int bRun = FALSE, float fRange = 1.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fRange);
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushObject(oMoveTo != null ? oMoveTo.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(22);
        }

        //  Cause the action subject to move to a certain distance away from oFleeFrom.
        //  - oFleeFrom: This is the object we wish the action subject to move away from.
        //    If oFleeFrom is not in the same area as the action subject, nothing will
        //    happen.
        //  - bRun: If this is TRUE, the action subject will run rather than walk
        //  - fMoveAwayRange: This is the distance we wish the action subject to put
        //    between themselves and oFleeFrom
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionMoveAwayFromObject failed."
        public static void ActionMoveAwayFromObject(NWN.Object oFleeFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fMoveAwayRange);
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushObject(oFleeFrom != null ? oFleeFrom.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(23);
        }

        //  Get the area that oTarget is currently in
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetArea(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(24);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  The value returned by this function depends on the object type of the caller:
        //  1) If the caller is a door it returns the object that last
        //     triggered it.
        //  2) If the caller is a trigger, area of effect, module, area or encounter it
        //     returns the object that last entered it.
        //  * Return value on error: OBJECT_INVALID
        //   When used for doors, this should only be called from the OnAreaTransitionClick
        //   event.  Otherwise, it should only be called in OnEnter scripts.
        public static NWN.Object GetEnteringObject()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(25);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the object that last left the caller.  This function works on triggers,
        //  areas of effect, modules, areas and encounters.
        //  * Return value on error: OBJECT_INVALID
        //  Should only be called in OnExit scripts.
        public static NWN.Object GetExitingObject()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(26);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the position of oTarget
        //  * Return value on error: vector (0.0f, 0.0f, 0.0f)
        public static NWN.Vector GetPosition(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(27);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  Get the direction in which oTarget is facing, expressed as a float between
        //  0.0f and 360.0f
        //  * Return value on error: -1.0f
        public static float GetFacing(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(28);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get the possessor of oItem
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetItemPossessor(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(29);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the object possessed by oCreature with the tag sItemTag
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetItemPossessedBy(NWN.Object oCreature, string sItemTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sItemTag);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(30);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create an item with the template sItemTemplate in oTarget's inventory.
        //  - nStackSize: This is the stack size of the item to be created
        //  - sNewTag: If this string is not empty, it will replace the default tag from the template
        //  * Return value: The object that has been created.  On error, this returns
        //    OBJECT_INVALID.
        //  If the item created was merged into an existing stack of similar items,
        //  the function will return the merged stack object. If the merged stack
        //  overflowed, the function will return the overflowed stack that was created.
        public static NWN.Object CreateItemOnObject(string sItemTemplate, NWN.Object oTarget = null, int nStackSize = 1, string sNewTag = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushInteger(nStackSize);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sItemTemplate);
            NWN.Internal.NativeFunctions.CallBuiltIn(31);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Equip oItem into nInventorySlot.
        //  - nInventorySlot: INVENTORY_SLOT_*
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionEquipItem failed."
        // 
        //  Note: 
        //        If the creature already has an item equipped in the slot specified, it will be 
        //        unequipped automatically by the call to ActionEquipItem.
        //      
        //        In order for ActionEquipItem to succeed the creature must be able to equip the
        //        item oItem normally. This means that:
        //        1) The item is in the creature's inventory.
        //        2) The item must already be identified (if magical). 
        //        3) The creature has the level required to equip the item (if magical and ILR is on).
        //        4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
        public static void ActionEquipItem(NWN.Object oItem, int nInventorySlot)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInventorySlot);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(32);
        }

        //  Unequip oItem from whatever slot it is currently in.
        public static void ActionUnequipItem(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(33);
        }

        //  Pick up oItem from the ground.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionPickUpItem failed."
        public static void ActionPickUpItem(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(34);
        }

        //  Put down oItem on the ground.
        //  * No return value, but if an error occurs the log file will contain
        //    "ActionPutDownItem failed."
        public static void ActionPutDownItem(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(35);
        }

        //  Get the last attacker of oAttackee.  This should only be used ONLY in the
        //  OnAttacked events for creatures, placeables and doors.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLastAttacker(NWN.Object oAttackee = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAttackee != null ? oAttackee.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(36);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Attack oAttackee.
        //  - bPassive: If this is TRUE, attack is in passive mode.
        public static void ActionAttack(NWN.Object oAttackee, int bPassive = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPassive);
            NWN.Internal.NativeFunctions.StackPushObject(oAttackee != null ? oAttackee.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(37);
        }

        //  Get the creature nearest to oTarget, subject to all the criteria specified.
        //  - nFirstCriteriaType: CREATURE_TYPE_*
        //  - nFirstCriteriaValue:
        //    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
        //    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
        //       or CREATURE_TYPE_HAS_SPELL_EFFECT
        //    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
        //    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
        //    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
        //       CREATURE_TYPE_PLAYER_CHAR
        //    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
        //    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
        //    For example, to get the nearest PC, use:
        //    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
        //  - oTarget: We're trying to find the creature of the specified type that is
        //    nearest to oTarget
        //  - nNth: We don't have to find the first nearest: we can find the Nth nearest...
        //  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
        //    to further specify the type of creature that we are looking for.
        //  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
        //    further specify the type of creature that we are looking for.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, NWN.Object oTarget = null, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nThirdCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nThirdCriteriaType);
            NWN.Internal.NativeFunctions.StackPushInteger(nSecondCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSecondCriteriaType);
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFirstCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nFirstCriteriaType);
            NWN.Internal.NativeFunctions.CallBuiltIn(38);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Add a speak action to the action subject.
        //  - sStringToSpeak: String to be spoken
        //  - nTalkVolume: TALKVOLUME_*
        public static void ActionSpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTalkVolume);
            NWN.Internal.NativeFunctions.StackPushString(sStringToSpeak);
            NWN.Internal.NativeFunctions.CallBuiltIn(39);
        }

        //  Cause the action subject to play an animation
        //  - nAnimation: ANIMATION_*
        //  - fSpeed: Speed of the animation
        //  - fDurationSeconds: Duration of the animation (this is not used for Fire and
        //    Forget animations)
        public static void ActionPlayAnimation(int nAnimation, float fSpeed = 1.0f, float fDurationSeconds = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDurationSeconds);
            NWN.Internal.NativeFunctions.StackPushFloat(fSpeed);
            NWN.Internal.NativeFunctions.StackPushInteger(nAnimation);
            NWN.Internal.NativeFunctions.CallBuiltIn(40);
        }

        //  Get the distance from the caller to oObject in metres.
        //  * Return value on error: -1.0f
        public static float GetDistanceToObject(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(41);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  * Returns TRUE if oObject is a valid object.
        public static int GetIsObjectValid(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(42);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Cause the action subject to open oDoor
        public static void ActionOpenDoor(NWN.Object oDoor)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oDoor != null ? oDoor.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(43);
        }

        //  Cause the action subject to close oDoor
        public static void ActionCloseDoor(NWN.Object oDoor)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oDoor != null ? oDoor.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(44);
        }

        //  Change the direction in which the camera is facing
        //  - fDirection is expressed as anticlockwise degrees from Due East.
        //    (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
        //  A value of -1.0f for any parameter will be ignored and instead it will
        //  use the current camera value.
        //  This can be used to change the way the camera is facing after the player
        //  emerges from an area transition.
        //  - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
        //    camera to the new position, while the other types will result in the camera moving gradually into position
        //  Pitch and distance are limited to valid values for the current camera mode:
        //  Top Down: Distance = 5-20, Pitch = 1-50
        //  Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
        //  Chase: Distance = 5-20, Pitch = 1-50
        //  *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
        //  Distance 1-25
        //  Pitch 1-89
        public static void SetCameraFacing(float fDirection, float fDistance = -1.0f, float fPitch = -1.0f, int nTransitionType = CAMERA_TRANSITION_TYPE_SNAP)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTransitionType);
            NWN.Internal.NativeFunctions.StackPushFloat(fPitch);
            NWN.Internal.NativeFunctions.StackPushFloat(fDistance);
            NWN.Internal.NativeFunctions.StackPushFloat(fDirection);
            NWN.Internal.NativeFunctions.CallBuiltIn(45);
        }

        //  Play sSoundName
        //  - sSoundName: TBD - SS
        //  This will play a mono sound from the location of the object running the command.
        public static void PlaySound(string sSoundName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sSoundName);
            NWN.Internal.NativeFunctions.CallBuiltIn(46);
        }

        //  Get the object at which the caller last cast a spell
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetSpellTargetObject()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(47);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  This action casts a spell at oTarget.
        //  - nSpell: SPELL_*
        //  - oTarget: Target for the spell
        //  - nMetamagic: METAMAGIC_*
        //  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
        //    able to cast the spell.
        //  - nDomainLevel: TBD - SS
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        //  - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows
        //    the end-user to simulate a high-level magic-user having lots of advance
        //    warning of impending trouble
        public static void ActionCastSpellAtObject(int nSpell, NWN.Object oTarget, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nDomainLevel = 0, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bInstantSpell);
            NWN.Internal.NativeFunctions.StackPushInteger(nProjectilePathType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDomainLevel);
            NWN.Internal.NativeFunctions.StackPushInteger(bCheat);
            NWN.Internal.NativeFunctions.StackPushInteger(nMetaMagic);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(48);
        }

        //  Get the current hitpoints of oObject
        //  * Return value on error: 0
        public static int GetCurrentHitPoints(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(49);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the maximum hitpoints of oObject
        //  * Return value on error: 0
        public static int GetMaxHitPoints(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(50);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oObject's local integer variable sVarName
        //  * Return value on error: 0
        public static int GetLocalInt(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(51);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oObject's local float variable sVarName
        //  * Return value on error: 0.0f
        public static float GetLocalFloat(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(52);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get oObject's local string variable sVarName
        //  * Return value on error: ""
        public static string GetLocalString(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(53);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get oObject's local object variable sVarName
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLocalObject(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(54);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Set oObject's local integer variable sVarName to nValue
        public static void SetLocalInt(NWN.Object oObject, string sVarName, int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(55);
        }

        //  Set oObject's local float variable sVarName to nValue
        public static void SetLocalFloat(NWN.Object oObject, string sVarName, float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(56);
        }

        //  Set oObject's local string variable sVarName to nValue
        public static void SetLocalString(NWN.Object oObject, string sVarName, string sValue)
        {
            NWN.Internal.NativeFunctions.StackPushString(sValue);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(57);
        }

        //  Set oObject's local object variable sVarName to nValue
        public static void SetLocalObject(NWN.Object oObject, string sVarName, NWN.Object oValue)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oValue != null ? oValue.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(58);
        }

        //  Get the length of sString
        //  * Return value on error: -1
        public static int GetStringLength(string sString)
        {
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(59);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Convert sString into upper case
        //  * Return value on error: ""
        public static string GetStringUpperCase(string sString)
        {
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(60);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Convert sString into lower case
        //  * Return value on error: ""
        public static string GetStringLowerCase(string sString)
        {
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(61);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get nCount characters from the right end of sString
        //  * Return value on error: ""
        public static string GetStringRight(string sString, int nCount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCount);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(62);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get nCounter characters from the left end of sString
        //  * Return value on error: ""
        public static string GetStringLeft(string sString, int nCount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCount);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(63);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Insert sString into sDestination at nPosition
        //  * Return value on error: ""
        public static string InsertString(string sDestination, string sString, int nPosition)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPosition);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.StackPushString(sDestination);
            NWN.Internal.NativeFunctions.CallBuiltIn(64);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get nCount characters from sString, starting at nStart
        //  * Return value on error: ""
        public static string GetSubString(string sString, int nStart, int nCount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCount);
            NWN.Internal.NativeFunctions.StackPushInteger(nStart);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(65);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Find the position of sSubstring inside sString
        //  - nStart: The character position to start searching at (from the left end of the string). 
        //  * Return value on error: -1
        public static int FindSubString(string sString, string sSubString, int nStart = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStart);
            NWN.Internal.NativeFunctions.StackPushString(sSubString);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.CallBuiltIn(66);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  math operations
        //  Maths operation: absolute value of fValue
        public static float fabs(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(67);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: cosine of fValue
        public static float cos(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(68);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: sine of fValue
        public static float sin(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(69);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: tan of fValue
        public static float tan(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(70);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: arccosine of fValue
        //  * Returns zero if fValue > 1 or fValue < -1
        public static float acos(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(71);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: arcsine of fValue
        //  * Returns zero if fValue >1 or fValue < -1
        public static float asin(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(72);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: arctan of fValue
        public static float atan(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(73);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: log of fValue
        //  * Returns zero if fValue <= zero
        public static float log(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(74);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: fValue is raised to the power of fExponent
        //  * Returns zero if fValue ==0 and fExponent <0
        public static float pow(float fValue, float fExponent)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fExponent);
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(75);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: square root of fValue
        //  * Returns zero if fValue <0
        public static float sqrt(float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(76);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Maths operation: integer absolute value of nValue
        //  * Return value on error: 0
        public static int abs(int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(77);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Heal effect. This should be applied as an instantaneous effect.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
        public static NWN.Effect EffectHeal(int nDamageToHeal)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageToHeal);
            NWN.Internal.NativeFunctions.CallBuiltIn(78);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage effect
        //  - nDamageAmount: amount of damage to be dealt. This should be applied as an
        //    instantaneous effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nDamagePower: DAMAGE_POWER_*
        public static NWN.Effect EffectDamage(int nDamageAmount, int nDamageType = DAMAGE_TYPE_MAGICAL, int nDamagePower = DAMAGE_POWER_NORMAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamagePower);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(79);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an Ability Increase effect
        //  - bAbilityToIncrease: ABILITY_*
        public static NWN.Effect EffectAbilityIncrease(int nAbilityToIncrease, int nModifyBy)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifyBy);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbilityToIncrease);
            NWN.Internal.NativeFunctions.CallBuiltIn(80);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage Resistance effect that removes the first nAmount points of
        //  damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nAmount
        //  - nLimit
        public static NWN.Effect EffectDamageResistance(int nDamageType, int nAmount, int nLimit = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLimit);
            NWN.Internal.NativeFunctions.StackPushInteger(nAmount);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(81);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Resurrection effect. This should be applied as an instantaneous effect.
        public static NWN.Effect EffectResurrection()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(82);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Summon Creature effect.  The creature is created and placed into the
        //  caller's party/faction.
        //  - sCreatureResref: Identifies the creature to be summoned
        //  - nVisualEffectId: VFX_*
        //  - fDelaySeconds: There can be delay between the visual effect being played, and the
        //    creature being added to the area
        //  - nUseAppearAnimation: should this creature play it's "appear" animation when it is
        //    summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
        //    it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
        public static NWN.Effect EffectSummonCreature(string sCreatureResref, int nVisualEffectId = VFX_NONE, float fDelaySeconds = 0.0f, int nUseAppearAnimation = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nUseAppearAnimation);
            NWN.Internal.NativeFunctions.StackPushFloat(fDelaySeconds);
            NWN.Internal.NativeFunctions.StackPushInteger(nVisualEffectId);
            NWN.Internal.NativeFunctions.StackPushString(sCreatureResref);
            NWN.Internal.NativeFunctions.CallBuiltIn(83);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the level at which this creature cast it's last spell (or spell-like ability)
        //  * Return value on error, or if oCreature has not yet cast a spell: 0;
        public static int GetCasterLevel(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(84);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the first in-game effect on oCreature.
        public static NWN.Effect GetFirstEffect(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(85);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the next in-game effect on oCreature.
        public static NWN.Effect GetNextEffect(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(86);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Remove eEffect from oCreature.
        //  * No return value
        public static void RemoveEffect(NWN.Object oCreature, NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(87);
        }

        //  * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
        //  * an object or else it will return FALSE
        public static int GetIsEffectValid(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(88);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the duration type (DURATION_TYPE_*) of eEffect.
        //  * Return value if eEffect is not valid: -1
        public static int GetEffectDurationType(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(89);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the subtype (SUBTYPE_*) of eEffect.
        //  * Return value on error: 0
        public static int GetEffectSubType(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(90);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the object that created eEffect.
        //  * Returns OBJECT_INVALID if eEffect is not a valid effect.
        public static NWN.Object GetEffectCreator(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(91);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Convert nInteger into a string.
        //  * Return value on error: ""
        public static string IntToString(int nInteger)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInteger);
            NWN.Internal.NativeFunctions.CallBuiltIn(92);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the first object in oArea.
        //  If no valid area is specified, it will use the caller's area.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetFirstObjectInArea(NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(93);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next object in oArea.
        //  If no valid area is specified, it will use the caller's area.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNextObjectInArea(NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(94);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the total from rolling (nNumDice x d2 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d2(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(95);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d3 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d3(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(96);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d4 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d4(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(97);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d6 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d6(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(98);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d8 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d8(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(99);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d10 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d10(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(100);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d12 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d12(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(101);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d20 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d20(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(102);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total from rolling (nNumDice x d100 dice).
        //  - nNumDice: If this is less than 1, the value 1 will be used.
        public static int d100(int nNumDice = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(103);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the magnitude of vVector; this can be used to determine the
        //  distance between two points.
        //  * Return value on error: 0.0f
        public static float VectorMagnitude(NWN.Vector? vVector)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vVector.HasValue ? vVector.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(104);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
        //  * Return value if the caster is not a valid object: -1
        public static int GetMetaMagicFeat()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(105);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the object type (OBJECT_TYPE_*) of oTarget
        //  * Return value if oTarget is not a valid object: -1
        public static int GetObjectType(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(106);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the racial type (RACIAL_TYPE_*) of oCreature
        //  * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
        public static int GetRacialType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(107);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Do a Fortitude Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int FortitudeSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSaveVersus != null ? oSaveVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDC);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(108);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Does a Reflex Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int ReflexSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSaveVersus != null ? oSaveVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDC);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(109);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Does a Will Save check for the given DC
        //  - oCreature
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        //  Returns: 0 if the saving throw roll failed
        //  Returns: 1 if the saving throw roll succeeded
        //  Returns: 2 if the target was immune to the save type specified
        //  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
        //  GetAreaOfEffectCreator() into oSaveVersus!!
        public static int WillSave(NWN.Object oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSaveVersus != null ? oSaveVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDC);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(110);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the DC to save against for a spell (10 + spell level + relevant ability
        //  bonus).  This can be called by a creature or by an Area of Effect object.
        public static int GetSpellSaveDC()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(111);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the subtype of eEffect to Magical and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Magical effects are removed by resting, and by dispel magic
        public static NWN.Effect MagicalEffect(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(112);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set the subtype of eEffect to Supernatural and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Permanent supernatural effects are not removed by resting
        public static NWN.Effect SupernaturalEffect(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(113);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set the subtype of eEffect to Extraordinary and return eEffect.
        //  (Effects default to magical if the subtype is not set)
        //  Extraordinary effects are removed by resting, but not by dispel magic
        public static NWN.Effect ExtraordinaryEffect(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(114);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an AC Increase effect
        //  - nValue: size of AC increase
        //  - nModifyType: AC_*_BONUS
        //  - nDamageType: DAMAGE_TYPE_*
        //    * Default value for nDamageType should only ever be used in this function prototype.
        public static NWN.Effect EffectACIncrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nModifyType);
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(115);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  If oObject is a creature, this will return that creature's armour class
        //  If oObject is an item, door or placeable, this will return zero.
        //  - nForFutureUse: this parameter is not currently used
        //  * Return value if oObject is not a creature, item, door or placeable: -1
        public static int GetAC(NWN.Object oObject, int nForFutureUse = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nForFutureUse);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(116);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Saving Throw Increase effect
        //  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
        //           SAVING_THROW_ALL
        //           SAVING_THROW_FORT
        //           SAVING_THROW_REFLEX
        //           SAVING_THROW_WILL 
        //  - nValue: size of the Saving Throw increase
        //  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
        public static NWN.Effect EffectSavingThrowIncrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSave);
            NWN.Internal.NativeFunctions.CallBuiltIn(117);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an Attack Increase effect
        //  - nBonus: size of attack bonus
        //  - nModifierType: ATTACK_BONUS_*
        public static NWN.Effect EffectAttackIncrease(int nBonus, int nModifierType = ATTACK_BONUS_MISC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifierType);
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(118);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage Reduction effect
        //  - nAmount: amount of damage reduction
        //  - nDamagePower: DAMAGE_POWER_*
        //  - nLimit: How much damage the effect can absorb before disappearing.
        //    Set to zero for infinite
        public static NWN.Effect EffectDamageReduction(int nAmount, int nDamagePower, int nLimit = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLimit);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamagePower);
            NWN.Internal.NativeFunctions.StackPushInteger(nAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(119);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage Increase effect
        //  - nBonus: DAMAGE_BONUS_*
        //  - nDamageType: DAMAGE_TYPE_*
        //  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
        //        result in odd behaviour.
        public static NWN.Effect EffectDamageIncrease(int nBonus, int nDamageType = DAMAGE_TYPE_MAGICAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(120);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Convert nRounds into a number of seconds
        //  A round is always 6.0 seconds
        public static float RoundsToSeconds(int nRounds)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRounds);
            NWN.Internal.NativeFunctions.CallBuiltIn(121);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Convert nHours into a number of seconds
        //  The result will depend on how many minutes there are per hour (game-time)
        public static float HoursToSeconds(int nHours)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHours);
            NWN.Internal.NativeFunctions.CallBuiltIn(122);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Convert nTurns into a number of seconds
        //  A turn is always 60.0 seconds
        public static float TurnsToSeconds(int nTurns)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTurns);
            NWN.Internal.NativeFunctions.CallBuiltIn(123);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get an integer between 0 and 100 (inclusive) to represent oCreature's
        //  Law/Chaos alignment
        //  (100=law, 0=chaos)
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetLawChaosValue(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(124);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) to represent oCreature's
        //  Good/Evil alignment
        //  (100=good, 0=evil)
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetGoodEvilValue(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(125);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetAlignmentLawChaos(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(126);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
        //  * Return value if oCreature is not a valid creature: -1
        public static int GetAlignmentGoodEvil(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(127);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the first object in nShape
        //  - nShape: SHAPE_*
        //  - fSize:
        //    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
        //    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
        //       Spell Cylinder's always have a radius of 1.5m.
        //    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
        //    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
        //       direction of lTarget. Spell cones are always 60 degrees with the origin
        //       at OBJECT_SELF.
        //    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
        //       the cube
        //  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
        //    or the end of a cylinder or cone.
        //  - bLineOfSight: This controls whether to do a line-of-sight check on the
        //    object returned. Line of sight check is done from origin to target object
        //    at a height 1m above the ground
        //    (This can be used to ensure that spell effects do not go through walls.)
        //  - nObjectFilter: This allows you to filter out undesired object types, using
        //    bitwise "or".
        //    For example, to return only creatures and doors, the value for this
        //    parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
        //  - vOrigin: This is only used for cylinders and cones, and specifies the
        //    origin of the effect(normally the spell-caster's position).
        //  Return value on error: OBJECT_INVALID
        public static NWN.Object GetFirstObjectInShape(int nShape, float fSize, NWN.Location lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, NWN.Vector? vOrigin = null)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vOrigin.HasValue ? vOrigin.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushInteger(nObjectFilter);
            NWN.Internal.NativeFunctions.StackPushInteger(bLineOfSight);
            NWN.Internal.NativeFunctions.StackPushLocation(lTarget.Handle);
            NWN.Internal.NativeFunctions.StackPushFloat(fSize);
            NWN.Internal.NativeFunctions.StackPushInteger(nShape);
            NWN.Internal.NativeFunctions.CallBuiltIn(128);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next object in nShape
        //  - nShape: SHAPE_*
        //  - fSize:
        //    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
        //    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder.
        //       Spell Cylinder's always have a radius of 1.5m.
        //    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
        //    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
        //       direction of lTarget. Spell cones are always 60 degrees with the origin
        //       at OBJECT_SELF.
        //    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
        //       the cube
        //  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
        //    or the end of a cylinder or cone.
        //  - bLineOfSight: This controls whether to do a line-of-sight check on the
        //    object returned. (This can be used to ensure that spell effects do not go
        //    through walls.) Line of sight check is done from origin to target object
        //    at a height 1m above the ground
        //  - nObjectFilter: This allows you to filter out undesired object types, using
        //    bitwise "or". For example, to return only creatures and doors, the value for
        //    this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
        //  - vOrigin: This is only used for cylinders and cones, and specifies the origin
        //    of the effect (normally the spell-caster's position).
        //  Return value on error: OBJECT_INVALID
        public static NWN.Object GetNextObjectInShape(int nShape, float fSize, NWN.Location lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, NWN.Vector? vOrigin = null)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vOrigin.HasValue ? vOrigin.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushInteger(nObjectFilter);
            NWN.Internal.NativeFunctions.StackPushInteger(bLineOfSight);
            NWN.Internal.NativeFunctions.StackPushLocation(lTarget.Handle);
            NWN.Internal.NativeFunctions.StackPushFloat(fSize);
            NWN.Internal.NativeFunctions.StackPushInteger(nShape);
            NWN.Internal.NativeFunctions.CallBuiltIn(129);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create an Entangle effect
        //  When applied, this effect will restrict the creature's movement and apply a
        //  (-2) to all attacks and a -4 to AC.
        public static NWN.Effect EffectEntangle()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(130);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Causes object oObject to run the event evToRun. The script on the object that is
        //  associated with the event specified will run.
        //  Events can be created using the following event functions:
        //     EventActivateItem() - This creates an OnActivateItem module event. The script for handling
        //                           this event can be set in Module Properties on the Event Tab.
        //     EventConversation() - This creates on OnConversation creature event. The script for handling
        //                           this event can be set by viewing the Creature Properties on a 
        //                           creature and then clicking on the Scripts Tab.
        //     EventSpellCastAt()  - This creates an OnSpellCastAt event. The script for handling this
        //                           event can be set in the Scripts Tab of the Properties menu 
        //                           for the object.
        //     EventUserDefined()  - This creates on OnUserDefined event. The script for handling this event
        //                           can be set in the Scripts Tab of the Properties menu for the object/area/module.
        public static void SignalEvent(NWN.Object oObject, NWN.Event evToRun)
        {
            NWN.Internal.NativeFunctions.StackPushEvent(evToRun.Handle);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(131);
        }

        //  Create an event of the type nUserDefinedEventNumber
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created UserDefined event as an argument.
        //  For example:
        //      SignalEvent(oObject, EventUserDefined(9999));
        //  Once the event has been signaled. The script associated with the OnUserDefined event will
        //  run on the object oObject.
        // 
        //  To specify the OnUserDefined script that should run, view the object's Properties
        //  and click on the Scripts Tab. Then specify a script for the OnUserDefined event.
        //  From inside the OnUserDefined script call:
        //     GetUserDefinedEventNumber() to retrieve the value of nUserDefinedEventNumber
        //     that was used when the event was signaled.
        public static NWN.Event EventUserDefined(int nUserDefinedEventNumber)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nUserDefinedEventNumber);
            NWN.Internal.NativeFunctions.CallBuiltIn(132);
            return new NWN.Event(NWN.Internal.NativeFunctions.StackPopEvent());
        }

        //  Create a Death effect
        //  - nSpectacularDeath: if this is TRUE, the creature to which this effect is
        //    applied will die in an extraordinary fashion
        //  - nDisplayFeedback
        public static NWN.Effect EffectDeath(int nSpectacularDeath = FALSE, int nDisplayFeedback = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDisplayFeedback);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpectacularDeath);
            NWN.Internal.NativeFunctions.CallBuiltIn(133);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Knockdown effect
        //  This effect knocks creatures off their feet, they will sit until the effect
        //  is removed. This should be applied as a temporary effect with a 3 second
        //  duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
        public static NWN.Effect EffectKnockdown()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(134);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Give oItem to oGiveTo
        //  If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
        //  happen.
        public static void ActionGiveItem(NWN.Object oItem, NWN.Object oGiveTo)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oGiveTo != null ? oGiveTo.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(135);
        }

        //  Take oItem from oTakeFrom
        //  If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
        //  will happen.
        public static void ActionTakeItem(NWN.Object oItem, NWN.Object oTakeFrom)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTakeFrom != null ? oTakeFrom.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(136);
        }

        //  Normalize vVector
        public static NWN.Vector VectorNormalize(NWN.Vector? vVector)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vVector.HasValue ? vVector.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(137);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  Create a Curse effect.
        //  - nStrMod: strength modifier
        //  - nDexMod: dexterity modifier
        //  - nConMod: constitution modifier
        //  - nIntMod: intelligence modifier
        //  - nWisMod: wisdom modifier
        //  - nChaMod: charisma modifier
        public static NWN.Effect EffectCurse(int nStrMod = 1, int nDexMod = 1, int nConMod = 1, int nIntMod = 1, int nWisMod = 1, int nChaMod = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nChaMod);
            NWN.Internal.NativeFunctions.StackPushInteger(nWisMod);
            NWN.Internal.NativeFunctions.StackPushInteger(nIntMod);
            NWN.Internal.NativeFunctions.StackPushInteger(nConMod);
            NWN.Internal.NativeFunctions.StackPushInteger(nDexMod);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrMod);
            NWN.Internal.NativeFunctions.CallBuiltIn(138);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the ability score of type nAbility for a creature (otherwise 0)
        //  - oCreature: the creature whose ability score we wish to find out
        //  - nAbilityType: ABILITY_*
        //  - nBaseAbilityScore: if set to true will return the base ability score without
        //                       bonuses (e.g. ability bonuses granted from equipped items).
        //  Return value on error: 0
        public static int GetAbilityScore(NWN.Object oCreature, int nAbilityType, int nBaseAbilityScore = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBaseAbilityScore);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbilityType);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(139);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
        public static int GetIsDead(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(140);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Output vVector to the logfile.
        //  - vVector
        //  - bPrepend: if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
        public static void PrintVector(NWN.Vector? vVector, int bPrepend)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPrepend);
            NWN.Internal.NativeFunctions.StackPushVector(vVector.HasValue ? vVector.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(141);
        }

        //  Create a vector with the specified values for x, y and z
        public static NWN.Vector Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(z);
            NWN.Internal.NativeFunctions.StackPushFloat(y);
            NWN.Internal.NativeFunctions.StackPushFloat(x);
            NWN.Internal.NativeFunctions.CallBuiltIn(142);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  Cause the caller to face vTarget
        public static void SetFacingPoint(NWN.Vector? vTarget)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vTarget.HasValue ? vTarget.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(143);
        }

        //  Convert fAngle to a vector
        public static NWN.Vector AngleToVector(float fAngle)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fAngle);
            NWN.Internal.NativeFunctions.CallBuiltIn(144);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  Convert vVector to an angle
        public static float VectorToAngle(NWN.Vector? vVector)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vVector.HasValue ? vVector.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(145);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  The caller will perform a Melee Touch Attack on oTarget
        //  This is not an action, and it assumes the caller is already within range of
        //  oTarget
        //  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
        public static int TouchAttackMelee(NWN.Object oTarget, int bDisplayFeedback = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bDisplayFeedback);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(146);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The caller will perform a Ranged Touch Attack on oTarget
        //  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
        public static int TouchAttackRanged(NWN.Object oTarget, int bDisplayFeedback = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bDisplayFeedback);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(147);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Paralyze effect
        public static NWN.Effect EffectParalyze()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(148);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Spell Immunity effect.
        //  There is a known bug with this function. There *must* be a parameter specified
        //  when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
        //  otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
        //  - nImmunityToSpell: SPELL_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
        //    invalid.
        public static NWN.Effect EffectSpellImmunity(int nImmunityToSpell = SPELL_ALL_SPELLS)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nImmunityToSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(149);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Deaf effect
        public static NWN.Effect EffectDeaf()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(150);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the distance in metres between oObjectA and oObjectB.
        //  * Return value if either object is invalid: 0.0f
        public static float GetDistanceBetween(NWN.Object oObjectA, NWN.Object oObjectB)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObjectB != null ? oObjectB.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oObjectA != null ? oObjectA.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(151);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Set oObject's local location variable sVarname to lValue
        public static void SetLocalLocation(NWN.Object oObject, string sVarName, NWN.Location lValue)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lValue.Handle);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(152);
        }

        //  Get oObject's local location variable sVarname
        public static NWN.Location GetLocalLocation(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(153);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  Create a Sleep effect
        public static NWN.Effect EffectSleep()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(154);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the object which is in oCreature's specified inventory slot
        //  - nInventorySlot: INVENTORY_SLOT_*
        //  - oCreature
        //  * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
        //    item in nInventorySlot.
        public static NWN.Object GetItemInSlot(int nInventorySlot, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nInventorySlot);
            NWN.Internal.NativeFunctions.CallBuiltIn(155);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create a Charm effect
        public static NWN.Effect EffectCharmed()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(156);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Confuse effect
        public static NWN.Effect EffectConfused()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(157);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Frighten effect
        public static NWN.Effect EffectFrightened()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(158);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Dominate effect
        public static NWN.Effect EffectDominated()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(159);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Daze effect
        public static NWN.Effect EffectDazed()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(160);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Stun effect
        public static NWN.Effect EffectStunned()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(161);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set whether oTarget's action stack can be modified
        public static void SetCommandable(int bCommandable, NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(bCommandable);
            NWN.Internal.NativeFunctions.CallBuiltIn(162);
        }

        //  Determine whether oTarget's action stack can be modified.
        public static int GetCommandable(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(163);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Regenerate effect.
        //  - nAmount: amount of damage to be regenerated per time interval
        //  - fIntervalSeconds: length of interval in seconds
        public static NWN.Effect EffectRegenerate(int nAmount, float fIntervalSeconds)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fIntervalSeconds);
            NWN.Internal.NativeFunctions.StackPushInteger(nAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(164);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Movement Speed Increase effect.
        //  - nPercentChange - range 0 through 99
        //  eg.
        //     0 = no change in speed
        //    50 = 50% faster
        //    99 = almost twice as fast
        public static NWN.Effect EffectMovementSpeedIncrease(int nPercentChange)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentChange);
            NWN.Internal.NativeFunctions.CallBuiltIn(165);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the number of hitdice for oCreature.
        //  * Return value if oCreature is not a valid creature: 0
        public static int GetHitDice(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(166);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The action subject will follow oFollow until a ClearAllActions() is called.
        //  - oFollow: this is the object to be followed
        //  - fFollowDistance: follow distance in metres
        //  * No return value
        public static void ActionForceFollowObject(NWN.Object oFollow, float fFollowDistance = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fFollowDistance);
            NWN.Internal.NativeFunctions.StackPushObject(oFollow != null ? oFollow.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(167);
        }

        //  Get the Tag of oObject
        //  * Return value if oObject is not a valid object: ""
        public static string GetTag(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(168);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
        //  the spell was resisted.
        //  * Return value if oCaster or oTarget is an invalid object: FALSE
        //  * Return value if spell cast is not a player spell: - 1
        //  * Return value if spell resisted: 1
        //  * Return value if spell resisted via magic immunity: 2
        //  * Return value if spell resisted via spell absorption: 3
        public static int ResistSpell(NWN.Object oCaster, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oCaster != null ? oCaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(169);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the effect type (EFFECT_TYPE_*) of eEffect.
        //  * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
        public static int GetEffectType(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(170);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create an Area Of Effect effect in the area of the creature it is applied to.
        //  If the scripts are not specified, default ones will be used.
        public static NWN.Effect EffectAreaOfEffect(int nAreaEffectId, string sOnEnterScript = "", string sHeartbeatScript = "", string sOnExitScript = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sOnExitScript);
            NWN.Internal.NativeFunctions.StackPushString(sHeartbeatScript);
            NWN.Internal.NativeFunctions.StackPushString(sOnEnterScript);
            NWN.Internal.NativeFunctions.StackPushInteger(nAreaEffectId);
            NWN.Internal.NativeFunctions.CallBuiltIn(171);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  * Returns TRUE if the Faction Ids of the two objects are the same
        public static int GetFactionEqual(NWN.Object oFirstObject, NWN.Object oSecondObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSecondObject != null ? oSecondObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oFirstObject != null ? oFirstObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(172);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
        //  NB. ** This will only work for two NPCs **
        public static void ChangeFaction(NWN.Object oObjectToChangeFaction, NWN.Object oMemberOfFactionToJoin)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oMemberOfFactionToJoin != null ? oMemberOfFactionToJoin.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oObjectToChangeFaction != null ? oObjectToChangeFaction.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(173);
        }

        //  * Returns TRUE if oObject is listening for something
        public static int GetIsListening(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(174);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set whether oObject is listening.
        public static void SetListening(NWN.Object oObject, int bValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bValue);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(175);
        }

        //  Set the string for oObject to listen for.
        //  Note: this does not set oObject to be listening.
        public static void SetListenPattern(NWN.Object oObject, string sPattern, int nNumber = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumber);
            NWN.Internal.NativeFunctions.StackPushString(sPattern);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(176);
        }

        //  * Returns TRUE if sStringToTest matches sPattern.
        public static int TestStringAgainstPattern(string sPattern, string sStringToTest)
        {
            NWN.Internal.NativeFunctions.StackPushString(sStringToTest);
            NWN.Internal.NativeFunctions.StackPushString(sPattern);
            NWN.Internal.NativeFunctions.CallBuiltIn(177);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the appropriate matched string (this should only be used in
        //  OnConversation scripts).
        //  * Returns the appropriate matched string, otherwise returns ""
        public static string GetMatchedSubstring(int nString)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nString);
            NWN.Internal.NativeFunctions.CallBuiltIn(178);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the number of string parameters available.
        //  * Returns -1 if no string matched (this could be because of a dialogue event)
        public static int GetMatchedSubstringsCount()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(179);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Create a Visual Effect that can be applied to an object.
        //  - nVisualEffectId
        //  - nMissEffect: if this is TRUE, a random vector near or past the target will
        //    be generated, on which to play the effect
        public static NWN.Effect EffectVisualEffect(int nVisualEffectId, int nMissEffect = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMissEffect);
            NWN.Internal.NativeFunctions.StackPushInteger(nVisualEffectId);
            NWN.Internal.NativeFunctions.CallBuiltIn(180);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the weakest member of oFactionMember's faction.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionWeakestMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(181);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the strongest member of oFactionMember's faction.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionStrongestMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(182);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the member of oFactionMember's faction that has taken the most hit points
        //  of damage.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionMostDamagedMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(183);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the member of oFactionMember's faction that has taken the fewest hit
        //  points of damage.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionLeastDamagedMember(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(184);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the amount of gold held by oFactionMember's faction.
        //  * Returns -1 if oFactionMember's faction is invalid.
        public static int GetFactionGold(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(185);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents how
        //  oSourceFactionMember's faction feels about oTarget.
        //  * Return value on error: -1
        public static int GetFactionAverageReputation(NWN.Object oSourceFactionMember, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oSourceFactionMember != null ? oSourceFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(186);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents the average
        //  good/evil alignment of oFactionMember's faction.
        //  * Return value on error: -1
        public static int GetFactionAverageGoodEvilAlignment(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(187);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get an integer between 0 and 100 (inclusive) that represents the average
        //  law/chaos alignment of oFactionMember's faction.
        //  * Return value on error: -1
        public static int GetFactionAverageLawChaosAlignment(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(188);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the average level of the members of the faction.
        //  * Return value on error: -1
        public static int GetFactionAverageLevel(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(189);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the average XP of the members of the faction.
        //  * Return value on error: -1
        public static int GetFactionAverageXP(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(190);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the most frequent class in the faction - this can be compared with the
        //  constants CLASS_TYPE_*.
        //  * Return value on error: -1
        public static int GetFactionMostFrequentClass(NWN.Object oFactionMember)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(191);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the object faction member with the lowest armour class.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionWorstAC(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(192);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the object faction member with the highest armour class.
        //  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
        public static NWN.Object GetFactionBestAC(NWN.Object oFactionMember = null, int bMustBeVisible = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMustBeVisible);
            NWN.Internal.NativeFunctions.StackPushObject(oFactionMember != null ? oFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(193);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Sit in oChair.
        //  Note: Not all creatures will be able to sit and not all
        //        objects can be sat on.
        //        The object oChair must also be marked as usable in the toolset.
        // 
        //  For Example: To get a player to sit in oChair when they click on it,
        //  place the following script in the OnUsed event for the object oChair.
        //  void main()
        //  {
        //     object oChair = OBJECT_SELF;
        //     AssignCommand(GetLastUsedBy(),ActionSit(oChair));
        //  }
        public static void ActionSit(NWN.Object oChair)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oChair != null ? oChair.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(194);
        }

        //  In an onConversation script this gets the number of the string pattern
        //  matched (the one that triggered the script).
        //  * Returns -1 if no string matched
        public static int GetListenPatternNumber()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(195);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Jump to an object ID, or as near to it as possible.
        public static void ActionJumpToObject(NWN.Object oToJumpTo, int bWalkStraightLineToPoint = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bWalkStraightLineToPoint);
            NWN.Internal.NativeFunctions.StackPushObject(oToJumpTo != null ? oToJumpTo.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(196);
        }

        //  Get the first waypoint with the specified tag.
        //  * Returns OBJECT_INVALID if the waypoint cannot be found.
        public static NWN.Object GetWaypointByTag(string sWaypointTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sWaypointTag);
            NWN.Internal.NativeFunctions.CallBuiltIn(197);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the destination object for the given object.
        // 
        //  All objects can hold a transition target, but only Doors and Triggers
        //  will be made clickable by the game engine (This may change in the
        //  future). You can set and query transition targets on other objects for
        //  your own scripted purposes.
        // 
        //  * Returns OBJECT_INVALID if oTransition does not hold a target.
        public static NWN.Object GetTransitionTarget(NWN.Object oTransition)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTransition != null ? oTransition.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(198);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Link the two supplied effects, returning eChildEffect as a child of
        //  eParentEffect.
        //  Note: When applying linked effects if the target is immune to all valid
        //  effects all other effects will be removed as well. This means that if you
        //  apply a visual effect and a silence effect (in a link) and the target is
        //  immune to the silence effect that the visual effect will get removed as well.
        //  Visual Effects are not considered "valid" effects for the purposes of
        //  determining if an effect will be removed or not and as such should never be
        //  packaged *only* with other visual effects in a link.
        public static NWN.Effect EffectLinkEffects(NWN.Effect eChildEffect, NWN.Effect eParentEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eParentEffect.Handle);
            NWN.Internal.NativeFunctions.StackPushEffect(eChildEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(199);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the nNth object with the specified tag.
        //  - sTag
        //  - nNth: the nth object with this tag may be requested
        //  * Returns OBJECT_INVALID if the object cannot be found.
        //  Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
        public static NWN.Object GetObjectByTag(string sTag, int nNth = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushString(sTag);
            NWN.Internal.NativeFunctions.CallBuiltIn(200);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Adjust the alignment of oSubject.
        //  - oSubject
        //  - nAlignment:
        //    -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
        //       alignment will be shifted in the direction specified
        //    -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
        //       good/evil alignment values
        //    -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
        //       good/evil alignment values in the direction which is towards neutrality.
        //      e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
        //           good/evil value of 80 (i.e. good) then if nShift is 15, the
        //           law/chaos value will become (10+15)=25 and the good/evil value will
        //           become (80-25)=55
        //      Furthermore, the shift will at most take the alignment value to 50 and
        //      not beyond.
        //      e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
        //           then if nShift is 15, the law/chaos value will become 50 and the
        //           good/evil value will become 55
        //  - nShift: this is the desired shift in alignment
        //  - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a 
        //                      diminished affect all members of oSubject's party (if oSubject is a Player).
        //                      When FALSE the shift only affects oSubject.
        //  * No return value
        public static void AdjustAlignment(NWN.Object oSubject, int nAlignment, int nShift, int bAllPartyMembers = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bAllPartyMembers);
            NWN.Internal.NativeFunctions.StackPushInteger(nShift);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignment);
            NWN.Internal.NativeFunctions.StackPushObject(oSubject != null ? oSubject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(201);
        }

        //  Do nothing for fSeconds seconds.
        public static void ActionWait(float fSeconds)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fSeconds);
            NWN.Internal.NativeFunctions.CallBuiltIn(202);
        }

        //  Set the transition bitmap of a player; this should only be called in area
        //  transition scripts. This action should be run by the person "clicking" the
        //  area transition via AssignCommand.
        //  - nPredefinedAreaTransition:
        //    -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
        //    -> To use a custom, user-defined area transition bitmap, use
        //       AREA_TRANSITION_USER_DEFINED and specify the filename in the second
        //       parameter
        //  - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined
        //    area transition bitmap
        public static void SetAreaTransitionBMP(int nPredefinedAreaTransition, string sCustomAreaTransitionBMP = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sCustomAreaTransitionBMP);
            NWN.Internal.NativeFunctions.StackPushInteger(nPredefinedAreaTransition);
            NWN.Internal.NativeFunctions.CallBuiltIn(203);
        }

        //  Starts a conversation with oObjectToConverseWith - this will cause their
        //  OnDialog event to fire.
        //  - oObjectToConverseWith
        //  - sDialogResRef: If this is blank, the creature's own dialogue file will be used
        //  - bPrivateConversation
        //  Turn off bPlayHello if you don't want the initial greeting to play
        public static void ActionStartConversation(NWN.Object oObjectToConverseWith, string sDialogResRef = "", int bPrivateConversation = FALSE, int bPlayHello = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPlayHello);
            NWN.Internal.NativeFunctions.StackPushInteger(bPrivateConversation);
            NWN.Internal.NativeFunctions.StackPushString(sDialogResRef);
            NWN.Internal.NativeFunctions.StackPushObject(oObjectToConverseWith != null ? oObjectToConverseWith.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(204);
        }

        //  Pause the current conversation.
        public static void ActionPauseConversation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(205);
        }

        //  Resume a conversation after it has been paused.
        public static void ActionResumeConversation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(206);
        }

        //  Create a Beam effect.
        //  - nBeamVisualEffect: VFX_BEAM_*
        //  - oEffector: the beam is emitted from this creature
        //  - nBodyPart: BODY_NODE_*
        //  - bMissEffect: If this is TRUE, the beam will fire to a random vector near or
        //    past the target
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
        //    not valid.
        public static NWN.Effect EffectBeam(int nBeamVisualEffect, NWN.Object oEffector, int nBodyPart, int bMissEffect = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bMissEffect);
            NWN.Internal.NativeFunctions.StackPushInteger(nBodyPart);
            NWN.Internal.NativeFunctions.StackPushObject(oEffector != null ? oEffector.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nBeamVisualEffect);
            NWN.Internal.NativeFunctions.CallBuiltIn(207);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get an integer between 0 and 100 (inclusive) that represents how oSource
        //  feels about oTarget.
        //  -> 0-10 means oSource is hostile to oTarget
        //  -> 11-89 means oSource is neutral to oTarget
        //  -> 90-100 means oSource is friendly to oTarget
        //  * Returns -1 if oSource or oTarget does not identify a valid object
        public static int GetReputation(NWN.Object oSource, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(208);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Adjust how oSourceFactionMember's faction feels about oTarget by the
        //  specified amount.
        //  Note: This adjusts Faction Reputation, how the entire faction that
        //  oSourceFactionMember is in, feels about oTarget.
        //  * No return value
        //  Note: You can't adjust a player character's (PC) faction towards
        //        NPCs, so attempting to make an NPC hostile by passing in a PC object
        //        as oSourceFactionMember in the following call will fail:
        //        AdjustReputation(oNPC,oPC,-100);
        //        Instead you should pass in the PC object as the first
        //        parameter as in the following call which should succeed: 
        //        AdjustReputation(oPC,oNPC,-100);
        //  Note: Will fail if oSourceFactionMember is a plot object.
        public static void AdjustReputation(NWN.Object oTarget, NWN.Object oSourceFactionMember, int nAdjustment)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAdjustment);
            NWN.Internal.NativeFunctions.StackPushObject(oSourceFactionMember != null ? oSourceFactionMember.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(209);
        }

        //  Get the creature that is currently sitting on the specified object.
        //  - oChair
        //  * Returns OBJECT_INVALID if oChair is not a valid placeable.
        public static NWN.Object GetSittingCreature(NWN.Object oChair)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oChair != null ? oChair.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(210);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the creature that is going to attack oTarget.
        //  Note: This value is cleared out at the end of every combat round and should
        //  not be used in any case except when getting a "going to be attacked" shout
        //  from the master creature (and this creature is a henchman)
        //  * Returns OBJECT_INVALID if oTarget is not a valid creature.
        public static NWN.Object GetGoingToBeAttackedBy(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(211);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create a Spell Resistance Increase effect.
        //  - nValue: size of spell resistance increase
        public static NWN.Effect EffectSpellResistanceIncrease(int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(212);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the location of oObject.
        public static NWN.Location GetLocation(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(213);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  The subject will jump to lLocation instantly (even between areas).
        //  If lLocation is invalid, nothing will happen.
        public static void ActionJumpToLocation(NWN.Location lLocation)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(214);
        }

        //  Create a location.
        public static NWN.Location Location(NWN.Object oArea, NWN.Vector? vPosition, float fOrientation)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fOrientation);
            NWN.Internal.NativeFunctions.StackPushVector(vPosition.HasValue ? vPosition.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(215);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  Apply eEffect at lLocation.
        public static void ApplyEffectAtLocation(int nDurationType, NWN.Effect eEffect, NWN.Location lLocation, float fDuration = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDuration);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nDurationType);
            NWN.Internal.NativeFunctions.CallBuiltIn(216);
        }

        //  * Returns TRUE if oCreature is a Player Controlled character.
        public static int GetIsPC(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(217);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Convert fFeet into a number of meters.
        public static float FeetToMeters(float fFeet)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fFeet);
            NWN.Internal.NativeFunctions.CallBuiltIn(218);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Convert fYards into a number of meters.
        public static float YardsToMeters(float fYards)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fYards);
            NWN.Internal.NativeFunctions.CallBuiltIn(219);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Apply eEffect to oTarget.
        public static void ApplyEffectToObject(int nDurationType, NWN.Effect eEffect, NWN.Object oTarget, float fDuration = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDuration);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nDurationType);
            NWN.Internal.NativeFunctions.CallBuiltIn(220);
        }

        //  The caller will immediately speak sStringToSpeak (this is different from
        //  ActionSpeakString)
        //  - sStringToSpeak
        //  - nTalkVolume: TALKVOLUME_*
        public static void SpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTalkVolume);
            NWN.Internal.NativeFunctions.StackPushString(sStringToSpeak);
            NWN.Internal.NativeFunctions.CallBuiltIn(221);
        }

        //  Get the location of the caller's last spell target.
        public static NWN.Location GetSpellTargetLocation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(222);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  Get the position vector from lLocation.
        public static NWN.Vector GetPositionFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(223);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  Get the area's object ID from lLocation.
        public static NWN.Object GetAreaFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(224);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the orientation value from lLocation.
        public static float GetFacingFromLocation(NWN.Location lLocation)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(225);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get the creature nearest to lLocation, subject to all the criteria specified.
        //  - nFirstCriteriaType: CREATURE_TYPE_*
        //  - nFirstCriteriaValue:
        //    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
        //    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
        //       or CREATURE_TYPE_HAS_SPELL_EFFECT
        //    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
        //    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
        //    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
        //       CREATURE_TYPE_PLAYER_CHAR
        //    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
        //    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
        //    For example, to get the nearest PC, use
        //    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
        //  - lLocation: We're trying to find the creature of the specified type that is
        //    nearest to lLocation
        //  - nNth: We don't have to find the first nearest: we can find the Nth nearest....
        //  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
        //    to further specify the type of creature that we are looking for.
        //  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
        //    further specify the type of creature that we are looking for.
        //  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
        //    further specify the type of creature that we are looking for.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, NWN.Location lLocation, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nThirdCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nThirdCriteriaType);
            NWN.Internal.NativeFunctions.StackPushInteger(nSecondCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSecondCriteriaType);
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nFirstCriteriaValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nFirstCriteriaType);
            NWN.Internal.NativeFunctions.CallBuiltIn(226);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the Nth object nearest to oTarget that is of the specified type.
        //  - nObjectType: OBJECT_TYPE_*
        //  - oTarget
        //  - nNth
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObject(int nObjectType = OBJECT_TYPE_ALL, NWN.Object oTarget = null, int nNth = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nObjectType);
            NWN.Internal.NativeFunctions.CallBuiltIn(227);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the nNth object nearest to lLocation that is of the specified type.
        //  - nObjectType: OBJECT_TYPE_*
        //  - lLocation
        //  - nNth
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObjectToLocation(int nObjectType, NWN.Location lLocation, int nNth = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nObjectType);
            NWN.Internal.NativeFunctions.CallBuiltIn(228);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the nth Object nearest to oTarget that has sTag as its tag.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetNearestObjectByTag(string sTag, NWN.Object oTarget = null, int nNth = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sTag);
            NWN.Internal.NativeFunctions.CallBuiltIn(229);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Convert nInteger into a floating point number.
        public static float IntToFloat(int nInteger)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInteger);
            NWN.Internal.NativeFunctions.CallBuiltIn(230);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Convert fFloat into the nearest integer.
        public static int FloatToInt(float fFloat)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fFloat);
            NWN.Internal.NativeFunctions.CallBuiltIn(231);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Convert sNumber into an integer.
        public static int StringToInt(string sNumber)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNumber);
            NWN.Internal.NativeFunctions.CallBuiltIn(232);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Convert sNumber into a floating point number.
        public static float StringToFloat(string sNumber)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNumber);
            NWN.Internal.NativeFunctions.CallBuiltIn(233);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Cast spell nSpell at lTargetLocation.
        //  - nSpell: SPELL_*
        //  - lTargetLocation
        //  - nMetaMagic: METAMAGIC_*
        //  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
        //    able to cast the spell.
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        //  - bInstantSpell: If this is TRUE, the spell is cast immediately; this allows
        //    the end-user to simulate
        //    a high-level magic user having lots of advance warning of impending trouble.
        public static void ActionCastSpellAtLocation(int nSpell, NWN.Location lTargetLocation, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bInstantSpell);
            NWN.Internal.NativeFunctions.StackPushInteger(nProjectilePathType);
            NWN.Internal.NativeFunctions.StackPushInteger(bCheat);
            NWN.Internal.NativeFunctions.StackPushInteger(nMetaMagic);
            NWN.Internal.NativeFunctions.StackPushLocation(lTargetLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(234);
        }

        //  * Returns TRUE if oSource considers oTarget as an enemy.
        public static int GetIsEnemy(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(235);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if oSource considers oTarget as a friend.
        public static int GetIsFriend(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(236);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if oSource considers oTarget as neutral.
        public static int GetIsNeutral(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(237);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the PC that is involved in the conversation.
        //  * Returns OBJECT_INVALID on error.
        public static NWN.Object GetPCSpeaker()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(238);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get a string from the talk table using nStrRef.
        public static string GetStringByStrRef(int nStrRef, int nGender = GENDER_MALE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nGender);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(239);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Causes the creature to speak a translated string.
        //  - nStrRef: Reference of the string in the talk table
        //  - nTalkVolume: TALKVOLUME_*
        public static void ActionSpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTalkVolume);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(240);
        }

        //  Destroy oObject (irrevocably).
        //  This will not work on modules and areas.
        public static void DestroyObject(NWN.Object oDestroy, float fDelay = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDelay);
            NWN.Internal.NativeFunctions.StackPushObject(oDestroy != null ? oDestroy.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(241);
        }

        //  Get the module.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetModule()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(242);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create an object of the specified type at lLocation.
        //  - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
        //    OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
        //  - sTemplate
        //  - lLocation
        //  - bUseAppearAnimation
        //  - sNewTag - if this string is not empty, it will replace the default tag from the template
        public static NWN.Object CreateObject(int nObjectType, string sTemplate, NWN.Location lLocation, int bUseAppearAnimation = FALSE, string sNewTag = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushInteger(bUseAppearAnimation);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushString(sTemplate);
            NWN.Internal.NativeFunctions.StackPushInteger(nObjectType);
            NWN.Internal.NativeFunctions.CallBuiltIn(243);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create an event which triggers the "SpellCastAt" script
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created SpellCastAt event as an argument.
        //  For example:
        //      SignalEvent(oCreature, EventSpellCastAt(oCaster, SPELL_MAGIC_MISSILE, TRUE));
        //  This function doesn't cast the spell specified, it only creates an event so that
        //  when the event is signaled on an object, the object will use its OnSpellCastAt script
        //  to react to the spell being cast.
        // 
        //  To specify the OnSpellCastAt script that should run, view the Object's Properties 
        //  and click on the Scripts Tab. Then specify a script for the OnSpellCastAt event.
        //  From inside the OnSpellCastAt script call:
        //      GetLastSpellCaster() to get the object that cast the spell (oCaster).
        //      GetLastSpell() to get the type of spell cast (nSpell)
        //      GetLastSpellHarmful() to determine if the spell cast at the object was harmful.
        public static NWN.Event EventSpellCastAt(NWN.Object oCaster, int nSpell, int bHarmful = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bHarmful);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.StackPushObject(oCaster != null ? oCaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(244);
            return new NWN.Event(NWN.Internal.NativeFunctions.StackPopEvent());
        }

        //  This is for use in a "Spell Cast" script, it gets who cast the spell.
        //  The spell could have been cast by a creature, placeable or door.
        //  * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
        public static NWN.Object GetLastSpellCaster()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(245);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  This is for use in a "Spell Cast" script, it gets the ID of the spell that
        //  was cast.
        public static int GetLastSpell()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(246);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  This is for use in a user-defined script, it gets the event number.
        public static int GetUserDefinedEventNumber()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(247);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  This is for use in a Spell script, it gets the ID of the spell that is being
        //  cast (SPELL_*).
        public static int GetSpellId()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(248);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Generate a random name.
        //  nNameType: The type of random name to be generated (NAME_*)
        public static string RandomName(int nNameType = NAME_FIRST_GENERIC_MALE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNameType);
            NWN.Internal.NativeFunctions.CallBuiltIn(249);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Create a Poison effect.
        //  - nPoisonType: POISON_*
        public static NWN.Effect EffectPoison(int nPoisonType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPoisonType);
            NWN.Internal.NativeFunctions.CallBuiltIn(250);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Disease effect.
        //  - nDiseaseType: DISEASE_*
        public static NWN.Effect EffectDisease(int nDiseaseType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDiseaseType);
            NWN.Internal.NativeFunctions.CallBuiltIn(251);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Silence effect.
        public static NWN.Effect EffectSilence()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(252);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set the name of oObject.
        // 
        //  - oObject: the object for which you are changing the name (area, creature, placeable, item, or door).
        //  - sNewName: the new name that the object will use.
        //  Note: SetName() does not work on player objects.
        //        Setting an object's name to "" will make the object
        //        revert to using the name it had originally before any
        //        SetName() calls were made on the object.
        public static string GetName(NWN.Object oObject, int bOriginalName = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bOriginalName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(253);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Use this in a conversation script to get the person with whom you are conversing.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetLastSpeaker()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(254);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnDialog script to start up the dialog tree.
        //  - sResRef: if this is not specified, the default dialog file will be used
        //  - oObjectToDialog: if this is not specified the person that triggered the
        //    event will be used
        public static int BeginConversation(string sResRef = "", NWN.Object oObjectToDialog = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObjectToDialog != null ? oObjectToDialog.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sResRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(255);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnPerception script to get the object that was perceived.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetLastPerceived()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(256);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived was heard.
        public static int GetLastPerceptionHeard()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(257);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived has become inaudible.
        public static int GetLastPerceptionInaudible()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(258);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived was seen.
        public static int GetLastPerceptionSeen()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(259);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnClosed script to get the object that closed the door or placeable.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastClosedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(260);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnPerception script to determine whether the object that was
        //  perceived has vanished.
        public static int GetLastPerceptionVanished()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(261);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the first object within oPersistentObject.
        //  - oPersistentObject
        //  - nResidentObjectType: OBJECT_TYPE_*
        //  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
        //    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
        //  * Returns OBJECT_INVALID if no object is found.
        public static NWN.Object GetFirstInPersistentObject(NWN.Object oPersistentObject = null, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPersistentZone);
            NWN.Internal.NativeFunctions.StackPushInteger(nResidentObjectType);
            NWN.Internal.NativeFunctions.StackPushObject(oPersistentObject != null ? oPersistentObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(262);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next object within oPersistentObject.
        //  - oPersistentObject
        //  - nResidentObjectType: OBJECT_TYPE_*
        //  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
        //    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
        //  * Returns OBJECT_INVALID if no object is found.
        public static NWN.Object GetNextInPersistentObject(NWN.Object oPersistentObject = null, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPersistentZone);
            NWN.Internal.NativeFunctions.StackPushInteger(nResidentObjectType);
            NWN.Internal.NativeFunctions.StackPushObject(oPersistentObject != null ? oPersistentObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(263);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  This returns the creator of oAreaOfEffectObject.
        //  * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
        public static NWN.Object GetAreaOfEffectCreator(NWN.Object oAreaOfEffectObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAreaOfEffectObject != null ? oAreaOfEffectObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(264);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Delete oObject's local integer variable sVarName
        public static void DeleteLocalInt(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(265);
        }

        //  Delete oObject's local float variable sVarName
        public static void DeleteLocalFloat(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(266);
        }

        //  Delete oObject's local string variable sVarName
        public static void DeleteLocalString(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(267);
        }

        //  Delete oObject's local object variable sVarName
        public static void DeleteLocalObject(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(268);
        }

        //  Delete oObject's local location variable sVarName
        public static void DeleteLocalLocation(NWN.Object oObject, string sVarName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(269);
        }

        //  Create a Haste effect.
        public static NWN.Effect EffectHaste()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(270);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Slow effect.
        public static NWN.Effect EffectSlow()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(271);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Convert oObject into a hexadecimal string.
        public static string ObjectToString(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(272);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Create an Immunity effect.
        //  - nImmunityType: IMMUNITY_TYPE_*
        public static NWN.Effect EffectImmunity(int nImmunityType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nImmunityType);
            NWN.Internal.NativeFunctions.CallBuiltIn(273);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  - oCreature
        //  - nImmunityType: IMMUNITY_TYPE_*
        //  - oVersus: if this is specified, then we also check for the race and
        //    alignment of oVersus
        //  * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
        public static int GetIsImmune(NWN.Object oCreature, int nImmunityType, NWN.Object oVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oVersus != null ? oVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nImmunityType);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(274);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Creates a Damage Immunity Increase effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nPercentImmunity
        public static NWN.Effect EffectDamageImmunityIncrease(int nDamageType, int nPercentImmunity)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentImmunity);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(275);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Determine whether oEncounter is active.
        public static int GetEncounterActive(NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(276);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set oEncounter's active state to nNewValue.
        //  - nNewValue: TRUE/FALSE
        //  - oEncounter
        public static void SetEncounterActive(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nNewValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(277);
        }

        //  Get the maximum number of times that oEncounter will spawn.
        public static int GetEncounterSpawnsMax(NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(278);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the maximum number of times that oEncounter can spawn
        public static void SetEncounterSpawnsMax(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nNewValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(279);
        }

        //  Get the number of times that oEncounter has spawned so far
        public static int GetEncounterSpawnsCurrent(NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(280);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the number of times that oEncounter has spawned so far
        public static void SetEncounterSpawnsCurrent(int nNewValue, NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nNewValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(281);
        }

        //  Use this in an OnItemAcquired script to get the item that was acquired.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemAcquired()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(282);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemAcquired script to get the creatre that previously
        //  possessed the item.
        //  * Returns OBJECT_INVALID if the item was picked up from the ground.
        public static NWN.Object GetModuleItemAcquiredFrom()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(283);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Set the value for a custom token.
        public static void SetCustomToken(int nCustomTokenNumber, string sTokenValue)
        {
            NWN.Internal.NativeFunctions.StackPushString(sTokenValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nCustomTokenNumber);
            NWN.Internal.NativeFunctions.CallBuiltIn(284);
        }

        //  Determine whether oCreature has nFeat, and nFeat is useable.
        //  - nFeat: FEAT_*
        //  - oCreature
        public static int GetHasFeat(int nFeat, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.CallBuiltIn(285);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oCreature has nSkill, and nSkill is useable.
        //  - nSkill: SKILL_*
        //  - oCreature
        public static int GetHasSkill(int nSkill, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(286);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use nFeat on oTarget.
        //  - nFeat: FEAT_*
        //  - oTarget
        public static void ActionUseFeat(int nFeat, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.CallBuiltIn(287);
        }

        //  Runs the action "UseSkill" on the current creature
        //  Use nSkill on oTarget.
        //  - nSkill: SKILL_*
        //  - oTarget
        //  - nSubSkill: SUBSKILL_*
        //  - oItemUsed: Item to use in conjunction with the skill
        public static void ActionUseSkill(int nSkill, NWN.Object oTarget, int nSubSkill = 0, NWN.Object oItemUsed = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItemUsed != null ? oItemUsed.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSubSkill);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(288);
        }

        //  Determine whether oSource sees oTarget.
        //  NOTE: This *only* works on creatures, as visibility lists are not
        //        maintained for non-creature objects.
        public static int GetObjectSeen(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(289);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oSource hears oTarget.
        //  NOTE: This *only* works on creatures, as visibility lists are not
        //        maintained for non-creature objects.
        public static int GetObjectHeard(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(290);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnPlayerDeath module script to get the last player that died.
        public static NWN.Object GetLastPlayerDied()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(291);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemLost script to get the item that was lost/dropped.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemLost()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(292);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemLost script to get the creature that lost the item.
        //  * Returns OBJECT_INVALID if the module is not valid.
        public static NWN.Object GetModuleItemLostBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(293);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Do aActionToDo.
        //  Creates a conversation event.
        //  Note: This only creates the event. The event wont actually trigger until SignalEvent()
        //  is called using this created conversation event as an argument.
        //  For example:
        //      SignalEvent(oCreature, EventConversation());
        //  Once the event has been signaled. The script associated with the OnConversation event will
        //  run on the creature oCreature.
        // 
        //  To specify the OnConversation script that should run, view the Creature Properties on
        //  the creature and click on the Scripts Tab. Then specify a script for the OnConversation event.
        public static NWN.Event EventConversation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(295);
            return new NWN.Event(NWN.Internal.NativeFunctions.StackPopEvent());
        }

        //  Set the difficulty level of oEncounter.
        //  - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*
        //  - oEncounter
        public static void SetEncounterDifficulty(int nEncounterDifficulty, NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nEncounterDifficulty);
            NWN.Internal.NativeFunctions.CallBuiltIn(296);
        }

        //  Get the difficulty level of oEncounter.
        public static int GetEncounterDifficulty(NWN.Object oEncounter = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oEncounter != null ? oEncounter.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(297);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the distance between lLocationA and lLocationB.
        public static float GetDistanceBetweenLocations(NWN.Location lLocationA, NWN.Location lLocationB)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lLocationB.Handle);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocationA.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(298);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
        //  evasion saves.
        //  - nDamage
        //  - oTarget
        //  - nDC: Difficulty check
        //  - nSaveType: SAVING_THROW_TYPE_*
        //  - oSaveVersus
        public static int GetReflexAdjustedDamage(int nDamage, NWN.Object oTarget, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, NWN.Object oSaveVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSaveVersus != null ? oSaveVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nDC);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.CallBuiltIn(299);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Play nAnimation immediately.
        //  - nAnimation: ANIMATION_*
        //  - fSpeed
        //  - fSeconds
        public static void PlayAnimation(int nAnimation, float fSpeed = 1.0f, float fSeconds = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fSeconds);
            NWN.Internal.NativeFunctions.StackPushFloat(fSpeed);
            NWN.Internal.NativeFunctions.StackPushInteger(nAnimation);
            NWN.Internal.NativeFunctions.CallBuiltIn(300);
        }

        //  Create a Spell Talent.
        //  - nSpell: SPELL_*
        public static NWN.Talent TalentSpell(int nSpell)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(301);
            return new NWN.Talent(NWN.Internal.NativeFunctions.StackPopTalent());
        }

        //  Create a Feat Talent.
        //  - nFeat: FEAT_*
        public static NWN.Talent TalentFeat(int nFeat)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.CallBuiltIn(302);
            return new NWN.Talent(NWN.Internal.NativeFunctions.StackPopTalent());
        }

        //  Create a Skill Talent.
        //  - nSkill: SKILL_*
        public static NWN.Talent TalentSkill(int nSkill)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(303);
            return new NWN.Talent(NWN.Internal.NativeFunctions.StackPopTalent());
        }

        //  Determines whether oObject has any effects applied by nSpell
        //  - nSpell: SPELL_*
        //  - oObject
        //  * The spell id on effects is only valid if the effect is created
        //    when the spell script runs. If it is created in a delayed command
        //    then the spell id on the effect will be invalid.
        public static int GetHasSpellEffect(int nSpell, NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(304);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the spell (SPELL_*) that applied eSpellEffect.
        //  * Returns -1 if eSpellEffect was applied outside a spell script.
        public static int GetEffectSpellId(NWN.Effect eSpellEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eSpellEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(305);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oCreature has tTalent.
        public static int GetCreatureHasTalent(NWN.Talent tTalent, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushTalent(tTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(306);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get a random talent of oCreature, within nCategory.
        //  - nCategory: TALENT_CATEGORY_*
        //  - oCreature
        public static NWN.Talent GetCreatureTalentRandom(int nCategory, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nCategory);
            NWN.Internal.NativeFunctions.CallBuiltIn(307);
            return new NWN.Talent(NWN.Internal.NativeFunctions.StackPopTalent());
        }

        //  Get the best talent (i.e. closest to nCRMax without going over) of oCreature,
        //  within nCategory.
        //  - nCategory: TALENT_CATEGORY_*
        //  - nCRMax: Challenge Rating of the talent
        //  - oCreature
        public static NWN.Talent GetCreatureTalentBest(int nCategory, int nCRMax, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nCRMax);
            NWN.Internal.NativeFunctions.StackPushInteger(nCategory);
            NWN.Internal.NativeFunctions.CallBuiltIn(308);
            return new NWN.Talent(NWN.Internal.NativeFunctions.StackPopTalent());
        }

        //  Use tChosenTalent on oTarget.
        public static void ActionUseTalentOnObject(NWN.Talent tChosenTalent, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushTalent(tChosenTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(309);
        }

        //  Use tChosenTalent at lTargetLocation.
        public static void ActionUseTalentAtLocation(NWN.Talent tChosenTalent, NWN.Location lTargetLocation)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lTargetLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushTalent(tChosenTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(310);
        }

        //  Get the gold piece value of oItem.
        //  * Returns 0 if oItem is not a valid item.
        public static int GetGoldPieceValue(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(311);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if oCreature is of a playable racial type.
        public static int GetIsPlayableRacialType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(312);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Jump to lDestination.  The action is added to the TOP of the action queue.
        public static void JumpToLocation(NWN.Location lDestination)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lDestination.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(313);
        }

        //  Create a Temporary Hitpoints effect.
        //  - nHitPoints: a positive integer
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
        public static NWN.Effect EffectTemporaryHitpoints(int nHitPoints)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHitPoints);
            NWN.Internal.NativeFunctions.CallBuiltIn(314);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the number of ranks that oTarget has in nSkill.
        //  - nSkill: SKILL_*
        //  - oTarget
        //  - nBaseSkillRank: if set to true returns the number of base skill ranks the target
        //                    has (i.e. not including any bonuses from ability scores, feats, etc).
        //  * Returns -1 if oTarget doesn't have nSkill.
        //  * Returns 0 if nSkill is untrained.
        public static int GetSkillRank(int nSkill, NWN.Object oTarget = null, int nBaseSkillRank = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBaseSkillRank);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(315);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the attack target of oCreature.
        //  This only works when oCreature is in combat.
        public static NWN.Object GetAttackTarget(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(316);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
        //  This only works when oCreature is in combat.
        public static int GetLastAttackType(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(317);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
        //  This only works when oCreature is in combat.
        public static int GetLastAttackMode(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(318);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the master of oAssociate.
        public static NWN.Object GetMaster(NWN.Object oAssociate = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAssociate != null ? oAssociate.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(319);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  * Returns TRUE if oCreature is in combat.
        public static int GetIsInCombat(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(320);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
        public static int GetLastAssociateCommand(NWN.Object oAssociate = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAssociate != null ? oAssociate.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(321);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Give nGP gold to oCreature.
        public static void GiveGoldToCreature(NWN.Object oCreature, int nGP)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nGP);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(322);
        }

        //  Set the destroyable status of the caller.
        //  - bDestroyable: If this is FALSE, the caller does not fade out on death, but
        //    sticks around as a corpse.
        //  - bRaiseable: If this is TRUE, the caller can be raised via resurrection.
        //  - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.
        public static void SetIsDestroyable(int bDestroyable, int bRaiseable = TRUE, int bSelectableWhenDead = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bSelectableWhenDead);
            NWN.Internal.NativeFunctions.StackPushInteger(bRaiseable);
            NWN.Internal.NativeFunctions.StackPushInteger(bDestroyable);
            NWN.Internal.NativeFunctions.CallBuiltIn(323);
        }

        //  Set the locked state of oTarget, which can be a door or a placeable object.
        public static void SetLocked(NWN.Object oTarget, int bLocked)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bLocked);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(324);
        }

        //  Get the locked state of oTarget, which can be a door or a placeable object.
        public static int GetLocked(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(325);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in a trigger's OnClick event script to get the object that last
        //  clicked on it.
        //  This is identical to GetEnteringObject.
        //  GetClickingObject() should not be called from a placeable's OnClick event,
        //  instead use GetPlaceableLastClickedBy();
        public static NWN.Object GetClickingObject()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(326);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Initialise oTarget to listen for the standard Associates commands.
        public static void SetAssociateListenPatterns(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(327);
        }

        //  Get the last weapon that oCreature used in an attack.
        //  * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
        public static NWN.Object GetLastWeaponUsed(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(328);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use oPlaceable.
        public static void ActionInteractObject(NWN.Object oPlaceable)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(329);
        }

        //  Get the last object that used the placeable object that is calling this function.
        //  * Returns OBJECT_INVALID if it is called by something other than a placeable or
        //    a door.
        public static NWN.Object GetLastUsedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(330);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Returns the ability modifier for the specified ability
        //  Get oCreature's ability modifier for nAbility.
        //  - nAbility: ABILITY_*
        //  - oCreature
        public static int GetAbilityModifier(int nAbility, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbility);
            NWN.Internal.NativeFunctions.CallBuiltIn(331);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determined whether oItem has been identified.
        public static int GetIdentified(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(332);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set whether oItem has been identified.
        public static void SetIdentified(NWN.Object oItem, int bIdentified)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bIdentified);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(333);
        }

        //  Summon an Animal Companion
        public static void SummonAnimalCompanion(NWN.Object oMaster = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(334);
        }

        //  Summon a Familiar
        public static void SummonFamiliar(NWN.Object oMaster = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(335);
        }

        //  Get the last blocking door encountered by the caller of this function.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetBlockingDoor()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(336);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  - oTargetDoor
        //  - nDoorAction: DOOR_ACTION_*
        //  * Returns TRUE if nDoorAction can be performed on oTargetDoor.
        public static int GetIsDoorActionPossible(NWN.Object oTargetDoor, int nDoorAction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDoorAction);
            NWN.Internal.NativeFunctions.StackPushObject(oTargetDoor != null ? oTargetDoor.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(337);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Perform nDoorAction on oTargetDoor.
        public static void DoDoorAction(NWN.Object oTargetDoor, int nDoorAction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDoorAction);
            NWN.Internal.NativeFunctions.StackPushObject(oTargetDoor != null ? oTargetDoor.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(338);
        }

        //  Get the first item in oTarget's inventory (start to cycle through oTarget's
        //  inventory).
        //  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
        //    or if no item is found.
        public static NWN.Object GetFirstItemInInventory(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(339);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next item in oTarget's inventory (continue to cycle through oTarget's
        //  inventory).
        //  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
        //    or if no item is found.
        public static NWN.Object GetNextItemInInventory(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(340);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  A creature can have up to three classes.  This function determines the
        //  creature's class (CLASS_TYPE_*) based on nClassPosition.
        //  - nClassPosition: 1, 2 or 3
        //  - oCreature
        //  * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
        //    nClassPosition (i.e. a single-class creature will only have a value in
        //    nClassLocation=1) or if oCreature is not a valid creature.
        public static int GetClassByPosition(int nClassPosition, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nClassPosition);
            NWN.Internal.NativeFunctions.CallBuiltIn(341);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  A creature can have up to three classes.  This function determines the
        //  creature's class level based on nClass Position.
        //  - nClassPosition: 1, 2 or 3
        //  - oCreature
        //  * Returns 0 if oCreature does not have a class in nClassPosition
        //    (i.e. a single-class creature will only have a value in nClassLocation=1)
        //    or if oCreature is not a valid creature.
        public static int GetLevelByPosition(int nClassPosition, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nClassPosition);
            NWN.Internal.NativeFunctions.CallBuiltIn(342);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine the levels that oCreature holds in nClassType.
        //  - nClassType: CLASS_TYPE_*
        //  - oCreature
        public static int GetLevelByClass(int nClassType, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nClassType);
            NWN.Internal.NativeFunctions.CallBuiltIn(343);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the amount of damage of type nDamageType that has been dealt to the caller.
        //  - nDamageType: DAMAGE_TYPE_*
        public static int GetDamageDealtByType(int nDamageType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(344);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the total amount of damage that has been dealt to the caller.
        public static int GetTotalDamageDealt()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(345);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the last object that damaged oObject
        //  * Returns OBJECT_INVALID if the passed in object is not a valid object.
        public static NWN.Object GetLastDamager(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(346);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last object that disarmed the trap on the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
        //    door.
        public static NWN.Object GetLastDisarmed()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(347);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last object that disturbed the inventory of the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
        public static NWN.Object GetLastDisturbed()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(348);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last object that locked the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastLocked()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(349);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last object that unlocked the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
        public static NWN.Object GetLastUnlocked()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(350);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create a Skill Increase effect.
        //  - nSkill: SKILL_*
        //  - nValue
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
        public static NWN.Effect EffectSkillIncrease(int nSkill, int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(351);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
        //  OnInventoryDisturbed script to fire.  This will only work for creatures and
        //  placeables.
        public static int GetInventoryDisturbType()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(352);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  get the item that caused the caller's OnInventoryDisturbed script to fire.
        //  * Returns OBJECT_INVALID if the caller is not a valid object.
        public static NWN.Object GetInventoryDisturbItem()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(353);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the henchman belonging to oMaster.
        //  * Return OBJECT_INVALID if oMaster does not have a henchman.
        //  -nNth: Which henchman to return.
        public static NWN.Object GetHenchman(NWN.Object oMaster = null, int nNth = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNth);
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(354);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Set eEffect to be versus a specific alignment.
        //  - eEffect
        //  - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
        //  - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
        public static NWN.Effect VersusAlignmentEffect(NWN.Effect eEffect, int nLawChaos = ALIGNMENT_ALL, int nGoodEvil = ALIGNMENT_ALL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nGoodEvil);
            NWN.Internal.NativeFunctions.StackPushInteger(nLawChaos);
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(355);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set eEffect to be versus nRacialType.
        //  - eEffect
        //  - nRacialType: RACIAL_TYPE_*
        public static NWN.Effect VersusRacialTypeEffect(NWN.Effect eEffect, int nRacialType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRacialType);
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(356);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Set eEffect to be versus traps.
        public static NWN.Effect VersusTrapEffect(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(357);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the gender of oCreature.
        public static int GetGender(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(358);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if tTalent is valid.
        public static int GetIsTalentValid(NWN.Talent tTalent)
        {
            NWN.Internal.NativeFunctions.StackPushTalent(tTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(359);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Causes the action subject to move away from lMoveAwayFrom.
        public static void ActionMoveAwayFromLocation(NWN.Location lMoveAwayFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fMoveAwayRange);
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushLocation(lMoveAwayFrom.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(360);
        }

        //  Get the target that the caller attempted to attack - this should be used in
        //  conjunction with GetAttackTarget(). This value is set every time an attack is
        //  made, and is reset at the end of combat.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetAttemptedAttackTarget()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(361);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the type (TALENT_TYPE_*) of tTalent.
        public static int GetTypeFromTalent(NWN.Talent tTalent)
        {
            NWN.Internal.NativeFunctions.StackPushTalent(tTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(362);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the ID of tTalent.  This could be a SPELL_*, FEAT_* or SKILL_*.
        public static int GetIdFromTalent(NWN.Talent tTalent)
        {
            NWN.Internal.NativeFunctions.StackPushTalent(tTalent.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(363);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the associate of type nAssociateType belonging to oMaster.
        //  - nAssociateType: ASSOCIATE_TYPE_*
        //  - nMaster
        //  - nTh: Which associate of the specified type to return
        //  * Returns OBJECT_INVALID if no such associate exists.
        public static NWN.Object GetAssociate(int nAssociateType, NWN.Object oMaster = null, int nTh = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTh);
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nAssociateType);
            NWN.Internal.NativeFunctions.CallBuiltIn(364);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Add oHenchman as a henchman to oMaster
        //  If oHenchman is either a DM or a player character, this will have no effect.
        public static void AddHenchman(NWN.Object oMaster, NWN.Object oHenchman = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oHenchman != null ? oHenchman.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(365);
        }

        //  Remove oHenchman from the service of oMaster, returning them to their original faction.
        public static void RemoveHenchman(NWN.Object oMaster, NWN.Object oHenchman = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oHenchman != null ? oHenchman.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(366);
        }

        //  Add a journal quest entry to oCreature.
        //  - szPlotID: the plot identifier used in the toolset's Journal Editor
        //  - nState: the state of the plot as seen in the toolset's Journal Editor
        //  - oCreature
        //  - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of
        //    everyone in the party
        //  - bAllPlayers: If this is TRUE, the entry will show up in the journal of
        //    everyone in the world
        //  - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower
        //    number than the one it is currently on
        public static void AddJournalQuestEntry(string szPlotID, int nState, NWN.Object oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE, int bAllowOverrideHigher = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bAllowOverrideHigher);
            NWN.Internal.NativeFunctions.StackPushInteger(bAllPlayers);
            NWN.Internal.NativeFunctions.StackPushInteger(bAllPartyMembers);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nState);
            NWN.Internal.NativeFunctions.StackPushString(szPlotID);
            NWN.Internal.NativeFunctions.CallBuiltIn(367);
        }

        //  Remove a journal quest entry from oCreature.
        //  - szPlotID: the plot identifier used in the toolset's Journal Editor
        //  - oCreature
        //  - bAllPartyMembers: If this is TRUE, the entry will be removed from the
        //    journal of everyone in the party
        //  - bAllPlayers: If this is TRUE, the entry will be removed from the journal of
        //    everyone in the world
        public static void RemoveJournalQuestEntry(string szPlotID, NWN.Object oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bAllPlayers);
            NWN.Internal.NativeFunctions.StackPushInteger(bAllPartyMembers);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(szPlotID);
            NWN.Internal.NativeFunctions.CallBuiltIn(368);
        }

        //  Get the public part of the CD Key that oPlayer used when logging in.
        //  - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will 
        //    be returned when the player is playing in single player mode 
        //    (otherwise returns an empty string in single player mode).
        public static string GetPCPublicCDKey(NWN.Object oPlayer, int nSinglePlayerCDKey = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSinglePlayerCDKey);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(369);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the IP address from which oPlayer has connected.
        public static string GetPCIPAddress(NWN.Object oPlayer)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(370);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the name of oPlayer.
        public static string GetPCPlayerName(NWN.Object oPlayer)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(371);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Sets oPlayer and oTarget to like each other.
        public static void SetPCLike(NWN.Object oPlayer, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(372);
        }

        //  Sets oPlayer and oTarget to dislike each other.
        public static void SetPCDislike(NWN.Object oPlayer, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(373);
        }

        //  Send a server message (szMessage) to the oPlayer.
        public static void SendMessageToPC(NWN.Object oPlayer, string szMessage)
        {
            NWN.Internal.NativeFunctions.StackPushString(szMessage);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(374);
        }

        //  Get the target at which the caller attempted to cast a spell.
        //  This value is set every time a spell is cast and is reset at the end of
        //  combat.
        //  * Returns OBJECT_INVALID if the caller is not a valid creature.
        public static NWN.Object GetAttemptedSpellTarget()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(375);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last creature that opened the caller.
        //  * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
        public static NWN.Object GetLastOpenedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(376);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Determines the number of times that oCreature has nSpell memorised.
        //  - nSpell: SPELL_*
        //  - oCreature
        public static int GetHasSpell(int nSpell, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(377);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Open oStore for oPC.
        //  - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
        //  - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
        public static void OpenStore(NWN.Object oStore, NWN.Object oPC, int nBonusMarkUp = 0, int nBonusMarkDown = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonusMarkDown);
            NWN.Internal.NativeFunctions.StackPushInteger(nBonusMarkUp);
            NWN.Internal.NativeFunctions.StackPushObject(oPC != null ? oPC.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oStore != null ? oStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(378);
        }

        //  Create a Turned effect.
        //  Turned effects are supernatural by default.
        public static NWN.Effect EffectTurned()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(379);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the first member of oMemberOfFaction's faction (start to cycle through
        //  oMemberOfFaction's faction).
        //  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
        public static NWN.Object GetFirstFactionMember(NWN.Object oMemberOfFaction, int bPCOnly = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPCOnly);
            NWN.Internal.NativeFunctions.StackPushObject(oMemberOfFaction != null ? oMemberOfFaction.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(380);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next member of oMemberOfFaction's faction (continue to cycle through
        //  oMemberOfFaction's faction).
        //  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
        public static NWN.Object GetNextFactionMember(NWN.Object oMemberOfFaction, int bPCOnly = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPCOnly);
            NWN.Internal.NativeFunctions.StackPushObject(oMemberOfFaction != null ? oMemberOfFaction.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(381);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Force the action subject to move to lDestination.
        public static void ActionForceMoveToLocation(NWN.Location lDestination, int bRun = FALSE, float fTimeout = 30.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fTimeout);
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushLocation(lDestination.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(382);
        }

        //  Force the action subject to move to oMoveTo.
        public static void ActionForceMoveToObject(NWN.Object oMoveTo, int bRun = FALSE, float fRange = 1.0f, float fTimeout = 30.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fTimeout);
            NWN.Internal.NativeFunctions.StackPushFloat(fRange);
            NWN.Internal.NativeFunctions.StackPushInteger(bRun);
            NWN.Internal.NativeFunctions.StackPushObject(oMoveTo != null ? oMoveTo.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(383);
        }

        //  Get the experience assigned in the journal editor for szPlotID.
        public static int GetJournalQuestExperience(string szPlotID)
        {
            NWN.Internal.NativeFunctions.StackPushString(szPlotID);
            NWN.Internal.NativeFunctions.CallBuiltIn(384);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Jump to oToJumpTo (the action is added to the top of the action queue).
        public static void JumpToObject(NWN.Object oToJumpTo, int nWalkStraightLineToPoint = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nWalkStraightLineToPoint);
            NWN.Internal.NativeFunctions.StackPushObject(oToJumpTo != null ? oToJumpTo.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(385);
        }

        //  Set whether oMapPin is enabled.
        //  - oMapPin
        //  - nEnabled: 0=Off, 1=On
        public static void SetMapPinEnabled(NWN.Object oMapPin, int nEnabled)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nEnabled);
            NWN.Internal.NativeFunctions.StackPushObject(oMapPin != null ? oMapPin.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(386);
        }

        //  Create a Hit Point Change When Dying effect.
        //  - fHitPointChangePerRound: this can be positive or negative, but not zero.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
        public static NWN.Effect EffectHitPointChangeWhenDying(float fHitPointChangePerRound)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fHitPointChangePerRound);
            NWN.Internal.NativeFunctions.CallBuiltIn(387);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Spawn a GUI panel for the client that controls oPC.
        //  - oPC
        //  - nGUIPanel: GUI_PANEL_*
        //  * Nothing happens if oPC is not a player character or if an invalid value is
        //    used for nGUIPanel.
        public static void PopUpGUIPanel(NWN.Object oPC, int nGUIPanel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nGUIPanel);
            NWN.Internal.NativeFunctions.StackPushObject(oPC != null ? oPC.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(388);
        }

        //  Clear all personal feelings that oSource has about oTarget.
        public static void ClearPersonalReputation(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(389);
        }

        //  oSource will temporarily be friends towards oTarget.
        //  bDecays determines whether the personal reputation value decays over time
        //  fDurationInSeconds is the length of time that the temporary friendship lasts
        //  Make oSource into a temporary friend of oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the friendship lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Friendship will only be in effect as long as
        //  (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
        public static void SetIsTemporaryFriend(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDurationInSeconds);
            NWN.Internal.NativeFunctions.StackPushInteger(bDecays);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(390);
        }

        //  Make oSource into a temporary enemy of oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the enmity lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Enmity will only be in effect as long as
        //  (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
        public static void SetIsTemporaryEnemy(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDurationInSeconds);
            NWN.Internal.NativeFunctions.StackPushInteger(bDecays);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(391);
        }

        //  Make oSource temporarily neutral to oTarget using personal reputation.
        //  - oTarget
        //  - oSource
        //  - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds;
        //    otherwise it is indefinite.
        //  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
        //    the neutrality lasts.
        //  Note: If bDecays is TRUE, the personal reputation amount decreases in size
        //  over fDurationInSeconds. Neutrality will only be in effect as long as
        //  (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
        //  (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
        public static void SetIsTemporaryNeutral(NWN.Object oTarget, NWN.Object oSource = null, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDurationInSeconds);
            NWN.Internal.NativeFunctions.StackPushInteger(bDecays);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(392);
        }

        //  Gives nXpAmount to oCreature.
        public static void GiveXPToCreature(NWN.Object oCreature, int nXpAmount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nXpAmount);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(393);
        }

        //  Sets oCreature's experience to nXpAmount.
        public static void SetXP(NWN.Object oCreature, int nXpAmount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nXpAmount);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(394);
        }

        //  Get oCreature's experience.
        public static int GetXP(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(395);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Convert nInteger to hex, returning the hex value as a string.
        //  * Return value has the format "0x????????" where each ? will be a hex digit
        //    (8 digits in total).
        public static string IntToHexString(int nInteger)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInteger);
            NWN.Internal.NativeFunctions.CallBuiltIn(396);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the base item type (BASE_ITEM_*) of oItem.
        //  * Returns BASE_ITEM_INVALID if oItem is an invalid item.
        public static int GetBaseItemType(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(397);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determines whether oItem has nProperty.
        //  - oItem
        //  - nProperty: ITEM_PROPERTY_*
        //  * Returns FALSE if oItem is not a valid item, or if oItem does not have
        //    nProperty.
        public static int GetItemHasItemProperty(NWN.Object oItem, int nProperty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nProperty);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(398);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The creature will equip the melee weapon in its possession that can do the
        //  most damage. If no valid melee weapon is found, it will equip the most
        //  damaging range weapon. This function should only ever be called in the
        //  EndOfCombatRound scripts, because otherwise it would have to stop the combat
        //  round to run simulation.
        //  - oVersus: You can try to get the most damaging weapon against oVersus
        //  - bOffHand
        public static void ActionEquipMostDamagingMelee(NWN.Object oVersus = null, int bOffHand = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bOffHand);
            NWN.Internal.NativeFunctions.StackPushObject(oVersus != null ? oVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(399);
        }

        //  The creature will equip the range weapon in its possession that can do the
        //  most damage.
        //  If no valid range weapon can be found, it will equip the most damaging melee
        //  weapon.
        //  - oVersus: You can try to get the most damaging weapon against oVersus
        public static void ActionEquipMostDamagingRanged(NWN.Object oVersus = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oVersus != null ? oVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(400);
        }

        //  Get the Armour Class of oItem.
        //  * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
        public static int GetItemACValue(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(401);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The creature will rest if not in combat and no enemies are nearby.
        //  - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies
        //                                      are nearby, but the creature can't see the enemy.
        //                                      FALSE the creature will not rest if enemies are
        //                                      nearby regardless of whether or not the creature
        //                                      can see them, such as if an enemy is close by,
        //                                      but is in a different room behind a closed door.
        public static void ActionRest(int bCreatureToEnemyLineOfSightCheck = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bCreatureToEnemyLineOfSightCheck);
            NWN.Internal.NativeFunctions.CallBuiltIn(402);
        }

        //  Expose/Hide the entire map of oArea for oPlayer.
        //  - oArea: The area that the map will be exposed/hidden for.
        //  - oPlayer: The player the map will be exposed/hidden for.
        //  - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.
        public static void ExploreAreaForPlayer(NWN.Object oArea, NWN.Object oPlayer, int bExplored = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bExplored);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(403);
        }

        //  The creature will equip the armour in its possession that has the highest
        //  armour class.
        public static void ActionEquipMostEffectiveArmor()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(404);
        }

        //  * Returns TRUE if it is currently day.
        public static int GetIsDay()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(405);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if it is currently night.
        public static int GetIsNight()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(406);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if it is currently dawn.
        public static int GetIsDawn()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(407);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if it is currently dusk.
        public static int GetIsDusk()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(408);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if oCreature was spawned from an encounter.
        public static int GetIsEncounterCreature(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(409);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnPlayerDying module script to get the last player who is dying.
        public static NWN.Object GetLastPlayerDying()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(410);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the starting location of the module.
        public static NWN.Location GetStartingLocation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(411);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  Make oCreatureToChange join one of the standard factions.
        //  ** This will only work on an NPC **
        //  - nStandardFaction: STANDARD_FACTION_*
        public static void ChangeToStandardFaction(NWN.Object oCreatureToChange, int nStandardFaction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStandardFaction);
            NWN.Internal.NativeFunctions.StackPushObject(oCreatureToChange != null ? oCreatureToChange.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(412);
        }

        //  Play oSound.
        public static void SoundObjectPlay(NWN.Object oSound)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSound != null ? oSound.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(413);
        }

        //  Stop playing oSound.
        public static void SoundObjectStop(NWN.Object oSound)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSound != null ? oSound.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(414);
        }

        //  Set the volume of oSound.
        //  - oSound
        //  - nVolume: 0-127
        public static void SoundObjectSetVolume(NWN.Object oSound, int nVolume)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nVolume);
            NWN.Internal.NativeFunctions.StackPushObject(oSound != null ? oSound.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(415);
        }

        //  Set the position of oSound.
        public static void SoundObjectSetPosition(NWN.Object oSound, NWN.Vector? vPosition)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vPosition.HasValue ? vPosition.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushObject(oSound != null ? oSound.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(416);
        }

        //  Immediately speak a conversation one-liner.
        //  - sDialogResRef
        //  - oTokenTarget: This must be specified if there are creature-specific tokens
        //    in the string.
        public static void SpeakOneLinerConversation(string sDialogResRef = "", NWN.Object oTokenTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTokenTarget != null ? oTokenTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sDialogResRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(417);
        }

        //  Get the amount of gold possessed by oTarget.
        public static int GetGold(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(418);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in an OnRespawnButtonPressed module script to get the object id of
        //  the player who last pressed the respawn button.
        public static NWN.Object GetLastRespawnButtonPresser()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(419);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  * Returns TRUE if oCreature is the Dungeon Master.
        //  Note: This will return FALSE if oCreature is a DM Possessed creature.
        //  To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
        public static int GetIsDM(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(420);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Play a voice chat.
        //  - nVoiceChatID: VOICE_CHAT_*
        //  - oTarget
        public static void PlayVoiceChat(int nVoiceChatID, NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nVoiceChatID);
            NWN.Internal.NativeFunctions.CallBuiltIn(421);
        }

        //  * Returns TRUE if the weapon equipped is capable of damaging oVersus.
        public static int GetIsWeaponEffective(NWN.Object oVersus = null, int bOffHand = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bOffHand);
            NWN.Internal.NativeFunctions.StackPushObject(oVersus != null ? oVersus.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(422);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this in a SpellCast script to determine whether the spell was considered
        //  harmful.
        //  * Returns TRUE if the last spell cast was harmful.
        public static int GetLastSpellHarmful()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(423);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Activate oItem.
        public static NWN.Event EventActivateItem(NWN.Object oItem, NWN.Location lTarget, NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushLocation(lTarget.Handle);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(424);
            return new NWN.Event(NWN.Internal.NativeFunctions.StackPopEvent());
        }

        //  Play the background music for oArea.
        public static void MusicBackgroundPlay(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(425);
        }

        //  Stop the background music for oArea.
        public static void MusicBackgroundStop(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(426);
        }

        //  Set the delay for the background music for oArea.
        //  - oArea
        //  - nDelay: delay in milliseconds
        public static void MusicBackgroundSetDelay(NWN.Object oArea, int nDelay)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDelay);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(427);
        }

        //  Change the background day track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void MusicBackgroundChangeDay(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrack);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(428);
        }

        //  Change the background night track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void MusicBackgroundChangeNight(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrack);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(429);
        }

        //  Play the battle music for oArea.
        public static void MusicBattlePlay(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(430);
        }

        //  Stop the battle music for oArea.
        public static void MusicBattleStop(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(431);
        }

        //  Change the battle track for oArea.
        //  - oArea
        //  - nTrack
        public static void MusicBattleChange(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrack);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(432);
        }

        //  Play the ambient sound for oArea.
        public static void AmbientSoundPlay(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(433);
        }

        //  Stop the ambient sound for oArea.
        public static void AmbientSoundStop(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(434);
        }

        //  Change the ambient day track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void AmbientSoundChangeDay(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrack);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(435);
        }

        //  Change the ambient night track for oArea to nTrack.
        //  - oArea
        //  - nTrack
        public static void AmbientSoundChangeNight(NWN.Object oArea, int nTrack)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrack);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(436);
        }

        //  Get the object that killed the caller.
        public static NWN.Object GetLastKiller()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(437);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in a spell script to get the item used to cast the spell.
        public static NWN.Object GetSpellCastItem()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(438);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the item that was activated.
        public static NWN.Object GetItemActivated()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(439);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the creature that
        //  activated the item.
        public static NWN.Object GetItemActivator()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(440);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this in an OnItemActivated module script to get the location of the item's
        //  target.
        public static NWN.Location GetItemActivatedTargetLocation()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(441);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  Use this in an OnItemActivated module script to get the item's target.
        public static NWN.Object GetItemActivatedTarget()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(442);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  * Returns TRUE if oObject (which is a placeable or a door) is currently open.
        public static int GetIsOpen(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(443);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Take nAmount of gold from oCreatureToTakeFrom.
        //  - nAmount
        //  - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.
        //  - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the
        //    gold will be destroyed and will vanish from the game.
        public static void TakeGoldFromCreature(int nAmount, NWN.Object oCreatureToTakeFrom, int bDestroy = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bDestroy);
            NWN.Internal.NativeFunctions.StackPushObject(oCreatureToTakeFrom != null ? oCreatureToTakeFrom.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(444);
        }

        //  Determine whether oObject is in conversation.
        public static int IsInConversation(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(445);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create an Ability Decrease effect.
        //  - nAbility: ABILITY_*
        //  - nModifyBy: This is the amount by which to decrement the ability
        public static NWN.Effect EffectAbilityDecrease(int nAbility, int nModifyBy)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifyBy);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbility);
            NWN.Internal.NativeFunctions.CallBuiltIn(446);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an Attack Decrease effect.
        //  - nPenalty
        //  - nModifierType: ATTACK_BONUS_*
        public static NWN.Effect EffectAttackDecrease(int nPenalty, int nModifierType = ATTACK_BONUS_MISC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifierType);
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.CallBuiltIn(447);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage Decrease effect.
        //  - nPenalty
        //  - nDamageType: DAMAGE_TYPE_*
        public static NWN.Effect EffectDamageDecrease(int nPenalty, int nDamageType = DAMAGE_TYPE_MAGICAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.CallBuiltIn(448);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Damage Immunity Decrease effect.
        //  - nDamageType: DAMAGE_TYPE_*
        //  - nPercentImmunity
        public static NWN.Effect EffectDamageImmunityDecrease(int nDamageType, int nPercentImmunity)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentImmunity);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(449);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an AC Decrease effect.
        //  - nValue
        //  - nModifyType: AC_*
        //  - nDamageType: DAMAGE_TYPE_*
        //    * Default value for nDamageType should only ever be used in this function prototype.
        public static NWN.Effect EffectACDecrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nModifyType);
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(450);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Movement Speed Decrease effect.
        //  - nPercentChange - range 0 through 99
        //  eg.
        //     0 = no change in speed
        //    50 = 50% slower
        //    99 = almost immobile
        public static NWN.Effect EffectMovementSpeedDecrease(int nPercentChange)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentChange);
            NWN.Internal.NativeFunctions.CallBuiltIn(451);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Saving Throw Decrease effect.
        //  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
        //           SAVING_THROW_ALL
        //           SAVING_THROW_FORT
        //           SAVING_THROW_REFLEX
        //           SAVING_THROW_WILL 
        //  - nValue: size of the Saving Throw decrease
        //  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
        public static NWN.Effect EffectSavingThrowDecrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveType);
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSave);
            NWN.Internal.NativeFunctions.CallBuiltIn(452);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Skill Decrease effect.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
        public static NWN.Effect EffectSkillDecrease(int nSkill, int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(453);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Spell Resistance Decrease effect.
        public static NWN.Effect EffectSpellResistanceDecrease(int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.CallBuiltIn(454);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Determine whether oTarget is a plot object.
        public static int GetPlotFlag(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(455);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set oTarget's plot object status.
        public static void SetPlotFlag(NWN.Object oTarget, int nPlotFlag)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPlotFlag);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(456);
        }

        //  Create an Invisibility effect.
        //  - nInvisibilityType: INVISIBILITY_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
        //    is invalid.
        public static NWN.Effect EffectInvisibility(int nInvisibilityType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nInvisibilityType);
            NWN.Internal.NativeFunctions.CallBuiltIn(457);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Concealment effect.
        //  - nPercentage: 1-100 inclusive
        //  - nMissChanceType: MISS_CHANCE_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
        //    nPercentage > 100.
        public static NWN.Effect EffectConcealment(int nPercentage, int nMissType = MISS_CHANCE_TYPE_NORMAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMissType);
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentage);
            NWN.Internal.NativeFunctions.CallBuiltIn(458);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Darkness effect.
        public static NWN.Effect EffectDarkness()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(459);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Dispel Magic All effect.
        //  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
        //  cause the dispel effect to use the level of the creature that created the
        //  effect.
        public static NWN.Effect EffectDispelMagicAll(int nCasterLevel = USE_CREATURE_LEVEL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCasterLevel);
            NWN.Internal.NativeFunctions.CallBuiltIn(460);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an Ultravision effect.
        public static NWN.Effect EffectUltravision()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(461);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Negative Level effect.
        //  - nNumLevels: the number of negative levels to apply.
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
        public static NWN.Effect EffectNegativeLevel(int nNumLevels, int bHPBonus = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bHPBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nNumLevels);
            NWN.Internal.NativeFunctions.CallBuiltIn(462);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Polymorph effect.
        public static NWN.Effect EffectPolymorph(int nPolymorphSelection, int nLocked = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLocked);
            NWN.Internal.NativeFunctions.StackPushInteger(nPolymorphSelection);
            NWN.Internal.NativeFunctions.CallBuiltIn(463);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Sanctuary effect.
        //  - nDifficultyClass: must be a non-zero, positive number
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
        public static NWN.Effect EffectSanctuary(int nDifficultyClass)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDifficultyClass);
            NWN.Internal.NativeFunctions.CallBuiltIn(464);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a True Seeing effect.
        public static NWN.Effect EffectTrueSeeing()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(465);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a See Invisible effect.
        public static NWN.Effect EffectSeeInvisible()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(466);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Time Stop effect.
        public static NWN.Effect EffectTimeStop()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(467);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Blindness effect.
        public static NWN.Effect EffectBlindness()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(468);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Determine whether oSource has a friendly reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsFriend() instead.
        //  * Returns TRUE if oSource has a friendly reaction towards oTarget
        public static int GetIsReactionTypeFriendly(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(469);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oSource has a neutral reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsNeutral() instead.
        //  * Returns TRUE if oSource has a neutral reaction towards oTarget
        public static int GetIsReactionTypeNeutral(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(470);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oSource has a Hostile reaction towards oTarget, depending
        //  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
        //  oSource's Like/Dislike setting for oTarget.
        //  Note: If you just want to know how two objects feel about each other in terms
        //  of faction and personal reputation, use GetIsEnemy() instead.
        //  * Returns TRUE if oSource has a hostile reaction towards oTarget
        public static int GetIsReactionTypeHostile(NWN.Object oTarget, NWN.Object oSource = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(471);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Spell Level Absorption effect.
        //  - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the
        //    effect
        //  - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be
        //    absorbed by the effect
        //  - nSpellSchool: SPELL_SCHOOL_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
        //    nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
        //    is invalid.
        public static NWN.Effect EffectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed = 0, int nSpellSchool = SPELL_SCHOOL_GENERAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpellSchool);
            NWN.Internal.NativeFunctions.StackPushInteger(nTotalSpellLevelsAbsorbed);
            NWN.Internal.NativeFunctions.StackPushInteger(nMaxSpellLevelAbsorbed);
            NWN.Internal.NativeFunctions.CallBuiltIn(472);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Dispel Magic Best effect.
        //  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
        //  cause the dispel effect to use the level of the creature that created the
        //  effect.
        public static NWN.Effect EffectDispelMagicBest(int nCasterLevel = USE_CREATURE_LEVEL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCasterLevel);
            NWN.Internal.NativeFunctions.CallBuiltIn(473);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Try to send oTarget to a new server defined by sIPaddress.
        //  - oTarget
        //  - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric
        //    "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
        //    "www.bioware.com:5121"; if the port is not specified, it will default to
        //    5121.
        //  - sPassword: login password for the destination server
        //  - sWaypointTag: if this is set, after portalling the character will be moved
        //    to this waypoint if it exists
        //  - bSeamless: if this is set, the client wil not be prompted with the
        //    information window telling them about the server, and they will not be
        //    allowed to save a copy of their character if they are using a local vault
        //    character.
        public static void ActivatePortal(NWN.Object oTarget, string sIPaddress = "", string sPassword = "", string sWaypointTag = "", int bSeemless = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bSeemless);
            NWN.Internal.NativeFunctions.StackPushString(sWaypointTag);
            NWN.Internal.NativeFunctions.StackPushString(sPassword);
            NWN.Internal.NativeFunctions.StackPushString(sIPaddress);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(474);
        }

        //  Get the number of stacked items that oItem comprises.
        public static int GetNumStackedItems(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(475);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this on an NPC to cause all creatures within a 10-metre radius to stop
        //  what they are doing and sets the NPC's enemies within this range to be
        //  neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
        //  or an object that is not a creature, nothing will happen.
        public static void SurrenderToEnemies()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(476);
        }

        //  Create a Miss Chance effect.
        //  - nPercentage: 1-100 inclusive
        //  - nMissChanceType: MISS_CHANCE_TYPE_*
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
        //    nPercentage > 100.
        public static NWN.Effect EffectMissChance(int nPercentage, int nMissChanceType = MISS_CHANCE_TYPE_NORMAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMissChanceType);
            NWN.Internal.NativeFunctions.StackPushInteger(nPercentage);
            NWN.Internal.NativeFunctions.CallBuiltIn(477);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the number of Hitdice worth of Turn Resistance that oUndead may have.
        //  This will only work on undead creatures.
        public static int GetTurnResistanceHD(NWN.Object oUndead = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oUndead != null ? oUndead.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(478);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the size (CREATURE_SIZE_*) of oCreature.
        public static int GetCreatureSize(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(479);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Disappear/Appear effect.
        //  The object will "fly away" for the duration of the effect and will reappear
        //  at lLocation.
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectDisappearAppear(NWN.Location lLocation, int nAnimation = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAnimation);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(480);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Disappear effect to make the object "fly away" and then destroy
        //  itself.
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectDisappear(int nAnimation = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAnimation);
            NWN.Internal.NativeFunctions.CallBuiltIn(481);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create an Appear effect to make the object "fly in".
        //  - nAnimation determines which appear and disappear animations to use. Most creatures
        //  only have animation 1, although a few have 2 (like beholders)
        public static NWN.Effect EffectAppear(int nAnimation = 1)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAnimation);
            NWN.Internal.NativeFunctions.CallBuiltIn(482);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  The action subject will unlock oTarget, which can be a door or a placeable
        //  object.
        public static void ActionUnlockObject(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(483);
        }

        //  The action subject will lock oTarget, which can be a door or a placeable
        //  object.
        public static void ActionLockObject(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(484);
        }

        //  Create a Modify Attacks effect to add attacks.
        //  - nAttacks: maximum is 5, even with the effect stacked
        //  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
        public static NWN.Effect EffectModifyAttacks(int nAttacks)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAttacks);
            NWN.Internal.NativeFunctions.CallBuiltIn(485);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the last trap detected by oTarget.
        //  * Return value on error: OBJECT_INVALID
        public static NWN.Object GetLastTrapDetected(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(486);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
        //  damage to any melee attacker on a successful attack of damage type nDamageType.
        //  - nDamageAmount: an integer value
        //  - nRandomAmount: DAMAGE_BONUS_*
        //  - nDamageType: DAMAGE_TYPE_*
        //  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
        //        result in odd behaviour.
        public static NWN.Effect EffectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nRandomAmount);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(487);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Get the trap nearest to oTarget.
        //  Note : "trap objects" are actually any trigger, placeable or door that is
        //  trapped in oTarget's area.
        //  - oTarget
        //  - nTrapDetected: if this is TRUE, the trap returned has to have been detected
        //    by oTarget.
        public static NWN.Object GetNearestTrapToObject(NWN.Object oTarget = null, int nTrapDetected = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrapDetected);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(488);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the name of oCreature's deity.
        //  * Returns "" if oCreature is invalid (or if the deity name is blank for
        //    oCreature).
        public static string GetDeity(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(489);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the name of oCreature's sub race.
        //  * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
        public static string GetSubRace(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(490);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get oTarget's base fortitude saving throw value (this will only work for
        //  creatures, doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetFortitudeSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(491);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oTarget's base will saving throw value (this will only work for creatures,
        //  doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetWillSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(492);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oTarget's base reflex saving throw value (this will only work for
        //  creatures, doors, and placeables).
        //  * Returns 0 if oTarget is invalid.
        public static int GetReflexSavingThrow(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(493);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oCreature's challenge rating.
        //  * Returns 0.0 if oCreature is invalid.
        public static float GetChallengeRating(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(494);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Get oCreature's age.
        //  * Returns 0 if oCreature is invalid.
        public static int GetAge(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(495);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oCreature's movement rate.
        //  * Returns 0 if oCreature is invalid.
        public static int GetMovementRate(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(496);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
        //  * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
        //    currently have a familiar.
        public static int GetFamiliarCreatureType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(497);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oCreature's animal companion creature type
        //  (ANIMAL_COMPANION_CREATURE_TYPE_*).
        //  * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
        //    not currently have an animal companion.
        public static int GetAnimalCompanionCreatureType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(498);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get oCreature's familiar's name.
        //  * Returns "" if oCreature is invalid, does not currently
        //  have a familiar or if the familiar's name is blank.
        public static string GetFamiliarName(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(499);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get oCreature's animal companion's name.
        //  * Returns "" if oCreature is invalid, does not currently
        //  have an animal companion or if the animal companion's name is blank.
        public static string GetAnimalCompanionName(NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(500);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  The action subject will fake casting a spell at oTarget; the conjure and cast
        //  animations and visuals will occur, nothing else.
        //  - nSpell
        //  - oTarget
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        public static void ActionCastFakeSpellAtObject(int nSpell, NWN.Object oTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nProjectilePathType);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(501);
        }

        //  The action subject will fake casting a spell at lLocation; the conjure and
        //  cast animations and visuals will occur, nothing else.
        //  - nSpell
        //  - lTarget
        //  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
        public static void ActionCastFakeSpellAtLocation(int nSpell, NWN.Location lTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nProjectilePathType);
            NWN.Internal.NativeFunctions.StackPushLocation(lTarget.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(502);
        }

        //  Removes oAssociate from the service of oMaster, returning them to their
        //  original faction.
        public static void RemoveSummonedAssociate(NWN.Object oMaster, NWN.Object oAssociate = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAssociate != null ? oAssociate.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oMaster != null ? oMaster.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(503);
        }

        //  Set the camera mode for oPlayer.
        //  - oPlayer
        //  - nCameraMode: CAMERA_MODE_*
        //  * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
        //    happens.
        public static void SetCameraMode(NWN.Object oPlayer, int nCameraMode)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCameraMode);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(504);
        }

        //  * Returns TRUE if oCreature is resting.
        public static int GetIsResting(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(505);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the last PC that has rested in the module.
        public static NWN.Object GetLastPCRested()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(506);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Set the weather for oTarget.
        //  - oTarget: if this is GetModule(), all outdoor areas will be modified by the
        //    weather constant. If it is an area, oTarget will play the weather only if
        //    it is an outdoor area.
        //  - nWeather: WEATHER_*
        //    -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
        //    -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
        //       the appropriate precipitation *without stopping*.
        public static void SetWeather(NWN.Object oTarget, int nWeather)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nWeather);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(507);
        }

        //  Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
        //  returned from the OnPCRested module event).
        public static int GetLastRestEventType()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(508);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Shut down the currently loaded module and start a new one (moving all
        //  currently-connected players to the starting point.
        public static void StartNewModule(string sModuleName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sModuleName);
            NWN.Internal.NativeFunctions.CallBuiltIn(509);
        }

        //  Create a Swarm effect.
        //  - nLooping: If this is TRUE, for the duration of the effect when one creature
        //    created by this effect dies, the next one in the list will be created.  If
        //    the last creature in the list dies, we loop back to the beginning and
        //    sCreatureTemplate1 will be created, and so on...
        //  - sCreatureTemplate1
        //  - sCreatureTemplate2
        //  - sCreatureTemplate3
        //  - sCreatureTemplate4
        public static NWN.Effect EffectSwarm(int nLooping, string sCreatureTemplate1, string sCreatureTemplate2 = "", string sCreatureTemplate3 = "", string sCreatureTemplate4 = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sCreatureTemplate4);
            NWN.Internal.NativeFunctions.StackPushString(sCreatureTemplate3);
            NWN.Internal.NativeFunctions.StackPushString(sCreatureTemplate2);
            NWN.Internal.NativeFunctions.StackPushString(sCreatureTemplate1);
            NWN.Internal.NativeFunctions.StackPushInteger(nLooping);
            NWN.Internal.NativeFunctions.CallBuiltIn(510);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  * Returns TRUE if oItem is a ranged weapon.
        public static int GetWeaponRanged(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(511);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Only if we are in a single player game, AutoSave the game.
        public static void DoSinglePlayerAutoSave()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(512);
        }

        //  Get the game difficulty (GAME_DIFFICULTY_*).
        public static int GetGameDifficulty()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(513);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the main light color on the tile at lTileLocation.
        //  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
        //    the tile.
        //  - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*
        //  - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*
        public static void SetTileMainLightColor(NWN.Location lTileLocation, int nMainLight1Color, int nMainLight2Color)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMainLight2Color);
            NWN.Internal.NativeFunctions.StackPushInteger(nMainLight1Color);
            NWN.Internal.NativeFunctions.StackPushLocation(lTileLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(514);
        }

        //  Set the source light color on the tile at lTileLocation.
        //  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
        //    the tile.
        //  - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*
        //  - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*
        public static void SetTileSourceLightColor(NWN.Location lTileLocation, int nSourceLight1Color, int nSourceLight2Color)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSourceLight2Color);
            NWN.Internal.NativeFunctions.StackPushInteger(nSourceLight1Color);
            NWN.Internal.NativeFunctions.StackPushLocation(lTileLocation.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(515);
        }

        //  All clients in oArea will recompute the static lighting.
        //  This can be used to update the lighting after changing any tile lights or if
        //  placeables with lights have been added/deleted.
        public static void RecomputeStaticLighting(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(516);
        }

        //  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
        //  lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.
        public static int GetTileMainLight1Color(NWN.Location lTile)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lTile.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(517);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
        //  lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileMainLight2Color(NWN.Location lTile)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lTile.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(518);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
        //  at lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileSourceLight1Color(NWN.Location lTile)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lTile.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(519);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
        //  at lTile.
        //  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
        //    tile.
        public static int GetTileSourceLight2Color(NWN.Location lTile)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(lTile.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(520);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Make the corresponding panel button on the player's client start or stop
        //  flashing.
        //  - oPlayer
        //  - nButton: PANEL_BUTTON_*
        //  - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,
        //    nButton will stop flashing.
        public static void SetPanelButtonFlash(NWN.Object oPlayer, int nButton, int nEnableFlash)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nEnableFlash);
            NWN.Internal.NativeFunctions.StackPushInteger(nButton);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(521);
        }

        //  Get the current action (ACTION_*) that oObject is executing.
        public static int GetCurrentAction(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(522);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set how nStandardFaction feels about oCreature.
        //  - nStandardFaction: STANDARD_FACTION_*
        //  - nNewReputation: 0-100 (inclusive)
        //  - oCreature
        public static void SetStandardFactionReputation(int nStandardFaction, int nNewReputation, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nNewReputation);
            NWN.Internal.NativeFunctions.StackPushInteger(nStandardFaction);
            NWN.Internal.NativeFunctions.CallBuiltIn(523);
        }

        //  Find out how nStandardFaction feels about oCreature.
        //  - nStandardFaction: STANDARD_FACTION_*
        //  - oCreature
        //  Returns -1 on an error.
        //  Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
        //  0-10   :  Hostile.
        //  11-89  :  Neutral.
        //  90-100 :  Friendly.
        public static int GetStandardFactionReputation(int nStandardFaction, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nStandardFaction);
            NWN.Internal.NativeFunctions.CallBuiltIn(524);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Display floaty text above the specified creature.
        //  The text will also appear in the chat buffer of each player that receives the
        //  floaty text.
        //  - nStrRefToDisplay: String ref (therefore text is translated)
        //  - oCreatureToFloatAbove
        //  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
        //    as oCreatureToFloatAbove
        //    will see the floaty text, and only if they are within range (30 metres).
        public static void FloatingTextStrRefOnCreature(int nStrRefToDisplay, NWN.Object oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bBroadcastToFaction);
            NWN.Internal.NativeFunctions.StackPushObject(oCreatureToFloatAbove != null ? oCreatureToFloatAbove.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRefToDisplay);
            NWN.Internal.NativeFunctions.CallBuiltIn(525);
        }

        //  Display floaty text above the specified creature.
        //  The text will also appear in the chat buffer of each player that receives the
        //  floaty text.
        //  - sStringToDisplay: String
        //  - oCreatureToFloatAbove
        //  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
        //    as oCreatureToFloatAbove
        //    will see the floaty text, and only if they are within range (30 metres).
        public static void FloatingTextStringOnCreature(string sStringToDisplay, NWN.Object oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bBroadcastToFaction);
            NWN.Internal.NativeFunctions.StackPushObject(oCreatureToFloatAbove != null ? oCreatureToFloatAbove.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sStringToDisplay);
            NWN.Internal.NativeFunctions.CallBuiltIn(526);
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is disarmable.
        public static int GetTrapDisarmable(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(527);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is detectable.
        public static int GetTrapDetectable(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(528);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  - oCreature
        //  * Returns TRUE if oCreature has detected oTrapObject
        public static int GetTrapDetectedBy(NWN.Object oTrapObject, NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(529);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
        public static int GetTrapFlagged(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(530);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapBaseType(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(531);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
        //    after firing.
        public static int GetTrapOneShot(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(532);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the creator of oTrapObject, the creature that set the trap.
        //  - oTrapObject: a placeable, door or trigger
        //  * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
        public static NWN.Object GetTrapCreator(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(533);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the tag of the key that will disarm oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static string GetTrapKeyTag(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(534);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the DC for disarming oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapDisarmDC(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(535);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the DC for detecting oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static int GetTrapDetectDC(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(536);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  * Returns TRUE if a specific key is required to open the lock on oObject.
        public static int GetLockKeyRequired(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(537);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the tag of the key that will open the lock on oObject.
        public static string GetLockKeyTag(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(538);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  * Returns TRUE if the lock on oObject is lockable.
        public static int GetLockLockable(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(539);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the DC for unlocking oObject.
        public static int GetLockUnlockDC(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(540);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the DC for locking oObject.
        public static int GetLockLockDC(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(541);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the last PC that levelled up.
        public static NWN.Object GetPCLevellingUp()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(542);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  - nFeat: FEAT_*
        //  - oObject
        //  * Returns TRUE if oObject has effects on it originating from nFeat.
        public static int GetHasFeatEffect(int nFeat, NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.CallBuiltIn(543);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the status of the illumination for oPlaceable.
        //  - oPlaceable
        //  - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.
        //    If this is FALSE, oPlaceable's illumination will be turned off.
        //  Note: You must call RecomputeStaticLighting() after calling this function in
        //  order for the changes to occur visually for the players.
        //  SetPlaceableIllumination() buffers the illumination changes, which are then
        //  sent out to the players once RecomputeStaticLighting() is called.  As such,
        //  it is best to call SetPlaceableIllumination() for all the placeables you wish
        //  to set the illumination on, and then call RecomputeStaticLighting() once after
        //  all the placeable illumination has been set.
        //  * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
        //    doesn't have a light, nothing will happen.
        public static void SetPlaceableIllumination(NWN.Object oPlaceable = null, int bIlluminate = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bIlluminate);
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(544);
        }

        //  * Returns TRUE if the illumination for oPlaceable is on
        public static int GetPlaceableIllumination(NWN.Object oPlaceable = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(545);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  - oPlaceable
        //  - nPlaceableAction: PLACEABLE_ACTION_*
        //  * Returns TRUE if nPlacebleAction is valid for oPlaceable.
        public static int GetIsPlaceableObjectActionPossible(NWN.Object oPlaceable, int nPlaceableAction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPlaceableAction);
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(546);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  The caller performs nPlaceableAction on oPlaceable.
        //  - oPlaceable
        //  - nPlaceableAction: PLACEABLE_ACTION_*
        public static void DoPlaceableObjectAction(NWN.Object oPlaceable, int nPlaceableAction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPlaceableAction);
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(547);
        }

        //  Get the first PC in the player list.
        //  This resets the position in the player list for GetNextPC().
        public static NWN.Object GetFirstPC()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(548);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the next PC in the player list.
        //  This picks up where the last GetFirstPC() or GetNextPC() left off.
        public static NWN.Object GetNextPC()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(549);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Set whether or not the creature oDetector has detected the trapped object oTrap.
        //  - oTrap: A trapped trigger, placeable or door object.
        //  - oDetector: This is the creature that the detected status of the trap is being adjusted for.
        //  - bDetected: A Boolean that sets whether the trapped object has been detected or not.
        public static int SetTrapDetectedBy(NWN.Object oTrap, NWN.Object oDetector, int bDetected = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bDetected);
            NWN.Internal.NativeFunctions.StackPushObject(oDetector != null ? oDetector.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTrap != null ? oTrap.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(550);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Note: Only placeables, doors and triggers can be trapped.
        //  * Returns TRUE if oObject is trapped.
        public static int GetIsTrapped(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(551);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Create a Turn Resistance Decrease effect.
        //  - nHitDice: a positive number representing the number of hit dice for the
        // /  decrease
        public static NWN.Effect EffectTurnResistanceDecrease(int nHitDice)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHitDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(552);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Create a Turn Resistance Increase effect.
        //  - nHitDice: a positive number representing the number of hit dice for the
        //    increase
        public static NWN.Effect EffectTurnResistanceIncrease(int nHitDice)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHitDice);
            NWN.Internal.NativeFunctions.CallBuiltIn(553);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Spawn in the Death GUI.
        //  The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
        //  if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
        //  function to use.
        //  - oPC
        //  - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled
        //    on the Death GUI.
        //  - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will
        //    be enabled on the Death GUI (Note: This button will not appear in single player games).
        //  - nHelpStringReference
        //  - sHelpString
        public static void PopUpDeathGUIPanel(NWN.Object oPC, int bRespawnButtonEnabled = TRUE, int bWaitForHelpButtonEnabled = TRUE, int nHelpStringReference = 0, string sHelpString = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sHelpString);
            NWN.Internal.NativeFunctions.StackPushInteger(nHelpStringReference);
            NWN.Internal.NativeFunctions.StackPushInteger(bWaitForHelpButtonEnabled);
            NWN.Internal.NativeFunctions.StackPushInteger(bRespawnButtonEnabled);
            NWN.Internal.NativeFunctions.StackPushObject(oPC != null ? oPC.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(554);
        }

        //  Disable oTrap.
        //  - oTrap: a placeable, door or trigger.
        public static void SetTrapDisabled(NWN.Object oTrap)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrap != null ? oTrap.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(555);
        }

        //  Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
        //  GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
        //  creature is pickpocketed).
        //  Note: Return values may only ever be:
        //  1) A Creature
        //  2) Plot Characters will never have this value set
        //  3) Area of Effect Objects will return the AOE creator if they are registered
        //     as this value, otherwise they will return INVALID_OBJECT_ID
        //  4) Traps will not return the creature that set the trap.
        //  5) This value will never be overwritten by another non-creature object.
        //  6) This value will never be a dead/destroyed creature
        public static NWN.Object GetLastHostileActor(NWN.Object oVictim = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oVictim != null ? oVictim.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(556);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Force all the characters of the players who are currently in the game to
        //  be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
        public static void ExportAllCharacters()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(557);
        }

        //  Get the Day Track for oArea.
        public static int MusicBackgroundGetDayTrack(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(558);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the Night Track for oArea.
        public static int MusicBackgroundGetNightTrack(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(559);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Write sLogEntry as a timestamped entry into the log file
        public static void WriteTimestampedLogEntry(string sLogEntry)
        {
            NWN.Internal.NativeFunctions.StackPushString(sLogEntry);
            NWN.Internal.NativeFunctions.CallBuiltIn(560);
        }

        //  Get the module's name in the language of the server that's running it.
        //  * If there is no entry for the language of the server, it will return an
        //    empty string
        public static string GetModuleName()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(561);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the player leader of the faction of which oMemberOfFaction is a member.
        //  * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
        //    or oMemberOfFaction is a member of a NPC faction.
        public static NWN.Object GetFactionLeader(NWN.Object oMemberOfFaction)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oMemberOfFaction != null ? oMemberOfFaction.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(562);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Sends szMessage to all the Dungeon Masters currently on the server.
        public static void SendMessageToAllDMs(string szMessage)
        {
            NWN.Internal.NativeFunctions.StackPushString(szMessage);
            NWN.Internal.NativeFunctions.CallBuiltIn(563);
        }

        //  End the currently running game, play sEndMovie then return all players to the
        //  game's main menu.
        public static void EndGame(string sEndMovie)
        {
            NWN.Internal.NativeFunctions.StackPushString(sEndMovie);
            NWN.Internal.NativeFunctions.CallBuiltIn(564);
        }

        //  Remove oPlayer from the server.
        //  You can optionally specify a reason to override the text shown to the player.
        public static void BootPC(NWN.Object oPlayer, string sReason = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sReason);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(565);
        }

        //  Counterspell oCounterSpellTarget.
        public static void ActionCounterSpell(NWN.Object oCounterSpellTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCounterSpellTarget != null ? oCounterSpellTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(566);
        }

        //  Set the ambient day volume for oArea to nVolume.
        //  - oArea
        //  - nVolume: 0 - 100
        public static void AmbientSoundSetDayVolume(NWN.Object oArea, int nVolume)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nVolume);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(567);
        }

        //  Set the ambient night volume for oArea to nVolume.
        //  - oArea
        //  - nVolume: 0 - 100
        public static void AmbientSoundSetNightVolume(NWN.Object oArea, int nVolume)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nVolume);
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(568);
        }

        //  Get the Battle Track for oArea.
        public static int MusicBackgroundGetBattleTrack(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(569);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Determine whether oObject has an inventory.
        //  * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
        //  * Returns FALSE for all other object types.
        public static int GetHasInventory(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(570);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the duration (in seconds) of the sound attached to nStrRef
        //  * Returns 0.0f if no duration is stored or if no sound is attached
        public static float GetStrRefSoundDuration(int nStrRef)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(571);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Add oPC to oPartyLeader's party.  This will only work on two PCs.
        //  - oPC: player to add to a party
        //  - oPartyLeader: player already in the party
        public static void AddToParty(NWN.Object oPC, NWN.Object oPartyLeader)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPartyLeader != null ? oPartyLeader.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oPC != null ? oPC.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(572);
        }

        //  Remove oPC from their current party. This will only work on a PC.
        //  - oPC: removes this player from whatever party they're currently in.
        public static void RemoveFromParty(NWN.Object oPC)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPC != null ? oPC.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(573);
        }

        //  Returns the stealth mode of the specified creature.
        //  - oCreature
        //  * Returns a constant STEALTH_MODE_*
        public static int GetStealthMode(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(574);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the detection mode of the specified creature.
        //  - oCreature
        //  * Returns a constant DETECT_MODE_*
        public static int GetDetectMode(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(575);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the defensive casting mode of the specified creature.
        //  - oCreature
        //  * Returns a constant DEFENSIVE_CASTING_MODE_*
        public static int GetDefensiveCastingMode(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(576);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  returns the appearance type of the specified creature.
        //  * returns a constant APPEARANCE_TYPE_* for valid creatures
        //  * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
        public static int GetAppearanceType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(577);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  SpawnScriptDebugger() will cause the script debugger to be executed
        //  after this command is executed!  
        //  In order to compile the script for debugging go to Tools->Options->Script Editor
        //  and check the box labeled "Generate Debug Information When Compiling Scripts"
        //  After you have checked the above box, recompile the script that you want to debug.
        //  If the script file isn't compiled for debugging, this command will do nothing.
        //  Remove any SpawnScriptDebugger() calls once you have finished 
        //  debugging the script.
        public static void SpawnScriptDebugger()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(578);
        }

        //  in an onItemAcquired script, returns the size of the stack of the item
        //  that was just acquired.
        //  * returns the stack size of the item acquired
        public static int GetModuleItemAcquiredStackSize()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(579);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Decrement the remaining uses per day for this creature by one.
        //  - oCreature: creature to modify
        //  - nFeat: constant FEAT_*
        public static void DecrementRemainingFeatUses(NWN.Object oCreature, int nFeat)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(580);
        }

        //  Decrement the remaining uses per day for this creature by one.
        //  - oCreature: creature to modify
        //  - nSpell: constant SPELL_*
        public static void DecrementRemainingSpellUses(NWN.Object oCreature, int nSpell)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(581);
        }

        //  returns the template used to create this object (if appropriate)
        //  * returns an empty string when no template found
        public static string GetResRef(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(582);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  returns an effect that will petrify the target
        //  * currently applies EffectParalyze and the stoneskin visual effect.
        public static NWN.Effect EffectPetrify()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(583);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  duplicates the item and returns a new object
        //  oItem - item to copy
        //  oTargetInventory - create item in this object's inventory. If this parameter
        //                     is not valid, the item will be created in oItem's location
        //  bCopyVars - copy the local variables from the old item to the new one
        //  * returns the new item
        //  * returns OBJECT_INVALID for non-items.
        //  * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
        //    other items.
        //  * if it is possible to merge this item with any others in the target location,
        //    then it will do so and return the merged object.
        public static NWN.Object CopyItem(NWN.Object oItem, NWN.Object oTargetInventory = null, int bCopyVars = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bCopyVars);
            NWN.Internal.NativeFunctions.StackPushObject(oTargetInventory != null ? oTargetInventory.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(584);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  returns an effect that is guaranteed to paralyze a creature.
        //  this effect is identical to EffectParalyze except that it cannot be resisted.
        public static NWN.Effect EffectCutsceneParalyze()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(585);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  returns TRUE if the item CAN be dropped
        //  Droppable items will appear on a creature's remains when the creature is killed.
        public static int GetDroppableFlag(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(586);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  returns TRUE if the placeable object is usable
        public static int GetUseableFlag(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(587);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  returns TRUE if the item is stolen
        public static int GetStolenFlag(NWN.Object oStolen)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oStolen != null ? oStolen.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(588);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  This stores a float out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignFloat(string sCampaignName, string sVarName, float flFloat, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushFloat(flFloat);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(589);
        }

        //  This stores an int out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignInt(string sCampaignName, string sVarName, int nInt, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nInt);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(590);
        }

        //  This stores a vector out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignVector(string sCampaignName, string sVarName, NWN.Vector? vVector, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushVector(vVector.HasValue ? vVector.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(591);
        }

        //  This stores a location out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignLocation(string sCampaignName, string sVarName, NWN.Location locLocation, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushLocation(locLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(592);
        }

        //  This stores a string out to the specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static void SetCampaignString(string sCampaignName, string sVarName, string sString, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sString);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(593);
        }

        //  This will delete the entire campaign database if it exists.
        public static void DestroyCampaignDatabase(string sCampaignName)
        {
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(594);
        }

        //  This will read a float from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static float GetCampaignFloat(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(595);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  This will read an int from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static int GetCampaignInt(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(596);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  This will read a vector from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static NWN.Vector GetCampaignVector(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(597);
            return NWN.Internal.NativeFunctions.StackPopVector();
        }

        //  This will read a location from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static NWN.Location GetCampaignLocation(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(598);
            return new NWN.Location(NWN.Internal.NativeFunctions.StackPopLocation());
        }

        //  This will read a string from the  specified campaign database
        //  The database name IS case sensitive and it must be the same for both set and get functions.
        //  The var name must be unique across the entire database, regardless of the variable type.
        //  If you want a variable to pertain to a specific player in the game, provide a player object.
        public static string GetCampaignString(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(599);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Duplicates the object specified by oSource.
        //  ONLY creatures and items can be specified.
        //  If an owner is specified and the object is an item, it will be put into their inventory
        //  If the object is a creature, they will be created at the location.
        //  If a new tag is specified, it will be assigned to the new object.
        public static NWN.Object CopyObject(NWN.Object oSource, NWN.Location locLocation, NWN.Object oOwner = null, string sNewTag = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushObject(oOwner != null ? oOwner.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushLocation(locLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(600);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  This will remove ANY campaign variable. Regardless of type.
        //  Note that by normal database standards, deleting does not actually removed the entry from
        //  the database, but flags it as deleted. Do not expect the database files to shrink in size
        //  from this command. If you want to 'pack' the database, you will have to do it externally
        //  from the game.
        public static void DeleteCampaignVariable(string sCampaignName, string sVarName, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(601);
        }

        //  Stores an object with the given id.
        //  NOTE: this command can only be used for storing Creatures and Items.
        //  Returns 0 if it failled, 1 if it worked.
        public static int StoreCampaignObject(string sCampaignName, string sVarName, NWN.Object oObject, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(602);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use RetrieveCampaign with the given id to restore it.
        //  If you specify an owner, the object will try to be created in their repository
        //  If the owner can't handle the item (or if it's a creature) it will be created on the ground.
        public static NWN.Object RetrieveCampaignObject(string sCampaignName, string sVarName, NWN.Location locLocation, NWN.Object oOwner = null, NWN.Object oPlayer = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oOwner != null ? oOwner.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushLocation(locLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushString(sVarName);
            NWN.Internal.NativeFunctions.StackPushString(sCampaignName);
            NWN.Internal.NativeFunctions.CallBuiltIn(603);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Returns an effect that is guaranteed to dominate a creature
        //  Like EffectDominated but cannot be resisted
        public static NWN.Effect EffectCutsceneDominated()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(604);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Returns stack size of an item
        //  - oItem: item to query
        public static int GetItemStackSize(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(605);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets stack size of an item.
        //  - oItem: item to change
        //  - nSize: new size of stack.  Will be restricted to be between 1 and the
        //    maximum stack size for the item type.  If a value less than 1 is passed it
        //    will set the stack to 1.  If a value greater than the max is passed
        //    then it will set the stack to the maximum size
        public static void SetItemStackSize(NWN.Object oItem, int nSize)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSize);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(606);
        }

        //  Returns charges left on an item
        //  - oItem: item to query
        public static int GetItemCharges(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(607);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets charges left on an item.
        //  - oItem: item to change
        //  - nCharges: number of charges.  If value below 0 is passed, # charges will
        //    be set to 0.  If value greater than maximum is passed, # charges will
        //    be set to maximum.  If the # charges drops to 0 the item
        //    will be destroyed.
        public static void SetItemCharges(NWN.Object oItem, int nCharges)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCharges);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(608);
        }

        //  ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************
        //  adds an item property to the specified item
        //  Only temporary and permanent duration types are allowed.
        public static void AddItemProperty(int nDurationType, NWN.ItemProperty ipProperty, NWN.Object oItem, float fDuration = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fDuration);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushItemProperty(ipProperty.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nDurationType);
            NWN.Internal.NativeFunctions.CallBuiltIn(609);
        }

        //  removes an item property from the specified item
        public static void RemoveItemProperty(NWN.Object oItem, NWN.ItemProperty ipProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(ipProperty.Handle);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(610);
        }

        //  if the item property is valid this will return true
        public static int GetIsItemPropertyValid(NWN.ItemProperty ipProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(ipProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(611);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the first item property on an item
        public static NWN.ItemProperty GetFirstItemProperty(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(612);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Will keep retrieving the next and the next item property on an Item,
        //  will return an invalid item property when the list is empty.
        public static NWN.ItemProperty GetNextItemProperty(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(613);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  will return the item property type (ie. holy avenger)
        public static int GetItemPropertyType(NWN.ItemProperty ip)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(ip.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(614);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  will return the duration type of the item property
        public static int GetItemPropertyDurationType(NWN.ItemProperty ip)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(ip.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(615);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns Item property ability bonus.  You need to specify an
        //  ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
        //  be a positive integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyAbilityBonus(int nAbility, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbility);
            NWN.Internal.NativeFunctions.CallBuiltIn(616);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property AC bonus.  You need to specify the bonus.
        //  The bonus should be a positive integer between 1 and 20. The modifier
        //  type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonus(int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(617);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property AC bonus vs. alignment group.  An example of
        //  an alignment group is Chaotic, or Good.  You need to specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
        //  The AC bonus should be an integer between 1 and 20.  The modifier
        //  type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsAlign(int nAlignGroup, int nACBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nACBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignGroup);
            NWN.Internal.NativeFunctions.CallBuiltIn(618);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property AC bonus vs. Damage type (ie. piercing).  You
        //  need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
        //  AC bonus.  The AC bonus should be an integer between 1 and 20.  The
        //  modifier type depends on the item it is being applied to.
        //  NOTE: Only the first 3 damage types may be used here, the 3 basic
        //        physical types.
        public static NWN.ItemProperty ItemPropertyACBonusVsDmgType(int nDamageType, int nACBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nACBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(619);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property AC bonus vs. Racial group.  You need to specify
        //  the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
        //  bonus should be an integer between 1 and 20.  The modifier type depends
        //  on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsRace(int nRace, int nACBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nACBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nRace);
            NWN.Internal.NativeFunctions.CallBuiltIn(620);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property AC bonus vs. Specific alignment.  You need to
        //  specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
        //  bonus.  The AC bonus should be an integer between 1 and 20.  The
        //  modifier type depends on the item it is being applied to.
        public static NWN.ItemProperty ItemPropertyACBonusVsSAlign(int nAlign, int nACBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nACBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlign);
            NWN.Internal.NativeFunctions.CallBuiltIn(621);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Enhancement bonus.  You need to specify the
        //  enhancement bonus.  The Enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonus(int nEnhancementBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nEnhancementBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(622);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Enhancement bonus vs. an Alignment group.  You
        //  need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
        //  and the enhancement bonus.  The Enhancement bonus should be an integer
        //  between 1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsAlign(int nAlignGroup, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignGroup);
            NWN.Internal.NativeFunctions.CallBuiltIn(623);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Enhancement bonus vs. Racial group.  You need
        //  to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
        //  enhancement bonus.  The enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsRace(int nRace, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nRace);
            NWN.Internal.NativeFunctions.CallBuiltIn(624);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Enhancement bonus vs. a specific alignment.  You
        //  need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
        //  enhancement bonus.  The enhancement bonus should be an integer between
        //  1 and 20.
        public static NWN.ItemProperty ItemPropertyEnhancementBonusVsSAlign(int nAlign, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlign);
            NWN.Internal.NativeFunctions.CallBuiltIn(625);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Enhancment penalty.  You need to specify the
        //  enhancement penalty.  The enhancement penalty should be a POSITIVE
        //  integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyEnhancementPenalty(int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.CallBuiltIn(626);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property weight reduction.  You need to specify the weight
        //  reduction constant(IP_CONST_REDUCEDWEIGHT_*).
        public static NWN.ItemProperty ItemPropertyWeightReduction(int nReduction)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nReduction);
            NWN.Internal.NativeFunctions.CallBuiltIn(627);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Bonus Feat.  You need to specify the the feat
        //  constant(IP_CONST_FEAT_*).
        public static NWN.ItemProperty ItemPropertyBonusFeat(int nFeat)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.CallBuiltIn(628);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Bonus level spell (Bonus spell of level).  You must
        //  specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
        //  spell casting class) and the level of the bonus spell.  The level of the
        //  bonus spell should be an integer between 0 and 9.
        public static NWN.ItemProperty ItemPropertyBonusLevelSpell(int nClass, int nSpellLevel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpellLevel);
            NWN.Internal.NativeFunctions.StackPushInteger(nClass);
            NWN.Internal.NativeFunctions.CallBuiltIn(629);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Cast spell.  You must specify the spell constant
        //  (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
        //  NOTE: The number after the name of the spell in the constant is the level
        //        at which the spell will be cast.  Sometimes there are multiple copies
        //        of the same spell but they each are cast at a different level.  The higher
        //        the level, the more cost will be added to the item.
        //  NOTE: The list of spells that can be applied to an item will depend on the
        //        item type.  For instance there are spells that can be applied to a wand
        //        that cannot be applied to a potion.  Below is a list of the types and the
        //        spells that are allowed to be placed on them.  If you try to put a cast
        //        spell effect on an item that is not allowed to have that effect it will
        //        not work.
        //  NOTE: Even if spells have multiple versions of different levels they are only
        //        listed below once.
        // 
        //  WANDS:
        //           Acid_Splash
        //           Activate_Item
        //           Aid
        //           Amplify
        //           Animate_Dead
        //           AuraOfGlory
        //           BalagarnsIronHorn
        //           Bane
        //           Banishment
        //           Barkskin
        //           Bestow_Curse
        //           Bigbys_Clenched_Fist
        //           Bigbys_Crushing_Hand
        //           Bigbys_Forceful_Hand
        //           Bigbys_Grasping_Hand
        //           Bigbys_Interposing_Hand
        //           Bless
        //           Bless_Weapon
        //           Blindness/Deafness
        //           Blood_Frenzy
        //           Bombardment
        //           Bulls_Strength
        //           Burning_Hands
        //           Call_Lightning
        //           Camoflage
        //           Cats_Grace
        //           Charm_Monster
        //           Charm_Person
        //           Charm_Person_or_Animal
        //           Clairaudience/Clairvoyance
        //           Clarity
        //           Color_Spray
        //           Confusion
        //           Continual_Flame
        //           Cure_Critical_Wounds
        //           Cure_Light_Wounds
        //           Cure_Minor_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Serious_Wounds
        //           Darkness
        //           Darkvision
        //           Daze
        //           Death_Ward
        //           Dirge
        //           Dismissal
        //           Dispel_Magic
        //           Displacement
        //           Divine_Favor
        //           Divine_Might
        //           Divine_Power
        //           Divine_Shield
        //           Dominate_Animal
        //           Dominate_Person
        //           Doom
        //           Dragon_Breath_Acid
        //           Dragon_Breath_Cold
        //           Dragon_Breath_Fear
        //           Dragon_Breath_Fire
        //           Dragon_Breath_Gas
        //           Dragon_Breath_Lightning
        //           Dragon_Breath_Paralyze
        //           Dragon_Breath_Sleep
        //           Dragon_Breath_Slow
        //           Dragon_Breath_Weaken
        //           Drown
        //           Eagle_Spledor
        //           Earthquake
        //           Electric_Jolt
        //           Elemental_Shield
        //           Endurance
        //           Endure_Elements
        //           Enervation
        //           Entangle
        //           Entropic_Shield
        //           Etherealness
        //           Expeditious_Retreat
        //           Fear
        //           Find_Traps
        //           Fireball
        //           Firebrand
        //           Flame_Arrow
        //           Flame_Lash
        //           Flame_Strike
        //           Flare
        //           Foxs_Cunning
        //           Freedom_of_Movement
        //           Ghostly_Visage
        //           Ghoul_Touch
        //           Grease
        //           Greater_Magic_Fang
        //           Greater_Magic_Weapon
        //           Grenade_Acid
        //           Grenade_Caltrops
        //           Grenade_Chicken
        //           Grenade_Choking
        //           Grenade_Fire
        //           Grenade_Holy
        //           Grenade_Tangle
        //           Grenade_Thunderstone
        //           Gust_of_wind
        //           Hammer_of_the_Gods
        //           Haste
        //           Hold_Animal
        //           Hold_Monster
        //           Hold_Person
        //           Ice_Storm
        //           Identify
        //           Improved_Invisibility
        //           Inferno
        //           Inflict_Critical_Wounds
        //           Inflict_Light_Wounds
        //           Inflict_Minor_Wounds
        //           Inflict_Moderate_Wounds
        //           Inflict_Serious_Wounds
        //           Invisibility
        //           Invisibility_Purge
        //           Invisibility_Sphere
        //           Isaacs_Greater_Missile_Storm
        //           Isaacs_Lesser_Missile_Storm
        //           Knock
        //           Lesser_Dispel
        //           Lesser_Restoration
        //           Lesser_Spell_Breach
        //           Light
        //           Lightning_Bolt
        //           Mage_Armor
        //           Magic_Circle_against_Alignment
        //           Magic_Fang
        //           Magic_Missile
        //           Manipulate_Portal_Stone
        //           Mass_Camoflage
        //           Melfs_Acid_Arrow
        //           Meteor_Swarm
        //           Mind_Blank
        //           Mind_Fog
        //           Negative_Energy_Burst
        //           Negative_Energy_Protection
        //           Negative_Energy_Ray
        //           Neutralize_Poison
        //           One_With_The_Land
        //           Owls_Insight
        //           Owls_Wisdom
        //           Phantasmal_Killer
        //           Planar_Ally
        //           Poison
        //           Polymorph_Self
        //           Prayer
        //           Protection_from_Alignment
        //           Protection_From_Elements
        //           Quillfire
        //           Ray_of_Enfeeblement
        //           Ray_of_Frost
        //           Remove_Blindness/Deafness
        //           Remove_Curse
        //           Remove_Disease
        //           Remove_Fear
        //           Remove_Paralysis
        //           Resist_Elements
        //           Resistance
        //           Restoration
        //           Sanctuary
        //           Scare
        //           Searing_Light
        //           See_Invisibility
        //           Shadow_Conjuration
        //           Shield
        //           Shield_of_Faith
        //           Silence
        //           Sleep
        //           Slow
        //           Sound_Burst
        //           Spike_Growth
        //           Stinking_Cloud
        //           Stoneskin
        //           Summon_Creature_I
        //           Summon_Creature_I
        //           Summon_Creature_II
        //           Summon_Creature_III
        //           Summon_Creature_IV
        //           Sunburst
        //           Tashas_Hideous_Laughter
        //           True_Strike
        //           Undeaths_Eternal_Foe
        //           Unique_Power
        //           Unique_Power_Self_Only
        //           Vampiric_Touch
        //           Virtue
        //           Wall_of_Fire
        //           Web
        //           Wounding_Whispers
        // 
        //  POTIONS:
        //           Activate_Item
        //           Aid
        //           Amplify
        //           AuraOfGlory
        //           Bane
        //           Barkskin
        //           Barkskin
        //           Barkskin
        //           Bless
        //           Bless_Weapon
        //           Bless_Weapon
        //           Blood_Frenzy
        //           Bulls_Strength
        //           Bulls_Strength
        //           Bulls_Strength
        //           Camoflage
        //           Cats_Grace
        //           Cats_Grace
        //           Cats_Grace
        //           Clairaudience/Clairvoyance
        //           Clairaudience/Clairvoyance
        //           Clairaudience/Clairvoyance
        //           Clarity
        //           Continual_Flame
        //           Cure_Critical_Wounds
        //           Cure_Critical_Wounds
        //           Cure_Critical_Wounds
        //           Cure_Light_Wounds
        //           Cure_Light_Wounds
        //           Cure_Minor_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Moderate_Wounds
        //           Cure_Serious_Wounds
        //           Cure_Serious_Wounds
        //           Cure_Serious_Wounds
        //           Darkness
        //           Darkvision
        //           Darkvision
        //           Death_Ward
        //           Dispel_Magic
        //           Dispel_Magic
        //           Displacement
        //           Divine_Favor
        //           Divine_Might
        //           Divine_Power
        //           Divine_Shield
        //           Dragon_Breath_Acid
        //           Dragon_Breath_Cold
        //           Dragon_Breath_Fear
        //           Dragon_Breath_Fire
        //           Dragon_Breath_Gas
        //           Dragon_Breath_Lightning
        //           Dragon_Breath_Paralyze
        //           Dragon_Breath_Sleep
        //           Dragon_Breath_Slow
        //           Dragon_Breath_Weaken
        //           Eagle_Spledor
        //           Eagle_Spledor
        //           Eagle_Spledor
        //           Elemental_Shield
        //           Elemental_Shield
        //           Endurance
        //           Endurance
        //           Endurance
        //           Endure_Elements
        //           Entropic_Shield
        //           Ethereal_Visage
        //           Ethereal_Visage
        //           Etherealness
        //           Expeditious_Retreat
        //           Find_Traps
        //           Foxs_Cunning
        //           Foxs_Cunning
        //           Foxs_Cunning
        //           Freedom_of_Movement
        //           Ghostly_Visage
        //           Ghostly_Visage
        //           Ghostly_Visage
        //           Globe_of_Invulnerability
        //           Greater_Bulls_Strength
        //           Greater_Cats_Grace
        //           Greater_Dispelling
        //           Greater_Dispelling
        //           Greater_Eagles_Splendor
        //           Greater_Endurance
        //           Greater_Foxs_Cunning
        //           Greater_Magic_Weapon
        //           Greater_Owls_Wisdom
        //           Greater_Restoration
        //           Greater_Spell_Mantle
        //           Greater_Stoneskin
        //           Grenade_Acid
        //           Grenade_Caltrops
        //           Grenade_Chicken
        //           Grenade_Choking
        //           Grenade_Fire
        //           Grenade_Holy
        //           Grenade_Tangle
        //           Grenade_Thunderstone
        //           Haste
        //           Haste
        //           Heal
        //           Hold_Animal
        //           Hold_Monster
        //           Hold_Person
        //           Identify
        //           Invisibility
        //           Lesser_Dispel
        //           Lesser_Dispel
        //           Lesser_Mind_Blank
        //           Lesser_Restoration
        //           Lesser_Spell_Mantle
        //           Light
        //           Light
        //           Mage_Armor
        //           Manipulate_Portal_Stone
        //           Mass_Camoflage
        //           Mind_Blank
        //           Minor_Globe_of_Invulnerability
        //           Minor_Globe_of_Invulnerability
        //           Mordenkainens_Disjunction
        //           Negative_Energy_Protection
        //           Negative_Energy_Protection
        //           Negative_Energy_Protection
        //           Neutralize_Poison
        //           One_With_The_Land
        //           Owls_Insight
        //           Owls_Wisdom
        //           Owls_Wisdom
        //           Owls_Wisdom
        //           Polymorph_Self
        //           Prayer
        //           Premonition
        //           Protection_From_Elements
        //           Protection_From_Elements
        //           Protection_from_Spells
        //           Protection_from_Spells
        //           Raise_Dead
        //           Remove_Blindness/Deafness
        //           Remove_Curse
        //           Remove_Disease
        //           Remove_Fear
        //           Remove_Paralysis
        //           Resist_Elements
        //           Resist_Elements
        //           Resistance
        //           Resistance
        //           Restoration
        //           Resurrection
        //           Rogues_Cunning
        //           See_Invisibility
        //           Shadow_Shield
        //           Shapechange
        //           Shield
        //           Shield_of_Faith
        //           Special_Alcohol_Beer
        //           Special_Alcohol_Spirits
        //           Special_Alcohol_Wine
        //           Special_Herb_Belladonna
        //           Special_Herb_Garlic
        //           Spell_Mantle
        //           Spell_Resistance
        //           Spell_Resistance
        //           Stoneskin
        //           Tensers_Transformation
        //           True_Seeing
        //           True_Strike
        //           Unique_Power
        //           Unique_Power_Self_Only
        //           Virtue
        // 
        //  GENERAL USE (ie. everything else):
        //           Just about every spell is useable by all the general use items so instead we
        //           will only list the ones that are not allowed:
        //           Special_Alcohol_Beer
        //           Special_Alcohol_Spirits
        //           Special_Alcohol_Wine
        // 
        public static NWN.ItemProperty ItemPropertyCastSpell(int nSpell, int nNumUses)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumUses);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(630);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage bonus.  You must specify the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonus(int nDamageType, int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(631);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage bonus vs. Alignment groups.  You must specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsAlign(int nAlignGroup, int nDamageType, int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignGroup);
            NWN.Internal.NativeFunctions.CallBuiltIn(632);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage bonus vs. specific race.  You must specify the
        //  racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsRace(int nRace, int nDamageType, int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nRace);
            NWN.Internal.NativeFunctions.CallBuiltIn(633);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage bonus vs. specific alignment.  You must specify the
        //  specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageBonusVsSAlign(int nAlign, int nDamageType, int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlign);
            NWN.Internal.NativeFunctions.CallBuiltIn(634);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage immunity.  You must specify the damage type constant
        //  (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
        //  constant(IP_CONST_DAMAGEIMMUNITY_*).
        //  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
        //        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
        public static NWN.ItemProperty ItemPropertyDamageImmunity(int nDamageType, int nImmuneBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nImmuneBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(635);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage penalty.  You must specify the damage penalty.
        //  The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDamagePenalty(int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.CallBuiltIn(636);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage reduction.  You must specify the enhancment level
        //  (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
        //  and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
        //  up if your weapon is not of high enough enhancement.
        public static NWN.ItemProperty ItemPropertyDamageReduction(int nEnhancement, int nHPSoak)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHPSoak);
            NWN.Internal.NativeFunctions.StackPushInteger(nEnhancement);
            NWN.Internal.NativeFunctions.CallBuiltIn(637);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage resistance.  You must specify the damage type
        //  constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
        //  (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
        public static NWN.ItemProperty ItemPropertyDamageResistance(int nDamageType, int nHPResist)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHPResist);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(638);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property damage vulnerability.  You must specify the damage type
        //  constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
        //  and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
        public static NWN.ItemProperty ItemPropertyDamageVulnerability(int nDamageType, int nVulnerability)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nVulnerability);
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(639);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Return Item property Darkvision.
        public static NWN.ItemProperty ItemPropertyDarkvision()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(640);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Return Item property decrease ability score.  You must specify the ability
        //  constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
        //  a POSITIVE integer between 1 and 10 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseAbility(int nAbility, int nModifier)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifier);
            NWN.Internal.NativeFunctions.StackPushInteger(nAbility);
            NWN.Internal.NativeFunctions.CallBuiltIn(641);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property decrease Armor Class.  You must specify the armor
        //  modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
        //  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseAC(int nModifierType, int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.StackPushInteger(nModifierType);
            NWN.Internal.NativeFunctions.CallBuiltIn(642);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property decrease skill.  You must specify the constant for the
        //  skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
        //  must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyDecreaseSkill(int nSkill, int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(643);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property container reduced weight.  This is used for special
        //  containers that reduce the weight of the objects inside them.  You must
        //  specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
        public static NWN.ItemProperty ItemPropertyContainerReducedWeight(int nContainerType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nContainerType);
            NWN.Internal.NativeFunctions.CallBuiltIn(644);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property extra melee damage type.  You must specify the extra
        //  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
        //  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
        //        here.
        //  NOTE: It is also only applicable to melee weapons.
        public static NWN.ItemProperty ItemPropertyExtraMeleeDamageType(int nDamageType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(645);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property extra ranged damage type.  You must specify the extra
        //  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
        //  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
        //        here.
        //  NOTE: It is also only applicable to ranged weapons.
        public static NWN.ItemProperty ItemPropertyExtraRangeDamageType(int nDamageType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamageType);
            NWN.Internal.NativeFunctions.CallBuiltIn(646);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property haste.
        public static NWN.ItemProperty ItemPropertyHaste()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(647);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Holy Avenger.
        public static NWN.ItemProperty ItemPropertyHolyAvenger()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(648);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property immunity to miscellaneous effects.  You must specify the
        //  effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
        public static NWN.ItemProperty ItemPropertyImmunityMisc(int nImmunityType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nImmunityType);
            NWN.Internal.NativeFunctions.CallBuiltIn(649);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property improved evasion.
        public static NWN.ItemProperty ItemPropertyImprovedEvasion()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(650);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property bonus spell resistance.  You must specify the bonus spell
        //  resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
        public static NWN.ItemProperty ItemPropertyBonusSpellResistance(int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(651);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property saving throw bonus vs. a specific effect or damage type.
        //  You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
        //  applied to and the bonus that is be applied.  The bonus must be an integer
        //  between 1 and 20.
        public static NWN.ItemProperty ItemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nBonusType);
            NWN.Internal.NativeFunctions.CallBuiltIn(652);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property saving throw bonus to the base type (ie. will, reflex,
        //  fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
        //  to which the user gets the bonus and the bonus that he/she will get.  The
        //  bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nBaseSaveType);
            NWN.Internal.NativeFunctions.CallBuiltIn(653);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property keen.  This means a critical threat range of 19-20 on a
        //  weapon will be increased to 17-20 etc.
        public static NWN.ItemProperty ItemPropertyKeen()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(654);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property light.  You must specify the intesity constant of the
        //  light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
        //  (IP_CONST_LIGHTCOLOR_*).
        public static NWN.ItemProperty ItemPropertyLight(int nBrightness, int nColor)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nColor);
            NWN.Internal.NativeFunctions.StackPushInteger(nBrightness);
            NWN.Internal.NativeFunctions.CallBuiltIn(655);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Max range strength modification (ie. mighty).  You must
        //  specify the maximum modifier for strength that is allowed on a ranged weapon.
        //  The modifier must be a positive integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyMaxRangeStrengthMod(int nModifier)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifier);
            NWN.Internal.NativeFunctions.CallBuiltIn(656);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property no damage.  This means the weapon will do no damage in
        //  combat.
        public static NWN.ItemProperty ItemPropertyNoDamage()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(657);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property on hit -> do effect property.  You must specify the on
        //  hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
        //  Some of the item properties require a special parameter as well.  If the
        //  property does not require one you may leave out the last one.  The list of
        //  the ones with 3 parameters and what they are are as follows:
        //       ABILITYDRAIN      :nSpecial is the ability it is to drain.
        //                          constant(IP_CONST_ABILITY_*)
        //       BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       CONFUSION         :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DAZE              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       DISEASE           :nSpecial is the type of desease that will effect the victim.
        //                          constant(DISEASE_*)
        //       DOOM              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       FEAR              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       HOLD              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
        //                          constant(IP_CONST_POISON_*)
        //       SILENCE           :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       SLAYRACE          :nSpecial is the race that will be slain.
        //                          constant(IP_CONST_RACIALTYPE_*)
        //       SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
        //                          constant(IP_CONST_ALIGNMENTGROUP_*)
        //       SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
        //                          constant(IP_CONST_ALIGNMENT_*)
        //       SLEEP             :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       SLOW              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        //       STUN              :nSpecial is the duration/percentage of effecting victim.
        //                          constant(IP_CONST_ONHIT_DURATION_*)
        public static NWN.ItemProperty ItemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpecial);
            NWN.Internal.NativeFunctions.StackPushInteger(nSaveDC);
            NWN.Internal.NativeFunctions.StackPushInteger(nProperty);
            NWN.Internal.NativeFunctions.CallBuiltIn(658);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property reduced saving throw vs. an effect or damage type.  You must
        //  specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
        //  penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
        //  (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.StackPushInteger(nBaseSaveType);
            NWN.Internal.NativeFunctions.CallBuiltIn(659);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property reduced saving to base type.  You must specify the base
        //  type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
        //  to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
        //  The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyReducedSavingThrow(int nBonusType, int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.StackPushInteger(nBonusType);
            NWN.Internal.NativeFunctions.CallBuiltIn(660);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property regeneration.  You must specify the regeneration amount.
        //  The amount must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyRegeneration(int nRegenAmount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRegenAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(661);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property skill bonus.  You must specify the skill to which the user
        //  will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
        //  be an integer between 1 and 50.
        public static NWN.ItemProperty ItemPropertySkillBonus(int nSkill, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.CallBuiltIn(662);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property spell immunity vs. specific spell.  You must specify the
        //  spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
        public static NWN.ItemProperty ItemPropertySpellImmunitySpecific(int nSpell)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(663);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property spell immunity vs. spell school.  You must specify the
        //  school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
        public static NWN.ItemProperty ItemPropertySpellImmunitySchool(int nSchool)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSchool);
            NWN.Internal.NativeFunctions.CallBuiltIn(664);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Thieves tools.  You must specify the modifier you wish
        //  the tools to have.  The modifier must be an integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyThievesTools(int nModifier)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifier);
            NWN.Internal.NativeFunctions.CallBuiltIn(665);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
        //  must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonus(int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(666);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Attack bonus vs. alignment group.  You must specify the
        //  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
        //  bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsAlign(int nAlignGroup, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignGroup);
            NWN.Internal.NativeFunctions.CallBuiltIn(667);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property attack bonus vs. racial group.  You must specify the
        //  racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
        //  must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsRace(int nRace, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nRace);
            NWN.Internal.NativeFunctions.CallBuiltIn(668);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property attack bonus vs. a specific alignment.  You must specify
        //  the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
        //  attack bonus.  The bonus must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nBonus);
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignment);
            NWN.Internal.NativeFunctions.CallBuiltIn(669);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property attack penalty.  You must specify the attack penalty.
        //  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
        public static NWN.ItemProperty ItemPropertyAttackPenalty(int nPenalty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPenalty);
            NWN.Internal.NativeFunctions.CallBuiltIn(670);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property unlimited ammo.  If you leave the parameter field blank
        //  it will be just a normal bolt, arrow, or bullet.  However you may specify that
        //  you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
        //  bonus).  For this parmeter you use the constants beginning with:
        //       (IP_CONST_UNLIMITEDAMMO_*).
        public static NWN.ItemProperty ItemPropertyUnlimitedAmmo(int nAmmoDamage = IP_CONST_UNLIMITEDAMMO_BASIC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAmmoDamage);
            NWN.Internal.NativeFunctions.CallBuiltIn(671);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property limit use by alignment group.  You must specify the
        //  alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByAlign(int nAlignGroup)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignGroup);
            NWN.Internal.NativeFunctions.CallBuiltIn(672);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property limit use by class.  You must specify the class(es) who
        //  are able to use this item(IP_CONST_CLASS_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByClass(int nClass)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nClass);
            NWN.Internal.NativeFunctions.CallBuiltIn(673);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property limit use by race.  You must specify the race(s) who are
        //  allowed to use this item(IP_CONST_RACIALTYPE_*).
        public static NWN.ItemProperty ItemPropertyLimitUseByRace(int nRace)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRace);
            NWN.Internal.NativeFunctions.CallBuiltIn(674);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property limit use by specific alignment.  You must specify the
        //  alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
        public static NWN.ItemProperty ItemPropertyLimitUseBySAlign(int nAlignment)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAlignment);
            NWN.Internal.NativeFunctions.CallBuiltIn(675);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  replace this function it does nothing.
        public static NWN.ItemProperty BadBadReplaceMeThisDoesNothing()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(676);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property vampiric regeneration.  You must specify the amount of
        //  regeneration.  The regen amount must be an integer between 1 and 20.
        public static NWN.ItemProperty ItemPropertyVampiricRegeneration(int nRegenAmount)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRegenAmount);
            NWN.Internal.NativeFunctions.CallBuiltIn(677);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Trap.  You must specify the trap level constant
        //  (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
        public static NWN.ItemProperty ItemPropertyTrap(int nTrapLevel, int nTrapType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTrapType);
            NWN.Internal.NativeFunctions.StackPushInteger(nTrapLevel);
            NWN.Internal.NativeFunctions.CallBuiltIn(678);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property true seeing.
        public static NWN.ItemProperty ItemPropertyTrueSeeing()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(679);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Monster on hit apply effect property.  You must specify
        //  the property that you want applied on hit.  There are some properties that
        //  require an additional special parameter to be specified.  The others that
        //  don't require any additional parameter you may just put in the one.  The
        //  special cases are as follows:
        //       ABILITYDRAIN:nSpecial is the ability to drain.
        //                    constant(IP_CONST_ABILITY_*)
        //       DISEASE     :nSpecial is the disease that you want applied.
        //                    constant(DISEASE_*)
        //       LEVELDRAIN  :nSpecial is the number of levels that you want drained.
        //                    integer between 1 and 5.
        //       POISON      :nSpecial is the type of poison that will effect the victim.
        //                    constant(IP_CONST_POISON_*)
        //       WOUNDING    :nSpecial is the amount of wounding.
        //                    integer between 1 and 5.
        //  NOTE: Any that do not appear in the above list do not require the second
        //        parameter.
        //  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
        //        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
        public static NWN.ItemProperty ItemPropertyOnMonsterHitProperties(int nProperty, int nSpecial = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpecial);
            NWN.Internal.NativeFunctions.StackPushInteger(nProperty);
            NWN.Internal.NativeFunctions.CallBuiltIn(680);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property turn resistance.  You must specify the resistance bonus.
        //  The bonus must be an integer between 1 and 50.
        public static NWN.ItemProperty ItemPropertyTurnResistance(int nModifier)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifier);
            NWN.Internal.NativeFunctions.CallBuiltIn(681);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Massive Critical.  You must specify the extra damage
        //  constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
        public static NWN.ItemProperty ItemPropertyMassiveCritical(int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.CallBuiltIn(682);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property free action.
        public static NWN.ItemProperty ItemPropertyFreeAction()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(683);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property monster damage.  You must specify the amount of damage
        //  the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
        //  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
        //        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
        public static NWN.ItemProperty ItemPropertyMonsterDamage(int nDamage)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDamage);
            NWN.Internal.NativeFunctions.CallBuiltIn(684);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property immunity to spell level.  You must specify the level of
        //  which that and below the user will be immune.  The level must be an integer
        //  between 1 and 9.  By putting in a 3 it will mean the user is immune to all
        //  3rd level and lower spells.
        public static NWN.ItemProperty ItemPropertyImmunityToSpellLevel(int nLevel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLevel);
            NWN.Internal.NativeFunctions.CallBuiltIn(685);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property special walk.  If no parameters are specified it will
        //  automatically use the zombie walk.  This will apply the special walk animation
        //  to the user.
        public static NWN.ItemProperty ItemPropertySpecialWalk(int nWalkType = 0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nWalkType);
            NWN.Internal.NativeFunctions.CallBuiltIn(686);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property healers kit.  You must specify the level of the kit.
        //  The modifier must be an integer between 1 and 12.
        public static NWN.ItemProperty ItemPropertyHealersKit(int nModifier)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModifier);
            NWN.Internal.NativeFunctions.CallBuiltIn(687);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property weight increase.  You must specify the weight increase
        //  constant(IP_CONST_WEIGHTINCREASE_*).
        public static NWN.ItemProperty ItemPropertyWeightIncrease(int nWeight)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nWeight);
            NWN.Internal.NativeFunctions.CallBuiltIn(688);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************
        //  Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
        //  - oTarget: the creature using the skill
        //  - nSkill: the skill being used
        //  - nDifficulty: Difficulty class of skill
        public static int GetIsSkillSuccessful(NWN.Object oTarget, int nSkill, int nDifficulty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDifficulty);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkill);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(689);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Creates an effect that inhibits spells
        //  - nPercent - percentage of failure
        //  - nSpellSchool - the school of spells affected.
        public static NWN.Effect EffectSpellFailure(int nPercent = 100, int nSpellSchool = SPELL_SCHOOL_GENERAL)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nSpellSchool);
            NWN.Internal.NativeFunctions.StackPushInteger(nPercent);
            NWN.Internal.NativeFunctions.CallBuiltIn(690);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Causes the object to instantly speak a translated string.
        //  (not an action, not blocked when uncommandable)
        //  - nStrRef: Reference of the string in the talk table
        //  - nTalkVolume: TALKVOLUME_*
        public static void SpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTalkVolume);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(691);
        }

        //  Sets the given creature into cutscene mode.  This prevents the player from
        //  using the GUI and camera controls.
        //  - oCreature: creature in a cutscene
        //  - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode
        //  - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.
        //                          FALSE to stop the user from interacting with the game world.
        //  Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
        //  SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
        //  was when SetCutsceneMode(oPlayer, TRUE) was called.
        public static void SetCutsceneMode(NWN.Object oCreature, int nInCutscene = TRUE, int nLeftClickingEnabled = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLeftClickingEnabled);
            NWN.Internal.NativeFunctions.StackPushInteger(nInCutscene);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(692);
        }

        //  Gets the last player character to cancel from a cutscene.
        public static NWN.Object GetLastPCToCancelCutscene()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(693);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Gets the length of the specified wavefile, in seconds
        //  Only works for sounds used for dialog.
        public static float GetDialogSoundLength(int nStrRef)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(694);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Fades the screen for the given creature/player from black to regular screen
        //  - oCreature: creature controlled by player that should fade from black
        public static void FadeFromBlack(NWN.Object oCreature, float fSpeed = FADE_SPEED_MEDIUM)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fSpeed);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(695);
        }

        //  Fades the screen for the given creature/player from regular screen to black
        //  - oCreature: creature controlled by player that should fade to black
        public static void FadeToBlack(NWN.Object oCreature, float fSpeed = FADE_SPEED_MEDIUM)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fSpeed);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(696);
        }

        //  Removes any fading or black screen.
        //  - oCreature: creature controlled by player that should be cleared
        public static void StopFade(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(697);
        }

        //  Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
        //  Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
        //  - oCreature: creature controlled by player that should see black screen
        public static void BlackScreen(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(698);
        }

        //  Returns the base attach bonus for the given creature.
        public static int GetBaseAttackBonus(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(699);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set a creature's immortality flag.
        //  -oCreature: creature affected
        //  -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
        //              FALSE = creature is not immortal and is damaged normally.
        //  This scripting command only works on Creature objects.
        public static void SetImmortal(NWN.Object oCreature, int bImmortal)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bImmortal);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(700);
        }

        //  Open's this creature's inventory panel for this player
        //  - oCreature: creature to view
        //  - oPlayer: the owner of this creature will see the panel pop up
        //  * DM's can view any creature's inventory
        //  * Players can view their own inventory, or that of their henchman, familiar or animal companion
        public static void OpenInventory(NWN.Object oCreature, NWN.Object oPlayer)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(701);
        }

        //  Stores the current camera mode and position so that it can be restored (using
        //  RestoreCameraFacing())
        public static void StoreCameraFacing()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(702);
        }

        //  Restores the camera mode and position to what they were last time StoreCameraFacing
        //  was called.  RestoreCameraFacing can only be called once, and must correspond to a
        //  previous call to StoreCameraFacing.
        public static void RestoreCameraFacing()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(703);
        }

        //  Levels up a creature using default settings.
        //  If successfull it returns the level the creature now is, or 0 if it fails.
        //  If you want to give them a different level (ie: Give a Fighter a level of Wizard)
        //     you can specify that in the nClass.
        //  However, if you specify a class to which the creature no package specified,
        //    they will use the default package for that class for their levelup choices.
        //    (ie: no Barbarian Savage/Wizard Divination combinations)
        //  If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
        //  if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
        public static int LevelUpHenchman(NWN.Object oCreature, int nClass = CLASS_TYPE_INVALID, int bReadyAllSpells = FALSE, int nPackage = PACKAGE_INVALID)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPackage);
            NWN.Internal.NativeFunctions.StackPushInteger(bReadyAllSpells);
            NWN.Internal.NativeFunctions.StackPushInteger(nClass);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(704);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the droppable flag on an item
        //  - oItem: the item to change
        //  - bDroppable: TRUE or FALSE, whether the item should be droppable
        //  Droppable items will appear on a creature's remains when the creature is killed.
        public static void SetDroppableFlag(NWN.Object oItem, int bDroppable)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bDroppable);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(705);
        }

        //  Gets the weight of an item, or the total carried weight of a creature in tenths
        //  of pounds (as per the baseitems.2da).
        //  - oTarget: the item or creature for which the weight is needed
        public static int GetWeight(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(706);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the object that acquired the module item.  May be a creature, item, or placeable
        public static NWN.Object GetModuleItemAcquiredBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(707);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the immortal flag on a creature
        public static int GetImmortal(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(708);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Does a single attack on every hostile creature within 10ft. of the attacker
        //  and determines damage accordingly.  If the attacker has a ranged weapon
        //  equipped, this will have no effect.
        //  ** NOTE ** This is meant to be called inside the spell script for whirlwind
        //  attack, it is not meant to be used to queue up a new whirlwind attack.  To do
        //  that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
        //  - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be
        //    displayed
        //  - int bImproved: If TRUE, the improved version of whirlwind is used
        public static void DoWhirlwindAttack(int bDisplayFeedback = TRUE, int bImproved = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bImproved);
            NWN.Internal.NativeFunctions.StackPushInteger(bDisplayFeedback);
            NWN.Internal.NativeFunctions.CallBuiltIn(709);
        }

        //  Gets a value from a 2DA file on the server and returns it as a string
        //  avoid using this function in loops
        //  - s2DA: the name of the 2da file, 16 chars max
        //  - sColumn: the name of the column in the 2da
        //  - nRow: the row in the 2da
        //  * returns an empty string if file, row, or column not found
        public static string Get2DAString(string s2DA, string sColumn, int nRow)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRow);
            NWN.Internal.NativeFunctions.StackPushString(sColumn);
            NWN.Internal.NativeFunctions.StackPushString(s2DA);
            NWN.Internal.NativeFunctions.CallBuiltIn(710);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
        //  except that the observers get no saving throw
        public static NWN.Effect EffectEthereal()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(711);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Gets the current AI Level that the creature is running at.
        //  Returns one of the following:
        //  AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
        public static int GetAILevel(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(712);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the current AI Level of the creature to the value specified. Does not work on Players.
        //  The game by default will choose an appropriate AI level for
        //  creatures based on the circumstances that the creature is in.
        //  Explicitly setting an AI level will over ride the game AI settings.
        //  The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
        //  AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.
        //  AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
        //  AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
        //  AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
        //  AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
        public static void SetAILevel(NWN.Object oTarget, int nAILevel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAILevel);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(713);
        }

        //  This will return TRUE if the creature running the script is a familiar currently
        //  possessed by his master.
        //  returns FALSE if not or if the creature object is invalid
        public static int GetIsPossessedFamiliar(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(714);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  This will cause a Player Creature to unpossess his/her familiar.  It will work if run
        //  on the player creature or the possessed familiar.  It does not work in conjunction with
        //  any DM possession.
        public static void UnpossessFamiliar(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(715);
        }

        //  This will return TRUE if the area is flagged as either interior or underground.
        public static int GetIsAreaInterior(NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(716);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Send a server message (szMessage) to the oPlayer.
        public static void SendMessageToPCByStrRef(NWN.Object oPlayer, int nStrRef)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(717);
        }

        //  Increment the remaining uses per day for this creature by one.
        //  Total number of feats per day can not exceed the maximum.
        //  - oCreature: creature to modify
        //  - nFeat: constant FEAT_*
        public static void IncrementRemainingFeatUses(NWN.Object oCreature, int nFeat)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nFeat);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(718);
        }

        //  Force the character of the player specified to be exported to its respective directory
        //  i.e. LocalVault/ServerVault/ etc.
        public static void ExportSingleCharacter(NWN.Object oPlayer)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(719);
        }

        //  This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
        //  if nRunAsAction is off then the sound is forced to play intantly.
        public static void PlaySoundByStrRef(int nStrRef, int nRunAsAction = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRunAsAction);
            NWN.Internal.NativeFunctions.StackPushInteger(nStrRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(720);
        }

        //  Set the name of oCreature's sub race to sSubRace.
        public static void SetSubRace(NWN.Object oCreature, string sSubRace)
        {
            NWN.Internal.NativeFunctions.StackPushString(sSubRace);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(721);
        }

        //  Set the name of oCreature's Deity to sDeity.
        public static void SetDeity(NWN.Object oCreature, string sDeity)
        {
            NWN.Internal.NativeFunctions.StackPushString(sDeity);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(722);
        }

        //  Returns TRUE if the creature oCreature is currently possessed by a DM character.
        //  Returns FALSE otherwise.
        //  Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
        //  To determine if oCreature is a DM character use GetIsDM()
        public static int GetIsDMPossessed(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(723);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the current weather conditions for the area oArea.
        //    Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
        //    Note: If called on an Interior area, this will always return WEATHER_CLEAR.
        public static int GetWeather(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(724);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
        //  Returns AREA_INVALID, on an error.
        public static int GetIsAreaNatural(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(725);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
        //  Returns AREA_INVALID, on an error.
        public static int GetIsAreaAboveGround(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(726);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Use this to get the item last equipped by a player character in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastEquipped()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(727);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this to get the player character who last equipped an item in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastEquippedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(728);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
        public static NWN.Object GetPCItemLastUnequipped()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(729);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
        public static NWN.Object GetPCItemLastUnequippedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(730);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Creates a new copy of an item, while making a single change to the appearance of the item.
        //  Helmet models and simple items ignore iIndex.
        //  iType                            iIndex                              iNewValue
        //  ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
        //  ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            1-4
        //  ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
        //  ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
        //  ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-175 [1]
        // 
        //  [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
        //  desired, the following equation can be used for nIndex to achieve that:
        // 
        //    ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
        // 
        //  For example, to change the CLOTH1 channel of the torso, nIndex would be:
        // 
        //    6 + (7 * 6) + 2 = 50
        // 
        //  [1] When specifying per-part coloring, the value 255 is allowed and corresponds with the logical
        //  function 'clear colour override', which clears the per-part override for that part.
        public static NWN.Object CopyItemAndModify(NWN.Object oItem, int nType, int nIndex, int nNewValue, int bCopyVars = FALSE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bCopyVars);
            NWN.Internal.NativeFunctions.StackPushInteger(nNewValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nIndex);
            NWN.Internal.NativeFunctions.StackPushInteger(nType);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(731);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Queries the current value of the appearance settings on an item. The parameters are
        //  identical to those of CopyItemAndModify().
        public static int GetItemAppearance(NWN.Object oItem, int nType, int nIndex)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nIndex);
            NWN.Internal.NativeFunctions.StackPushInteger(nType);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(732);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Creates an item property that (when applied to a weapon item) causes a spell to be cast
        //  when a successful strike is made, or (when applied to armor) is struck by an opponent.
        //  - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
        public static NWN.ItemProperty ItemPropertyOnHitCastSpell(int nSpell, int nLevel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLevel);
            NWN.Internal.NativeFunctions.StackPushInteger(nSpell);
            NWN.Internal.NativeFunctions.CallBuiltIn(733);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns the SubType number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertySubType(NWN.ItemProperty iProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(iProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(734);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the status of ACTION_MODE_* modes on a creature.
        public static int GetActionMode(NWN.Object oCreature, int nMode)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMode);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(735);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the status of modes ACTION_MODE_* on a creature.
        public static void SetActionMode(NWN.Object oCreature, int nMode, int nStatus)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStatus);
            NWN.Internal.NativeFunctions.StackPushInteger(nMode);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(736);
        }

        //  Returns the current arcane spell failure factor of a creature
        public static int GetArcaneSpellFailure(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(737);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Makes a player examine the object oExamine. This causes the examination
        //  pop-up box to appear for the object specified.
        public static void ActionExamine(NWN.Object oExamine)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oExamine != null ? oExamine.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(738);
        }

        //  Creates a visual effect (ITEM_VISUAL_*) that may be applied to
        //  melee weapons only.
        public static NWN.ItemProperty ItemPropertyVisualEffect(int nEffect)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nEffect);
            NWN.Internal.NativeFunctions.CallBuiltIn(739);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Sets the lootable state of a *living* NPC creature.
        //  This function will *not* work on players or dead creatures.
        public static void SetLootable(NWN.Object oCreature, int bLootable)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bLootable);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(740);
        }

        //  Returns the lootable state of a creature.
        public static int GetLootable(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(741);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the current movement rate factor
        //  of the cutscene 'camera man'.
        //  NOTE: This will be a value between 0.1, 2.0 (10%-200%)
        public static float GetCutsceneCameraMoveRate(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(742);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Sets the current movement rate factor for the cutscene
        //  camera man.
        //  NOTE: You can only set values between 0.1, 2.0 (10%-200%)
        public static void SetCutsceneCameraMoveRate(NWN.Object oCreature, float fRate)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fRate);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(743);
        }

        //  Returns TRUE if the item is cursed and cannot be dropped
        public static int GetItemCursedFlag(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(744);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  When cursed, items cannot be dropped
        public static void SetItemCursedFlag(NWN.Object oItem, int nCursed)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCursed);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(745);
        }

        //  Sets the maximum number of henchmen
        public static void SetMaxHenchmen(int nNumHenchmen)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNumHenchmen);
            NWN.Internal.NativeFunctions.CallBuiltIn(746);
        }

        //  Gets the maximum number of henchmen
        public static int GetMaxHenchmen()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(747);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the associate type of the specified creature.
        //  - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
        public static int GetAssociateType(NWN.Object oAssociate)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oAssociate != null ? oAssociate.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(748);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the spell resistance of the specified creature.
        //  - Returns 0 if the creature has no spell resistance or an invalid
        //    creature is passed in.
        public static int GetSpellResistance(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(749);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Changes the current Day/Night cycle for this player to night
        //  - oPlayer: which player to change the lighting for
        //  - fTransitionTime: how long the transition should take
        public static void DayToNight(NWN.Object oPlayer, float fTransitionTime = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fTransitionTime);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(750);
        }

        //  Changes the current Day/Night cycle for this player to daylight
        //  - oPlayer: which player to change the lighting for
        //  - fTransitionTime: how long the transition should take
        public static void NightToDay(NWN.Object oPlayer, float fTransitionTime = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fTransitionTime);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(751);
        }

        //  Returns whether or not there is a direct line of sight
        //  between the two objects. (Not blocked by any geometry).
        // 
        //  PLEASE NOTE: This is an expensive function and may
        //               degrade performance if used frequently.
        public static int LineOfSightObject(NWN.Object oSource, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oSource != null ? oSource.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(752);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns whether or not there is a direct line of sight
        //  between the two vectors. (Not blocked by any geometry).
        // 
        //  This function must be run on a valid object in the area
        //  it will not work on the module or area.
        // 
        //  PLEASE NOTE: This is an expensive function and may
        //               degrade performance if used frequently.
        public static int LineOfSightVector(NWN.Vector? vSource, NWN.Vector? vTarget)
        {
            NWN.Internal.NativeFunctions.StackPushVector(vTarget.HasValue ? vTarget.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.StackPushVector(vSource.HasValue ? vSource.Value : new NWN.Vector());
            NWN.Internal.NativeFunctions.CallBuiltIn(753);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the class that the spellcaster cast the
        //  spell as.
        //  - Returns CLASS_TYPE_INVALID if the caster has
        //    no valid class (placeables, etc...)
        public static int GetLastSpellCastClass()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(754);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the number of base attacks for the specified
        //  creatures. The range of values accepted are from
        //  1 to 6
        //  Note: This function does not work on Player Characters
        public static void SetBaseAttackBonus(int nBaseAttackBonus, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nBaseAttackBonus);
            NWN.Internal.NativeFunctions.CallBuiltIn(755);
        }

        //  Restores the number of base attacks back to it's
        //  original state.
        public static void RestoreBaseAttackBonus(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(756);
        }

        //  Creates a cutscene ghost effect, this will allow creatures
        //  to pathfind through other creatures without bumping into them
        //  for the duration of the effect.
        public static NWN.Effect EffectCutsceneGhost()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(757);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Creates an item property that offsets the effect on arcane spell failure
        //  that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
        public static NWN.ItemProperty ItemPropertyArcaneSpellFailure(int nModLevel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nModLevel);
            NWN.Internal.NativeFunctions.CallBuiltIn(758);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns the amount of gold a store currently has. -1 indicates it is not using gold.
        //  -2 indicates the store could not be located.
        public static int GetStoreGold(NWN.Object oidStore)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(759);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the amount of gold a store has. -1 means the store does not use gold.
        public static void SetStoreGold(NWN.Object oidStore, int nGold)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nGold);
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(760);
        }

        //  Gets the maximum amount a store will pay for any item. -1 means price unlimited.
        //  -2 indicates the store could not be located.
        public static int GetStoreMaxBuyPrice(NWN.Object oidStore)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(761);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the maximum amount a store will pay for any item. -1 means price unlimited.
        public static void SetStoreMaxBuyPrice(NWN.Object oidStore, int nMaxBuy)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMaxBuy);
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(762);
        }

        //  Gets the amount a store charges for identifying an item. Default is 100. -1 means
        //  the store will not identify items.
        //  -2 indicates the store could not be located.
        public static int GetStoreIdentifyCost(NWN.Object oidStore)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(763);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the amount a store charges for identifying an item. Default is 100. -1 means
        //  the store will not identify items.
        public static void SetStoreIdentifyCost(NWN.Object oidStore, int nCost)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nCost);
            NWN.Internal.NativeFunctions.StackPushObject(oidStore != null ? oidStore.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(764);
        }

        //  Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
        public static void SetCreatureAppearanceType(NWN.Object oCreature, int nAppearanceType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAppearanceType);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(765);
        }

        //  Returns the default package selected for this creature to level up with
        //  - returns PACKAGE_INVALID if error occurs
        public static int GetCreatureStartingPackage(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(766);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns an effect that when applied will paralyze the target's legs, rendering
        //  them unable to walk but otherwise unpenalized. This effect cannot be resisted.
        public static NWN.Effect EffectCutsceneImmobilize()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(767);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Is this creature in the given subarea? (trigger, area of effect object, etc..)
        //  This function will tell you if the creature has triggered an onEnter event,
        //  not if it is physically within the space of the subarea
        public static int GetIsInSubArea(NWN.Object oCreature, NWN.Object oSubArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oSubArea != null ? oSubArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(768);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the Cost Table number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyCostTable(NWN.ItemProperty iProp)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(iProp.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(769);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the Cost Table value (index of the cost table) of the item property.
        //  See the 2DA files for value definitions.
        public static int GetItemPropertyCostTableValue(NWN.ItemProperty iProp)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(iProp.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(770);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the Param1 number of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyParam1(NWN.ItemProperty iProp)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(iProp.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(771);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the Param1 value of the item property. See the 2DA files for value definitions.
        public static int GetItemPropertyParam1Value(NWN.ItemProperty iProp)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(iProp.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(772);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Is this creature able to be disarmed? (checks disarm flag on creature, and if
        //  the creature actually has a weapon equipped in their right hand that is droppable)
        public static int GetIsCreatureDisarmable(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(773);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets whether this item is 'stolen' or not
        public static void SetStolenFlag(NWN.Object oItem, int nStolenFlag)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nStolenFlag);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(774);
        }

        //  Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
        public static void ForceRest(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(775);
        }

        //  Forces this player's camera to be set to this height. Setting this value to zero will
        //  restore the camera to the racial default height.
        public static void SetCameraHeight(NWN.Object oPlayer, float fHeight = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fHeight);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(776);
        }

        //  Changes the sky that is displayed in the specified area.
        //  nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetSkyBox(int nSkyBox, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nSkyBox);
            NWN.Internal.NativeFunctions.CallBuiltIn(777);
        }

        //  Returns the creature's currently set PhenoType (body type).
        public static int GetPhenoType(NWN.Object oCreature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(778);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the creature's PhenoType (body type) to the type specified.
        //  nPhenoType = PHENOTYPE_NORMAL
        //  nPhenoType = PHENOTYPE_BIG
        //  nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever
        //  be used if you have specifically created your own custom content that
        //  requires the use of a new PhenoType and you have specified the appropriate
        //  custom PhenoType in your custom content.
        //  SetPhenoType will only work on part based creature (i.e. the starting
        //  default playable races).
        public static void SetPhenoType(int nPhenoType, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nPhenoType);
            NWN.Internal.NativeFunctions.CallBuiltIn(779);
        }

        //  Sets the fog color in the area specified.
        //  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
        //  nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
        //  The fog color can also be represented as a hex RGB number if specific color shades
        //  are desired.
        //  The format of a hex specified color would be 0xFFEEDD where
        //  FF would represent the amount of red in the color
        //  EE would represent the amount of green in the color
        //  DD would represent the amount of blue in the color.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetFogColor(int nFogType, int nFogColor, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogColor);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogType);
            NWN.Internal.NativeFunctions.CallBuiltIn(780);
        }

        //  Gets the current cutscene state of the player specified by oCreature.
        //  Returns TRUE if the player is in cutscene mode.
        //  Returns FALSE if the player is not in cutscene mode, or on an error
        //  (such as specifying a non creature object).
        public static int GetCutsceneMode(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(781);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the skybox that is currently displayed in the specified area.
        //  Returns:
        //      SKYBOX_* constant
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetSkyBox(NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(782);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the fog color in the area specified.
        //  nFogType specifies wether the Sun, or Moon fog type is returned. 
        //     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetFogColor(int nFogType, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogType);
            NWN.Internal.NativeFunctions.CallBuiltIn(783);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the fog amount in the area specified.
        //  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
        //  nFogAmount = specifies the density that the fog is being set to.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static void SetFogAmount(int nFogType, int nFogAmount, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogAmount);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogType);
            NWN.Internal.NativeFunctions.CallBuiltIn(784);
        }

        //  Gets the fog amount in the area specified.
        //  nFogType = nFogType specifies wether the Sun, or Moon fog type is returned. 
        //     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
        //  If no valid area (or object) is specified, it uses the area of caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetFogAmount(int nFogType, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFogType);
            NWN.Internal.NativeFunctions.CallBuiltIn(785);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  returns TRUE if the item CAN be pickpocketed
        public static int GetPickpocketableFlag(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(786);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the Pickpocketable flag on an item
        //  - oItem: the item to change
        //  - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.
        public static void SetPickpocketableFlag(NWN.Object oItem, int bPickpocketable)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bPickpocketable);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(787);
        }

        //  returns the footstep type of the creature specified.
        //  The footstep type determines what the creature's footsteps sound
        //  like when ever they take a step.
        //  returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
        //  used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
        public static int GetFootstepType(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(788);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the footstep type of the creature specified.
        //  Changing a creature's footstep type will change the sound that
        //  its feet make when ever the creature makes takes a step.
        //  By default a creature's footsteps are detemined by the appearance
        //  type of the creature. SetFootstepType() allows you to make a
        //  creature use a difference footstep type than it would use by default
        //  for its given appearance.
        //  - nFootstepType (FOOTSTEP_TYPE_*):
        //       FOOTSTEP_TYPE_NORMAL
        //       FOOTSTEP_TYPE_LARGE
        //       FOOTSTEP_TYPE_DRAGON
        //       FOOTSTEP_TYPE_SoFT
        //       FOOTSTEP_TYPE_HOOF
        //       FOOTSTEP_TYPE_HOOF_LARGE
        //       FOOTSTEP_TYPE_BEETLE
        //       FOOTSTEP_TYPE_SPIDER
        //       FOOTSTEP_TYPE_SKELETON
        //       FOOTSTEP_TYPE_LEATHER_WING
        //       FOOTSTEP_TYPE_FEATHER_WING
        //       FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.
        //       FOOTSTEP_TYPE_NONE
        //  - oCreature: the creature to change the footstep sound for.
        public static void SetFootstepType(int nFootstepType, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nFootstepType);
            NWN.Internal.NativeFunctions.CallBuiltIn(789);
        }

        //  returns the Wing type of the creature specified.
        //       CREATURE_WING_TYPE_NONE
        //       CREATURE_WING_TYPE_DEMON
        //       CREATURE_WING_TYPE_ANGEL
        //       CREATURE_WING_TYPE_BAT
        //       CREATURE_WING_TYPE_DRAGON
        //       CREATURE_WING_TYPE_BUTTERFLY
        //       CREATURE_WING_TYPE_BIRD
        //  returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
        //  if the creature has no wings, or if the creature can not have its
        //  wing type changed in the toolset.
        public static int GetCreatureWingType(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(790);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the Wing type of the creature specified.
        //  - nWingType (CREATURE_WING_TYPE_*)
        //       CREATURE_WING_TYPE_NONE
        //       CREATURE_WING_TYPE_DEMON
        //       CREATURE_WING_TYPE_ANGEL
        //       CREATURE_WING_TYPE_BAT
        //       CREATURE_WING_TYPE_DRAGON
        //       CREATURE_WING_TYPE_BUTTERFLY
        //       CREATURE_WING_TYPE_BIRD
        //  - oCreature: the creature to change the wing type for.
        //  Note: Only two creature model types will support wings. 
        //  The MODELTYPE for the part based (playable races) 'P' 
        //  and MODELTYPE 'W'in the appearance.2da
        public static void SetCreatureWingType(int nWingType, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nWingType);
            NWN.Internal.NativeFunctions.CallBuiltIn(791);
        }

        //  returns the model number being used for the body part and creature specified
        //  The model number returned is for the body part when the creature is not wearing
        //  armor (i.e. whether or not the creature is wearing armor does not affect
        //  the return value).
        //  Note: Only works on part based creatures, which is typically restricted to
        //  the playable races (unless some new part based custom content has been 
        //  added to the module).
        // 
        //  returns CREATURE_PART_INVALID if used on a non-creature object,
        //  or if the creature does not use a part based model.
        // 
        //  - nPart (CREATURE_PART_*)
        //       CREATURE_PART_RIGHT_FOOT
        //       CREATURE_PART_LEFT_FOOT
        //       CREATURE_PART_RIGHT_SHIN
        //       CREATURE_PART_LEFT_SHIN
        //       CREATURE_PART_RIGHT_THIGH
        //       CREATURE_PART_LEFT_THIGH
        //       CREATURE_PART_PELVIS
        //       CREATURE_PART_TORSO
        //       CREATURE_PART_BELT
        //       CREATURE_PART_NECK
        //       CREATURE_PART_RIGHT_FOREARM
        //       CREATURE_PART_LEFT_FOREARM
        //       CREATURE_PART_RIGHT_BICEP
        //       CREATURE_PART_LEFT_BICEP
        //       CREATURE_PART_RIGHT_SHOULDER
        //       CREATURE_PART_LEFT_SHOULDER
        //       CREATURE_PART_RIGHT_HAND
        //       CREATURE_PART_LEFT_HAND
        //       CREATURE_PART_HEAD
        public static int GetCreatureBodyPart(int nPart, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nPart);
            NWN.Internal.NativeFunctions.CallBuiltIn(792);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the body part model to be used on the creature specified.
        //  The model names for parts need to be in the following format:
        //    p<m/f><race letter><phenotype>_<body part><model number>.mdl
        // 
        //  - nPart (CREATURE_PART_*)
        //       CREATURE_PART_RIGHT_FOOT
        //       CREATURE_PART_LEFT_FOOT
        //       CREATURE_PART_RIGHT_SHIN
        //       CREATURE_PART_LEFT_SHIN
        //       CREATURE_PART_RIGHT_THIGH
        //       CREATURE_PART_LEFT_THIGH
        //       CREATURE_PART_PELVIS
        //       CREATURE_PART_TORSO
        //       CREATURE_PART_BELT
        //       CREATURE_PART_NECK
        //       CREATURE_PART_RIGHT_FOREARM
        //       CREATURE_PART_LEFT_FOREARM
        //       CREATURE_PART_RIGHT_BICEP
        //       CREATURE_PART_LEFT_BICEP
        //       CREATURE_PART_RIGHT_SHOULDER
        //       CREATURE_PART_LEFT_SHOULDER
        //       CREATURE_PART_RIGHT_HAND
        //       CREATURE_PART_LEFT_HAND
        //       CREATURE_PART_HEAD
        //  - nModelNumber: CREATURE_MODEL_TYPE_*
        //       CREATURE_MODEL_TYPE_NONE
        //       CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
        //       CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
        //       CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
        //  - oCreature: the creature to change the body part for.
        //  Note: Only part based creature appearance types are supported. 
        //  i.e. The model types for the playable races ('P') in the appearance.2da
        public static void SetCreatureBodyPart(int nPart, int nModelNumber, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nModelNumber);
            NWN.Internal.NativeFunctions.StackPushInteger(nPart);
            NWN.Internal.NativeFunctions.CallBuiltIn(793);
        }

        //  returns the Tail type of the creature specified.
        //       CREATURE_TAIL_TYPE_NONE
        //       CREATURE_TAIL_TYPE_LIZARD
        //       CREATURE_TAIL_TYPE_BONE
        //       CREATURE_TAIL_TYPE_DEVIL
        //  returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
        //  if the creature has no Tail, or if the creature can not have its
        //  Tail type changed in the toolset.
        public static int GetCreatureTailType(NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(794);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the Tail type of the creature specified.
        //  - nTailType (CREATURE_TAIL_TYPE_*)
        //       CREATURE_TAIL_TYPE_NONE
        //       CREATURE_TAIL_TYPE_LIZARD
        //       CREATURE_TAIL_TYPE_BONE
        //       CREATURE_TAIL_TYPE_DEVIL
        //  - oCreature: the creature to change the Tail type for.
        //  Note: Only two creature model types will support Tails. 
        //  The MODELTYPE for the part based (playable) races 'P' 
        //  and MODELTYPE 'T'in the appearance.2da
        public static void SetCreatureTailType(int nTailType, NWN.Object oCreature = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oCreature != null ? oCreature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nTailType);
            NWN.Internal.NativeFunctions.CallBuiltIn(795);
        }

        //  returns the Hardness of a Door or Placeable object.
        //  - oObject: a door or placeable object.
        //  returns -1 on an error or if used on an object that is
        //  neither a door nor a placeable object.
        public static int GetHardness(NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(796);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the Hardness of a Door or Placeable object.
        //  - nHardness: must be between 0 and 250.
        //  - oObject: a door or placeable object.
        //  Does nothing if used on an object that is neither
        //  a door nor a placeable.
        public static void SetHardness(int nHardness, NWN.Object oObject = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nHardness);
            NWN.Internal.NativeFunctions.CallBuiltIn(797);
        }

        //  When set the object can not be opened unless the
        //  opener possesses the required key. The key tag required
        //  can be specified either in the toolset, or by using
        //  the SetLockKeyTag() scripting command.
        //  - oObject: a door, or placeable.
        //  - nKeyRequired: TRUE/FALSE
        public static void SetLockKeyRequired(NWN.Object oObject, int nKeyRequired = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nKeyRequired);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(798);
        }

        //  Set the key tag required to open object oObject.
        //  This will only have an effect if the object is set to
        //  "Key required to unlock or lock" either in the toolset
        //  or by using the scripting command SetLockKeyRequired().
        //  - oObject: a door, placeable or trigger.
        //  - sNewKeyTag: the key tag required to open the locked object.
        public static void SetLockKeyTag(NWN.Object oObject, string sNewKeyTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewKeyTag);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(799);
        }

        //  Sets whether or not the object can be locked.
        //  - oObject: a door or placeable.
        //  - nLockable: TRUE/FALSE
        public static void SetLockLockable(NWN.Object oObject, int nLockable = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nLockable);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(800);
        }

        //  Sets the DC for unlocking the object.
        //  - oObject: a door or placeable object.
        //  - nNewUnlockDC: must be between 0 and 250.
        public static void SetLockUnlockDC(NWN.Object oObject, int nNewUnlockDC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewUnlockDC);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(801);
        }

        //  Sets the DC for locking the object.
        //  - oObject: a door or placeable object.
        //  - nNewLockDC: must be between 0 and 250.
        public static void SetLockLockDC(NWN.Object oObject, int nNewLockDC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLockDC);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(802);
        }

        //  Sets whether or not the trapped object can be disarmed.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDisarmable: TRUE/FALSE
        public static void SetTrapDisarmable(NWN.Object oTrapObject, int nDisarmable = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDisarmable);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(803);
        }

        //  Sets whether or not the trapped object can be detected.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDetectable: TRUE/FALSE
        //  Note: Setting a trapped object to not be detectable will
        //  not make the trap disappear if it has already been detected.
        public static void SetTrapDetectable(NWN.Object oTrapObject, int nDetectable = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDetectable);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(804);
        }

        //  Sets whether or not the trap is a one-shot trap
        //  (i.e. whether or not the trap resets itself after firing).
        //  - oTrapObject: a placeable, door or trigger
        //  - nOneShot: TRUE/FALSE
        public static void SetTrapOneShot(NWN.Object oTrapObject, int nOneShot = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nOneShot);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(805);
        }

        //  Set the tag of the key that will disarm oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        public static void SetTrapKeyTag(NWN.Object oTrapObject, string sKeyTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sKeyTag);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(806);
        }

        //  Set the DC for disarming oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDisarmDC: must be between 0 and 250.
        public static void SetTrapDisarmDC(NWN.Object oTrapObject, int nDisarmDC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDisarmDC);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(807);
        }

        //  Set the DC for detecting oTrapObject.
        //  - oTrapObject: a placeable, door or trigger
        //  - nDetectDC: must be between 0 and 250.
        public static void SetTrapDetectDC(NWN.Object oTrapObject, int nDetectDC)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nDetectDC);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(808);
        }

        //  Creates a square Trap object.
        //  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
        //  - lLocation: The location and orientation that the trap will be created at.
        //  - fSize: The size of the trap. Minimum size allowed is 1.0f.
        //  - sTag: The tag of the trap being created.
        //  - nFaction: The faction of the trap (STANDARD_FACTION_*).
        //  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
        //                     If "" no script will fire.
        //  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
        //                            trap is triggered.
        //                            If "" the default OnTrapTriggered script for the trap
        //                            type specified will fire instead (as specified in the
        //                            traps.2da).
        public static NWN.Object CreateTrapAtLocation(int nTrapType, NWN.Location lLocation, float fSize = 2.0f, string sTag = "", int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sOnTrapTriggeredScript);
            NWN.Internal.NativeFunctions.StackPushString(sOnDisarmScript);
            NWN.Internal.NativeFunctions.StackPushInteger(nFaction);
            NWN.Internal.NativeFunctions.StackPushString(sTag);
            NWN.Internal.NativeFunctions.StackPushFloat(fSize);
            NWN.Internal.NativeFunctions.StackPushLocation(lLocation.Handle);
            NWN.Internal.NativeFunctions.StackPushInteger(nTrapType);
            NWN.Internal.NativeFunctions.CallBuiltIn(809);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Creates a Trap on the object specified.
        //  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
        //  - oObject: The object that the trap will be created on. Works only on Doors and Placeables.
        //  - nFaction: The faction of the trap (STANDARD_FACTION_*).
        //  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
        //                     If "" no script will fire.
        //  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
        //                            trap is triggered.
        //                            If "" the default OnTrapTriggered script for the trap
        //                            type specified will fire instead (as specified in the
        //                            traps.2da).
        //  Note: After creating a trap on an object, you can change the trap's properties
        //        using the various SetTrap* scripting commands by passing in the object
        //        that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
        public static void CreateTrapOnObject(int nTrapType, NWN.Object oObject, int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sOnTrapTriggeredScript);
            NWN.Internal.NativeFunctions.StackPushString(sOnDisarmScript);
            NWN.Internal.NativeFunctions.StackPushInteger(nFaction);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nTrapType);
            NWN.Internal.NativeFunctions.CallBuiltIn(810);
        }

        //  Set the Will saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nWillSave: must be between 0 and 250.
        public static void SetWillSavingThrow(NWN.Object oObject, int nWillSave)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nWillSave);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(811);
        }

        //  Set the Reflex saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nReflexSave: must be between 0 and 250.
        public static void SetReflexSavingThrow(NWN.Object oObject, int nReflexSave)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nReflexSave);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(812);
        }

        //  Set the Fortitude saving throw value of the Door or Placeable object oObject.
        //  - oObject: a door or placeable object.
        //  - nFortitudeSave: must be between 0 and 250.
        public static void SetFortitudeSavingThrow(NWN.Object oObject, int nFortitudeSave)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nFortitudeSave);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(813);
        }

        //  returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
        //       TILESET_RESREF_BEHOLDER_CAVES
        //       TILESET_RESREF_CASTLE_INTERIOR
        //       TILESET_RESREF_CITY_EXTERIOR
        //       TILESET_RESREF_CITY_INTERIOR
        //       TILESET_RESREF_CRYPT
        //       TILESET_RESREF_DESERT
        //       TILESET_RESREF_DROW_INTERIOR
        //       TILESET_RESREF_DUNGEON
        //       TILESET_RESREF_FOREST
        //       TILESET_RESREF_FROZEN_WASTES
        //       TILESET_RESREF_ILLITHID_INTERIOR
        //       TILESET_RESREF_MICROSET
        //       TILESET_RESREF_MINES_AND_CAVERNS
        //       TILESET_RESREF_RUINS
        //       TILESET_RESREF_RURAL
        //       TILESET_RESREF_RURAL_WINTER
        //       TILESET_RESREF_SEWERS
        //       TILESET_RESREF_UNDERDARK
        //  * returns an empty string on an error.
        public static string GetTilesetResRef(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(814);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject can be recovered.
        public static int GetTrapRecoverable(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(815);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets whether or not the trapped object can be recovered.
        //  - oTrapObject: a placeable, door or trigger
        public static void SetTrapRecoverable(NWN.Object oTrapObject, int nRecoverable = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nRecoverable);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(816);
        }

        //  Get the XP scale being used for the module.
        public static int GetModuleXPScale()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(817);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the XP scale used by the module.
        //  - nXPScale: The XP scale to be used. Must be between 0 and 200.
        public static void SetModuleXPScale(int nXPScale)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nXPScale);
            NWN.Internal.NativeFunctions.CallBuiltIn(818);
        }

        //  Get the feedback message that will be displayed when trying to unlock the object oObject.
        //  - oObject: a door or placeable.
        //  Returns an empty string "" on an error or if the game's default feedback message is being used
        public static string GetKeyRequiredFeedback(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(819);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Set the feedback message that is displayed when trying to unlock the object oObject.
        //  This will only have an effect if the object is set to
        //  "Key required to unlock or lock" either in the toolset
        //  or by using the scripting command SetLockKeyRequired().
        //  - oObject: a door or placeable.
        //  - sFeedbackMessage: the string to be displayed in the player's text window.
        //                      to use the game's default message, set sFeedbackMessage to ""
        public static void SetKeyRequiredFeedback(NWN.Object oObject, string sFeedbackMessage)
        {
            NWN.Internal.NativeFunctions.StackPushString(sFeedbackMessage);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(820);
        }

        //  - oTrapObject: a placeable, door or trigger
        //  * Returns TRUE if oTrapObject is active
        public static int GetTrapActive(NWN.Object oTrapObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(821);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets whether or not the trap is an active trap
        //  - oTrapObject: a placeable, door or trigger
        //  - nActive: TRUE/FALSE
        //  Notes:
        //  Setting a trap as inactive will not make the
        //  trap disappear if it has already been detected.
        //  Call SetTrapDetectedBy() to make a detected trap disappear.
        //  To make an inactive trap not detectable call SetTrapDetectable()
        public static void SetTrapActive(NWN.Object oTrapObject, int nActive = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nActive);
            NWN.Internal.NativeFunctions.StackPushObject(oTrapObject != null ? oTrapObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(822);
        }

        //  Locks the player's camera pitch to its current pitch setting,
        //  or unlocks the player's camera pitch.
        //  Stops the player from tilting their camera angle. 
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraPitch(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bLocked);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(823);
        }

        //  Locks the player's camera distance to its current distance setting,
        //  or unlocks the player's camera distance.
        //  Stops the player from being able to zoom in/out the camera.
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraDistance(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bLocked);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(824);
        }

        //  Locks the player's camera direction to its current direction,
        //  or unlocks the player's camera direction to enable it to move
        //  freely again.
        //  Stops the player from being able to rotate the camera direction.
        //  - oPlayer: A player object.
        //  - bLocked: TRUE/FALSE.
        public static void LockCameraDirection(NWN.Object oPlayer, int bLocked = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bLocked);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(825);
        }

        //  Get the last object that default clicked (left clicked) on the placeable object
        //  that is calling this function.
        //  Should only be called from a placeables OnClick event.
        //  * Returns OBJECT_INVALID if it is called by something other than a placeable.
        public static NWN.Object GetPlaceableLastClickedBy()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(826);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  returns TRUE if the item is flagged as infinite.
        //  - oItem: an item.
        //  The infinite property affects the buying/selling behavior of the item in a store.
        //  An infinite item will still be available to purchase from a store after a player
        //  buys the item (non-infinite items will disappear from the store when purchased).
        public static int GetInfiniteFlag(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(827);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the Infinite flag on an item
        //  - oItem: the item to change
        //  - bInfinite: TRUE or FALSE, whether the item should be Infinite
        //  The infinite property affects the buying/selling behavior of the item in a store.
        //  An infinite item will still be available to purchase from a store after a player
        //  buys the item (non-infinite items will disappear from the store when purchased).
        public static void SetInfiniteFlag(NWN.Object oItem, int bInfinite = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bInfinite);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(828);
        }

        //  Gets the size of the area.
        //  - nAreaDimension: The area dimension that you wish to determine.
        //       AREA_HEIGHT
        //       AREA_WIDTH
        //  - oArea: The area that you wish to get the size of.
        //  Returns: The number of tiles that the area is wide/high, or zero on an error.
        //  If no valid area (or object) is specified, it uses the area of the caller.
        //  If an object other than an area is specified, will use the area that the object is currently in.
        public static int GetAreaSize(int nAreaDimension, NWN.Object oArea = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushInteger(nAreaDimension);
            NWN.Internal.NativeFunctions.CallBuiltIn(829);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the name of oObject.
        //  - oObject: the object for which you are changing the name (a creature, placeable, item, or door).
        //  - sNewName: the new name that the object will use.
        //  Note: SetName() does not work on player objects.
        //        Setting an object's name to "" will make the object
        //        revert to using the name it had originally before any
        //        SetName() calls were made on the object.
        public static void SetName(NWN.Object oObject, string sNewName = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewName);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(830);
        }

        //  Get the PortraitId of oTarget.
        //  - oTarget: the object for which you are getting the portrait Id.
        //  Returns: The Portrait Id number being used for the object oTarget.
        //           The Portrait Id refers to the row number of the Portraits.2da
        //           that this portrait is from.
        //           If a custom portrait is being used, oTarget is a player object,
        //           or on an error returns PORTRAIT_INVALID. In these instances
        //           try using GetPortraitResRef() instead.
        public static int GetPortraitId(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(831);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Change the portrait of oTarget to use the Portrait Id specified.
        //  - oTarget: the object for which you are changing the portrait.
        //  - nPortraitId: The Id of the new portrait to use. 
        //                 nPortraitId refers to a row in the Portraits.2da
        //  Note: Not all portrait Ids are suitable for use with all object types.
        //        Setting the portrait Id will also cause the portrait ResRef
        //        to be set to the appropriate portrait ResRef for the Id specified.
        public static void SetPortraitId(NWN.Object oTarget, int nPortraitId)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nPortraitId);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(832);
        }

        //  Get the Portrait ResRef of oTarget.
        //  - oTarget: the object for which you are getting the portrait ResRef.
        //  Returns: The Portrait ResRef being used for the object oTarget.
        //           The Portrait ResRef will not include a trailing size letter.
        public static string GetPortraitResRef(NWN.Object oTarget = null)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(833);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Change the portrait of oTarget to use the Portrait ResRef specified.
        //  - oTarget: the object for which you are changing the portrait.
        //  - sPortraitResRef: The ResRef of the new portrait to use. 
        //                     The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
        //  Note: Not all portrait ResRefs are suitable for use with all object types.
        //        Setting the portrait ResRef will also cause the portrait Id
        //        to be set to PORTRAIT_INVALID.
        public static void SetPortraitResRef(NWN.Object oTarget, string sPortraitResRef)
        {
            NWN.Internal.NativeFunctions.StackPushString(sPortraitResRef);
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(834);
        }

        //  Set oPlaceable's useable object status.
        //  Note: Only works on non-static placeables.
        public static void SetUseableFlag(NWN.Object oPlaceable, int nUseableFlag)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nUseableFlag);
            NWN.Internal.NativeFunctions.StackPushObject(oPlaceable != null ? oPlaceable.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(835);
        }

        //  Get the description of oObject.
        //  - oObject: the object from which you are obtaining the description. 
        //             Can be a creature, item, placeable, door, trigger or module object.
        //  - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command
        //                    is ignored and the original object's description is returned instead.
        //  - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,
        //                 setting this to FALSE will return the unidentified description. This flag has no
        //                 effect on objects other than items.
        public static string GetDescription(NWN.Object oObject, int bOriginalDescription = FALSE, int bIdentifiedDescription = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bIdentifiedDescription);
            NWN.Internal.NativeFunctions.StackPushInteger(bOriginalDescription);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(836);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Set the description of oObject.
        //  - oObject: the object for which you are changing the description 
        //             Can be a creature, placeable, item, door, or trigger.
        //  - sNewDescription: the new description that the object will use.
        //  - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,
        //                 setting this to FALSE will set the unidentified description. This flag has no
        //                 effect on objects other than items.
        //  Note: Setting an object's description to "" will make the object
        //        revert to using the description it originally had before any
        //        SetDescription() calls were made on the object.
        public static void SetDescription(NWN.Object oObject, string sNewDescription = "", int bIdentifiedDescription = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bIdentifiedDescription);
            NWN.Internal.NativeFunctions.StackPushString(sNewDescription);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(837);
        }

        //  Get the PC that sent the last player chat(text) message.
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns OBJECT_INVALID on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static NWN.Object GetPCChatSpeaker()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(838);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Get the last player chat(text) message that was sent.
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns empty string "" on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static string GetPCChatMessage()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(839);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Get the volume of the last player chat(text) message that was sent.
        //  Returns one of the following TALKVOLUME_* constants based on the volume setting
        //  that the player used to send the chat message.
        //                 TALKVOLUME_TALK
        //                 TALKVOLUME_WHISPER
        //                 TALKVOLUME_SHOUT
        //                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
        //                 TALKVOLUME_PARTY
        //  Should only be called from a module's OnPlayerChat event script.
        //  * Returns -1 on error.
        //  Note: Private tells do not trigger a OnPlayerChat event.
        public static int GetPCChatVolume()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(840);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the last player chat(text) message before it gets sent to other players.
        //  - sNewChatMessage: The new chat text to be sent onto other players.
        //                     Setting the player chat message to an empty string "",
        //                     will cause the chat message to be discarded 
        //                     (i.e. it will not be sent to other players).
        //  Note: The new chat message gets sent after the OnPlayerChat script exits.
        public static void SetPCChatMessage(string sNewChatMessage = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewChatMessage);
            NWN.Internal.NativeFunctions.CallBuiltIn(841);
        }

        //  Set the last player chat(text) volume before it gets sent to other players.
        //  - nTalkVolume: The new volume of the chat text to be sent onto other players.
        //                 TALKVOLUME_TALK
        //                 TALKVOLUME_WHISPER
        //                 TALKVOLUME_SHOUT
        //                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
        //                 TALKVOLUME_PARTY
        //                 TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
        //  Note: The new chat message gets sent after the OnPlayerChat script exits.
        public static void SetPCChatVolume(int nTalkVolume = TALKVOLUME_TALK)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTalkVolume);
            NWN.Internal.NativeFunctions.CallBuiltIn(842);
        }

        //  Get the Color of oObject from the color channel specified.
        //  - oObject: the object from which you are obtaining the color. 
        //             Can be a creature that has color information (i.e. the playable races).
        //  - nColorChannel: The color channel that you want to get the color value of.
        //                    COLOR_CHANNEL_SKIN
        //                    COLOR_CHANNEL_HAIR
        //                    COLOR_CHANNEL_TATTOO_1
        //                    COLOR_CHANNEL_TATTOO_2
        //  * Returns -1 on error.
        public static int GetColor(NWN.Object oObject, int nColorChannel)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nColorChannel);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(843);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Set the color channel of oObject to the color specified.
        //  - oObject: the object for which you are changing the color.
        //             Can be a creature that has color information (i.e. the playable races).
        //  - nColorChannel: The color channel that you want to set the color value of.
        //                    COLOR_CHANNEL_SKIN
        //                    COLOR_CHANNEL_HAIR
        //                    COLOR_CHANNEL_TATTOO_1
        //                    COLOR_CHANNEL_TATTOO_2
        //  - nColorValue: The color you want to set (0-175).
        public static void SetColor(NWN.Object oObject, int nColorChannel, int nColorValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nColorValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nColorChannel);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(844);
        }

        //  Returns Item property Material.  You need to specify the Material Type.
        //  - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
        //  Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
        public static NWN.ItemProperty ItemPropertyMaterial(int nMaterialType)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMaterialType);
            NWN.Internal.NativeFunctions.CallBuiltIn(845);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns Item property Quality. You need to specify the Quality.
        //  - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).
        //               IP_CONST_QUALITY_*
        //  Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
        public static NWN.ItemProperty ItemPropertyQuality(int nQuality)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nQuality);
            NWN.Internal.NativeFunctions.CallBuiltIn(846);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns a generic Additional Item property. You need to specify the Additional property.
        //  - nProperty: The item property to create (see iprp_addcost.2da).
        //               IP_CONST_ADDITIONAL_*
        //  Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
        public static NWN.ItemProperty ItemPropertyAdditional(int nAdditionalProperty)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nAdditionalProperty);
            NWN.Internal.NativeFunctions.CallBuiltIn(847);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Sets a new tag for oObject.
        //  Will do nothing for invalid objects or the module object.
        // 
        //  Note: Care needs to be taken with this function.
        //        Changing the tag for creature with waypoints will make them stop walking them.
        //        Changing waypoint, door or trigger tags will break their area transitions.
        public static void SetTag(NWN.Object oObject, string sNewTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(848);
        }

        //  Returns the string tag set for the provided effect.
        //  - If no tag has been set, returns an empty string.
        public static string GetEffectTag(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(849);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Tags the effect with the provided string.
        //  - Any other tags in the link will be overwritten.
        public static NWN.Effect TagEffect(NWN.Effect eEffect, string sNewTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(850);
            return new NWN.Effect(NWN.Internal.NativeFunctions.StackPopEffect());
        }

        //  Returns the caster level of the creature who created the effect.
        //  - If not created by a creature, returns 0.
        //  - If created by a spell-like ability, returns 0.
        public static int GetEffectCasterLevel(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(851);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the total duration of the effect in seconds.
        //  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
        public static int GetEffectDuration(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(852);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the remaining duration of the effect in seconds.
        //  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
        public static int GetEffectDurationRemaining(NWN.Effect eEffect)
        {
            NWN.Internal.NativeFunctions.StackPushEffect(eEffect.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(853);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the string tag set for the provided item property.
        //  - If no tag has been set, returns an empty string.
        public static string GetItemPropertyTag(NWN.ItemProperty nProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(nProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(854);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Tags the item property with the provided string.
        //  - Any tags currently set on the item property will be overwritten.
        public static NWN.ItemProperty TagItemProperty(NWN.ItemProperty nProperty, string sNewTag)
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushItemProperty(nProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(855);
            return new NWN.ItemProperty(NWN.Internal.NativeFunctions.StackPopItemProperty());
        }

        //  Returns the total duration of the item property in seconds.
        //  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
        public static int GetItemPropertyDuration(NWN.ItemProperty nProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(nProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(856);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the remaining duration of the item property in seconds.
        //  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
        public static int GetItemPropertyDurationRemaining(NWN.ItemProperty nProperty)
        {
            NWN.Internal.NativeFunctions.StackPushItemProperty(nProperty.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(857);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Instances a new area from the given resref, which needs to be a existing module area.
        //  Will optionally set a new area tag and displayed name. The new area is accessible
        //  immediately, but initialisation scripts for the area and all contained creatures will only
        //  run after the current script finishes (so you can clean up objects before returning).
        // 
        //  Returns the new area, or OBJECT_INVALID on failure.
        // 
        //  Note: When spawning a second instance of a existing area, you will have to manually
        //        adjust all transitions (doors, triggers) with the relevant script commands,
        //        or players might end up in the wrong area.
        public static NWN.Object CreateArea(string sResRef, string sNewTag = "", string sNewName = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sNewName);
            NWN.Internal.NativeFunctions.StackPushString(sNewTag);
            NWN.Internal.NativeFunctions.StackPushString(sResRef);
            NWN.Internal.NativeFunctions.CallBuiltIn(858);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Destroys the given area object and everything in it.
        // 
        //  Return values:
        //     0: Object not an area or invalid.
        //    -1: Area contains spawn location and removal would leave module without entrypoint.
        //    -2: Players in area.
        //     1: Area destroyed successfully.
        public static int DestroyArea(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(859);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Creates a copy of a existing area, including everything inside of it (except players).
        // 
        //  Returns the new area, or OBJECT_INVALID on error.
        // 
        //  Note: You will have to manually adjust all transitions (doors, triggers) with the
        //        relevant script commands, or players might end up in the wrong area.
        public static NWN.Object CopyArea(NWN.Object oArea)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oArea != null ? oArea.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(860);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Returns the first area in the module.
        public static NWN.Object GetFirstArea()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(861);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Returns the next area in the module (after GetFirstArea), or OBJECT_INVALID if no more
        //  areas are loaded.
        public static NWN.Object GetNextArea()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(862);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        //  Sets the transition target for oTransition.
        // 
        //  Notes:
        //  - oTransition can be any valid game object, except areas.
        //  - oTarget can be any valid game object with a location, or OBJECT_INVALID (to unlink).
        //  - Rebinding a transition will NOT change the other end of the transition; for example,
        //    with normal doors you will have to do either end separately.
        //  - Any valid game object can hold a transition target, but only some are used by the game engine
        //    (doors and triggers). This might change in the future. You can still set and query them for
        //    other game objects from nwscript.
        //  - Transition target objects are cached: The toolset-configured destination tag is
        //    used for a lookup only once, at first use. Thus, attempting to use SetTag() to change the
        //    destination for a transition will not work in a predictable fashion.
        public static void SetTransitionTarget(NWN.Object oTransition, NWN.Object oTarget)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oTarget != null ? oTarget.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(oTransition != null ? oTransition.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(863);
        }

        //  Sets whether the provided item should be hidden when equipped.
        //  - The intended usage of this function is to provide an easy way to hide helmets, but it
        //    can be used equally for any slot which has creature mesh visibility when equipped,
        //    e.g.: armour, helm, cloak, left hand, and right hand.
        //  - nValue should be TRUE or FALSE.
        public static void SetHiddenWhenEquipped(NWN.Object oItem, int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(864);
        }

        //  Returns whether the provided item is hidden when equipped.
        public static int GetHiddenWhenEquipped(NWN.Object oItem)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oItem != null ? oItem.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(865);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets if the given creature has explored tile at x, y of the given area.
        //  Note that creature needs to be a player- or player-possessed creature.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  Return values:
        //   -1: Area or creature invalid.
        //    0: Tile was not explored before setting newState.
        //    1: Tile was explored before setting newState.
        public static int SetTileExplored(NWN.Object creature, NWN.Object area, int x, int y, int newState)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(newState);
            NWN.Internal.NativeFunctions.StackPushInteger(y);
            NWN.Internal.NativeFunctions.StackPushInteger(x);
            NWN.Internal.NativeFunctions.StackPushObject(area != null ? area.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(creature != null ? creature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(866);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns whether the given tile at x, y, for the given creature in the stated
        //  area is visible on the map.
        //  Note that creature needs to be a player- or player-possessed creature.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  Return values:
        //   -1: Area or creature invalid.
        //    0: Tile is not explored yet.
        //    1: Tile is explored.
        public static int GetTileExplored(NWN.Object creature, NWN.Object area, int x, int y)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(y);
            NWN.Internal.NativeFunctions.StackPushInteger(x);
            NWN.Internal.NativeFunctions.StackPushObject(area != null ? area.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushObject(creature != null ? creature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(867);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the creature to auto-explore the map as it walks around.
        // 
        //  Keep in mind that tile exploration also controls object visibility in areas
        //  and the fog of war for interior and underground areas.
        // 
        //  This means that if you turn off auto exploration, it falls to you to manage this
        //  through SetTileExplored(); otherwise, the player will not be able to see anything.
        // 
        //  Valid arguments: TRUE and FALSE.
        //  Does nothing for non-creatures.
        //  Returns the previous state (or -1 if non-creature).
        public static int SetCreatureExploresMinimap(NWN.Object creature, int newState)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(newState);
            NWN.Internal.NativeFunctions.StackPushObject(creature != null ? creature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(868);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns TRUE if the creature is set to auto-explore the map as it walks around (on by default).
        //  Returns FALSE if creature is not actually a creature.
        public static int GetCreatureExploresMinimap(NWN.Object creature)
        {
            NWN.Internal.NativeFunctions.StackPushObject(creature != null ? creature.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(869);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Get the surface material at the given location. (This is
        //  equivalent to the walkmesh type).
        //  Returns 0 if the location is invalid or has no surface type.
        public static int GetSurfaceMaterial(NWN.Location at)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(at.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(870);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the z-offset at which the walkmesh is at the given location.
        //  Returns -6.0 for invalid locations.
        public static float GetGroundHeight(NWN.Location at)
        {
            NWN.Internal.NativeFunctions.StackPushLocation(at.Handle);
            NWN.Internal.NativeFunctions.CallBuiltIn(871);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        //  Gets the attack bonus limit.
        //  - The default value is 20.
        public static int GetAttackBonusLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(872);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the damage bonus limit.
        //  - The default value is 100.
        public static int GetDamageBonusLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(873);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the saving throw bonus limit.
        //  - The default value is 20.
        public static int GetSavingThrowBonusLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(874);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the ability bonus limit.
        //  - The default value is 12.
        public static int GetAbilityBonusLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(875);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the ability penalty limit.
        //  - The default value is 30.
        public static int GetAbilityPenaltyLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(876);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Gets the skill bonus limit.
        //  - The default value is 50.
        public static int GetSkillBonusLimit()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(877);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Sets the attack bonus limit.
        //  - The minimum value is 0.
        public static void SetAttackBonusLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(878);
        }

        //  Sets the damage bonus limit.
        //  - The minimum value is 0.
        public static void SetDamageBonusLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(879);
        }

        //  Sets the saving throw bonus limit.
        //  - The minimum value is 0.
        public static void SetSavingThrowBonusLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(880);
        }

        //  Sets the ability bonus limit.
        //  - The minimum value is 0.
        public static void SetAbilityBonusLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(881);
        }

        //  Sets the ability penalty limit.
        //  - The minimum value is 0.
        public static void SetAbilityPenaltyLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(882);
        }

        //  Sets the skill bonus limit.
        //  - The minimum value is 0.
        public static void SetSkillBonusLimit(int nNewLimit)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nNewLimit);
            NWN.Internal.NativeFunctions.CallBuiltIn(883);
        }

        //  Get if oPlayer is currently connected over a relay (instead of directly).
        //  Returns FALSE for any other object, including OBJECT_INVALID.
        public static int GetIsPlayerConnectionRelayed(NWN.Object oPlayer)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(884);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        //  Returns the event script for the given object and handler.
        //  Will return "" if unset, the object is invalid, or the object cannot
        //  have the requested handler.
        public static string GetEventScript(NWN.Object oObject, int nHandler)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nHandler);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(885);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        //  Sets the given event script for the given object and handler.
        //  Returns 1 on success, 0 on failure.
        //  Will fail if oObject is invalid or does not have the requested handler.
        public static int SetEventScript(NWN.Object oObject, int nHandler, string sScript)
        {
            NWN.Internal.NativeFunctions.StackPushString(sScript);
            NWN.Internal.NativeFunctions.StackPushInteger(nHandler);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(886);
            return NWN.Internal.NativeFunctions.StackPopInteger();
        }

        // Gets a visual transform on the given object.
        // - oObject can be any valid Creature, Placeable, Item or Door.
        // - nTransform is one of OBJECT_VISUAL_TRANSFORM_*
        // Returns the current (or default) value.
        public static float GetObjectVisualTransform(NWN.Object oObject, int nTransform)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nTransform);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(887);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        // Sets a visual transform on the given object.
        // - oObject can be any valid Creature, Placeable, Item or Door.
        // - nTransform is one of OBJECT_VISUAL_TRANSFORM_*
        // - fValue depends on the transformation to apply.
        // Returns the old/previous value.
        public static float SetObjectVisualTransform(NWN.Object oObject, int nTransform, float fValue)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nTransform);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(888);
            return NWN.Internal.NativeFunctions.StackPopFloat();
        }

        // Sets an integer material shader uniform override.
        // - sMaterial needs to be a material on that object.
        // - sParam needs to be a valid shader parameter already defined on the material.
        public static void SetMaterialShaderUniformInt(NWN.Object oObject, string sMaterial, string sParam, int nValue)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nValue);
            NWN.Internal.NativeFunctions.StackPushString(sParam);
            NWN.Internal.NativeFunctions.StackPushString(sMaterial);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(889);
        }

        // Sets a vec4 material shader uniform override.
        // - sMaterial needs to be a material on that object.
        // - sParam needs to be a valid shader parameter already defined on the material.
        // - You can specify a single float value to set just a float, instead of a vec4.
        public static void SetMaterialShaderUniformVec4(NWN.Object oObject, string sMaterial, string sParam, float fValue1, float fValue2 = 0.0f, float fValue3 = 0.0f, float fValue4 = 0.0f)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fValue4);
            NWN.Internal.NativeFunctions.StackPushFloat(fValue3);
            NWN.Internal.NativeFunctions.StackPushFloat(fValue2);
            NWN.Internal.NativeFunctions.StackPushFloat(fValue1);
            NWN.Internal.NativeFunctions.StackPushString(sParam);
            NWN.Internal.NativeFunctions.StackPushString(sMaterial);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(890);
        }

        // Resets material shader parameters on the given object:
        // - Supply a material to only reset shader uniforms for meshes with that material.
        // - Supply a parameter to only reset shader uniforms of that name.
        // - Supply both to only reset shader uniforms of that name on meshes with that material.
        public static void ResetMaterialShaderUniforms(NWN.Object oObject, string sMaterial = "", string sParam = "")
        {
            NWN.Internal.NativeFunctions.StackPushString(sParam);
            NWN.Internal.NativeFunctions.StackPushString(sMaterial);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(891);
        }

        // Vibrate the player's device or controller. Does nothing if vibration is not supported.
        // - nMotor is one of VIBRATOR_MOTOR_*
        // - fStrength is between 0.0 and 1.0
        // - fSeconds is the number of seconds to vibrate
        public static void Vibrate(NWN.Object oPlayer, int nMotor, float fStrength, float fSeconds)
        {
            NWN.Internal.NativeFunctions.StackPushFloat(fSeconds);
            NWN.Internal.NativeFunctions.StackPushFloat(fStrength);
            NWN.Internal.NativeFunctions.StackPushInteger(nMotor);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(892);
        }

        // Unlock an achievement for the given player who must be logged in.
        // - sId is the achievement ID on the remote server
        // - nLastValue is the previous value of the associated achievement stat
        // - nCurValue is the current value of the associated achievement stat
        // - nMaxValue is the maximum value of the associate achievement stat
        public static void UnlockAchievement(NWN.Object oPlayer, string sId, int nLastValue=0, int nCurValue=0, int nMaxValue=0)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(nMaxValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nCurValue);
            NWN.Internal.NativeFunctions.StackPushInteger(nLastValue);
            NWN.Internal.NativeFunctions.StackPushString(sId);
            NWN.Internal.NativeFunctions.StackPushObject(oPlayer != null ? oPlayer.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(893);
        }

        // Execute a script chunk.
        // The script chunk runs immediately, same as ExecuteScript().
        // The script is jitted in place and currently not cached: Each invocation will recompile the script chunk.
        // Note that the script chunk will run as if a separate script. This is not eval().
        // By default, the script chunk is wrapped into void main() {}. Pass in bWrapIntoMain = FALSE to override.
        // Returns "" on success, or the compilation error.
        public static string ExecuteScriptChunk(string sScriptChunk, NWN.Object oObject, int bWrapIntoMain = TRUE)
        {
            NWN.Internal.NativeFunctions.StackPushInteger(bWrapIntoMain);
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.StackPushString(sScriptChunk);
            NWN.Internal.NativeFunctions.CallBuiltIn(894);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        // Returns a UUID. This UUID will not be associated with any object.
        // The generated UUID is currently a v4.
        public static string GetRandomUUID()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(895);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        // Returns the given objects' UUID. This UUID is persisted across save boundaries,
        // like Save/RestoreCampaignObject and save games.
        //
        // Thus, reidentification is only guaranteed in scenarios where players cannot introduce
        // new objects (i.e. servervault servers).
        //
        // UUIDs are guaranteed to be unique in any single running game.
        //
        // If a loaded object would collide with a UUID already present in the game, the
        // object receives no UUID and a warning is emitted to the log. Requesting a UUID
        // for the new object will generate a random one.
        //
        // This UUID is useful to, for example:
        // - Safely identify servervault characters
        // - Track serialisable objects (like items or creatures) as they are saved to the
        //   campaign DB - i.e. persistent storage chests or dropped items.
        // - Track objects across multiple game instances (in trusted scenarios).
        //
        // Currently, the following objects can carry UUIDs:
        //   Items, Creatures, Placeables, Triggers, Doors, Waypoints, Stores,
        //   Encounters, Areas.
        //
        // Will return "" (empty string) when the given object cannot carry a UUID.
        public static string GetObjectUUID(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(896);
            return NWN.Internal.NativeFunctions.StackPopString();
        }

        // Forces the given object to receive a new UUID, discarding the current value.
        public static void ForceRefreshObjectUUID(NWN.Object oObject)
        {
            NWN.Internal.NativeFunctions.StackPushObject(oObject != null ? oObject.Self : NWN.Object.OBJECT_INVALID);
            NWN.Internal.NativeFunctions.CallBuiltIn(897);
        }

        // Looks up a object on the server by it's UUID.
        // Returns OBJECT_INVALID if the UUID is not on the server.
        public static NWN.Object GetObjectByUUID(string sUUID)
        {
            NWN.Internal.NativeFunctions.StackPushString(sUUID);
            NWN.Internal.NativeFunctions.CallBuiltIn(898);
            return NWN.Internal.NativeFunctions.StackPopObject();
        }

        // Do not call. This does nothing on this platform except to return an error.
        public static void Reserved899()
        {
            NWN.Internal.NativeFunctions.CallBuiltIn(899);
        }
    }
}
