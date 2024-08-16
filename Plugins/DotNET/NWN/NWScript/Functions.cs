using System;
using System.Numerics;

namespace NWN
{
  public static partial class NWScript
  {
    public static uint OBJECT_SELF => Internal.OBJECT_SELF;

    /// <summary>
    /// Assign aActionToAssign to oActionSubject.
    /// * No return value, but if an error occurs, the log file will contain
    ///   "AssignCommand failed."
    ///   (If the object doesn't exist, nothing happens.)
    /// </summary>
    public static void AssignCommand(uint oActionSubject, ActionDelegate aActionToAssign)
    {
      Internal.ClosureAssignCommand(oActionSubject, aActionToAssign);
    }

    /// <summary>
    /// Delay aActionToDelay by fSeconds.
    /// * No return value, but if an error occurs, the log file will contain
    ///   "DelayCommand failed.".
    /// It is suggested that functions which create effects should not be used
    /// as parameters to delayed actions.  Instead, the effect should be created in the
    /// script and then passed into the action.  For example:
    /// effect eDamage = EffectDamage(nDamage, DAMAGE_TYPE_MAGICAL);
    /// DelayCommand(fDelay, ApplyEffectToObject(DURATION_TYPE_INSTANT, eDamage, oTarget);
    /// </summary>
    public static void DelayCommand(float fSeconds, ActionDelegate aActionToDelay)
    {
      Internal.ClosureDelayCommand(Internal.OBJECT_SELF, fSeconds, aActionToDelay);
    }

    /// <summary>
    /// Do aActionToDo.
    /// </summary>
    public static void ActionDoCommand(ActionDelegate aActionToDo)
    {
      Internal.ClosureActionDoCommand(Internal.OBJECT_SELF, aActionToDo);
    }

    /// <summary>
    ///  Get an integer between 0 and nMaxInteger-1.
    ///  Return value on error: 0
    /// </summary>
    public static int Random(int nMaxInteger)
    {
      NWNXPInvoke.StackPushInteger(nMaxInteger);
      NWNXPInvoke.CallBuiltIn(0);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Output sString to the log file.
    /// </summary>
    public static void PrintString(string sString)
    {
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(1);
    }

    /// <summary>
    ///  Output a formatted float to the log file.
    ///  - nWidth should be a value from 0 to 18 inclusive.
    ///  - nDecimals should be a value from 0 to 9 inclusive.
    /// </summary>
    public static void PrintFloat(float fFloat, int nWidth = 18, int nDecimals = 9)
    {
      NWNXPInvoke.StackPushInteger(nDecimals);
      NWNXPInvoke.StackPushInteger(nWidth);
      NWNXPInvoke.StackPushFloat(fFloat);
      NWNXPInvoke.CallBuiltIn(2);
    }

    /// <summary>
    ///  Convert fFloat into a string.
    ///  - nWidth should be a value from 0 to 18 inclusive.
    ///  - nDecimals should be a value from 0 to 9 inclusive.
    /// </summary>
    public static string FloatToString(float fFloat, int nWidth = 18, int nDecimals = 9)
    {
      NWNXPInvoke.StackPushInteger(nDecimals);
      NWNXPInvoke.StackPushInteger(nWidth);
      NWNXPInvoke.StackPushFloat(fFloat);
      NWNXPInvoke.CallBuiltIn(3);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Output nInteger to the log file.
    /// </summary>
    public static void PrintInteger(int nInteger)
    {
      NWNXPInvoke.StackPushInteger(nInteger);
      NWNXPInvoke.CallBuiltIn(4);
    }

    /// <summary>
    ///  Output oObject's ID to the log file.
    /// </summary>
    public static void PrintObject(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(5);
    }

    /// <summary>
    ///  Make oTarget run sScript and then return execution to the calling script.
    ///  If sScript does not specify a compiled script, nothing happens.
    /// </summary>
    public static void ExecuteScript(string sScript, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushString(sScript);
      NWNXPInvoke.CallBuiltIn(8);
    }

    /// <summary>
    ///  Clear all the actions of the caller.
    ///  * No return value, but if an error occurs, the log file will contain
    ///    "ClearAllActions failed.".
    ///  - nClearCombatState: if true, this will immediately clear the combat state
    ///    on a creature, which will stop the combat music and allow them to rest,
    ///    engage in dialog, or other actions that they would normally have to wait for.
    /// </summary>
    public static void ClearAllActions(int nClearCombatState = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nClearCombatState);
      NWNXPInvoke.CallBuiltIn(9);
    }

    /// <summary>
    ///  Cause the caller to face fDirection.
    ///  - fDirection is expressed as anticlockwise degrees from Due East.
    ///    DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
    ///    predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
    /// </summary>
    public static void SetFacing(float fDirection)
    {
      NWNXPInvoke.StackPushFloat(fDirection);
      NWNXPInvoke.CallBuiltIn(10);
    }

    /// <summary>
    ///  Set the calendar to the specified date.
    ///  - nYear should be from 0 to 32000 inclusive
    ///  - nMonth should be from 1 to 12 inclusive
    ///  - nDay should be from 1 to 28 inclusive
    ///  1) Time can only be advanced forwards; attempting to set the time backwards
    ///     will result in no change to the calendar.
    ///  2) If values larger than the month or day are specified, they will be wrapped
    ///     around and the overflow will be used to advance the next field.
    ///     e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
    ///     the calender being set to a year of 1352, a month of 9 and a day of 10.
    /// </summary>
    public static void SetCalendar(int nYear, int nMonth, int nDay)
    {
      NWNXPInvoke.StackPushInteger(nDay);
      NWNXPInvoke.StackPushInteger(nMonth);
      NWNXPInvoke.StackPushInteger(nYear);
      NWNXPInvoke.CallBuiltIn(11);
    }

    /// <summary>
    ///  Set the time to the time specified.
    ///  - nHour should be from 0 to 23 inclusive
    ///  - nMinute should be from 0 to 59 inclusive
    ///  - nSecond should be from 0 to 59 inclusive
    ///  - nMillisecond should be from 0 to 999 inclusive
    ///  1) Time can only be advanced forwards; attempting to set the time backwards
    ///     will result in the day advancing and then the time being set to that
    ///     specified, e.g. if the current hour is 15 and then the hour is set to 3,
    ///     the day will be advanced by 1 and the hour will be set to 3.
    ///  2) If values larger than the max hour, minute, second or millisecond are
    ///     specified, they will be wrapped around and the overflow will be used to
    ///     advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
    ///     and 10 milliseconds will result in the calendar day being advanced by 2
    ///     and the time being set to 18 hours, 10 minutes, 10 milliseconds.
    /// </summary>
    public static void SetTime(int nHour, int nMinute, int nSecond, int nMillisecond)
    {
      NWNXPInvoke.StackPushInteger(nMillisecond);
      NWNXPInvoke.StackPushInteger(nSecond);
      NWNXPInvoke.StackPushInteger(nMinute);
      NWNXPInvoke.StackPushInteger(nHour);
      NWNXPInvoke.CallBuiltIn(12);
    }

    /// <summary>
    ///  Get the current calendar year.
    /// </summary>
    public static int GetCalendarYear()
    {
      NWNXPInvoke.CallBuiltIn(13);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current calendar month.
    /// </summary>
    public static int GetCalendarMonth()
    {
      NWNXPInvoke.CallBuiltIn(14);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current calendar day.
    /// </summary>
    public static int GetCalendarDay()
    {
      NWNXPInvoke.CallBuiltIn(15);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current hour.
    /// </summary>
    public static int GetTimeHour()
    {
      NWNXPInvoke.CallBuiltIn(16);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current minute
    /// </summary>
    public static int GetTimeMinute()
    {
      NWNXPInvoke.CallBuiltIn(17);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current second
    /// </summary>
    public static int GetTimeSecond()
    {
      NWNXPInvoke.CallBuiltIn(18);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the current millisecond
    /// </summary>
    public static int GetTimeMillisecond()
    {
      NWNXPInvoke.CallBuiltIn(19);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The action subject will generate a random location near its current location
    ///  and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
    ///  to call ClearAllActions in order to allow a creature to perform any other action
    ///  once ActionRandomWalk has been called.
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionRandomWalk failed."
    /// </summary>
    public static void ActionRandomWalk()
    {
      NWNXPInvoke.CallBuiltIn(20);
    }

    /// <summary>
    ///  The action subject will move to lDestination.
    ///  - lDestination: The object will move to this location.  If the location is
    ///    invalid or a path cannot be found to it, the command does nothing.
    ///  - bRun: If this is TRUE, the action subject will run rather than walk
    ///  * No return value, but if an error occurs the log file will contain
    ///    "MoveToPoint failed."
    /// </summary>
    public static void ActionMoveToLocation(IntPtr lDestination, int bRun = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
      NWNXPInvoke.CallBuiltIn(21);
    }

    /// <summary>
    ///  Cause the action subject to move to a certain distance from oMoveTo.
    ///  If there is no path to oMoveTo, this command will do nothing.
    ///  - oMoveTo: This is the object we wish the action subject to move to
    ///  - bRun: If this is TRUE, the action subject will run rather than walk
    ///  - fRange: This is the desired distance between the action subject and oMoveTo
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionMoveToObject failed."
    /// </summary>
    public static void ActionMoveToObject(uint oMoveTo, int bRun = FALSE, float fRange = 1.0f)
    {
      NWNXPInvoke.StackPushFloat(fRange);
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushObject(oMoveTo);
      NWNXPInvoke.CallBuiltIn(22);
    }

    /// <summary>
    ///  Cause the action subject to move to a certain distance away from oFleeFrom.
    ///  - oFleeFrom: This is the object we wish the action subject to move away from.
    ///    If oFleeFrom is not in the same area as the action subject, nothing will
    ///    happen.
    ///  - bRun: If this is TRUE, the action subject will run rather than walk
    ///  - fMoveAwayRange: This is the distance we wish the action subject to put
    ///    between themselves and oFleeFrom
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionMoveAwayFromObject failed."
    /// </summary>
    public static void ActionMoveAwayFromObject(uint oFleeFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
    {
      NWNXPInvoke.StackPushFloat(fMoveAwayRange);
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushObject(oFleeFrom);
      NWNXPInvoke.CallBuiltIn(23);
    }

    /// <summary>
    ///  Get the area that oTarget is currently in
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetArea(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(24);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  The value returned by this function depends on the object type of the caller:
    ///  1) If the caller is a door it returns the object that last
    ///     triggered it.
    ///  2) If the caller is a trigger, area of effect, module, area or encounter it
    ///     returns the object that last entered it.
    ///  * Return value on error: OBJECT_INVALID
    ///   When used for doors, this should only be called from the OnAreaTransitionClick
    ///   event.  Otherwise, it should only be called in OnEnter scripts.
    /// </summary>
    public static uint GetEnteringObject()
    {
      NWNXPInvoke.CallBuiltIn(25);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the object that last left the caller.  This function works on triggers,
    ///  areas of effect, modules, areas and encounters.
    ///  * Return value on error: OBJECT_INVALID
    ///  Should only be called in OnExit scripts.
    /// </summary>
    public static uint GetExitingObject()
    {
      NWNXPInvoke.CallBuiltIn(26);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the position of oTarget
    ///  * Return value on error: vector (0.0f, 0.0f, 0.0f)
    /// </summary>
    public static Vector3 GetPosition(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(27);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  Get the direction in which oTarget is facing, expressed as a float between
    ///  0.0f and 360.0f
    ///  * Return value on error: -1.0f
    /// </summary>
    public static float GetFacing(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(28);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get the possessor of oItem
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetItemPossessor(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(29);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the object possessed by oCreature with the tag sItemTag
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetItemPossessedBy(uint oCreature, string sItemTag)
    {
      NWNXPInvoke.StackPushString(sItemTag);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(30);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create an item with the template sItemTemplate in oTarget's inventory.
    ///  - nStackSize: This is the stack size of the item to be created
    ///  - sNewTag: If this string is not empty, it will replace the default tag from the template
    ///  * Return value: The object that has been created.  On error, this returns
    ///    OBJECT_INVALID.
    ///  If the item created was merged into an existing stack of similar items,
    ///  the function will return the merged stack object. If the merged stack
    ///  overflowed, the function will return the overflowed stack that was created.
    /// </summary>
    public static uint CreateItemOnObject(string sItemTemplate, uint oTarget = OBJECT_INVALID, int nStackSize = 1, string sNewTag = "")
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushInteger(nStackSize);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushString(sItemTemplate);
      NWNXPInvoke.CallBuiltIn(31);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Equip oItem into nInventorySlot.
    ///  - nInventorySlot: INVENTORY_SLOT_*
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionEquipItem failed."
    ///
    ///  Note:
    ///        If the creature already has an item equipped in the slot specified, it will be
    ///        unequipped automatically by the call to ActionEquipItem.
    ///
    ///        In order for ActionEquipItem to succeed the creature must be able to equip the
    ///        item oItem normally. This means that:
    ///        1) The item is in the creature's inventory.
    ///        2) The item must already be identified (if magical).
    ///        3) The creature has the level required to equip the item (if magical and ILR is on).
    ///        4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
    /// </summary>
    public static void ActionEquipItem(uint oItem, int nInventorySlot)
    {
      NWNXPInvoke.StackPushInteger(nInventorySlot);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(32);
    }

    /// <summary>
    ///  Unequip oItem from whatever slot it is currently in.
    /// </summary>
    public static void ActionUnequipItem(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(33);
    }

    /// <summary>
    ///  Pick up oItem from the ground.
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionPickUpItem failed."
    /// </summary>
    public static void ActionPickUpItem(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(34);
    }

    /// <summary>
    ///  Put down oItem on the ground.
    ///  * No return value, but if an error occurs the log file will contain
    ///    "ActionPutDownItem failed."
    /// </summary>
    public static void ActionPutDownItem(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(35);
    }

    /// <summary>
    ///  Get the last attacker of oAttackee.  This should only be used ONLY in the
    ///  OnAttacked events for creatures, placeables and doors.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetLastAttacker(uint oAttackee = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oAttackee);
      NWNXPInvoke.CallBuiltIn(36);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Attack oAttackee.
    ///  - bPassive: If this is TRUE, attack is in passive mode.
    /// </summary>
    public static void ActionAttack(uint oAttackee, int bPassive = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bPassive);
      NWNXPInvoke.StackPushObject(oAttackee);
      NWNXPInvoke.CallBuiltIn(37);
    }

    /// <summary>
    ///  Get the creature nearest to oTarget, subject to all the criteria specified.
    ///  - nFirstCriteriaType: CREATURE_TYPE_*
    ///  - nFirstCriteriaValue:
    ///    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
    ///    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
    ///       or CREATURE_TYPE_HAS_SPELL_EFFECT
    ///    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
    ///    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
    ///    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
    ///       CREATURE_TYPE_PLAYER_CHAR
    ///    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
    ///    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
    ///    For example, to get the nearest PC, use:
    ///    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
    ///  - oTarget: We're trying to find the creature of the specified type that is
    ///    nearest to oTarget
    ///  - nNth: We don't have to find the first nearest: we can find the Nth nearest...
    ///  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
    ///    further specify the type of creature that we are looking for.
    ///  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
    ///    to further specify the type of creature that we are looking for.
    ///  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
    ///    further specify the type of creature that we are looking for.
    ///  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
    ///    further specify the type of creature that we are looking for.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, uint oTarget = OBJECT_INVALID, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
    {
      NWNXPInvoke.StackPushInteger(nThirdCriteriaValue);
      NWNXPInvoke.StackPushInteger(nThirdCriteriaType);
      NWNXPInvoke.StackPushInteger(nSecondCriteriaValue);
      NWNXPInvoke.StackPushInteger(nSecondCriteriaType);
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nFirstCriteriaValue);
      NWNXPInvoke.StackPushInteger(nFirstCriteriaType);
      NWNXPInvoke.CallBuiltIn(38);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Add a speak action to the action subject.
    ///  - sStringToSpeak: String to be spoken
    ///  - nTalkVolume: TALKVOLUME_*
    /// </summary>
    public static void ActionSpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
    {
      NWNXPInvoke.StackPushInteger(nTalkVolume);
      NWNXPInvoke.StackPushString(sStringToSpeak);
      NWNXPInvoke.CallBuiltIn(39);
    }

    /// <summary>
    ///  Cause the action subject to play an animation
    ///  - nAnimation: ANIMATION_*
    ///  - fSpeed: Speed of the animation
    ///  - fDurationSeconds: Duration of the animation (this is not used for Fire and
    ///    Forget animations)
    /// </summary>
    public static void ActionPlayAnimation(int nAnimation, float fSpeed = 1.0f, float fDurationSeconds = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fDurationSeconds);
      NWNXPInvoke.StackPushFloat(fSpeed);
      NWNXPInvoke.StackPushInteger(nAnimation);
      NWNXPInvoke.CallBuiltIn(40);
    }

    /// <summary>
    ///  Get the distance from the caller to oObject in metres.
    ///  * Return value on error: -1.0f
    /// </summary>
    public static float GetDistanceToObject(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(41);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  * Returns TRUE if oObject is a valid object.
    /// </summary>
    public static int GetIsObjectValid(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(42);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Cause the action subject to open oDoor
    /// </summary>
    public static void ActionOpenDoor(uint oDoor)
    {
      NWNXPInvoke.StackPushObject(oDoor);
      NWNXPInvoke.CallBuiltIn(43);
    }

    /// <summary>
    ///  Cause the action subject to close oDoor
    /// </summary>
    public static void ActionCloseDoor(uint oDoor)
    {
      NWNXPInvoke.StackPushObject(oDoor);
      NWNXPInvoke.CallBuiltIn(44);
    }

    /// <summary>
    ///  Change the direction in which the camera is facing
    ///  - fDirection is expressed as anticlockwise degrees from Due East.
    ///    (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
    ///  A value of -1.0f for any parameter will be ignored and instead it will
    ///  use the current camera value.
    ///  This can be used to change the way the camera is facing after the player
    ///  emerges from an area transition.
    ///  - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
    ///    camera to the new position, while the other types will result in the camera moving gradually into position
    ///  Pitch and distance are limited to valid values for the current camera mode:
    ///  Top Down: Distance = 5-20, Pitch = 1-50
    ///  Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
    ///  Chase: Distance = 5-20, Pitch = 1-50
    ///  *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
    ///  Distance 1-25
    ///  Pitch 1-89
    /// </summary>
    public static void SetCameraFacing(float fDirection, float fDistance = -1.0f, float fPitch = -1.0f, int nTransitionType = CAMERA_TRANSITION_TYPE_SNAP)
    {
      NWNXPInvoke.StackPushInteger(nTransitionType);
      NWNXPInvoke.StackPushFloat(fPitch);
      NWNXPInvoke.StackPushFloat(fDistance);
      NWNXPInvoke.StackPushFloat(fDirection);
      NWNXPInvoke.CallBuiltIn(45);
    }

    /// <summary>
    ///  Play sSoundName
    ///  - sSoundName: TBD - SS
    ///  This will play a mono sound from the location of the object running the command.
    /// </summary>
    public static void PlaySound(string sSoundName)
    {
      NWNXPInvoke.StackPushString(sSoundName);
      NWNXPInvoke.CallBuiltIn(46);
    }

    /// <summary>
    ///  Get the object at which the caller last cast a spell
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetSpellTargetObject()
    {
      NWNXPInvoke.CallBuiltIn(47);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  This action casts a spell at oTarget.
    ///  - nSpell: SPELL_*
    ///  - oTarget: Target for the spell
    ///  - nMetamagic: METAMAGIC_*
    ///  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
    ///    able to cast the spell.
    ///  - nDomainLevel: TBD - SS
    ///  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
    ///  - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows
    ///    the end-user to simulate a high-level magic-user having lots of advance
    ///    warning of impending trouble
    /// </summary>
    public static void ActionCastSpellAtObject(int nSpell, uint oTarget, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nDomainLevel = 0, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bInstantSpell);
      NWNXPInvoke.StackPushInteger(nProjectilePathType);
      NWNXPInvoke.StackPushInteger(nDomainLevel);
      NWNXPInvoke.StackPushInteger(bCheat);
      NWNXPInvoke.StackPushInteger(nMetaMagic);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(48);
    }

    /// <summary>
    ///  Get the current hitpoints of oObject
    ///  * Return value on error: 0
    /// </summary>
    public static int GetCurrentHitPoints(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(49);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the maximum hitpoints of oObject
    ///  * Return value on error: 0
    /// </summary>
    public static int GetMaxHitPoints(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(50);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oObject's local integer variable sVarName
    ///  * Return value on error: 0
    /// </summary>
    public static int GetLocalInt(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(51);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oObject's local float variable sVarName
    ///  * Return value on error: 0.0f
    /// </summary>
    public static float GetLocalFloat(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(52);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get oObject's local string variable sVarName
    ///  * Return value on error: ""
    /// </summary>
    public static string GetLocalString(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(53);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get oObject's local object variable sVarName
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetLocalObject(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(54);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Set oObject's local integer variable sVarName to nValue
    /// </summary>
    public static void SetLocalInt(uint oObject, string sVarName, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(55);
    }

    /// <summary>
    ///  Set oObject's local float variable sVarName to nValue
    /// </summary>
    public static void SetLocalFloat(uint oObject, string sVarName, float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(56);
    }

    /// <summary>
    ///  Set oObject's local string variable sVarName to nValue
    /// </summary>
    public static void SetLocalString(uint oObject, string sVarName, string sValue)
    {
      NWNXPInvoke.StackPushString(sValue);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(57);
    }

    /// <summary>
    ///  Set oObject's local object variable sVarName to nValue
    /// </summary>
    public static void SetLocalObject(uint oObject, string sVarName, uint oValue)
    {
      NWNXPInvoke.StackPushObject(oValue);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(58);
    }

    /// <summary>
    ///  Get the length of sString
    ///  * Return value on error: -1
    /// </summary>
    public static int GetStringLength(string sString)
    {
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(59);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Convert sString into upper case
    ///  * Return value on error: ""
    /// </summary>
    public static string GetStringUpperCase(string sString)
    {
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(60);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Convert sString into lower case
    ///  * Return value on error: ""
    /// </summary>
    public static string GetStringLowerCase(string sString)
    {
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(61);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get nCount characters from the right end of sString
    ///  * Return value on error: ""
    /// </summary>
    public static string GetStringRight(string sString, int nCount)
    {
      NWNXPInvoke.StackPushInteger(nCount);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(62);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get nCounter characters from the left end of sString
    ///  * Return value on error: ""
    /// </summary>
    public static string GetStringLeft(string sString, int nCount)
    {
      NWNXPInvoke.StackPushInteger(nCount);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(63);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Insert sString into sDestination at nPosition
    ///  * Return value on error: ""
    /// </summary>
    public static string InsertString(string sDestination, string sString, int nPosition)
    {
      NWNXPInvoke.StackPushInteger(nPosition);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.StackPushString(sDestination);
      NWNXPInvoke.CallBuiltIn(64);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get nCount characters from sString, starting at nStart
    ///  * Return value on error: ""
    /// </summary>
    public static string GetSubString(string sString, int nStart, int nCount)
    {
      NWNXPInvoke.StackPushInteger(nCount);
      NWNXPInvoke.StackPushInteger(nStart);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(65);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Find the position of sSubstring inside sString
    ///  - nStart: The character position to start searching at (from the left end of the string).
    ///  * Return value on error: -1
    /// </summary>
    public static int FindSubString(string sString, string sSubString, int nStart = 0)
    {
      NWNXPInvoke.StackPushInteger(nStart);
      NWNXPInvoke.StackPushString(sSubString);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.CallBuiltIn(66);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  math operations
    ///  Maths operation: absolute value of fValue
    /// </summary>
    public static float fabs(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(67);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: cosine of fValue
    /// </summary>
    public static float cos(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(68);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: sine of fValue
    /// </summary>
    public static float sin(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(69);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: tan of fValue
    /// </summary>
    public static float tan(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(70);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: arccosine of fValue
    ///  * Returns zero if fValue > 1 or fValue < -1
    /// </summary>
    public static float acos(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(71);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: arcsine of fValue
    ///  * Returns zero if fValue >1 or fValue < -1
    /// </summary>
    public static float asin(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(72);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: arctan of fValue
    /// </summary>
    public static float atan(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(73);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: log of fValue
    ///  * Returns zero if fValue <= zero
    /// </summary>
    public static float log(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(74);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: fValue is raised to the power of fExponent
    ///  * Returns zero if fValue ==0 and fExponent <0
    /// </summary>
    public static float pow(float fValue, float fExponent)
    {
      NWNXPInvoke.StackPushFloat(fExponent);
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(75);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: square root of fValue
    ///  * Returns zero if fValue <0
    /// </summary>
    public static float sqrt(float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.CallBuiltIn(76);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Maths operation: integer absolute value of nValue
    ///  * Return value on error: 0
    /// </summary>
    public static int abs(int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.CallBuiltIn(77);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Heal effect. This should be applied as an instantaneous effect.
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
    /// </summary>
    public static IntPtr EffectHeal(int nDamageToHeal)
    {
      NWNXPInvoke.StackPushInteger(nDamageToHeal);
      NWNXPInvoke.CallBuiltIn(78);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage effect
    ///  - nDamageAmount: amount of damage to be dealt. This should be applied as an
    ///    instantaneous effect.
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  - nDamagePower: DAMAGE_POWER_*
    /// </summary>
    public static IntPtr EffectDamage(int nDamageAmount, int nDamageType = DAMAGE_TYPE_MAGICAL, int nDamagePower = DAMAGE_POWER_NORMAL)
    {
      NWNXPInvoke.StackPushInteger(nDamagePower);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nDamageAmount);
      NWNXPInvoke.CallBuiltIn(79);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an Ability Increase effect
    ///  - bAbilityToIncrease: ABILITY_*
    /// </summary>
    public static IntPtr EffectAbilityIncrease(int nAbilityToIncrease, int nModifyBy)
    {
      NWNXPInvoke.StackPushInteger(nModifyBy);
      NWNXPInvoke.StackPushInteger(nAbilityToIncrease);
      NWNXPInvoke.CallBuiltIn(80);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage Resistance effect that removes the first nAmount points of
    ///  damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  - nAmount
    ///  - nLimit
    /// </summary>
    public static IntPtr EffectDamageResistance(int nDamageType, int nAmount, int nLimit = 0)
    {
      NWNXPInvoke.StackPushInteger(nLimit);
      NWNXPInvoke.StackPushInteger(nAmount);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(81);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Resurrection effect. This should be applied as an instantaneous effect.
    /// </summary>
    public static IntPtr EffectResurrection()
    {
      NWNXPInvoke.CallBuiltIn(82);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Summon Creature effect.  The creature is created and placed into the
    ///  caller's party/faction.
    ///  - sCreatureResref: Identifies the creature to be summoned
    ///  - nVisualEffectId: VFX_*
    ///  - fDelaySeconds: There can be delay between the visual effect being played, and the
    ///    creature being added to the area
    ///  - nUseAppearAnimation: should this creature play it's "appear" animation when it is
    ///    summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
    ///    it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
    /// </summary>
    public static IntPtr EffectSummonCreature(string sCreatureResref, int nVisualEffectId = VFX_NONE, float fDelaySeconds = 0.0f, int nUseAppearAnimation = 0)
    {
      NWNXPInvoke.StackPushInteger(nUseAppearAnimation);
      NWNXPInvoke.StackPushFloat(fDelaySeconds);
      NWNXPInvoke.StackPushInteger(nVisualEffectId);
      NWNXPInvoke.StackPushString(sCreatureResref);
      NWNXPInvoke.CallBuiltIn(83);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the level at which this creature cast it's last spell (or spell-like ability)
    ///  * Return value on error, or if oCreature has not yet cast a spell: 0;
    /// </summary>
    public static int GetCasterLevel(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(84);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the first in-game effect on oCreature.
    /// </summary>
    public static IntPtr GetFirstEffect(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(85);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the next in-game effect on oCreature.
    /// </summary>
    public static IntPtr GetNextEffect(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(86);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Remove eEffect from oCreature.
    ///  * No return value
    /// </summary>
    public static void RemoveEffect(uint oCreature, IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(87);
    }

    /// <summary>
    ///  * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
    ///  * an object or else it will return FALSE
    /// </summary>
    public static int GetIsEffectValid(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(88);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the duration type (DURATION_TYPE_*) of eEffect.
    ///  * Return value if eEffect is not valid: -1
    /// </summary>
    public static int GetEffectDurationType(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(89);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the subtype (SUBTYPE_*) of eEffect.
    ///  * Return value on error: 0
    /// </summary>
    public static int GetEffectSubType(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(90);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the object that created eEffect.
    ///  * Returns OBJECT_INVALID if eEffect is not a valid effect.
    /// </summary>
    public static uint GetEffectCreator(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(91);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Convert nInteger into a string.
    ///  * Return value on error: ""
    /// </summary>
    public static string IntToString(int nInteger)
    {
      NWNXPInvoke.StackPushInteger(nInteger);
      NWNXPInvoke.CallBuiltIn(92);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the first object in oArea.
    ///  If no valid area is specified, it will use the caller's area.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetFirstObjectInArea(uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(93);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next object in oArea.
    ///  If no valid area is specified, it will use the caller's area.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNextObjectInArea(uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(94);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d2 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d2(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(95);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d3 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d3(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(96);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d4 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d4(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(97);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d6 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d6(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(98);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d8 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d8(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(99);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d10 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d10(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(100);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d12 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d12(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(101);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d20 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d20(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(102);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total from rolling (nNumDice x d100 dice).
    ///  - nNumDice: If this is less than 1, the value 1 will be used.
    /// </summary>
    public static int d100(int nNumDice = 1)
    {
      NWNXPInvoke.StackPushInteger(nNumDice);
      NWNXPInvoke.CallBuiltIn(103);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the magnitude of vVector; this can be used to determine the
    ///  distance between two points.
    ///  * Return value on error: 0.0f
    /// </summary>
    public static float VectorMagnitude(Vector3 vVector)
    {
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.CallBuiltIn(104);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
    ///  * Return value if the caster is not a valid object: -1
    /// </summary>
    public static int GetMetaMagicFeat()
    {
      NWNXPInvoke.CallBuiltIn(105);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the object type (OBJECT_TYPE_*) of oTarget
    ///  * Return value if oTarget is not a valid object: -1
    /// </summary>
    public static int GetObjectType(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(106);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the racial type (RACIAL_TYPE_*) of oCreature
    ///  * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
    /// </summary>
    public static int GetRacialType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(107);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Do a Fortitude Save check for the given DC
    ///  - oCreature
    ///  - nDC: Difficulty check
    ///  - nSaveType: SAVING_THROW_TYPE_*
    ///  - oSaveVersus
    ///  Returns: 0 if the saving throw roll failed
    ///  Returns: 1 if the saving throw roll succeeded
    ///  Returns: 2 if the target was immune to the save type specified
    ///  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
    ///  GetAreaOfEffectCreator() into oSaveVersus!!
    /// </summary>
    public static int FortitudeSave(uint oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, uint oSaveVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSaveVersus);
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nDC);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(108);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Does a Reflex Save check for the given DC
    ///  - oCreature
    ///  - nDC: Difficulty check
    ///  - nSaveType: SAVING_THROW_TYPE_*
    ///  - oSaveVersus
    ///  Returns: 0 if the saving throw roll failed
    ///  Returns: 1 if the saving throw roll succeeded
    ///  Returns: 2 if the target was immune to the save type specified
    ///  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
    ///  GetAreaOfEffectCreator() into oSaveVersus!!
    /// </summary>
    public static int ReflexSave(uint oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, uint oSaveVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSaveVersus);
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nDC);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(109);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Does a Will Save check for the given DC
    ///  - oCreature
    ///  - nDC: Difficulty check
    ///  - nSaveType: SAVING_THROW_TYPE_*
    ///  - oSaveVersus
    ///  Returns: 0 if the saving throw roll failed
    ///  Returns: 1 if the saving throw roll succeeded
    ///  Returns: 2 if the target was immune to the save type specified
    ///  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
    ///  GetAreaOfEffectCreator() into oSaveVersus!!
    /// </summary>
    public static int WillSave(uint oCreature, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, uint oSaveVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSaveVersus);
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nDC);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(110);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the DC to save against for a spell (10 + spell level + relevant ability
    ///  bonus).  This can be called by a creature or by an Area of Effect object.
    /// </summary>
    public static int GetSpellSaveDC()
    {
      NWNXPInvoke.CallBuiltIn(111);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the subtype of eEffect to Magical and return eEffect.
    ///  (Effects default to magical if the subtype is not set)
    ///  Magical effects are removed by resting, and by dispel magic
    /// </summary>
    public static IntPtr MagicalEffect(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(112);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set the subtype of eEffect to Supernatural and return eEffect.
    ///  (Effects default to magical if the subtype is not set)
    ///  Permanent supernatural effects are not removed by resting
    /// </summary>
    public static IntPtr SupernaturalEffect(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(113);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set the subtype of eEffect to Extraordinary and return eEffect.
    ///  (Effects default to magical if the subtype is not set)
    ///  Extraordinary effects are removed by resting, but not by dispel magic
    /// </summary>
    public static IntPtr ExtraordinaryEffect(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(114);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an AC Increase effect
    ///  - nValue: size of AC increase
    ///  - nModifyType: AC_*_BONUS
    ///  - nDamageType: DAMAGE_TYPE_*
    ///    * Default value for nDamageType should only ever be used in this function prototype.
    /// </summary>
    public static IntPtr EffectACIncrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nModifyType);
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.CallBuiltIn(115);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  If oObject is a creature, this will return that creature's armour class
    ///  If oObject is an item, door or placeable, this will return zero.
    ///  - nForFutureUse: this parameter is not currently used
    ///  * Return value if oObject is not a creature, item, door or placeable: -1
    /// </summary>
    public static int GetAC(uint oObject, int nForFutureUse = 0)
    {
      NWNXPInvoke.StackPushInteger(nForFutureUse);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(116);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Saving Throw Increase effect
    ///  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
    ///           SAVING_THROW_ALL
    ///           SAVING_THROW_FORT
    ///           SAVING_THROW_REFLEX
    ///           SAVING_THROW_WILL
    ///  - nValue: size of the Saving Throw increase
    ///  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
    /// </summary>
    public static IntPtr EffectSavingThrowIncrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
    {
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushInteger(nSave);
      NWNXPInvoke.CallBuiltIn(117);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an Attack Increase effect
    ///  - nBonus: size of attack bonus
    ///  - nModifierType: ATTACK_BONUS_*
    /// </summary>
    public static IntPtr EffectAttackIncrease(int nBonus, int nModifierType = ATTACK_BONUS_MISC)
    {
      NWNXPInvoke.StackPushInteger(nModifierType);
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.CallBuiltIn(118);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage Reduction effect
    ///  - nAmount: amount of damage reduction
    ///  - nDamagePower: DAMAGE_POWER_*
    ///  - nLimit: How much damage the effect can absorb before disappearing.
    ///    Set to zero for infinite
    /// </summary>
    public static IntPtr EffectDamageReduction(int nAmount, int nDamagePower, int nLimit = 0)
    {
      NWNXPInvoke.StackPushInteger(nLimit);
      NWNXPInvoke.StackPushInteger(nDamagePower);
      NWNXPInvoke.StackPushInteger(nAmount);
      NWNXPInvoke.CallBuiltIn(119);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage Increase effect
    ///  - nBonus: DAMAGE_BONUS_*
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
    ///        result in odd behaviour.
    /// </summary>
    public static IntPtr EffectDamageIncrease(int nBonus, int nDamageType = DAMAGE_TYPE_MAGICAL)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.CallBuiltIn(120);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Convert nRounds into a number of seconds
    ///  A round is always 6.0 seconds
    /// </summary>
    public static float RoundsToSeconds(int nRounds)
    {
      NWNXPInvoke.StackPushInteger(nRounds);
      NWNXPInvoke.CallBuiltIn(121);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Convert nHours into a number of seconds
    ///  The result will depend on how many minutes there are per hour (game-time)
    /// </summary>
    public static float HoursToSeconds(int nHours)
    {
      NWNXPInvoke.StackPushInteger(nHours);
      NWNXPInvoke.CallBuiltIn(122);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Convert nTurns into a number of seconds
    ///  A turn is always 60.0 seconds
    /// </summary>
    public static float TurnsToSeconds(int nTurns)
    {
      NWNXPInvoke.StackPushInteger(nTurns);
      NWNXPInvoke.CallBuiltIn(123);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) to represent oCreature's
    ///  Law/Chaos alignment
    ///  (100=law, 0=chaos)
    ///  * Return value if oCreature is not a valid creature: -1
    /// </summary>
    public static int GetLawChaosValue(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(124);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) to represent oCreature's
    ///  Good/Evil alignment
    ///  (100=good, 0=evil)
    ///  * Return value if oCreature is not a valid creature: -1
    /// </summary>
    public static int GetGoodEvilValue(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(125);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
    ///  * Return value if oCreature is not a valid creature: -1
    /// </summary>
    public static int GetAlignmentLawChaos(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(126);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
    ///  * Return value if oCreature is not a valid creature: -1
    /// </summary>
    public static int GetAlignmentGoodEvil(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(127);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the first object in nShape
    ///  - nShape: SHAPE_*
    ///  - fSize:
    ///    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
    ///    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
    ///       Spell Cylinder's always have a radius of 1.5m.
    ///    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
    ///    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
    ///       direction of lTarget. Spell cones are always 60 degrees with the origin
    ///       at OBJECT_SELF.
    ///    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
    ///       the cube
    ///  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
    ///    or the end of a cylinder or cone.
    ///  - bLineOfSight: This controls whether to do a line-of-sight check on the
    ///    object returned. Line of sight check is done from origin to target object
    ///    at a height 1m above the ground
    ///    (This can be used to ensure that spell effects do not go through walls.)
    ///  - nObjectFilter: This allows you to filter out undesired object types, using
    ///    bitwise "or".
    ///    For example, to return only creatures and doors, the value for this
    ///    parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
    ///  - vOrigin: This is only used for cylinders and cones, and specifies the
    ///    origin of the effect(normally the spell-caster's position).
    ///  Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetFirstObjectInShape(int nShape, float fSize, IntPtr lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, Vector3 vOrigin = default)
    {
      NWNXPInvoke.StackPushVector(vOrigin);
      NWNXPInvoke.StackPushInteger(nObjectFilter);
      NWNXPInvoke.StackPushInteger(bLineOfSight);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
      NWNXPInvoke.StackPushFloat(fSize);
      NWNXPInvoke.StackPushInteger(nShape);
      NWNXPInvoke.CallBuiltIn(128);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next object in nShape
    ///  - nShape: SHAPE_*
    ///  - fSize:
    ///    -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
    ///    -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder.
    ///       Spell Cylinder's always have a radius of 1.5m.
    ///    -> If nShape == SHAPE_CONE, this is the widest radius of the cone
    ///    -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
    ///       direction of lTarget. Spell cones are always 60 degrees with the origin
    ///       at OBJECT_SELF.
    ///    -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
    ///       the cube
    ///  - lTarget: This is the centre of the effect, usually GetSpellTargetLocation(),
    ///    or the end of a cylinder or cone.
    ///  - bLineOfSight: This controls whether to do a line-of-sight check on the
    ///    object returned. (This can be used to ensure that spell effects do not go
    ///    through walls.) Line of sight check is done from origin to target object
    ///    at a height 1m above the ground
    ///  - nObjectFilter: This allows you to filter out undesired object types, using
    ///    bitwise "or". For example, to return only creatures and doors, the value for
    ///    this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
    ///  - vOrigin: This is only used for cylinders and cones, and specifies the origin
    ///    of the effect (normally the spell-caster's position).
    ///  Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNextObjectInShape(int nShape, float fSize, IntPtr lTarget, int bLineOfSight = FALSE, int nObjectFilter = OBJECT_TYPE_CREATURE, Vector3 vOrigin = default)
    {
      NWNXPInvoke.StackPushVector(vOrigin);
      NWNXPInvoke.StackPushInteger(nObjectFilter);
      NWNXPInvoke.StackPushInteger(bLineOfSight);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
      NWNXPInvoke.StackPushFloat(fSize);
      NWNXPInvoke.StackPushInteger(nShape);
      NWNXPInvoke.CallBuiltIn(129);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create an Entangle effect
    ///  When applied, this effect will restrict the creature's movement and apply a
    ///  (-2) to all attacks and a -4 to AC.
    /// </summary>
    public static IntPtr EffectEntangle()
    {
      NWNXPInvoke.CallBuiltIn(130);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Causes object oObject to run the event evToRun. The script on the object that is
    ///  associated with the event specified will run.
    ///  Events can be created using the following event functions:
    ///     EventActivateItem() - This creates an OnActivateItem module event. The script for handling
    ///                           this event can be set in Module Properties on the Event Tab.
    ///     EventConversation() - This creates on OnConversation creature event. The script for handling
    ///                           this event can be set by viewing the Creature Properties on a
    ///                           creature and then clicking on the Scripts Tab.
    ///     EventSpellCastAt()  - This creates an OnSpellCastAt event. The script for handling this
    ///                           event can be set in the Scripts Tab of the Properties menu
    ///                           for the object.
    ///     EventUserDefined()  - This creates on OnUserDefined event. The script for handling this event
    ///                           can be set in the Scripts Tab of the Properties menu for the object/area/module.
    /// </summary>
    public static void SignalEvent(uint oObject, IntPtr evToRun)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EVENT, evToRun);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(131);
    }

    /// <summary>
    ///  Create an event of the type nUserDefinedEventNumber
    ///  Note: This only creates the event. The event wont actually trigger until SignalEvent()
    ///  is called using this created UserDefined event as an argument.
    ///  For example:
    ///      SignalEvent(oObject, EventUserDefined(9999));
    ///  Once the event has been signaled. The script associated with the OnUserDefined event will
    ///  run on the object oObject.
    ///
    ///  To specify the OnUserDefined script that should run, view the object's Properties
    ///  and click on the Scripts Tab. Then specify a script for the OnUserDefined event.
    ///  From inside the OnUserDefined script call:
    ///     GetUserDefinedEventNumber() to retrieve the value of nUserDefinedEventNumber
    ///     that was used when the event was signaled.
    /// </summary>
    public static IntPtr EventUserDefined(int nUserDefinedEventNumber)
    {
      NWNXPInvoke.StackPushInteger(nUserDefinedEventNumber);
      NWNXPInvoke.CallBuiltIn(132);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EVENT);
    }

    /// <summary>
    ///  Create a Death effect
    ///  - nSpectacularDeath: if this is TRUE, the creature to which this effect is
    ///    applied will die in an extraordinary fashion
    ///  - nDisplayFeedback
    /// </summary>
    public static IntPtr EffectDeath(int nSpectacularDeath = FALSE, int nDisplayFeedback = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nDisplayFeedback);
      NWNXPInvoke.StackPushInteger(nSpectacularDeath);
      NWNXPInvoke.CallBuiltIn(133);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Knockdown effect
    ///  This effect knocks creatures off their feet, they will sit until the effect
    ///  is removed. This should be applied as a temporary effect with a 3 second
    ///  duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
    /// </summary>
    public static IntPtr EffectKnockdown()
    {
      NWNXPInvoke.CallBuiltIn(134);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Give oItem to oGiveTo
    ///  If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
    ///  happen.
    /// </summary>
    public static void ActionGiveItem(uint oItem, uint oGiveTo)
    {
      NWNXPInvoke.StackPushObject(oGiveTo);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(135);
    }

    /// <summary>
    ///  Take oItem from oTakeFrom
    ///  If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
    ///  will happen.
    /// </summary>
    public static void ActionTakeItem(uint oItem, uint oTakeFrom)
    {
      NWNXPInvoke.StackPushObject(oTakeFrom);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(136);
    }

    /// <summary>
    ///  Normalize vVector
    /// </summary>
    public static Vector3 VectorNormalize(Vector3 vVector)
    {
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.CallBuiltIn(137);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  Create a Curse effect.
    ///  - nStrMod: strength modifier
    ///  - nDexMod: dexterity modifier
    ///  - nConMod: constitution modifier
    ///  - nIntMod: intelligence modifier
    ///  - nWisMod: wisdom modifier
    ///  - nChaMod: charisma modifier
    /// </summary>
    public static IntPtr EffectCurse(int nStrMod = 1, int nDexMod = 1, int nConMod = 1, int nIntMod = 1, int nWisMod = 1, int nChaMod = 1)
    {
      NWNXPInvoke.StackPushInteger(nChaMod);
      NWNXPInvoke.StackPushInteger(nWisMod);
      NWNXPInvoke.StackPushInteger(nIntMod);
      NWNXPInvoke.StackPushInteger(nConMod);
      NWNXPInvoke.StackPushInteger(nDexMod);
      NWNXPInvoke.StackPushInteger(nStrMod);
      NWNXPInvoke.CallBuiltIn(138);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the ability score of type nAbility for a creature (otherwise 0)
    ///  - oCreature: the creature whose ability score we wish to find out
    ///  - nAbilityType: ABILITY_*
    ///  - nBaseAbilityScore: if set to true will return the base ability score without
    ///                       bonuses (e.g. ability bonuses granted from equipped items).
    ///  Return value on error: 0
    /// </summary>
    public static int GetAbilityScore(uint oCreature, int nAbilityType, int nBaseAbilityScore = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nBaseAbilityScore);
      NWNXPInvoke.StackPushInteger(nAbilityType);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(139);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
    /// </summary>
    public static int GetIsDead(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(140);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Output vVector to the logfile.
    ///  - vVector
    ///  - bPrepend: if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
    /// </summary>
    public static void PrintVector(Vector3 vVector, int bPrepend)
    {
      NWNXPInvoke.StackPushInteger(bPrepend);
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.CallBuiltIn(141);
    }

    /// <summary>
    ///  Create a vector with the specified values for x, y and z
    /// </summary>
    public static Vector3 Vector(float x = 0.0f, float y = 0.0f, float z = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(z);
      NWNXPInvoke.StackPushFloat(y);
      NWNXPInvoke.StackPushFloat(x);
      NWNXPInvoke.CallBuiltIn(142);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  Cause the caller to face vTarget
    /// </summary>
    public static void SetFacingPoint(Vector3 vTarget)
    {
      NWNXPInvoke.StackPushVector(vTarget);
      NWNXPInvoke.CallBuiltIn(143);
    }

    /// <summary>
    ///  Convert fAngle to a vector
    /// </summary>
    public static Vector3 AngleToVector(float fAngle)
    {
      NWNXPInvoke.StackPushFloat(fAngle);
      NWNXPInvoke.CallBuiltIn(144);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  Convert vVector to an angle
    /// </summary>
    public static float VectorToAngle(Vector3 vVector)
    {
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.CallBuiltIn(145);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  The caller will perform a Melee Touch Attack on oTarget
    ///  This is not an action, and it assumes the caller is already within range of
    ///  oTarget
    ///  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
    /// </summary>
    public static int TouchAttackMelee(uint oTarget, int bDisplayFeedback = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bDisplayFeedback);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(146);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The caller will perform a Ranged Touch Attack on oTarget
    ///  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
    /// </summary>
    public static int TouchAttackRanged(uint oTarget, int bDisplayFeedback = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bDisplayFeedback);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(147);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Paralyze effect
    /// </summary>
    public static IntPtr EffectParalyze()
    {
      NWNXPInvoke.CallBuiltIn(148);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Spell Immunity effect.
    ///  There is a known bug with this function. There *must* be a parameter specified
    ///  when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
    ///  otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
    ///  - nImmunityToSpell: SPELL_*
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
    ///    invalid.
    /// </summary>
    public static IntPtr EffectSpellImmunity(int nImmunityToSpell = SPELL_ALL_SPELLS)
    {
      NWNXPInvoke.StackPushInteger(nImmunityToSpell);
      NWNXPInvoke.CallBuiltIn(149);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Deaf effect
    /// </summary>
    public static IntPtr EffectDeaf()
    {
      NWNXPInvoke.CallBuiltIn(150);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the distance in metres between oObjectA and oObjectB.
    ///  * Return value if either object is invalid: 0.0f
    /// </summary>
    public static float GetDistanceBetween(uint oObjectA, uint oObjectB)
    {
      NWNXPInvoke.StackPushObject(oObjectB);
      NWNXPInvoke.StackPushObject(oObjectA);
      NWNXPInvoke.CallBuiltIn(151);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Set oObject's local location variable sVarname to lValue
    /// </summary>
    public static void SetLocalLocation(uint oObject, string sVarName, IntPtr lValue)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lValue);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(152);
    }

    /// <summary>
    ///  Get oObject's local location variable sVarname
    /// </summary>
    public static IntPtr GetLocalLocation(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(153);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  Create a Sleep effect
    /// </summary>
    public static IntPtr EffectSleep()
    {
      NWNXPInvoke.CallBuiltIn(154);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the object which is in oCreature's specified inventory slot
    ///  - nInventorySlot: INVENTORY_SLOT_*
    ///  - oCreature
    ///  * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
    ///    item in nInventorySlot.
    /// </summary>
    public static uint GetItemInSlot(int nInventorySlot, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nInventorySlot);
      NWNXPInvoke.CallBuiltIn(155);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create a Charm effect
    /// </summary>
    public static IntPtr EffectCharmed()
    {
      NWNXPInvoke.CallBuiltIn(156);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Confuse effect
    /// </summary>
    public static IntPtr EffectConfused()
    {
      NWNXPInvoke.CallBuiltIn(157);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Frighten effect
    /// </summary>
    public static IntPtr EffectFrightened()
    {
      NWNXPInvoke.CallBuiltIn(158);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Dominate effect
    /// </summary>
    public static IntPtr EffectDominated()
    {
      NWNXPInvoke.CallBuiltIn(159);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Daze effect
    /// </summary>
    public static IntPtr EffectDazed()
    {
      NWNXPInvoke.CallBuiltIn(160);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Stun effect
    /// </summary>
    public static IntPtr EffectStunned()
    {
      NWNXPInvoke.CallBuiltIn(161);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set whether oTarget's action stack can be modified
    /// </summary>
    public static void SetCommandable(int bCommandable, uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(bCommandable);
      NWNXPInvoke.CallBuiltIn(162);
    }

    /// <summary>
    ///  Determine whether oTarget's action stack can be modified.
    /// </summary>
    public static int GetCommandable(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(163);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Regenerate effect.
    ///  - nAmount: amount of damage to be regenerated per time interval
    ///  - fIntervalSeconds: length of interval in seconds
    /// </summary>
    public static IntPtr EffectRegenerate(int nAmount, float fIntervalSeconds)
    {
      NWNXPInvoke.StackPushFloat(fIntervalSeconds);
      NWNXPInvoke.StackPushInteger(nAmount);
      NWNXPInvoke.CallBuiltIn(164);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Movement Speed Increase effect.
    ///  - nPercentChange - range 0 through 99
    ///  eg.
    ///     0 = no change in speed
    ///    50 = 50% faster
    ///    99 = almost twice as fast
    /// </summary>
    public static IntPtr EffectMovementSpeedIncrease(int nPercentChange)
    {
      NWNXPInvoke.StackPushInteger(nPercentChange);
      NWNXPInvoke.CallBuiltIn(165);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the number of hitdice for oCreature.
    ///  * Return value if oCreature is not a valid creature: 0
    /// </summary>
    public static int GetHitDice(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(166);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The action subject will follow oFollow until a ClearAllActions() is called.
    ///  - oFollow: this is the object to be followed
    ///  - fFollowDistance: follow distance in metres
    ///  * No return value
    /// </summary>
    public static void ActionForceFollowObject(uint oFollow, float fFollowDistance = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fFollowDistance);
      NWNXPInvoke.StackPushObject(oFollow);
      NWNXPInvoke.CallBuiltIn(167);
    }

    /// <summary>
    ///  Get the Tag of oObject
    ///  * Return value if oObject is not a valid object: ""
    /// </summary>
    public static string GetTag(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(168);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
    ///  the spell was resisted.
    ///  * Return value if oCaster or oTarget is an invalid object: FALSE
    ///  * Return value if spell cast is not a player spell: - 1
    ///  * Return value if spell resisted: 1
    ///  * Return value if spell resisted via magic immunity: 2
    ///  * Return value if spell resisted via spell absorption: 3
    /// </summary>
    public static int ResistSpell(uint oCaster, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oCaster);
      NWNXPInvoke.CallBuiltIn(169);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the effect type (EFFECT_TYPE_*) of eEffect.
    ///  * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
    /// </summary>
    public static int GetEffectType(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(170);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create an Area Of Effect effect in the area of the creature it is applied to.
    ///  If the scripts are not specified, default ones will be used.
    /// </summary>
    public static IntPtr EffectAreaOfEffect(int nAreaEffectId, string sOnEnterScript = "", string sHeartbeatScript = "", string sOnExitScript = "")
    {
      NWNXPInvoke.StackPushString(sOnExitScript);
      NWNXPInvoke.StackPushString(sHeartbeatScript);
      NWNXPInvoke.StackPushString(sOnEnterScript);
      NWNXPInvoke.StackPushInteger(nAreaEffectId);
      NWNXPInvoke.CallBuiltIn(171);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  * Returns TRUE if the Faction Ids of the two objects are the same
    /// </summary>
    public static int GetFactionEqual(uint oFirstObject, uint oSecondObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSecondObject);
      NWNXPInvoke.StackPushObject(oFirstObject);
      NWNXPInvoke.CallBuiltIn(172);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
    ///  NB. ** This will only work for two NPCs **
    /// </summary>
    public static void ChangeFaction(uint oObjectToChangeFaction, uint oMemberOfFactionToJoin)
    {
      NWNXPInvoke.StackPushObject(oMemberOfFactionToJoin);
      NWNXPInvoke.StackPushObject(oObjectToChangeFaction);
      NWNXPInvoke.CallBuiltIn(173);
    }

    /// <summary>
    ///  * Returns TRUE if oObject is listening for something
    /// </summary>
    public static int GetIsListening(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(174);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set whether oObject is listening.
    /// </summary>
    public static void SetListening(uint oObject, int bValue)
    {
      NWNXPInvoke.StackPushInteger(bValue);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(175);
    }

    /// <summary>
    ///  Set the string for oObject to listen for.
    ///  Note: this does not set oObject to be listening.
    /// </summary>
    public static void SetListenPattern(uint oObject, string sPattern, int nNumber = 0)
    {
      NWNXPInvoke.StackPushInteger(nNumber);
      NWNXPInvoke.StackPushString(sPattern);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(176);
    }

    /// <summary>
    ///  * Returns TRUE if sStringToTest matches sPattern.
    /// </summary>
    public static int TestStringAgainstPattern(string sPattern, string sStringToTest)
    {
      NWNXPInvoke.StackPushString(sStringToTest);
      NWNXPInvoke.StackPushString(sPattern);
      NWNXPInvoke.CallBuiltIn(177);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the appropriate matched string (this should only be used in
    ///  OnConversation scripts).
    ///  * Returns the appropriate matched string, otherwise returns ""
    /// </summary>
    public static string GetMatchedSubstring(int nString)
    {
      NWNXPInvoke.StackPushInteger(nString);
      NWNXPInvoke.CallBuiltIn(178);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the number of string parameters available.
    ///  * Returns -1 if no string matched (this could be because of a dialogue event)
    /// </summary>
    public static int GetMatchedSubstringsCount()
    {
      NWNXPInvoke.CallBuiltIn(179);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Create a Visual Effect that can be applied to an object.
    ///  - nVisualEffectId
    ///  - nMissEffect: if this is TRUE, a random vector near or past the target will
    ///    be generated, on which to play the effect
    /// </summary>
    public static IntPtr EffectVisualEffect(int nVisualEffectId, int nMissEffect = FALSE, float fScale = 1.0f, Vector3 vTranslate = default, Vector3 vRotate = default)
    {
      NWNXPInvoke.StackPushVector(vRotate);
      NWNXPInvoke.StackPushVector(vTranslate);
      NWNXPInvoke.StackPushFloat(fScale);
      NWNXPInvoke.StackPushInteger(nMissEffect);
      NWNXPInvoke.StackPushInteger(nVisualEffectId);
      NWNXPInvoke.CallBuiltIn(180);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the weakest member of oFactionMember's faction.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionWeakestMember(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(181);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the strongest member of oFactionMember's faction.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionStrongestMember(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(182);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the member of oFactionMember's faction that has taken the most hit points
    ///  of damage.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionMostDamagedMember(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(183);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the member of oFactionMember's faction that has taken the fewest hit
    ///  points of damage.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionLeastDamagedMember(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(184);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the amount of gold held by oFactionMember's faction.
    ///  * Returns -1 if oFactionMember's faction is invalid.
    /// </summary>
    public static int GetFactionGold(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(185);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) that represents how
    ///  oSourceFactionMember's faction feels about oTarget.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionAverageReputation(uint oSourceFactionMember, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oSourceFactionMember);
      NWNXPInvoke.CallBuiltIn(186);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) that represents the average
    ///  good/evil alignment of oFactionMember's faction.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionAverageGoodEvilAlignment(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(187);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) that represents the average
    ///  law/chaos alignment of oFactionMember's faction.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionAverageLawChaosAlignment(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(188);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the average level of the members of the faction.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionAverageLevel(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(189);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the average XP of the members of the faction.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionAverageXP(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(190);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the most frequent class in the faction - this can be compared with the
    ///  constants CLASS_TYPE_*.
    ///  * Return value on error: -1
    /// </summary>
    public static int GetFactionMostFrequentClass(uint oFactionMember)
    {
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(191);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the object faction member with the lowest armour class.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionWorstAC(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(192);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the object faction member with the highest armour class.
    ///  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
    /// </summary>
    public static uint GetFactionBestAC(uint oFactionMember = OBJECT_INVALID, int bMustBeVisible = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bMustBeVisible);
      NWNXPInvoke.StackPushObject(oFactionMember);
      NWNXPInvoke.CallBuiltIn(193);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Sit in oChair.
    ///  Note: Not all creatures will be able to sit and not all
    ///        objects can be sat on.
    ///        The object oChair must also be marked as usable in the toolset.
    ///
    ///  For Example: To get a player to sit in oChair when they click on it,
    ///  place the following script in the OnUsed event for the object oChair.
    ///  void main()
    ///  {
    ///     object oChair = OBJECT_SELF;
    ///     AssignCommand(GetLastUsedBy(),ActionSit(oChair));
    ///  }
    /// </summary>
    public static void ActionSit(uint oChair)
    {
      NWNXPInvoke.StackPushObject(oChair);
      NWNXPInvoke.CallBuiltIn(194);
    }

    /// <summary>
    ///  In an onConversation script this gets the number of the string pattern
    ///  matched (the one that triggered the script).
    ///  * Returns -1 if no string matched
    /// </summary>
    public static int GetListenPatternNumber()
    {
      NWNXPInvoke.CallBuiltIn(195);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Jump to an object ID, or as near to it as possible.
    /// </summary>
    public static void ActionJumpToObject(uint oToJumpTo, int bWalkStraightLineToPoint = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bWalkStraightLineToPoint);
      NWNXPInvoke.StackPushObject(oToJumpTo);
      NWNXPInvoke.CallBuiltIn(196);
    }

    /// <summary>
    ///  Get the first waypoint with the specified tag.
    ///  * Returns OBJECT_INVALID if the waypoint cannot be found.
    /// </summary>
    public static uint GetWaypointByTag(string sWaypointTag)
    {
      NWNXPInvoke.StackPushString(sWaypointTag);
      NWNXPInvoke.CallBuiltIn(197);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the destination object for the given object.
    ///
    ///  All objects can hold a transition target, but only Doors and Triggers
    ///  will be made clickable by the game engine (This may change in the
    ///  future). You can set and query transition targets on other objects for
    ///  your own scripted purposes.
    ///
    ///  * Returns OBJECT_INVALID if oTransition does not hold a target.
    /// </summary>
    public static uint GetTransitionTarget(uint oTransition)
    {
      NWNXPInvoke.StackPushObject(oTransition);
      NWNXPInvoke.CallBuiltIn(198);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Link the two supplied effects, returning eChildEffect as a child of
    ///  eParentEffect.
    ///  Note: When applying linked effects if the target is immune to all valid
    ///  effects all other effects will be removed as well. This means that if you
    ///  apply a visual effect and a silence effect (in a link) and the target is
    ///  immune to the silence effect that the visual effect will get removed as well.
    ///  Visual Effects are not considered "valid" effects for the purposes of
    ///  determining if an effect will be removed or not and as such should never be
    ///  packaged *only* with other visual effects in a link.
    /// </summary>
    public static IntPtr EffectLinkEffects(IntPtr eChildEffect, IntPtr eParentEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eParentEffect);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eChildEffect);
      NWNXPInvoke.CallBuiltIn(199);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the nNth object with the specified tag.
    ///  - sTag
    ///  - nNth: the nth object with this tag may be requested
    ///  * Returns OBJECT_INVALID if the object cannot be found.
    ///  Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
    /// </summary>
    public static uint GetObjectByTag(string sTag, int nNth = 0)
    {
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushString(sTag);
      NWNXPInvoke.CallBuiltIn(200);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Adjust the alignment of oSubject.
    ///  - oSubject
    ///  - nAlignment:
    ///    -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
    ///       alignment will be shifted in the direction specified
    ///    -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
    ///       good/evil alignment values
    ///    -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
    ///       good/evil alignment values in the direction which is towards neutrality.
    ///      e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
    ///           good/evil value of 80 (i.e. good) then if nShift is 15, the
    ///           law/chaos value will become (10+15)=25 and the good/evil value will
    ///           become (80-25)=55
    ///      Furthermore, the shift will at most take the alignment value to 50 and
    ///      not beyond.
    ///      e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
    ///           then if nShift is 15, the law/chaos value will become 50 and the
    ///           good/evil value will become 55
    ///  - nShift: this is the desired shift in alignment
    ///  - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a
    ///                      diminished affect all members of oSubject's party (if oSubject is a Player).
    ///                      When FALSE the shift only affects oSubject.
    ///  * No return value
    /// </summary>
    public static void AdjustAlignment(uint oSubject, int nAlignment, int nShift, int bAllPartyMembers = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bAllPartyMembers);
      NWNXPInvoke.StackPushInteger(nShift);
      NWNXPInvoke.StackPushInteger(nAlignment);
      NWNXPInvoke.StackPushObject(oSubject);
      NWNXPInvoke.CallBuiltIn(201);
    }

    /// <summary>
    ///  Do nothing for fSeconds seconds.
    /// </summary>
    public static void ActionWait(float fSeconds)
    {
      NWNXPInvoke.StackPushFloat(fSeconds);
      NWNXPInvoke.CallBuiltIn(202);
    }

    /// <summary>
    ///  Set the transition bitmap of a player; this should only be called in area
    ///  transition scripts. This action should be run by the person "clicking" the
    ///  area transition via AssignCommand.
    ///  - nPredefinedAreaTransition:
    ///    -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
    ///    -> To use a custom, user-defined area transition bitmap, use
    ///       AREA_TRANSITION_USER_DEFINED and specify the filename in the second
    ///       parameter
    ///  - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined
    ///    area transition bitmap
    /// </summary>
    public static void SetAreaTransitionBMP(int nPredefinedAreaTransition, string sCustomAreaTransitionBMP = "")
    {
      NWNXPInvoke.StackPushString(sCustomAreaTransitionBMP);
      NWNXPInvoke.StackPushInteger(nPredefinedAreaTransition);
      NWNXPInvoke.CallBuiltIn(203);
    }

    /// <summary>
    ///  Starts a conversation with oObjectToConverseWith - this will cause their
    ///  OnDialog event to fire.
    ///  - oObjectToConverseWith
    ///  - sDialogResRef: If this is blank, the creature's own dialogue file will be used
    ///  - bPrivateConversation
    ///  Turn off bPlayHello if you don't want the initial greeting to play
    /// </summary>
    public static void ActionStartConversation(uint oObjectToConverseWith, string sDialogResRef = "", int bPrivateConversation = FALSE, int bPlayHello = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bPlayHello);
      NWNXPInvoke.StackPushInteger(bPrivateConversation);
      NWNXPInvoke.StackPushString(sDialogResRef);
      NWNXPInvoke.StackPushObject(oObjectToConverseWith);
      NWNXPInvoke.CallBuiltIn(204);
    }

    /// <summary>
    ///  Pause the current conversation.
    /// </summary>
    public static void ActionPauseConversation()
    {
      NWNXPInvoke.CallBuiltIn(205);
    }

    /// <summary>
    ///  Resume a conversation after it has been paused.
    /// </summary>
    public static void ActionResumeConversation()
    {
      NWNXPInvoke.CallBuiltIn(206);
    }

    /// <summary>
    ///  Create a Beam effect.
    ///  - nBeamVisualEffect: VFX_BEAM_*
    ///  - oEffector: the beam is emitted from this creature
    ///  - nBodyPart: BODY_NODE_*
    ///  - bMissEffect: If this is TRUE, the beam will fire to a random vector near or
    ///    past the target
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
    ///    not valid.
    /// </summary>
    public static IntPtr EffectBeam(int nBeamVisualEffect, uint oEffector, int nBodyPart, int bMissEffect = FALSE, float fScale = 1.0f, Vector3 vTranslate = default, Vector3 vRotate = default)
    {
      NWNXPInvoke.StackPushVector(vRotate);
      NWNXPInvoke.StackPushVector(vTranslate);
      NWNXPInvoke.StackPushFloat(fScale);
      NWNXPInvoke.StackPushInteger(bMissEffect);
      NWNXPInvoke.StackPushInteger(nBodyPart);
      NWNXPInvoke.StackPushObject(oEffector);
      NWNXPInvoke.StackPushInteger(nBeamVisualEffect);
      NWNXPInvoke.CallBuiltIn(207);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get an integer between 0 and 100 (inclusive) that represents how oSource
    ///  feels about oTarget.
    ///  -> 0-10 means oSource is hostile to oTarget
    ///  -> 11-89 means oSource is neutral to oTarget
    ///  -> 90-100 means oSource is friendly to oTarget
    ///  * Returns -1 if oSource or oTarget does not identify a valid object
    /// </summary>
    public static int GetReputation(uint oSource, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.CallBuiltIn(208);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Adjust how oSourceFactionMember's faction feels about oTarget by the
    ///  specified amount.
    ///  Note: This adjusts Faction Reputation, how the entire faction that
    ///  oSourceFactionMember is in, feels about oTarget.
    ///  * No return value
    ///  Note: You can't adjust a player character's (PC) faction towards
    ///        NPCs, so attempting to make an NPC hostile by passing in a PC object
    ///        as oSourceFactionMember in the following call will fail:
    ///        AdjustReputation(oNPC,oPC,-100);
    ///        Instead you should pass in the PC object as the first
    ///        parameter as in the following call which should succeed:
    ///        AdjustReputation(oPC,oNPC,-100);
    ///  Note: Will fail if oSourceFactionMember is a plot object.
    /// </summary>
    public static void AdjustReputation(uint oTarget, uint oSourceFactionMember, int nAdjustment)
    {
      NWNXPInvoke.StackPushInteger(nAdjustment);
      NWNXPInvoke.StackPushObject(oSourceFactionMember);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(209);
    }

    /// <summary>
    ///  Get the creature that is currently sitting on the specified object.
    ///  - oChair
    ///  * Returns OBJECT_INVALID if oChair is not a valid placeable.
    /// </summary>
    public static uint GetSittingCreature(uint oChair)
    {
      NWNXPInvoke.StackPushObject(oChair);
      NWNXPInvoke.CallBuiltIn(210);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the creature that is going to attack oTarget.
    ///  Note: This value is cleared out at the end of every combat round and should
    ///  not be used in any case except when getting a "going to be attacked" shout
    ///  from the master creature (and this creature is a henchman)
    ///  * Returns OBJECT_INVALID if oTarget is not a valid creature.
    /// </summary>
    public static uint GetGoingToBeAttackedBy(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(211);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create a Spell Resistance Increase effect.
    ///  - nValue: size of spell resistance increase
    /// </summary>
    public static IntPtr EffectSpellResistanceIncrease(int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.CallBuiltIn(212);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the location of oObject.
    /// </summary>
    public static IntPtr GetLocation(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(213);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  The subject will jump to lLocation instantly (even between areas).
    ///  If lLocation is invalid, nothing will happen.
    /// </summary>
    public static void ActionJumpToLocation(IntPtr lLocation)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.CallBuiltIn(214);
    }

    /// <summary>
    ///  Create a location.
    /// </summary>
    public static IntPtr Location(uint oArea, Vector3 vPosition, float fOrientation)
    {
      NWNXPInvoke.StackPushFloat(fOrientation);
      NWNXPInvoke.StackPushVector(vPosition);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(215);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  Apply eEffect at lLocation.
    /// </summary>
    public static void ApplyEffectAtLocation(int nDurationType, IntPtr eEffect, IntPtr lLocation, float fDuration = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fDuration);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.StackPushInteger(nDurationType);
      NWNXPInvoke.CallBuiltIn(216);
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is a Player Controlled character.
    /// </summary>
    public static int GetIsPC(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(217);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Convert fFeet into a number of meters.
    /// </summary>
    public static float FeetToMeters(float fFeet)
    {
      NWNXPInvoke.StackPushFloat(fFeet);
      NWNXPInvoke.CallBuiltIn(218);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Convert fYards into a number of meters.
    /// </summary>
    public static float YardsToMeters(float fYards)
    {
      NWNXPInvoke.StackPushFloat(fYards);
      NWNXPInvoke.CallBuiltIn(219);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Apply eEffect to oTarget.
    /// </summary>
    public static void ApplyEffectToObject(int nDurationType, IntPtr eEffect, uint oTarget, float fDuration = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fDuration);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.StackPushInteger(nDurationType);
      NWNXPInvoke.CallBuiltIn(220);
    }

    /// <summary>
    ///  The caller will immediately speak sStringToSpeak (this is different from
    ///  ActionSpeakString)
    ///  - sStringToSpeak
    ///  - nTalkVolume: TALKVOLUME_*
    /// </summary>
    public static void SpeakString(string sStringToSpeak, int nTalkVolume = TALKVOLUME_TALK)
    {
      NWNXPInvoke.StackPushInteger(nTalkVolume);
      NWNXPInvoke.StackPushString(sStringToSpeak);
      NWNXPInvoke.CallBuiltIn(221);
    }

    /// <summary>
    ///  Get the location of the caller's last spell target.
    /// </summary>
    public static IntPtr GetSpellTargetLocation()
    {
      NWNXPInvoke.CallBuiltIn(222);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  Get the position vector from lLocation.
    /// </summary>
    public static Vector3 GetPositionFromLocation(IntPtr lLocation)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.CallBuiltIn(223);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  Get the area's object ID from lLocation.
    /// </summary>
    public static uint GetAreaFromLocation(IntPtr lLocation)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.CallBuiltIn(224);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the orientation value from lLocation.
    /// </summary>
    public static float GetFacingFromLocation(IntPtr lLocation)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.CallBuiltIn(225);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get the creature nearest to lLocation, subject to all the criteria specified.
    ///  - nFirstCriteriaType: CREATURE_TYPE_*
    ///  - nFirstCriteriaValue:
    ///    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
    ///    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
    ///       or CREATURE_TYPE_HAS_SPELL_EFFECT
    ///    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
    ///    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
    ///    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
    ///       CREATURE_TYPE_PLAYER_CHAR
    ///    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
    ///    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
    ///    For example, to get the nearest PC, use
    ///    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
    ///  - lLocation: We're trying to find the creature of the specified type that is
    ///    nearest to lLocation
    ///  - nNth: We don't have to find the first nearest: we can find the Nth nearest....
    ///  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
    ///    further specify the type of creature that we are looking for.
    ///  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
    ///    to further specify the type of creature that we are looking for.
    ///  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
    ///    further specify the type of creature that we are looking for.
    ///  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
    ///    further specify the type of creature that we are looking for.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, IntPtr lLocation, int nNth = 1, int nSecondCriteriaType = -1, int nSecondCriteriaValue = -1, int nThirdCriteriaType = -1, int nThirdCriteriaValue = -1)
    {
      NWNXPInvoke.StackPushInteger(nThirdCriteriaValue);
      NWNXPInvoke.StackPushInteger(nThirdCriteriaType);
      NWNXPInvoke.StackPushInteger(nSecondCriteriaValue);
      NWNXPInvoke.StackPushInteger(nSecondCriteriaType);
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.StackPushInteger(nFirstCriteriaValue);
      NWNXPInvoke.StackPushInteger(nFirstCriteriaType);
      NWNXPInvoke.CallBuiltIn(226);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the Nth object nearest to oTarget that is of the specified type.
    ///  - nObjectType: OBJECT_TYPE_*
    ///  - oTarget
    ///  - nNth
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNearestObject(int nObjectType = OBJECT_TYPE_ALL, uint oTarget = OBJECT_INVALID, int nNth = 1)
    {
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nObjectType);
      NWNXPInvoke.CallBuiltIn(227);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the nNth object nearest to lLocation that is of the specified type.
    ///  - nObjectType: OBJECT_TYPE_*
    ///  - lLocation
    ///  - nNth
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNearestObjectToLocation(int nObjectType, IntPtr lLocation, int nNth = 1)
    {
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.StackPushInteger(nObjectType);
      NWNXPInvoke.CallBuiltIn(228);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the nth Object nearest to oTarget that has sTag as its tag.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetNearestObjectByTag(string sTag, uint oTarget = OBJECT_INVALID, int nNth = 1)
    {
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushString(sTag);
      NWNXPInvoke.CallBuiltIn(229);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Convert nInteger into a floating point number.
    /// </summary>
    public static float IntToFloat(int nInteger)
    {
      NWNXPInvoke.StackPushInteger(nInteger);
      NWNXPInvoke.CallBuiltIn(230);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Convert fFloat into the nearest integer.
    /// </summary>
    public static int FloatToInt(float fFloat)
    {
      NWNXPInvoke.StackPushFloat(fFloat);
      NWNXPInvoke.CallBuiltIn(231);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Convert sNumber into an integer.
    /// </summary>
    public static int StringToInt(string sNumber)
    {
      NWNXPInvoke.StackPushString(sNumber);
      NWNXPInvoke.CallBuiltIn(232);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Convert sNumber into a floating point number.
    /// </summary>
    public static float StringToFloat(string sNumber)
    {
      NWNXPInvoke.StackPushString(sNumber);
      NWNXPInvoke.CallBuiltIn(233);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Cast spell nSpell at lTargetLocation.
    ///  - nSpell: SPELL_*
    ///  - lTargetLocation
    ///  - nMetaMagic: METAMAGIC_*
    ///  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
    ///    able to cast the spell.
    ///  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
    ///  - bInstantSpell: If this is TRUE, the spell is cast immediately; this allows
    ///    the end-user to simulate
    ///    a high-level magic user having lots of advance warning of impending trouble.
    /// </summary>
    public static void ActionCastSpellAtLocation(int nSpell, IntPtr lTargetLocation, int nMetaMagic = METAMAGIC_ANY, int bCheat = FALSE, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT, int bInstantSpell = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bInstantSpell);
      NWNXPInvoke.StackPushInteger(nProjectilePathType);
      NWNXPInvoke.StackPushInteger(bCheat);
      NWNXPInvoke.StackPushInteger(nMetaMagic);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(234);
    }

    /// <summary>
    ///  * Returns TRUE if oSource considers oTarget as an enemy.
    /// </summary>
    public static int GetIsEnemy(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(235);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if oSource considers oTarget as a friend.
    /// </summary>
    public static int GetIsFriend(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(236);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if oSource considers oTarget as neutral.
    /// </summary>
    public static int GetIsNeutral(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(237);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the PC that is involved in the conversation.
    ///  * Returns OBJECT_INVALID on error.
    /// </summary>
    public static uint GetPCSpeaker()
    {
      NWNXPInvoke.CallBuiltIn(238);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get a string from the talk table using nStrRef.
    /// </summary>
    public static string GetStringByStrRef(int nStrRef, int nGender = GENDER_MALE)
    {
      NWNXPInvoke.StackPushInteger(nGender);
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(239);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Causes the creature to speak a translated string.
    ///  - nStrRef: Reference of the string in the talk table
    ///  - nTalkVolume: TALKVOLUME_*
    /// </summary>
    public static void ActionSpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
    {
      NWNXPInvoke.StackPushInteger(nTalkVolume);
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(240);
    }

    /// <summary>
    ///  Destroy oObject (irrevocably).
    ///  This will not work on modules and areas.
    /// </summary>
    public static void DestroyObject(uint oDestroy, float fDelay = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fDelay);
      NWNXPInvoke.StackPushObject(oDestroy);
      NWNXPInvoke.CallBuiltIn(241);
    }

    /// <summary>
    ///  Get the module.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetModule()
    {
      NWNXPInvoke.CallBuiltIn(242);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create an object of the specified type at lLocation.
    ///  - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
    ///    OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
    ///  - sTemplate
    ///  - lLocation
    ///  - bUseAppearAnimation
    ///  - sNewTag - if this string is not empty, it will replace the default tag from the template
    /// </summary>
    public static uint CreateObject(int nObjectType, string sTemplate, IntPtr lLocation, int bUseAppearAnimation = FALSE, string sNewTag = "")
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushInteger(bUseAppearAnimation);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.StackPushString(sTemplate);
      NWNXPInvoke.StackPushInteger(nObjectType);
      NWNXPInvoke.CallBuiltIn(243);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create an event which triggers the "SpellCastAt" script
    ///  Note: This only creates the event. The event wont actually trigger until SignalEvent()
    ///  is called using this created SpellCastAt event as an argument.
    ///  For example:
    ///      SignalEvent(oCreature, EventSpellCastAt(oCaster, SPELL_MAGIC_MISSILE, TRUE));
    ///  This function doesn't cast the spell specified, it only creates an event so that
    ///  when the event is signaled on an object, the object will use its OnSpellCastAt script
    ///  to react to the spell being cast.
    ///
    ///  To specify the OnSpellCastAt script that should run, view the Object's Properties
    ///  and click on the Scripts Tab. Then specify a script for the OnSpellCastAt event.
    ///  From inside the OnSpellCastAt script call:
    ///      GetLastSpellCaster() to get the object that cast the spell (oCaster).
    ///      GetLastSpell() to get the type of spell cast (nSpell)
    ///      GetLastSpellHarmful() to determine if the spell cast at the object was harmful.
    /// </summary>
    public static IntPtr EventSpellCastAt(uint oCaster, int nSpell, int bHarmful = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bHarmful);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.StackPushObject(oCaster);
      NWNXPInvoke.CallBuiltIn(244);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EVENT);
    }

    /// <summary>
    ///  This is for use in a "Spell Cast" script, it gets who cast the spell.
    ///  The spell could have been cast by a creature, placeable or door.
    ///  * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
    /// </summary>
    public static uint GetLastSpellCaster()
    {
      NWNXPInvoke.CallBuiltIn(245);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  This is for use in a "Spell Cast" script, it gets the ID of the spell that
    ///  was cast.
    /// </summary>
    public static int GetLastSpell()
    {
      NWNXPInvoke.CallBuiltIn(246);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  This is for use in a user-defined script, it gets the event number.
    /// </summary>
    public static int GetUserDefinedEventNumber()
    {
      NWNXPInvoke.CallBuiltIn(247);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  This is for use in a Spell script, it gets the ID of the spell that is being
    ///  cast (SPELL_*).
    /// </summary>
    public static int GetSpellId()
    {
      NWNXPInvoke.CallBuiltIn(248);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Generate a random name.
    ///  nNameType: The type of random name to be generated (NAME_*)
    /// </summary>
    public static string RandomName(int nNameType = NAME_FIRST_GENERIC_MALE)
    {
      NWNXPInvoke.StackPushInteger(nNameType);
      NWNXPInvoke.CallBuiltIn(249);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Create a Poison effect.
    ///  - nPoisonType: POISON_*
    /// </summary>
    public static IntPtr EffectPoison(int nPoisonType)
    {
      NWNXPInvoke.StackPushInteger(nPoisonType);
      NWNXPInvoke.CallBuiltIn(250);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Disease effect.
    ///  - nDiseaseType: DISEASE_*
    /// </summary>
    public static IntPtr EffectDisease(int nDiseaseType)
    {
      NWNXPInvoke.StackPushInteger(nDiseaseType);
      NWNXPInvoke.CallBuiltIn(251);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Silence effect.
    /// </summary>
    public static IntPtr EffectSilence()
    {
      NWNXPInvoke.CallBuiltIn(252);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set the name of oObject.
    ///
    ///  - oObject: the object for which you are changing the name (area, creature, placeable, item, or door).
    ///  - sNewName: the new name that the object will use.
    ///  Note: SetName() does not work on player objects.
    ///        Setting an object's name to "" will make the object
    ///        revert to using the name it had originally before any
    ///        SetName() calls were made on the object.
    /// </summary>
    public static string GetName(uint oObject, int bOriginalName = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bOriginalName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(253);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Use this in a conversation script to get the person with whom you are conversing.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature.
    /// </summary>
    public static uint GetLastSpeaker()
    {
      NWNXPInvoke.CallBuiltIn(254);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnDialog script to start up the dialog tree.
    ///  - sResRef: if this is not specified, the default dialog file will be used
    ///  - oObjectToDialog: if this is not specified the person that triggered the
    ///    event will be used
    /// </summary>
    public static int BeginConversation(string sResRef = "", uint oObjectToDialog = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObjectToDialog);
      NWNXPInvoke.StackPushString(sResRef);
      NWNXPInvoke.CallBuiltIn(255);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnPerception script to get the object that was perceived.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature.
    /// </summary>
    public static uint GetLastPerceived()
    {
      NWNXPInvoke.CallBuiltIn(256);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnPerception script to determine whether the object that was
    ///  perceived was heard.
    /// </summary>
    public static int GetLastPerceptionHeard()
    {
      NWNXPInvoke.CallBuiltIn(257);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnPerception script to determine whether the object that was
    ///  perceived has become inaudible.
    /// </summary>
    public static int GetLastPerceptionInaudible()
    {
      NWNXPInvoke.CallBuiltIn(258);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnPerception script to determine whether the object that was
    ///  perceived was seen.
    /// </summary>
    public static int GetLastPerceptionSeen()
    {
      NWNXPInvoke.CallBuiltIn(259);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnClosed script to get the object that closed the door or placeable.
    ///  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
    /// </summary>
    public static uint GetLastClosedBy()
    {
      NWNXPInvoke.CallBuiltIn(260);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnPerception script to determine whether the object that was
    ///  perceived has vanished.
    /// </summary>
    public static int GetLastPerceptionVanished()
    {
      NWNXPInvoke.CallBuiltIn(261);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the first object within oPersistentObject.
    ///  - oPersistentObject
    ///  - nResidentObjectType: OBJECT_TYPE_*
    ///  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
    ///    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
    ///  * Returns OBJECT_INVALID if no object is found.
    /// </summary>
    public static uint GetFirstInPersistentObject(uint oPersistentObject = OBJECT_INVALID, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
    {
      NWNXPInvoke.StackPushInteger(nPersistentZone);
      NWNXPInvoke.StackPushInteger(nResidentObjectType);
      NWNXPInvoke.StackPushObject(oPersistentObject);
      NWNXPInvoke.CallBuiltIn(262);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next object within oPersistentObject.
    ///  - oPersistentObject
    ///  - nResidentObjectType: OBJECT_TYPE_*
    ///  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
    ///    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
    ///  * Returns OBJECT_INVALID if no object is found.
    /// </summary>
    public static uint GetNextInPersistentObject(uint oPersistentObject = OBJECT_INVALID, int nResidentObjectType = OBJECT_TYPE_CREATURE, int nPersistentZone = PERSISTENT_ZONE_ACTIVE)
    {
      NWNXPInvoke.StackPushInteger(nPersistentZone);
      NWNXPInvoke.StackPushInteger(nResidentObjectType);
      NWNXPInvoke.StackPushObject(oPersistentObject);
      NWNXPInvoke.CallBuiltIn(263);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  This returns the creator of oAreaOfEffectObject.
    ///  * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
    /// </summary>
    public static uint GetAreaOfEffectCreator(uint oAreaOfEffectObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oAreaOfEffectObject);
      NWNXPInvoke.CallBuiltIn(264);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Delete oObject's local integer variable sVarName
    /// </summary>
    public static void DeleteLocalInt(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(265);
    }

    /// <summary>
    ///  Delete oObject's local float variable sVarName
    /// </summary>
    public static void DeleteLocalFloat(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(266);
    }

    /// <summary>
    ///  Delete oObject's local string variable sVarName
    /// </summary>
    public static void DeleteLocalString(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(267);
    }

    /// <summary>
    ///  Delete oObject's local object variable sVarName
    /// </summary>
    public static void DeleteLocalObject(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(268);
    }

    /// <summary>
    ///  Delete oObject's local location variable sVarName
    /// </summary>
    public static void DeleteLocalLocation(uint oObject, string sVarName)
    {
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(269);
    }

    /// <summary>
    ///  Create a Haste effect.
    /// </summary>
    public static IntPtr EffectHaste()
    {
      NWNXPInvoke.CallBuiltIn(270);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Slow effect.
    /// </summary>
    public static IntPtr EffectSlow()
    {
      NWNXPInvoke.CallBuiltIn(271);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Convert oObject into a hexadecimal string.
    /// </summary>
    public static string ObjectToString(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(272);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Create an Immunity effect.
    ///  - nImmunityType: IMMUNITY_TYPE_*
    /// </summary>
    public static IntPtr EffectImmunity(int nImmunityType)
    {
      NWNXPInvoke.StackPushInteger(nImmunityType);
      NWNXPInvoke.CallBuiltIn(273);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  - oCreature
    ///  - nImmunityType: IMMUNITY_TYPE_*
    ///  - oVersus: if this is specified, then we also check for the race and
    ///    alignment of oVersus
    ///  * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
    /// </summary>
    public static int GetIsImmune(uint oCreature, int nImmunityType, uint oVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oVersus);
      NWNXPInvoke.StackPushInteger(nImmunityType);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(274);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Creates a Damage Immunity Increase effect.
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  - nPercentImmunity
    /// </summary>
    public static IntPtr EffectDamageImmunityIncrease(int nDamageType, int nPercentImmunity)
    {
      NWNXPInvoke.StackPushInteger(nPercentImmunity);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(275);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Determine whether oEncounter is active.
    /// </summary>
    public static int GetEncounterActive(uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.CallBuiltIn(276);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set oEncounter's active state to nNewValue.
    ///  - nNewValue: TRUE/FALSE
    ///  - oEncounter
    /// </summary>
    public static void SetEncounterActive(int nNewValue, uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.StackPushInteger(nNewValue);
      NWNXPInvoke.CallBuiltIn(277);
    }

    /// <summary>
    ///  Get the maximum number of times that oEncounter will spawn.
    /// </summary>
    public static int GetEncounterSpawnsMax(uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.CallBuiltIn(278);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the maximum number of times that oEncounter can spawn
    /// </summary>
    public static void SetEncounterSpawnsMax(int nNewValue, uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.StackPushInteger(nNewValue);
      NWNXPInvoke.CallBuiltIn(279);
    }

    /// <summary>
    ///  Get the number of times that oEncounter has spawned so far
    /// </summary>
    public static int GetEncounterSpawnsCurrent(uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.CallBuiltIn(280);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the number of times that oEncounter has spawned so far
    /// </summary>
    public static void SetEncounterSpawnsCurrent(int nNewValue, uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.StackPushInteger(nNewValue);
      NWNXPInvoke.CallBuiltIn(281);
    }

    /// <summary>
    ///  Use this in an OnItemAcquired script to get the item that was acquired.
    ///  * Returns OBJECT_INVALID if the module is not valid.
    /// </summary>
    public static uint GetModuleItemAcquired()
    {
      NWNXPInvoke.CallBuiltIn(282);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemAcquired script to get the creatre that previously
    ///  possessed the item.
    ///  * Returns OBJECT_INVALID if the item was picked up from the ground.
    /// </summary>
    public static uint GetModuleItemAcquiredFrom()
    {
      NWNXPInvoke.CallBuiltIn(283);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Set the value for a custom token.
    /// </summary>
    public static void SetCustomToken(int nCustomTokenNumber, string sTokenValue)
    {
      NWNXPInvoke.StackPushString(sTokenValue);
      NWNXPInvoke.StackPushInteger(nCustomTokenNumber);
      NWNXPInvoke.CallBuiltIn(284);
    }

    /// <summary>
    ///  Determine whether oCreature has nFeat, and nFeat is useable.
    ///  - nFeat: FEAT_*
    ///  - oCreature
    /// </summary>
    public static int GetHasFeat(int nFeat, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.CallBuiltIn(285);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oCreature has nSkill, and nSkill is useable.
    ///  - nSkill: SKILL_*
    ///  - oCreature
    /// </summary>
    public static int GetHasSkill(int nSkill, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(286);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use nFeat on oTarget.
    ///  - nFeat: FEAT_*
    ///  - oTarget
    /// </summary>
    public static void ActionUseFeat(int nFeat, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.CallBuiltIn(287);
    }

    /// <summary>
    ///  Runs the action "UseSkill" on the current creature
    ///  Use nSkill on oTarget.
    ///  - nSkill: SKILL_*
    ///  - oTarget
    ///  - nSubSkill: SUBSKILL_*
    ///  - oItemUsed: Item to use in conjunction with the skill
    /// </summary>
    public static void ActionUseSkill(int nSkill, uint oTarget, int nSubSkill = 0, uint oItemUsed = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oItemUsed);
      NWNXPInvoke.StackPushInteger(nSubSkill);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(288);
    }

    /// <summary>
    ///  Determine whether oSource sees oTarget.
    ///  NOTE: This *only* works on creatures, as visibility lists are not
    ///        maintained for non-creature objects.
    /// </summary>
    public static int GetObjectSeen(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(289);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oSource hears oTarget.
    ///  NOTE: This *only* works on creatures, as visibility lists are not
    ///        maintained for non-creature objects.
    /// </summary>
    public static int GetObjectHeard(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(290);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnPlayerDeath module script to get the last player that died.
    /// </summary>
    public static uint GetLastPlayerDied()
    {
      NWNXPInvoke.CallBuiltIn(291);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemLost script to get the item that was lost/dropped.
    ///  * Returns OBJECT_INVALID if the module is not valid.
    /// </summary>
    public static uint GetModuleItemLost()
    {
      NWNXPInvoke.CallBuiltIn(292);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemLost script to get the creature that lost the item.
    ///  * Returns OBJECT_INVALID if the module is not valid.
    /// </summary>
    public static uint GetModuleItemLostBy()
    {
      NWNXPInvoke.CallBuiltIn(293);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Creates a conversation event.
    ///  Note: This only creates the event. The event wont actually trigger until SignalEvent()
    ///  is called using this created conversation event as an argument.
    ///  For example:
    ///      SignalEvent(oCreature, EventConversation());
    ///  Once the event has been signaled. The script associated with the OnConversation event will
    ///  run on the creature oCreature.
    ///
    ///  To specify the OnConversation script that should run, view the Creature Properties on
    ///  the creature and click on the Scripts Tab. Then specify a script for the OnConversation event.
    /// </summary>
    public static IntPtr EventConversation()
    {
      NWNXPInvoke.CallBuiltIn(295);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EVENT);
    }

    /// <summary>
    ///  Set the difficulty level of oEncounter.
    ///  - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*
    ///  - oEncounter
    /// </summary>
    public static void SetEncounterDifficulty(int nEncounterDifficulty, uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.StackPushInteger(nEncounterDifficulty);
      NWNXPInvoke.CallBuiltIn(296);
    }

    /// <summary>
    ///  Get the difficulty level of oEncounter.
    /// </summary>
    public static int GetEncounterDifficulty(uint oEncounter = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oEncounter);
      NWNXPInvoke.CallBuiltIn(297);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the distance between lLocationA and lLocationB.
    /// </summary>
    public static float GetDistanceBetweenLocations(IntPtr lLocationA, IntPtr lLocationB)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocationB);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocationA);
      NWNXPInvoke.CallBuiltIn(298);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
    ///  evasion saves.
    ///  - nDamage
    ///  - oTarget
    ///  - nDC: Difficulty check
    ///  - nSaveType: SAVING_THROW_TYPE_*
    ///  - oSaveVersus
    /// </summary>
    public static int GetReflexAdjustedDamage(int nDamage, uint oTarget, int nDC, int nSaveType = SAVING_THROW_TYPE_NONE, uint oSaveVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSaveVersus);
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nDC);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.CallBuiltIn(299);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Play nAnimation immediately.
    ///  - nAnimation: ANIMATION_*
    ///  - fSpeed
    ///  - fSeconds
    /// </summary>
    public static void PlayAnimation(int nAnimation, float fSpeed = 1.0f, float fSeconds = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fSeconds);
      NWNXPInvoke.StackPushFloat(fSpeed);
      NWNXPInvoke.StackPushInteger(nAnimation);
      NWNXPInvoke.CallBuiltIn(300);
    }

    /// <summary>
    ///  Create a Spell Talent.
    ///  - nSpell: SPELL_*
    /// </summary>
    public static IntPtr TalentSpell(int nSpell)
    {
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(301);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_TALENT);
    }

    /// <summary>
    ///  Create a Feat Talent.
    ///  - nFeat: FEAT_*
    /// </summary>
    public static IntPtr TalentFeat(int nFeat)
    {
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.CallBuiltIn(302);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_TALENT);
    }

    /// <summary>
    ///  Create a Skill Talent.
    ///  - nSkill: SKILL_*
    /// </summary>
    public static IntPtr TalentSkill(int nSkill)
    {
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(303);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_TALENT);
    }

    /// <summary>
    ///  Determines whether oObject has any effects applied by nSpell
    ///  - nSpell: SPELL_*
    ///  - oObject
    ///  * The spell id on effects is only valid if the effect is created
    ///    when the spell script runs. If it is created in a delayed command
    ///    then the spell id on the effect will be invalid.
    /// </summary>
    public static int GetHasSpellEffect(int nSpell, uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(304);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the spell (SPELL_*) that applied eSpellEffect.
    ///  * Returns -1 if eSpellEffect was applied outside a spell script.
    /// </summary>
    public static int GetEffectSpellId(IntPtr eSpellEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eSpellEffect);
      NWNXPInvoke.CallBuiltIn(305);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oCreature has tTalent.
    /// </summary>
    public static int GetCreatureHasTalent(IntPtr tTalent, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tTalent);
      NWNXPInvoke.CallBuiltIn(306);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get a random talent of oCreature, within nCategory.
    ///  - nCategory: TALENT_CATEGORY_*
    ///  - oCreature
    /// </summary>
    public static IntPtr GetCreatureTalentRandom(int nCategory, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nCategory);
      NWNXPInvoke.CallBuiltIn(307);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_TALENT);
    }

    /// <summary>
    ///  Get the best talent (i.e. closest to nCRMax without going over) of oCreature,
    ///  within nCategory.
    ///  - nCategory: TALENT_CATEGORY_*
    ///  - nCRMax: Challenge Rating of the talent
    ///  - oCreature
    /// </summary>
    public static IntPtr GetCreatureTalentBest(int nCategory, int nCRMax, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nCRMax);
      NWNXPInvoke.StackPushInteger(nCategory);
      NWNXPInvoke.CallBuiltIn(308);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_TALENT);
    }

    /// <summary>
    ///  Use tChosenTalent on oTarget.
    /// </summary>
    public static void ActionUseTalentOnObject(IntPtr tChosenTalent, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tChosenTalent);
      NWNXPInvoke.CallBuiltIn(309);
    }

    /// <summary>
    ///  Use tChosenTalent at lTargetLocation.
    /// </summary>
    public static void ActionUseTalentAtLocation(IntPtr tChosenTalent, IntPtr lTargetLocation)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTargetLocation);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tChosenTalent);
      NWNXPInvoke.CallBuiltIn(310);
    }

    /// <summary>
    ///  Get the gold piece value of oItem.
    ///  * Returns 0 if oItem is not a valid item.
    /// </summary>
    public static int GetGoldPieceValue(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(311);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is of a playable racial type.
    /// </summary>
    public static int GetIsPlayableRacialType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(312);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Jump to lDestination.  The action is added to the TOP of the action queue.
    /// </summary>
    public static void JumpToLocation(IntPtr lDestination)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
      NWNXPInvoke.CallBuiltIn(313);
    }

    /// <summary>
    ///  Create a Temporary Hitpoints effect.
    ///  - nHitPoints: a positive integer
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
    /// </summary>
    public static IntPtr EffectTemporaryHitpoints(int nHitPoints)
    {
      NWNXPInvoke.StackPushInteger(nHitPoints);
      NWNXPInvoke.CallBuiltIn(314);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the number of ranks that oTarget has in nSkill.
    ///  - nSkill: SKILL_*
    ///  - oTarget
    ///  - nBaseSkillRank: if set to true returns the number of base skill ranks the target
    ///                    has (i.e. not including any bonuses from ability scores, feats, etc).
    ///  * Returns -1 if oTarget doesn't have nSkill.
    ///  * Returns 0 if nSkill is untrained.
    /// </summary>
    public static int GetSkillRank(int nSkill, uint oTarget = OBJECT_INVALID, int nBaseSkillRank = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nBaseSkillRank);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(315);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the attack target of oCreature.
    ///  This only works when oCreature is in combat.
    /// </summary>
    public static uint GetAttackTarget(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(316);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
    ///  This only works when oCreature is in combat.
    /// </summary>
    public static int GetLastAttackType(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(317);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
    ///  This only works when oCreature is in combat.
    /// </summary>
    public static int GetLastAttackMode(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(318);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the master of oAssociate.
    /// </summary>
    public static uint GetMaster(uint oAssociate = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oAssociate);
      NWNXPInvoke.CallBuiltIn(319);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is in combat.
    /// </summary>
    public static int GetIsInCombat(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(320);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
    /// </summary>
    public static int GetLastAssociateCommand(uint oAssociate = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oAssociate);
      NWNXPInvoke.CallBuiltIn(321);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Give nGP gold to oCreature.
    /// </summary>
    public static void GiveGoldToCreature(uint oCreature, int nGP)
    {
      NWNXPInvoke.StackPushInteger(nGP);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(322);
    }

    /// <summary>
    ///  Set the destroyable status of the caller.
    ///  - bDestroyable: If this is FALSE, the caller does not fade out on death, but
    ///    sticks around as a corpse.
    ///  - bRaiseable: If this is TRUE, the caller can be raised via resurrection.
    ///  - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.
    /// </summary>
    public static void SetIsDestroyable(int bDestroyable, int bRaiseable = TRUE, int bSelectableWhenDead = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bSelectableWhenDead);
      NWNXPInvoke.StackPushInteger(bRaiseable);
      NWNXPInvoke.StackPushInteger(bDestroyable);
      NWNXPInvoke.CallBuiltIn(323);
    }

    /// <summary>
    ///  Set the locked state of oTarget, which can be a door or a placeable object.
    /// </summary>
    public static void SetLocked(uint oTarget, int bLocked)
    {
      NWNXPInvoke.StackPushInteger(bLocked);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(324);
    }

    /// <summary>
    ///  Get the locked state of oTarget, which can be a door or a placeable object.
    /// </summary>
    public static int GetLocked(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(325);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in a trigger's OnClick event script to get the object that last
    ///  clicked on it.
    ///  This is identical to GetEnteringObject.
    ///  GetClickingObject() should not be called from a placeable's OnClick event,
    ///  instead use GetPlaceableLastClickedBy();
    /// </summary>
    public static uint GetClickingObject()
    {
      NWNXPInvoke.CallBuiltIn(326);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Initialise oTarget to listen for the standard Associates commands.
    /// </summary>
    public static void SetAssociateListenPatterns(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(327);
    }

    /// <summary>
    ///  Get the last weapon that oCreature used in an attack.
    ///  * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
    /// </summary>
    public static uint GetLastWeaponUsed(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(328);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use oPlaceable.
    /// </summary>
    public static void ActionInteractObject(uint oPlaceable)
    {
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(329);
    }

    /// <summary>
    ///  Get the last object that used the placeable object that is calling this function.
    ///  * Returns OBJECT_INVALID if it is called by something other than a placeable or
    ///    a door.
    /// </summary>
    public static uint GetLastUsedBy()
    {
      NWNXPInvoke.CallBuiltIn(330);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Returns the ability modifier for the specified ability
    ///  Get oCreature's ability modifier for nAbility.
    ///  - nAbility: ABILITY_*
    ///  - oCreature
    /// </summary>
    public static int GetAbilityModifier(int nAbility, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nAbility);
      NWNXPInvoke.CallBuiltIn(331);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determined whether oItem has been identified.
    /// </summary>
    public static int GetIdentified(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(332);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set whether oItem has been identified.
    /// </summary>
    public static void SetIdentified(uint oItem, int bIdentified)
    {
      NWNXPInvoke.StackPushInteger(bIdentified);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(333);
    }

    /// <summary>
    ///  Summon an Animal Companion
    /// </summary>
    public static void SummonAnimalCompanion(uint oMaster = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(334);
    }

    /// <summary>
    ///  Summon a Familiar
    /// </summary>
    public static void SummonFamiliar(uint oMaster = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(335);
    }

    /// <summary>
    ///  Get the last blocking door encountered by the caller of this function.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature.
    /// </summary>
    public static uint GetBlockingDoor()
    {
      NWNXPInvoke.CallBuiltIn(336);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  - oTargetDoor
    ///  - nDoorAction: DOOR_ACTION_*
    ///  * Returns TRUE if nDoorAction can be performed on oTargetDoor.
    /// </summary>
    public static int GetIsDoorActionPossible(uint oTargetDoor, int nDoorAction)
    {
      NWNXPInvoke.StackPushInteger(nDoorAction);
      NWNXPInvoke.StackPushObject(oTargetDoor);
      NWNXPInvoke.CallBuiltIn(337);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Perform nDoorAction on oTargetDoor.
    /// </summary>
    public static void DoDoorAction(uint oTargetDoor, int nDoorAction)
    {
      NWNXPInvoke.StackPushInteger(nDoorAction);
      NWNXPInvoke.StackPushObject(oTargetDoor);
      NWNXPInvoke.CallBuiltIn(338);
    }

    /// <summary>
    ///  Get the first item in oTarget's inventory (start to cycle through oTarget's
    ///  inventory).
    ///  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
    ///    or if no item is found.
    /// </summary>
    public static uint GetFirstItemInInventory(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(339);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next item in oTarget's inventory (continue to cycle through oTarget's
    ///  inventory).
    ///  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
    ///    or if no item is found.
    /// </summary>
    public static uint GetNextItemInInventory(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(340);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  A creature can have up to three classes.  This function determines the
    ///  creature's class (CLASS_TYPE_*) based on nClassPosition.
    ///  - nClassPosition: 1, 2 or 3
    ///  - oCreature
    ///  * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
    ///    nClassPosition (i.e. a single-class creature will only have a value in
    ///    nClassLocation=1) or if oCreature is not a valid creature.
    /// </summary>
    public static int GetClassByPosition(int nClassPosition, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nClassPosition);
      NWNXPInvoke.CallBuiltIn(341);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  A creature can have up to three classes.  This function determines the
    ///  creature's class level based on nClass Position.
    ///  - nClassPosition: 1, 2 or 3
    ///  - oCreature
    ///  * Returns 0 if oCreature does not have a class in nClassPosition
    ///    (i.e. a single-class creature will only have a value in nClassLocation=1)
    ///    or if oCreature is not a valid creature.
    /// </summary>
    public static int GetLevelByPosition(int nClassPosition, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nClassPosition);
      NWNXPInvoke.CallBuiltIn(342);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine the levels that oCreature holds in nClassType.
    ///  - nClassType: CLASS_TYPE_*
    ///  - oCreature
    /// </summary>
    public static int GetLevelByClass(int nClassType, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nClassType);
      NWNXPInvoke.CallBuiltIn(343);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the amount of damage of type nDamageType that has been dealt to the caller.
    ///  - nDamageType: DAMAGE_TYPE_*
    /// </summary>
    public static int GetDamageDealtByType(int nDamageType)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(344);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the total amount of damage that has been dealt to the caller.
    /// </summary>
    public static int GetTotalDamageDealt()
    {
      NWNXPInvoke.CallBuiltIn(345);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the last object that damaged oObject
    ///  * Returns OBJECT_INVALID if the passed in object is not a valid object.
    /// </summary>
    public static uint GetLastDamager(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(346);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last object that disarmed the trap on the caller.
    ///  * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
    ///    door.
    /// </summary>
    public static uint GetLastDisarmed()
    {
      NWNXPInvoke.CallBuiltIn(347);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last object that disturbed the inventory of the caller.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
    /// </summary>
    public static uint GetLastDisturbed()
    {
      NWNXPInvoke.CallBuiltIn(348);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last object that locked the caller.
    ///  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
    /// </summary>
    public static uint GetLastLocked()
    {
      NWNXPInvoke.CallBuiltIn(349);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last object that unlocked the caller.
    ///  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
    /// </summary>
    public static uint GetLastUnlocked()
    {
      NWNXPInvoke.CallBuiltIn(350);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create a Skill Increase effect.
    ///  - nSkill: SKILL_*
    ///  - nValue
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
    /// </summary>
    public static IntPtr EffectSkillIncrease(int nSkill, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(351);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
    ///  OnInventoryDisturbed script to fire.  This will only work for creatures and
    ///  placeables.
    /// </summary>
    public static int GetInventoryDisturbType()
    {
      NWNXPInvoke.CallBuiltIn(352);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  get the item that caused the caller's OnInventoryDisturbed script to fire.
    ///  * Returns OBJECT_INVALID if the caller is not a valid object.
    /// </summary>
    public static uint GetInventoryDisturbItem()
    {
      NWNXPInvoke.CallBuiltIn(353);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the henchman belonging to oMaster.
    ///  * Return OBJECT_INVALID if oMaster does not have a henchman.
    ///  -nNth: Which henchman to return.
    /// </summary>
    public static uint GetHenchman(uint oMaster = OBJECT_INVALID, int nNth = 1)
    {
      NWNXPInvoke.StackPushInteger(nNth);
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(354);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Set eEffect to be versus a specific alignment.
    ///  - eEffect
    ///  - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
    ///  - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
    /// </summary>
    public static IntPtr VersusAlignmentEffect(IntPtr eEffect, int nLawChaos = ALIGNMENT_ALL, int nGoodEvil = ALIGNMENT_ALL)
    {
      NWNXPInvoke.StackPushInteger(nGoodEvil);
      NWNXPInvoke.StackPushInteger(nLawChaos);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(355);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set eEffect to be versus nRacialType.
    ///  - eEffect
    ///  - nRacialType: RACIAL_TYPE_*
    /// </summary>
    public static IntPtr VersusRacialTypeEffect(IntPtr eEffect, int nRacialType)
    {
      NWNXPInvoke.StackPushInteger(nRacialType);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(356);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Set eEffect to be versus traps.
    /// </summary>
    public static IntPtr VersusTrapEffect(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(357);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the gender of oCreature.
    /// </summary>
    public static int GetGender(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(358);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if tTalent is valid.
    /// </summary>
    public static int GetIsTalentValid(IntPtr tTalent)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tTalent);
      NWNXPInvoke.CallBuiltIn(359);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Causes the action subject to move away from lMoveAwayFrom.
    /// </summary>
    public static void ActionMoveAwayFromLocation(IntPtr lMoveAwayFrom, int bRun = FALSE, float fMoveAwayRange = 40.0f)
    {
      NWNXPInvoke.StackPushFloat(fMoveAwayRange);
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lMoveAwayFrom);
      NWNXPInvoke.CallBuiltIn(360);
    }

    /// <summary>
    ///  Get the target that the caller attempted to attack - this should be used in
    ///  conjunction with GetAttackTarget(). This value is set every time an attack is
    ///  made, and is reset at the end of combat.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature.
    /// </summary>
    public static uint GetAttemptedAttackTarget()
    {
      NWNXPInvoke.CallBuiltIn(361);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the type (TALENT_TYPE_*) of tTalent.
    /// </summary>
    public static int GetTypeFromTalent(IntPtr tTalent)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tTalent);
      NWNXPInvoke.CallBuiltIn(362);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the ID of tTalent.  This could be a SPELL_*, FEAT_* or SKILL_*.
    /// </summary>
    public static int GetIdFromTalent(IntPtr tTalent)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_TALENT, tTalent);
      NWNXPInvoke.CallBuiltIn(363);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the associate of type nAssociateType belonging to oMaster.
    ///  - nAssociateType: ASSOCIATE_TYPE_*
    ///  - nMaster
    ///  - nTh: Which associate of the specified type to return
    ///  * Returns OBJECT_INVALID if no such associate exists.
    /// </summary>
    public static uint GetAssociate(int nAssociateType, uint oMaster = OBJECT_INVALID, int nTh = 1)
    {
      NWNXPInvoke.StackPushInteger(nTh);
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.StackPushInteger(nAssociateType);
      NWNXPInvoke.CallBuiltIn(364);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Add oHenchman as a henchman to oMaster
    ///  If oHenchman is either a DM or a player character, this will have no effect.
    /// </summary>
    public static void AddHenchman(uint oMaster, uint oHenchman = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oHenchman);
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(365);
    }

    /// <summary>
    ///  Remove oHenchman from the service of oMaster, returning them to their original faction.
    /// </summary>
    public static void RemoveHenchman(uint oMaster, uint oHenchman = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oHenchman);
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(366);
    }

    /// <summary>
    ///  Add a journal quest entry to oCreature.
    ///  - szPlotID: the plot identifier used in the toolset's Journal Editor
    ///  - nState: the state of the plot as seen in the toolset's Journal Editor
    ///  - oCreature
    ///  - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of
    ///    everyone in the party
    ///  - bAllPlayers: If this is TRUE, the entry will show up in the journal of
    ///    everyone in the world
    ///  - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower
    ///    number than the one it is currently on
    /// </summary>
    public static void AddJournalQuestEntry(string szPlotID, int nState, uint oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE, int bAllowOverrideHigher = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bAllowOverrideHigher);
      NWNXPInvoke.StackPushInteger(bAllPlayers);
      NWNXPInvoke.StackPushInteger(bAllPartyMembers);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nState);
      NWNXPInvoke.StackPushString(szPlotID);
      NWNXPInvoke.CallBuiltIn(367);
    }

    /// <summary>
    ///  Remove a journal quest entry from oCreature.
    ///  - szPlotID: the plot identifier used in the toolset's Journal Editor
    ///  - oCreature
    ///  - bAllPartyMembers: If this is TRUE, the entry will be removed from the
    ///    journal of everyone in the party
    ///  - bAllPlayers: If this is TRUE, the entry will be removed from the journal of
    ///    everyone in the world
    /// </summary>
    public static void RemoveJournalQuestEntry(string szPlotID, uint oCreature, int bAllPartyMembers = TRUE, int bAllPlayers = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bAllPlayers);
      NWNXPInvoke.StackPushInteger(bAllPartyMembers);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushString(szPlotID);
      NWNXPInvoke.CallBuiltIn(368);
    }

    /// <summary>
    ///  Get the public part of the CD Key that oPlayer used when logging in.
    ///  - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will
    ///    be returned when the player is playing in single player mode
    ///    (otherwise returns an empty string in single player mode).
    /// </summary>
    public static string GetPCPublicCDKey(uint oPlayer, int nSinglePlayerCDKey = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nSinglePlayerCDKey);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(369);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the IP address from which oPlayer has connected.
    /// </summary>
    public static string GetPCIPAddress(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(370);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the name of oPlayer.
    /// </summary>
    public static string GetPCPlayerName(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(371);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Sets oPlayer and oTarget to like each other.
    /// </summary>
    public static void SetPCLike(uint oPlayer, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(372);
    }

    /// <summary>
    ///  Sets oPlayer and oTarget to dislike each other.
    /// </summary>
    public static void SetPCDislike(uint oPlayer, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(373);
    }

    /// <summary>
    ///  Send a server message (szMessage) to the oPlayer.
    /// </summary>
    public static void SendMessageToPC(uint oPlayer, string szMessage)
    {
      NWNXPInvoke.StackPushString(szMessage);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(374);
    }

    /// <summary>
    ///  Get the target at which the caller attempted to cast a spell.
    ///  This value is set every time a spell is cast and is reset at the end of
    ///  combat.
    ///  * Returns OBJECT_INVALID if the caller is not a valid creature.
    /// </summary>
    public static uint GetAttemptedSpellTarget()
    {
      NWNXPInvoke.CallBuiltIn(375);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last creature that opened the caller.
    ///  * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
    /// </summary>
    public static uint GetLastOpenedBy()
    {
      NWNXPInvoke.CallBuiltIn(376);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Determines the number of times that oCreature has nSpell memorised.
    ///  - nSpell: SPELL_*
    ///  - oCreature
    /// </summary>
    public static int GetHasSpell(int nSpell, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(377);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Open oStore for oPC.
    ///  - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
    ///  - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
    /// </summary>
    public static void OpenStore(uint oStore, uint oPC, int nBonusMarkUp = 0, int nBonusMarkDown = 0)
    {
      NWNXPInvoke.StackPushInteger(nBonusMarkDown);
      NWNXPInvoke.StackPushInteger(nBonusMarkUp);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.StackPushObject(oStore);
      NWNXPInvoke.CallBuiltIn(378);
    }

    /// <summary>
    ///  Create a Turned effect.
    ///  Turned effects are supernatural by default.
    /// </summary>
    public static IntPtr EffectTurned()
    {
      NWNXPInvoke.CallBuiltIn(379);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the first member of oMemberOfFaction's faction (start to cycle through
    ///  oMemberOfFaction's faction).
    ///  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
    /// </summary>
    public static uint GetFirstFactionMember(uint oMemberOfFaction, int bPCOnly = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bPCOnly);
      NWNXPInvoke.StackPushObject(oMemberOfFaction);
      NWNXPInvoke.CallBuiltIn(380);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next member of oMemberOfFaction's faction (continue to cycle through
    ///  oMemberOfFaction's faction).
    ///  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
    /// </summary>
    public static uint GetNextFactionMember(uint oMemberOfFaction, int bPCOnly = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bPCOnly);
      NWNXPInvoke.StackPushObject(oMemberOfFaction);
      NWNXPInvoke.CallBuiltIn(381);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Force the action subject to move to lDestination.
    /// </summary>
    public static void ActionForceMoveToLocation(IntPtr lDestination, int bRun = FALSE, float fTimeout = 30.0f)
    {
      NWNXPInvoke.StackPushFloat(fTimeout);
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lDestination);
      NWNXPInvoke.CallBuiltIn(382);
    }

    /// <summary>
    ///  Force the action subject to move to oMoveTo.
    /// </summary>
    public static void ActionForceMoveToObject(uint oMoveTo, int bRun = FALSE, float fRange = 1.0f, float fTimeout = 30.0f)
    {
      NWNXPInvoke.StackPushFloat(fTimeout);
      NWNXPInvoke.StackPushFloat(fRange);
      NWNXPInvoke.StackPushInteger(bRun);
      NWNXPInvoke.StackPushObject(oMoveTo);
      NWNXPInvoke.CallBuiltIn(383);
    }

    /// <summary>
    ///  Get the experience assigned in the journal editor for szPlotID.
    /// </summary>
    public static int GetJournalQuestExperience(string szPlotID)
    {
      NWNXPInvoke.StackPushString(szPlotID);
      NWNXPInvoke.CallBuiltIn(384);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Jump to oToJumpTo (the action is added to the top of the action queue).
    /// </summary>
    public static void JumpToObject(uint oToJumpTo, int nWalkStraightLineToPoint = 1)
    {
      NWNXPInvoke.StackPushInteger(nWalkStraightLineToPoint);
      NWNXPInvoke.StackPushObject(oToJumpTo);
      NWNXPInvoke.CallBuiltIn(385);
    }

    /// <summary>
    ///  Set whether oMapPin is enabled.
    ///  - oMapPin
    ///  - nEnabled: 0=Off, 1=On
    /// </summary>
    public static void SetMapPinEnabled(uint oMapPin, int nEnabled)
    {
      NWNXPInvoke.StackPushInteger(nEnabled);
      NWNXPInvoke.StackPushObject(oMapPin);
      NWNXPInvoke.CallBuiltIn(386);
    }

    /// <summary>
    ///  Create a Hit Point Change When Dying effect.
    ///  - fHitPointChangePerRound: this can be positive or negative, but not zero.
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
    /// </summary>
    public static IntPtr EffectHitPointChangeWhenDying(float fHitPointChangePerRound)
    {
      NWNXPInvoke.StackPushFloat(fHitPointChangePerRound);
      NWNXPInvoke.CallBuiltIn(387);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Spawn a GUI panel for the client that controls oPC.
    ///  - oPC
    ///  - nGUIPanel: GUI_PANEL_*
    ///  * Nothing happens if oPC is not a player character or if an invalid value is
    ///    used for nGUIPanel.
    /// </summary>
    public static void PopUpGUIPanel(uint oPC, int nGUIPanel)
    {
      NWNXPInvoke.StackPushInteger(nGUIPanel);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(388);
    }

    /// <summary>
    ///  Clear all personal feelings that oSource has about oTarget.
    /// </summary>
    public static void ClearPersonalReputation(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(389);
    }

    /// <summary>
    ///  oSource will temporarily be friends towards oTarget.
    ///  bDecays determines whether the personal reputation value decays over time
    ///  fDurationInSeconds is the length of time that the temporary friendship lasts
    ///  Make oSource into a temporary friend of oTarget using personal reputation.
    ///  - oTarget
    ///  - oSource
    ///  - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds;
    ///    otherwise it is indefinite.
    ///  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
    ///    the friendship lasts.
    ///  Note: If bDecays is TRUE, the personal reputation amount decreases in size
    ///  over fDurationInSeconds. Friendship will only be in effect as long as
    ///  (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
    /// </summary>
    public static void SetIsTemporaryFriend(uint oTarget, uint oSource = OBJECT_INVALID, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
    {
      NWNXPInvoke.StackPushFloat(fDurationInSeconds);
      NWNXPInvoke.StackPushInteger(bDecays);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(390);
    }

    /// <summary>
    ///  Make oSource into a temporary enemy of oTarget using personal reputation.
    ///  - oTarget
    ///  - oSource
    ///  - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds;
    ///    otherwise it is indefinite.
    ///  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
    ///    the enmity lasts.
    ///  Note: If bDecays is TRUE, the personal reputation amount decreases in size
    ///  over fDurationInSeconds. Enmity will only be in effect as long as
    ///  (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
    /// </summary>
    public static void SetIsTemporaryEnemy(uint oTarget, uint oSource = OBJECT_INVALID, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
    {
      NWNXPInvoke.StackPushFloat(fDurationInSeconds);
      NWNXPInvoke.StackPushInteger(bDecays);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(391);
    }

    /// <summary>
    ///  Make oSource temporarily neutral to oTarget using personal reputation.
    ///  - oTarget
    ///  - oSource
    ///  - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds;
    ///    otherwise it is indefinite.
    ///  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
    ///    the neutrality lasts.
    ///  Note: If bDecays is TRUE, the personal reputation amount decreases in size
    ///  over fDurationInSeconds. Neutrality will only be in effect as long as
    ///  (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
    ///  (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
    /// </summary>
    public static void SetIsTemporaryNeutral(uint oTarget, uint oSource = OBJECT_INVALID, int bDecays = FALSE, float fDurationInSeconds = 180.0f)
    {
      NWNXPInvoke.StackPushFloat(fDurationInSeconds);
      NWNXPInvoke.StackPushInteger(bDecays);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(392);
    }

    /// <summary>
    ///  Gives nXpAmount to oCreature.
    /// </summary>
    public static void GiveXPToCreature(uint oCreature, int nXpAmount)
    {
      NWNXPInvoke.StackPushInteger(nXpAmount);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(393);
    }

    /// <summary>
    ///  Sets oCreature's experience to nXpAmount.
    /// </summary>
    public static void SetXP(uint oCreature, int nXpAmount)
    {
      NWNXPInvoke.StackPushInteger(nXpAmount);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(394);
    }

    /// <summary>
    ///  Get oCreature's experience.
    /// </summary>
    public static int GetXP(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(395);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Convert nInteger to hex, returning the hex value as a string.
    ///  * Return value has the format "0x????????" where each ? will be a hex digit
    ///    (8 digits in total).
    /// </summary>
    public static string IntToHexString(int nInteger)
    {
      NWNXPInvoke.StackPushInteger(nInteger);
      NWNXPInvoke.CallBuiltIn(396);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the base item type (BASE_ITEM_*) of oItem.
    ///  * Returns BASE_ITEM_INVALID if oItem is an invalid item.
    /// </summary>
    public static int GetBaseItemType(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(397);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determines whether oItem has nProperty.
    ///  - oItem
    ///  - nProperty: ITEM_PROPERTY_*
    ///  * Returns FALSE if oItem is not a valid item, or if oItem does not have
    ///    nProperty.
    /// </summary>
    public static int GetItemHasItemProperty(uint oItem, int nProperty)
    {
      NWNXPInvoke.StackPushInteger(nProperty);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(398);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The creature will equip the melee weapon in its possession that can do the
    ///  most damage. If no valid melee weapon is found, it will equip the most
    ///  damaging range weapon. This function should only ever be called in the
    ///  EndOfCombatRound scripts, because otherwise it would have to stop the combat
    ///  round to run simulation.
    ///  - oVersus: You can try to get the most damaging weapon against oVersus
    ///  - bOffHand
    /// </summary>
    public static void ActionEquipMostDamagingMelee(uint oVersus = OBJECT_INVALID, int bOffHand = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bOffHand);
      NWNXPInvoke.StackPushObject(oVersus);
      NWNXPInvoke.CallBuiltIn(399);
    }

    /// <summary>
    ///  The creature will equip the range weapon in its possession that can do the
    ///  most damage.
    ///  If no valid range weapon can be found, it will equip the most damaging melee
    ///  weapon.
    ///  - oVersus: You can try to get the most damaging weapon against oVersus
    /// </summary>
    public static void ActionEquipMostDamagingRanged(uint oVersus = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oVersus);
      NWNXPInvoke.CallBuiltIn(400);
    }

    /// <summary>
    ///  Get the Armour Class of oItem.
    ///  * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
    /// </summary>
    public static int GetItemACValue(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(401);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The creature will rest if not in combat and no enemies are nearby.
    ///  - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies
    ///                                      are nearby, but the creature can't see the enemy.
    ///                                      FALSE the creature will not rest if enemies are
    ///                                      nearby regardless of whether or not the creature
    ///                                      can see them, such as if an enemy is close by,
    ///                                      but is in a different room behind a closed door.
    /// </summary>
    public static void ActionRest(int bCreatureToEnemyLineOfSightCheck = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bCreatureToEnemyLineOfSightCheck);
      NWNXPInvoke.CallBuiltIn(402);
    }

    /// <summary>
    ///  Expose/Hide the entire map of oArea for oPlayer.
    ///  - oArea: The area that the map will be exposed/hidden for.
    ///  - oPlayer: The player the map will be exposed/hidden for.
    ///  - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.
    /// </summary>
    public static void ExploreAreaForPlayer(uint oArea, uint oPlayer, int bExplored = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bExplored);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(403);
    }

    /// <summary>
    ///  The creature will equip the armour in its possession that has the highest
    ///  armour class.
    /// </summary>
    public static void ActionEquipMostEffectiveArmor()
    {
      NWNXPInvoke.CallBuiltIn(404);
    }

    /// <summary>
    ///  * Returns TRUE if it is currently day.
    /// </summary>
    public static int GetIsDay()
    {
      NWNXPInvoke.CallBuiltIn(405);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if it is currently night.
    /// </summary>
    public static int GetIsNight()
    {
      NWNXPInvoke.CallBuiltIn(406);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if it is currently dawn.
    /// </summary>
    public static int GetIsDawn()
    {
      NWNXPInvoke.CallBuiltIn(407);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if it is currently dusk.
    /// </summary>
    public static int GetIsDusk()
    {
      NWNXPInvoke.CallBuiltIn(408);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if oCreature was spawned from an encounter.
    /// </summary>
    public static int GetIsEncounterCreature(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(409);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnPlayerDying module script to get the last player who is dying.
    /// </summary>
    public static uint GetLastPlayerDying()
    {
      NWNXPInvoke.CallBuiltIn(410);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the starting location of the module.
    /// </summary>
    public static IntPtr GetStartingLocation()
    {
      NWNXPInvoke.CallBuiltIn(411);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  Make oCreatureToChange join one of the standard factions.
    ///  ** This will only work on an NPC **
    ///  - nStandardFaction: STANDARD_FACTION_*
    /// </summary>
    public static void ChangeToStandardFaction(uint oCreatureToChange, int nStandardFaction)
    {
      NWNXPInvoke.StackPushInteger(nStandardFaction);
      NWNXPInvoke.StackPushObject(oCreatureToChange);
      NWNXPInvoke.CallBuiltIn(412);
    }

    /// <summary>
    ///  Play oSound.
    /// </summary>
    public static void SoundObjectPlay(uint oSound)
    {
      NWNXPInvoke.StackPushObject(oSound);
      NWNXPInvoke.CallBuiltIn(413);
    }

    /// <summary>
    ///  Stop playing oSound.
    /// </summary>
    public static void SoundObjectStop(uint oSound)
    {
      NWNXPInvoke.StackPushObject(oSound);
      NWNXPInvoke.CallBuiltIn(414);
    }

    /// <summary>
    ///  Set the volume of oSound.
    ///  - oSound
    ///  - nVolume: 0-127
    /// </summary>
    public static void SoundObjectSetVolume(uint oSound, int nVolume)
    {
      NWNXPInvoke.StackPushInteger(nVolume);
      NWNXPInvoke.StackPushObject(oSound);
      NWNXPInvoke.CallBuiltIn(415);
    }

    /// <summary>
    ///  Set the position of oSound.
    /// </summary>
    public static void SoundObjectSetPosition(uint oSound, Vector3 vPosition)
    {
      NWNXPInvoke.StackPushVector(vPosition);
      NWNXPInvoke.StackPushObject(oSound);
      NWNXPInvoke.CallBuiltIn(416);
    }

    /// <summary>
    ///  Immediately speak a conversation one-liner.
    ///  - sDialogResRef
    ///  - oTokenTarget: This must be specified if there are creature-specific tokens
    ///    in the string.
    /// </summary>
    public static void SpeakOneLinerConversation(string sDialogResRef = "", uint oTokenTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTokenTarget);
      NWNXPInvoke.StackPushString(sDialogResRef);
      NWNXPInvoke.CallBuiltIn(417);
    }

    /// <summary>
    ///  Get the amount of gold possessed by oTarget.
    /// </summary>
    public static int GetGold(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(418);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in an OnRespawnButtonPressed module script to get the object id of
    ///  the player who last pressed the respawn button.
    /// </summary>
    public static uint GetLastRespawnButtonPresser()
    {
      NWNXPInvoke.CallBuiltIn(419);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is the Dungeon Master.
    ///  Note: This will return FALSE if oCreature is a DM Possessed creature.
    ///  To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
    /// </summary>
    public static int GetIsDM(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(420);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Play a voice chat.
    ///  - nVoiceChatID: VOICE_CHAT_*
    ///  - oTarget
    /// </summary>
    public static void PlayVoiceChat(int nVoiceChatID, uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nVoiceChatID);
      NWNXPInvoke.CallBuiltIn(421);
    }

    /// <summary>
    ///  * Returns TRUE if the weapon equipped is capable of damaging oVersus.
    /// </summary>
    public static int GetIsWeaponEffective(uint oVersus = OBJECT_INVALID, int bOffHand = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bOffHand);
      NWNXPInvoke.StackPushObject(oVersus);
      NWNXPInvoke.CallBuiltIn(422);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this in a SpellCast script to determine whether the spell was considered
    ///  harmful.
    ///  * Returns TRUE if the last spell cast was harmful.
    /// </summary>
    public static int GetLastSpellHarmful()
    {
      NWNXPInvoke.CallBuiltIn(423);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Activate oItem.
    /// </summary>
    public static IntPtr EventActivateItem(uint oItem, IntPtr lTarget, uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(424);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EVENT);
    }

    /// <summary>
    ///  Play the background music for oArea.
    /// </summary>
    public static void MusicBackgroundPlay(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(425);
    }

    /// <summary>
    ///  Stop the background music for oArea.
    /// </summary>
    public static void MusicBackgroundStop(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(426);
    }

    /// <summary>
    ///  Set the delay for the background music for oArea.
    ///  - oArea
    ///  - nDelay: delay in milliseconds
    /// </summary>
    public static void MusicBackgroundSetDelay(uint oArea, int nDelay)
    {
      NWNXPInvoke.StackPushInteger(nDelay);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(427);
    }

    /// <summary>
    ///  Change the background day track for oArea to nTrack.
    ///  - oArea
    ///  - nTrack
    /// </summary>
    public static void MusicBackgroundChangeDay(uint oArea, int nTrack)
    {
      NWNXPInvoke.StackPushInteger(nTrack);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(428);
    }

    /// <summary>
    ///  Change the background night track for oArea to nTrack.
    ///  - oArea
    ///  - nTrack
    /// </summary>
    public static void MusicBackgroundChangeNight(uint oArea, int nTrack)
    {
      NWNXPInvoke.StackPushInteger(nTrack);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(429);
    }

    /// <summary>
    ///  Play the battle music for oArea.
    /// </summary>
    public static void MusicBattlePlay(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(430);
    }

    /// <summary>
    ///  Stop the battle music for oArea.
    /// </summary>
    public static void MusicBattleStop(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(431);
    }

    /// <summary>
    ///  Change the battle track for oArea.
    ///  - oArea
    ///  - nTrack
    /// </summary>
    public static void MusicBattleChange(uint oArea, int nTrack)
    {
      NWNXPInvoke.StackPushInteger(nTrack);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(432);
    }

    /// <summary>
    ///  Play the ambient sound for oArea.
    /// </summary>
    public static void AmbientSoundPlay(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(433);
    }

    /// <summary>
    ///  Stop the ambient sound for oArea.
    /// </summary>
    public static void AmbientSoundStop(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(434);
    }

    /// <summary>
    ///  Change the ambient day track for oArea to nTrack.
    ///  - oArea
    ///  - nTrack
    /// </summary>
    public static void AmbientSoundChangeDay(uint oArea, int nTrack)
    {
      NWNXPInvoke.StackPushInteger(nTrack);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(435);
    }

    /// <summary>
    ///  Change the ambient night track for oArea to nTrack.
    ///  - oArea
    ///  - nTrack
    /// </summary>
    public static void AmbientSoundChangeNight(uint oArea, int nTrack)
    {
      NWNXPInvoke.StackPushInteger(nTrack);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(436);
    }

    /// <summary>
    ///  Get the object that killed the caller.
    /// </summary>
    public static uint GetLastKiller()
    {
      NWNXPInvoke.CallBuiltIn(437);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in a spell script to get the item used to cast the spell.
    /// </summary>
    public static uint GetSpellCastItem()
    {
      NWNXPInvoke.CallBuiltIn(438);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemActivated module script to get the item that was activated.
    /// </summary>
    public static uint GetItemActivated()
    {
      NWNXPInvoke.CallBuiltIn(439);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemActivated module script to get the creature that
    ///  activated the item.
    /// </summary>
    public static uint GetItemActivator()
    {
      NWNXPInvoke.CallBuiltIn(440);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this in an OnItemActivated module script to get the location of the item's
    ///  target.
    /// </summary>
    public static IntPtr GetItemActivatedTargetLocation()
    {
      NWNXPInvoke.CallBuiltIn(441);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  Use this in an OnItemActivated module script to get the item's target.
    /// </summary>
    public static uint GetItemActivatedTarget()
    {
      NWNXPInvoke.CallBuiltIn(442);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  * Returns TRUE if oObject (which is a placeable or a door) is currently open.
    /// </summary>
    public static int GetIsOpen(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(443);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Take nAmount of gold from oCreatureToTakeFrom.
    ///  - nAmount
    ///  - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.
    ///  - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the
    ///    gold will be destroyed and will vanish from the game.
    /// </summary>
    public static void TakeGoldFromCreature(int nAmount, uint oCreatureToTakeFrom, int bDestroy = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bDestroy);
      NWNXPInvoke.StackPushObject(oCreatureToTakeFrom);
      NWNXPInvoke.StackPushInteger(nAmount);
      NWNXPInvoke.CallBuiltIn(444);
    }

    /// <summary>
    ///  Determine whether oObject is in conversation.
    /// </summary>
    public static int IsInConversation(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(445);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create an Ability Decrease effect.
    ///  - nAbility: ABILITY_*
    ///  - nModifyBy: This is the amount by which to decrement the ability
    /// </summary>
    public static IntPtr EffectAbilityDecrease(int nAbility, int nModifyBy)
    {
      NWNXPInvoke.StackPushInteger(nModifyBy);
      NWNXPInvoke.StackPushInteger(nAbility);
      NWNXPInvoke.CallBuiltIn(446);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an Attack Decrease effect.
    ///  - nPenalty
    ///  - nModifierType: ATTACK_BONUS_*
    /// </summary>
    public static IntPtr EffectAttackDecrease(int nPenalty, int nModifierType = ATTACK_BONUS_MISC)
    {
      NWNXPInvoke.StackPushInteger(nModifierType);
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.CallBuiltIn(447);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage Decrease effect.
    ///  - nPenalty
    ///  - nDamageType: DAMAGE_TYPE_*
    /// </summary>
    public static IntPtr EffectDamageDecrease(int nPenalty, int nDamageType = DAMAGE_TYPE_MAGICAL)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.CallBuiltIn(448);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Damage Immunity Decrease effect.
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  - nPercentImmunity
    /// </summary>
    public static IntPtr EffectDamageImmunityDecrease(int nDamageType, int nPercentImmunity)
    {
      NWNXPInvoke.StackPushInteger(nPercentImmunity);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(449);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an AC Decrease effect.
    ///  - nValue
    ///  - nModifyType: AC_*
    ///  - nDamageType: DAMAGE_TYPE_*
    ///    * Default value for nDamageType should only ever be used in this function prototype.
    /// </summary>
    public static IntPtr EffectACDecrease(int nValue, int nModifyType = AC_DODGE_BONUS, int nDamageType = AC_VS_DAMAGE_TYPE_ALL)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nModifyType);
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.CallBuiltIn(450);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Movement Speed Decrease effect.
    ///  - nPercentChange - range 0 through 99
    ///  eg.
    ///     0 = no change in speed
    ///    50 = 50% slower
    ///    99 = almost immobile
    /// </summary>
    public static IntPtr EffectMovementSpeedDecrease(int nPercentChange)
    {
      NWNXPInvoke.StackPushInteger(nPercentChange);
      NWNXPInvoke.CallBuiltIn(451);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Saving Throw Decrease effect.
    ///  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
    ///           SAVING_THROW_ALL
    ///           SAVING_THROW_FORT
    ///           SAVING_THROW_REFLEX
    ///           SAVING_THROW_WILL
    ///  - nValue: size of the Saving Throw decrease
    ///  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
    /// </summary>
    public static IntPtr EffectSavingThrowDecrease(int nSave, int nValue, int nSaveType = SAVING_THROW_TYPE_ALL)
    {
      NWNXPInvoke.StackPushInteger(nSaveType);
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushInteger(nSave);
      NWNXPInvoke.CallBuiltIn(452);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Skill Decrease effect.
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
    /// </summary>
    public static IntPtr EffectSkillDecrease(int nSkill, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(453);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Spell Resistance Decrease effect.
    /// </summary>
    public static IntPtr EffectSpellResistanceDecrease(int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.CallBuiltIn(454);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Determine whether oTarget is a plot object.
    /// </summary>
    public static int GetPlotFlag(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(455);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set oTarget's plot object status.
    /// </summary>
    public static void SetPlotFlag(uint oTarget, int nPlotFlag)
    {
      NWNXPInvoke.StackPushInteger(nPlotFlag);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(456);
    }

    /// <summary>
    ///  Create an Invisibility effect.
    ///  - nInvisibilityType: INVISIBILITY_TYPE_*
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
    ///    is invalid.
    /// </summary>
    public static IntPtr EffectInvisibility(int nInvisibilityType)
    {
      NWNXPInvoke.StackPushInteger(nInvisibilityType);
      NWNXPInvoke.CallBuiltIn(457);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Concealment effect.
    ///  - nPercentage: 1-100 inclusive
    ///  - nMissChanceType: MISS_CHANCE_TYPE_*
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
    ///    nPercentage > 100.
    /// </summary>
    public static IntPtr EffectConcealment(int nPercentage, int nMissType = MISS_CHANCE_TYPE_NORMAL)
    {
      NWNXPInvoke.StackPushInteger(nMissType);
      NWNXPInvoke.StackPushInteger(nPercentage);
      NWNXPInvoke.CallBuiltIn(458);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Darkness effect.
    /// </summary>
    public static IntPtr EffectDarkness()
    {
      NWNXPInvoke.CallBuiltIn(459);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Dispel Magic All effect.
    ///  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
    ///  cause the dispel effect to use the level of the creature that created the
    ///  effect.
    /// </summary>
    public static IntPtr EffectDispelMagicAll(int nCasterLevel = USE_CREATURE_LEVEL)
    {
      NWNXPInvoke.StackPushInteger(nCasterLevel);
      NWNXPInvoke.CallBuiltIn(460);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an Ultravision effect.
    /// </summary>
    public static IntPtr EffectUltravision()
    {
      NWNXPInvoke.CallBuiltIn(461);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Negative Level effect.
    ///  - nNumLevels: the number of negative levels to apply.
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
    /// </summary>
    public static IntPtr EffectNegativeLevel(int nNumLevels, int bHPBonus = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bHPBonus);
      NWNXPInvoke.StackPushInteger(nNumLevels);
      NWNXPInvoke.CallBuiltIn(462);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Polymorph effect.
    /// </summary>
    public static IntPtr EffectPolymorph(int nPolymorphSelection, int nLocked = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nLocked);
      NWNXPInvoke.StackPushInteger(nPolymorphSelection);
      NWNXPInvoke.CallBuiltIn(463);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Sanctuary effect.
    ///  - nDifficultyClass: must be a non-zero, positive number
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
    /// </summary>
    public static IntPtr EffectSanctuary(int nDifficultyClass)
    {
      NWNXPInvoke.StackPushInteger(nDifficultyClass);
      NWNXPInvoke.CallBuiltIn(464);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a True Seeing effect.
    /// </summary>
    public static IntPtr EffectTrueSeeing()
    {
      NWNXPInvoke.CallBuiltIn(465);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a See Invisible effect.
    /// </summary>
    public static IntPtr EffectSeeInvisible()
    {
      NWNXPInvoke.CallBuiltIn(466);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Time Stop effect.
    /// </summary>
    public static IntPtr EffectTimeStop()
    {
      NWNXPInvoke.CallBuiltIn(467);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Blindness effect.
    /// </summary>
    public static IntPtr EffectBlindness()
    {
      NWNXPInvoke.CallBuiltIn(468);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Determine whether oSource has a friendly reaction towards oTarget, depending
    ///  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
    ///  oSource's Like/Dislike setting for oTarget.
    ///  Note: If you just want to know how two objects feel about each other in terms
    ///  of faction and personal reputation, use GetIsFriend() instead.
    ///  * Returns TRUE if oSource has a friendly reaction towards oTarget
    /// </summary>
    public static int GetIsReactionTypeFriendly(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(469);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oSource has a neutral reaction towards oTarget, depending
    ///  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
    ///  oSource's Like/Dislike setting for oTarget.
    ///  Note: If you just want to know how two objects feel about each other in terms
    ///  of faction and personal reputation, use GetIsNeutral() instead.
    ///  * Returns TRUE if oSource has a neutral reaction towards oTarget
    /// </summary>
    public static int GetIsReactionTypeNeutral(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(470);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oSource has a Hostile reaction towards oTarget, depending
    ///  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
    ///  oSource's Like/Dislike setting for oTarget.
    ///  Note: If you just want to know how two objects feel about each other in terms
    ///  of faction and personal reputation, use GetIsEnemy() instead.
    ///  * Returns TRUE if oSource has a hostile reaction towards oTarget
    /// </summary>
    public static int GetIsReactionTypeHostile(uint oTarget, uint oSource = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(471);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Spell Level Absorption effect.
    ///  - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the
    ///    effect
    ///  - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be
    ///    absorbed by the effect
    ///  - nSpellSchool: SPELL_SCHOOL_*
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
    ///    nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
    ///    is invalid.
    /// </summary>
    public static IntPtr EffectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed = 0, int nSpellSchool = SPELL_SCHOOL_GENERAL)
    {
      NWNXPInvoke.StackPushInteger(nSpellSchool);
      NWNXPInvoke.StackPushInteger(nTotalSpellLevelsAbsorbed);
      NWNXPInvoke.StackPushInteger(nMaxSpellLevelAbsorbed);
      NWNXPInvoke.CallBuiltIn(472);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Dispel Magic Best effect.
    ///  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
    ///  cause the dispel effect to use the level of the creature that created the
    ///  effect.
    /// </summary>
    public static IntPtr EffectDispelMagicBest(int nCasterLevel = USE_CREATURE_LEVEL)
    {
      NWNXPInvoke.StackPushInteger(nCasterLevel);
      NWNXPInvoke.CallBuiltIn(473);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Try to send oTarget to a new server defined by sIPaddress.
    ///  - oTarget
    ///  - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric
    ///    "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
    ///    "www.bioware.com:5121"; if the port is not specified, it will default to
    ///    5121.
    ///  - sPassword: login password for the destination server
    ///  - sWaypointTag: if this is set, after portalling the character will be moved
    ///    to this waypoint if it exists
    ///  - bSeamless: if this is set, the client wil not be prompted with the
    ///    information window telling them about the server, and they will not be
    ///    allowed to save a copy of their character if they are using a local vault
    ///    character.
    /// </summary>
    public static void ActivatePortal(uint oTarget, string sIPaddress = "", string sPassword = "", string sWaypointTag = "", int bSeemless = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bSeemless);
      NWNXPInvoke.StackPushString(sWaypointTag);
      NWNXPInvoke.StackPushString(sPassword);
      NWNXPInvoke.StackPushString(sIPaddress);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(474);
    }

    /// <summary>
    ///  Get the number of stacked items that oItem comprises.
    /// </summary>
    public static int GetNumStackedItems(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(475);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this on an NPC to cause all creatures within a 10-metre radius to stop
    ///  what they are doing and sets the NPC's enemies within this range to be
    ///  neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
    ///  or an object that is not a creature, nothing will happen.
    /// </summary>
    public static void SurrenderToEnemies()
    {
      NWNXPInvoke.CallBuiltIn(476);
    }

    /// <summary>
    ///  Create a Miss Chance effect.
    ///  - nPercentage: 1-100 inclusive
    ///  - nMissChanceType: MISS_CHANCE_TYPE_*
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
    ///    nPercentage > 100.
    /// </summary>
    public static IntPtr EffectMissChance(int nPercentage, int nMissChanceType = MISS_CHANCE_TYPE_NORMAL)
    {
      NWNXPInvoke.StackPushInteger(nMissChanceType);
      NWNXPInvoke.StackPushInteger(nPercentage);
      NWNXPInvoke.CallBuiltIn(477);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the number of Hitdice worth of Turn Resistance that oUndead may have.
    ///  This will only work on undead creatures.
    /// </summary>
    public static int GetTurnResistanceHD(uint oUndead = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oUndead);
      NWNXPInvoke.CallBuiltIn(478);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the size (CREATURE_SIZE_*) of oCreature.
    /// </summary>
    public static int GetCreatureSize(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(479);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Disappear/Appear effect.
    ///  The object will "fly away" for the duration of the effect and will reappear
    ///  at lLocation.
    ///  - nAnimation determines which appear and disappear animations to use. Most creatures
    ///  only have animation 1, although a few have 2 (like beholders)
    /// </summary>
    public static IntPtr EffectDisappearAppear(IntPtr lLocation, int nAnimation = 1)
    {
      NWNXPInvoke.StackPushInteger(nAnimation);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.CallBuiltIn(480);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Disappear effect to make the object "fly away" and then destroy
    ///  itself.
    ///  - nAnimation determines which appear and disappear animations to use. Most creatures
    ///  only have animation 1, although a few have 2 (like beholders)
    /// </summary>
    public static IntPtr EffectDisappear(int nAnimation = 1)
    {
      NWNXPInvoke.StackPushInteger(nAnimation);
      NWNXPInvoke.CallBuiltIn(481);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create an Appear effect to make the object "fly in".
    ///  - nAnimation determines which appear and disappear animations to use. Most creatures
    ///  only have animation 1, although a few have 2 (like beholders)
    /// </summary>
    public static IntPtr EffectAppear(int nAnimation = 1)
    {
      NWNXPInvoke.StackPushInteger(nAnimation);
      NWNXPInvoke.CallBuiltIn(482);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  The action subject will unlock oTarget, which can be a door or a placeable
    ///  object.
    /// </summary>
    public static void ActionUnlockObject(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(483);
    }

    /// <summary>
    ///  The action subject will lock oTarget, which can be a door or a placeable
    ///  object.
    /// </summary>
    public static void ActionLockObject(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(484);
    }

    /// <summary>
    ///  Create a Modify Attacks effect to add attacks.
    ///  - nAttacks: maximum is 5, even with the effect stacked
    ///  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
    /// </summary>
    public static IntPtr EffectModifyAttacks(int nAttacks)
    {
      NWNXPInvoke.StackPushInteger(nAttacks);
      NWNXPInvoke.CallBuiltIn(485);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the last trap detected by oTarget.
    ///  * Return value on error: OBJECT_INVALID
    /// </summary>
    public static uint GetLastTrapDetected(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(486);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
    ///  damage to any melee attacker on a successful attack of damage type nDamageType.
    ///  - nDamageAmount: an integer value
    ///  - nRandomAmount: DAMAGE_BONUS_*
    ///  - nDamageType: DAMAGE_TYPE_*
    ///  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
    ///        result in odd behaviour.
    /// </summary>
    public static IntPtr EffectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nRandomAmount);
      NWNXPInvoke.StackPushInteger(nDamageAmount);
      NWNXPInvoke.CallBuiltIn(487);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Get the trap nearest to oTarget.
    ///  Note : "trap objects" are actually any trigger, placeable or door that is
    ///  trapped in oTarget's area.
    ///  - oTarget
    ///  - nTrapDetected: if this is TRUE, the trap returned has to have been detected
    ///    by oTarget.
    /// </summary>
    public static uint GetNearestTrapToObject(uint oTarget = OBJECT_INVALID, int nTrapDetected = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nTrapDetected);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(488);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the name of oCreature's deity.
    ///  * Returns "" if oCreature is invalid (or if the deity name is blank for
    ///    oCreature).
    /// </summary>
    public static string GetDeity(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(489);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the name of oCreature's sub race.
    ///  * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
    /// </summary>
    public static string GetSubRace(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(490);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get oTarget's base fortitude saving throw value (this will only work for
    ///  creatures, doors, and placeables).
    ///  * Returns 0 if oTarget is invalid.
    /// </summary>
    public static int GetFortitudeSavingThrow(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(491);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oTarget's base will saving throw value (this will only work for creatures,
    ///  doors, and placeables).
    ///  * Returns 0 if oTarget is invalid.
    /// </summary>
    public static int GetWillSavingThrow(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(492);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oTarget's base reflex saving throw value (this will only work for
    ///  creatures, doors, and placeables).
    ///  * Returns 0 if oTarget is invalid.
    /// </summary>
    public static int GetReflexSavingThrow(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(493);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oCreature's challenge rating.
    ///  * Returns 0.0 if oCreature is invalid.
    /// </summary>
    public static float GetChallengeRating(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(494);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Get oCreature's age.
    ///  * Returns 0 if oCreature is invalid.
    /// </summary>
    public static int GetAge(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(495);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oCreature's movement rate.
    ///  * Returns 0 if oCreature is invalid.
    /// </summary>
    public static int GetMovementRate(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(496);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
    ///  * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
    ///    currently have a familiar.
    /// </summary>
    public static int GetFamiliarCreatureType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(497);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oCreature's animal companion creature type
    ///  (ANIMAL_COMPANION_CREATURE_TYPE_*).
    ///  * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
    ///    not currently have an animal companion.
    /// </summary>
    public static int GetAnimalCompanionCreatureType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(498);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get oCreature's familiar's name.
    ///  * Returns "" if oCreature is invalid, does not currently
    ///  have a familiar or if the familiar's name is blank.
    /// </summary>
    public static string GetFamiliarName(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(499);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get oCreature's animal companion's name.
    ///  * Returns "" if oCreature is invalid, does not currently
    ///  have an animal companion or if the animal companion's name is blank.
    /// </summary>
    public static string GetAnimalCompanionName(uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(500);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  The action subject will fake casting a spell at oTarget; the conjure and cast
    ///  animations and visuals will occur, nothing else.
    ///  - nSpell
    ///  - oTarget
    ///  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
    /// </summary>
    public static void ActionCastFakeSpellAtObject(int nSpell, uint oTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
    {
      NWNXPInvoke.StackPushInteger(nProjectilePathType);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(501);
    }

    /// <summary>
    ///  The action subject will fake casting a spell at lLocation; the conjure and
    ///  cast animations and visuals will occur, nothing else.
    ///  - nSpell
    ///  - lTarget
    ///  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
    /// </summary>
    public static void ActionCastFakeSpellAtLocation(int nSpell, IntPtr lTarget, int nProjectilePathType = PROJECTILE_PATH_TYPE_DEFAULT)
    {
      NWNXPInvoke.StackPushInteger(nProjectilePathType);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(502);
    }

    /// <summary>
    ///  Removes oAssociate from the service of oMaster, returning them to their
    ///  original faction.
    /// </summary>
    public static void RemoveSummonedAssociate(uint oMaster, uint oAssociate = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oAssociate);
      NWNXPInvoke.StackPushObject(oMaster);
      NWNXPInvoke.CallBuiltIn(503);
    }

    /// <summary>
    ///  Set the camera mode for oPlayer.
    ///  - oPlayer
    ///  - nCameraMode: CAMERA_MODE_*
    ///  * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
    ///    happens.
    /// </summary>
    public static void SetCameraMode(uint oPlayer, int nCameraMode)
    {
      NWNXPInvoke.StackPushInteger(nCameraMode);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(504);
    }

    /// <summary>
    ///  * Returns TRUE if oCreature is resting.
    /// </summary>
    public static int GetIsResting(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(505);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the last PC that has rested in the module.
    /// </summary>
    public static uint GetLastPCRested()
    {
      NWNXPInvoke.CallBuiltIn(506);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Set the weather for oTarget.
    ///  - oTarget: if this is GetModule(), all outdoor areas will be modified by the
    ///    weather constant. If it is an area, oTarget will play the weather only if
    ///    it is an outdoor area.
    ///  - nWeather: WEATHER_*
    ///    -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
    ///    -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
    ///       the appropriate precipitation *without stopping*.
    /// </summary>
    public static void SetWeather(uint oTarget, int nWeather)
    {
      NWNXPInvoke.StackPushInteger(nWeather);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(507);
    }

    /// <summary>
    ///  Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
    ///  returned from the OnPCRested module event).
    /// </summary>
    public static int GetLastRestEventType()
    {
      NWNXPInvoke.CallBuiltIn(508);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Shut down the currently loaded module and start a new one (moving all
    ///  currently-connected players to the starting point.
    /// </summary>
    public static void StartNewModule(string sModuleName)
    {
      NWNXPInvoke.StackPushString(sModuleName);
      NWNXPInvoke.CallBuiltIn(509);
    }

    /// <summary>
    ///  Create a Swarm effect.
    ///  - nLooping: If this is TRUE, for the duration of the effect when one creature
    ///    created by this effect dies, the next one in the list will be created.  If
    ///    the last creature in the list dies, we loop back to the beginning and
    ///    sCreatureTemplate1 will be created, and so on...
    ///  - sCreatureTemplate1
    ///  - sCreatureTemplate2
    ///  - sCreatureTemplate3
    ///  - sCreatureTemplate4
    /// </summary>
    public static IntPtr EffectSwarm(int nLooping, string sCreatureTemplate1, string sCreatureTemplate2 = "", string sCreatureTemplate3 = "", string sCreatureTemplate4 = "")
    {
      NWNXPInvoke.StackPushString(sCreatureTemplate4);
      NWNXPInvoke.StackPushString(sCreatureTemplate3);
      NWNXPInvoke.StackPushString(sCreatureTemplate2);
      NWNXPInvoke.StackPushString(sCreatureTemplate1);
      NWNXPInvoke.StackPushInteger(nLooping);
      NWNXPInvoke.CallBuiltIn(510);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  * Returns TRUE if oItem is a ranged weapon.
    /// </summary>
    public static int GetWeaponRanged(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(511);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Only if we are in a single player game, AutoSave the game.
    /// </summary>
    public static void DoSinglePlayerAutoSave()
    {
      NWNXPInvoke.CallBuiltIn(512);
    }

    /// <summary>
    ///  Get the game difficulty (GAME_DIFFICULTY_*).
    /// </summary>
    public static int GetGameDifficulty()
    {
      NWNXPInvoke.CallBuiltIn(513);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the main light color on the tile at lTileLocation.
    ///  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
    ///    the tile.
    ///  - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*
    ///  - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*
    /// </summary>
    public static void SetTileMainLightColor(IntPtr lTileLocation, int nMainLight1Color, int nMainLight2Color)
    {
      NWNXPInvoke.StackPushInteger(nMainLight2Color);
      NWNXPInvoke.StackPushInteger(nMainLight1Color);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation);
      NWNXPInvoke.CallBuiltIn(514);
    }

    /// <summary>
    ///  Set the source light color on the tile at lTileLocation.
    ///  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
    ///    the tile.
    ///  - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*
    ///  - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*
    /// </summary>
    public static void SetTileSourceLightColor(IntPtr lTileLocation, int nSourceLight1Color, int nSourceLight2Color)
    {
      NWNXPInvoke.StackPushInteger(nSourceLight2Color);
      NWNXPInvoke.StackPushInteger(nSourceLight1Color);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTileLocation);
      NWNXPInvoke.CallBuiltIn(515);
    }

    /// <summary>
    ///  All clients in oArea will recompute the static lighting.
    ///  This can be used to update the lighting after changing any tile lights or if
    ///  placeables with lights have been added/deleted.
    /// </summary>
    public static void RecomputeStaticLighting(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(516);
    }

    /// <summary>
    ///  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
    ///  lTile.
    ///  - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.
    /// </summary>
    public static int GetTileMainLight1Color(IntPtr lTile)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTile);
      NWNXPInvoke.CallBuiltIn(517);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
    ///  lTile.
    ///  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
    ///    tile.
    /// </summary>
    public static int GetTileMainLight2Color(IntPtr lTile)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTile);
      NWNXPInvoke.CallBuiltIn(518);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
    ///  at lTile.
    ///  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
    ///    tile.
    /// </summary>
    public static int GetTileSourceLight1Color(IntPtr lTile)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTile);
      NWNXPInvoke.CallBuiltIn(519);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
    ///  at lTile.
    ///  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
    ///    tile.
    /// </summary>
    public static int GetTileSourceLight2Color(IntPtr lTile)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTile);
      NWNXPInvoke.CallBuiltIn(520);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Make the corresponding panel button on the player's client start or stop
    ///  flashing.
    ///  - oPlayer
    ///  - nButton: PANEL_BUTTON_*
    ///  - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,
    ///    nButton will stop flashing.
    /// </summary>
    public static void SetPanelButtonFlash(uint oPlayer, int nButton, int nEnableFlash)
    {
      NWNXPInvoke.StackPushInteger(nEnableFlash);
      NWNXPInvoke.StackPushInteger(nButton);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(521);
    }

    /// <summary>
    ///  Get the current action (ACTION_*) that oObject is executing.
    /// </summary>
    public static int GetCurrentAction(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(522);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set how nStandardFaction feels about oCreature.
    ///  - nStandardFaction: STANDARD_FACTION_*
    ///  - nNewReputation: 0-100 (inclusive)
    ///  - oCreature
    /// </summary>
    public static void SetStandardFactionReputation(int nStandardFaction, int nNewReputation, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nNewReputation);
      NWNXPInvoke.StackPushInteger(nStandardFaction);
      NWNXPInvoke.CallBuiltIn(523);
    }

    /// <summary>
    ///  Find out how nStandardFaction feels about oCreature.
    ///  - nStandardFaction: STANDARD_FACTION_*
    ///  - oCreature
    ///  Returns -1 on an error.
    ///  Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
    ///  0-10   :  Hostile.
    ///  11-89  :  Neutral.
    ///  90-100 :  Friendly.
    /// </summary>
    public static int GetStandardFactionReputation(int nStandardFaction, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nStandardFaction);
      NWNXPInvoke.CallBuiltIn(524);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Display floaty text above the specified creature.
    ///  The text will also appear in the chat buffer of each player that receives the
    ///  floaty text.
    ///  - nStrRefToDisplay: String ref (therefore text is translated)
    ///  - oCreatureToFloatAbove
    ///  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
    ///    as oCreatureToFloatAbove
    ///    will see the floaty text, and only if they are within range (30 metres).
    /// </summary>
    public static void FloatingTextStrRefOnCreature(int nStrRefToDisplay, uint oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bBroadcastToFaction);
      NWNXPInvoke.StackPushObject(oCreatureToFloatAbove);
      NWNXPInvoke.StackPushInteger(nStrRefToDisplay);
      NWNXPInvoke.CallBuiltIn(525);
    }

    /// <summary>
    ///  Display floaty text above the specified creature.
    ///  The text will also appear in the chat buffer of each player that receives the
    ///  floaty text.
    ///  - sStringToDisplay: String
    ///  - oCreatureToFloatAbove
    ///  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
    ///    as oCreatureToFloatAbove
    ///    will see the floaty text, and only if they are within range (30 metres).
    /// </summary>
    public static void FloatingTextStringOnCreature(string sStringToDisplay, uint oCreatureToFloatAbove, int bBroadcastToFaction = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bBroadcastToFaction);
      NWNXPInvoke.StackPushObject(oCreatureToFloatAbove);
      NWNXPInvoke.StackPushString(sStringToDisplay);
      NWNXPInvoke.CallBuiltIn(526);
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject is disarmable.
    /// </summary>
    public static int GetTrapDisarmable(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(527);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject is detectable.
    /// </summary>
    public static int GetTrapDetectable(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(528);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  - oCreature
    ///  * Returns TRUE if oCreature has detected oTrapObject
    /// </summary>
    public static int GetTrapDetectedBy(uint oTrapObject, uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(529);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
    /// </summary>
    public static int GetTrapFlagged(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(530);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static int GetTrapBaseType(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(531);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
    ///    after firing.
    /// </summary>
    public static int GetTrapOneShot(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(532);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the creator of oTrapObject, the creature that set the trap.
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
    /// </summary>
    public static uint GetTrapCreator(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(533);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the tag of the key that will disarm oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static string GetTrapKeyTag(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(534);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the DC for disarming oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static int GetTrapDisarmDC(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(535);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the DC for detecting oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static int GetTrapDetectDC(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(536);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  * Returns TRUE if a specific key is required to open the lock on oObject.
    /// </summary>
    public static int GetLockKeyRequired(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(537);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the tag of the key that will open the lock on oObject.
    /// </summary>
    public static string GetLockKeyTag(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(538);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  * Returns TRUE if the lock on oObject is lockable.
    /// </summary>
    public static int GetLockLockable(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(539);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the DC for unlocking oObject.
    /// </summary>
    public static int GetLockUnlockDC(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(540);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the DC for locking oObject.
    /// </summary>
    public static int GetLockLockDC(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(541);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the last PC that levelled up.
    /// </summary>
    public static uint GetPCLevellingUp()
    {
      NWNXPInvoke.CallBuiltIn(542);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  - nFeat: FEAT_*
    ///  - oObject
    ///  * Returns TRUE if oObject has effects on it originating from nFeat.
    /// </summary>
    public static int GetHasFeatEffect(int nFeat, uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.CallBuiltIn(543);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the status of the illumination for oPlaceable.
    ///  - oPlaceable
    ///  - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.
    ///    If this is FALSE, oPlaceable's illumination will be turned off.
    ///  Note: You must call RecomputeStaticLighting() after calling this function in
    ///  order for the changes to occur visually for the players.
    ///  SetPlaceableIllumination() buffers the illumination changes, which are then
    ///  sent out to the players once RecomputeStaticLighting() is called.  As such,
    ///  it is best to call SetPlaceableIllumination() for all the placeables you wish
    ///  to set the illumination on, and then call RecomputeStaticLighting() once after
    ///  all the placeable illumination has been set.
    ///  * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
    ///    doesn't have a light, nothing will happen.
    /// </summary>
    public static void SetPlaceableIllumination(uint oPlaceable = OBJECT_INVALID, int bIlluminate = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bIlluminate);
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(544);
    }

    /// <summary>
    ///  * Returns TRUE if the illumination for oPlaceable is on
    /// </summary>
    public static int GetPlaceableIllumination(uint oPlaceable = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(545);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  - oPlaceable
    ///  - nPlaceableAction: PLACEABLE_ACTION_*
    ///  * Returns TRUE if nPlacebleAction is valid for oPlaceable.
    /// </summary>
    public static int GetIsPlaceableObjectActionPossible(uint oPlaceable, int nPlaceableAction)
    {
      NWNXPInvoke.StackPushInteger(nPlaceableAction);
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(546);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  The caller performs nPlaceableAction on oPlaceable.
    ///  - oPlaceable
    ///  - nPlaceableAction: PLACEABLE_ACTION_*
    /// </summary>
    public static void DoPlaceableObjectAction(uint oPlaceable, int nPlaceableAction)
    {
      NWNXPInvoke.StackPushInteger(nPlaceableAction);
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(547);
    }

    /// <summary>
    ///  Get the first PC in the player list.
    ///  This resets the position in the player list for GetNextPC().
    /// </summary>
    public static uint GetFirstPC()
    {
      NWNXPInvoke.CallBuiltIn(548);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the next PC in the player list.
    ///  This picks up where the last GetFirstPC() or GetNextPC() left off.
    /// </summary>
    public static uint GetNextPC()
    {
      NWNXPInvoke.CallBuiltIn(549);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Set whether or not the creature oDetector has detected the trapped object oTrap.
    ///  - oTrap: A trapped trigger, placeable or door object.
    ///  - oDetector: This is the creature that the detected status of the trap is being adjusted for.
    ///  - bDetected: A Boolean that sets whether the trapped object has been detected or not.
    /// </summary>
    public static int SetTrapDetectedBy(uint oTrap, uint oDetector, int bDetected = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bDetected);
      NWNXPInvoke.StackPushObject(oDetector);
      NWNXPInvoke.StackPushObject(oTrap);
      NWNXPInvoke.CallBuiltIn(550);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Note: Only placeables, doors and triggers can be trapped.
    ///  * Returns TRUE if oObject is trapped.
    /// </summary>
    public static int GetIsTrapped(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(551);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Create a Turn Resistance Decrease effect.
    ///  - nHitDice: a positive number representing the number of hit dice for the
    /// /  decrease
    /// </summary>
    public static IntPtr EffectTurnResistanceDecrease(int nHitDice)
    {
      NWNXPInvoke.StackPushInteger(nHitDice);
      NWNXPInvoke.CallBuiltIn(552);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Create a Turn Resistance Increase effect.
    ///  - nHitDice: a positive number representing the number of hit dice for the
    ///    increase
    /// </summary>
    public static IntPtr EffectTurnResistanceIncrease(int nHitDice)
    {
      NWNXPInvoke.StackPushInteger(nHitDice);
      NWNXPInvoke.CallBuiltIn(553);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Spawn in the Death GUI.
    ///  The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
    ///  if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
    ///  function to use.
    ///  - oPC
    ///  - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled
    ///    on the Death GUI.
    ///  - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will
    ///    be enabled on the Death GUI (Note: This button will not appear in single player games).
    ///  - nHelpStringReference
    ///  - sHelpString
    /// </summary>
    public static void PopUpDeathGUIPanel(uint oPC, int bRespawnButtonEnabled = TRUE, int bWaitForHelpButtonEnabled = TRUE, int nHelpStringReference = 0, string sHelpString = "")
    {
      NWNXPInvoke.StackPushString(sHelpString);
      NWNXPInvoke.StackPushInteger(nHelpStringReference);
      NWNXPInvoke.StackPushInteger(bWaitForHelpButtonEnabled);
      NWNXPInvoke.StackPushInteger(bRespawnButtonEnabled);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(554);
    }

    /// <summary>
    ///  Disable oTrap.
    ///  - oTrap: a placeable, door or trigger.
    /// </summary>
    public static void SetTrapDisabled(uint oTrap)
    {
      NWNXPInvoke.StackPushObject(oTrap);
      NWNXPInvoke.CallBuiltIn(555);
    }

    /// <summary>
    ///  Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
    ///  GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
    ///  creature is pickpocketed).
    ///  Note: Return values may only ever be:
    ///  1) A Creature
    ///  2) Plot Characters will never have this value set
    ///  3) Area of Effect Objects will return the AOE creator if they are registered
    ///     as this value, otherwise they will return INVALID_OBJECT_ID
    ///  4) Traps will not return the creature that set the trap.
    ///  5) This value will never be overwritten by another non-creature object.
    ///  6) This value will never be a dead/destroyed creature
    /// </summary>
    public static uint GetLastHostileActor(uint oVictim = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oVictim);
      NWNXPInvoke.CallBuiltIn(556);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Force all the characters of the players who are currently in the game to
    ///  be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
    /// </summary>
    public static void ExportAllCharacters()
    {
      NWNXPInvoke.CallBuiltIn(557);
    }

    /// <summary>
    ///  Get the Day Track for oArea.
    /// </summary>
    public static int MusicBackgroundGetDayTrack(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(558);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the Night Track for oArea.
    /// </summary>
    public static int MusicBackgroundGetNightTrack(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(559);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Write sLogEntry as a timestamped entry into the log file
    /// </summary>
    public static void WriteTimestampedLogEntry(string sLogEntry)
    {
      NWNXPInvoke.StackPushString(sLogEntry);
      NWNXPInvoke.CallBuiltIn(560);
    }

    /// <summary>
    ///  Get the module's name in the language of the server that's running it.
    ///  * If there is no entry for the language of the server, it will return an
    ///    empty string
    /// </summary>
    public static string GetModuleName()
    {
      NWNXPInvoke.CallBuiltIn(561);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the player leader of the faction of which oMemberOfFaction is a member.
    ///  * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
    ///    or oMemberOfFaction is a member of a NPC faction.
    /// </summary>
    public static uint GetFactionLeader(uint oMemberOfFaction)
    {
      NWNXPInvoke.StackPushObject(oMemberOfFaction);
      NWNXPInvoke.CallBuiltIn(562);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Sends szMessage to all the Dungeon Masters currently on the server.
    /// </summary>
    public static void SendMessageToAllDMs(string szMessage)
    {
      NWNXPInvoke.StackPushString(szMessage);
      NWNXPInvoke.CallBuiltIn(563);
    }

    /// <summary>
    ///  End the currently running game, play sEndMovie then return all players to the
    ///  game's main menu.
    /// </summary>
    public static void EndGame(string sEndMovie)
    {
      NWNXPInvoke.StackPushString(sEndMovie);
      NWNXPInvoke.CallBuiltIn(564);
    }

    /// <summary>
    ///  Remove oPlayer from the server.
    ///  You can optionally specify a reason to override the text shown to the player.
    /// </summary>
    public static void BootPC(uint oPlayer, string sReason = "")
    {
      NWNXPInvoke.StackPushString(sReason);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(565);
    }

    /// <summary>
    ///  Counterspell oCounterSpellTarget.
    /// </summary>
    public static void ActionCounterSpell(uint oCounterSpellTarget)
    {
      NWNXPInvoke.StackPushObject(oCounterSpellTarget);
      NWNXPInvoke.CallBuiltIn(566);
    }

    /// <summary>
    ///  Set the ambient day volume for oArea to nVolume.
    ///  - oArea
    ///  - nVolume: 0 - 100
    /// </summary>
    public static void AmbientSoundSetDayVolume(uint oArea, int nVolume)
    {
      NWNXPInvoke.StackPushInteger(nVolume);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(567);
    }

    /// <summary>
    ///  Set the ambient night volume for oArea to nVolume.
    ///  - oArea
    ///  - nVolume: 0 - 100
    /// </summary>
    public static void AmbientSoundSetNightVolume(uint oArea, int nVolume)
    {
      NWNXPInvoke.StackPushInteger(nVolume);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(568);
    }

    /// <summary>
    ///  Get the Battle Track for oArea.
    /// </summary>
    public static int MusicBackgroundGetBattleTrack(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(569);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Determine whether oObject has an inventory.
    ///  * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
    ///  * Returns FALSE for all other object types.
    /// </summary>
    public static int GetHasInventory(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(570);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the duration (in seconds) of the sound attached to nStrRef
    ///  * Returns 0.0f if no duration is stored or if no sound is attached
    /// </summary>
    public static float GetStrRefSoundDuration(int nStrRef)
    {
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(571);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Add oPC to oPartyLeader's party.  This will only work on two PCs.
    ///  - oPC: player to add to a party
    ///  - oPartyLeader: player already in the party
    /// </summary>
    public static void AddToParty(uint oPC, uint oPartyLeader)
    {
      NWNXPInvoke.StackPushObject(oPartyLeader);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(572);
    }

    /// <summary>
    ///  Remove oPC from their current party. This will only work on a PC.
    ///  - oPC: removes this player from whatever party they're currently in.
    /// </summary>
    public static void RemoveFromParty(uint oPC)
    {
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(573);
    }

    /// <summary>
    ///  Returns the stealth mode of the specified creature.
    ///  - oCreature
    ///  * Returns a constant STEALTH_MODE_*
    /// </summary>
    public static int GetStealthMode(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(574);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the detection mode of the specified creature.
    ///  - oCreature
    ///  * Returns a constant DETECT_MODE_*
    /// </summary>
    public static int GetDetectMode(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(575);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the defensive casting mode of the specified creature.
    ///  - oCreature
    ///  * Returns a constant DEFENSIVE_CASTING_MODE_*
    /// </summary>
    public static int GetDefensiveCastingMode(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(576);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  returns the appearance type of the specified creature.
    ///  * returns a constant APPEARANCE_TYPE_* for valid creatures
    ///  * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
    /// </summary>
    public static int GetAppearanceType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(577);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  SpawnScriptDebugger() will cause the script debugger to be executed
    ///  after this command is executed!
    ///  In order to compile the script for debugging go to Tools->Options->Script Editor
    ///  and check the box labeled "Generate Debug Information When Compiling Scripts"
    ///  After you have checked the above box, recompile the script that you want to debug.
    ///  If the script file isn't compiled for debugging, this command will do nothing.
    ///  Remove any SpawnScriptDebugger() calls once you have finished
    ///  debugging the script.
    /// </summary>
    public static void SpawnScriptDebugger()
    {
      NWNXPInvoke.CallBuiltIn(578);
    }

    /// <summary>
    ///  in an onItemAcquired script, returns the size of the stack of the item
    ///  that was just acquired.
    ///  * returns the stack size of the item acquired
    /// </summary>
    public static int GetModuleItemAcquiredStackSize()
    {
      NWNXPInvoke.CallBuiltIn(579);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Decrement the remaining uses per day for this creature by one.
    ///  - oCreature: creature to modify
    ///  - nFeat: constant FEAT_*
    /// </summary>
    public static void DecrementRemainingFeatUses(uint oCreature, int nFeat)
    {
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(580);
    }

    /// <summary>
    ///  Decrement the remaining uses per day for this creature by one.
    ///  - oCreature: creature to modify
    ///  - nSpell: constant SPELL_*
    /// </summary>
    public static void DecrementRemainingSpellUses(uint oCreature, int nSpell)
    {
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(581);
    }

    /// <summary>
    ///  returns the template used to create this object (if appropriate)
    ///  * returns an empty string when no template found
    /// </summary>
    public static string GetResRef(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(582);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  returns an effect that will petrify the target
    ///  * currently applies EffectParalyze and the stoneskin visual effect.
    /// </summary>
    public static IntPtr EffectPetrify()
    {
      NWNXPInvoke.CallBuiltIn(583);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  duplicates the item and returns a new object
    ///  oItem - item to copy
    ///  oTargetInventory - create item in this object's inventory. If this parameter
    ///                     is not valid, the item will be created in oItem's location
    ///  bCopyVars - copy the local variables from the old item to the new one
    ///  * returns the new item
    ///  * returns OBJECT_INVALID for non-items.
    ///  * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
    ///    other items.
    ///  * if it is possible to merge this item with any others in the target location,
    ///    then it will do so and return the merged object.
    /// </summary>
    public static uint CopyItem(uint oItem, uint oTargetInventory = OBJECT_INVALID, int bCopyVars = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bCopyVars);
      NWNXPInvoke.StackPushObject(oTargetInventory);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(584);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  returns an effect that is guaranteed to paralyze a creature.
    ///  this effect is identical to EffectParalyze except that it cannot be resisted.
    /// </summary>
    public static IntPtr EffectCutsceneParalyze()
    {
      NWNXPInvoke.CallBuiltIn(585);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  returns TRUE if the item CAN be dropped
    ///  Droppable items will appear on a creature's remains when the creature is killed.
    /// </summary>
    public static int GetDroppableFlag(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(586);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  returns TRUE if the placeable object is usable
    /// </summary>
    public static int GetUseableFlag(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(587);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  returns TRUE if the item is stolen
    /// </summary>
    public static int GetStolenFlag(uint oStolen)
    {
      NWNXPInvoke.StackPushObject(oStolen);
      NWNXPInvoke.CallBuiltIn(588);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  This stores a float out to the specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static void SetCampaignFloat(string sCampaignName, string sVarName, float flFloat, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushFloat(flFloat);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(589);
    }

    /// <summary>
    ///  This stores an int out to the specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static void SetCampaignInt(string sCampaignName, string sVarName, int nInt, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushInteger(nInt);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(590);
    }

    /// <summary>
    ///  This stores a vector out to the specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static void SetCampaignVector(string sCampaignName, string sVarName, Vector3 vVector, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(591);
    }

    /// <summary>
    ///  This stores a location out to the specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static void SetCampaignLocation(string sCampaignName, string sVarName, IntPtr locLocation, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(592);
    }

    /// <summary>
    ///  This stores a string out to the specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static void SetCampaignString(string sCampaignName, string sVarName, string sString, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(593);
    }

    /// <summary>
    ///  This will delete the entire campaign database if it exists.
    /// </summary>
    public static void DestroyCampaignDatabase(string sCampaignName)
    {
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(594);
    }

    /// <summary>
    ///  This will read a float from the  specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static float GetCampaignFloat(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(595);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  This will read an int from the  specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static int GetCampaignInt(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(596);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  This will read a vector from the  specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static Vector3 GetCampaignVector(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(597);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    ///  This will read a location from the  specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static IntPtr GetCampaignLocation(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(598);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_LOCATION);
    }

    /// <summary>
    ///  This will read a string from the  specified campaign database
    ///  The database name IS case sensitive and it must be the same for both set and get functions.
    ///  The var name must be unique across the entire database, regardless of the variable type.
    ///  If you want a variable to pertain to a specific player in the game, provide a player object.
    /// </summary>
    public static string GetCampaignString(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(599);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Duplicates the object specified by oSource.
    ///  ONLY creatures and items can be specified.
    ///  If an owner is specified and the object is an item, it will be put into their inventory
    ///  If the object is a creature, they will be created at the location.
    ///  If a new tag is specified, it will be assigned to the new object.
    /// </summary>
    public static uint CopyObject(uint oSource, IntPtr locLocation, uint oOwner = OBJECT_INVALID, string sNewTag = "")
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushObject(oOwner);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.CallBuiltIn(600);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  This will remove ANY campaign variable. Regardless of type.
    ///  Note that by normal database standards, deleting does not actually removed the entry from
    ///  the database, but flags it as deleted. Do not expect the database files to shrink in size
    ///  from this command. If you want to 'pack' the database, you will have to do it externally
    ///  from the game.
    /// </summary>
    public static void DeleteCampaignVariable(string sCampaignName, string sVarName, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(601);
    }

    /// <summary>
    ///  Stores an object with the given id.
    ///  NOTE: this command can only be used for storing Creatures and Items.
    ///  Returns 0 if it failled, 1 if it worked.
    /// </summary>
    public static int StoreCampaignObject(string sCampaignName, string sVarName, uint oObject, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(602);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use RetrieveCampaign with the given id to restore it.
    ///  If you specify an owner, the object will try to be created in their repository
    ///  If the owner can't handle the item (or if it's a creature) it will be created on the ground.
    /// </summary>
    public static uint RetrieveCampaignObject(string sCampaignName, string sVarName, IntPtr locLocation, uint oOwner = OBJECT_INVALID, uint oPlayer = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushObject(oOwner);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, locLocation);
      NWNXPInvoke.StackPushString(sVarName);
      NWNXPInvoke.StackPushString(sCampaignName);
      NWNXPInvoke.CallBuiltIn(603);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Returns an effect that is guaranteed to dominate a creature
    ///  Like EffectDominated but cannot be resisted
    /// </summary>
    public static IntPtr EffectCutsceneDominated()
    {
      NWNXPInvoke.CallBuiltIn(604);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Returns stack size of an item
    ///  - oItem: item to query
    /// </summary>
    public static int GetItemStackSize(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(605);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets stack size of an item.
    ///  - oItem: item to change
    ///  - nSize: new size of stack.  Will be restricted to be between 1 and the
    ///    maximum stack size for the item type.  If a value less than 1 is passed it
    ///    will set the stack to 1.  If a value greater than the max is passed
    ///    then it will set the stack to the maximum size
    /// </summary>
    public static void SetItemStackSize(uint oItem, int nSize)
    {
      NWNXPInvoke.StackPushInteger(nSize);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(606);
    }

    /// <summary>
    ///  Returns charges left on an item
    ///  - oItem: item to query
    /// </summary>
    public static int GetItemCharges(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(607);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets charges left on an item.
    ///  - oItem: item to change
    ///  - nCharges: number of charges.  If value below 0 is passed, # charges will
    ///    be set to 0.  If value greater than maximum is passed, # charges will
    ///    be set to maximum.  If the # charges drops to 0 the item
    ///    will be destroyed.
    /// </summary>
    public static void SetItemCharges(uint oItem, int nCharges)
    {
      NWNXPInvoke.StackPushInteger(nCharges);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(608);
    }

    /// <summary>
    ///  ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************
    ///  adds an item property to the specified item
    ///  Only temporary and permanent duration types are allowed.
    /// </summary>
    public static void AddItemProperty(int nDurationType, IntPtr ipProperty, uint oItem, float fDuration = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fDuration);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ipProperty);
      NWNXPInvoke.StackPushInteger(nDurationType);
      NWNXPInvoke.CallBuiltIn(609);
    }

    /// <summary>
    ///  removes an item property from the specified item
    /// </summary>
    public static void RemoveItemProperty(uint oItem, IntPtr ipProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ipProperty);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(610);
    }

    /// <summary>
    ///  if the item property is valid this will return true
    /// </summary>
    public static int GetIsItemPropertyValid(IntPtr ipProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ipProperty);
      NWNXPInvoke.CallBuiltIn(611);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the first item property on an item
    /// </summary>
    public static IntPtr GetFirstItemProperty(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(612);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Will keep retrieving the next and the next item property on an Item,
    ///  will return an invalid item property when the list is empty.
    /// </summary>
    public static IntPtr GetNextItemProperty(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(613);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  will return the item property type (ie. holy avenger)
    /// </summary>
    public static int GetItemPropertyType(IntPtr ip)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.CallBuiltIn(614);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  will return the duration type of the item property
    /// </summary>
    public static int GetItemPropertyDurationType(IntPtr ip)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.CallBuiltIn(615);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns Item property ability bonus.  You need to specify an
    ///  ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
    ///  be a positive integer between 1 and 12.
    /// </summary>
    public static IntPtr ItemPropertyAbilityBonus(int nAbility, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nAbility);
      NWNXPInvoke.CallBuiltIn(616);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property AC bonus.  You need to specify the bonus.
    ///  The bonus should be a positive integer between 1 and 20. The modifier
    ///  type depends on the item it is being applied to.
    /// </summary>
    public static IntPtr ItemPropertyACBonus(int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.CallBuiltIn(617);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property AC bonus vs. alignment group.  An example of
    ///  an alignment group is Chaotic, or Good.  You need to specify the
    ///  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
    ///  The AC bonus should be an integer between 1 and 20.  The modifier
    ///  type depends on the item it is being applied to.
    /// </summary>
    public static IntPtr ItemPropertyACBonusVsAlign(int nAlignGroup, int nACBonus)
    {
      NWNXPInvoke.StackPushInteger(nACBonus);
      NWNXPInvoke.StackPushInteger(nAlignGroup);
      NWNXPInvoke.CallBuiltIn(618);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property AC bonus vs. Damage type (ie. piercing).  You
    ///  need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
    ///  AC bonus.  The AC bonus should be an integer between 1 and 20.  The
    ///  modifier type depends on the item it is being applied to.
    ///  NOTE: Only the first 3 damage types may be used here, the 3 basic
    ///        physical types.
    /// </summary>
    public static IntPtr ItemPropertyACBonusVsDmgType(int nDamageType, int nACBonus)
    {
      NWNXPInvoke.StackPushInteger(nACBonus);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(619);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property AC bonus vs. Racial group.  You need to specify
    ///  the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
    ///  bonus should be an integer between 1 and 20.  The modifier type depends
    ///  on the item it is being applied to.
    /// </summary>
    public static IntPtr ItemPropertyACBonusVsRace(int nRace, int nACBonus)
    {
      NWNXPInvoke.StackPushInteger(nACBonus);
      NWNXPInvoke.StackPushInteger(nRace);
      NWNXPInvoke.CallBuiltIn(620);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property AC bonus vs. Specific alignment.  You need to
    ///  specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
    ///  bonus.  The AC bonus should be an integer between 1 and 20.  The
    ///  modifier type depends on the item it is being applied to.
    /// </summary>
    public static IntPtr ItemPropertyACBonusVsSAlign(int nAlign, int nACBonus)
    {
      NWNXPInvoke.StackPushInteger(nACBonus);
      NWNXPInvoke.StackPushInteger(nAlign);
      NWNXPInvoke.CallBuiltIn(621);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Enhancement bonus.  You need to specify the
    ///  enhancement bonus.  The Enhancement bonus should be an integer between
    ///  1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyEnhancementBonus(int nEnhancementBonus)
    {
      NWNXPInvoke.StackPushInteger(nEnhancementBonus);
      NWNXPInvoke.CallBuiltIn(622);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Enhancement bonus vs. an Alignment group.  You
    ///  need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
    ///  and the enhancement bonus.  The Enhancement bonus should be an integer
    ///  between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyEnhancementBonusVsAlign(int nAlignGroup, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nAlignGroup);
      NWNXPInvoke.CallBuiltIn(623);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Enhancement bonus vs. Racial group.  You need
    ///  to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
    ///  enhancement bonus.  The enhancement bonus should be an integer between
    ///  1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyEnhancementBonusVsRace(int nRace, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nRace);
      NWNXPInvoke.CallBuiltIn(624);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Enhancement bonus vs. a specific alignment.  You
    ///  need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
    ///  enhancement bonus.  The enhancement bonus should be an integer between
    ///  1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyEnhancementBonusVsSAlign(int nAlign, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nAlign);
      NWNXPInvoke.CallBuiltIn(625);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Enhancment penalty.  You need to specify the
    ///  enhancement penalty.  The enhancement penalty should be a POSITIVE
    ///  integer between 1 and 5 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyEnhancementPenalty(int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.CallBuiltIn(626);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property weight reduction.  You need to specify the weight
    ///  reduction constant(IP_CONST_REDUCEDWEIGHT_*).
    /// </summary>
    public static IntPtr ItemPropertyWeightReduction(int nReduction)
    {
      NWNXPInvoke.StackPushInteger(nReduction);
      NWNXPInvoke.CallBuiltIn(627);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Bonus Feat.  You need to specify the the feat
    ///  constant(IP_CONST_FEAT_*).
    /// </summary>
    public static IntPtr ItemPropertyBonusFeat(int nFeat)
    {
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.CallBuiltIn(628);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Bonus level spell (Bonus spell of level).  You must
    ///  specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
    ///  spell casting class) and the level of the bonus spell.  The level of the
    ///  bonus spell should be an integer between 0 and 9.
    /// </summary>
    public static IntPtr ItemPropertyBonusLevelSpell(int nClass, int nSpellLevel)
    {
      NWNXPInvoke.StackPushInteger(nSpellLevel);
      NWNXPInvoke.StackPushInteger(nClass);
      NWNXPInvoke.CallBuiltIn(629);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Cast spell.  You must specify the spell constant
    ///  (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
    ///  NOTE: The number after the name of the spell in the constant is the level
    ///        at which the spell will be cast.  Sometimes there are multiple copies
    ///        of the same spell but they each are cast at a different level.  The higher
    ///        the level, the more cost will be added to the item.
    ///  NOTE: The list of spells that can be applied to an item will depend on the
    ///        item type.  For instance there are spells that can be applied to a wand
    ///        that cannot be applied to a potion.  Below is a list of the types and the
    ///        spells that are allowed to be placed on them.  If you try to put a cast
    ///        spell effect on an item that is not allowed to have that effect it will
    ///        not work.
    ///  NOTE: Even if spells have multiple versions of different levels they are only
    ///        listed below once.
    ///
    ///  WANDS:
    ///           Acid_Splash
    ///           Activate_Item
    ///           Aid
    ///           Amplify
    ///           Animate_Dead
    ///           AuraOfGlory
    ///           BalagarnsIronHorn
    ///           Bane
    ///           Banishment
    ///           Barkskin
    ///           Bestow_Curse
    ///           Bigbys_Clenched_Fist
    ///           Bigbys_Crushing_Hand
    ///           Bigbys_Forceful_Hand
    ///           Bigbys_Grasping_Hand
    ///           Bigbys_Interposing_Hand
    ///           Bless
    ///           Bless_Weapon
    ///           Blindness/Deafness
    ///           Blood_Frenzy
    ///           Bombardment
    ///           Bulls_Strength
    ///           Burning_Hands
    ///           Call_Lightning
    ///           Camoflage
    ///           Cats_Grace
    ///           Charm_Monster
    ///           Charm_Person
    ///           Charm_Person_or_Animal
    ///           Clairaudience/Clairvoyance
    ///           Clarity
    ///           Color_Spray
    ///           Confusion
    ///           Continual_Flame
    ///           Cure_Critical_Wounds
    ///           Cure_Light_Wounds
    ///           Cure_Minor_Wounds
    ///           Cure_Moderate_Wounds
    ///           Cure_Serious_Wounds
    ///           Darkness
    ///           Darkvision
    ///           Daze
    ///           Death_Ward
    ///           Dirge
    ///           Dismissal
    ///           Dispel_Magic
    ///           Displacement
    ///           Divine_Favor
    ///           Divine_Might
    ///           Divine_Power
    ///           Divine_Shield
    ///           Dominate_Animal
    ///           Dominate_Person
    ///           Doom
    ///           Dragon_Breath_Acid
    ///           Dragon_Breath_Cold
    ///           Dragon_Breath_Fear
    ///           Dragon_Breath_Fire
    ///           Dragon_Breath_Gas
    ///           Dragon_Breath_Lightning
    ///           Dragon_Breath_Paralyze
    ///           Dragon_Breath_Sleep
    ///           Dragon_Breath_Slow
    ///           Dragon_Breath_Weaken
    ///           Drown
    ///           Eagle_Spledor
    ///           Earthquake
    ///           Electric_Jolt
    ///           Elemental_Shield
    ///           Endurance
    ///           Endure_Elements
    ///           Enervation
    ///           Entangle
    ///           Entropic_Shield
    ///           Etherealness
    ///           Expeditious_Retreat
    ///           Fear
    ///           Find_Traps
    ///           Fireball
    ///           Firebrand
    ///           Flame_Arrow
    ///           Flame_Lash
    ///           Flame_Strike
    ///           Flare
    ///           Foxs_Cunning
    ///           Freedom_of_Movement
    ///           Ghostly_Visage
    ///           Ghoul_Touch
    ///           Grease
    ///           Greater_Magic_Fang
    ///           Greater_Magic_Weapon
    ///           Grenade_Acid
    ///           Grenade_Caltrops
    ///           Grenade_Chicken
    ///           Grenade_Choking
    ///           Grenade_Fire
    ///           Grenade_Holy
    ///           Grenade_Tangle
    ///           Grenade_Thunderstone
    ///           Gust_of_wind
    ///           Hammer_of_the_Gods
    ///           Haste
    ///           Hold_Animal
    ///           Hold_Monster
    ///           Hold_Person
    ///           Ice_Storm
    ///           Identify
    ///           Improved_Invisibility
    ///           Inferno
    ///           Inflict_Critical_Wounds
    ///           Inflict_Light_Wounds
    ///           Inflict_Minor_Wounds
    ///           Inflict_Moderate_Wounds
    ///           Inflict_Serious_Wounds
    ///           Invisibility
    ///           Invisibility_Purge
    ///           Invisibility_Sphere
    ///           Isaacs_Greater_Missile_Storm
    ///           Isaacs_Lesser_Missile_Storm
    ///           Knock
    ///           Lesser_Dispel
    ///           Lesser_Restoration
    ///           Lesser_Spell_Breach
    ///           Light
    ///           Lightning_Bolt
    ///           Mage_Armor
    ///           Magic_Circle_against_Alignment
    ///           Magic_Fang
    ///           Magic_Missile
    ///           Manipulate_Portal_Stone
    ///           Mass_Camoflage
    ///           Melfs_Acid_Arrow
    ///           Meteor_Swarm
    ///           Mind_Blank
    ///           Mind_Fog
    ///           Negative_Energy_Burst
    ///           Negative_Energy_Protection
    ///           Negative_Energy_Ray
    ///           Neutralize_Poison
    ///           One_With_The_Land
    ///           Owls_Insight
    ///           Owls_Wisdom
    ///           Phantasmal_Killer
    ///           Planar_Ally
    ///           Poison
    ///           Polymorph_Self
    ///           Prayer
    ///           Protection_from_Alignment
    ///           Protection_From_Elements
    ///           Quillfire
    ///           Ray_of_Enfeeblement
    ///           Ray_of_Frost
    ///           Remove_Blindness/Deafness
    ///           Remove_Curse
    ///           Remove_Disease
    ///           Remove_Fear
    ///           Remove_Paralysis
    ///           Resist_Elements
    ///           Resistance
    ///           Restoration
    ///           Sanctuary
    ///           Scare
    ///           Searing_Light
    ///           See_Invisibility
    ///           Shadow_Conjuration
    ///           Shield
    ///           Shield_of_Faith
    ///           Silence
    ///           Sleep
    ///           Slow
    ///           Sound_Burst
    ///           Spike_Growth
    ///           Stinking_Cloud
    ///           Stoneskin
    ///           Summon_Creature_I
    ///           Summon_Creature_I
    ///           Summon_Creature_II
    ///           Summon_Creature_III
    ///           Summon_Creature_IV
    ///           Sunburst
    ///           Tashas_Hideous_Laughter
    ///           True_Strike
    ///           Undeaths_Eternal_Foe
    ///           Unique_Power
    ///           Unique_Power_Self_Only
    ///           Vampiric_Touch
    ///           Virtue
    ///           Wall_of_Fire
    ///           Web
    ///           Wounding_Whispers
    ///
    ///  POTIONS:
    ///           Activate_Item
    ///           Aid
    ///           Amplify
    ///           AuraOfGlory
    ///           Bane
    ///           Barkskin
    ///           Barkskin
    ///           Barkskin
    ///           Bless
    ///           Bless_Weapon
    ///           Bless_Weapon
    ///           Blood_Frenzy
    ///           Bulls_Strength
    ///           Bulls_Strength
    ///           Bulls_Strength
    ///           Camoflage
    ///           Cats_Grace
    ///           Cats_Grace
    ///           Cats_Grace
    ///           Clairaudience/Clairvoyance
    ///           Clairaudience/Clairvoyance
    ///           Clairaudience/Clairvoyance
    ///           Clarity
    ///           Continual_Flame
    ///           Cure_Critical_Wounds
    ///           Cure_Critical_Wounds
    ///           Cure_Critical_Wounds
    ///           Cure_Light_Wounds
    ///           Cure_Light_Wounds
    ///           Cure_Minor_Wounds
    ///           Cure_Moderate_Wounds
    ///           Cure_Moderate_Wounds
    ///           Cure_Moderate_Wounds
    ///           Cure_Serious_Wounds
    ///           Cure_Serious_Wounds
    ///           Cure_Serious_Wounds
    ///           Darkness
    ///           Darkvision
    ///           Darkvision
    ///           Death_Ward
    ///           Dispel_Magic
    ///           Dispel_Magic
    ///           Displacement
    ///           Divine_Favor
    ///           Divine_Might
    ///           Divine_Power
    ///           Divine_Shield
    ///           Dragon_Breath_Acid
    ///           Dragon_Breath_Cold
    ///           Dragon_Breath_Fear
    ///           Dragon_Breath_Fire
    ///           Dragon_Breath_Gas
    ///           Dragon_Breath_Lightning
    ///           Dragon_Breath_Paralyze
    ///           Dragon_Breath_Sleep
    ///           Dragon_Breath_Slow
    ///           Dragon_Breath_Weaken
    ///           Eagle_Spledor
    ///           Eagle_Spledor
    ///           Eagle_Spledor
    ///           Elemental_Shield
    ///           Elemental_Shield
    ///           Endurance
    ///           Endurance
    ///           Endurance
    ///           Endure_Elements
    ///           Entropic_Shield
    ///           Ethereal_Visage
    ///           Ethereal_Visage
    ///           Etherealness
    ///           Expeditious_Retreat
    ///           Find_Traps
    ///           Foxs_Cunning
    ///           Foxs_Cunning
    ///           Foxs_Cunning
    ///           Freedom_of_Movement
    ///           Ghostly_Visage
    ///           Ghostly_Visage
    ///           Ghostly_Visage
    ///           Globe_of_Invulnerability
    ///           Greater_Bulls_Strength
    ///           Greater_Cats_Grace
    ///           Greater_Dispelling
    ///           Greater_Dispelling
    ///           Greater_Eagles_Splendor
    ///           Greater_Endurance
    ///           Greater_Foxs_Cunning
    ///           Greater_Magic_Weapon
    ///           Greater_Owls_Wisdom
    ///           Greater_Restoration
    ///           Greater_Spell_Mantle
    ///           Greater_Stoneskin
    ///           Grenade_Acid
    ///           Grenade_Caltrops
    ///           Grenade_Chicken
    ///           Grenade_Choking
    ///           Grenade_Fire
    ///           Grenade_Holy
    ///           Grenade_Tangle
    ///           Grenade_Thunderstone
    ///           Haste
    ///           Haste
    ///           Heal
    ///           Hold_Animal
    ///           Hold_Monster
    ///           Hold_Person
    ///           Identify
    ///           Invisibility
    ///           Lesser_Dispel
    ///           Lesser_Dispel
    ///           Lesser_Mind_Blank
    ///           Lesser_Restoration
    ///           Lesser_Spell_Mantle
    ///           Light
    ///           Light
    ///           Mage_Armor
    ///           Manipulate_Portal_Stone
    ///           Mass_Camoflage
    ///           Mind_Blank
    ///           Minor_Globe_of_Invulnerability
    ///           Minor_Globe_of_Invulnerability
    ///           Mordenkainens_Disjunction
    ///           Negative_Energy_Protection
    ///           Negative_Energy_Protection
    ///           Negative_Energy_Protection
    ///           Neutralize_Poison
    ///           One_With_The_Land
    ///           Owls_Insight
    ///           Owls_Wisdom
    ///           Owls_Wisdom
    ///           Owls_Wisdom
    ///           Polymorph_Self
    ///           Prayer
    ///           Premonition
    ///           Protection_From_Elements
    ///           Protection_From_Elements
    ///           Protection_from_Spells
    ///           Protection_from_Spells
    ///           Raise_Dead
    ///           Remove_Blindness/Deafness
    ///           Remove_Curse
    ///           Remove_Disease
    ///           Remove_Fear
    ///           Remove_Paralysis
    ///           Resist_Elements
    ///           Resist_Elements
    ///           Resistance
    ///           Resistance
    ///           Restoration
    ///           Resurrection
    ///           Rogues_Cunning
    ///           See_Invisibility
    ///           Shadow_Shield
    ///           Shapechange
    ///           Shield
    ///           Shield_of_Faith
    ///           Special_Alcohol_Beer
    ///           Special_Alcohol_Spirits
    ///           Special_Alcohol_Wine
    ///           Special_Herb_Belladonna
    ///           Special_Herb_Garlic
    ///           Spell_Mantle
    ///           Spell_Resistance
    ///           Spell_Resistance
    ///           Stoneskin
    ///           Tensers_Transformation
    ///           True_Seeing
    ///           True_Strike
    ///           Unique_Power
    ///           Unique_Power_Self_Only
    ///           Virtue
    ///
    ///  GENERAL USE (ie. everything else):
    ///           Just about every spell is useable by all the general use items so instead we
    ///           will only list the ones that are not allowed:
    ///           Special_Alcohol_Beer
    ///           Special_Alcohol_Spirits
    ///           Special_Alcohol_Wine
    ///
    /// </summary>
    public static IntPtr ItemPropertyCastSpell(int nSpell, int nNumUses)
    {
      NWNXPInvoke.StackPushInteger(nNumUses);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(630);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage bonus.  You must specify the damage type constant
    ///  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
    ///  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
    ///        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
    /// </summary>
    public static IntPtr ItemPropertyDamageBonus(int nDamageType, int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(631);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage bonus vs. Alignment groups.  You must specify the
    ///  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
    ///  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
    ///  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
    ///        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
    /// </summary>
    public static IntPtr ItemPropertyDamageBonusVsAlign(int nAlignGroup, int nDamageType, int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nAlignGroup);
      NWNXPInvoke.CallBuiltIn(632);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage bonus vs. specific race.  You must specify the
    ///  racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
    ///  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
    ///  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
    ///        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
    /// </summary>
    public static IntPtr ItemPropertyDamageBonusVsRace(int nRace, int nDamageType, int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nRace);
      NWNXPInvoke.CallBuiltIn(633);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage bonus vs. specific alignment.  You must specify the
    ///  specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
    ///  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
    ///  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
    ///        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
    /// </summary>
    public static IntPtr ItemPropertyDamageBonusVsSAlign(int nAlign, int nDamageType, int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.StackPushInteger(nAlign);
      NWNXPInvoke.CallBuiltIn(634);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage immunity.  You must specify the damage type constant
    ///  (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
    ///  constant(IP_CONST_DAMAGEIMMUNITY_*).
    ///  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
    ///        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
    /// </summary>
    public static IntPtr ItemPropertyDamageImmunity(int nDamageType, int nImmuneBonus)
    {
      NWNXPInvoke.StackPushInteger(nImmuneBonus);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(635);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage penalty.  You must specify the damage penalty.
    ///  The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyDamagePenalty(int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.CallBuiltIn(636);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage reduction.  You must specify the enhancment level
    ///  (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
    ///  and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
    ///  up if your weapon is not of high enough enhancement.
    /// </summary>
    public static IntPtr ItemPropertyDamageReduction(int nEnhancement, int nHPSoak)
    {
      NWNXPInvoke.StackPushInteger(nHPSoak);
      NWNXPInvoke.StackPushInteger(nEnhancement);
      NWNXPInvoke.CallBuiltIn(637);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage resistance.  You must specify the damage type
    ///  constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
    ///  (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
    /// </summary>
    public static IntPtr ItemPropertyDamageResistance(int nDamageType, int nHPResist)
    {
      NWNXPInvoke.StackPushInteger(nHPResist);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(638);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property damage vulnerability.  You must specify the damage type
    ///  constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
    ///  and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
    /// </summary>
    public static IntPtr ItemPropertyDamageVulnerability(int nDamageType, int nVulnerability)
    {
      NWNXPInvoke.StackPushInteger(nVulnerability);
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(639);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Return Item property Darkvision.
    /// </summary>
    public static IntPtr ItemPropertyDarkvision()
    {
      NWNXPInvoke.CallBuiltIn(640);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Return Item property decrease ability score.  You must specify the ability
    ///  constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
    ///  a POSITIVE integer between 1 and 10 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyDecreaseAbility(int nAbility, int nModifier)
    {
      NWNXPInvoke.StackPushInteger(nModifier);
      NWNXPInvoke.StackPushInteger(nAbility);
      NWNXPInvoke.CallBuiltIn(641);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property decrease Armor Class.  You must specify the armor
    ///  modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
    ///  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyDecreaseAC(int nModifierType, int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.StackPushInteger(nModifierType);
      NWNXPInvoke.CallBuiltIn(642);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property decrease skill.  You must specify the constant for the
    ///  skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
    ///  must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyDecreaseSkill(int nSkill, int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(643);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property container reduced weight.  This is used for special
    ///  containers that reduce the weight of the objects inside them.  You must
    ///  specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
    /// </summary>
    public static IntPtr ItemPropertyContainerReducedWeight(int nContainerType)
    {
      NWNXPInvoke.StackPushInteger(nContainerType);
      NWNXPInvoke.CallBuiltIn(644);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property extra melee damage type.  You must specify the extra
    ///  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
    ///  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
    ///        here.
    ///  NOTE: It is also only applicable to melee weapons.
    /// </summary>
    public static IntPtr ItemPropertyExtraMeleeDamageType(int nDamageType)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(645);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property extra ranged damage type.  You must specify the extra
    ///  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
    ///  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
    ///        here.
    ///  NOTE: It is also only applicable to ranged weapons.
    /// </summary>
    public static IntPtr ItemPropertyExtraRangeDamageType(int nDamageType)
    {
      NWNXPInvoke.StackPushInteger(nDamageType);
      NWNXPInvoke.CallBuiltIn(646);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property haste.
    /// </summary>
    public static IntPtr ItemPropertyHaste()
    {
      NWNXPInvoke.CallBuiltIn(647);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Holy Avenger.
    /// </summary>
    public static IntPtr ItemPropertyHolyAvenger()
    {
      NWNXPInvoke.CallBuiltIn(648);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property immunity to miscellaneous effects.  You must specify the
    ///  effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
    /// </summary>
    public static IntPtr ItemPropertyImmunityMisc(int nImmunityType)
    {
      NWNXPInvoke.StackPushInteger(nImmunityType);
      NWNXPInvoke.CallBuiltIn(649);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property improved evasion.
    /// </summary>
    public static IntPtr ItemPropertyImprovedEvasion()
    {
      NWNXPInvoke.CallBuiltIn(650);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property bonus spell resistance.  You must specify the bonus spell
    ///  resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
    /// </summary>
    public static IntPtr ItemPropertyBonusSpellResistance(int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.CallBuiltIn(651);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property saving throw bonus vs. a specific effect or damage type.
    ///  You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
    ///  applied to and the bonus that is be applied.  The bonus must be an integer
    ///  between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nBonusType);
      NWNXPInvoke.CallBuiltIn(652);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property saving throw bonus to the base type (ie. will, reflex,
    ///  fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
    ///  to which the user gets the bonus and the bonus that he/she will get.  The
    ///  bonus must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nBaseSaveType);
      NWNXPInvoke.CallBuiltIn(653);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property keen.  This means a critical threat range of 19-20 on a
    ///  weapon will be increased to 17-20 etc.
    /// </summary>
    public static IntPtr ItemPropertyKeen()
    {
      NWNXPInvoke.CallBuiltIn(654);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property light.  You must specify the intesity constant of the
    ///  light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
    ///  (IP_CONST_LIGHTCOLOR_*).
    /// </summary>
    public static IntPtr ItemPropertyLight(int nBrightness, int nColor)
    {
      NWNXPInvoke.StackPushInteger(nColor);
      NWNXPInvoke.StackPushInteger(nBrightness);
      NWNXPInvoke.CallBuiltIn(655);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Max range strength modification (ie. mighty).  You must
    ///  specify the maximum modifier for strength that is allowed on a ranged weapon.
    ///  The modifier must be a positive integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyMaxRangeStrengthMod(int nModifier)
    {
      NWNXPInvoke.StackPushInteger(nModifier);
      NWNXPInvoke.CallBuiltIn(656);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property no damage.  This means the weapon will do no damage in
    ///  combat.
    /// </summary>
    public static IntPtr ItemPropertyNoDamage()
    {
      NWNXPInvoke.CallBuiltIn(657);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property on hit -> do effect property.  You must specify the on
    ///  hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
    ///  Some of the item properties require a special parameter as well.  If the
    ///  property does not require one you may leave out the last one.  The list of
    ///  the ones with 3 parameters and what they are are as follows:
    ///       ABILITYDRAIN      :nSpecial is the ability it is to drain.
    ///                          constant(IP_CONST_ABILITY_*)
    ///       BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       CONFUSION         :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       DAZE              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       DISEASE           :nSpecial is the type of desease that will effect the victim.
    ///                          constant(DISEASE_*)
    ///       DOOM              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       FEAR              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       HOLD              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
    ///                          constant(IP_CONST_POISON_*)
    ///       SILENCE           :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       SLAYRACE          :nSpecial is the race that will be slain.
    ///                          constant(IP_CONST_RACIALTYPE_*)
    ///       SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
    ///                          constant(IP_CONST_ALIGNMENTGROUP_*)
    ///       SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
    ///                          constant(IP_CONST_ALIGNMENT_*)
    ///       SLEEP             :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       SLOW              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    ///       STUN              :nSpecial is the duration/percentage of effecting victim.
    ///                          constant(IP_CONST_ONHIT_DURATION_*)
    /// </summary>
    public static IntPtr ItemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial = 0)
    {
      NWNXPInvoke.StackPushInteger(nSpecial);
      NWNXPInvoke.StackPushInteger(nSaveDC);
      NWNXPInvoke.StackPushInteger(nProperty);
      NWNXPInvoke.CallBuiltIn(658);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property reduced saving throw vs. an effect or damage type.  You must
    ///  specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
    ///  penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
    ///  (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.StackPushInteger(nBaseSaveType);
      NWNXPInvoke.CallBuiltIn(659);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property reduced saving to base type.  You must specify the base
    ///  type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
    ///  to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
    ///  The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyReducedSavingThrow(int nBonusType, int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.StackPushInteger(nBonusType);
      NWNXPInvoke.CallBuiltIn(660);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property regeneration.  You must specify the regeneration amount.
    ///  The amount must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyRegeneration(int nRegenAmount)
    {
      NWNXPInvoke.StackPushInteger(nRegenAmount);
      NWNXPInvoke.CallBuiltIn(661);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property skill bonus.  You must specify the skill to which the user
    ///  will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
    ///  be an integer between 1 and 50.
    /// </summary>
    public static IntPtr ItemPropertySkillBonus(int nSkill, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.CallBuiltIn(662);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property spell immunity vs. specific spell.  You must specify the
    ///  spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
    /// </summary>
    public static IntPtr ItemPropertySpellImmunitySpecific(int nSpell)
    {
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(663);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property spell immunity vs. spell school.  You must specify the
    ///  school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
    /// </summary>
    public static IntPtr ItemPropertySpellImmunitySchool(int nSchool)
    {
      NWNXPInvoke.StackPushInteger(nSchool);
      NWNXPInvoke.CallBuiltIn(664);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Thieves tools.  You must specify the modifier you wish
    ///  the tools to have.  The modifier must be an integer between 1 and 12.
    /// </summary>
    public static IntPtr ItemPropertyThievesTools(int nModifier)
    {
      NWNXPInvoke.StackPushInteger(nModifier);
      NWNXPInvoke.CallBuiltIn(665);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
    ///  must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyAttackBonus(int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.CallBuiltIn(666);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Attack bonus vs. alignment group.  You must specify the
    ///  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
    ///  bonus must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyAttackBonusVsAlign(int nAlignGroup, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nAlignGroup);
      NWNXPInvoke.CallBuiltIn(667);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property attack bonus vs. racial group.  You must specify the
    ///  racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
    ///  must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyAttackBonusVsRace(int nRace, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nRace);
      NWNXPInvoke.CallBuiltIn(668);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property attack bonus vs. a specific alignment.  You must specify
    ///  the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
    ///  attack bonus.  The bonus must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus)
    {
      NWNXPInvoke.StackPushInteger(nBonus);
      NWNXPInvoke.StackPushInteger(nAlignment);
      NWNXPInvoke.CallBuiltIn(669);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property attack penalty.  You must specify the attack penalty.
    ///  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
    /// </summary>
    public static IntPtr ItemPropertyAttackPenalty(int nPenalty)
    {
      NWNXPInvoke.StackPushInteger(nPenalty);
      NWNXPInvoke.CallBuiltIn(670);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property unlimited ammo.  If you leave the parameter field blank
    ///  it will be just a normal bolt, arrow, or bullet.  However you may specify that
    ///  you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
    ///  bonus).  For this parmeter you use the constants beginning with:
    ///       (IP_CONST_UNLIMITEDAMMO_*).
    /// </summary>
    public static IntPtr ItemPropertyUnlimitedAmmo(int nAmmoDamage = IP_CONST_UNLIMITEDAMMO_BASIC)
    {
      NWNXPInvoke.StackPushInteger(nAmmoDamage);
      NWNXPInvoke.CallBuiltIn(671);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property limit use by alignment group.  You must specify the
    ///  alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
    /// </summary>
    public static IntPtr ItemPropertyLimitUseByAlign(int nAlignGroup)
    {
      NWNXPInvoke.StackPushInteger(nAlignGroup);
      NWNXPInvoke.CallBuiltIn(672);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property limit use by class.  You must specify the class(es) who
    ///  are able to use this item(IP_CONST_CLASS_*).
    /// </summary>
    public static IntPtr ItemPropertyLimitUseByClass(int nClass)
    {
      NWNXPInvoke.StackPushInteger(nClass);
      NWNXPInvoke.CallBuiltIn(673);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property limit use by race.  You must specify the race(s) who are
    ///  allowed to use this item(IP_CONST_RACIALTYPE_*).
    /// </summary>
    public static IntPtr ItemPropertyLimitUseByRace(int nRace)
    {
      NWNXPInvoke.StackPushInteger(nRace);
      NWNXPInvoke.CallBuiltIn(674);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property limit use by specific alignment.  You must specify the
    ///  alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
    /// </summary>
    public static IntPtr ItemPropertyLimitUseBySAlign(int nAlignment)
    {
      NWNXPInvoke.StackPushInteger(nAlignment);
      NWNXPInvoke.CallBuiltIn(675);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  replace this function it does nothing.
    /// </summary>
    public static IntPtr BadBadReplaceMeThisDoesNothing()
    {
      NWNXPInvoke.CallBuiltIn(676);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property vampiric regeneration.  You must specify the amount of
    ///  regeneration.  The regen amount must be an integer between 1 and 20.
    /// </summary>
    public static IntPtr ItemPropertyVampiricRegeneration(int nRegenAmount)
    {
      NWNXPInvoke.StackPushInteger(nRegenAmount);
      NWNXPInvoke.CallBuiltIn(677);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Trap.  You must specify the trap level constant
    ///  (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
    /// </summary>
    public static IntPtr ItemPropertyTrap(int nTrapLevel, int nTrapType)
    {
      NWNXPInvoke.StackPushInteger(nTrapType);
      NWNXPInvoke.StackPushInteger(nTrapLevel);
      NWNXPInvoke.CallBuiltIn(678);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property true seeing.
    /// </summary>
    public static IntPtr ItemPropertyTrueSeeing()
    {
      NWNXPInvoke.CallBuiltIn(679);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Monster on hit apply effect property.  You must specify
    ///  the property that you want applied on hit.  There are some properties that
    ///  require an additional special parameter to be specified.  The others that
    ///  don't require any additional parameter you may just put in the one.  The
    ///  special cases are as follows:
    ///       ABILITYDRAIN:nSpecial is the ability to drain.
    ///                    constant(IP_CONST_ABILITY_*)
    ///       DISEASE     :nSpecial is the disease that you want applied.
    ///                    constant(DISEASE_*)
    ///       LEVELDRAIN  :nSpecial is the number of levels that you want drained.
    ///                    integer between 1 and 5.
    ///       POISON      :nSpecial is the type of poison that will effect the victim.
    ///                    constant(IP_CONST_POISON_*)
    ///       WOUNDING    :nSpecial is the amount of wounding.
    ///                    integer between 1 and 5.
    ///  NOTE: Any that do not appear in the above list do not require the second
    ///        parameter.
    ///  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
    ///        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
    /// </summary>
    public static IntPtr ItemPropertyOnMonsterHitProperties(int nProperty, int nSpecial = 0)
    {
      NWNXPInvoke.StackPushInteger(nSpecial);
      NWNXPInvoke.StackPushInteger(nProperty);
      NWNXPInvoke.CallBuiltIn(680);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property turn resistance.  You must specify the resistance bonus.
    ///  The bonus must be an integer between 1 and 50.
    /// </summary>
    public static IntPtr ItemPropertyTurnResistance(int nModifier)
    {
      NWNXPInvoke.StackPushInteger(nModifier);
      NWNXPInvoke.CallBuiltIn(681);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Massive Critical.  You must specify the extra damage
    ///  constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
    /// </summary>
    public static IntPtr ItemPropertyMassiveCritical(int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.CallBuiltIn(682);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property free action.
    /// </summary>
    public static IntPtr ItemPropertyFreeAction()
    {
      NWNXPInvoke.CallBuiltIn(683);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property monster damage.  You must specify the amount of damage
    ///  the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
    ///  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
    ///        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
    /// </summary>
    public static IntPtr ItemPropertyMonsterDamage(int nDamage)
    {
      NWNXPInvoke.StackPushInteger(nDamage);
      NWNXPInvoke.CallBuiltIn(684);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property immunity to spell level.  You must specify the level of
    ///  which that and below the user will be immune.  The level must be an integer
    ///  between 1 and 9.  By putting in a 3 it will mean the user is immune to all
    ///  3rd level and lower spells.
    /// </summary>
    public static IntPtr ItemPropertyImmunityToSpellLevel(int nLevel)
    {
      NWNXPInvoke.StackPushInteger(nLevel);
      NWNXPInvoke.CallBuiltIn(685);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property special walk.  If no parameters are specified it will
    ///  automatically use the zombie walk.  This will apply the special walk animation
    ///  to the user.
    /// </summary>
    public static IntPtr ItemPropertySpecialWalk(int nWalkType = 0)
    {
      NWNXPInvoke.StackPushInteger(nWalkType);
      NWNXPInvoke.CallBuiltIn(686);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property healers kit.  You must specify the level of the kit.
    ///  The modifier must be an integer between 1 and 12.
    /// </summary>
    public static IntPtr ItemPropertyHealersKit(int nModifier)
    {
      NWNXPInvoke.StackPushInteger(nModifier);
      NWNXPInvoke.CallBuiltIn(687);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property weight increase.  You must specify the weight increase
    ///  constant(IP_CONST_WEIGHTINCREASE_*).
    /// </summary>
    public static IntPtr ItemPropertyWeightIncrease(int nWeight)
    {
      NWNXPInvoke.StackPushInteger(nWeight);
      NWNXPInvoke.CallBuiltIn(688);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************
    ///  Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
    ///  - oTarget: the creature using the skill
    ///  - nSkill: the skill being used
    ///  - nDifficulty: Difficulty class of skill
    /// </summary>
    public static int GetIsSkillSuccessful(uint oTarget, int nSkill, int nDifficulty)
    {
      NWNXPInvoke.StackPushInteger(nDifficulty);
      NWNXPInvoke.StackPushInteger(nSkill);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(689);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Creates an effect that inhibits spells
    ///  - nPercent - percentage of failure
    ///  - nSpellSchool - the school of spells affected.
    /// </summary>
    public static IntPtr EffectSpellFailure(int nPercent = 100, int nSpellSchool = SPELL_SCHOOL_GENERAL)
    {
      NWNXPInvoke.StackPushInteger(nSpellSchool);
      NWNXPInvoke.StackPushInteger(nPercent);
      NWNXPInvoke.CallBuiltIn(690);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Causes the object to instantly speak a translated string.
    ///  (not an action, not blocked when uncommandable)
    ///  - nStrRef: Reference of the string in the talk table
    ///  - nTalkVolume: TALKVOLUME_*
    /// </summary>
    public static void SpeakStringByStrRef(int nStrRef, int nTalkVolume = TALKVOLUME_TALK)
    {
      NWNXPInvoke.StackPushInteger(nTalkVolume);
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(691);
    }

    /// <summary>
    ///  Sets the given creature into cutscene mode.  This prevents the player from
    ///  using the GUI and camera controls.
    ///  - oCreature: creature in a cutscene
    ///  - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode
    ///  - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.
    ///                          FALSE to stop the user from interacting with the game world.
    ///  Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
    ///  SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
    ///  was when SetCutsceneMode(oPlayer, TRUE) was called.
    /// </summary>
    public static void SetCutsceneMode(uint oCreature, int nInCutscene = TRUE, int nLeftClickingEnabled = FALSE)
    {
      NWNXPInvoke.StackPushInteger(nLeftClickingEnabled);
      NWNXPInvoke.StackPushInteger(nInCutscene);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(692);
    }

    /// <summary>
    ///  Gets the last player character to cancel from a cutscene.
    /// </summary>
    public static uint GetLastPCToCancelCutscene()
    {
      NWNXPInvoke.CallBuiltIn(693);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Gets the length of the specified wavefile, in seconds
    ///  Only works for sounds used for dialog.
    /// </summary>
    public static float GetDialogSoundLength(int nStrRef)
    {
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(694);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Fades the screen for the given creature/player from black to regular screen
    ///  - oCreature: creature controlled by player that should fade from black
    /// </summary>
    public static void FadeFromBlack(uint oCreature, float fSpeed = FADE_SPEED_MEDIUM)
    {
      NWNXPInvoke.StackPushFloat(fSpeed);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(695);
    }

    /// <summary>
    ///  Fades the screen for the given creature/player from regular screen to black
    ///  - oCreature: creature controlled by player that should fade to black
    /// </summary>
    public static void FadeToBlack(uint oCreature, float fSpeed = FADE_SPEED_MEDIUM)
    {
      NWNXPInvoke.StackPushFloat(fSpeed);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(696);
    }

    /// <summary>
    ///  Removes any fading or black screen.
    ///  - oCreature: creature controlled by player that should be cleared
    /// </summary>
    public static void StopFade(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(697);
    }

    /// <summary>
    ///  Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
    ///  Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
    ///  - oCreature: creature controlled by player that should see black screen
    /// </summary>
    public static void BlackScreen(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(698);
    }

    /// <summary>
    ///  Returns the base attach bonus for the given creature.
    /// </summary>
    public static int GetBaseAttackBonus(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(699);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set a creature's immortality flag.
    ///  -oCreature: creature affected
    ///  -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
    ///              FALSE = creature is not immortal and is damaged normally.
    ///  This scripting command only works on Creature objects.
    /// </summary>
    public static void SetImmortal(uint oCreature, int bImmortal)
    {
      NWNXPInvoke.StackPushInteger(bImmortal);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(700);
    }

    /// <summary>
    ///  Open's this creature's inventory panel for this player
    ///  - oCreature: creature to view
    ///  - oPlayer: the owner of this creature will see the panel pop up
    ///  * DM's can view any creature's inventory
    ///  * Players can view their own inventory, or that of their henchman, familiar or animal companion
    /// </summary>
    public static void OpenInventory(uint oCreature, uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(701);
    }

    /// <summary>
    ///  Stores the current camera mode and position so that it can be restored (using
    ///  RestoreCameraFacing())
    /// </summary>
    public static void StoreCameraFacing()
    {
      NWNXPInvoke.CallBuiltIn(702);
    }

    /// <summary>
    ///  Restores the camera mode and position to what they were last time StoreCameraFacing
    ///  was called.  RestoreCameraFacing can only be called once, and must correspond to a
    ///  previous call to StoreCameraFacing.
    /// </summary>
    public static void RestoreCameraFacing()
    {
      NWNXPInvoke.CallBuiltIn(703);
    }

    /// <summary>
    ///  Levels up a creature using default settings.
    ///  If successfull it returns the level the creature now is, or 0 if it fails.
    ///  If you want to give them a different level (ie: Give a Fighter a level of Wizard)
    ///     you can specify that in the nClass.
    ///  However, if you specify a class to which the creature no package specified,
    ///    they will use the default package for that class for their levelup choices.
    ///    (ie: no Barbarian Savage/Wizard Divination combinations)
    ///  If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
    ///  if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
    /// </summary>
    public static int LevelUpHenchman(uint oCreature, int nClass = CLASS_TYPE_INVALID, int bReadyAllSpells = FALSE, int nPackage = PACKAGE_INVALID)
    {
      NWNXPInvoke.StackPushInteger(nPackage);
      NWNXPInvoke.StackPushInteger(bReadyAllSpells);
      NWNXPInvoke.StackPushInteger(nClass);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(704);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the droppable flag on an item
    ///  - oItem: the item to change
    ///  - bDroppable: TRUE or FALSE, whether the item should be droppable
    ///  Droppable items will appear on a creature's remains when the creature is killed.
    /// </summary>
    public static void SetDroppableFlag(uint oItem, int bDroppable)
    {
      NWNXPInvoke.StackPushInteger(bDroppable);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(705);
    }

    /// <summary>
    ///  Gets the weight of an item, or the total carried weight of a creature in tenths
    ///  of pounds (as per the baseitems.2da).
    ///  - oTarget: the item or creature for which the weight is needed
    /// </summary>
    public static int GetWeight(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(706);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the object that acquired the module item.  May be a creature, item, or placeable
    /// </summary>
    public static uint GetModuleItemAcquiredBy()
    {
      NWNXPInvoke.CallBuiltIn(707);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the immortal flag on a creature
    /// </summary>
    public static int GetImmortal(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(708);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Does a single attack on every hostile creature within 10ft. of the attacker
    ///  and determines damage accordingly.  If the attacker has a ranged weapon
    ///  equipped, this will have no effect.
    ///  ** NOTE ** This is meant to be called inside the spell script for whirlwind
    ///  attack, it is not meant to be used to queue up a new whirlwind attack.  To do
    ///  that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
    ///  - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be
    ///    displayed
    ///  - int bImproved: If TRUE, the improved version of whirlwind is used
    /// </summary>
    public static void DoWhirlwindAttack(int bDisplayFeedback = TRUE, int bImproved = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bImproved);
      NWNXPInvoke.StackPushInteger(bDisplayFeedback);
      NWNXPInvoke.CallBuiltIn(709);
    }

    /// <summary>
    ///  Gets a value from a 2DA file on the server and returns it as a string
    ///  avoid using this function in loops
    ///  - s2DA: the name of the 2da file, 16 chars max
    ///  - sColumn: the name of the column in the 2da
    ///  - nRow: the row in the 2da
    ///  * returns an empty string if file, row, or column not found
    /// </summary>
    public static string Get2DAString(string s2DA, string sColumn, int nRow)
    {
      NWNXPInvoke.StackPushInteger(nRow);
      NWNXPInvoke.StackPushString(sColumn);
      NWNXPInvoke.StackPushString(s2DA);
      NWNXPInvoke.CallBuiltIn(710);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
    ///  except that the observers get no saving throw
    /// </summary>
    public static IntPtr EffectEthereal()
    {
      NWNXPInvoke.CallBuiltIn(711);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Gets the current AI Level that the creature is running at.
    ///  Returns one of the following:
    ///  AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
    /// </summary>
    public static int GetAILevel(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(712);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the current AI Level of the creature to the value specified. Does not work on Players.
    ///  The game by default will choose an appropriate AI level for
    ///  creatures based on the circumstances that the creature is in.
    ///  Explicitly setting an AI level will over ride the game AI settings.
    ///  The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
    ///  AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.
    ///  AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
    ///  AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
    ///  AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
    ///  AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
    /// </summary>
    public static void SetAILevel(uint oTarget, int nAILevel)
    {
      NWNXPInvoke.StackPushInteger(nAILevel);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(713);
    }

    /// <summary>
    ///  This will return TRUE if the creature running the script is a familiar currently
    ///  possessed by his master.
    ///  returns FALSE if not or if the creature object is invalid
    /// </summary>
    public static int GetIsPossessedFamiliar(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(714);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  This will cause a Player Creature to unpossess his/her familiar.  It will work if run
    ///  on the player creature or the possessed familiar.  It does not work in conjunction with
    ///  any DM possession.
    /// </summary>
    public static void UnpossessFamiliar(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(715);
    }

    /// <summary>
    ///  This will return TRUE if the area is flagged as either interior or underground.
    /// </summary>
    public static int GetIsAreaInterior(uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(716);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Send a server message (szMessage) to the oPlayer.
    /// </summary>
    public static void SendMessageToPCByStrRef(uint oPlayer, int nStrRef)
    {
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(717);
    }

    /// <summary>
    ///  Increment the remaining uses per day for this creature by one.
    ///  Total number of feats per day can not exceed the maximum.
    ///  - oCreature: creature to modify
    ///  - nFeat: constant FEAT_*
    /// </summary>
    public static void IncrementRemainingFeatUses(uint oCreature, int nFeat)
    {
      NWNXPInvoke.StackPushInteger(nFeat);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(718);
    }

    /// <summary>
    ///  Force the character of the player specified to be exported to its respective directory
    ///  i.e. LocalVault/ServerVault/ etc.
    /// </summary>
    public static void ExportSingleCharacter(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(719);
    }

    /// <summary>
    ///  This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
    ///  if nRunAsAction is off then the sound is forced to play intantly.
    /// </summary>
    public static void PlaySoundByStrRef(int nStrRef, int nRunAsAction = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nRunAsAction);
      NWNXPInvoke.StackPushInteger(nStrRef);
      NWNXPInvoke.CallBuiltIn(720);
    }

    /// <summary>
    ///  Set the name of oCreature's sub race to sSubRace.
    /// </summary>
    public static void SetSubRace(uint oCreature, string sSubRace)
    {
      NWNXPInvoke.StackPushString(sSubRace);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(721);
    }

    /// <summary>
    ///  Set the name of oCreature's Deity to sDeity.
    /// </summary>
    public static void SetDeity(uint oCreature, string sDeity)
    {
      NWNXPInvoke.StackPushString(sDeity);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(722);
    }

    /// <summary>
    ///  Returns TRUE if the creature oCreature is currently possessed by a DM character.
    ///  Returns FALSE otherwise.
    ///  Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
    ///  To determine if oCreature is a DM character use GetIsDM()
    /// </summary>
    public static int GetIsDMPossessed(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(723);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the current weather conditions for the area oArea.
    ///    Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
    ///    Note: If called on an Interior area, this will always return WEATHER_CLEAR.
    /// </summary>
    public static int GetWeather(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(724);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
    ///  Returns AREA_INVALID, on an error.
    /// </summary>
    public static int GetIsAreaNatural(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(725);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
    ///  Returns AREA_INVALID, on an error.
    /// </summary>
    public static int GetIsAreaAboveGround(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(726);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Use this to get the item last equipped by a player character in OnPlayerEquipItem..
    /// </summary>
    public static uint GetPCItemLastEquipped()
    {
      NWNXPInvoke.CallBuiltIn(727);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this to get the player character who last equipped an item in OnPlayerEquipItem..
    /// </summary>
    public static uint GetPCItemLastEquippedBy()
    {
      NWNXPInvoke.CallBuiltIn(728);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
    /// </summary>
    public static uint GetPCItemLastUnequipped()
    {
      NWNXPInvoke.CallBuiltIn(729);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
    /// </summary>
    public static uint GetPCItemLastUnequippedBy()
    {
      NWNXPInvoke.CallBuiltIn(730);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Creates a new copy of an item, while making a single change to the appearance of the item.
    ///  Helmet models and simple items ignore iIndex.
    ///  iType                            iIndex                              iNewValue
    ///  ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
    ///  ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            1-4
    ///  ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
    ///  ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
    ///  ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-175 [1]
    ///
    ///  [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
    ///  desired, the following equation can be used for nIndex to achieve that:
    ///
    ///    ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
    ///
    ///  For example, to change the CLOTH1 channel of the torso, nIndex would be:
    ///
    ///    6 + (7 * 6) + 2 = 50
    ///
    ///  [1] When specifying per-part coloring, the value 255 is allowed and corresponds with the logical
    ///  function 'clear colour override', which clears the per-part override for that part.
    /// </summary>
    public static uint CopyItemAndModify(uint oItem, int nType, int nIndex, int nNewValue, int bCopyVars = FALSE)
    {
      NWNXPInvoke.StackPushInteger(bCopyVars);
      NWNXPInvoke.StackPushInteger(nNewValue);
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushInteger(nType);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(731);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Queries the current value of the appearance settings on an item. The parameters are
    ///  identical to those of CopyItemAndModify().
    /// </summary>
    public static int GetItemAppearance(uint oItem, int nType, int nIndex)
    {
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushInteger(nType);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(732);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Creates an item property that (when applied to a weapon item) causes a spell to be cast
    ///  when a successful strike is made, or (when applied to armor) is struck by an opponent.
    ///  - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
    /// </summary>
    public static IntPtr ItemPropertyOnHitCastSpell(int nSpell, int nLevel)
    {
      NWNXPInvoke.StackPushInteger(nLevel);
      NWNXPInvoke.StackPushInteger(nSpell);
      NWNXPInvoke.CallBuiltIn(733);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns the SubType number of the item property. See the 2DA files for value definitions.
    /// </summary>
    public static int GetItemPropertySubType(IntPtr iProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, iProperty);
      NWNXPInvoke.CallBuiltIn(734);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the status of ACTION_MODE_* modes on a creature.
    /// </summary>
    public static int GetActionMode(uint oCreature, int nMode)
    {
      NWNXPInvoke.StackPushInteger(nMode);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(735);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the status of modes ACTION_MODE_* on a creature.
    /// </summary>
    public static void SetActionMode(uint oCreature, int nMode, int nStatus)
    {
      NWNXPInvoke.StackPushInteger(nStatus);
      NWNXPInvoke.StackPushInteger(nMode);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(736);
    }

    /// <summary>
    ///  Returns the current arcane spell failure factor of a creature
    /// </summary>
    public static int GetArcaneSpellFailure(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(737);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Makes a player examine the object oExamine. This causes the examination
    ///  pop-up box to appear for the object specified.
    /// </summary>
    public static void ActionExamine(uint oExamine)
    {
      NWNXPInvoke.StackPushObject(oExamine);
      NWNXPInvoke.CallBuiltIn(738);
    }

    /// <summary>
    ///  Creates a visual effect (ITEM_VISUAL_*) that may be applied to
    ///  melee weapons only.
    /// </summary>
    public static IntPtr ItemPropertyVisualEffect(int nEffect)
    {
      NWNXPInvoke.StackPushInteger(nEffect);
      NWNXPInvoke.CallBuiltIn(739);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Sets the lootable state of a *living* NPC creature.
    ///  This function will *not* work on players or dead creatures.
    /// </summary>
    public static void SetLootable(uint oCreature, int bLootable)
    {
      NWNXPInvoke.StackPushInteger(bLootable);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(740);
    }

    /// <summary>
    ///  Returns the lootable state of a creature.
    /// </summary>
    public static int GetLootable(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(741);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the current movement rate factor
    ///  of the cutscene 'camera man'.
    ///  NOTE: This will be a value between 0.1, 2.0 (10%-200%)
    /// </summary>
    public static float GetCutsceneCameraMoveRate(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(742);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Sets the current movement rate factor for the cutscene
    ///  camera man.
    ///  NOTE: You can only set values between 0.1, 2.0 (10%-200%)
    /// </summary>
    public static void SetCutsceneCameraMoveRate(uint oCreature, float fRate)
    {
      NWNXPInvoke.StackPushFloat(fRate);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(743);
    }

    /// <summary>
    ///  Returns TRUE if the item is cursed and cannot be dropped
    /// </summary>
    public static int GetItemCursedFlag(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(744);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  When cursed, items cannot be dropped
    /// </summary>
    public static void SetItemCursedFlag(uint oItem, int nCursed)
    {
      NWNXPInvoke.StackPushInteger(nCursed);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(745);
    }

    /// <summary>
    ///  Sets the maximum number of henchmen
    /// </summary>
    public static void SetMaxHenchmen(int nNumHenchmen)
    {
      NWNXPInvoke.StackPushInteger(nNumHenchmen);
      NWNXPInvoke.CallBuiltIn(746);
    }

    /// <summary>
    ///  Gets the maximum number of henchmen
    /// </summary>
    public static int GetMaxHenchmen()
    {
      NWNXPInvoke.CallBuiltIn(747);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the associate type of the specified creature.
    ///  - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
    /// </summary>
    public static int GetAssociateType(uint oAssociate)
    {
      NWNXPInvoke.StackPushObject(oAssociate);
      NWNXPInvoke.CallBuiltIn(748);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the spell resistance of the specified creature.
    ///  - Returns 0 if the creature has no spell resistance or an invalid
    ///    creature is passed in.
    /// </summary>
    public static int GetSpellResistance(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(749);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Changes the current Day/Night cycle for this player to night
    ///  - oPlayer: which player to change the lighting for
    ///  - fTransitionTime: how long the transition should take
    /// </summary>
    public static void DayToNight(uint oPlayer, float fTransitionTime = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fTransitionTime);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(750);
    }

    /// <summary>
    ///  Changes the current Day/Night cycle for this player to daylight
    ///  - oPlayer: which player to change the lighting for
    ///  - fTransitionTime: how long the transition should take
    /// </summary>
    public static void NightToDay(uint oPlayer, float fTransitionTime = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fTransitionTime);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(751);
    }

    /// <summary>
    ///  Returns whether or not there is a direct line of sight
    ///  between the two objects. (Not blocked by any geometry).
    ///
    ///  PLEASE NOTE: This is an expensive function and may
    ///               degrade performance if used frequently.
    /// </summary>
    public static int LineOfSightObject(uint oSource, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oSource);
      NWNXPInvoke.CallBuiltIn(752);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns whether or not there is a direct line of sight
    ///  between the two vectors. (Not blocked by any geometry).
    ///
    ///  This function must be run on a valid object in the area
    ///  it will not work on the module or area.
    ///
    ///  PLEASE NOTE: This is an expensive function and may
    ///               degrade performance if used frequently.
    /// </summary>
    public static int LineOfSightVector(Vector3 vSource, Vector3 vTarget)
    {
      NWNXPInvoke.StackPushVector(vTarget);
      NWNXPInvoke.StackPushVector(vSource);
      NWNXPInvoke.CallBuiltIn(753);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the class that the spellcaster cast the
    ///  spell as.
    ///  - Returns CLASS_TYPE_INVALID if the caster has
    ///    no valid class (placeables, etc...)
    /// </summary>
    public static int GetLastSpellCastClass()
    {
      NWNXPInvoke.CallBuiltIn(754);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the number of base attacks for the specified
    ///  creatures. The range of values accepted are from
    ///  1 to 6
    ///  Note: This function does not work on Player Characters
    /// </summary>
    public static void SetBaseAttackBonus(int nBaseAttackBonus, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nBaseAttackBonus);
      NWNXPInvoke.CallBuiltIn(755);
    }

    /// <summary>
    ///  Restores the number of base attacks back to it's
    ///  original state.
    /// </summary>
    public static void RestoreBaseAttackBonus(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(756);
    }

    /// <summary>
    ///  Creates a cutscene ghost effect, this will allow creatures
    ///  to pathfind through other creatures without bumping into them
    ///  for the duration of the effect.
    /// </summary>
    public static IntPtr EffectCutsceneGhost()
    {
      NWNXPInvoke.CallBuiltIn(757);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Creates an item property that offsets the effect on arcane spell failure
    ///  that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
    /// </summary>
    public static IntPtr ItemPropertyArcaneSpellFailure(int nModLevel)
    {
      NWNXPInvoke.StackPushInteger(nModLevel);
      NWNXPInvoke.CallBuiltIn(758);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns the amount of gold a store currently has. -1 indicates it is not using gold.
    ///  -2 indicates the store could not be located.
    /// </summary>
    public static int GetStoreGold(uint oidStore)
    {
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(759);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the amount of gold a store has. -1 means the store does not use gold.
    /// </summary>
    public static void SetStoreGold(uint oidStore, int nGold)
    {
      NWNXPInvoke.StackPushInteger(nGold);
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(760);
    }

    /// <summary>
    ///  Gets the maximum amount a store will pay for any item. -1 means price unlimited.
    ///  -2 indicates the store could not be located.
    /// </summary>
    public static int GetStoreMaxBuyPrice(uint oidStore)
    {
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(761);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the maximum amount a store will pay for any item. -1 means price unlimited.
    /// </summary>
    public static void SetStoreMaxBuyPrice(uint oidStore, int nMaxBuy)
    {
      NWNXPInvoke.StackPushInteger(nMaxBuy);
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(762);
    }

    /// <summary>
    ///  Gets the amount a store charges for identifying an item. Default is 100. -1 means
    ///  the store will not identify items.
    ///  -2 indicates the store could not be located.
    /// </summary>
    public static int GetStoreIdentifyCost(uint oidStore)
    {
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(763);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the amount a store charges for identifying an item. Default is 100. -1 means
    ///  the store will not identify items.
    /// </summary>
    public static void SetStoreIdentifyCost(uint oidStore, int nCost)
    {
      NWNXPInvoke.StackPushInteger(nCost);
      NWNXPInvoke.StackPushObject(oidStore);
      NWNXPInvoke.CallBuiltIn(764);
    }

    /// <summary>
    ///  Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
    /// </summary>
    public static void SetCreatureAppearanceType(uint oCreature, int nAppearanceType)
    {
      NWNXPInvoke.StackPushInteger(nAppearanceType);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(765);
    }

    /// <summary>
    ///  Returns the default package selected for this creature to level up with
    ///  - returns PACKAGE_INVALID if error occurs
    /// </summary>
    public static int GetCreatureStartingPackage(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(766);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns an effect that when applied will paralyze the target's legs, rendering
    ///  them unable to walk but otherwise unpenalized. This effect cannot be resisted.
    /// </summary>
    public static IntPtr EffectCutsceneImmobilize()
    {
      NWNXPInvoke.CallBuiltIn(767);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Is this creature in the given subarea? (trigger, area of effect object, etc..)
    ///  This function will tell you if the creature has triggered an onEnter event,
    ///  not if it is physically within the space of the subarea
    /// </summary>
    public static int GetIsInSubArea(uint oCreature, uint oSubArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oSubArea);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(768);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the Cost Table number of the item property. See the 2DA files for value definitions.
    /// </summary>
    public static int GetItemPropertyCostTable(IntPtr iProp)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, iProp);
      NWNXPInvoke.CallBuiltIn(769);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the Cost Table value (index of the cost table) of the item property.
    ///  See the 2DA files for value definitions.
    /// </summary>
    public static int GetItemPropertyCostTableValue(IntPtr iProp)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, iProp);
      NWNXPInvoke.CallBuiltIn(770);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the Param1 number of the item property. See the 2DA files for value definitions.
    /// </summary>
    public static int GetItemPropertyParam1(IntPtr iProp)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, iProp);
      NWNXPInvoke.CallBuiltIn(771);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the Param1 value of the item property. See the 2DA files for value definitions.
    /// </summary>
    public static int GetItemPropertyParam1Value(IntPtr iProp)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, iProp);
      NWNXPInvoke.CallBuiltIn(772);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Is this creature able to be disarmed? (checks disarm flag on creature, and if
    ///  the creature actually has a weapon equipped in their right hand that is droppable)
    /// </summary>
    public static int GetIsCreatureDisarmable(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(773);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets whether this item is 'stolen' or not
    /// </summary>
    public static void SetStolenFlag(uint oItem, int nStolenFlag)
    {
      NWNXPInvoke.StackPushInteger(nStolenFlag);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(774);
    }

    /// <summary>
    ///  Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
    /// </summary>
    public static void ForceRest(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(775);
    }

    /// <summary>
    ///  Forces this player's camera to be set to this height. Setting this value to zero will
    ///  restore the camera to the racial default height.
    /// </summary>
    public static void SetCameraHeight(uint oPlayer, float fHeight = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fHeight);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(776);
    }

    /// <summary>
    ///  Changes the sky that is displayed in the specified area.
    ///  nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static void SetSkyBox(int nSkyBox, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nSkyBox);
      NWNXPInvoke.CallBuiltIn(777);
    }

    /// <summary>
    ///  Returns the creature's currently set PhenoType (body type).
    /// </summary>
    public static int GetPhenoType(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(778);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the creature's PhenoType (body type) to the type specified.
    ///  nPhenoType = PHENOTYPE_NORMAL
    ///  nPhenoType = PHENOTYPE_BIG
    ///  nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever
    ///  be used if you have specifically created your own custom content that
    ///  requires the use of a new PhenoType and you have specified the appropriate
    ///  custom PhenoType in your custom content.
    ///  SetPhenoType will only work on part based creature (i.e. the starting
    ///  default playable races).
    /// </summary>
    public static void SetPhenoType(int nPhenoType, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nPhenoType);
      NWNXPInvoke.CallBuiltIn(779);
    }

    /// <summary>
    ///  Sets the fog color in the area specified.
    ///  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
    ///  nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
    ///  The fog color can also be represented as a hex RGB number if specific color shades
    ///  are desired.
    ///  The format of a hex specified color would be 0xFFEEDD where
    ///  FF would represent the amount of red in the color
    ///  EE would represent the amount of green in the color
    ///  DD would represent the amount of blue in the color.
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static void SetFogColor(int nFogType, int nFogColor, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nFogColor);
      NWNXPInvoke.StackPushInteger(nFogType);
      NWNXPInvoke.CallBuiltIn(780);
    }

    /// <summary>
    ///  Gets the current cutscene state of the player specified by oCreature.
    ///  Returns TRUE if the player is in cutscene mode.
    ///  Returns FALSE if the player is not in cutscene mode, or on an error
    ///  (such as specifying a non creature object).
    /// </summary>
    public static int GetCutsceneMode(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(781);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the skybox that is currently displayed in the specified area.
    ///  Returns:
    ///      SKYBOX_* constant
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static int GetSkyBox(uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(782);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the fog color in the area specified.
    ///  nFogType specifies wether the Sun, or Moon fog type is returned.
    ///     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static int GetFogColor(int nFogType, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nFogType);
      NWNXPInvoke.CallBuiltIn(783);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the fog amount in the area specified.
    ///  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
    ///  nFogAmount = specifies the density that the fog is being set to.
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static void SetFogAmount(int nFogType, int nFogAmount, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nFogAmount);
      NWNXPInvoke.StackPushInteger(nFogType);
      NWNXPInvoke.CallBuiltIn(784);
    }

    /// <summary>
    ///  Gets the fog amount in the area specified.
    ///  nFogType = nFogType specifies wether the Sun, or Moon fog type is returned.
    ///     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
    ///  If no valid area (or object) is specified, it uses the area of caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static int GetFogAmount(int nFogType, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nFogType);
      NWNXPInvoke.CallBuiltIn(785);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  returns TRUE if the item CAN be pickpocketed
    /// </summary>
    public static int GetPickpocketableFlag(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(786);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the Pickpocketable flag on an item
    ///  - oItem: the item to change
    ///  - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.
    /// </summary>
    public static void SetPickpocketableFlag(uint oItem, int bPickpocketable)
    {
      NWNXPInvoke.StackPushInteger(bPickpocketable);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(787);
    }

    /// <summary>
    ///  returns the footstep type of the creature specified.
    ///  The footstep type determines what the creature's footsteps sound
    ///  like when ever they take a step.
    ///  returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
    ///  used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
    /// </summary>
    public static int GetFootstepType(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(788);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the footstep type of the creature specified.
    ///  Changing a creature's footstep type will change the sound that
    ///  its feet make when ever the creature makes takes a step.
    ///  By default a creature's footsteps are detemined by the appearance
    ///  type of the creature. SetFootstepType() allows you to make a
    ///  creature use a difference footstep type than it would use by default
    ///  for its given appearance.
    ///  - nFootstepType (FOOTSTEP_TYPE_*):
    ///       FOOTSTEP_TYPE_NORMAL
    ///       FOOTSTEP_TYPE_LARGE
    ///       FOOTSTEP_TYPE_DRAGON
    ///       FOOTSTEP_TYPE_SoFT
    ///       FOOTSTEP_TYPE_HOOF
    ///       FOOTSTEP_TYPE_HOOF_LARGE
    ///       FOOTSTEP_TYPE_BEETLE
    ///       FOOTSTEP_TYPE_SPIDER
    ///       FOOTSTEP_TYPE_SKELETON
    ///       FOOTSTEP_TYPE_LEATHER_WING
    ///       FOOTSTEP_TYPE_FEATHER_WING
    ///       FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.
    ///       FOOTSTEP_TYPE_NONE
    ///  - oCreature: the creature to change the footstep sound for.
    /// </summary>
    public static void SetFootstepType(int nFootstepType, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nFootstepType);
      NWNXPInvoke.CallBuiltIn(789);
    }

    /// <summary>
    ///  returns the Wing type of the creature specified.
    ///       CREATURE_WING_TYPE_NONE
    ///       CREATURE_WING_TYPE_DEMON
    ///       CREATURE_WING_TYPE_ANGEL
    ///       CREATURE_WING_TYPE_BAT
    ///       CREATURE_WING_TYPE_DRAGON
    ///       CREATURE_WING_TYPE_BUTTERFLY
    ///       CREATURE_WING_TYPE_BIRD
    ///  returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
    ///  if the creature has no wings, or if the creature can not have its
    ///  wing type changed in the toolset.
    /// </summary>
    public static int GetCreatureWingType(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(790);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the Wing type of the creature specified.
    ///  - nWingType (CREATURE_WING_TYPE_*)
    ///       CREATURE_WING_TYPE_NONE
    ///       CREATURE_WING_TYPE_DEMON
    ///       CREATURE_WING_TYPE_ANGEL
    ///       CREATURE_WING_TYPE_BAT
    ///       CREATURE_WING_TYPE_DRAGON
    ///       CREATURE_WING_TYPE_BUTTERFLY
    ///       CREATURE_WING_TYPE_BIRD
    ///  - oCreature: the creature to change the wing type for.
    ///  Note: Only two creature model types will support wings.
    ///  The MODELTYPE for the part based (playable races) 'P'
    ///  and MODELTYPE 'W'in the appearance.2da
    /// </summary>
    public static void SetCreatureWingType(int nWingType, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nWingType);
      NWNXPInvoke.CallBuiltIn(791);
    }

    /// <summary>
    ///  returns the model number being used for the body part and creature specified
    ///  The model number returned is for the body part when the creature is not wearing
    ///  armor (i.e. whether or not the creature is wearing armor does not affect
    ///  the return value).
    ///  Note: Only works on part based creatures, which is typically restricted to
    ///  the playable races (unless some new part based custom content has been
    ///  added to the module).
    ///
    ///  returns CREATURE_PART_INVALID if used on a non-creature object,
    ///  or if the creature does not use a part based model.
    ///
    ///  - nPart (CREATURE_PART_*)
    ///       CREATURE_PART_RIGHT_FOOT
    ///       CREATURE_PART_LEFT_FOOT
    ///       CREATURE_PART_RIGHT_SHIN
    ///       CREATURE_PART_LEFT_SHIN
    ///       CREATURE_PART_RIGHT_THIGH
    ///       CREATURE_PART_LEFT_THIGH
    ///       CREATURE_PART_PELVIS
    ///       CREATURE_PART_TORSO
    ///       CREATURE_PART_BELT
    ///       CREATURE_PART_NECK
    ///       CREATURE_PART_RIGHT_FOREARM
    ///       CREATURE_PART_LEFT_FOREARM
    ///       CREATURE_PART_RIGHT_BICEP
    ///       CREATURE_PART_LEFT_BICEP
    ///       CREATURE_PART_RIGHT_SHOULDER
    ///       CREATURE_PART_LEFT_SHOULDER
    ///       CREATURE_PART_RIGHT_HAND
    ///       CREATURE_PART_LEFT_HAND
    ///       CREATURE_PART_HEAD
    /// </summary>
    public static int GetCreatureBodyPart(int nPart, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nPart);
      NWNXPInvoke.CallBuiltIn(792);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the body part model to be used on the creature specified.
    ///  The model names for parts need to be in the following format:
    ///    p<m/f><race letter><phenotype>_<body part><model number>.mdl
    ///
    ///  - nPart (CREATURE_PART_*)
    ///       CREATURE_PART_RIGHT_FOOT
    ///       CREATURE_PART_LEFT_FOOT
    ///       CREATURE_PART_RIGHT_SHIN
    ///       CREATURE_PART_LEFT_SHIN
    ///       CREATURE_PART_RIGHT_THIGH
    ///       CREATURE_PART_LEFT_THIGH
    ///       CREATURE_PART_PELVIS
    ///       CREATURE_PART_TORSO
    ///       CREATURE_PART_BELT
    ///       CREATURE_PART_NECK
    ///       CREATURE_PART_RIGHT_FOREARM
    ///       CREATURE_PART_LEFT_FOREARM
    ///       CREATURE_PART_RIGHT_BICEP
    ///       CREATURE_PART_LEFT_BICEP
    ///       CREATURE_PART_RIGHT_SHOULDER
    ///       CREATURE_PART_LEFT_SHOULDER
    ///       CREATURE_PART_RIGHT_HAND
    ///       CREATURE_PART_LEFT_HAND
    ///       CREATURE_PART_HEAD
    ///  - nModelNumber: CREATURE_MODEL_TYPE_*
    ///       CREATURE_MODEL_TYPE_NONE
    ///       CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
    ///       CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
    ///       CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
    ///  - oCreature: the creature to change the body part for.
    ///  Note: Only part based creature appearance types are supported.
    ///  i.e. The model types for the playable races ('P') in the appearance.2da
    /// </summary>
    public static void SetCreatureBodyPart(int nPart, int nModelNumber, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nModelNumber);
      NWNXPInvoke.StackPushInteger(nPart);
      NWNXPInvoke.CallBuiltIn(793);
    }

    /// <summary>
    ///  returns the Tail type of the creature specified.
    ///       CREATURE_TAIL_TYPE_NONE
    ///       CREATURE_TAIL_TYPE_LIZARD
    ///       CREATURE_TAIL_TYPE_BONE
    ///       CREATURE_TAIL_TYPE_DEVIL
    ///  returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
    ///  if the creature has no Tail, or if the creature can not have its
    ///  Tail type changed in the toolset.
    /// </summary>
    public static int GetCreatureTailType(uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(794);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the Tail type of the creature specified.
    ///  - nTailType (CREATURE_TAIL_TYPE_*)
    ///       CREATURE_TAIL_TYPE_NONE
    ///       CREATURE_TAIL_TYPE_LIZARD
    ///       CREATURE_TAIL_TYPE_BONE
    ///       CREATURE_TAIL_TYPE_DEVIL
    ///  - oCreature: the creature to change the Tail type for.
    ///  Note: Only two creature model types will support Tails.
    ///  The MODELTYPE for the part based (playable) races 'P'
    ///  and MODELTYPE 'T'in the appearance.2da
    /// </summary>
    public static void SetCreatureTailType(int nTailType, uint oCreature = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.StackPushInteger(nTailType);
      NWNXPInvoke.CallBuiltIn(795);
    }

    /// <summary>
    ///  returns the Hardness of a Door or Placeable object.
    ///  - oObject: a door or placeable object.
    ///  returns -1 on an error or if used on an object that is
    ///  neither a door nor a placeable object.
    /// </summary>
    public static int GetHardness(uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(796);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the Hardness of a Door or Placeable object.
    ///  - nHardness: must be between 0 and 250.
    ///  - oObject: a door or placeable object.
    ///  Does nothing if used on an object that is neither
    ///  a door nor a placeable.
    /// </summary>
    public static void SetHardness(int nHardness, uint oObject = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushInteger(nHardness);
      NWNXPInvoke.CallBuiltIn(797);
    }

    /// <summary>
    ///  When set the object can not be opened unless the
    ///  opener possesses the required key. The key tag required
    ///  can be specified either in the toolset, or by using
    ///  the SetLockKeyTag() scripting command.
    ///  - oObject: a door, or placeable.
    ///  - nKeyRequired: TRUE/FALSE
    /// </summary>
    public static void SetLockKeyRequired(uint oObject, int nKeyRequired = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nKeyRequired);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(798);
    }

    /// <summary>
    ///  Set the key tag required to open object oObject.
    ///  This will only have an effect if the object is set to
    ///  "Key required to unlock or lock" either in the toolset
    ///  or by using the scripting command SetLockKeyRequired().
    ///  - oObject: a door, placeable or trigger.
    ///  - sNewKeyTag: the key tag required to open the locked object.
    /// </summary>
    public static void SetLockKeyTag(uint oObject, string sNewKeyTag)
    {
      NWNXPInvoke.StackPushString(sNewKeyTag);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(799);
    }

    /// <summary>
    ///  Sets whether or not the object can be locked.
    ///  - oObject: a door or placeable.
    ///  - nLockable: TRUE/FALSE
    /// </summary>
    public static void SetLockLockable(uint oObject, int nLockable = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nLockable);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(800);
    }

    /// <summary>
    ///  Sets the DC for unlocking the object.
    ///  - oObject: a door or placeable object.
    ///  - nNewUnlockDC: must be between 0 and 250.
    /// </summary>
    public static void SetLockUnlockDC(uint oObject, int nNewUnlockDC)
    {
      NWNXPInvoke.StackPushInteger(nNewUnlockDC);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(801);
    }

    /// <summary>
    ///  Sets the DC for locking the object.
    ///  - oObject: a door or placeable object.
    ///  - nNewLockDC: must be between 0 and 250.
    /// </summary>
    public static void SetLockLockDC(uint oObject, int nNewLockDC)
    {
      NWNXPInvoke.StackPushInteger(nNewLockDC);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(802);
    }

    /// <summary>
    ///  Sets whether or not the trapped object can be disarmed.
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nDisarmable: TRUE/FALSE
    /// </summary>
    public static void SetTrapDisarmable(uint oTrapObject, int nDisarmable = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nDisarmable);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(803);
    }

    /// <summary>
    ///  Sets whether or not the trapped object can be detected.
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nDetectable: TRUE/FALSE
    ///  Note: Setting a trapped object to not be detectable will
    ///  not make the trap disappear if it has already been detected.
    /// </summary>
    public static void SetTrapDetectable(uint oTrapObject, int nDetectable = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nDetectable);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(804);
    }

    /// <summary>
    ///  Sets whether or not the trap is a one-shot trap
    ///  (i.e. whether or not the trap resets itself after firing).
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nOneShot: TRUE/FALSE
    /// </summary>
    public static void SetTrapOneShot(uint oTrapObject, int nOneShot = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nOneShot);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(805);
    }

    /// <summary>
    ///  Set the tag of the key that will disarm oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static void SetTrapKeyTag(uint oTrapObject, string sKeyTag)
    {
      NWNXPInvoke.StackPushString(sKeyTag);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(806);
    }

    /// <summary>
    ///  Set the DC for disarming oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nDisarmDC: must be between 0 and 250.
    /// </summary>
    public static void SetTrapDisarmDC(uint oTrapObject, int nDisarmDC)
    {
      NWNXPInvoke.StackPushInteger(nDisarmDC);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(807);
    }

    /// <summary>
    ///  Set the DC for detecting oTrapObject.
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nDetectDC: must be between 0 and 250.
    /// </summary>
    public static void SetTrapDetectDC(uint oTrapObject, int nDetectDC)
    {
      NWNXPInvoke.StackPushInteger(nDetectDC);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(808);
    }

    /// <summary>
    ///  Creates a square Trap object.
    ///  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
    ///  - lLocation: The location and orientation that the trap will be created at.
    ///  - fSize: The size of the trap. Minimum size allowed is 1.0f.
    ///  - sTag: The tag of the trap being created.
    ///  - nFaction: The faction of the trap (STANDARD_FACTION_*).
    ///  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
    ///                     If "" no script will fire.
    ///  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
    ///                            trap is triggered.
    ///                            If "" the default OnTrapTriggered script for the trap
    ///                            type specified will fire instead (as specified in the
    ///                            traps.2da).
    /// </summary>
    public static uint CreateTrapAtLocation(int nTrapType, IntPtr lLocation, float fSize = 2.0f, string sTag = "", int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
    {
      NWNXPInvoke.StackPushString(sOnTrapTriggeredScript);
      NWNXPInvoke.StackPushString(sOnDisarmScript);
      NWNXPInvoke.StackPushInteger(nFaction);
      NWNXPInvoke.StackPushString(sTag);
      NWNXPInvoke.StackPushFloat(fSize);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lLocation);
      NWNXPInvoke.StackPushInteger(nTrapType);
      NWNXPInvoke.CallBuiltIn(809);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Creates a Trap on the object specified.
    ///  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
    ///  - oObject: The object that the trap will be created on. Works only on Doors and Placeables.
    ///  - nFaction: The faction of the trap (STANDARD_FACTION_*).
    ///  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
    ///                     If "" no script will fire.
    ///  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
    ///                            trap is triggered.
    ///                            If "" the default OnTrapTriggered script for the trap
    ///                            type specified will fire instead (as specified in the
    ///                            traps.2da).
    ///  Note: After creating a trap on an object, you can change the trap's properties
    ///        using the various SetTrap* scripting commands by passing in the object
    ///        that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
    /// </summary>
    public static void CreateTrapOnObject(int nTrapType, uint oObject, int nFaction = STANDARD_FACTION_HOSTILE, string sOnDisarmScript = "", string sOnTrapTriggeredScript = "")
    {
      NWNXPInvoke.StackPushString(sOnTrapTriggeredScript);
      NWNXPInvoke.StackPushString(sOnDisarmScript);
      NWNXPInvoke.StackPushInteger(nFaction);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushInteger(nTrapType);
      NWNXPInvoke.CallBuiltIn(810);
    }

    /// <summary>
    ///  Set the Will saving throw value of the Door or Placeable object oObject.
    ///  - oObject: a door or placeable object.
    ///  - nWillSave: must be between 0 and 250.
    /// </summary>
    public static void SetWillSavingThrow(uint oObject, int nWillSave)
    {
      NWNXPInvoke.StackPushInteger(nWillSave);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(811);
    }

    /// <summary>
    ///  Set the Reflex saving throw value of the Door or Placeable object oObject.
    ///  - oObject: a door or placeable object.
    ///  - nReflexSave: must be between 0 and 250.
    /// </summary>
    public static void SetReflexSavingThrow(uint oObject, int nReflexSave)
    {
      NWNXPInvoke.StackPushInteger(nReflexSave);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(812);
    }

    /// <summary>
    ///  Set the Fortitude saving throw value of the Door or Placeable object oObject.
    ///  - oObject: a door or placeable object.
    ///  - nFortitudeSave: must be between 0 and 250.
    /// </summary>
    public static void SetFortitudeSavingThrow(uint oObject, int nFortitudeSave)
    {
      NWNXPInvoke.StackPushInteger(nFortitudeSave);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(813);
    }

    /// <summary>
    ///  returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
    ///       TILESET_RESREF_BEHOLDER_CAVES
    ///       TILESET_RESREF_CASTLE_INTERIOR
    ///       TILESET_RESREF_CITY_EXTERIOR
    ///       TILESET_RESREF_CITY_INTERIOR
    ///       TILESET_RESREF_CRYPT
    ///       TILESET_RESREF_DESERT
    ///       TILESET_RESREF_DROW_INTERIOR
    ///       TILESET_RESREF_DUNGEON
    ///       TILESET_RESREF_FOREST
    ///       TILESET_RESREF_FROZEN_WASTES
    ///       TILESET_RESREF_ILLITHID_INTERIOR
    ///       TILESET_RESREF_MICROSET
    ///       TILESET_RESREF_MINES_AND_CAVERNS
    ///       TILESET_RESREF_RUINS
    ///       TILESET_RESREF_RURAL
    ///       TILESET_RESREF_RURAL_WINTER
    ///       TILESET_RESREF_SEWERS
    ///       TILESET_RESREF_UNDERDARK
    ///  * returns an empty string on an error.
    /// </summary>
    public static string GetTilesetResRef(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(814);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject can be recovered.
    /// </summary>
    public static int GetTrapRecoverable(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(815);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets whether or not the trapped object can be recovered.
    ///  - oTrapObject: a placeable, door or trigger
    /// </summary>
    public static void SetTrapRecoverable(uint oTrapObject, int nRecoverable = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nRecoverable);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(816);
    }

    /// <summary>
    ///  Get the XP scale being used for the module.
    /// </summary>
    public static int GetModuleXPScale()
    {
      NWNXPInvoke.CallBuiltIn(817);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the XP scale used by the module.
    ///  - nXPScale: The XP scale to be used. Must be between 0 and 200.
    /// </summary>
    public static void SetModuleXPScale(int nXPScale)
    {
      NWNXPInvoke.StackPushInteger(nXPScale);
      NWNXPInvoke.CallBuiltIn(818);
    }

    /// <summary>
    ///  Get the feedback message that will be displayed when trying to unlock the object oObject.
    ///  - oObject: a door or placeable.
    ///  Returns an empty string "" on an error or if the game's default feedback message is being used
    /// </summary>
    public static string GetKeyRequiredFeedback(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(819);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Set the feedback message that is displayed when trying to unlock the object oObject.
    ///  This will only have an effect if the object is set to
    ///  "Key required to unlock or lock" either in the toolset
    ///  or by using the scripting command SetLockKeyRequired().
    ///  - oObject: a door or placeable.
    ///  - sFeedbackMessage: the string to be displayed in the player's text window.
    ///                      to use the game's default message, set sFeedbackMessage to ""
    /// </summary>
    public static void SetKeyRequiredFeedback(uint oObject, string sFeedbackMessage)
    {
      NWNXPInvoke.StackPushString(sFeedbackMessage);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(820);
    }

    /// <summary>
    ///  - oTrapObject: a placeable, door or trigger
    ///  * Returns TRUE if oTrapObject is active
    /// </summary>
    public static int GetTrapActive(uint oTrapObject)
    {
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(821);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets whether or not the trap is an active trap
    ///  - oTrapObject: a placeable, door or trigger
    ///  - nActive: TRUE/FALSE
    ///  Notes:
    ///  Setting a trap as inactive will not make the
    ///  trap disappear if it has already been detected.
    ///  Call SetTrapDetectedBy() to make a detected trap disappear.
    ///  To make an inactive trap not detectable call SetTrapDetectable()
    /// </summary>
    public static void SetTrapActive(uint oTrapObject, int nActive = TRUE)
    {
      NWNXPInvoke.StackPushInteger(nActive);
      NWNXPInvoke.StackPushObject(oTrapObject);
      NWNXPInvoke.CallBuiltIn(822);
    }

    /// <summary>
    ///  Locks the player's camera pitch to its current pitch setting,
    ///  or unlocks the player's camera pitch.
    ///  Stops the player from tilting their camera angle.
    ///  - oPlayer: A player object.
    ///  - bLocked: TRUE/FALSE.
    /// </summary>
    public static void LockCameraPitch(uint oPlayer, int bLocked = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bLocked);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(823);
    }

    /// <summary>
    ///  Locks the player's camera distance to its current distance setting,
    ///  or unlocks the player's camera distance.
    ///  Stops the player from being able to zoom in/out the camera.
    ///  - oPlayer: A player object.
    ///  - bLocked: TRUE/FALSE.
    /// </summary>
    public static void LockCameraDistance(uint oPlayer, int bLocked = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bLocked);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(824);
    }

    /// <summary>
    ///  Locks the player's camera direction to its current direction,
    ///  or unlocks the player's camera direction to enable it to move
    ///  freely again.
    ///  Stops the player from being able to rotate the camera direction.
    ///  - oPlayer: A player object.
    ///  - bLocked: TRUE/FALSE.
    /// </summary>
    public static void LockCameraDirection(uint oPlayer, int bLocked = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bLocked);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(825);
    }

    /// <summary>
    ///  Get the last object that default clicked (left clicked) on the placeable object
    ///  that is calling this function.
    ///  Should only be called from a placeables OnClick event.
    ///  * Returns OBJECT_INVALID if it is called by something other than a placeable.
    /// </summary>
    public static uint GetPlaceableLastClickedBy()
    {
      NWNXPInvoke.CallBuiltIn(826);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  returns TRUE if the item is flagged as infinite.
    ///  - oItem: an item.
    ///  The infinite property affects the buying/selling behavior of the item in a store.
    ///  An infinite item will still be available to purchase from a store after a player
    ///  buys the item (non-infinite items will disappear from the store when purchased).
    /// </summary>
    public static int GetInfiniteFlag(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(827);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the Infinite flag on an item
    ///  - oItem: the item to change
    ///  - bInfinite: TRUE or FALSE, whether the item should be Infinite
    ///  The infinite property affects the buying/selling behavior of the item in a store.
    ///  An infinite item will still be available to purchase from a store after a player
    ///  buys the item (non-infinite items will disappear from the store when purchased).
    /// </summary>
    public static void SetInfiniteFlag(uint oItem, int bInfinite = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bInfinite);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(828);
    }

    /// <summary>
    ///  Gets the size of the area.
    ///  - nAreaDimension: The area dimension that you wish to determine.
    ///       AREA_HEIGHT
    ///       AREA_WIDTH
    ///  - oArea: The area that you wish to get the size of.
    ///  Returns: The number of tiles that the area is wide/high, or zero on an error.
    ///  If no valid area (or object) is specified, it uses the area of the caller.
    ///  If an object other than an area is specified, will use the area that the object is currently in.
    /// </summary>
    public static int GetAreaSize(int nAreaDimension, uint oArea = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.StackPushInteger(nAreaDimension);
      NWNXPInvoke.CallBuiltIn(829);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the name of oObject.
    ///  - oObject: the object for which you are changing the name (a creature, placeable, item, or door).
    ///  - sNewName: the new name that the object will use.
    ///  Note: SetName() does not work on player objects.
    ///        Setting an object's name to "" will make the object
    ///        revert to using the name it had originally before any
    ///        SetName() calls were made on the object.
    /// </summary>
    public static void SetName(uint oObject, string sNewName = "")
    {
      NWNXPInvoke.StackPushString(sNewName);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(830);
    }

    /// <summary>
    ///  Get the PortraitId of oTarget.
    ///  - oTarget: the object for which you are getting the portrait Id.
    ///  Returns: The Portrait Id number being used for the object oTarget.
    ///           The Portrait Id refers to the row number of the Portraits.2da
    ///           that this portrait is from.
    ///           If a custom portrait is being used, oTarget is a player object,
    ///           or on an error returns PORTRAIT_INVALID. In these instances
    ///           try using GetPortraitResRef() instead.
    /// </summary>
    public static int GetPortraitId(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(831);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Change the portrait of oTarget to use the Portrait Id specified.
    ///  - oTarget: the object for which you are changing the portrait.
    ///  - nPortraitId: The Id of the new portrait to use.
    ///                 nPortraitId refers to a row in the Portraits.2da
    ///  Note: Not all portrait Ids are suitable for use with all object types.
    ///        Setting the portrait Id will also cause the portrait ResRef
    ///        to be set to the appropriate portrait ResRef for the Id specified.
    /// </summary>
    public static void SetPortraitId(uint oTarget, int nPortraitId)
    {
      NWNXPInvoke.StackPushInteger(nPortraitId);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(832);
    }

    /// <summary>
    ///  Get the Portrait ResRef of oTarget.
    ///  - oTarget: the object for which you are getting the portrait ResRef.
    ///  Returns: The Portrait ResRef being used for the object oTarget.
    ///           The Portrait ResRef will not include a trailing size letter.
    /// </summary>
    public static string GetPortraitResRef(uint oTarget = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(833);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Change the portrait of oTarget to use the Portrait ResRef specified.
    ///  - oTarget: the object for which you are changing the portrait.
    ///  - sPortraitResRef: The ResRef of the new portrait to use.
    ///                     The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
    ///  Note: Not all portrait ResRefs are suitable for use with all object types.
    ///        Setting the portrait ResRef will also cause the portrait Id
    ///        to be set to PORTRAIT_INVALID.
    /// </summary>
    public static void SetPortraitResRef(uint oTarget, string sPortraitResRef)
    {
      NWNXPInvoke.StackPushString(sPortraitResRef);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.CallBuiltIn(834);
    }

    /// <summary>
    ///  Set oPlaceable's useable object status.
    ///  Note: Only works on non-static placeables.
    /// </summary>
    public static void SetUseableFlag(uint oPlaceable, int nUseableFlag)
    {
      NWNXPInvoke.StackPushInteger(nUseableFlag);
      NWNXPInvoke.StackPushObject(oPlaceable);
      NWNXPInvoke.CallBuiltIn(835);
    }

    /// <summary>
    ///  Get the description of oObject.
    ///  - oObject: the object from which you are obtaining the description.
    ///             Can be a creature, item, placeable, door, trigger or module object.
    ///  - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command
    ///                    is ignored and the original object's description is returned instead.
    ///  - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,
    ///                 setting this to FALSE will return the unidentified description. This flag has no
    ///                 effect on objects other than items.
    /// </summary>
    public static string GetDescription(uint oObject, int bOriginalDescription = FALSE, int bIdentifiedDescription = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bIdentifiedDescription);
      NWNXPInvoke.StackPushInteger(bOriginalDescription);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(836);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Set the description of oObject.
    ///  - oObject: the object for which you are changing the description
    ///             Can be a creature, placeable, item, door, or trigger.
    ///  - sNewDescription: the new description that the object will use.
    ///  - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,
    ///                 setting this to FALSE will set the unidentified description. This flag has no
    ///                 effect on objects other than items.
    ///  Note: Setting an object's description to "" will make the object
    ///        revert to using the description it originally had before any
    ///        SetDescription() calls were made on the object.
    /// </summary>
    public static void SetDescription(uint oObject, string sNewDescription = "", int bIdentifiedDescription = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bIdentifiedDescription);
      NWNXPInvoke.StackPushString(sNewDescription);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(837);
    }

    /// <summary>
    ///  Get the PC that sent the last player chat(text) message.
    ///  Should only be called from a module's OnPlayerChat event script.
    ///  * Returns OBJECT_INVALID on error.
    ///  Note: Private tells do not trigger a OnPlayerChat event.
    /// </summary>
    public static uint GetPCChatSpeaker()
    {
      NWNXPInvoke.CallBuiltIn(838);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Get the last player chat(text) message that was sent.
    ///  Should only be called from a module's OnPlayerChat event script.
    ///  * Returns empty string "" on error.
    ///  Note: Private tells do not trigger a OnPlayerChat event.
    /// </summary>
    public static string GetPCChatMessage()
    {
      NWNXPInvoke.CallBuiltIn(839);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Get the volume of the last player chat(text) message that was sent.
    ///  Returns one of the following TALKVOLUME_* constants based on the volume setting
    ///  that the player used to send the chat message.
    ///                 TALKVOLUME_TALK
    ///                 TALKVOLUME_WHISPER
    ///                 TALKVOLUME_SHOUT
    ///                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
    ///                 TALKVOLUME_PARTY
    ///  Should only be called from a module's OnPlayerChat event script.
    ///  * Returns -1 on error.
    ///  Note: Private tells do not trigger a OnPlayerChat event.
    /// </summary>
    public static int GetPCChatVolume()
    {
      NWNXPInvoke.CallBuiltIn(840);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the last player chat(text) message before it gets sent to other players.
    ///  - sNewChatMessage: The new chat text to be sent onto other players.
    ///                     Setting the player chat message to an empty string "",
    ///                     will cause the chat message to be discarded
    ///                     (i.e. it will not be sent to other players).
    ///  Note: The new chat message gets sent after the OnPlayerChat script exits.
    /// </summary>
    public static void SetPCChatMessage(string sNewChatMessage = "")
    {
      NWNXPInvoke.StackPushString(sNewChatMessage);
      NWNXPInvoke.CallBuiltIn(841);
    }

    /// <summary>
    ///  Set the last player chat(text) volume before it gets sent to other players.
    ///  - nTalkVolume: The new volume of the chat text to be sent onto other players.
    ///                 TALKVOLUME_TALK
    ///                 TALKVOLUME_WHISPER
    ///                 TALKVOLUME_SHOUT
    ///                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
    ///                 TALKVOLUME_PARTY
    ///                 TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
    ///  Note: The new chat message gets sent after the OnPlayerChat script exits.
    /// </summary>
    public static void SetPCChatVolume(int nTalkVolume = TALKVOLUME_TALK)
    {
      NWNXPInvoke.StackPushInteger(nTalkVolume);
      NWNXPInvoke.CallBuiltIn(842);
    }

    /// <summary>
    ///  Get the Color of oObject from the color channel specified.
    ///  - oObject: the object from which you are obtaining the color.
    ///             Can be a creature that has color information (i.e. the playable races).
    ///  - nColorChannel: The color channel that you want to get the color value of.
    ///                    COLOR_CHANNEL_SKIN
    ///                    COLOR_CHANNEL_HAIR
    ///                    COLOR_CHANNEL_TATTOO_1
    ///                    COLOR_CHANNEL_TATTOO_2
    ///  * Returns -1 on error.
    /// </summary>
    public static int GetColor(uint oObject, int nColorChannel)
    {
      NWNXPInvoke.StackPushInteger(nColorChannel);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(843);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Set the color channel of oObject to the color specified.
    ///  - oObject: the object for which you are changing the color.
    ///             Can be a creature that has color information (i.e. the playable races).
    ///  - nColorChannel: The color channel that you want to set the color value of.
    ///                    COLOR_CHANNEL_SKIN
    ///                    COLOR_CHANNEL_HAIR
    ///                    COLOR_CHANNEL_TATTOO_1
    ///                    COLOR_CHANNEL_TATTOO_2
    ///  - nColorValue: The color you want to set (0-175).
    /// </summary>
    public static void SetColor(uint oObject, int nColorChannel, int nColorValue)
    {
      NWNXPInvoke.StackPushInteger(nColorValue);
      NWNXPInvoke.StackPushInteger(nColorChannel);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(844);
    }

    /// <summary>
    ///  Returns Item property Material.  You need to specify the Material Type.
    ///  - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
    ///  Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
    /// </summary>
    public static IntPtr ItemPropertyMaterial(int nMaterialType)
    {
      NWNXPInvoke.StackPushInteger(nMaterialType);
      NWNXPInvoke.CallBuiltIn(845);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns Item property Quality. You need to specify the Quality.
    ///  - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).
    ///               IP_CONST_QUALITY_*
    ///  Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
    /// </summary>
    public static IntPtr ItemPropertyQuality(int nQuality)
    {
      NWNXPInvoke.StackPushInteger(nQuality);
      NWNXPInvoke.CallBuiltIn(846);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns a generic Additional Item property. You need to specify the Additional property.
    ///  - nProperty: The item property to create (see iprp_addcost.2da).
    ///               IP_CONST_ADDITIONAL_*
    ///  Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
    /// </summary>
    public static IntPtr ItemPropertyAdditional(int nAdditionalProperty)
    {
      NWNXPInvoke.StackPushInteger(nAdditionalProperty);
      NWNXPInvoke.CallBuiltIn(847);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Sets a new tag for oObject.
    ///  Will do nothing for invalid objects or the module object.
    ///
    ///  Note: Care needs to be taken with this function.
    ///        Changing the tag for creature with waypoints will make them stop walking them.
    ///        Changing waypoint, door or trigger tags will break their area transitions.
    /// </summary>
    public static void SetTag(uint oObject, string sNewTag)
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(848);
    }

    /// <summary>
    ///  Returns the string tag set for the provided effect.
    ///  - If no tag has been set, returns an empty string.
    /// </summary>
    public static string GetEffectTag(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(849);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Tags the effect with the provided string.
    ///  - Any other tags in the link will be overwritten.
    /// </summary>
    public static IntPtr TagEffect(IntPtr eEffect, string sNewTag)
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(850);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_EFFECT);
    }

    /// <summary>
    ///  Returns the caster level of the creature who created the effect.
    ///  - If not created by a creature, returns 0.
    ///  - If created by a spell-like ability, returns 0.
    /// </summary>
    public static int GetEffectCasterLevel(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(851);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the total duration of the effect in seconds.
    ///  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
    /// </summary>
    public static int GetEffectDuration(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(852);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the remaining duration of the effect in seconds.
    ///  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
    /// </summary>
    public static int GetEffectDurationRemaining(IntPtr eEffect)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_EFFECT, eEffect);
      NWNXPInvoke.CallBuiltIn(853);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the string tag set for the provided item property.
    ///  - If no tag has been set, returns an empty string.
    /// </summary>
    public static string GetItemPropertyTag(IntPtr nProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, nProperty);
      NWNXPInvoke.CallBuiltIn(854);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Tags the item property with the provided string.
    ///  - Any tags currently set on the item property will be overwritten.
    /// </summary>
    public static IntPtr TagItemProperty(IntPtr nProperty, string sNewTag)
    {
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, nProperty);
      NWNXPInvoke.CallBuiltIn(855);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY);
    }

    /// <summary>
    ///  Returns the total duration of the item property in seconds.
    ///  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
    /// </summary>
    public static int GetItemPropertyDuration(IntPtr nProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, nProperty);
      NWNXPInvoke.CallBuiltIn(856);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the remaining duration of the item property in seconds.
    ///  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
    /// </summary>
    public static int GetItemPropertyDurationRemaining(IntPtr nProperty)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, nProperty);
      NWNXPInvoke.CallBuiltIn(857);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Instances a new area from the given resref, which needs to be a existing module area.
    ///  Will optionally set a new area tag and displayed name. The new area is accessible
    ///  immediately, but initialisation scripts for the area and all contained creatures will only
    ///  run after the current script finishes (so you can clean up objects before returning).
    ///
    ///  Returns the new area, or OBJECT_INVALID on failure.
    ///
    ///  Note: When spawning a second instance of a existing area, you will have to manually
    ///        adjust all transitions (doors, triggers) with the relevant script commands,
    ///        or players might end up in the wrong area.
    /// </summary>
    public static uint CreateArea(string sResRef, string sNewTag = "", string sNewName = "")
    {
      NWNXPInvoke.StackPushString(sNewName);
      NWNXPInvoke.StackPushString(sNewTag);
      NWNXPInvoke.StackPushString(sResRef);
      NWNXPInvoke.CallBuiltIn(858);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Destroys the given area object and everything in it.
    ///
    ///  Return values:
    ///     0: Object not an area or invalid.
    ///    -1: Area contains spawn location and removal would leave module without entrypoint.
    ///    -2: Players in area.
    ///     1: Area destroyed successfully.
    /// </summary>
    public static int DestroyArea(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(859);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Creates a copy of a existing area, including everything inside of it (except players).
    ///
    ///  Returns the new area, or OBJECT_INVALID on error.
    ///
    ///  Note: You will have to manually adjust all transitions (doors, triggers) with the
    ///        relevant script commands, or players might end up in the wrong area.
    /// </summary>
    public static uint CopyArea(uint oArea)
    {
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(860);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Returns the first area in the module.
    /// </summary>
    public static uint GetFirstArea()
    {
      NWNXPInvoke.CallBuiltIn(861);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Returns the next area in the module (after GetFirstArea), or OBJECT_INVALID if no more
    ///  areas are loaded.
    /// </summary>
    public static uint GetNextArea()
    {
      NWNXPInvoke.CallBuiltIn(862);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    ///  Sets the transition target for oTransition.
    ///
    ///  Notes:
    ///  - oTransition can be any valid game object, except areas.
    ///  - oTarget can be any valid game object with a location, or OBJECT_INVALID (to unlink).
    ///  - Rebinding a transition will NOT change the other end of the transition; for example,
    ///    with normal doors you will have to do either end separately.
    ///  - Any valid game object can hold a transition target, but only some are used by the game engine
    ///    (doors and triggers). This might change in the future. You can still set and query them for
    ///    other game objects from nwscript.
    ///  - Transition target objects are cached: The toolset-configured destination tag is
    ///    used for a lookup only once, at first use. Thus, attempting to use SetTag() to change the
    ///    destination for a transition will not work in a predictable fashion.
    /// </summary>
    public static void SetTransitionTarget(uint oTransition, uint oTarget)
    {
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushObject(oTransition);
      NWNXPInvoke.CallBuiltIn(863);
    }

    /// <summary>
    ///  Sets whether the provided item should be hidden when equipped.
    ///  - The intended usage of this function is to provide an easy way to hide helmets, but it
    ///    can be used equally for any slot which has creature mesh visibility when equipped,
    ///    e.g.: armour, helm, cloak, left hand, and right hand.
    ///  - nValue should be TRUE or FALSE.
    /// </summary>
    public static void SetHiddenWhenEquipped(uint oItem, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(864);
    }

    /// <summary>
    ///  Returns whether the provided item is hidden when equipped.
    /// </summary>
    public static int GetHiddenWhenEquipped(uint oItem)
    {
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(865);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets if the given creature has explored tile at x, y of the given area.
    ///  Note that creature needs to be a player- or player-possessed creature.
    ///
    ///  Keep in mind that tile exploration also controls object visibility in areas
    ///  and the fog of war for interior and underground areas.
    ///
    ///  Return values:
    ///   -1: Area or creature invalid.
    ///    0: Tile was not explored before setting newState.
    ///    1: Tile was explored before setting newState.
    /// </summary>
    public static int SetTileExplored(uint creature, uint area, int x, int y, int newState)
    {
      NWNXPInvoke.StackPushInteger(newState);
      NWNXPInvoke.StackPushInteger(y);
      NWNXPInvoke.StackPushInteger(x);
      NWNXPInvoke.StackPushObject(area);
      NWNXPInvoke.StackPushObject(creature);
      NWNXPInvoke.CallBuiltIn(866);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns whether the given tile at x, y, for the given creature in the stated
    ///  area is visible on the map.
    ///  Note that creature needs to be a player- or player-possessed creature.
    ///
    ///  Keep in mind that tile exploration also controls object visibility in areas
    ///  and the fog of war for interior and underground areas.
    ///
    ///  Return values:
    ///   -1: Area or creature invalid.
    ///    0: Tile is not explored yet.
    ///    1: Tile is explored.
    /// </summary>
    public static int GetTileExplored(uint creature, uint area, int x, int y)
    {
      NWNXPInvoke.StackPushInteger(y);
      NWNXPInvoke.StackPushInteger(x);
      NWNXPInvoke.StackPushObject(area);
      NWNXPInvoke.StackPushObject(creature);
      NWNXPInvoke.CallBuiltIn(867);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the creature to auto-explore the map as it walks around.
    ///
    ///  Keep in mind that tile exploration also controls object visibility in areas
    ///  and the fog of war for interior and underground areas.
    ///
    ///  This means that if you turn off auto exploration, it falls to you to manage this
    ///  through SetTileExplored(); otherwise, the player will not be able to see anything.
    ///
    ///  Valid arguments: TRUE and FALSE.
    ///  Does nothing for non-creatures.
    ///  Returns the previous state (or -1 if non-creature).
    /// </summary>
    public static int SetCreatureExploresMinimap(uint creature, int newState)
    {
      NWNXPInvoke.StackPushInteger(newState);
      NWNXPInvoke.StackPushObject(creature);
      NWNXPInvoke.CallBuiltIn(868);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns TRUE if the creature is set to auto-explore the map as it walks around (on by default).
    ///  Returns FALSE if creature is not actually a creature.
    /// </summary>
    public static int GetCreatureExploresMinimap(uint creature)
    {
      NWNXPInvoke.StackPushObject(creature);
      NWNXPInvoke.CallBuiltIn(869);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Get the surface material at the given location. (This is
    ///  equivalent to the walkmesh type).
    ///  Returns 0 if the location is invalid or has no surface type.
    /// </summary>
    public static int GetSurfaceMaterial(IntPtr at)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, at);
      NWNXPInvoke.CallBuiltIn(870);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the z-offset at which the walkmesh is at the given location.
    ///  Returns -6.0 for invalid locations.
    /// </summary>
    public static float GetGroundHeight(IntPtr at)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, at);
      NWNXPInvoke.CallBuiltIn(871);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    ///  Gets the attack bonus limit.
    ///  - The default value is 20.
    /// </summary>
    public static int GetAttackBonusLimit()
    {
      NWNXPInvoke.CallBuiltIn(872);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the damage bonus limit.
    ///  - The default value is 100.
    /// </summary>
    public static int GetDamageBonusLimit()
    {
      NWNXPInvoke.CallBuiltIn(873);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the saving throw bonus limit.
    ///  - The default value is 20.
    /// </summary>
    public static int GetSavingThrowBonusLimit()
    {
      NWNXPInvoke.CallBuiltIn(874);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the ability bonus limit.
    ///  - The default value is 12.
    /// </summary>
    public static int GetAbilityBonusLimit()
    {
      NWNXPInvoke.CallBuiltIn(875);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the ability penalty limit.
    ///  - The default value is 30.
    /// </summary>
    public static int GetAbilityPenaltyLimit()
    {
      NWNXPInvoke.CallBuiltIn(876);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Gets the skill bonus limit.
    ///  - The default value is 50.
    /// </summary>
    public static int GetSkillBonusLimit()
    {
      NWNXPInvoke.CallBuiltIn(877);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Sets the attack bonus limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetAttackBonusLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(878);
    }

    /// <summary>
    ///  Sets the damage bonus limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetDamageBonusLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(879);
    }

    /// <summary>
    ///  Sets the saving throw bonus limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetSavingThrowBonusLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(880);
    }

    /// <summary>
    ///  Sets the ability bonus limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetAbilityBonusLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(881);
    }

    /// <summary>
    ///  Sets the ability penalty limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetAbilityPenaltyLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(882);
    }

    /// <summary>
    ///  Sets the skill bonus limit.
    ///  - The minimum value is 0.
    /// </summary>
    public static void SetSkillBonusLimit(int nNewLimit)
    {
      NWNXPInvoke.StackPushInteger(nNewLimit);
      NWNXPInvoke.CallBuiltIn(883);
    }

    /// <summary>
    ///  Get if oPlayer is currently connected over a relay (instead of directly).
    ///  Returns FALSE for any other object, including OBJECT_INVALID.
    /// </summary>
    public static int GetIsPlayerConnectionRelayed(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(884);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    ///  Returns the event script for the given object and handler.
    ///  Will return "" if unset, the object is invalid, or the object cannot
    ///  have the requested handler.
    /// </summary>
    public static string GetEventScript(uint oObject, int nHandler)
    {
      NWNXPInvoke.StackPushInteger(nHandler);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(885);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    ///  Sets the given event script for the given object and handler.
    ///  Returns 1 on success, 0 on failure.
    ///  Will fail if oObject is invalid or does not have the requested handler.
    /// </summary>
    public static int SetEventScript(uint oObject, int nHandler, string sScript)
    {
      NWNXPInvoke.StackPushString(sScript);
      NWNXPInvoke.StackPushInteger(nHandler);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(886);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Gets a visual transform on the given object.
    /// - oObject can be any valid Creature, Placeable, Item or Door.
    /// - nTransform is one of OBJECT_VISUAL_TRANSFORM_*
    /// Returns the current (or default) value.
    /// </summary>
    public static float GetObjectVisualTransform(uint oObject, int nTransform)
    {
      NWNXPInvoke.StackPushInteger(nTransform);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(887);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    /// Sets a visual transform on the given object.
    /// - oObject can be any valid Creature, Placeable, Item or Door.
    /// - nTransform is one of OBJECT_VISUAL_TRANSFORM_*
    /// - fValue depends on the transformation to apply.
    /// Returns the old/previous value.
    /// </summary>
    public static float SetObjectVisualTransform(uint oObject, int nTransform, float fValue)
    {
      NWNXPInvoke.StackPushFloat(fValue);
      NWNXPInvoke.StackPushInteger(nTransform);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(888);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    /// Sets an integer material shader uniform override.
    /// - sMaterial needs to be a material on that object.
    /// - sParam needs to be a valid shader parameter already defined on the material.
    /// </summary>
    public static void SetMaterialShaderUniformInt(uint oObject, string sMaterial, string sParam, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushString(sMaterial);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(889);
    }

    /// <summary>
    /// Sets a vec4 material shader uniform override.
    /// - sMaterial needs to be a material on that object.
    /// - sParam needs to be a valid shader parameter already defined on the material.
    /// - You can specify a single float value to set just a float, instead of a vec4.
    /// </summary>
    public static void SetMaterialShaderUniformVec4(uint oObject, string sMaterial, string sParam, float fValue1, float fValue2 = 0.0f, float fValue3 = 0.0f, float fValue4 = 0.0f)
    {
      NWNXPInvoke.StackPushFloat(fValue4);
      NWNXPInvoke.StackPushFloat(fValue3);
      NWNXPInvoke.StackPushFloat(fValue2);
      NWNXPInvoke.StackPushFloat(fValue1);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushString(sMaterial);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(890);
    }

    /// <summary>
    /// Resets material shader parameters on the given object:
    /// - Supply a material to only reset shader uniforms for meshes with that material.
    /// - Supply a parameter to only reset shader uniforms of that name.
    /// - Supply both to only reset shader uniforms of that name on meshes with that material.
    /// </summary>
    public static void ResetMaterialShaderUniforms(uint oObject, string sMaterial = "", string sParam = "")
    {
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushString(sMaterial);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(891);
    }

    /// <summary>
    /// Vibrate the player's device or controller. Does nothing if vibration is not supported.
    /// - nMotor is one of VIBRATOR_MOTOR_*
    /// - fStrength is between 0.0 and 1.0
    /// - fSeconds is the number of seconds to vibrate
    /// </summary>
    public static void Vibrate(uint oPlayer, int nMotor, float fStrength, float fSeconds)
    {
      NWNXPInvoke.StackPushFloat(fSeconds);
      NWNXPInvoke.StackPushFloat(fStrength);
      NWNXPInvoke.StackPushInteger(nMotor);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(892);
    }

    /// <summary>
    /// Unlock an achievement for the given player who must be logged in.
    /// - sId is the achievement ID on the remote server
    /// - nLastValue is the previous value of the associated achievement stat
    /// - nCurValue is the current value of the associated achievement stat
    /// - nMaxValue is the maximum value of the associate achievement stat
    /// </summary>
    public static void UnlockAchievement(uint oPlayer, string sId, int nLastValue=0, int nCurValue=0, int nMaxValue=0)
    {
      NWNXPInvoke.StackPushInteger(nMaxValue);
      NWNXPInvoke.StackPushInteger(nCurValue);
      NWNXPInvoke.StackPushInteger(nLastValue);
      NWNXPInvoke.StackPushString(sId);
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(893);
    }

    /// <summary>
    /// Execute a script chunk.
    /// The script chunk runs immediately, same as ExecuteScript().
    /// The script is jitted in place and currently not cached: Each invocation will recompile the script chunk.
    /// Note that the script chunk will run as if a separate script. This is not eval().
    /// By default, the script chunk is wrapped into void main() {}. Pass in bWrapIntoMain = FALSE to override.
    /// Returns "" on success, or the compilation error.
    /// </summary>
    public static string ExecuteScriptChunk(string sScriptChunk, uint oObject, int bWrapIntoMain = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bWrapIntoMain);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushString(sScriptChunk);
      NWNXPInvoke.CallBuiltIn(894);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Returns a UUID. This UUID will not be associated with any object.
    /// The generated UUID is currently a v4.
    /// </summary>
    public static string GetRandomUUID()
    {
      NWNXPInvoke.CallBuiltIn(895);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Returns the given objects' UUID. This UUID is persisted across save boundaries,
    /// like Save/RestoreCampaignObject and save games.
    ///
    /// Thus, reidentification is only guaranteed in scenarios where players cannot introduce
    /// new objects (i.e. servervault servers).
    ///
    /// UUIDs are guaranteed to be unique in any single running game.
    ///
    /// If a loaded object would collide with a UUID already present in the game, the
    /// object receives no UUID and a warning is emitted to the log. Requesting a UUID
    /// for the new object will generate a random one.
    ///
    /// This UUID is useful to, for example:
    /// - Safely identify servervault characters
    /// - Track serialisable objects (like items or creatures) as they are saved to the
    ///   campaign DB - i.e. persistent storage chests or dropped items.
    /// - Track objects across multiple game instances (in trusted scenarios).
    ///
    /// Currently, the following objects can carry UUIDs:
    ///   Items, Creatures, Placeables, Triggers, Doors, Waypoints, Stores,
    ///   Encounters, Areas.
    ///
    /// Will return "" (empty string) when the given object cannot carry a UUID.
    /// </summary>
    public static string GetObjectUUID(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(896);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Forces the given object to receive a new UUID, discarding the current value.
    /// </summary>
    public static void ForceRefreshObjectUUID(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(897);
    }

    /// <summary>
    /// Looks up a object on the server by it's UUID.
    /// Returns OBJECT_INVALID if the UUID is not on the server.
    /// </summary>
    public static uint GetObjectByUUID(string sUUID)
    {
      NWNXPInvoke.StackPushString(sUUID);
      NWNXPInvoke.CallBuiltIn(898);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    /// Do not call. This does nothing on this platform except to return an error.
    /// </summary>
    public static void Reserved899()
    {
      NWNXPInvoke.CallBuiltIn(899);
    }

    /// <summary>
    /// Makes oPC load texture sNewName instead of sOldName.
    /// If oPC is OBJECT_INVALID, it will apply the override to all active players
    /// Setting sNewName to "" will clear the override and revert to original.
    /// </summary>
    public static void SetTextureOverride(string sOldName, string sNewName = "", uint oPC = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.StackPushString(sNewName);
      NWNXPInvoke.StackPushString(sOldName);
      NWNXPInvoke.CallBuiltIn(900);
    }

    /// <summary>
    /// Displays sMsg on oPC's screen.
    /// The message is displayed on top of whatever is on the screen, including UI elements
    ///  nX, nY - coordinates of the first character to be displayed. The value is in terms
    ///           of character 'slot' relative to the nAnchor anchor point.
    ///           If the number is negative, it is applied from the bottom/right.
    ///  nAnchor - SCREEN_ANCHOR_* constant
    ///  fLife - Duration in seconds until the string disappears.
    ///  nRGBA, nRGBA2 - Colors of the string in 0xRRGGBBAA format. String starts at nRGBA,
    ///                  but as it nears end of life, it will slowly blend into nRGBA2.
    ///  nID - Optional ID of a string. If not 0, subsequent calls to PostString will
    ///        remove the old string with the same ID, even if it's lifetime has not elapsed.
    ///        Only positive values are allowed.
    ///  sFont - If specified, use this custom font instead of default console font.
    /// </summary>
    public static void PostString(uint oPC, string sMsg, int nX = 0, int nY = 0, int nAnchor = SCREEN_ANCHOR_TOP_LEFT, float fLife = 10.0f, int nRGBA = 2147418367, int nRGBA2 = 2147418367, int nID = 0, string sFont = "")
    {
      NWNXPInvoke.StackPushString(sFont);
      NWNXPInvoke.StackPushInteger(nID);
      NWNXPInvoke.StackPushInteger(nRGBA2);
      NWNXPInvoke.StackPushInteger(nRGBA);
      NWNXPInvoke.StackPushFloat(fLife);
      NWNXPInvoke.StackPushInteger(nAnchor);
      NWNXPInvoke.StackPushInteger(nY);
      NWNXPInvoke.StackPushInteger(nX);
      NWNXPInvoke.StackPushString(sMsg);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(901);
    }

    /// <summary>
    /// Returns oCreature's spell school specialization in nClass (SPELL_SCHOOL_* constants)
    /// Unless custom content is used, only Wizards have spell schools
    /// Returns -1 on error
    /// </summary>
    public static int GetSpecialization(uint oCreature, int nClass = CLASS_TYPE_WIZARD)
    {
      NWNXPInvoke.StackPushInteger(nClass);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(902);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Returns oCreature's domain in nClass (DOMAIN_* constants)
    /// nDomainIndex - 1 or 2
    /// Unless custom content is used, only Clerics have domains
    /// Returns -1 on error
    /// </summary>
    public static int GetDomain(uint oCreature, int nDomainIndex = 1, int nClass = CLASS_TYPE_CLERIC)
    {
      NWNXPInvoke.StackPushInteger(nClass);
      NWNXPInvoke.StackPushInteger(nDomainIndex);
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(903);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Returns the build number of oPlayer (i.e. 8193).
    /// Returns 0 if the given object isn't a player or did not advertise their build info.
    /// </summary>
    public static int GetPlayerBuildVersionMajor(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(904);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Returns the patch revision of oPlayer (i.e. 8).
    /// Returns 0 if the given object isn't a player or did not advertise their build info.
    /// </summary>
    public static int GetPlayerBuildVersionMinor(uint oPlayer)
    {
      NWNXPInvoke.StackPushObject(oPlayer);
      NWNXPInvoke.CallBuiltIn(905);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Returns the script parameter value for a given parameter name.
    /// Script parameters can be set for conversation scripts in the toolset's
    /// Conversation Editor, or for any script with SetScriptParam().
    /// * Will return "" if a parameter with the given name does not exist.
    /// </summary>
    public static string GetScriptParam(string sParamName)
    {
      NWNXPInvoke.StackPushString(sParamName);
      NWNXPInvoke.CallBuiltIn(906);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Set a script parameter value for the next script to be run.
    /// Call this function to set parameters right before calling ExecuteScript().
    /// </summary>
    public static void SetScriptParam(string sParamName, string sParamValue)
    {
      NWNXPInvoke.StackPushString(sParamValue);
      NWNXPInvoke.StackPushString(sParamName);
      NWNXPInvoke.CallBuiltIn(907);
    }

    /// <summary>
    /// Returns the number of uses per day remaining of the given item and item property.
    /// * Will return 0 if the given item does not have the requested item property,
    ///   or the item property is not uses/day.
    /// </summary>
    public static int GetItemPropertyUsesPerDayRemaining(uint oItem, IntPtr ip)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(908);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Sets the number of uses per day remaining of the given item and item property.
    /// * Will do nothing if the given item and item property is not uses/day.
    /// * Will constrain nUsesPerDay to the maximum allowed as the cost table defines.
    /// </summary>
    public static void SetItemPropertyUsesPerDayRemaining(uint oItem, IntPtr ip, int nUsesPerDay)
    {
      NWNXPInvoke.StackPushInteger(nUsesPerDay);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(909);
    }

    /// <summary>
    /// Queue an action to use an active item property.
    /// * oItem - item that has the item property to use
    /// * ip - item property to use
    /// * object oTarget - target
    /// * nSubPropertyIndex - specify if your itemproperty has subproperties (such as subradial spells)
    /// * bDecrementCharges - decrement charges if item property is limited
    /// </summary>
    public static void ActionUseItemOnObject(uint oItem, IntPtr ip, uint oTarget, int nSubPropertyIndex = 0, int bDecrementCharges = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bDecrementCharges);
      NWNXPInvoke.StackPushInteger(nSubPropertyIndex);
      NWNXPInvoke.StackPushObject(oTarget);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(910);
    }

    /// <summary>
    /// Queue an action to use an active item property.
    /// * oItem - item that has the item property to use
    /// * ip - item property to use
    /// * location lTarget - target location (must be in the same area as item possessor)
    /// * nSubPropertyIndex - specify if your itemproperty has subproperties (such as subradial spells)
    /// * bDecrementCharges - decrement charges if item property is limited
    /// </summary>
    public static void ActionUseItemAtLocation(uint oItem, IntPtr ip, IntPtr lTarget, int nSubPropertyIndex = 0, int bDecrementCharges = TRUE)
    {
      NWNXPInvoke.StackPushInteger(bDecrementCharges);
      NWNXPInvoke.StackPushInteger(nSubPropertyIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lTarget);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_ITEM_PROPERTY, ip);
      NWNXPInvoke.StackPushObject(oItem);
      NWNXPInvoke.CallBuiltIn(911);
    }

    /// <summary>
    /// Makes oPC enter a targeting mode, letting them select an object as a target
    /// If a PC selects a target, it will trigger the module OnPlayerTarget event.
    /// </summary>
    public static void EnterTargetingMode(uint oPC, int nValidObjectTypes = OBJECT_TYPE_ALL, int nMouseCursorId = MOUSECURSOR_MAGIC, int nBadTargetCursor = MOUSECURSOR_NOMAGIC)
    {
      NWNXPInvoke.StackPushInteger(nBadTargetCursor);
      NWNXPInvoke.StackPushInteger(nMouseCursorId);
      NWNXPInvoke.StackPushInteger(nValidObjectTypes);
      NWNXPInvoke.StackPushObject(oPC);
      NWNXPInvoke.CallBuiltIn(912);
    }

    /// <summary>
    /// Gets the target object in the module OnPlayerTarget event.
    /// Returns the area object when the target is the ground.
    /// </summary>
    public static uint GetTargetingModeSelectedObject()
    {
      NWNXPInvoke.CallBuiltIn(913);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    /// Gets the target position in the module OnPlayerTarget event.
    /// </summary>
    public static Vector3 GetTargetingModeSelectedPosition()
    {
      NWNXPInvoke.CallBuiltIn(914);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    /// Gets the player object that triggered the OnPlayerTarget event.
    /// </summary>
    public static uint GetLastPlayerToSelectTarget()
    {
      NWNXPInvoke.CallBuiltIn(915);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    /// Sets oObject's hilite color to nColor
    /// The nColor format is 0xRRGGBB; -1 clears the color override.
    /// </summary>
    public static void SetObjectHiliteColor(uint oObject, int nColor = -1)
    {
      NWNXPInvoke.StackPushInteger(nColor);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(916);
    }

    /// <summary>
    /// Sets the cursor (MOUSECURSOR_*) to use when hovering over oObject
    /// </summary>
    public static void SetObjectMouseCursor(uint oObject, int nCursor = -1)
    {
      NWNXPInvoke.StackPushInteger(nCursor);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(917);
    }

    /// <summary>
    /// Returns TRUE if the given player-controlled creature has DM privileges
    /// gained through a player login (as opposed to the DM client).
    /// Note: GetIsDM() also returns TRUE for player creature DMs.
    /// </summary>
    public static int GetIsPlayerDM(uint oCreature)
    {
      NWNXPInvoke.StackPushObject(oCreature);
      NWNXPInvoke.CallBuiltIn(918);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Sets the detailed wind data for oArea
    /// The predefined values in the toolset are:
    ///   NONE:  vDirection=(1.0, 1.0, 0.0), fMagnitude=0.0, fYaw=0.0,   fPitch=0.0
    ///   LIGHT: vDirection=(1.0, 1.0, 0.0), fMagnitude=1.0, fYaw=100.0, fPitch=3.0
    ///   HEAVY: vDirection=(1.0, 1.0, 0.0), fMagnitude=2.0, fYaw=150.0, fPitch=5.0
    /// </summary>
    public static void SetAreaWind(uint oArea, Vector3 vDirection, float fMagnitude, float fYaw, float fPitch)
    {
      NWNXPInvoke.StackPushFloat(fPitch);
      NWNXPInvoke.StackPushFloat(fYaw);
      NWNXPInvoke.StackPushFloat(fMagnitude);
      NWNXPInvoke.StackPushVector(vDirection);
      NWNXPInvoke.StackPushObject(oArea);
      NWNXPInvoke.CallBuiltIn(919);
    }

    /// <summary>
    /// Replace's oObject's texture sOld with sNew.
    /// Specifying sNew = "" will restore the original texture.
    /// If sNew cannot be found, the original texture will be restored.
    /// sNew must refer to a simple texture, not PLT
    /// </summary>
    public static void ReplaceObjectTexture(uint oObject, string sOld, string sNew = "")
    {
      NWNXPInvoke.StackPushString(sNew);
      NWNXPInvoke.StackPushString(sOld);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(920);
    }

    /// <summary>
    /// Destroys the given sqlite database, clearing out all data and schema.
    /// This operation is _immediate_ and _irreversible_, even when
    /// inside a transaction or running query.
    /// Existing active/prepared sqlqueries will remain functional, but any references
    /// to stored data or schema members will be invalidated.
    /// oObject: Same as SqlPrepareQueryObject().
    ///          To reset a campaign database, please use DestroyCampaignDatabase().
    /// </summary>
    public static void SqlDestroyDatabase(uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(921);
    }

    /// <summary>
    /// Returns "" if the last Sql command succeeded; or a human-readable error otherwise.
    /// Additionally, all SQL errors are logged to the server log.
    /// </summary>
    public static string SqlGetError(IntPtr sqlQuery)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(922);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Sets up a query.
    /// This will NOT run the query; only make it available for parameter binding.
    /// To run the query, you need to call SqlStep(); even if you do not
    /// expect result data.
    /// sDatabase: The name of a campaign database.
    ///            Note that when accessing campaign databases, you do not write access
    ///            to the builtin tables needed for CampaignDB functionality.
    /// N.B.: You can pass sqlqueries into DelayCommand; HOWEVER
    ///       *** they will NOT survive a game save/load ***
    ///       Any commands on a restored sqlquery will fail.
    /// </summary>
    public static IntPtr SqlPrepareQueryCampaign(string sDatabase, string sQuery)
    {
      NWNXPInvoke.StackPushString(sQuery);
      NWNXPInvoke.StackPushString(sDatabase);
      NWNXPInvoke.CallBuiltIn(923);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY);
    }

    /// <summary>
    /// Sets up a query.
    /// This will NOT run the query; only make it available for parameter binding.
    /// To run the query, you need to call SqlStep(); even if you do not
    /// expect result data.
    /// oObject: Can be either the module (GetModule()), or a player character.
    ///          The database is persisted to savegames in case of the module,
    ///          and to character files in case of a player characters.
    ///          Other objects cannot carry databases, and this function call
    ///          will error for them.
    /// N.B: Databases on objects (especially player characters!) should be kept
    ///      to a reasonable size. Delete old data you no longer need.
    ///      If you attempt to store more than a few megabytes of data on a
    ///      player creature, you may have a bad time.
    /// N.B.: You can pass sqlqueries into DelayCommand; HOWEVER
    ///       *** they will NOT survive a game save/load ***
    ///       Any commands on a restored sqlquery will fail.
    /// </summary>
    public static IntPtr SqlPrepareQueryObject(uint oObject, string sQuery)
    {
      NWNXPInvoke.StackPushString(sQuery);
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.CallBuiltIn(924);
      return NWNXPInvoke.StackPopGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY);
    }

    /// <summary>
    /// Bind an integer to a named parameter of the given prepared query.
    /// Example:
    ///   sqlquery v = SqlPrepareQueryObject(GetModule(), "insert into test (col) values (@myint);");
    ///   SqlBindInt(v, "@v", 5);
    ///   SqlStep(v);
    /// </summary>
    public static void SqlBindInt(IntPtr sqlQuery, string sParam, int nValue)
    {
      NWNXPInvoke.StackPushInteger(nValue);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(925);
    }

    /// <summary>
    /// Bind a float to a named parameter of the given prepared query.
    /// </summary>
    public static void SqlBindFloat(IntPtr sqlQuery, string sParam, float fFloat)
    {
      NWNXPInvoke.StackPushFloat(fFloat);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(926);
    }

    /// <summary>
    /// Bind a string to a named parameter of the given prepared query.
    /// </summary>
    public static void SqlBindString(IntPtr sqlQuery, string sParam, string sString)
    {
      NWNXPInvoke.StackPushString(sString);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(927);
    }

    /// <summary>
    /// Bind a vector to a named parameter of the given prepared query.
    /// </summary>
    public static void SqlBindVector(IntPtr sqlQuery, string sParam, Vector3 vVector)
    {
      NWNXPInvoke.StackPushVector(vVector);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(928);
    }

    /// <summary>
    /// Bind a object to a named parameter of the given prepared query.
    /// Objects are serialized, NOT stored as a reference!
    /// Currently supported object types: Creatures, Items, Placeables, Waypoints, Stores, Doors, Triggers
    /// </summary>
    public static void SqlBindObject(IntPtr sqlQuery, string sParam, uint oObject)
    {
      NWNXPInvoke.StackPushObject(oObject);
      NWNXPInvoke.StackPushString(sParam);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(929);
    }

    /// <summary>
    /// Executes the given query and fetches a row; returning true if row data was
    /// made available; false otherwise. Note that this will return false even if
    /// the query ran successfully but did not return data.
    /// You need to call SqlPrepareQuery() and potentially SqlBind* before calling this.
    /// Example:
    ///   sqlquery n = SqlPrepareQueryObject(GetFirstPC(), "select widget from widgets;");
    ///   while (SqlStep(n))
    ///     SendMessageToPC(GetFirstPC(), "Found widget: " + SqlGetString(n, 0));
    /// </summary>
    public static int SqlStep(IntPtr sqlQuery)
    {
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(930);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Retrieve a column cast as an integer of the currently stepped row.
    /// You can call this after SqlStep() returned TRUE.
    /// In case of error, 0 will be returned.
    /// In traditional fashion, nIndex starts at 0.
    /// </summary>
    public static int SqlGetInt(IntPtr sqlQuery, int nIndex)
    {
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(931);
      return NWNXPInvoke.StackPopInteger();
    }

    /// <summary>
    /// Retrieve a column cast as a float of the currently stepped row.
    /// You can call this after SqlStep() returned TRUE.
    /// In case of error, 0.0f will be returned.
    /// In traditional fashion, nIndex starts at 0.
    /// </summary>
    public static float SqlGetFloat(IntPtr sqlQuery, int nIndex)
    {
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(932);
      return NWNXPInvoke.StackPopFloat();
    }

    /// <summary>
    /// Retrieve a column cast as a string of the currently stepped row.
    /// You can call this after SqlStep() returned TRUE.
    /// In case of error, a empty string will be returned.
    /// In traditional fashion, nIndex starts at 0.
    /// </summary>
    public static string SqlGetString(IntPtr sqlQuery, int nIndex)
    {
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(933);
      return NWNXPInvoke.StackPopString();
    }

    /// <summary>
    /// Retrieve a vector of the currently stepped query.
    /// You can call this after SqlStep() returned TRUE.
    /// In case of error, a zero vector will be returned.
    /// In traditional fashion, nIndex starts at 0.
    /// </summary>
    public static Vector3 SqlGetVector(IntPtr sqlQuery, int nIndex)
    {
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(934);
      return NWNXPInvoke.StackPopVector();
    }

    /// <summary>
    /// Retrieve a object of the currently stepped query.
    /// You can call this after SqlStep() returned TRUE.
    /// The object will be spawned into a inventory if it is a item and the receiver
    /// has the capability to receive it, otherwise at lSpawnAt.
    /// Objects are serialized, NOT stored as a reference!
    /// In case of error, INVALID_OBJECT will be returned.
    /// In traditional fashion, nIndex starts at 0.
    /// </summary>
    public static uint SqlGetObject(IntPtr sqlQuery, int nIndex, IntPtr lSpawnAt, uint oInventory = OBJECT_INVALID)
    {
      NWNXPInvoke.StackPushObject(oInventory);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_LOCATION, lSpawnAt);
      NWNXPInvoke.StackPushInteger(nIndex);
      NWNXPInvoke.StackPushGameDefinedStructure(ENGINE_STRUCTURE_SQL_QUERY, sqlQuery);
      NWNXPInvoke.CallBuiltIn(935);
      return NWNXPInvoke.StackPopObject();
    }

    /// <summary>
    /// Convert sHex, a string containing a hexadecimal object id,
    /// into a object reference. Counterpart to StringToObject().
    /// </summary>
    public static uint StringToObject(string sHex)
    {
      NWNXPInvoke.StackPushString(sHex);
      NWNXPInvoke.CallBuiltIn(936);
      return NWNXPInvoke.StackPopObject();
    }
  }
}
