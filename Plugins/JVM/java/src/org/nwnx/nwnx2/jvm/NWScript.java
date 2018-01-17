// Generated on 2017-12-16 13:11:04 +0100

package org.nwnx.nwnx2.jvm;

import java.util.Vector;

public class NWScript {
    public NWScript() { }

    private native static synchronized int popInteger();
    private native static synchronized void pushInteger(int value);
    private native static synchronized float popFloat();
    private native static synchronized void pushFloat(float value);
    private native static synchronized String popString();
    private native static synchronized void pushString(String value);
    private native static synchronized NWObject popObject();
    private native static synchronized void pushObject(NWObject oObject);
    private native static synchronized NWVector popVector();
    private native static synchronized void pushVector(NWVector value);
    private native static synchronized NWLocation popLocation();
    private native static synchronized void pushLocation(NWLocation value);
    private native static synchronized NWEffect popEffect();
    private native static synchronized void pushEffect(NWEffect value);
    private native static synchronized NWItemProperty popItemProperty();
    private native static synchronized void pushItemProperty(NWItemProperty value);
    private native static synchronized void callFunction(int fid, int argc);
    private native static synchronized boolean canCallVM();

    /**
      * Get all currently online players.
    **/
    public static synchronized NWObject[] getPCs() throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstPC();
      while (i.valid()) {
        ret.add(i);
        i = getNextPC();
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all effects on the given NWObject.
    **/
    public static synchronized NWEffect[] getEffects(NWObject oWithEffects) throws NWNotInContextException
    {
      Vector<NWEffect> ret = new Vector<NWEffect>();
      NWEffect i = getFirstEffect(oWithEffects);
      while (getIsEffectValid(i)) {
        ret.add(i);
        i = getNextEffect(oWithEffects);
      }
      return ret.toArray(new NWEffect[0]);
    }

    /**
      * Get all itemproperties on the given NWObject.
    **/
    public static synchronized NWItemProperty[] getItemProperties(NWObject oItem) throws NWNotInContextException
    {
      Vector<NWItemProperty> ret = new Vector<NWItemProperty>();
      NWItemProperty i = getFirstItemProperty(oItem);
      while (getIsItemPropertyValid(i)) {
        ret.add(i);
        i = getNextItemProperty(oItem);
      }
      return ret.toArray(new NWItemProperty[0]);
    }

    /**
      * Get all items in the given NWObjects inventory.
    **/
    public static synchronized NWObject[] getItemsInInventory(NWObject oWithInventory) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstItemInInventory(oWithInventory);
      while (i.valid()) {
        ret.add(i);
        i = getNextItemInInventory(oWithInventory);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects in the given area.
    **/
    public static synchronized NWObject[] getObjectsInArea(NWObject oArea) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstObjectInArea(oArea);
      while (i.valid()) {
        ret.add(i);
        i = getNextObjectInArea(oArea);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects in the given shape.
      * @param nShape SHAPE_*
      * @param fSize
      * -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
      * -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
      * Spell Cylinder's always have a radius of 1.5m.
      * -> If nShape == SHAPE_CONE, this is the widest radius of the cone
      * -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
      * direction of lTarget. Spell cones are always 60 degrees with the origin
      * at OBJECT_SELF.
      * -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
      * the cube
      * @param lTarget This is the centre of the effect, usually GetSpellTargetLocation(),
      * or the end of a cylinder or cone.
      * @param bLineOfSight This controls whether to do a line-of-sight check on the
      * object returned. Line of sight check is done from origin to target object
      * at a height 1m above the ground
      * (This can be used to ensure that spell effects do not go through walls.)
      * @param nObjectFilter This allows you to filter out undesired object types, using
      * bitwise "or".
      * For example, to return only creatures and doors, the value for this
      * parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
      * @param vOrigin This is only used for cylinders and cones, and specifies the
      * origin of the effect(normally the spell-caster's position).
    **/
    public static synchronized NWObject[] getObjectsInShape(int nShapeType, float fSize, NWLocation lTarget, boolean bLineOfSight, int nObjectFilter, NWVector vOrigin) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstObjectInShape(nShapeType, fSize, lTarget, bLineOfSight, nObjectFilter, vOrigin);
      while (i.valid()) {
        ret.add(i);
        i = getNextObjectInShape(nShapeType, fSize, lTarget, bLineOfSight, nObjectFilter, vOrigin);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Returns all members of the given objects faction.
    */
    public static synchronized NWObject[] getFactionMembers(NWObject oMemberOf, boolean bPCOnly) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstFactionMember(oMemberOf, bPCOnly);
      while (i.valid()) {
        ret.add(i);
        i = getNextFactionMember(oMemberOf, bPCOnly);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
      * Get all objects within within oPersistentObject.
      * @param oPersistentObject
      * @param nResidentObjectType OBJECT_TYPE_*
      * @param nPersistentZone PERSISTENT_ZONE_ACTIVE. [This could also take the value
      * PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
    **/
    public static synchronized NWObject[] getObjectsInPersistentObject(NWObject oPersistentObject, int nResidentObjectType, int nPersistentZone) throws NWNotInContextException
    {
      Vector<NWObject> ret = new Vector<NWObject>();
      NWObject i = getFirstInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone);
      while (i.valid()) {
        ret.add(i);
        i = getNextInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone);
      }
      return ret.toArray(new NWObject[0]);
    }

    /**
     * Get an integer between 0 and nMaxInteger-1.
     * Return value on error: 0
     */
    public static synchronized int random(int nMaxInteger) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling random");
        pushInteger(nMaxInteger);
        callFunction(0, 1);
        return popInteger();
    }

    /**
     * Output sString to the log file.
     */
    public static synchronized void printString(String sString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling printString");
        pushString(sString);
        callFunction(1, 1);
    }

    /**
     * Output a formatted float to the log file.
     * @param nWidth should be a value from 0 to 18 inclusive.
     * @param nDecimals should be a value from 0 to 9 inclusive.
     */
    public static synchronized void printFloat(float fFloat, int nWidth, int nDecimals) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling printFloat");
        pushInteger(nDecimals);
        pushInteger(nWidth);
        pushFloat(fFloat);
        callFunction(2, 3);
    }

    /**
     * Convert fFloat into a string.
     * @param nWidth should be a value from 0 to 18 inclusive.
     * @param nDecimals should be a value from 0 to 9 inclusive.
     */
    public static synchronized String floatToString(float fFloat, int nWidth, int nDecimals) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling floatToString");
        pushInteger(nDecimals);
        pushInteger(nWidth);
        pushFloat(fFloat);
        callFunction(3, 3);
        return popString();
    }

    /**
     * Output nInteger to the log file.
     */
    public static synchronized void printInteger(int nInteger) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling printInteger");
        pushInteger(nInteger);
        callFunction(4, 1);
    }

    /**
     * Output oObject's ID to the log file.
     */
    public static synchronized void printObject(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling printObject");
        pushObject(oObject);
        callFunction(5, 1);
    }

    /**
     * Make oTarget run sScript and then return execution to the calling script.
     * If sScript does not specify a compiled script, nothing happens.
     */
    public static synchronized void executeScript(String sScript, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling executeScript");
        pushObject(oTarget);
        pushString(sScript);
        callFunction(6, 2);
    }

    /**
     * Clear all the actions of the caller.
     * * No return value, but if an error occurs, the log file will contain
     * "ClearAllActions failed.".
     * @param bClearCombatState if true, this will immediately clear the combat state
     * on a creature, which will stop the combat music and allow them to rest,
     * engage in dialog, or other actions that they would normally have to wait for.
     */
    public static synchronized void clearAllActions(boolean bClearCombatState) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling clearAllActions");
        pushInteger(bClearCombatState ? 1 : 0);
        callFunction(7, 1);
    }

    /**
     * Cause the caller to face fDirection.
     * @param fDirection is expressed as anticlockwise degrees from Due East.
     * DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
     * predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
     */
    public static synchronized void setFacing(float fDirection) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFacing");
        pushFloat(fDirection);
        callFunction(8, 1);
    }

    /**
     * Set the calendar to the specified date.
     * @param nYear should be from 0 to 32000 inclusive
     * @param nMonth should be from 1 to 12 inclusive
     * @param nDay should be from 1 to 28 inclusive
     * 1) Time can only be advanced forwards; attempting to set the time backwards
     * will result in no change to the calendar.
     * 2) If values larger than the month or day are specified, they will be wrapped
     * around and the overflow will be used to advance the next field.
     * e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
     * the calender being set to a year of 1352, a month of 9 and a day of 10.
     */
    public static synchronized void setCalendar(int nYear, int nMonth, int nDay) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCalendar");
        pushInteger(nDay);
        pushInteger(nMonth);
        pushInteger(nYear);
        callFunction(9, 3);
    }

    /**
     * Set the time to the time specified.
     * @param nHour should be from 0 to 23 inclusive
     * @param nMinute should be from 0 to 59 inclusive
     * @param nSecond should be from 0 to 59 inclusive
     * @param nMillisecond should be from 0 to 999 inclusive
     * 1) Time can only be advanced forwards; attempting to set the time backwards
     * will result in the day advancing and then the time being set to that
     * specified, e.g. if the current hour is 15 and then the hour is set to 3,
     * the day will be advanced by 1 and the hour will be set to 3.
     * 2) If values larger than the max hour, minute, second or millisecond are
     * specified, they will be wrapped around and the overflow will be used to
     * advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
     * and 10 milliseconds will result in the calendar day being advanced by 2
     * and the time being set to 18 hours, 10 minutes, 10 milliseconds.
     */
    public static synchronized void setTime(int nHour, int nMinute, int nSecond, int nMillisecond) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTime");
        pushInteger(nMillisecond);
        pushInteger(nSecond);
        pushInteger(nMinute);
        pushInteger(nHour);
        callFunction(10, 4);
    }

    /**
     * Get the current calendar year.
     */
    public static synchronized int getCalendarYear() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCalendarYear");
        callFunction(11, 0);
        return popInteger();
    }

    /**
     * Get the current calendar month.
     */
    public static synchronized int getCalendarMonth() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCalendarMonth");
        callFunction(12, 0);
        return popInteger();
    }

    /**
     * Get the current calendar day.
     */
    public static synchronized int getCalendarDay() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCalendarDay");
        callFunction(13, 0);
        return popInteger();
    }

    /**
     * Get the current hour.
     */
    public static synchronized int getTimeHour() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTimeHour");
        callFunction(14, 0);
        return popInteger();
    }

    /**
     * Get the current minute
     */
    public static synchronized int getTimeMinute() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTimeMinute");
        callFunction(15, 0);
        return popInteger();
    }

    /**
     * Get the current second
     */
    public static synchronized int getTimeSecond() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTimeSecond");
        callFunction(16, 0);
        return popInteger();
    }

    /**
     * Get the current millisecond
     */
    public static synchronized int getTimeMillisecond() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTimeMillisecond");
        callFunction(17, 0);
        return popInteger();
    }

    /**
     * The action subject will generate a random location near its current location
     * and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
     * to call ClearAllActions in order to allow a creature to perform any other action
     * once ActionRandomWalk has been called.
     * * No return value, but if an error occurs the log file will contain
     * "ActionRandomWalk failed."
     */
    public static synchronized void actionRandomWalk() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionRandomWalk");
        callFunction(18, 0);
    }

    /**
     * The action subject will move to lDestination.
     * @param lDestination The object will move to this location.  If the location is
     * invalid or a path cannot be found to it, the command does nothing.
     * @param bRun If this is TRUE, the action subject will run rather than walk
     * * No return value, but if an error occurs the log file will contain
     * "MoveToPoint failed."
     */
    public static synchronized void actionMoveToLocation(NWLocation lDestination, boolean bRun) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionMoveToLocation");
        pushInteger(bRun ? 1 : 0);
        pushLocation(lDestination);
        callFunction(19, 2);
    }

    /**
     * Cause the action subject to move to a certain distance from oMoveTo.
     * If there is no path to oMoveTo, this command will do nothing.
     * @param oMoveTo This is the object we wish the action subject to move to
     * @param bRun If this is TRUE, the action subject will run rather than walk
     * @param fRange This is the desired distance between the action subject and oMoveTo
     * * No return value, but if an error occurs the log file will contain
     * "ActionMoveToObject failed."
     */
    public static synchronized void actionMoveToObject(NWObject oMoveTo, boolean bRun, float fRange) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionMoveToObject");
        pushFloat(fRange);
        pushInteger(bRun ? 1 : 0);
        pushObject(oMoveTo);
        callFunction(20, 3);
    }

    /**
     * Cause the action subject to move to a certain distance away from oFleeFrom.
     * @param oFleeFrom This is the object we wish the action subject to move away from.
     * If oFleeFrom is not in the same area as the action subject, nothing will
     * happen.
     * @param bRun If this is TRUE, the action subject will run rather than walk
     * @param fMoveAwayRange This is the distance we wish the action subject to put
     * between themselves and oFleeFrom
     * * No return value, but if an error occurs the log file will contain
     * "ActionMoveAwayFromObject failed."
     */
    public static synchronized void actionMoveAwayFromObject(NWObject oFleeFrom, boolean bRun, float fMoveAwayRange) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionMoveAwayFromObject");
        pushFloat(fMoveAwayRange);
        pushInteger(bRun ? 1 : 0);
        pushObject(oFleeFrom);
        callFunction(21, 3);
    }

    /**
     * Get the area that oTarget is currently in
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getArea(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getArea");
        pushObject(oTarget);
        callFunction(22, 1);
        return popObject();
    }

    /**
     * The value returned by this function depends on the object type of the caller:
     * 1) If the caller is a door it returns the object that last
     * triggered it.
     * 2) If the caller is a trigger, area of effect, module, area or encounter it
     * returns the object that last entered it.
     * * Return value on error: OBJECT_INVALID
     * When used for doors, this should only be called from the OnAreaTransitionClick
     * event.  Otherwise, it should only be called in OnEnter scripts.
     */
    public static synchronized NWObject getEnteringObject() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEnteringObject");
        callFunction(23, 0);
        return popObject();
    }

    /**
     * Get the object that last left the caller.  This function works on triggers,
     * areas of effect, modules, areas and encounters.
     * * Return value on error: OBJECT_INVALID
     * Should only be called in OnExit scripts.
     */
    public static synchronized NWObject getExitingObject() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getExitingObject");
        callFunction(24, 0);
        return popObject();
    }

    /**
     * Get the position of oTarget
     * * Return value on error: vector (0.0f, 0.0f, 0.0f)
     */
    public static synchronized NWVector getPosition(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPosition");
        pushObject(oTarget);
        callFunction(25, 1);
        return popVector();
    }

    /**
     * Get the direction in which oTarget is facing, expressed as a float between
     * 0.0f and 360.0f
     * * Return value on error: -1.0f
     */
    public static synchronized float getFacing(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFacing");
        pushObject(oTarget);
        callFunction(26, 1);
        return popFloat();
    }

    /**
     * Get the possessor of oItem
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getItemPossessor(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPossessor");
        pushObject(oItem);
        callFunction(27, 1);
        return popObject();
    }

    /**
     * Get the object possessed by oCreature with the tag sItemTag
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getItemPossessedBy(NWObject oCreature, String sItemTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPossessedBy");
        pushString(sItemTag);
        pushObject(oCreature);
        callFunction(28, 2);
        return popObject();
    }

    /**
     * Create an item with the template sItemTemplate in oTarget's inventory.
     * @param nStackSize This is the stack size of the item to be created
     * @param sNewTag If this string is not empty, it will replace the default tag from the template
     * * Return value: The object that has been created.  On error, this returns
     * OBJECT_INVALID.
     * If the item created was merged into an existing stack of similar items,
     * the function will return the merged stack object. If the merged stack
     * overflowed, the function will return the overflowed stack that was created.
     */
    public static synchronized NWObject createItemOnObject(String sItemTemplate, NWObject oTarget, int nStackSize, String sNewTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling createItemOnObject");
        pushString(sNewTag);
        pushInteger(nStackSize);
        pushObject(oTarget);
        pushString(sItemTemplate);
        callFunction(29, 4);
        return popObject();
    }

    /**
     * Equip oItem into nInventorySlot.
     * @param nInventorySlot INVENTORY_SLOT_*
     * * No return value, but if an error occurs the log file will contain
     * "ActionEquipItem failed."
     *
     * Note:
     * If the creature already has an item equipped in the slot specified, it will be
     * unequipped automatically by the call to ActionEquipItem.
     *
     * In order for ActionEquipItem to succeed the creature must be able to equip the
     * item oItem normally. This means that:
     * 1) The item is in the creature's inventory.
     * 2) The item must already be identified (if magical).
     * 3) The creature has the level required to equip the item (if magical and ILR is on).
     * 4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
     */
    public static synchronized void actionEquipItem(NWObject oItem, int nInventorySlot) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionEquipItem");
        pushInteger(nInventorySlot);
        pushObject(oItem);
        callFunction(30, 2);
    }

    /**
     * Unequip oItem from whatever slot it is currently in.
     */
    public static synchronized void actionUnequipItem(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionUnequipItem");
        pushObject(oItem);
        callFunction(31, 1);
    }

    /**
     * Pick up oItem from the ground.
     * * No return value, but if an error occurs the log file will contain
     * "ActionPickUpItem failed."
     */
    public static synchronized void actionPickUpItem(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionPickUpItem");
        pushObject(oItem);
        callFunction(32, 1);
    }

    /**
     * Put down oItem on the ground.
     * * No return value, but if an error occurs the log file will contain
     * "ActionPutDownItem failed."
     */
    public static synchronized void actionPutDownItem(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionPutDownItem");
        pushObject(oItem);
        callFunction(33, 1);
    }

    /**
     * Get the last attacker of oAttackee.  This should only be used ONLY in the
     * OnAttacked events for creatures, placeables and doors.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getLastAttacker(NWObject oAttackee) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastAttacker");
        pushObject(oAttackee);
        callFunction(34, 1);
        return popObject();
    }

    /**
     * Attack oAttackee.
     * @param bPassive If this is TRUE, attack is in passive mode.
     */
    public static synchronized void actionAttack(NWObject oAttackee, boolean bPassive) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionAttack");
        pushInteger(bPassive ? 1 : 0);
        pushObject(oAttackee);
        callFunction(35, 2);
    }

    /**
     * Get the creature nearest to oTarget, subject to all the criteria specified.
     * @param nFirstCriteriaType CREATURE_TYPE_*
     * @param nFirstCriteriaValue:
     * -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
     * -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
     * or CREATURE_TYPE_HAS_SPELL_EFFECT
     * -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
     * -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
     * -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
     * CREATURE_TYPE_PLAYER_CHAR
     * -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
     * -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
     * For example, to get the nearest PC, use:
     * (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
     * @param oTarget We're trying to find the creature of the specified type that is
     * nearest to oTarget
     * @param nNth We don't have to find the first nearest: we can find the Nth nearest...
     * @param nSecondCriteriaType This is used in the same way as nFirstCriteriaType to
     * further specify the type of creature that we are looking for.
     * @param nSecondCriteriaValue This is used in the same way as nFirstCriteriaValue
     * to further specify the type of creature that we are looking for.
     * @param nThirdCriteriaType This is used in the same way as nFirstCriteriaType to
     * further specify the type of creature that we are looking for.
     * @param nThirdCriteriaValue This is used in the same way as nFirstCriteriaValue to
     * further specify the type of creature that we are looking for.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNearestCreature(int nFirstCriteriaType, int nFirstCriteriaValue, NWObject oTarget, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestCreature");
        pushInteger(nThirdCriteriaValue);
        pushInteger(nThirdCriteriaType);
        pushInteger(nSecondCriteriaValue);
        pushInteger(nSecondCriteriaType);
        pushInteger(nNth);
        pushObject(oTarget);
        pushInteger(nFirstCriteriaValue);
        pushInteger(nFirstCriteriaType);
        callFunction(36, 8);
        return popObject();
    }

    /**
     * Add a speak action to the action subject.
     * @param sStringToSpeak String to be spoken
     * @param nTalkVolume TALKVOLUME_*
     */
    public static synchronized void actionSpeakString(String sStringToSpeak, int nTalkVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionSpeakString");
        pushInteger(nTalkVolume);
        pushString(sStringToSpeak);
        callFunction(37, 2);
    }

    /**
     * Cause the action subject to play an animation
     * @param nAnimation ANIMATION_*
     * @param fSpeed Speed of the animation
     * @param fDurationSeconds Duration of the animation (this is not used for Fire and
     * Forget animations)
     */
    public static synchronized void actionPlayAnimation(int nAnimation, float fSpeed, float fDurationSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionPlayAnimation");
        pushFloat(fDurationSeconds);
        pushFloat(fSpeed);
        pushInteger(nAnimation);
        callFunction(38, 3);
    }

    /**
     * Get the distance from the caller to oObject in metres.
     * * Return value on error: -1.0f
     */
    public static synchronized float getDistanceToObject(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDistanceToObject");
        pushObject(oObject);
        callFunction(39, 1);
        return popFloat();
    }

    /**
     * * Returns TRUE if oObject is a valid object.
     */
    public static synchronized boolean getIsObjectValid(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsObjectValid");
        pushObject(oObject);
        callFunction(40, 1);
        return popInteger() > 0;
    }

    /**
     * Cause the action subject to open oDoor
     */
    public static synchronized void actionOpenDoor(NWObject oDoor) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionOpenDoor");
        pushObject(oDoor);
        callFunction(41, 1);
    }

    /**
     * Cause the action subject to close oDoor
     */
    public static synchronized void actionCloseDoor(NWObject oDoor) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCloseDoor");
        pushObject(oDoor);
        callFunction(42, 1);
    }

    /**
     * Change the direction in which the camera is facing
     * @param fDirection is expressed as anticlockwise degrees from Due East.
     * (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
     * A value of -1.0f for any parameter will be ignored and instead it will
     * use the current camera value.
     * This can be used to change the way the camera is facing after the player
     * emerges from an area transition.
     * @param nTransitionType CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
     * camera to the new position, while the other types will result in the camera moving gradually into position
     * Pitch and distance are limited to valid values for the current camera mode:
     * Top Down: Distance = 5-20, Pitch = 1-50
     * Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
     * Chase: Distance = 5-20, Pitch = 1-50
     * *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
     * Distance 1-25
     * Pitch 1-89
     */
    public static synchronized void setCameraFacing(float fDirection, float fDistance, float fPitch, int nTransitionType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCameraFacing");
        pushInteger(nTransitionType);
        pushFloat(fPitch);
        pushFloat(fDistance);
        pushFloat(fDirection);
        callFunction(43, 4);
    }

    /**
     * Play sSoundName
     * @param sSoundName TBD - SS
     * This will play a mono sound from the location of the object running the command.
     */
    public static synchronized void playSound(String sSoundName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling playSound");
        pushString(sSoundName);
        callFunction(44, 1);
    }

    /**
     * Get the object at which the caller last cast a spell
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getSpellTargetObject() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellTargetObject");
        callFunction(45, 0);
        return popObject();
    }

    /**
     * This action casts a spell at oTarget.
     * @param nSpell SPELL_*
     * @param oTarget Target for the spell
     * @param nMetamagic METAMAGIC_*
     * @param bCheat If this is TRUE, then the executor of the action doesn't have to be
     * able to cast the spell.
     * @param nDomainLevel TBD - SS
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     * @param bInstantSpell If this is TRUE, the spell is cast immediately. This allows
     * the end-user to simulate a high-level magic-user having lots of advance
     * warning of impending trouble
     */
    public static synchronized void actionCastSpellAtObject(int nSpell, NWObject oTarget, int nMetaMagic, boolean bCheat, int nDomainLevel, int nProjectilePathType, boolean bInstantSpell) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCastSpellAtObject");
        pushInteger(bInstantSpell ? 1 : 0);
        pushInteger(nProjectilePathType);
        pushInteger(nDomainLevel);
        pushInteger(bCheat ? 1 : 0);
        pushInteger(nMetaMagic);
        pushObject(oTarget);
        pushInteger(nSpell);
        callFunction(46, 7);
    }

    /**
     * Get the current hitpoints of oObject
     * * Return value on error: 0
     */
    public static synchronized int getCurrentHitPoints(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCurrentHitPoints");
        pushObject(oObject);
        callFunction(47, 1);
        return popInteger();
    }

    /**
     * Get the maximum hitpoints of oObject
     * * Return value on error: 0
     */
    public static synchronized int getMaxHitPoints(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMaxHitPoints");
        pushObject(oObject);
        callFunction(48, 1);
        return popInteger();
    }

    /**
     * Get oObject's local integer variable sVarName
     * * Return value on error: 0
     */
    public static synchronized int getLocalInt(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocalInt");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(49, 2);
        return popInteger();
    }

    /**
     * Get oObject's local float variable sVarName
     * * Return value on error: 0.0f
     */
    public static synchronized float getLocalFloat(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocalFloat");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(50, 2);
        return popFloat();
    }

    /**
     * Get oObject's local string variable sVarName
     * * Return value on error: ""
     */
    public static synchronized String getLocalString(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocalString");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(51, 2);
        return popString();
    }

    /**
     * Get oObject's local object variable sVarName
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getLocalObject(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocalObject");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(52, 2);
        return popObject();
    }

    /**
     * Set oObject's local integer variable sVarName to nValue
     */
    public static synchronized void setLocalInt(NWObject oObject, String sVarName, int nValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocalInt");
        pushInteger(nValue);
        pushString(sVarName);
        pushObject(oObject);
        callFunction(53, 3);
    }

    /**
     * Set oObject's local float variable sVarName to nValue
     */
    public static synchronized void setLocalFloat(NWObject oObject, String sVarName, float fValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocalFloat");
        pushFloat(fValue);
        pushString(sVarName);
        pushObject(oObject);
        callFunction(54, 3);
    }

    /**
     * Set oObject's local string variable sVarName to nValue
     */
    public static synchronized void setLocalString(NWObject oObject, String sVarName, String sValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocalString");
        pushString(sValue);
        pushString(sVarName);
        pushObject(oObject);
        callFunction(55, 3);
    }

    /**
     * Set oObject's local object variable sVarName to nValue
     */
    public static synchronized void setLocalObject(NWObject oObject, String sVarName, NWObject oValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocalObject");
        pushObject(oValue);
        pushString(sVarName);
        pushObject(oObject);
        callFunction(56, 3);
    }

    /**
     * Get the length of sString
     * * Return value on error: -1
     */
    public static synchronized int getStringLength(String sString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringLength");
        pushString(sString);
        callFunction(57, 1);
        return popInteger();
    }

    /**
     * Convert sString into upper case
     * * Return value on error: ""
     */
    public static synchronized String getStringUpperCase(String sString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringUpperCase");
        pushString(sString);
        callFunction(58, 1);
        return popString();
    }

    /**
     * Convert sString into lower case
     * * Return value on error: ""
     */
    public static synchronized String getStringLowerCase(String sString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringLowerCase");
        pushString(sString);
        callFunction(59, 1);
        return popString();
    }

    /**
     * Get nCount characters from the right end of sString
     * * Return value on error: ""
     */
    public static synchronized String getStringRight(String sString, int nCount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringRight");
        pushInteger(nCount);
        pushString(sString);
        callFunction(60, 2);
        return popString();
    }

    /**
     * Get nCounter characters from the left end of sString
     * * Return value on error: ""
     */
    public static synchronized String getStringLeft(String sString, int nCount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringLeft");
        pushInteger(nCount);
        pushString(sString);
        callFunction(61, 2);
        return popString();
    }

    /**
     * Insert sString into sDestination at nPosition
     * * Return value on error: ""
     */
    public static synchronized String insertString(String sDestination, String sString, int nPosition) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling insertString");
        pushInteger(nPosition);
        pushString(sString);
        pushString(sDestination);
        callFunction(62, 3);
        return popString();
    }

    /**
     * Get nCount characters from sString, starting at nStart
     * * Return value on error: ""
     */
    public static synchronized String getSubString(String sString, int nStart, int nCount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSubString");
        pushInteger(nCount);
        pushInteger(nStart);
        pushString(sString);
        callFunction(63, 3);
        return popString();
    }

    /**
     * Find the position of sSubstring inside sString
     * @param nStart The character position to start searching at (from the left end of the string).
     * * Return value on error: -1
     */
    public static synchronized int findSubString(String sString, String sSubString, int nStart) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling findSubString");
        pushInteger(nStart);
        pushString(sSubString);
        pushString(sString);
        callFunction(64, 3);
        return popInteger();
    }

    /**
     * Create a Heal effect. This should be applied as an instantaneous effect.
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
     */
    public static synchronized NWEffect effectHeal(int nDamageToHeal) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectHeal");
        pushInteger(nDamageToHeal);
        callFunction(65, 1);
        return popEffect();
    }

    /**
     * Create a Damage effect
     * @param nDamageAmount amount of damage to be dealt. This should be applied as an
     * instantaneous effect.
     * @param nDamageType DAMAGE_TYPE_*
     * @param nDamagePower DAMAGE_POWER_*
     */
    public static synchronized NWEffect effectDamage(int nDamageAmount, int nDamageType, int nDamagePower) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamage");
        pushInteger(nDamagePower);
        pushInteger(nDamageType);
        pushInteger(nDamageAmount);
        callFunction(66, 3);
        return popEffect();
    }

    /**
     * Create an Ability Increase effect
     * @param bAbilityToIncrease ABILITY_*
     */
    public static synchronized NWEffect effectAbilityIncrease(int nAbility, int nModifyBy) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAbilityIncrease");
        pushInteger(nModifyBy);
        pushInteger(nAbility);
        callFunction(67, 2);
        return popEffect();
    }

    /**
     * Create a Damage Resistance effect that removes the first nAmount points of
     * damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
     * @param nDamageType DAMAGE_TYPE_*
     * @param nAmount
     * @param nLimit
     */
    public static synchronized NWEffect effectDamageResistance(int nDamageType, int nAmount, int nLimit) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageResistance");
        pushInteger(nLimit);
        pushInteger(nAmount);
        pushInteger(nDamageType);
        callFunction(68, 3);
        return popEffect();
    }

    /**
     * Create a Resurrection effect. This should be applied as an instantaneous effect.
     */
    public static synchronized NWEffect effectResurrection() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectResurrection");
        callFunction(69, 0);
        return popEffect();
    }

    /**
     * Create a Summon Creature effect.  The creature is created and placed into the
     * caller's party/faction.
     * @param sCreatureResref Identifies the creature to be summoned
     * @param nVisualEffectId VFX_*
     * @param fDelaySeconds There can be delay between the visual effect being played, and the
     * creature being added to the area
     * @param bUseAppearAnimation should this creature play it's "appear" animation when it is
     * summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
     * it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
     */
    public static synchronized NWEffect effectSummonCreature(String sCreatureResref, int nVisualEffectId, float fDelaySeconds, boolean bUseAppearAnimation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSummonCreature");
        pushInteger(bUseAppearAnimation ? 1 : 0);
        pushFloat(fDelaySeconds);
        pushInteger(nVisualEffectId);
        pushString(sCreatureResref);
        callFunction(70, 4);
        return popEffect();
    }

    /**
     * Get the level at which this creature cast it's last spell (or spell-like ability)
     * * Return value on error, or if oCreature has not yet cast a spell: 0;
     */
    public static synchronized int getCasterLevel(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCasterLevel");
        pushObject(oCreature);
        callFunction(71, 1);
        return popInteger();
    }

    /**
     * Get the first in-game effect on oCreature.
     */
    public static synchronized NWEffect getFirstEffect(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstEffect");
        pushObject(oCreature);
        callFunction(72, 1);
        return popEffect();
    }

    /**
     * Get the next in-game effect on oCreature.
     */
    public static synchronized NWEffect getNextEffect(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextEffect");
        pushObject(oCreature);
        callFunction(73, 1);
        return popEffect();
    }

    /**
     * Remove eEffect from oCreature.
     * * No return value
     */
    public static synchronized void removeEffect(NWObject oCreature, NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeEffect");
        pushEffect(eEffect);
        pushObject(oCreature);
        callFunction(74, 2);
    }

    /**
     * * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
     * * an object or else it will return FALSE
     */
    public static synchronized boolean getIsEffectValid(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsEffectValid");
        pushEffect(eEffect);
        callFunction(75, 1);
        return popInteger() > 0;
    }

    /**
     * Get the duration type (DURATION_TYPE_*) of eEffect.
     * * Return value if eEffect is not valid: -1
     */
    public static synchronized int getEffectDurationType(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectDurationType");
        pushEffect(eEffect);
        callFunction(76, 1);
        return popInteger();
    }

    /**
     * Get the subtype (SUBTYPE_*) of eEffect.
     * * Return value on error: 0
     */
    public static synchronized int getEffectSubType(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectSubType");
        pushEffect(eEffect);
        callFunction(77, 1);
        return popInteger();
    }

    /**
     * Get the object that created eEffect.
     * * Returns OBJECT_INVALID if eEffect is not a valid effect.
     */
    public static synchronized NWObject getEffectCreator(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectCreator");
        pushEffect(eEffect);
        callFunction(78, 1);
        return popObject();
    }

    /**
     * Convert nInteger into a string.
     * * Return value on error: ""
     */
    public static synchronized String intToString(int nInteger) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling intToString");
        pushInteger(nInteger);
        callFunction(79, 1);
        return popString();
    }

    /**
     * Get the first object in oArea.
     * If no valid area is specified, it will use the caller's area.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getFirstObjectInArea(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstObjectInArea");
        pushObject(oArea);
        callFunction(80, 1);
        return popObject();
    }

    /**
     * Get the next object in oArea.
     * If no valid area is specified, it will use the caller's area.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNextObjectInArea(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextObjectInArea");
        pushObject(oArea);
        callFunction(81, 1);
        return popObject();
    }

    /**
     * Get the magnitude of vVector; this can be used to determine the
     * distance between two points.
     * * Return value on error: 0.0f
     */
    public static synchronized float vectorMagnitude(NWVector vVector) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling vectorMagnitude");
        pushVector(vVector);
        callFunction(82, 1);
        return popFloat();
    }

    /**
     * Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
     * * Return value if the caster is not a valid object: -1
     */
    public static synchronized int getMetaMagicFeat() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMetaMagicFeat");
        callFunction(83, 0);
        return popInteger();
    }

    /**
     * Get the object type (OBJECT_TYPE_*) of oTarget
     * * Return value if oTarget is not a valid object: -1
     */
    public static synchronized int getObjectType(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getObjectType");
        pushObject(oTarget);
        callFunction(84, 1);
        return popInteger();
    }

    /**
     * Get the racial type (RACIAL_TYPE_*) of oCreature
     * * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
     */
    public static synchronized int getRacialType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getRacialType");
        pushObject(oCreature);
        callFunction(85, 1);
        return popInteger();
    }

    /**
     * Do a Fortitude Save check for the given DC
     * @param oCreature
     * @param nDC Difficulty check
     * @param nSaveType SAVING_THROW_TYPE_*
     * @param oSaveVersus
     * Returns: 0 if the saving throw roll failed
     * Returns: 1 if the saving throw roll succeeded
     * Returns: 2 if the target was immune to the save type specified
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
     * GetAreaOfEffectCreator() into oSaveVersus!!
     */
    public static synchronized int fortitudeSave(NWObject oCreature, int nDC, int nSaveType, NWObject oSaveVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling fortitudeSave");
        pushObject(oSaveVersus);
        pushInteger(nSaveType);
        pushInteger(nDC);
        pushObject(oCreature);
        callFunction(86, 4);
        return popInteger();
    }

    /**
     * Does a Reflex Save check for the given DC
     * @param oCreature
     * @param nDC Difficulty check
     * @param nSaveType SAVING_THROW_TYPE_*
     * @param oSaveVersus
     * Returns: 0 if the saving throw roll failed
     * Returns: 1 if the saving throw roll succeeded
     * Returns: 2 if the target was immune to the save type specified
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
     * GetAreaOfEffectCreator() into oSaveVersus!!
     */
    public static synchronized int reflexSave(NWObject oCreature, int nDC, int nSaveType, NWObject oSaveVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling reflexSave");
        pushObject(oSaveVersus);
        pushInteger(nSaveType);
        pushInteger(nDC);
        pushObject(oCreature);
        callFunction(87, 4);
        return popInteger();
    }

    /**
     * Does a Will Save check for the given DC
     * @param oCreature
     * @param nDC Difficulty check
     * @param nSaveType SAVING_THROW_TYPE_*
     * @param oSaveVersus
     * Returns: 0 if the saving throw roll failed
     * Returns: 1 if the saving throw roll succeeded
     * Returns: 2 if the target was immune to the save type specified
     * Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
     * GetAreaOfEffectCreator() into oSaveVersus!!
     */
    public static synchronized int willSave(NWObject oCreature, int nDC, int nSaveType, NWObject oSaveVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling willSave");
        pushObject(oSaveVersus);
        pushInteger(nSaveType);
        pushInteger(nDC);
        pushObject(oCreature);
        callFunction(88, 4);
        return popInteger();
    }

    /**
     * Get the DC to save against for a spell (10 + spell level + relevant ability
     * bonus).  This can be called by a creature or by an Area of Effect object.
     */
    public static synchronized int getSpellSaveDC() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellSaveDC");
        callFunction(89, 0);
        return popInteger();
    }

    /**
     * Set the subtype of eEffect to Magical and return eEffect.
     * (Effects default to magical if the subtype is not set)
     * Magical effects are removed by resting, and by dispel magic
     */
    public static synchronized NWEffect magicalEffect(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling magicalEffect");
        pushEffect(eEffect);
        callFunction(90, 1);
        return popEffect();
    }

    /**
     * Set the subtype of eEffect to Supernatural and return eEffect.
     * (Effects default to magical if the subtype is not set)
     * Permanent supernatural effects are not removed by resting
     */
    public static synchronized NWEffect supernaturalEffect(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling supernaturalEffect");
        pushEffect(eEffect);
        callFunction(91, 1);
        return popEffect();
    }

    /**
     * Set the subtype of eEffect to Extraordinary and return eEffect.
     * (Effects default to magical if the subtype is not set)
     * Extraordinary effects are removed by resting, but not by dispel magic
     */
    public static synchronized NWEffect extraordinaryEffect(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling extraordinaryEffect");
        pushEffect(eEffect);
        callFunction(92, 1);
        return popEffect();
    }

    /**
     * Create an AC Increase effect
     * @param nValue size of AC increase
     * @param nACModifyType AC_*_BONUS
     * @param nDamageType DAMAGE_TYPE_*
     * * Default value for nDamageType should only ever be used in this function prototype.
     */
    public static synchronized NWEffect effectACIncrease(int nValue, int nACModifyType, int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectACIncrease");
        pushInteger(nDamageType);
        pushInteger(nACModifyType);
        pushInteger(nValue);
        callFunction(93, 3);
        return popEffect();
    }

    /**
     * If oObject is a creature, this will return that creature's armour class
     * If oObject is an item, door or placeable, this will return zero.
     * @param nForFutureUse this parameter is not currently used
     * * Return value if oObject is not a creature, item, door or placeable: -1
     */
    public static synchronized int getAC(NWObject oObject, int nForFutureUse) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAC");
        pushInteger(nForFutureUse);
        pushObject(oObject);
        callFunction(94, 2);
        return popInteger();
    }

    /**
     * Create a Saving Throw Increase effect
     * @param nSave SAVING_THROW_* (not SAVING_THROW_TYPE_*)
     * SAVING_THROW_ALL
     * SAVING_THROW_FORT
     * SAVING_THROW_REFLEX
     * SAVING_THROW_WILL
     * @param nValue size of the Saving Throw increase
     * @param nSaveType SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
     */
    public static synchronized NWEffect effectSavingThrowIncrease(int nSave, int nValue, int nSaveType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSavingThrowIncrease");
        pushInteger(nSaveType);
        pushInteger(nValue);
        pushInteger(nSave);
        callFunction(95, 3);
        return popEffect();
    }

    /**
     * Create an Attack Increase effect
     * @param nBonus size of attack bonus
     * @param nAttackBonus ATTACK_BONUS_*
     */
    public static synchronized NWEffect effectAttackIncrease(int nBonus, int nAttackBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAttackIncrease");
        pushInteger(nAttackBonus);
        pushInteger(nBonus);
        callFunction(96, 2);
        return popEffect();
    }

    /**
     * Create a Damage Reduction effect
     * @param nAmount amount of damage reduction
     * @param nDamagePower DAMAGE_POWER_*
     * @param nLimit How much damage the effect can absorb before disappearing.
     * Set to zero for infinite
     */
    public static synchronized NWEffect effectDamageReduction(int nAmount, int nDamagePower, int nLimit) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageReduction");
        pushInteger(nLimit);
        pushInteger(nDamagePower);
        pushInteger(nAmount);
        callFunction(97, 3);
        return popEffect();
    }

    /**
     * Create a Damage Increase effect
     * @param nBonus DAMAGE_BONUS_*
     * @param nDamageType DAMAGE_TYPE_*
     * NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
     * result in odd behaviour.
     */
    public static synchronized NWEffect effectDamageIncrease(int nBonus, int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageIncrease");
        pushInteger(nDamageType);
        pushInteger(nBonus);
        callFunction(98, 2);
        return popEffect();
    }

    /**
     * Convert nRounds into a number of seconds
     * A round is always 6.0 seconds
     */
    public static synchronized float roundsToSeconds(int nRounds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling roundsToSeconds");
        pushInteger(nRounds);
        callFunction(99, 1);
        return popFloat();
    }

    /**
     * Convert nHours into a number of seconds
     * The result will depend on how many minutes there are per hour (game-time)
     */
    public static synchronized float hoursToSeconds(int nHours) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling hoursToSeconds");
        pushInteger(nHours);
        callFunction(100, 1);
        return popFloat();
    }

    /**
     * Convert nTurns into a number of seconds
     * A turn is always 60.0 seconds
     */
    public static synchronized float turnsToSeconds(int nTurns) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling turnsToSeconds");
        pushInteger(nTurns);
        callFunction(101, 1);
        return popFloat();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) to represent oCreature's
     * Law/Chaos alignment
     * (100=law, 0=chaos)
     * * Return value if oCreature is not a valid creature: -1
     */
    public static synchronized int getLawChaosValue(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLawChaosValue");
        pushObject(oCreature);
        callFunction(102, 1);
        return popInteger();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) to represent oCreature's
     * Good/Evil alignment
     * (100=good, 0=evil)
     * * Return value if oCreature is not a valid creature: -1
     */
    public static synchronized int getGoodEvilValue(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGoodEvilValue");
        pushObject(oCreature);
        callFunction(103, 1);
        return popInteger();
    }

    /**
     * Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
     * * Return value if oCreature is not a valid creature: -1
     */
    public static synchronized int getAlignmentLawChaos(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAlignmentLawChaos");
        pushObject(oCreature);
        callFunction(104, 1);
        return popInteger();
    }

    /**
     * Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
     * * Return value if oCreature is not a valid creature: -1
     */
    public static synchronized int getAlignmentGoodEvil(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAlignmentGoodEvil");
        pushObject(oCreature);
        callFunction(105, 1);
        return popInteger();
    }

    /**
     * Get the first object in nShape
     * @param nShapeType SHAPE_*
     * @param fSize:
     * -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
     * -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder
     * Spell Cylinder's always have a radius of 1.5m.
     * -> If nShape == SHAPE_CONE, this is the widest radius of the cone
     * -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
     * direction of lTarget. Spell cones are always 60 degrees with the origin
     * at OBJECT_SELF.
     * -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
     * the cube
     * @param lTarget This is the centre of the effect, usually GetSpellTargetLocation(),
     * or the end of a cylinder or cone.
     * @param bLineOfSight This controls whether to do a line-of-sight check on the
     * object returned. Line of sight check is done from origin to target object
     * at a height 1m above the ground
     * (This can be used to ensure that spell effects do not go through walls.)
     * @param nObjectFilter This allows you to filter out undesired object types, using
     * bitwise "or".
     * For example, to return only creatures and doors, the value for this
     * parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
     * @param vOrigin This is only used for cylinders and cones, and specifies the
     * origin of the effect(normally the spell-caster's position).
     * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getFirstObjectInShape(int nShapeType, float fSize, NWLocation lTarget, boolean bLineOfSight, int nObjectFilter, NWVector vOrigin) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstObjectInShape");
        pushVector(vOrigin);
        pushInteger(nObjectFilter);
        pushInteger(bLineOfSight ? 1 : 0);
        pushLocation(lTarget);
        pushFloat(fSize);
        pushInteger(nShapeType);
        callFunction(106, 6);
        return popObject();
    }

    /**
     * Get the next object in nShape
     * @param nShapeType SHAPE_*
     * @param fSize:
     * -> If nShape == SHAPE_SPHERE, this is the radius of the sphere
     * -> If nShape == SHAPE_SPELLCYLINDER, this is the length of the cylinder.
     * Spell Cylinder's always have a radius of 1.5m.
     * -> If nShape == SHAPE_CONE, this is the widest radius of the cone
     * -> If nShape == SHAPE_SPELLCONE, this is the length of the cone in the
     * direction of lTarget. Spell cones are always 60 degrees with the origin
     * at OBJECT_SELF.
     * -> If nShape == SHAPE_CUBE, this is half the length of one of the sides of
     * the cube
     * @param lTarget This is the centre of the effect, usually GetSpellTargetLocation(),
     * or the end of a cylinder or cone.
     * @param bLineOfSight This controls whether to do a line-of-sight check on the
     * object returned. (This can be used to ensure that spell effects do not go
     * through walls.) Line of sight check is done from origin to target object
     * at a height 1m above the ground
     * @param nObjectFilter This allows you to filter out undesired object types, using
     * bitwise "or". For example, to return only creatures and doors, the value for
     * this parameter would be OBJECT_TYPE_CREATURE | OBJECT_TYPE_DOOR
     * @param vOrigin This is only used for cylinders and cones, and specifies the origin
     * of the effect (normally the spell-caster's position).
     * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNextObjectInShape(int nShapeType, float fSize, NWLocation lTarget, boolean bLineOfSight, int nObjectFilter, NWVector vOrigin) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextObjectInShape");
        pushVector(vOrigin);
        pushInteger(nObjectFilter);
        pushInteger(bLineOfSight ? 1 : 0);
        pushLocation(lTarget);
        pushFloat(fSize);
        pushInteger(nShapeType);
        callFunction(107, 6);
        return popObject();
    }

    /**
     * Create an Entangle effect
     * When applied, this effect will restrict the creature's movement and apply a
     * (-2) to all attacks and a -4 to AC.
     */
    public static synchronized NWEffect effectEntangle() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectEntangle");
        callFunction(108, 0);
        return popEffect();
    }

    /**
     * Create a Death effect
     * @param bSpectacularDeath if this is TRUE, the creature to which this effect is
     * applied will die in an extraordinary fashion
     * @param bDisplayFeedback
     */
    public static synchronized NWEffect effectDeath(boolean bSpectacularDeath, boolean bDisplayFeedback) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDeath");
        pushInteger(bDisplayFeedback ? 1 : 0);
        pushInteger(bSpectacularDeath ? 1 : 0);
        callFunction(109, 2);
        return popEffect();
    }

    /**
     * Create a Knockdown effect
     * This effect knocks creatures off their feet, they will sit until the effect
     * is removed. This should be applied as a temporary effect with a 3 second
     * duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
     */
    public static synchronized NWEffect effectKnockdown() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectKnockdown");
        callFunction(110, 0);
        return popEffect();
    }

    /**
     * Give oItem to oGiveTo
     * If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
     * happen.
     */
    public static synchronized void actionGiveItem(NWObject oItem, NWObject oGiveTo) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionGiveItem");
        pushObject(oGiveTo);
        pushObject(oItem);
        callFunction(111, 2);
    }

    /**
     * Take oItem from oTakeFrom
     * If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
     * will happen.
     */
    public static synchronized void actionTakeItem(NWObject oItem, NWObject oTakeFrom) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionTakeItem");
        pushObject(oTakeFrom);
        pushObject(oItem);
        callFunction(112, 2);
    }

    /**
     * Normalize vVector
     */
    public static synchronized NWVector vectorNormalize(NWVector vVector) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling vectorNormalize");
        pushVector(vVector);
        callFunction(113, 1);
        return popVector();
    }

    /**
     * Create a Curse effect.
     * @param nStrMod strength modifier
     * @param nDexMod dexterity modifier
     * @param nConMod constitution modifier
     * @param nIntMod intelligence modifier
     * @param nWisMod wisdom modifier
     * @param nChaMod charisma modifier
     */
    public static synchronized NWEffect effectCurse(int nStrMod, int nDexMod, int nConMod, int nIntMod, int nWisMod, int nChaMod) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCurse");
        pushInteger(nChaMod);
        pushInteger(nWisMod);
        pushInteger(nIntMod);
        pushInteger(nConMod);
        pushInteger(nDexMod);
        pushInteger(nStrMod);
        callFunction(114, 6);
        return popEffect();
    }

    /**
     * Get the ability score of type nAbility for a creature (otherwise 0)
     * @param oCreature the creature whose ability score we wish to find out
     * @param nAbility ABILITY_*
     * @param bBaseAbilityScore if set to true will return the base ability score without
     * bonuses (e.g. ability bonuses granted from equipped items).
     * Return value on error: 0
     */
    public static synchronized int getAbilityScore(NWObject oCreature, int nAbility, boolean bBaseAbilityScore) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAbilityScore");
        pushInteger(bBaseAbilityScore ? 1 : 0);
        pushInteger(nAbility);
        pushObject(oCreature);
        callFunction(115, 3);
        return popInteger();
    }

    /**
     * * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
     */
    public static synchronized boolean getIsDead(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDead");
        pushObject(oCreature);
        callFunction(116, 1);
        return popInteger() > 0;
    }

    /**
     * Output vVector to the logfile.
     * @param vVector
     * @param bPrepend if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
     */
    public static synchronized void printVector(NWVector vVector, boolean bPrepend) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling printVector");
        pushInteger(bPrepend ? 1 : 0);
        pushVector(vVector);
        callFunction(117, 2);
    }

    /**
     * Create a vector with the specified values for x, y and z
     */
    public static synchronized NWVector vector(float x, float y, float z) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling vector");
        pushFloat(z);
        pushFloat(y);
        pushFloat(x);
        callFunction(118, 3);
        return popVector();
    }

    /**
     * Cause the caller to face vTarget
     */
    public static synchronized void setFacingPoint(NWVector vTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFacingPoint");
        pushVector(vTarget);
        callFunction(119, 1);
    }

    /**
     * Convert fAngle to a vector
     */
    public static synchronized NWVector angleToVector(float fAngle) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling angleToVector");
        pushFloat(fAngle);
        callFunction(120, 1);
        return popVector();
    }

    /**
     * Convert vVector to an angle
     */
    public static synchronized float vectorToAngle(NWVector vVector) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling vectorToAngle");
        pushVector(vVector);
        callFunction(121, 1);
        return popFloat();
    }

    /**
     * The caller will perform a Melee Touch Attack on oTarget
     * This is not an action, and it assumes the caller is already within range of
     * oTarget
     * * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
     */
    public static synchronized int touchAttackMelee(NWObject oTarget, boolean bDisplayFeedback) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling touchAttackMelee");
        pushInteger(bDisplayFeedback ? 1 : 0);
        pushObject(oTarget);
        callFunction(122, 2);
        return popInteger();
    }

    /**
     * The caller will perform a Ranged Touch Attack on oTarget
     * * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
     */
    public static synchronized int touchAttackRanged(NWObject oTarget, boolean bDisplayFeedback) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling touchAttackRanged");
        pushInteger(bDisplayFeedback ? 1 : 0);
        pushObject(oTarget);
        callFunction(123, 2);
        return popInteger();
    }

    /**
     * Create a Paralyze effect
     */
    public static synchronized NWEffect effectParalyze() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectParalyze");
        callFunction(124, 0);
        return popEffect();
    }

    /**
     * Create a Spell Immunity effect.
     * There is a known bug with this function. There *must* be a parameter specified
     * when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
     * otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
     * @param nImmunityToSpell SPELL_*
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
     * invalid.
     */
    public static synchronized NWEffect effectSpellImmunity(int nImmunityToSpell) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSpellImmunity");
        pushInteger(nImmunityToSpell);
        callFunction(125, 1);
        return popEffect();
    }

    /**
     * Create a Deaf effect
     */
    public static synchronized NWEffect effectDeaf() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDeaf");
        callFunction(126, 0);
        return popEffect();
    }

    /**
     * Get the distance in metres between oObjectA and oObjectB.
     * * Return value if either object is invalid: 0.0f
     */
    public static synchronized float getDistanceBetween(NWObject oObjectA, NWObject oObjectB) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDistanceBetween");
        pushObject(oObjectB);
        pushObject(oObjectA);
        callFunction(127, 2);
        return popFloat();
    }

    /**
     * Set oObject's local location variable sVarname to lValue
     */
    public static synchronized void setLocalLocation(NWObject oObject, String sVarName, NWLocation lValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocalLocation");
        pushLocation(lValue);
        pushString(sVarName);
        pushObject(oObject);
        callFunction(128, 3);
    }

    /**
     * Get oObject's local location variable sVarname
     */
    public static synchronized NWLocation getLocalLocation(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocalLocation");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(129, 2);
        return popLocation();
    }

    /**
     * Create a Sleep effect
     */
    public static synchronized NWEffect effectSleep() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSleep");
        callFunction(130, 0);
        return popEffect();
    }

    /**
     * Get the object which is in oCreature's specified inventory slot
     * @param nInventorySlot INVENTORY_SLOT_*
     * @param oCreature
     * * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
     * item in nInventorySlot.
     */
    public static synchronized NWObject getItemInSlot(int nInventorySlot, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemInSlot");
        pushObject(oCreature);
        pushInteger(nInventorySlot);
        callFunction(131, 2);
        return popObject();
    }

    /**
     * Create a Charm effect
     */
    public static synchronized NWEffect effectCharmed() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCharmed");
        callFunction(132, 0);
        return popEffect();
    }

    /**
     * Create a Confuse effect
     */
    public static synchronized NWEffect effectConfused() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectConfused");
        callFunction(133, 0);
        return popEffect();
    }

    /**
     * Create a Frighten effect
     */
    public static synchronized NWEffect effectFrightened() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectFrightened");
        callFunction(134, 0);
        return popEffect();
    }

    /**
     * Create a Dominate effect
     */
    public static synchronized NWEffect effectDominated() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDominated");
        callFunction(135, 0);
        return popEffect();
    }

    /**
     * Create a Daze effect
     */
    public static synchronized NWEffect effectDazed() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDazed");
        callFunction(136, 0);
        return popEffect();
    }

    /**
     * Create a Stun effect
     */
    public static synchronized NWEffect effectStunned() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectStunned");
        callFunction(137, 0);
        return popEffect();
    }

    /**
     * Set whether oTarget's action stack can be modified
     */
    public static synchronized void setCommandable(boolean bCommandable, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCommandable");
        pushObject(oTarget);
        pushInteger(bCommandable ? 1 : 0);
        callFunction(138, 2);
    }

    /**
     * Determine whether oTarget's action stack can be modified.
     */
    public static synchronized boolean getCommandable(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCommandable");
        pushObject(oTarget);
        callFunction(139, 1);
        return popInteger() > 0;
    }

    /**
     * Create a Regenerate effect.
     * @param nAmount amount of damage to be regenerated per time interval
     * @param fIntervalSeconds length of interval in seconds
     */
    public static synchronized NWEffect effectRegenerate(int nAmount, float fIntervalSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectRegenerate");
        pushFloat(fIntervalSeconds);
        pushInteger(nAmount);
        callFunction(140, 2);
        return popEffect();
    }

    /**
     * Create a Movement Speed Increase effect.
     * @param nPercentChange - range 0 through 99
     * eg.
     * 0 = no change in speed
     * 50 = 50% faster
     * 99 = almost twice as fast
     */
    public static synchronized NWEffect effectMovementSpeedIncrease(int nPercentChange) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectMovementSpeedIncrease");
        pushInteger(nPercentChange);
        callFunction(141, 1);
        return popEffect();
    }

    /**
     * Get the number of hitdice for oCreature.
     * * Return value if oCreature is not a valid creature: 0
     */
    public static synchronized int getHitDice(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHitDice");
        pushObject(oCreature);
        callFunction(142, 1);
        return popInteger();
    }

    /**
     * The action subject will follow oFollow until a ClearAllActions() is called.
     * @param oFollow this is the object to be followed
     * @param fFollowDistance follow distance in metres
     * * No return value
     */
    public static synchronized void actionForceFollowObject(NWObject oFollow, float fFollowDistance) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionForceFollowObject");
        pushFloat(fFollowDistance);
        pushObject(oFollow);
        callFunction(143, 2);
    }

    /**
     * Get the Tag of oObject
     * * Return value if oObject is not a valid object: ""
     */
    public static synchronized String getTag(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTag");
        pushObject(oObject);
        callFunction(144, 1);
        return popString();
    }

    /**
     * Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
     * the spell was resisted.
     * * Return value if oCaster or oTarget is an invalid object: FALSE
     * * Return value if spell cast is not a player spell: @param 1
     * * Return value if spell resisted: 1
     * * Return value if spell resisted via magic immunity: 2
     * * Return value if spell resisted via spell absorption: 3
     */
    public static synchronized int resistSpell(NWObject oCaster, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling resistSpell");
        pushObject(oTarget);
        pushObject(oCaster);
        callFunction(145, 2);
        return popInteger();
    }

    /**
     * Get the effect type (EFFECT_TYPE_*) of eEffect.
     * * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
     */
    public static synchronized int getEffectType(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectType");
        pushEffect(eEffect);
        callFunction(146, 1);
        return popInteger();
    }

    /**
     * Create an Area Of Effect effect in the area of the creature it is applied to.
     * If the scripts are not specified, default ones will be used.
     */
    public static synchronized NWEffect effectAreaOfEffect(int nAreaEffectId, String sOnEnterScript, String sHeartbeatScript, String sOnExitScript) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAreaOfEffect");
        pushString(sOnExitScript);
        pushString(sHeartbeatScript);
        pushString(sOnEnterScript);
        pushInteger(nAreaEffectId);
        callFunction(147, 4);
        return popEffect();
    }

    /**
     * * Returns TRUE if the Faction Ids of the two objects are the same
     */
    public static synchronized boolean getFactionEqual(NWObject oFirstObject, NWObject oSecondObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionEqual");
        pushObject(oSecondObject);
        pushObject(oFirstObject);
        callFunction(148, 2);
        return popInteger() > 0;
    }

    /**
     * Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
     * NB. ** This will only work for two NPCs **
     */
    public static synchronized void changeFaction(NWObject oObjectToChangeFaction, NWObject oMemberOfFactionToJoin) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling changeFaction");
        pushObject(oMemberOfFactionToJoin);
        pushObject(oObjectToChangeFaction);
        callFunction(149, 2);
    }

    /**
     * * Returns TRUE if oObject is listening for something
     */
    public static synchronized boolean getIsListening(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsListening");
        pushObject(oObject);
        callFunction(150, 1);
        return popInteger() > 0;
    }

    /**
     * Set whether oObject is listening.
     */
    public static synchronized void setListening(NWObject oObject, boolean bValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setListening");
        pushInteger(bValue ? 1 : 0);
        pushObject(oObject);
        callFunction(151, 2);
    }

    /**
     * Set the string for oObject to listen for.
     * Note: this does not set oObject to be listening.
     */
    public static synchronized void setListenPattern(NWObject oObject, String sPattern, int nNumber) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setListenPattern");
        pushInteger(nNumber);
        pushString(sPattern);
        pushObject(oObject);
        callFunction(152, 3);
    }

    /**
     * * Returns TRUE if sStringToTest matches sPattern.
     */
    public static synchronized int testStringAgainstPattern(String sPattern, String sStringToTest) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling testStringAgainstPattern");
        pushString(sStringToTest);
        pushString(sPattern);
        callFunction(153, 2);
        return popInteger();
    }

    /**
     * Get the appropriate matched string (this should only be used in
     * OnConversation scripts).
     * * Returns the appropriate matched string, otherwise returns ""
     */
    public static synchronized String getMatchedSubstring(int nString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMatchedSubstring");
        pushInteger(nString);
        callFunction(154, 1);
        return popString();
    }

    /**
     * Get the number of string parameters available.
     * * Returns -1 if no string matched (this could be because of a dialogue event)
     */
    public static synchronized int getMatchedSubstringsCount() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMatchedSubstringsCount");
        callFunction(155, 0);
        return popInteger();
    }

    /**
     * * Create a Visual Effect that can be applied to an object.
     * @param nVisualEffectId
     * @param bMissEffect if this is TRUE, a random vector near or past the target will
     * be generated, on which to play the effect
     */
    public static synchronized NWEffect effectVisualEffect(int nVisualEffectId, boolean bMissEffect) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectVisualEffect");
        pushInteger(bMissEffect ? 1 : 0);
        pushInteger(nVisualEffectId);
        callFunction(156, 2);
        return popEffect();
    }

    /**
     * Get the weakest member of oFactionMember's faction.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionWeakestMember(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionWeakestMember");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(157, 2);
        return popObject();
    }

    /**
     * Get the strongest member of oFactionMember's faction.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionStrongestMember(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionStrongestMember");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(158, 2);
        return popObject();
    }

    /**
     * Get the member of oFactionMember's faction that has taken the most hit points
     * of damage.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionMostDamagedMember(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionMostDamagedMember");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(159, 2);
        return popObject();
    }

    /**
     * Get the member of oFactionMember's faction that has taken the fewest hit
     * points of damage.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionLeastDamagedMember(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionLeastDamagedMember");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(160, 2);
        return popObject();
    }

    /**
     * Get the amount of gold held by oFactionMember's faction.
     * * Returns -1 if oFactionMember's faction is invalid.
     */
    public static synchronized int getFactionGold(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionGold");
        pushObject(oFactionMember);
        callFunction(161, 1);
        return popInteger();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) that represents how
     * oSourceFactionMember's faction feels about oTarget.
     * * Return value on error: -1
     */
    public static synchronized int getFactionAverageReputation(NWObject oSourceFactionMember, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionAverageReputation");
        pushObject(oTarget);
        pushObject(oSourceFactionMember);
        callFunction(162, 2);
        return popInteger();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) that represents the average
     * good/evil alignment of oFactionMember's faction.
     * * Return value on error: -1
     */
    public static synchronized int getFactionAverageGoodEvilAlignment(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionAverageGoodEvilAlignment");
        pushObject(oFactionMember);
        callFunction(163, 1);
        return popInteger();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) that represents the average
     * law/chaos alignment of oFactionMember's faction.
     * * Return value on error: -1
     */
    public static synchronized int getFactionAverageLawChaosAlignment(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionAverageLawChaosAlignment");
        pushObject(oFactionMember);
        callFunction(164, 1);
        return popInteger();
    }

    /**
     * Get the average level of the members of the faction.
     * * Return value on error: -1
     */
    public static synchronized int getFactionAverageLevel(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionAverageLevel");
        pushObject(oFactionMember);
        callFunction(165, 1);
        return popInteger();
    }

    /**
     * Get the average XP of the members of the faction.
     * * Return value on error: -1
     */
    public static synchronized int getFactionAverageXP(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionAverageXP");
        pushObject(oFactionMember);
        callFunction(166, 1);
        return popInteger();
    }

    /**
     * Get the most frequent class in the faction @param this can be compared with the
     * constants CLASS_TYPE_*.
     * * Return value on error: -1
     */
    public static synchronized int getFactionMostFrequentClass(NWObject oFactionMember) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionMostFrequentClass");
        pushObject(oFactionMember);
        callFunction(167, 1);
        return popInteger();
    }

    /**
     * Get the object faction member with the lowest armour class.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionWorstAC(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionWorstAC");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(168, 2);
        return popObject();
    }

    /**
     * Get the object faction member with the highest armour class.
     * * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
     */
    public static synchronized NWObject getFactionBestAC(NWObject oFactionMember, boolean bMustBeVisible) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionBestAC");
        pushInteger(bMustBeVisible ? 1 : 0);
        pushObject(oFactionMember);
        callFunction(169, 2);
        return popObject();
    }

    /**
     * Sit in oChair.
     * Note: Not all creatures will be able to sit and not all
     * objects can be sat on.
     * The object oChair must also be marked as usable in the toolset.
     *
     * For Example: To get a player to sit in oChair when they click on it,
     * place the following script in the OnUsed event for the object oChair.
     * void main()
     * {
     * object oChair = OBJECT_SELF;
     * AssignCommand(GetLastUsedBy(),ActionSit(oChair));
     * }
     */
    public static synchronized void actionSit(NWObject oChair) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionSit");
        pushObject(oChair);
        callFunction(170, 1);
    }

    /**
     * In an onConversation script this gets the number of the string pattern
     * matched (the one that triggered the script).
     * * Returns -1 if no string matched
     */
    public static synchronized int getListenPatternNumber() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getListenPatternNumber");
        callFunction(171, 0);
        return popInteger();
    }

    /**
     * Jump to an object ID, or as near to it as possible.
     */
    public static synchronized void actionJumpToObject(NWObject oToJumpTo, boolean bWalkStraightLineToPoint) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionJumpToObject");
        pushInteger(bWalkStraightLineToPoint ? 1 : 0);
        pushObject(oToJumpTo);
        callFunction(172, 2);
    }

    /**
     * Get the first waypoint with the specified tag.
     * * Returns OBJECT_INVALID if the waypoint cannot be found.
     */
    public static synchronized NWObject getWaypointByTag(String sWaypointTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getWaypointByTag");
        pushString(sWaypointTag);
        callFunction(173, 1);
        return popObject();
    }

    /**
     * Get the destination object for the given object.
     *
     * All objects can hold a transition target, but only Doors and Triggers
     * will be made clickable by the game engine (This may change in the
     * future). You can set and query transition targets on other objects for
     * your own scripted purposes.
     *
     * * Returns OBJECT_INVALID if oTransition does not hold a target.
     */
    public static synchronized NWObject getTransitionTarget(NWObject oTransition) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTransitionTarget");
        pushObject(oTransition);
        callFunction(174, 1);
        return popObject();
    }

    /**
     * Link the two supplied effects, returning eChildEffect as a child of
     * eParentEffect.
     * Note: When applying linked effects if the target is immune to all valid
     * effects all other effects will be removed as well. This means that if you
     * apply a visual effect and a silence effect (in a link) and the target is
     * immune to the silence effect that the visual effect will get removed as well.
     * Visual Effects are not considered "valid" effects for the purposes of
     * determining if an effect will be removed or not and as such should never be
     * packaged *only* with other visual effects in a link.
     */
    public static synchronized NWEffect effectLinkEffects(NWEffect eChildEffect, NWEffect eParentEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectLinkEffects");
        pushEffect(eParentEffect);
        pushEffect(eChildEffect);
        callFunction(175, 2);
        return popEffect();
    }

    /**
     * Get the nNth object with the specified tag.
     * @param sTag
     * @param nNth the nth object with this tag may be requested
     * * Returns OBJECT_INVALID if the object cannot be found.
     * Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
     */
    public static synchronized NWObject getObjectByTag(String sTag, int nNth) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getObjectByTag");
        pushInteger(nNth);
        pushString(sTag);
        callFunction(176, 2);
        return popObject();
    }

    /**
     * Adjust the alignment of oSubject.
     * @param oSubject
     * @param nAlignment:
     * -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
     * alignment will be shifted in the direction specified
     * -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
     * good/evil alignment values
     * -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
     * good/evil alignment values in the direction which is towards neutrality.
     * e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
     * good/evil value of 80 (i.e. good) then if nShift is 15, the
     * law/chaos value will become (10+15)=25 and the good/evil value will
     * become (80-25)=55
     * Furthermore, the shift will at most take the alignment value to 50 and
     * not beyond.
     * e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
     * then if nShift is 15, the law/chaos value will become 50 and the
     * good/evil value will become 55
     * @param nShift this is the desired shift in alignment
     * @param bAllPartyMembers when TRUE the alignment shift of oSubject also has a
     * diminished affect all members of oSubject's party (if oSubject is a Player).
     * When FALSE the shift only affects oSubject.
     * * No return value
     */
    public static synchronized void adjustAlignment(NWObject oSubject, int nAlignment, int nShift, boolean bAllPartyMembers) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling adjustAlignment");
        pushInteger(bAllPartyMembers ? 1 : 0);
        pushInteger(nShift);
        pushInteger(nAlignment);
        pushObject(oSubject);
        callFunction(177, 4);
    }

    /**
     * Do nothing for fSeconds seconds.
     */
    public static synchronized void actionWait(float fSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionWait");
        pushFloat(fSeconds);
        callFunction(178, 1);
    }

    /**
     * Set the transition bitmap of a player; this should only be called in area
     * transition scripts. This action should be run by the person "clicking" the
     * area transition via AssignCommand.
     * @param nPredefinedAreaTransition:
     * -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
     * -> To use a custom, user-defined area transition bitmap, use
     * AREA_TRANSITION_USER_DEFINED and specify the filename in the second
     * parameter
     * @param sCustomAreaTransitionBMP this is the filename of a custom, user-defined
     * area transition bitmap
     */
    public static synchronized void setAreaTransitionBMP(int nPredefinedAreaTransition, String sCustomAreaTransitionBMP) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setAreaTransitionBMP");
        pushString(sCustomAreaTransitionBMP);
        pushInteger(nPredefinedAreaTransition);
        callFunction(179, 2);
    }

    /**
     * Starts a conversation with oObjectToConverseWith @param this will cause their
     * OnDialog event to fire.
     * @param oObjectToConverseWith
     * @param sDialogResRef If this is blank, the creature's own dialogue file will be used
     * @param bPrivateConversation
     * Turn off bPlayHello if you don't want the initial greeting to play
     */
    public static synchronized void actionStartConversation(NWObject oObjectToConverseWith, String sDialogResRef, boolean bPrivateConversation, boolean bPlayHello) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionStartConversation");
        pushInteger(bPlayHello ? 1 : 0);
        pushInteger(bPrivateConversation ? 1 : 0);
        pushString(sDialogResRef);
        pushObject(oObjectToConverseWith);
        callFunction(180, 4);
    }

    /**
     * Pause the current conversation.
     */
    public static synchronized void actionPauseConversation() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionPauseConversation");
        callFunction(181, 0);
    }

    /**
     * Resume a conversation after it has been paused.
     */
    public static synchronized void actionResumeConversation() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionResumeConversation");
        callFunction(182, 0);
    }

    /**
     * Create a Beam effect.
     * @param nBeamVisualEffect VFX_BEAM_*
     * @param oEffector the beam is emitted from this creature
     * @param nCreaturePart BODY_NODE_*
     * @param bMissEffect If this is TRUE, the beam will fire to a random vector near or
     * past the target
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
     * not valid.
     */
    public static synchronized NWEffect effectBeam(int nBeamVisualEffect, NWObject oEffector, int nCreaturePart, boolean bMissEffect) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectBeam");
        pushInteger(bMissEffect ? 1 : 0);
        pushInteger(nCreaturePart);
        pushObject(oEffector);
        pushInteger(nBeamVisualEffect);
        callFunction(183, 4);
        return popEffect();
    }

    /**
     * Get an integer between 0 and 100 (inclusive) that represents how oSource
     * feels about oTarget.
     * -> 0-10 means oSource is hostile to oTarget
     * -> 11-89 means oSource is neutral to oTarget
     * -> 90-100 means oSource is friendly to oTarget
     * * Returns -1 if oSource or oTarget does not identify a valid object
     */
    public static synchronized int getReputation(NWObject oSource, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getReputation");
        pushObject(oTarget);
        pushObject(oSource);
        callFunction(184, 2);
        return popInteger();
    }

    /**
     * Adjust how oSourceFactionMember's faction feels about oTarget by the
     * specified amount.
     * Note: This adjusts Faction Reputation, how the entire faction that
     * oSourceFactionMember is in, feels about oTarget.
     * * No return value
     * Note: You can't adjust a player character's (PC) faction towards
     * NPCs, so attempting to make an NPC hostile by passing in a PC object
     * as oSourceFactionMember in the following call will fail:
     * AdjustReputation(oNPC,oPC,-100);
     * Instead you should pass in the PC object as the first
     * parameter as in the following call which should succeed:
     * AdjustReputation(oPC,oNPC,-100);
     * Note: Will fail if oSourceFactionMember is a plot object.
     */
    public static synchronized void adjustReputation(NWObject oTarget, NWObject oSourceFactionMember, int nAdjustment) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling adjustReputation");
        pushInteger(nAdjustment);
        pushObject(oSourceFactionMember);
        pushObject(oTarget);
        callFunction(185, 3);
    }

    /**
     * Get the creature that is currently sitting on the specified object.
     * @param oChair
     * * Returns OBJECT_INVALID if oChair is not a valid placeable.
     */
    public static synchronized NWObject getSittingCreature(NWObject oChair) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSittingCreature");
        pushObject(oChair);
        callFunction(186, 1);
        return popObject();
    }

    /**
     * Get the creature that is going to attack oTarget.
     * Note: This value is cleared out at the end of every combat round and should
     * not be used in any case except when getting a "going to be attacked" shout
     * from the master creature (and this creature is a henchman)
     * * Returns OBJECT_INVALID if oTarget is not a valid creature.
     */
    public static synchronized NWObject getGoingToBeAttackedBy(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGoingToBeAttackedBy");
        pushObject(oTarget);
        callFunction(187, 1);
        return popObject();
    }

    /**
     * Create a Spell Resistance Increase effect.
     * @param nValue size of spell resistance increase
     */
    public static synchronized NWEffect effectSpellResistanceIncrease(int nValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSpellResistanceIncrease");
        pushInteger(nValue);
        callFunction(188, 1);
        return popEffect();
    }

    /**
     * Get the location of oObject.
     */
    public static synchronized NWLocation getLocation(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocation");
        pushObject(oObject);
        callFunction(189, 1);
        return popLocation();
    }

    /**
     * The subject will jump to lLocation instantly (even between areas).
     * If lLocation is invalid, nothing will happen.
     */
    public static synchronized void actionJumpToLocation(NWLocation lLocation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionJumpToLocation");
        pushLocation(lLocation);
        callFunction(190, 1);
    }

    /**
     * Create a location.
     */
    public static synchronized NWLocation location(NWObject oArea, NWVector vPosition, float fOrientation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling location");
        pushFloat(fOrientation);
        pushVector(vPosition);
        pushObject(oArea);
        callFunction(191, 3);
        return popLocation();
    }

    /**
     * Apply eEffect at lLocation.
     */
    public static synchronized void applyEffectAtLocation(int nDurationType, NWEffect eEffect, NWLocation lLocation, float fDuration) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling applyEffectAtLocation");
        pushFloat(fDuration);
        pushLocation(lLocation);
        pushEffect(eEffect);
        pushInteger(nDurationType);
        callFunction(192, 4);
    }

    /**
     * * Returns TRUE if oCreature is a Player Controlled character.
     */
    public static synchronized boolean getIsPC(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsPC");
        pushObject(oCreature);
        callFunction(193, 1);
        return popInteger() > 0;
    }

    /**
     * Convert fFeet into a number of meters.
     */
    public static synchronized float feetToMeters(float fFeet) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling feetToMeters");
        pushFloat(fFeet);
        callFunction(194, 1);
        return popFloat();
    }

    /**
     * Convert fYards into a number of meters.
     */
    public static synchronized float yardsToMeters(float fYards) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling yardsToMeters");
        pushFloat(fYards);
        callFunction(195, 1);
        return popFloat();
    }

    /**
     * Apply eEffect to oTarget.
     */
    public static synchronized void applyEffectToObject(int nDurationType, NWEffect eEffect, NWObject oTarget, float fDuration) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling applyEffectToObject");
        pushFloat(fDuration);
        pushObject(oTarget);
        pushEffect(eEffect);
        pushInteger(nDurationType);
        callFunction(196, 4);
    }

    /**
     * The caller will immediately speak sStringToSpeak (this is different from
     * ActionSpeakString)
     * @param sStringToSpeak
     * @param nTalkVolume TALKVOLUME_*
     */
    public static synchronized void speakString(String sStringToSpeak, int nTalkVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling speakString");
        pushInteger(nTalkVolume);
        pushString(sStringToSpeak);
        callFunction(197, 2);
    }

    /**
     * Get the location of the caller's last spell target.
     */
    public static synchronized NWLocation getSpellTargetLocation() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellTargetLocation");
        callFunction(198, 0);
        return popLocation();
    }

    /**
     * Get the position vector from lLocation.
     */
    public static synchronized NWVector getPositionFromLocation(NWLocation lLocation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPositionFromLocation");
        pushLocation(lLocation);
        callFunction(199, 1);
        return popVector();
    }

    /**
     * Get the area's object ID from lLocation.
     */
    public static synchronized NWObject getAreaFromLocation(NWLocation lLocation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAreaFromLocation");
        pushLocation(lLocation);
        callFunction(200, 1);
        return popObject();
    }

    /**
     * Get the orientation value from lLocation.
     */
    public static synchronized float getFacingFromLocation(NWLocation lLocation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFacingFromLocation");
        pushLocation(lLocation);
        callFunction(201, 1);
        return popFloat();
    }

    /**
     * Get the creature nearest to lLocation, subject to all the criteria specified.
     * @param nFirstCriteriaType CREATURE_TYPE_*
     * @param nFirstCriteriaValue:
     * -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
     * -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
     * or CREATURE_TYPE_HAS_SPELL_EFFECT
     * -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
     * -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
     * -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
     * CREATURE_TYPE_PLAYER_CHAR
     * -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
     * -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
     * For example, to get the nearest PC, use
     * (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
     * @param lLocation We're trying to find the creature of the specified type that is
     * nearest to lLocation
     * @param nNth We don't have to find the first nearest: we can find the Nth nearest....
     * @param nSecondCriteriaType This is used in the same way as nFirstCriteriaType to
     * further specify the type of creature that we are looking for.
     * @param nSecondCriteriaValue This is used in the same way as nFirstCriteriaValue
     * to further specify the type of creature that we are looking for.
     * @param nThirdCriteriaType This is used in the same way as nFirstCriteriaType to
     * further specify the type of creature that we are looking for.
     * @param nThirdCriteriaValue This is used in the same way as nFirstCriteriaValue to
     * further specify the type of creature that we are looking for.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNearestCreatureToLocation(int nFirstCriteriaType, int nFirstCriteriaValue, NWLocation lLocation, int nNth, int nSecondCriteriaType, int nSecondCriteriaValue, int nThirdCriteriaType, int nThirdCriteriaValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestCreatureToLocation");
        pushInteger(nThirdCriteriaValue);
        pushInteger(nThirdCriteriaType);
        pushInteger(nSecondCriteriaValue);
        pushInteger(nSecondCriteriaType);
        pushInteger(nNth);
        pushLocation(lLocation);
        pushInteger(nFirstCriteriaValue);
        pushInteger(nFirstCriteriaType);
        callFunction(202, 8);
        return popObject();
    }

    /**
     * Get the Nth object nearest to oTarget that is of the specified type.
     * @param nObjectType OBJECT_TYPE_*
     * @param oTarget
     * @param nNth
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNearestObject(int nObjectType, NWObject oTarget, int nNth) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestObject");
        pushInteger(nNth);
        pushObject(oTarget);
        pushInteger(nObjectType);
        callFunction(203, 3);
        return popObject();
    }

    /**
     * Get the nNth object nearest to lLocation that is of the specified type.
     * @param nObjectType OBJECT_TYPE_*
     * @param lLocation
     * @param nNth
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNearestObjectToLocation(int nObjectType, NWLocation lLocation, int nNth) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestObjectToLocation");
        pushInteger(nNth);
        pushLocation(lLocation);
        pushInteger(nObjectType);
        callFunction(204, 3);
        return popObject();
    }

    /**
     * Get the nth Object nearest to oTarget that has sTag as its tag.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getNearestObjectByTag(String sTag, NWObject oTarget, int nNth) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestObjectByTag");
        pushInteger(nNth);
        pushObject(oTarget);
        pushString(sTag);
        callFunction(205, 3);
        return popObject();
    }

    /**
     * Convert nInteger into a floating point number.
     */
    public static synchronized float intToFloat(int nInteger) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling intToFloat");
        pushInteger(nInteger);
        callFunction(206, 1);
        return popFloat();
    }

    /**
     * Convert fFloat into the nearest integer.
     */
    public static synchronized int floatToInt(float fFloat) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling floatToInt");
        pushFloat(fFloat);
        callFunction(207, 1);
        return popInteger();
    }

    /**
     * Convert sNumber into an integer.
     */
    public static synchronized int stringToInt(String sNumber) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling stringToInt");
        pushString(sNumber);
        callFunction(208, 1);
        return popInteger();
    }

    /**
     * Convert sNumber into a floating point number.
     */
    public static synchronized float stringToFloat(String sNumber) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling stringToFloat");
        pushString(sNumber);
        callFunction(209, 1);
        return popFloat();
    }

    /**
     * Cast spell nSpell at lTargetLocation.
     * @param nSpell SPELL_*
     * @param lTargetLocation
     * @param nMetaMagic METAMAGIC_*
     * @param bCheat If this is TRUE, then the executor of the action doesn't have to be
     * able to cast the spell.
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     * @param bInstantSpell If this is TRUE, the spell is cast immediately; this allows
     * the end-user to simulate
     * a high-level magic user having lots of advance warning of impending trouble.
     */
    public static synchronized void actionCastSpellAtLocation(int nSpell, NWLocation lTargetLocation, int nMetaMagic, boolean bCheat, int nProjectilePathType, boolean bInstantSpell) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCastSpellAtLocation");
        pushInteger(bInstantSpell ? 1 : 0);
        pushInteger(nProjectilePathType);
        pushInteger(bCheat ? 1 : 0);
        pushInteger(nMetaMagic);
        pushLocation(lTargetLocation);
        pushInteger(nSpell);
        callFunction(210, 6);
    }

    /**
     * * Returns TRUE if oSource considers oTarget as an enemy.
     */
    public static synchronized boolean getIsEnemy(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsEnemy");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(211, 2);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if oSource considers oTarget as a friend.
     */
    public static synchronized boolean getIsFriend(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsFriend");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(212, 2);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if oSource considers oTarget as neutral.
     */
    public static synchronized boolean getIsNeutral(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsNeutral");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(213, 2);
        return popInteger() > 0;
    }

    /**
     * Get the PC that is involved in the conversation.
     * * Returns OBJECT_INVALID on error.
     */
    public static synchronized NWObject getPCSpeaker() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCSpeaker");
        callFunction(214, 0);
        return popObject();
    }

    /**
     * Get a string from the talk table using nStrRef.
     */
    public static synchronized String getStringByStrRef(int nStrRef, int nGender) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStringByStrRef");
        pushInteger(nGender);
        pushInteger(nStrRef);
        callFunction(215, 2);
        return popString();
    }

    /**
     * Causes the creature to speak a translated string.
     * @param nStrRef Reference of the string in the talk table
     * @param nTalkVolume TALKVOLUME_*
     */
    public static synchronized void actionSpeakStringByStrRef(int nStrRef, int nTalkVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionSpeakStringByStrRef");
        pushInteger(nTalkVolume);
        pushInteger(nStrRef);
        callFunction(216, 2);
    }

    /**
     * Destroy oObject (irrevocably).
     * This will not work on modules and areas.
     */
    public static synchronized void destroyObject(NWObject oDestroy, float fDelay) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling destroyObject");
        pushFloat(fDelay);
        pushObject(oDestroy);
        callFunction(217, 2);
    }

    /**
     * Get the module.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getModule() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModule");
        callFunction(218, 0);
        return popObject();
    }

    /**
     * Create an object of the specified type at lLocation.
     * @param nObjectType OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
     * OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
     * @param sTemplate
     * @param lLocation
     * @param bUseAppearAnimation
     * @param sNewTag - if this string is not empty, it will replace the default tag from the template
     */
    public static synchronized NWObject createObject(int nObjectType, String sTemplate, NWLocation lLocation, boolean bUseAppearAnimation, String sNewTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling createObject");
        pushString(sNewTag);
        pushInteger(bUseAppearAnimation ? 1 : 0);
        pushLocation(lLocation);
        pushString(sTemplate);
        pushInteger(nObjectType);
        callFunction(219, 5);
        return popObject();
    }

    /**
     * This is for use in a "Spell Cast" script, it gets who cast the spell.
     * The spell could have been cast by a creature, placeable or door.
     * * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
     */
    public static synchronized NWObject getLastSpellCaster() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastSpellCaster");
        callFunction(220, 0);
        return popObject();
    }

    /**
     * This is for use in a "Spell Cast" script, it gets the ID of the spell that
     * was cast.
     */
    public static synchronized int getLastSpell() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastSpell");
        callFunction(221, 0);
        return popInteger();
    }

    /**
     * This is for use in a user-defined script, it gets the event number.
     */
    public static synchronized int getUserDefinedEventNumber() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getUserDefinedEventNumber");
        callFunction(222, 0);
        return popInteger();
    }

    /**
     * This is for use in a Spell script, it gets the ID of the spell that is being
     * cast (SPELL_*).
     */
    public static synchronized int getSpellId() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellId");
        callFunction(223, 0);
        return popInteger();
    }

    /**
     * Generate a random name.
     * nNameType: The type of random name to be generated (NAME_*)
     */
    public static synchronized String randomName(int nNameType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling randomName");
        pushInteger(nNameType);
        callFunction(224, 1);
        return popString();
    }

    /**
     * Create a Poison effect.
     * @param nPoisonType POISON_*
     */
    public static synchronized NWEffect effectPoison(int nPoisonType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectPoison");
        pushInteger(nPoisonType);
        callFunction(225, 1);
        return popEffect();
    }

    /**
     * Create a Disease effect.
     * @param nDiseaseType DISEASE_*
     */
    public static synchronized NWEffect effectDisease(int nDiseaseType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDisease");
        pushInteger(nDiseaseType);
        callFunction(226, 1);
        return popEffect();
    }

    /**
     * Create a Silence effect.
     */
    public static synchronized NWEffect effectSilence() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSilence");
        callFunction(227, 0);
        return popEffect();
    }

    /**
     * Set the name of oObject.
     *
     * @param oObject the object for which you are changing the name (area, creature, placeable, item, or door).
     * @param sNewName the new name that the object will use.
     * Note: SetName() does not work on player objects.
     * Setting an object's name to "" will make the object
     * revert to using the name it had originally before any
     * SetName() calls were made on the object.
     */
    public static synchronized String getName(NWObject oObject, boolean bOriginalName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getName");
        pushInteger(bOriginalName ? 1 : 0);
        pushObject(oObject);
        callFunction(228, 2);
        return popString();
    }

    /**
     * Use this in a conversation script to get the person with whom you are conversing.
     * * Returns OBJECT_INVALID if the caller is not a valid creature.
     */
    public static synchronized NWObject getLastSpeaker() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastSpeaker");
        callFunction(229, 0);
        return popObject();
    }

    /**
     * Use this in an OnDialog script to start up the dialog tree.
     * @param sResRef if this is not specified, the default dialog file will be used
     * @param oObjectToDialog if this is not specified the person that triggered the
     * event will be used
     */
    public static synchronized int beginConversation(String sResRef, NWObject oObjectToDialog) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling beginConversation");
        pushObject(oObjectToDialog);
        pushString(sResRef);
        callFunction(230, 2);
        return popInteger();
    }

    /**
     * Use this in an OnPerception script to get the object that was perceived.
     * * Returns OBJECT_INVALID if the caller is not a valid creature.
     */
    public static synchronized NWObject getLastPerceived() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPerceived");
        callFunction(231, 0);
        return popObject();
    }

    /**
     * Use this in an OnPerception script to determine whether the object that was
     * perceived was heard.
     */
    public static synchronized boolean getLastPerceptionHeard() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPerceptionHeard");
        callFunction(232, 0);
        return popInteger() > 0;
    }

    /**
     * Use this in an OnPerception script to determine whether the object that was
     * perceived has become inaudible.
     */
    public static synchronized boolean getLastPerceptionInaudible() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPerceptionInaudible");
        callFunction(233, 0);
        return popInteger() > 0;
    }

    /**
     * Use this in an OnPerception script to determine whether the object that was
     * perceived was seen.
     */
    public static synchronized boolean getLastPerceptionSeen() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPerceptionSeen");
        callFunction(234, 0);
        return popInteger() > 0;
    }

    /**
     * Use this in an OnClosed script to get the object that closed the door or placeable.
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
     */
    public static synchronized NWObject getLastClosedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastClosedBy");
        callFunction(235, 0);
        return popObject();
    }

    /**
     * Use this in an OnPerception script to determine whether the object that was
     * perceived has vanished.
     */
    public static synchronized boolean getLastPerceptionVanished() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPerceptionVanished");
        callFunction(236, 0);
        return popInteger() > 0;
    }

    /**
     * Get the first object within oPersistentObject.
     * @param oPersistentObject
     * @param nResidentObjectType OBJECT_TYPE_*
     * @param nPersistentZone PERSISTENT_ZONE_ACTIVE. [This could also take the value
     * PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
     * * Returns OBJECT_INVALID if no object is found.
     */
    public static synchronized NWObject getFirstInPersistentObject(NWObject oPersistentObject, int nResidentObjectType, int nPersistentZone) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstInPersistentObject");
        pushInteger(nPersistentZone);
        pushInteger(nResidentObjectType);
        pushObject(oPersistentObject);
        callFunction(237, 3);
        return popObject();
    }

    /**
     * Get the next object within oPersistentObject.
     * @param oPersistentObject
     * @param nResidentObjectType OBJECT_TYPE_*
     * @param nPersistentZone PERSISTENT_ZONE_ACTIVE. [This could also take the value
     * PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
     * * Returns OBJECT_INVALID if no object is found.
     */
    public static synchronized NWObject getNextInPersistentObject(NWObject oPersistentObject, int nResidentObjectType, int nPersistentZone) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextInPersistentObject");
        pushInteger(nPersistentZone);
        pushInteger(nResidentObjectType);
        pushObject(oPersistentObject);
        callFunction(238, 3);
        return popObject();
    }

    /**
     * This returns the creator of oAreaOfEffectObject.
     * * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
     */
    public static synchronized NWObject getAreaOfEffectCreator(NWObject oAreaOfEffectObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAreaOfEffectCreator");
        pushObject(oAreaOfEffectObject);
        callFunction(239, 1);
        return popObject();
    }

    /**
     * Delete oObject's local integer variable sVarName
     */
    public static synchronized void deleteLocalInt(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteLocalInt");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(240, 2);
    }

    /**
     * Delete oObject's local float variable sVarName
     */
    public static synchronized void deleteLocalFloat(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteLocalFloat");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(241, 2);
    }

    /**
     * Delete oObject's local string variable sVarName
     */
    public static synchronized void deleteLocalString(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteLocalString");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(242, 2);
    }

    /**
     * Delete oObject's local object variable sVarName
     */
    public static synchronized void deleteLocalObject(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteLocalObject");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(243, 2);
    }

    /**
     * Delete oObject's local location variable sVarName
     */
    public static synchronized void deleteLocalLocation(NWObject oObject, String sVarName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteLocalLocation");
        pushString(sVarName);
        pushObject(oObject);
        callFunction(244, 2);
    }

    /**
     * Create a Haste effect.
     */
    public static synchronized NWEffect effectHaste() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectHaste");
        callFunction(245, 0);
        return popEffect();
    }

    /**
     * Create a Slow effect.
     */
    public static synchronized NWEffect effectSlow() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSlow");
        callFunction(246, 0);
        return popEffect();
    }

    /**
     * Create an Immunity effect.
     * @param nImmunityType IMMUNITY_TYPE_*
     */
    public static synchronized NWEffect effectImmunity(int nImmunityType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectImmunity");
        pushInteger(nImmunityType);
        callFunction(248, 1);
        return popEffect();
    }

    /**
     * @param oCreature
     * @param nImmunityType IMMUNITY_TYPE_*
     * @param oVersus if this is specified, then we also check for the race and
     * alignment of oVersus
     * * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
     */
    public static synchronized boolean getIsImmune(NWObject oCreature, int nImmunityType, NWObject oVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsImmune");
        pushObject(oVersus);
        pushInteger(nImmunityType);
        pushObject(oCreature);
        callFunction(249, 3);
        return popInteger() > 0;
    }

    /**
     * Creates a Damage Immunity Increase effect.
     * @param nDamageType DAMAGE_TYPE_*
     * @param nPercentImmunity
     */
    public static synchronized NWEffect effectDamageImmunityIncrease(int nDamageType, int nPercentImmunity) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageImmunityIncrease");
        pushInteger(nPercentImmunity);
        pushInteger(nDamageType);
        callFunction(250, 2);
        return popEffect();
    }

    /**
     * Determine whether oEncounter is active.
     */
    public static synchronized int getEncounterActive(NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEncounterActive");
        pushObject(oEncounter);
        callFunction(251, 1);
        return popInteger();
    }

    /**
     * Set oEncounter's active state to nNewValue.
     * @param bNewValue TRUE/FALSE
     * @param oEncounter
     */
    public static synchronized void setEncounterActive(boolean bNewValue, NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setEncounterActive");
        pushObject(oEncounter);
        pushInteger(bNewValue ? 1 : 0);
        callFunction(252, 2);
    }

    /**
     * Get the maximum number of times that oEncounter will spawn.
     */
    public static synchronized int getEncounterSpawnsMax(NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEncounterSpawnsMax");
        pushObject(oEncounter);
        callFunction(253, 1);
        return popInteger();
    }

    /**
     * Set the maximum number of times that oEncounter can spawn
     */
    public static synchronized void setEncounterSpawnsMax(int nNewValue, NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setEncounterSpawnsMax");
        pushObject(oEncounter);
        pushInteger(nNewValue);
        callFunction(254, 2);
    }

    /**
     * Get the number of times that oEncounter has spawned so far
     */
    public static synchronized int getEncounterSpawnsCurrent(NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEncounterSpawnsCurrent");
        pushObject(oEncounter);
        callFunction(255, 1);
        return popInteger();
    }

    /**
     * Set the number of times that oEncounter has spawned so far
     */
    public static synchronized void setEncounterSpawnsCurrent(int nNewValue, NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setEncounterSpawnsCurrent");
        pushObject(oEncounter);
        pushInteger(nNewValue);
        callFunction(256, 2);
    }

    /**
     * Use this in an OnItemAcquired script to get the item that was acquired.
     * * Returns OBJECT_INVALID if the module is not valid.
     */
    public static synchronized NWObject getModuleItemAcquired() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemAcquired");
        callFunction(257, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemAcquired script to get the creatre that previously
     * possessed the item.
     * * Returns OBJECT_INVALID if the item was picked up from the ground.
     */
    public static synchronized NWObject getModuleItemAcquiredFrom() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemAcquiredFrom");
        callFunction(258, 0);
        return popObject();
    }

    /**
     * Set the value for a custom token.
     */
    public static synchronized void setCustomToken(int nCustomTokenNumber, String sTokenValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCustomToken");
        pushString(sTokenValue);
        pushInteger(nCustomTokenNumber);
        callFunction(259, 2);
    }

    /**
     * Determine whether oCreature has nFeat, and nFeat is useable.
     * @param nFeat FEAT_*
     * @param oCreature
     */
    public static synchronized boolean getHasFeat(int nFeat, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasFeat");
        pushObject(oCreature);
        pushInteger(nFeat);
        callFunction(260, 2);
        return popInteger() > 0;
    }

    /**
     * Determine whether oCreature has nSkill, and nSkill is useable.
     * @param nSkill SKILL_*
     * @param oCreature
     */
    public static synchronized boolean getHasSkill(int nSkill, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasSkill");
        pushObject(oCreature);
        pushInteger(nSkill);
        callFunction(261, 2);
        return popInteger() > 0;
    }

    /**
     * Use nFeat on oTarget.
     * @param nFeat FEAT_*
     * @param oTarget
     */
    public static synchronized void actionUseFeat(int nFeat, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionUseFeat");
        pushObject(oTarget);
        pushInteger(nFeat);
        callFunction(262, 2);
    }

    /**
     * Runs the action "UseSkill" on the current creature
     * Use nSkill on oTarget.
     * @param nSkill SKILL_*
     * @param oTarget
     * @param nSubSkill SUBSKILL_*
     * @param oItemUsed Item to use in conjunction with the skill
     */
    public static synchronized void actionUseSkill(int nSkill, NWObject oTarget, int nSubSkill, NWObject oItemUsed) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionUseSkill");
        pushObject(oItemUsed);
        pushInteger(nSubSkill);
        pushObject(oTarget);
        pushInteger(nSkill);
        callFunction(263, 4);
    }

    /**
     * Determine whether oSource sees oTarget.
     * NOTE: This *only* works on creatures, as visibility lists are not
     * maintained for non-creature objects.
     */
    public static synchronized boolean getObjectSeen(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getObjectSeen");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(264, 2);
        return popInteger() > 0;
    }

    /**
     * Determine whether oSource hears oTarget.
     * NOTE: This *only* works on creatures, as visibility lists are not
     * maintained for non-creature objects.
     */
    public static synchronized boolean getObjectHeard(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getObjectHeard");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(265, 2);
        return popInteger() > 0;
    }

    /**
     * Use this in an OnPlayerDeath module script to get the last player that died.
     */
    public static synchronized NWObject getLastPlayerDied() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPlayerDied");
        callFunction(266, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemLost script to get the item that was lost/dropped.
     * * Returns OBJECT_INVALID if the module is not valid.
     */
    public static synchronized NWObject getModuleItemLost() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemLost");
        callFunction(267, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemLost script to get the creature that lost the item.
     * * Returns OBJECT_INVALID if the module is not valid.
     */
    public static synchronized NWObject getModuleItemLostBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemLostBy");
        callFunction(268, 0);
        return popObject();
    }

    /**
     * Set the difficulty level of oEncounter.
     * @param nEncounterDifficulty ENCOUNTER_DIFFICULTY_*
     * @param oEncounter
     */
    public static synchronized void setEncounterDifficulty(int nEncounterDifficulty, NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setEncounterDifficulty");
        pushObject(oEncounter);
        pushInteger(nEncounterDifficulty);
        callFunction(269, 2);
    }

    /**
     * Get the difficulty level of oEncounter.
     */
    public static synchronized int getEncounterDifficulty(NWObject oEncounter) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEncounterDifficulty");
        pushObject(oEncounter);
        callFunction(270, 1);
        return popInteger();
    }

    /**
     * Get the distance between lLocationA and lLocationB.
     */
    public static synchronized float getDistanceBetweenLocations(NWLocation lLocationA, NWLocation lLocationB) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDistanceBetweenLocations");
        pushLocation(lLocationB);
        pushLocation(lLocationA);
        callFunction(271, 2);
        return popFloat();
    }

    /**
     * Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
     * evasion saves.
     * @param nDamage
     * @param oTarget
     * @param nDC Difficulty check
     * @param nSaveType SAVING_THROW_TYPE_*
     * @param oSaveVersus
     */
    public static synchronized int getReflexAdjustedDamage(int nDamage, NWObject oTarget, int nDC, int nSaveType, NWObject oSaveVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getReflexAdjustedDamage");
        pushObject(oSaveVersus);
        pushInteger(nSaveType);
        pushInteger(nDC);
        pushObject(oTarget);
        pushInteger(nDamage);
        callFunction(272, 5);
        return popInteger();
    }

    /**
     * Play nAnimation immediately.
     * @param nAnimation ANIMATION_*
     * @param fSpeed
     * @param fSeconds
     */
    public static synchronized void playAnimation(int nAnimation, float fSpeed, float fSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling playAnimation");
        pushFloat(fSeconds);
        pushFloat(fSpeed);
        pushInteger(nAnimation);
        callFunction(273, 3);
    }

    /**
     * Determines whether oObject has any effects applied by nSpell
     * @param nSpell SPELL_*
     * @param oObject
     * * The spell id on effects is only valid if the effect is created
     * when the spell script runs. If it is created in a delayed command
     * then the spell id on the effect will be invalid.
     */
    public static synchronized boolean getHasSpellEffect(int nSpell, NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasSpellEffect");
        pushObject(oObject);
        pushInteger(nSpell);
        callFunction(274, 2);
        return popInteger() > 0;
    }

    /**
     * Get the spell (SPELL_*) that applied eSpellEffect.
     * * Returns -1 if eSpellEffect was applied outside a spell script.
     */
    public static synchronized int getEffectSpellId(NWEffect eSpellEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectSpellId");
        pushEffect(eSpellEffect);
        callFunction(275, 1);
        return popInteger();
    }

    /**
     * Get the gold piece value of oItem.
     * * Returns 0 if oItem is not a valid item.
     */
    public static synchronized int getGoldPieceValue(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGoldPieceValue");
        pushObject(oItem);
        callFunction(276, 1);
        return popInteger();
    }

    /**
     * * Returns TRUE if oCreature is of a playable racial type.
     */
    public static synchronized boolean getIsPlayableRacialType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsPlayableRacialType");
        pushObject(oCreature);
        callFunction(277, 1);
        return popInteger() > 0;
    }

    /**
     * Jump to lDestination.  The action is added to the TOP of the action queue.
     */
    public static synchronized void jumpToLocation(NWLocation lDestination) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling jumpToLocation");
        pushLocation(lDestination);
        callFunction(278, 1);
    }

    /**
     * Create a Temporary Hitpoints effect.
     * @param nHitPoints a positive integer
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
     */
    public static synchronized NWEffect effectTemporaryHitpoints(int nHitPoints) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTemporaryHitpoints");
        pushInteger(nHitPoints);
        callFunction(279, 1);
        return popEffect();
    }

    /**
     * Get the number of ranks that oTarget has in nSkill.
     * @param nSkill SKILL_*
     * @param oTarget
     * @param bBaseSkillRank if set to true returns the number of base skill ranks the target
     * has (i.e. not including any bonuses from ability scores, feats, etc).
     * * Returns -1 if oTarget doesn't have nSkill.
     * * Returns 0 if nSkill is untrained.
     */
    public static synchronized int getSkillRank(int nSkill, NWObject oTarget, boolean bBaseSkillRank) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSkillRank");
        pushInteger(bBaseSkillRank ? 1 : 0);
        pushObject(oTarget);
        pushInteger(nSkill);
        callFunction(280, 3);
        return popInteger();
    }

    /**
     * Get the attack target of oCreature.
     * This only works when oCreature is in combat.
     */
    public static synchronized NWObject getAttackTarget(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAttackTarget");
        pushObject(oCreature);
        callFunction(281, 1);
        return popObject();
    }

    /**
     * Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
     * This only works when oCreature is in combat.
     */
    public static synchronized int getLastAttackType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastAttackType");
        pushObject(oCreature);
        callFunction(282, 1);
        return popInteger();
    }

    /**
     * Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
     * This only works when oCreature is in combat.
     */
    public static synchronized int getLastAttackMode(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastAttackMode");
        pushObject(oCreature);
        callFunction(283, 1);
        return popInteger();
    }

    /**
     * Get the master of oAssociate.
     */
    public static synchronized NWObject getMaster(NWObject oAssociate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMaster");
        pushObject(oAssociate);
        callFunction(284, 1);
        return popObject();
    }

    /**
     * * Returns TRUE if oCreature is in combat.
     */
    public static synchronized boolean getIsInCombat(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsInCombat");
        pushObject(oCreature);
        callFunction(285, 1);
        return popInteger() > 0;
    }

    /**
     * Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
     */
    public static synchronized int getLastAssociateCommand(NWObject oAssociate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastAssociateCommand");
        pushObject(oAssociate);
        callFunction(286, 1);
        return popInteger();
    }

    /**
     * Give nGP gold to oCreature.
     */
    public static synchronized void giveGoldToCreature(NWObject oCreature, int nGP) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling giveGoldToCreature");
        pushInteger(nGP);
        pushObject(oCreature);
        callFunction(287, 2);
    }

    /**
     * Set the destroyable status of the caller.
     * @param bDestroyable If this is FALSE, the caller does not fade out on death, but
     * sticks around as a corpse.
     * @param bRaiseable If this is TRUE, the caller can be raised via resurrection.
     * @param bSelectableWhenDead If this is TRUE, the caller is selectable after death.
     */
    public static synchronized void setIsDestroyable(boolean bDestroyable, boolean bRaiseable, boolean bSelectableWhenDead) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setIsDestroyable");
        pushInteger(bSelectableWhenDead ? 1 : 0);
        pushInteger(bRaiseable ? 1 : 0);
        pushInteger(bDestroyable ? 1 : 0);
        callFunction(288, 3);
    }

    /**
     * Set the locked state of oTarget, which can be a door or a placeable object.
     */
    public static synchronized void setLocked(NWObject oTarget, boolean bLocked) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLocked");
        pushInteger(bLocked ? 1 : 0);
        pushObject(oTarget);
        callFunction(289, 2);
    }

    /**
     * Get the locked state of oTarget, which can be a door or a placeable object.
     */
    public static synchronized boolean getLocked(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLocked");
        pushObject(oTarget);
        callFunction(290, 1);
        return popInteger() > 0;
    }

    /**
     * Use this in a trigger's OnClick event script to get the object that last
     * clicked on it.
     * This is identical to GetEnteringObject.
     * GetClickingObject() should not be called from a placeable's OnClick event,
     * instead use GetPlaceableLastClickedBy();
     */
    public static synchronized NWObject getClickingObject() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getClickingObject");
        callFunction(291, 0);
        return popObject();
    }

    /**
     * Initialise oTarget to listen for the standard Associates commands.
     */
    public static synchronized void setAssociateListenPatterns(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setAssociateListenPatterns");
        pushObject(oTarget);
        callFunction(292, 1);
    }

    /**
     * Get the last weapon that oCreature used in an attack.
     * * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
     */
    public static synchronized NWObject getLastWeaponUsed(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastWeaponUsed");
        pushObject(oCreature);
        callFunction(293, 1);
        return popObject();
    }

    /**
     * Use oPlaceable.
     */
    public static synchronized void actionInteractObject(NWObject oPlaceable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionInteractObject");
        pushObject(oPlaceable);
        callFunction(294, 1);
    }

    /**
     * Get the last object that used the placeable object that is calling this function.
     * * Returns OBJECT_INVALID if it is called by something other than a placeable or
     * a door.
     */
    public static synchronized NWObject getLastUsedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastUsedBy");
        callFunction(295, 0);
        return popObject();
    }

    /**
     * Returns the ability modifier for the specified ability
     * Get oCreature's ability modifier for nAbility.
     * @param nAbility ABILITY_*
     * @param oCreature
     */
    public static synchronized int getAbilityModifier(int nAbility, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAbilityModifier");
        pushObject(oCreature);
        pushInteger(nAbility);
        callFunction(296, 2);
        return popInteger();
    }

    /**
     * Determined whether oItem has been identified.
     */
    public static synchronized boolean getIdentified(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIdentified");
        pushObject(oItem);
        callFunction(297, 1);
        return popInteger() > 0;
    }

    /**
     * Set whether oItem has been identified.
     */
    public static synchronized void setIdentified(NWObject oItem, boolean bIdentified) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setIdentified");
        pushInteger(bIdentified ? 1 : 0);
        pushObject(oItem);
        callFunction(298, 2);
    }

    /**
     * Summon an Animal Companion
     */
    public static synchronized void summonAnimalCompanion(NWObject oMaster) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling summonAnimalCompanion");
        pushObject(oMaster);
        callFunction(299, 1);
    }

    /**
     * Summon a Familiar
     */
    public static synchronized void summonFamiliar(NWObject oMaster) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling summonFamiliar");
        pushObject(oMaster);
        callFunction(300, 1);
    }

    /**
     * Get the last blocking door encountered by the caller of this function.
     * * Returns OBJECT_INVALID if the caller is not a valid creature.
     */
    public static synchronized NWObject getBlockingDoor() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getBlockingDoor");
        callFunction(301, 0);
        return popObject();
    }

    /**
     * @param oTargetDoor
     * @param nDoorAction DOOR_ACTION_*
     * * Returns TRUE if nDoorAction can be performed on oTargetDoor.
     */
    public static synchronized boolean getIsDoorActionPossible(NWObject oTargetDoor, int nDoorAction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDoorActionPossible");
        pushInteger(nDoorAction);
        pushObject(oTargetDoor);
        callFunction(302, 2);
        return popInteger() > 0;
    }

    /**
     * Perform nDoorAction on oTargetDoor.
     */
    public static synchronized void doDoorAction(NWObject oTargetDoor, int nDoorAction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling doDoorAction");
        pushInteger(nDoorAction);
        pushObject(oTargetDoor);
        callFunction(303, 2);
    }

    /**
     * Get the first item in oTarget's inventory (start to cycle through oTarget's
     * inventory).
     * * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
     * or if no item is found.
     */
    public static synchronized NWObject getFirstItemInInventory(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstItemInInventory");
        pushObject(oTarget);
        callFunction(304, 1);
        return popObject();
    }

    /**
     * Get the next item in oTarget's inventory (continue to cycle through oTarget's
     * inventory).
     * * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
     * or if no item is found.
     */
    public static synchronized NWObject getNextItemInInventory(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextItemInInventory");
        pushObject(oTarget);
        callFunction(305, 1);
        return popObject();
    }

    /**
     * A creature can have up to three classes.  This function determines the
     * creature's class (CLASS_TYPE_*) based on nClassPosition.
     * @param nClassPosition 1, 2 or 3
     * @param oCreature
     * * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
     * nClassPosition (i.e. a single-class creature will only have a value in
     * nClassLocation=1) or if oCreature is not a valid creature.
     */
    public static synchronized int getClassByPosition(int nClassPosition, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getClassByPosition");
        pushObject(oCreature);
        pushInteger(nClassPosition);
        callFunction(306, 2);
        return popInteger();
    }

    /**
     * A creature can have up to three classes.  This function determines the
     * creature's class level based on nClass Position.
     * @param nClassPosition 1, 2 or 3
     * @param oCreature
     * * Returns 0 if oCreature does not have a class in nClassPosition
     * (i.e. a single-class creature will only have a value in nClassLocation=1)
     * or if oCreature is not a valid creature.
     */
    public static synchronized int getLevelByPosition(int nClassPosition, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLevelByPosition");
        pushObject(oCreature);
        pushInteger(nClassPosition);
        callFunction(307, 2);
        return popInteger();
    }

    /**
     * Determine the levels that oCreature holds in nClassType.
     * @param nClassType CLASS_TYPE_*
     * @param oCreature
     */
    public static synchronized int getLevelByClass(int nClassType, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLevelByClass");
        pushObject(oCreature);
        pushInteger(nClassType);
        callFunction(308, 2);
        return popInteger();
    }

    /**
     * Get the amount of damage of type nDamageType that has been dealt to the caller.
     * @param nDamageType DAMAGE_TYPE_*
     */
    public static synchronized int getDamageDealtByType(int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDamageDealtByType");
        pushInteger(nDamageType);
        callFunction(309, 1);
        return popInteger();
    }

    /**
     * Get the total amount of damage that has been dealt to the caller.
     */
    public static synchronized int getTotalDamageDealt() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTotalDamageDealt");
        callFunction(310, 0);
        return popInteger();
    }

    /**
     * Get the last object that damaged oObject
     * * Returns OBJECT_INVALID if the passed in object is not a valid object.
     */
    public static synchronized NWObject getLastDamager(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastDamager");
        pushObject(oObject);
        callFunction(311, 1);
        return popObject();
    }

    /**
     * Get the last object that disarmed the trap on the caller.
     * * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
     * door.
     */
    public static synchronized NWObject getLastDisarmed() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastDisarmed");
        callFunction(312, 0);
        return popObject();
    }

    /**
     * Get the last object that disturbed the inventory of the caller.
     * * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
     */
    public static synchronized NWObject getLastDisturbed() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastDisturbed");
        callFunction(313, 0);
        return popObject();
    }

    /**
     * Get the last object that locked the caller.
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
     */
    public static synchronized NWObject getLastLocked() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastLocked");
        callFunction(314, 0);
        return popObject();
    }

    /**
     * Get the last object that unlocked the caller.
     * * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
     */
    public static synchronized NWObject getLastUnlocked() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastUnlocked");
        callFunction(315, 0);
        return popObject();
    }

    /**
     * Create a Skill Increase effect.
     * @param nSkill SKILL_*
     * @param nValue
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
     */
    public static synchronized NWEffect effectSkillIncrease(int nSkill, int nValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSkillIncrease");
        pushInteger(nValue);
        pushInteger(nSkill);
        callFunction(316, 2);
        return popEffect();
    }

    /**
     * Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
     * OnInventoryDisturbed script to fire.  This will only work for creatures and
     * placeables.
     */
    public static synchronized int getInventoryDisturbType() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getInventoryDisturbType");
        callFunction(317, 0);
        return popInteger();
    }

    /**
     * get the item that caused the caller's OnInventoryDisturbed script to fire.
     * * Returns OBJECT_INVALID if the caller is not a valid object.
     */
    public static synchronized NWObject getInventoryDisturbItem() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getInventoryDisturbItem");
        callFunction(318, 0);
        return popObject();
    }

    /**
     * Get the henchman belonging to oMaster.
     * * Return OBJECT_INVALID if oMaster does not have a henchman.
     * -nNth: Which henchman to return.
     */
    public static synchronized NWObject getHenchman(NWObject oMaster, int nNth) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHenchman");
        pushInteger(nNth);
        pushObject(oMaster);
        callFunction(319, 2);
        return popObject();
    }

    /**
     * Set eEffect to be versus a specific alignment.
     * @param eEffect
     * @param nLawChaos ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
     * @param nGoodEvil ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
     */
    public static synchronized NWEffect versusAlignmentEffect(NWEffect eEffect, int nLawChaos, int nGoodEvil) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling versusAlignmentEffect");
        pushInteger(nGoodEvil);
        pushInteger(nLawChaos);
        pushEffect(eEffect);
        callFunction(320, 3);
        return popEffect();
    }

    /**
     * Set eEffect to be versus nRacialType.
     * @param eEffect
     * @param nRacialType RACIAL_TYPE_*
     */
    public static synchronized NWEffect versusRacialTypeEffect(NWEffect eEffect, int nRacialType) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling versusRacialTypeEffect");
        pushInteger(nRacialType);
        pushEffect(eEffect);
        callFunction(321, 2);
        return popEffect();
    }

    /**
     * Set eEffect to be versus traps.
     */
    public static synchronized NWEffect versusTrapEffect(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling versusTrapEffect");
        pushEffect(eEffect);
        callFunction(322, 1);
        return popEffect();
    }

    /**
     * Get the gender of oCreature.
     */
    public static synchronized int getGender(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGender");
        pushObject(oCreature);
        callFunction(323, 1);
        return popInteger();
    }

    /**
     * Causes the action subject to move away from lMoveAwayFrom.
     */
    public static synchronized void actionMoveAwayFromLocation(NWLocation lMoveAwayFrom, boolean bRun, float fMoveAwayRange) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionMoveAwayFromLocation");
        pushFloat(fMoveAwayRange);
        pushInteger(bRun ? 1 : 0);
        pushLocation(lMoveAwayFrom);
        callFunction(324, 3);
    }

    /**
     * Get the target that the caller attempted to attack @param this should be used in
     * conjunction with GetAttackTarget(). This value is set every time an attack is
     * made, and is reset at the end of combat.
     * * Returns OBJECT_INVALID if the caller is not a valid creature.
     */
    public static synchronized NWObject getAttemptedAttackTarget() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAttemptedAttackTarget");
        callFunction(325, 0);
        return popObject();
    }

    /**
     * Get the associate of type nAssociateType belonging to oMaster.
     * @param nAssociateType ASSOCIATE_TYPE_*
     * @param nMaster
     * @param nTh Which associate of the specified type to return
     * * Returns OBJECT_INVALID if no such associate exists.
     */
    public static synchronized NWObject getAssociate(int nAssociateType, NWObject oMaster, int nTh) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAssociate");
        pushInteger(nTh);
        pushObject(oMaster);
        pushInteger(nAssociateType);
        callFunction(326, 3);
        return popObject();
    }

    /**
     * Add oHenchman as a henchman to oMaster
     * If oHenchman is either a DM or a player character, this will have no effect.
     */
    public static synchronized void addHenchman(NWObject oMaster, NWObject oHenchman) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling addHenchman");
        pushObject(oHenchman);
        pushObject(oMaster);
        callFunction(327, 2);
    }

    /**
     * Remove oHenchman from the service of oMaster, returning them to their original faction.
     */
    public static synchronized void removeHenchman(NWObject oMaster, NWObject oHenchman) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeHenchman");
        pushObject(oHenchman);
        pushObject(oMaster);
        callFunction(328, 2);
    }

    /**
     * Add a journal quest entry to oCreature.
     * @param szPlotID the plot identifier used in the toolset's Journal Editor
     * @param nState the state of the plot as seen in the toolset's Journal Editor
     * @param oCreature
     * @param bAllPartyMembers If this is TRUE, the entry will show up in the journal of
     * everyone in the party
     * @param bAllPlayers If this is TRUE, the entry will show up in the journal of
     * everyone in the world
     * @param bAllowOverrideHigher If this is TRUE, you can set the state to a lower
     * number than the one it is currently on
     */
    public static synchronized void addJournalQuestEntry(String szPlotID, int nState, NWObject oCreature, boolean bAllPartyMembers, boolean bAllPlayers, boolean bAllowOverrideHigher) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling addJournalQuestEntry");
        pushInteger(bAllowOverrideHigher ? 1 : 0);
        pushInteger(bAllPlayers ? 1 : 0);
        pushInteger(bAllPartyMembers ? 1 : 0);
        pushObject(oCreature);
        pushInteger(nState);
        pushString(szPlotID);
        callFunction(329, 6);
    }

    /**
     * Remove a journal quest entry from oCreature.
     * @param szPlotID the plot identifier used in the toolset's Journal Editor
     * @param oCreature
     * @param bAllPartyMembers If this is TRUE, the entry will be removed from the
     * journal of everyone in the party
     * @param bAllPlayers If this is TRUE, the entry will be removed from the journal of
     * everyone in the world
     */
    public static synchronized void removeJournalQuestEntry(String szPlotID, NWObject oCreature, boolean bAllPartyMembers, boolean bAllPlayers) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeJournalQuestEntry");
        pushInteger(bAllPlayers ? 1 : 0);
        pushInteger(bAllPartyMembers ? 1 : 0);
        pushObject(oCreature);
        pushString(szPlotID);
        callFunction(330, 4);
    }

    /**
     * Get the public part of the CD Key that oPlayer used when logging in.
     * @param bSinglePlayerCDKey If set to TRUE, the player's public CD Key will
     * be returned when the player is playing in single player mode
     * (otherwise returns an empty string in single player mode).
     */
    public static synchronized String getPCPublicCDKey(NWObject oPlayer, boolean bSinglePlayerCDKey) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCPublicCDKey");
        pushInteger(bSinglePlayerCDKey ? 1 : 0);
        pushObject(oPlayer);
        callFunction(331, 2);
        return popString();
    }

    /**
     * Get the IP address from which oPlayer has connected.
     */
    public static synchronized String getPCIPAddress(NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCIPAddress");
        pushObject(oPlayer);
        callFunction(332, 1);
        return popString();
    }

    /**
     * Get the name of oPlayer.
     */
    public static synchronized String getPCPlayerName(NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCPlayerName");
        pushObject(oPlayer);
        callFunction(333, 1);
        return popString();
    }

    /**
     * Sets oPlayer and oTarget to like each other.
     */
    public static synchronized void setPCLike(NWObject oPlayer, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPCLike");
        pushObject(oTarget);
        pushObject(oPlayer);
        callFunction(334, 2);
    }

    /**
     * Sets oPlayer and oTarget to dislike each other.
     */
    public static synchronized void setPCDislike(NWObject oPlayer, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPCDislike");
        pushObject(oTarget);
        pushObject(oPlayer);
        callFunction(335, 2);
    }

    /**
     * Send a server message (szMessage) to the oPlayer.
     */
    public static synchronized void sendMessageToPC(NWObject oPlayer, String szMessage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling sendMessageToPC");
        pushString(szMessage);
        pushObject(oPlayer);
        callFunction(336, 2);
    }

    /**
     * Get the target at which the caller attempted to cast a spell.
     * This value is set every time a spell is cast and is reset at the end of
     * combat.
     * * Returns OBJECT_INVALID if the caller is not a valid creature.
     */
    public static synchronized NWObject getAttemptedSpellTarget() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAttemptedSpellTarget");
        callFunction(337, 0);
        return popObject();
    }

    /**
     * Get the last creature that opened the caller.
     * * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
     */
    public static synchronized NWObject getLastOpenedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastOpenedBy");
        callFunction(338, 0);
        return popObject();
    }

    /**
     * Determines the number of times that oCreature has nSpell memorised.
     * @param nSpell SPELL_*
     * @param oCreature
     */
    public static synchronized boolean getHasSpell(int nSpell, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasSpell");
        pushObject(oCreature);
        pushInteger(nSpell);
        callFunction(339, 2);
        return popInteger() > 0;
    }

    /**
     * Open oStore for oPC.
     * @param nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
     * @param nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
     */
    public static synchronized void openStore(NWObject oStore, NWObject oPC, int nBonusMarkUp, int nBonusMarkDown) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling openStore");
        pushInteger(nBonusMarkDown);
        pushInteger(nBonusMarkUp);
        pushObject(oPC);
        pushObject(oStore);
        callFunction(340, 4);
    }

    /**
     * Create a Turned effect.
     * Turned effects are supernatural by default.
     */
    public static synchronized NWEffect effectTurned() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTurned");
        callFunction(341, 0);
        return popEffect();
    }

    /**
     * Get the first member of oMemberOfFaction's faction (start to cycle through
     * oMemberOfFaction's faction).
     * * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
     */
    public static synchronized NWObject getFirstFactionMember(NWObject oMemberOfFaction, boolean bPCOnly) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstFactionMember");
        pushInteger(bPCOnly ? 1 : 0);
        pushObject(oMemberOfFaction);
        callFunction(342, 2);
        return popObject();
    }

    /**
     * Get the next member of oMemberOfFaction's faction (continue to cycle through
     * oMemberOfFaction's faction).
     * * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
     */
    public static synchronized NWObject getNextFactionMember(NWObject oMemberOfFaction, boolean bPCOnly) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextFactionMember");
        pushInteger(bPCOnly ? 1 : 0);
        pushObject(oMemberOfFaction);
        callFunction(343, 2);
        return popObject();
    }

    /**
     * Force the action subject to move to lDestination.
     */
    public static synchronized void actionForceMoveToLocation(NWLocation lDestination, boolean bRun, float fTimeout) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionForceMoveToLocation");
        pushFloat(fTimeout);
        pushInteger(bRun ? 1 : 0);
        pushLocation(lDestination);
        callFunction(344, 3);
    }

    /**
     * Force the action subject to move to oMoveTo.
     */
    public static synchronized void actionForceMoveToObject(NWObject oMoveTo, boolean bRun, float fRange, float fTimeout) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionForceMoveToObject");
        pushFloat(fTimeout);
        pushFloat(fRange);
        pushInteger(bRun ? 1 : 0);
        pushObject(oMoveTo);
        callFunction(345, 4);
    }

    /**
     * Get the experience assigned in the journal editor for szPlotID.
     */
    public static synchronized int getJournalQuestExperience(String szPlotID) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getJournalQuestExperience");
        pushString(szPlotID);
        callFunction(346, 1);
        return popInteger();
    }

    /**
     * Jump to oToJumpTo (the action is added to the top of the action queue).
     */
    public static synchronized void jumpToObject(NWObject oToJumpTo, boolean bWalkStraightLineToPoint) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling jumpToObject");
        pushInteger(bWalkStraightLineToPoint ? 1 : 0);
        pushObject(oToJumpTo);
        callFunction(347, 2);
    }

    /**
     * Set whether oMapPin is enabled.
     * @param oMapPin
     * @param bEnabled 0=Off, 1=On
     */
    public static synchronized void setMapPinEnabled(NWObject oMapPin, boolean bEnabled) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setMapPinEnabled");
        pushInteger(bEnabled ? 1 : 0);
        pushObject(oMapPin);
        callFunction(348, 2);
    }

    /**
     * Create a Hit Point Change When Dying effect.
     * @param fHitPointChangePerRound this can be positive or negative, but not zero.
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
     */
    public static synchronized NWEffect effectHitPointChangeWhenDying(float fHitPointChangePerRound) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectHitPointChangeWhenDying");
        pushFloat(fHitPointChangePerRound);
        callFunction(349, 1);
        return popEffect();
    }

    /**
     * Spawn a GUI panel for the client that controls oPC.
     * @param oPC
     * @param nGUIPanel GUI_PANEL_*
     * * Nothing happens if oPC is not a player character or if an invalid value is
     * used for nGUIPanel.
     */
    public static synchronized void popUpGUIPanel(NWObject oPC, int nGUIPanel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling popUpGUIPanel");
        pushInteger(nGUIPanel);
        pushObject(oPC);
        callFunction(350, 2);
    }

    /**
     * Clear all personal feelings that oSource has about oTarget.
     */
    public static synchronized void clearPersonalReputation(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling clearPersonalReputation");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(351, 2);
    }

    /**
     * oSource will temporarily be friends towards oTarget.
     * bDecays determines whether the personal reputation value decays over time
     * fDurationInSeconds is the length of time that the temporary friendship lasts
     * Make oSource into a temporary friend of oTarget using personal reputation.
     * @param oTarget
     * @param oSource
     * @param bDecays If this is TRUE, the friendship decays over fDurationInSeconds;
     * otherwise it is indefinite.
     * @param fDurationInSeconds This is only used if bDecays is TRUE, it is how long
     * the friendship lasts.
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size
     * over fDurationInSeconds. Friendship will only be in effect as long as
     * (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
     */
    public static synchronized void setIsTemporaryFriend(NWObject oTarget, NWObject oSource, boolean bDecays, float fDurationInSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setIsTemporaryFriend");
        pushFloat(fDurationInSeconds);
        pushInteger(bDecays ? 1 : 0);
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(352, 4);
    }

    /**
     * Make oSource into a temporary enemy of oTarget using personal reputation.
     * @param oTarget
     * @param oSource
     * @param bDecays If this is TRUE, the enmity decays over fDurationInSeconds;
     * otherwise it is indefinite.
     * @param fDurationInSeconds This is only used if bDecays is TRUE, it is how long
     * the enmity lasts.
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size
     * over fDurationInSeconds. Enmity will only be in effect as long as
     * (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
     */
    public static synchronized void setIsTemporaryEnemy(NWObject oTarget, NWObject oSource, boolean bDecays, float fDurationInSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setIsTemporaryEnemy");
        pushFloat(fDurationInSeconds);
        pushInteger(bDecays ? 1 : 0);
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(353, 4);
    }

    /**
     * Make oSource temporarily neutral to oTarget using personal reputation.
     * @param oTarget
     * @param oSource
     * @param bDecays If this is TRUE, the neutrality decays over fDurationInSeconds;
     * otherwise it is indefinite.
     * @param fDurationInSeconds This is only used if bDecays is TRUE, it is how long
     * the neutrality lasts.
     * Note: If bDecays is TRUE, the personal reputation amount decreases in size
     * over fDurationInSeconds. Neutrality will only be in effect as long as
     * (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
     * (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
     */
    public static synchronized void setIsTemporaryNeutral(NWObject oTarget, NWObject oSource, boolean bDecays, float fDurationInSeconds) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setIsTemporaryNeutral");
        pushFloat(fDurationInSeconds);
        pushInteger(bDecays ? 1 : 0);
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(354, 4);
    }

    /**
     * Gives nXpAmount to oCreature.
     */
    public static synchronized void giveXPToCreature(NWObject oCreature, int nXpAmount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling giveXPToCreature");
        pushInteger(nXpAmount);
        pushObject(oCreature);
        callFunction(355, 2);
    }

    /**
     * Sets oCreature's experience to nXpAmount.
     */
    public static synchronized void setXP(NWObject oCreature, int nXpAmount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setXP");
        pushInteger(nXpAmount);
        pushObject(oCreature);
        callFunction(356, 2);
    }

    /**
     * Get oCreature's experience.
     */
    public static synchronized int getXP(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getXP");
        pushObject(oCreature);
        callFunction(357, 1);
        return popInteger();
    }

    /**
     * Convert nInteger to hex, returning the hex value as a string.
     * * Return value has the format "0x????????" where each ? will be a hex digit
     * (8 digits in total).
     */
    public static synchronized String intToHexString(int nInteger) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling intToHexString");
        pushInteger(nInteger);
        callFunction(358, 1);
        return popString();
    }

    /**
     * Get the base item type (BASE_ITEM_*) of oItem.
     * * Returns BASE_ITEM_INVALID if oItem is an invalid item.
     */
    public static synchronized int getBaseItemType(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getBaseItemType");
        pushObject(oItem);
        callFunction(359, 1);
        return popInteger();
    }

    /**
     * Determines whether oItem has nProperty.
     * @param oItem
     * @param nProperty ITEM_PROPERTY_*
     * * Returns FALSE if oItem is not a valid item, or if oItem does not have
     * nProperty.
     */
    public static synchronized boolean getItemHasItemProperty(NWObject oItem, int nProperty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemHasItemProperty");
        pushInteger(nProperty);
        pushObject(oItem);
        callFunction(360, 2);
        return popInteger() > 0;
    }

    /**
     * The creature will equip the melee weapon in its possession that can do the
     * most damage. If no valid melee weapon is found, it will equip the most
     * damaging range weapon. This function should only ever be called in the
     * EndOfCombatRound scripts, because otherwise it would have to stop the combat
     * round to run simulation.
     * @param oVersus You can try to get the most damaging weapon against oVersus
     * @param bOffHand
     */
    public static synchronized void actionEquipMostDamagingMelee(NWObject oVersus, boolean bOffHand) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionEquipMostDamagingMelee");
        pushInteger(bOffHand ? 1 : 0);
        pushObject(oVersus);
        callFunction(361, 2);
    }

    /**
     * The creature will equip the range weapon in its possession that can do the
     * most damage.
     * If no valid range weapon can be found, it will equip the most damaging melee
     * weapon.
     * @param oVersus You can try to get the most damaging weapon against oVersus
     */
    public static synchronized void actionEquipMostDamagingRanged(NWObject oVersus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionEquipMostDamagingRanged");
        pushObject(oVersus);
        callFunction(362, 1);
    }

    /**
     * Get the Armour Class of oItem.
     * * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
     */
    public static synchronized int getItemACValue(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemACValue");
        pushObject(oItem);
        callFunction(363, 1);
        return popInteger();
    }

    /**
     * The creature will rest if not in combat and no enemies are nearby.
     * @param bCreatureToEnemyLineOfSightCheck TRUE to allow the creature to rest if enemies
     * are nearby, but the creature can't see the enemy.
     * FALSE the creature will not rest if enemies are
     * nearby regardless of whether or not the creature
     * can see them, such as if an enemy is close by,
     * but is in a different room behind a closed door.
     */
    public static synchronized void actionRest(boolean bCreatureToEnemyLineOfSightCheck) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionRest");
        pushInteger(bCreatureToEnemyLineOfSightCheck ? 1 : 0);
        callFunction(364, 1);
    }

    /**
     * Expose/Hide the entire map of oArea for oPlayer.
     * @param oArea The area that the map will be exposed/hidden for.
     * @param oPlayer The player the map will be exposed/hidden for.
     * @param bExplored TRUE/FALSE. Whether the map should be completely explored or hidden.
     */
    public static synchronized void exploreAreaForPlayer(NWObject oArea, NWObject oPlayer, boolean bExplored) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling exploreAreaForPlayer");
        pushInteger(bExplored ? 1 : 0);
        pushObject(oPlayer);
        pushObject(oArea);
        callFunction(365, 3);
    }

    /**
     * The creature will equip the armour in its possession that has the highest
     * armour class.
     */
    public static synchronized void actionEquipMostEffectiveArmor() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionEquipMostEffectiveArmor");
        callFunction(366, 0);
    }

    /**
     * * Returns TRUE if it is currently day.
     */
    public static synchronized boolean getIsDay() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDay");
        callFunction(367, 0);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if it is currently night.
     */
    public static synchronized boolean getIsNight() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsNight");
        callFunction(368, 0);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if it is currently dawn.
     */
    public static synchronized boolean getIsDawn() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDawn");
        callFunction(369, 0);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if it is currently dusk.
     */
    public static synchronized boolean getIsDusk() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDusk");
        callFunction(370, 0);
        return popInteger() > 0;
    }

    /**
     * * Returns TRUE if oCreature was spawned from an encounter.
     */
    public static synchronized boolean getIsEncounterCreature(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsEncounterCreature");
        pushObject(oCreature);
        callFunction(371, 1);
        return popInteger() > 0;
    }

    /**
     * Use this in an OnPlayerDying module script to get the last player who is dying.
     */
    public static synchronized NWObject getLastPlayerDying() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPlayerDying");
        callFunction(372, 0);
        return popObject();
    }

    /**
     * Get the starting location of the module.
     */
    public static synchronized NWLocation getStartingLocation() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStartingLocation");
        callFunction(373, 0);
        return popLocation();
    }

    /**
     * Make oCreatureToChange join one of the standard factions.
     * ** This will only work on an NPC **
     * @param nStandardFaction STANDARD_FACTION_*
     */
    public static synchronized void changeToStandardFaction(NWObject oCreatureToChange, int nStandardFaction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling changeToStandardFaction");
        pushInteger(nStandardFaction);
        pushObject(oCreatureToChange);
        callFunction(374, 2);
    }

    /**
     * Play oSound.
     */
    public static synchronized void soundObjectPlay(NWObject oSound) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling soundObjectPlay");
        pushObject(oSound);
        callFunction(375, 1);
    }

    /**
     * Stop playing oSound.
     */
    public static synchronized void soundObjectStop(NWObject oSound) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling soundObjectStop");
        pushObject(oSound);
        callFunction(376, 1);
    }

    /**
     * Set the volume of oSound.
     * @param oSound
     * @param nVolume 0-127
     */
    public static synchronized void soundObjectSetVolume(NWObject oSound, int nVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling soundObjectSetVolume");
        pushInteger(nVolume);
        pushObject(oSound);
        callFunction(377, 2);
    }

    /**
     * Set the position of oSound.
     */
    public static synchronized void soundObjectSetPosition(NWObject oSound, NWVector vPosition) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling soundObjectSetPosition");
        pushVector(vPosition);
        pushObject(oSound);
        callFunction(378, 2);
    }

    /**
     * Immediately speak a conversation one-liner.
     * @param sDialogResRef
     * @param oTokenTarget This must be specified if there are creature-specific tokens
     * in the string.
     */
    public static synchronized void speakOneLinerConversation(String sDialogResRef, NWObject oTokenTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling speakOneLinerConversation");
        pushObject(oTokenTarget);
        pushString(sDialogResRef);
        callFunction(379, 2);
    }

    /**
     * Get the amount of gold possessed by oTarget.
     */
    public static synchronized int getGold(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGold");
        pushObject(oTarget);
        callFunction(380, 1);
        return popInteger();
    }

    /**
     * Use this in an OnRespawnButtonPressed module script to get the object id of
     * the player who last pressed the respawn button.
     */
    public static synchronized NWObject getLastRespawnButtonPresser() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastRespawnButtonPresser");
        callFunction(381, 0);
        return popObject();
    }

    /**
     * * Returns TRUE if oCreature is the Dungeon Master.
     * Note: This will return FALSE if oCreature is a DM Possessed creature.
     * To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
     */
    public static synchronized boolean getIsDM(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDM");
        pushObject(oCreature);
        callFunction(382, 1);
        return popInteger() > 0;
    }

    /**
     * Play a voice chat.
     * @param nVoiceChatID VOICE_CHAT_*
     * @param oTarget
     */
    public static synchronized void playVoiceChat(int nVoiceChatID, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling playVoiceChat");
        pushObject(oTarget);
        pushInteger(nVoiceChatID);
        callFunction(383, 2);
    }

    /**
     * * Returns TRUE if the weapon equipped is capable of damaging oVersus.
     */
    public static synchronized boolean getIsWeaponEffective(NWObject oVersus, boolean bOffHand) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsWeaponEffective");
        pushInteger(bOffHand ? 1 : 0);
        pushObject(oVersus);
        callFunction(384, 2);
        return popInteger() > 0;
    }

    /**
     * Use this in a SpellCast script to determine whether the spell was considered
     * harmful.
     * * Returns TRUE if the last spell cast was harmful.
     */
    public static synchronized boolean getLastSpellHarmful() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastSpellHarmful");
        callFunction(385, 0);
        return popInteger() > 0;
    }

    /**
     * Play the background music for oArea.
     */
    public static synchronized void musicBackgroundPlay(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundPlay");
        pushObject(oArea);
        callFunction(386, 1);
    }

    /**
     * Stop the background music for oArea.
     */
    public static synchronized void musicBackgroundStop(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundStop");
        pushObject(oArea);
        callFunction(387, 1);
    }

    /**
     * Set the delay for the background music for oArea.
     * @param oArea
     * @param nDelay delay in milliseconds
     */
    public static synchronized void musicBackgroundSetDelay(NWObject oArea, int nDelay) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundSetDelay");
        pushInteger(nDelay);
        pushObject(oArea);
        callFunction(388, 2);
    }

    /**
     * Change the background day track for oArea to nTrack.
     * @param oArea
     * @param nTrack
     */
    public static synchronized void musicBackgroundChangeDay(NWObject oArea, int nTrack) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundChangeDay");
        pushInteger(nTrack);
        pushObject(oArea);
        callFunction(389, 2);
    }

    /**
     * Change the background night track for oArea to nTrack.
     * @param oArea
     * @param nTrack
     */
    public static synchronized void musicBackgroundChangeNight(NWObject oArea, int nTrack) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundChangeNight");
        pushInteger(nTrack);
        pushObject(oArea);
        callFunction(390, 2);
    }

    /**
     * Play the battle music for oArea.
     */
    public static synchronized void musicBattlePlay(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBattlePlay");
        pushObject(oArea);
        callFunction(391, 1);
    }

    /**
     * Stop the battle music for oArea.
     */
    public static synchronized void musicBattleStop(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBattleStop");
        pushObject(oArea);
        callFunction(392, 1);
    }

    /**
     * Change the battle track for oArea.
     * @param oArea
     * @param nTrack
     */
    public static synchronized void musicBattleChange(NWObject oArea, int nTrack) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBattleChange");
        pushInteger(nTrack);
        pushObject(oArea);
        callFunction(393, 2);
    }

    /**
     * Play the ambient sound for oArea.
     */
    public static synchronized void ambientSoundPlay(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundPlay");
        pushObject(oArea);
        callFunction(394, 1);
    }

    /**
     * Stop the ambient sound for oArea.
     */
    public static synchronized void ambientSoundStop(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundStop");
        pushObject(oArea);
        callFunction(395, 1);
    }

    /**
     * Change the ambient day track for oArea to nTrack.
     * @param oArea
     * @param nTrack
     */
    public static synchronized void ambientSoundChangeDay(NWObject oArea, int nTrack) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundChangeDay");
        pushInteger(nTrack);
        pushObject(oArea);
        callFunction(396, 2);
    }

    /**
     * Change the ambient night track for oArea to nTrack.
     * @param oArea
     * @param nTrack
     */
    public static synchronized void ambientSoundChangeNight(NWObject oArea, int nTrack) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundChangeNight");
        pushInteger(nTrack);
        pushObject(oArea);
        callFunction(397, 2);
    }

    /**
     * Get the object that killed the caller.
     */
    public static synchronized NWObject getLastKiller() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastKiller");
        callFunction(398, 0);
        return popObject();
    }

    /**
     * Use this in a spell script to get the item used to cast the spell.
     */
    public static synchronized NWObject getSpellCastItem() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellCastItem");
        callFunction(399, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemActivated module script to get the item that was activated.
     */
    public static synchronized NWObject getItemActivated() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemActivated");
        callFunction(400, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemActivated module script to get the creature that
     * activated the item.
     */
    public static synchronized NWObject getItemActivator() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemActivator");
        callFunction(401, 0);
        return popObject();
    }

    /**
     * Use this in an OnItemActivated module script to get the location of the item's
     * target.
     */
    public static synchronized NWLocation getItemActivatedTargetLocation() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemActivatedTargetLocation");
        callFunction(402, 0);
        return popLocation();
    }

    /**
     * Use this in an OnItemActivated module script to get the item's target.
     */
    public static synchronized NWObject getItemActivatedTarget() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemActivatedTarget");
        callFunction(403, 0);
        return popObject();
    }

    /**
     * * Returns TRUE if oObject (which is a placeable or a door) is currently open.
     */
    public static synchronized boolean getIsOpen(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsOpen");
        pushObject(oObject);
        callFunction(404, 1);
        return popInteger() > 0;
    }

    /**
     * Take nAmount of gold from oCreatureToTakeFrom.
     * @param nAmount
     * @param oCreatureToTakeFrom If this is not a valid creature, nothing will happen.
     * @param bDestroy If this is TRUE, the caller will not get the gold.  Instead, the
     * gold will be destroyed and will vanish from the game.
     */
    public static synchronized void takeGoldFromCreature(int nAmount, NWObject oCreatureToTakeFrom, boolean bDestroy) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling takeGoldFromCreature");
        pushInteger(bDestroy ? 1 : 0);
        pushObject(oCreatureToTakeFrom);
        pushInteger(nAmount);
        callFunction(405, 3);
    }

    /**
     * Determine whether oObject is in conversation.
     */
    public static synchronized boolean isInConversation(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling isInConversation");
        pushObject(oObject);
        callFunction(406, 1);
        return popInteger() > 0;
    }

    /**
     * Create an Ability Decrease effect.
     * @param nAbility ABILITY_*
     * @param nModifyBy This is the amount by which to decrement the ability
     */
    public static synchronized NWEffect effectAbilityDecrease(int nAbility, int nModifyBy) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAbilityDecrease");
        pushInteger(nModifyBy);
        pushInteger(nAbility);
        callFunction(407, 2);
        return popEffect();
    }

    /**
     * Create an Attack Decrease effect.
     * @param nPenalty
     * @param nAttackBonus ATTACK_BONUS_*
     */
    public static synchronized NWEffect effectAttackDecrease(int nPenalty, int nAttackBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAttackDecrease");
        pushInteger(nAttackBonus);
        pushInteger(nPenalty);
        callFunction(408, 2);
        return popEffect();
    }

    /**
     * Create a Damage Decrease effect.
     * @param nPenalty
     * @param nDamageType DAMAGE_TYPE_*
     */
    public static synchronized NWEffect effectDamageDecrease(int nPenalty, int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageDecrease");
        pushInteger(nDamageType);
        pushInteger(nPenalty);
        callFunction(409, 2);
        return popEffect();
    }

    /**
     * Create a Damage Immunity Decrease effect.
     * @param nDamageType DAMAGE_TYPE_*
     * @param nPercentImmunity
     */
    public static synchronized NWEffect effectDamageImmunityDecrease(int nDamageType, int nPercentImmunity) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageImmunityDecrease");
        pushInteger(nPercentImmunity);
        pushInteger(nDamageType);
        callFunction(410, 2);
        return popEffect();
    }

    /**
     * Create an AC Decrease effect.
     * @param nValue
     * @param nACModifyType AC_*
     * @param nDamageType DAMAGE_TYPE_*
     * * Default value for nDamageType should only ever be used in this function prototype.
     */
    public static synchronized NWEffect effectACDecrease(int nValue, int nACModifyType, int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectACDecrease");
        pushInteger(nDamageType);
        pushInteger(nACModifyType);
        pushInteger(nValue);
        callFunction(411, 3);
        return popEffect();
    }

    /**
     * Create a Movement Speed Decrease effect.
     * @param nPercentChange - range 0 through 99
     * eg.
     * 0 = no change in speed
     * 50 = 50% slower
     * 99 = almost immobile
     */
    public static synchronized NWEffect effectMovementSpeedDecrease(int nPercentChange) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectMovementSpeedDecrease");
        pushInteger(nPercentChange);
        callFunction(412, 1);
        return popEffect();
    }

    /**
     * Create a Saving Throw Decrease effect.
     * @param nSave SAVING_THROW_* (not SAVING_THROW_TYPE_*)
     * SAVING_THROW_ALL
     * SAVING_THROW_FORT
     * SAVING_THROW_REFLEX
     * SAVING_THROW_WILL
     * @param nValue size of the Saving Throw decrease
     * @param nSaveType SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
     */
    public static synchronized NWEffect effectSavingThrowDecrease(int nSave, int nValue, int nSaveType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSavingThrowDecrease");
        pushInteger(nSaveType);
        pushInteger(nValue);
        pushInteger(nSave);
        callFunction(413, 3);
        return popEffect();
    }

    /**
     * Create a Skill Decrease effect.
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
     */
    public static synchronized NWEffect effectSkillDecrease(int nSkill, int nValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSkillDecrease");
        pushInteger(nValue);
        pushInteger(nSkill);
        callFunction(414, 2);
        return popEffect();
    }

    /**
     * Create a Spell Resistance Decrease effect.
     */
    public static synchronized NWEffect effectSpellResistanceDecrease(int nValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSpellResistanceDecrease");
        pushInteger(nValue);
        callFunction(415, 1);
        return popEffect();
    }

    /**
     * Determine whether oTarget is a plot object.
     */
    public static synchronized boolean getPlotFlag(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPlotFlag");
        pushObject(oTarget);
        callFunction(416, 1);
        return popInteger() > 0;
    }

    /**
     * Set oTarget's plot object status.
     */
    public static synchronized void setPlotFlag(NWObject oTarget, boolean bPlotFlag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPlotFlag");
        pushInteger(bPlotFlag ? 1 : 0);
        pushObject(oTarget);
        callFunction(417, 2);
    }

    /**
     * Create an Invisibility effect.
     * @param nInvisibilityType INVISIBILITY_TYPE_*
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
     * is invalid.
     */
    public static synchronized NWEffect effectInvisibility(int nInvisibilityType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectInvisibility");
        pushInteger(nInvisibilityType);
        callFunction(418, 1);
        return popEffect();
    }

    /**
     * Create a Concealment effect.
     * @param nPercentage 1-100 inclusive
     * @param nMissChanceType MISS_CHANCE_TYPE_*
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
     * nPercentage > 100.
     */
    public static synchronized NWEffect effectConcealment(int nPercentage, int nMissChanceType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectConcealment");
        pushInteger(nMissChanceType);
        pushInteger(nPercentage);
        callFunction(419, 2);
        return popEffect();
    }

    /**
     * Create a Darkness effect.
     */
    public static synchronized NWEffect effectDarkness() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDarkness");
        callFunction(420, 0);
        return popEffect();
    }

    /**
     * Create a Dispel Magic All effect.
     * If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
     * cause the dispel effect to use the level of the creature that created the
     * effect.
     */
    public static synchronized NWEffect effectDispelMagicAll(int nCasterLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDispelMagicAll");
        pushInteger(nCasterLevel);
        callFunction(421, 1);
        return popEffect();
    }

    /**
     * Create an Ultravision effect.
     */
    public static synchronized NWEffect effectUltravision() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectUltravision");
        callFunction(422, 0);
        return popEffect();
    }

    /**
     * Create a Negative Level effect.
     * @param nNumLevels the number of negative levels to apply.
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
     */
    public static synchronized NWEffect effectNegativeLevel(int nNumLevels, boolean bHPBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectNegativeLevel");
        pushInteger(bHPBonus ? 1 : 0);
        pushInteger(nNumLevels);
        callFunction(423, 2);
        return popEffect();
    }

    /**
     * Create a Polymorph effect.
     */
    public static synchronized NWEffect effectPolymorph(int nPolymorphSelection, boolean bLocked) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectPolymorph");
        pushInteger(bLocked ? 1 : 0);
        pushInteger(nPolymorphSelection);
        callFunction(424, 2);
        return popEffect();
    }

    /**
     * Create a Sanctuary effect.
     * @param nDifficultyClass must be a non-zero, positive number
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
     */
    public static synchronized NWEffect effectSanctuary(int nDifficultyClass) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSanctuary");
        pushInteger(nDifficultyClass);
        callFunction(425, 1);
        return popEffect();
    }

    /**
     * Create a True Seeing effect.
     */
    public static synchronized NWEffect effectTrueSeeing() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTrueSeeing");
        callFunction(426, 0);
        return popEffect();
    }

    /**
     * Create a See Invisible effect.
     */
    public static synchronized NWEffect effectSeeInvisible() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSeeInvisible");
        callFunction(427, 0);
        return popEffect();
    }

    /**
     * Create a Time Stop effect.
     */
    public static synchronized NWEffect effectTimeStop() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTimeStop");
        callFunction(428, 0);
        return popEffect();
    }

    /**
     * Create a Blindness effect.
     */
    public static synchronized NWEffect effectBlindness() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectBlindness");
        callFunction(429, 0);
        return popEffect();
    }

    /**
     * Determine whether oSource has a friendly reaction towards oTarget, depending
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),
     * oSource's Like/Dislike setting for oTarget.
     * Note: If you just want to know how two objects feel about each other in terms
     * of faction and personal reputation, use GetIsFriend() instead.
     * * Returns TRUE if oSource has a friendly reaction towards oTarget
     */
    public static synchronized boolean getIsReactionTypeFriendly(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsReactionTypeFriendly");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(430, 2);
        return popInteger() > 0;
    }

    /**
     * Determine whether oSource has a neutral reaction towards oTarget, depending
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),
     * oSource's Like/Dislike setting for oTarget.
     * Note: If you just want to know how two objects feel about each other in terms
     * of faction and personal reputation, use GetIsNeutral() instead.
     * * Returns TRUE if oSource has a neutral reaction towards oTarget
     */
    public static synchronized boolean getIsReactionTypeNeutral(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsReactionTypeNeutral");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(431, 2);
        return popInteger() > 0;
    }

    /**
     * Determine whether oSource has a Hostile reaction towards oTarget, depending
     * on the reputation, PVP setting and (if both oSource and oTarget are PCs),
     * oSource's Like/Dislike setting for oTarget.
     * Note: If you just want to know how two objects feel about each other in terms
     * of faction and personal reputation, use GetIsEnemy() instead.
     * * Returns TRUE if oSource has a hostile reaction towards oTarget
     */
    public static synchronized boolean getIsReactionTypeHostile(NWObject oTarget, NWObject oSource) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsReactionTypeHostile");
        pushObject(oSource);
        pushObject(oTarget);
        callFunction(432, 2);
        return popInteger() > 0;
    }

    /**
     * Create a Spell Level Absorption effect.
     * @param nMaxSpellLevelAbsorbed maximum spell level that will be absorbed by the
     * effect
     * @param nTotalSpellLevelsAbsorbed maximum number of spell levels that will be
     * absorbed by the effect
     * @param nSpellSchool SPELL_SCHOOL_*
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
     * nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
     * is invalid.
     */
    public static synchronized NWEffect effectSpellLevelAbsorption(int nMaxSpellLevelAbsorbed, int nTotalSpellLevelsAbsorbed, int nSpellSchool) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSpellLevelAbsorption");
        pushInteger(nSpellSchool);
        pushInteger(nTotalSpellLevelsAbsorbed);
        pushInteger(nMaxSpellLevelAbsorbed);
        callFunction(433, 3);
        return popEffect();
    }

    /**
     * Create a Dispel Magic Best effect.
     * If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
     * cause the dispel effect to use the level of the creature that created the
     * effect.
     */
    public static synchronized NWEffect effectDispelMagicBest(int nCasterLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDispelMagicBest");
        pushInteger(nCasterLevel);
        callFunction(434, 1);
        return popEffect();
    }

    /**
     * Try to send oTarget to a new server defined by sIPaddress.
     * @param oTarget
     * @param sIPaddress this can be numerical "192.168.0.84" or alphanumeric
     * "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
     * "www.bioware.com:5121"; if the port is not specified, it will default to
     * 5121.
     * @param sPassword login password for the destination server
     * @param sWaypointTag if this is set, after portalling the character will be moved
     * to this waypoint if it exists
     * @param bSeamless if this is set, the client wil not be prompted with the
     * information window telling them about the server, and they will not be
     * allowed to save a copy of their character if they are using a local vault
     * character.
     */
    public static synchronized void activatePortal(NWObject oTarget, String sIPaddress, String sPassword, String sWaypointTag, boolean bSeemless) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling activatePortal");
        pushInteger(bSeemless ? 1 : 0);
        pushString(sWaypointTag);
        pushString(sPassword);
        pushString(sIPaddress);
        pushObject(oTarget);
        callFunction(435, 5);
    }

    /**
     * Get the number of stacked items that oItem comprises.
     */
    public static synchronized int getNumStackedItems(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNumStackedItems");
        pushObject(oItem);
        callFunction(436, 1);
        return popInteger();
    }

    /**
     * Use this on an NPC to cause all creatures within a 10-metre radius to stop
     * what they are doing and sets the NPC's enemies within this range to be
     * neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
     * or an object that is not a creature, nothing will happen.
     */
    public static synchronized void surrenderToEnemies() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling surrenderToEnemies");
        callFunction(437, 0);
    }

    /**
     * Create a Miss Chance effect.
     * @param nPercentage 1-100 inclusive
     * @param nMissChanceType MISS_CHANCE_TYPE_*
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
     * nPercentage > 100.
     */
    public static synchronized NWEffect effectMissChance(int nPercentage, int nMissChanceType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectMissChance");
        pushInteger(nMissChanceType);
        pushInteger(nPercentage);
        callFunction(438, 2);
        return popEffect();
    }

    /**
     * Get the number of Hitdice worth of Turn Resistance that oUndead may have.
     * This will only work on undead creatures.
     */
    public static synchronized int getTurnResistanceHD(NWObject oUndead) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTurnResistanceHD");
        pushObject(oUndead);
        callFunction(439, 1);
        return popInteger();
    }

    /**
     * Get the size (CREATURE_SIZE_*) of oCreature.
     */
    public static synchronized int getCreatureSize(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCreatureSize");
        pushObject(oCreature);
        callFunction(440, 1);
        return popInteger();
    }

    /**
     * Create a Disappear/Appear effect.
     * The object will "fly away" for the duration of the effect and will reappear
     * at lLocation.
     * @param nAnimation determines which appear and disappear animations to use. Most creatures
     * only have animation 1, although a few have 2 (like beholders)
     */
    public static synchronized NWEffect effectDisappearAppear(NWLocation lLocation, int nAnimation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDisappearAppear");
        pushInteger(nAnimation);
        pushLocation(lLocation);
        callFunction(441, 2);
        return popEffect();
    }

    /**
     * Create a Disappear effect to make the object "fly away" and then destroy
     * itself.
     * @param nAnimation determines which appear and disappear animations to use. Most creatures
     * only have animation 1, although a few have 2 (like beholders)
     */
    public static synchronized NWEffect effectDisappear(int nAnimation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDisappear");
        pushInteger(nAnimation);
        callFunction(442, 1);
        return popEffect();
    }

    /**
     * Create an Appear effect to make the object "fly in".
     * @param nAnimation determines which appear and disappear animations to use. Most creatures
     * only have animation 1, although a few have 2 (like beholders)
     */
    public static synchronized NWEffect effectAppear(int nAnimation) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectAppear");
        pushInteger(nAnimation);
        callFunction(443, 1);
        return popEffect();
    }

    /**
     * The action subject will unlock oTarget, which can be a door or a placeable
     * object.
     */
    public static synchronized void actionUnlockObject(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionUnlockObject");
        pushObject(oTarget);
        callFunction(444, 1);
    }

    /**
     * The action subject will lock oTarget, which can be a door or a placeable
     * object.
     */
    public static synchronized void actionLockObject(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionLockObject");
        pushObject(oTarget);
        callFunction(445, 1);
    }

    /**
     * Create a Modify Attacks effect to add attacks.
     * @param nAttacks maximum is 5, even with the effect stacked
     * * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
     */
    public static synchronized NWEffect effectModifyAttacks(int nAttacks) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectModifyAttacks");
        pushInteger(nAttacks);
        callFunction(446, 1);
        return popEffect();
    }

    /**
     * Get the last trap detected by oTarget.
     * * Return value on error: OBJECT_INVALID
     */
    public static synchronized NWObject getLastTrapDetected(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastTrapDetected");
        pushObject(oTarget);
        callFunction(447, 1);
        return popObject();
    }

    /**
     * Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
     * damage to any melee attacker on a successful attack of damage type nDamageType.
     * @param nDamageAmount an integer value
     * @param nRandomAmount DAMAGE_BONUS_*
     * @param nDamageType DAMAGE_TYPE_*
     * NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
     * result in odd behaviour.
     */
    public static synchronized NWEffect effectDamageShield(int nDamageAmount, int nRandomAmount, int nDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectDamageShield");
        pushInteger(nDamageType);
        pushInteger(nRandomAmount);
        pushInteger(nDamageAmount);
        callFunction(448, 3);
        return popEffect();
    }

    /**
     * Get the trap nearest to oTarget.
     * Note : "trap objects" are actually any trigger, placeable or door that is
     * trapped in oTarget's area.
     * @param oTarget
     * @param bTrapDetected if this is TRUE, the trap returned has to have been detected
     * by oTarget.
     */
    public static synchronized NWObject getNearestTrapToObject(NWObject oTarget, boolean bTrapDetected) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNearestTrapToObject");
        pushInteger(bTrapDetected ? 1 : 0);
        pushObject(oTarget);
        callFunction(449, 2);
        return popObject();
    }

    /**
     * Get the name of oCreature's deity.
     * * Returns "" if oCreature is invalid (or if the deity name is blank for
     * oCreature).
     */
    public static synchronized String getDeity(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDeity");
        pushObject(oCreature);
        callFunction(450, 1);
        return popString();
    }

    /**
     * Get the name of oCreature's sub race.
     * * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
     */
    public static synchronized String getSubRace(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSubRace");
        pushObject(oTarget);
        callFunction(451, 1);
        return popString();
    }

    /**
     * Get oTarget's base fortitude saving throw value (this will only work for
     * creatures, doors, and placeables).
     * * Returns 0 if oTarget is invalid.
     */
    public static synchronized int getFortitudeSavingThrow(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFortitudeSavingThrow");
        pushObject(oTarget);
        callFunction(452, 1);
        return popInteger();
    }

    /**
     * Get oTarget's base will saving throw value (this will only work for creatures,
     * doors, and placeables).
     * * Returns 0 if oTarget is invalid.
     */
    public static synchronized int getWillSavingThrow(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getWillSavingThrow");
        pushObject(oTarget);
        callFunction(453, 1);
        return popInteger();
    }

    /**
     * Get oTarget's base reflex saving throw value (this will only work for
     * creatures, doors, and placeables).
     * * Returns 0 if oTarget is invalid.
     */
    public static synchronized int getReflexSavingThrow(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getReflexSavingThrow");
        pushObject(oTarget);
        callFunction(454, 1);
        return popInteger();
    }

    /**
     * Get oCreature's challenge rating.
     * * Returns 0.0 if oCreature is invalid.
     */
    public static synchronized float getChallengeRating(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getChallengeRating");
        pushObject(oCreature);
        callFunction(455, 1);
        return popFloat();
    }

    /**
     * Get oCreature's age.
     * * Returns 0 if oCreature is invalid.
     */
    public static synchronized int getAge(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAge");
        pushObject(oCreature);
        callFunction(456, 1);
        return popInteger();
    }

    /**
     * Get oCreature's movement rate.
     * * Returns 0 if oCreature is invalid.
     */
    public static synchronized int getMovementRate(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMovementRate");
        pushObject(oCreature);
        callFunction(457, 1);
        return popInteger();
    }

    /**
     * Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
     * * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
     * currently have a familiar.
     */
    public static synchronized int getFamiliarCreatureType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFamiliarCreatureType");
        pushObject(oCreature);
        callFunction(458, 1);
        return popInteger();
    }

    /**
     * Get oCreature's animal companion creature type
     * (ANIMAL_COMPANION_CREATURE_TYPE_*).
     * * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
     * not currently have an animal companion.
     */
    public static synchronized int getAnimalCompanionCreatureType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAnimalCompanionCreatureType");
        pushObject(oCreature);
        callFunction(459, 1);
        return popInteger();
    }

    /**
     * Get oCreature's familiar's name.
     * * Returns "" if oCreature is invalid, does not currently
     * have a familiar or if the familiar's name is blank.
     */
    public static synchronized String getFamiliarName(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFamiliarName");
        pushObject(oCreature);
        callFunction(460, 1);
        return popString();
    }

    /**
     * Get oCreature's animal companion's name.
     * * Returns "" if oCreature is invalid, does not currently
     * have an animal companion or if the animal companion's name is blank.
     */
    public static synchronized String getAnimalCompanionName(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAnimalCompanionName");
        pushObject(oTarget);
        callFunction(461, 1);
        return popString();
    }

    /**
     * The action subject will fake casting a spell at oTarget; the conjure and cast
     * animations and visuals will occur, nothing else.
     * @param nSpell
     * @param oTarget
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     */
    public static synchronized void actionCastFakeSpellAtObject(int nSpell, NWObject oTarget, int nProjectilePathType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCastFakeSpellAtObject");
        pushInteger(nProjectilePathType);
        pushObject(oTarget);
        pushInteger(nSpell);
        callFunction(462, 3);
    }

    /**
     * The action subject will fake casting a spell at lLocation; the conjure and
     * cast animations and visuals will occur, nothing else.
     * @param nSpell
     * @param lTarget
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     */
    public static synchronized void actionCastFakeSpellAtLocation(int nSpell, NWLocation lTarget, int nProjectilePathType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCastFakeSpellAtLocation");
        pushInteger(nProjectilePathType);
        pushLocation(lTarget);
        pushInteger(nSpell);
        callFunction(463, 3);
    }

    /**
     * Removes oAssociate from the service of oMaster, returning them to their
     * original faction.
     */
    public static synchronized void removeSummonedAssociate(NWObject oMaster, NWObject oAssociate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeSummonedAssociate");
        pushObject(oAssociate);
        pushObject(oMaster);
        callFunction(464, 2);
    }

    /**
     * Set the camera mode for oPlayer.
     * @param oPlayer
     * @param nCameraMode CAMERA_MODE_*
     * * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
     * happens.
     */
    public static synchronized void setCameraMode(NWObject oPlayer, int nCameraMode) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCameraMode");
        pushInteger(nCameraMode);
        pushObject(oPlayer);
        callFunction(465, 2);
    }

    /**
     * * Returns TRUE if oCreature is resting.
     */
    public static synchronized boolean getIsResting(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsResting");
        pushObject(oCreature);
        callFunction(466, 1);
        return popInteger() > 0;
    }

    /**
     * Get the last PC that has rested in the module.
     */
    public static synchronized NWObject getLastPCRested() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPCRested");
        callFunction(467, 0);
        return popObject();
    }

    /**
     * Set the weather for oTarget.
     * @param oTarget if this is GetModule(), all outdoor areas will be modified by the
     * weather constant. If it is an area, oTarget will play the weather only if
     * it is an outdoor area.
     * @param nWeather WEATHER_*
     * -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
     * -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
     * the appropriate precipitation *without stopping*.
     */
    public static synchronized void setWeather(NWObject oTarget, int nWeather) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setWeather");
        pushInteger(nWeather);
        pushObject(oTarget);
        callFunction(468, 2);
    }

    /**
     * Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
     * returned from the OnPCRested module event).
     */
    public static synchronized int getLastRestEventType() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastRestEventType");
        callFunction(469, 0);
        return popInteger();
    }

    /**
     * Shut down the currently loaded module and start a new one (moving all
     * currently-connected players to the starting point.
     */
    public static synchronized void startNewModule(String sModuleName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling startNewModule");
        pushString(sModuleName);
        callFunction(470, 1);
    }

    /**
     * Create a Swarm effect.
     * @param bLooping If this is TRUE, for the duration of the effect when one creature
     * created by this effect dies, the next one in the list will be created.  If
     * the last creature in the list dies, we loop back to the beginning and
     * sCreatureTemplate1 will be created, and so on...
     * @param sCreatureTemplate1
     * @param sCreatureTemplate2
     * @param sCreatureTemplate3
     * @param sCreatureTemplate4
     */
    public static synchronized NWEffect effectSwarm(boolean bLooping, String sCreatureTemplate1, String sCreatureTemplate2, String sCreatureTemplate3, String sCreatureTemplate4) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSwarm");
        pushString(sCreatureTemplate4);
        pushString(sCreatureTemplate3);
        pushString(sCreatureTemplate2);
        pushString(sCreatureTemplate1);
        pushInteger(bLooping ? 1 : 0);
        callFunction(471, 5);
        return popEffect();
    }

    /**
     * * Returns TRUE if oItem is a ranged weapon.
     */
    public static synchronized boolean getWeaponRanged(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getWeaponRanged");
        pushObject(oItem);
        callFunction(472, 1);
        return popInteger() > 0;
    }

    /**
     * Only if we are in a single player game, AutoSave the game.
     */
    public static synchronized void doSinglePlayerAutoSave() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling doSinglePlayerAutoSave");
        callFunction(473, 0);
    }

    /**
     * Get the game difficulty (GAME_DIFFICULTY_*).
     */
    public static synchronized int getGameDifficulty() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getGameDifficulty");
        callFunction(474, 0);
        return popInteger();
    }

    /**
     * Set the main light color on the tile at lTileLocation.
     * @param lTileLocation the vector part of this is the tile grid (x,y) coordinate of
     * the tile.
     * @param nMainLight1Color TILE_MAIN_LIGHT_COLOR_*
     * @param nMainLight2Color TILE_MAIN_LIGHT_COLOR_*
     */
    public static synchronized void setTileMainLightColor(NWLocation lTileLocation, int nMainLight1Color, int nMainLight2Color) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTileMainLightColor");
        pushInteger(nMainLight2Color);
        pushInteger(nMainLight1Color);
        pushLocation(lTileLocation);
        callFunction(475, 3);
    }

    /**
     * Set the source light color on the tile at lTileLocation.
     * @param lTileLocation the vector part of this is the tile grid (x,y) coordinate of
     * the tile.
     * @param nSourceLight1Color TILE_SOURCE_LIGHT_COLOR_*
     * @param nSourceLight2Color TILE_SOURCE_LIGHT_COLOR_*
     */
    public static synchronized void setTileSourceLightColor(NWLocation lTileLocation, int nSourceLight1Color, int nSourceLight2Color) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTileSourceLightColor");
        pushInteger(nSourceLight2Color);
        pushInteger(nSourceLight1Color);
        pushLocation(lTileLocation);
        callFunction(476, 3);
    }

    /**
     * All clients in oArea will recompute the static lighting.
     * This can be used to update the lighting after changing any tile lights or if
     * placeables with lights have been added/deleted.
     */
    public static synchronized void recomputeStaticLighting(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling recomputeStaticLighting");
        pushObject(oArea);
        callFunction(477, 1);
    }

    /**
     * Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
     * lTile.
     * @param lTile the vector part of this is the tile grid (x,y) coordinate of the tile.
     */
    public static synchronized int getTileMainLight1Color(NWLocation lTile) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTileMainLight1Color");
        pushLocation(lTile);
        callFunction(478, 1);
        return popInteger();
    }

    /**
     * Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
     * lTile.
     * @param lTile the vector part of this is the tile grid (x,y) coordinate of the
     * tile.
     */
    public static synchronized int getTileMainLight2Color(NWLocation lTile) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTileMainLight2Color");
        pushLocation(lTile);
        callFunction(479, 1);
        return popInteger();
    }

    /**
     * Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
     * at lTile.
     * @param lTile the vector part of this is the tile grid (x,y) coordinate of the
     * tile.
     */
    public static synchronized int getTileSourceLight1Color(NWLocation lTile) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTileSourceLight1Color");
        pushLocation(lTile);
        callFunction(480, 1);
        return popInteger();
    }

    /**
     * Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
     * at lTile.
     * @param lTile the vector part of this is the tile grid (x,y) coordinate of the
     * tile.
     */
    public static synchronized int getTileSourceLight2Color(NWLocation lTile) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTileSourceLight2Color");
        pushLocation(lTile);
        callFunction(481, 1);
        return popInteger();
    }

    /**
     * Make the corresponding panel button on the player's client start or stop
     * flashing.
     * @param oPlayer
     * @param nButton PANEL_BUTTON_*
     * @param bEnableFlash if this is TRUE nButton will start flashing.  It if is FALSE,
     * nButton will stop flashing.
     */
    public static synchronized void setPanelButtonFlash(NWObject oPlayer, int nButton, boolean bEnableFlash) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPanelButtonFlash");
        pushInteger(bEnableFlash ? 1 : 0);
        pushInteger(nButton);
        pushObject(oPlayer);
        callFunction(482, 3);
    }

    /**
     * Get the current action (ACTION_*) that oObject is executing.
     */
    public static synchronized int getCurrentAction(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCurrentAction");
        pushObject(oObject);
        callFunction(483, 1);
        return popInteger();
    }

    /**
     * Set how nStandardFaction feels about oCreature.
     * @param nStandardFaction STANDARD_FACTION_*
     * @param nNewReputation 0-100 (inclusive)
     * @param oCreature
     */
    public static synchronized void setStandardFactionReputation(int nStandardFaction, int nNewReputation, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setStandardFactionReputation");
        pushObject(oCreature);
        pushInteger(nNewReputation);
        pushInteger(nStandardFaction);
        callFunction(484, 3);
    }

    /**
     * Find out how nStandardFaction feels about oCreature.
     * @param nStandardFaction STANDARD_FACTION_*
     * @param oCreature
     * Returns -1 on an error.
     * Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
     * 0-10   :  Hostile.
     * 11-89  :  Neutral.
     * 90-100 :  Friendly.
     */
    public static synchronized int getStandardFactionReputation(int nStandardFaction, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStandardFactionReputation");
        pushObject(oCreature);
        pushInteger(nStandardFaction);
        callFunction(485, 2);
        return popInteger();
    }

    /**
     * Display floaty text above the specified creature.
     * The text will also appear in the chat buffer of each player that receives the
     * floaty text.
     * @param nStrRefToDisplay String ref (therefore text is translated)
     * @param oCreatureToFloatAbove
     * @param bBroadcastToFaction If this is TRUE then only creatures in the same faction
     * as oCreatureToFloatAbove
     * will see the floaty text, and only if they are within range (30 metres).
     */
    public static synchronized void floatingTextStrRefOnCreature(int nStrRefToDisplay, NWObject oCreatureToFloatAbove, boolean bBroadcastToFaction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling floatingTextStrRefOnCreature");
        pushInteger(bBroadcastToFaction ? 1 : 0);
        pushObject(oCreatureToFloatAbove);
        pushInteger(nStrRefToDisplay);
        callFunction(486, 3);
    }

    /**
     * Display floaty text above the specified creature.
     * The text will also appear in the chat buffer of each player that receives the
     * floaty text.
     * @param sStringToDisplay String
     * @param oCreatureToFloatAbove
     * @param bBroadcastToFaction If this is TRUE then only creatures in the same faction
     * as oCreatureToFloatAbove
     * will see the floaty text, and only if they are within range (30 metres).
     */
    public static synchronized void floatingTextStringOnCreature(String sStringToDisplay, NWObject oCreatureToFloatAbove, boolean bBroadcastToFaction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling floatingTextStringOnCreature");
        pushInteger(bBroadcastToFaction ? 1 : 0);
        pushObject(oCreatureToFloatAbove);
        pushString(sStringToDisplay);
        callFunction(487, 3);
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject is disarmable.
     */
    public static synchronized boolean getTrapDisarmable(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapDisarmable");
        pushObject(oTrapObject);
        callFunction(488, 1);
        return popInteger() > 0;
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject is detectable.
     */
    public static synchronized boolean getTrapDetectable(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapDetectable");
        pushObject(oTrapObject);
        callFunction(489, 1);
        return popInteger() > 0;
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * @param oCreature
     * * Returns TRUE if oCreature has detected oTrapObject
     */
    public static synchronized boolean getTrapDetectedBy(NWObject oTrapObject, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapDetectedBy");
        pushObject(oCreature);
        pushObject(oTrapObject);
        callFunction(490, 2);
        return popInteger() > 0;
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
     */
    public static synchronized boolean getTrapFlagged(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapFlagged");
        pushObject(oTrapObject);
        callFunction(491, 1);
        return popInteger() > 0;
    }

    /**
     * Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized int getTrapBaseType(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapBaseType");
        pushObject(oTrapObject);
        callFunction(492, 1);
        return popInteger();
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
     * after firing.
     */
    public static synchronized boolean getTrapOneShot(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapOneShot");
        pushObject(oTrapObject);
        callFunction(493, 1);
        return popInteger() > 0;
    }

    /**
     * Get the creator of oTrapObject, the creature that set the trap.
     * @param oTrapObject a placeable, door or trigger
     * * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
     */
    public static synchronized NWObject getTrapCreator(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapCreator");
        pushObject(oTrapObject);
        callFunction(494, 1);
        return popObject();
    }

    /**
     * Get the tag of the key that will disarm oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized String getTrapKeyTag(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapKeyTag");
        pushObject(oTrapObject);
        callFunction(495, 1);
        return popString();
    }

    /**
     * Get the DC for disarming oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized int getTrapDisarmDC(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapDisarmDC");
        pushObject(oTrapObject);
        callFunction(496, 1);
        return popInteger();
    }

    /**
     * Get the DC for detecting oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized int getTrapDetectDC(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapDetectDC");
        pushObject(oTrapObject);
        callFunction(497, 1);
        return popInteger();
    }

    /**
     * * Returns TRUE if a specific key is required to open the lock on oObject.
     */
    public static synchronized boolean getLockKeyRequired(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLockKeyRequired");
        pushObject(oObject);
        callFunction(498, 1);
        return popInteger() > 0;
    }

    /**
     * Get the tag of the key that will open the lock on oObject.
     */
    public static synchronized String getLockKeyTag(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLockKeyTag");
        pushObject(oObject);
        callFunction(499, 1);
        return popString();
    }

    /**
     * * Returns TRUE if the lock on oObject is lockable.
     */
    public static synchronized boolean getLockLockable(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLockLockable");
        pushObject(oObject);
        callFunction(500, 1);
        return popInteger() > 0;
    }

    /**
     * Get the DC for unlocking oObject.
     */
    public static synchronized int getLockUnlockDC(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLockUnlockDC");
        pushObject(oObject);
        callFunction(501, 1);
        return popInteger();
    }

    /**
     * Get the DC for locking oObject.
     */
    public static synchronized int getLockLockDC(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLockLockDC");
        pushObject(oObject);
        callFunction(502, 1);
        return popInteger();
    }

    /**
     * Get the last PC that levelled up.
     */
    public static synchronized NWObject getPCLevellingUp() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCLevellingUp");
        callFunction(503, 0);
        return popObject();
    }

    /**
     * @param nFeat FEAT_*
     * @param oObject
     * * Returns TRUE if oObject has effects on it originating from nFeat.
     */
    public static synchronized boolean getHasFeatEffect(int nFeat, NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasFeatEffect");
        pushObject(oObject);
        pushInteger(nFeat);
        callFunction(504, 2);
        return popInteger() > 0;
    }

    /**
     * Set the status of the illumination for oPlaceable.
     * @param oPlaceable
     * @param bIlluminate if this is TRUE, oPlaceable's illumination will be turned on.
     * If this is FALSE, oPlaceable's illumination will be turned off.
     * Note: You must call RecomputeStaticLighting() after calling this function in
     * order for the changes to occur visually for the players.
     * SetPlaceableIllumination() buffers the illumination changes, which are then
     * sent out to the players once RecomputeStaticLighting() is called.  As such,
     * it is best to call SetPlaceableIllumination() for all the placeables you wish
     * to set the illumination on, and then call RecomputeStaticLighting() once after
     * all the placeable illumination has been set.
     * * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
     * doesn't have a light, nothing will happen.
     */
    public static synchronized void setPlaceableIllumination(NWObject oPlaceable, boolean bIlluminate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPlaceableIllumination");
        pushInteger(bIlluminate ? 1 : 0);
        pushObject(oPlaceable);
        callFunction(505, 2);
    }

    /**
     * * Returns TRUE if the illumination for oPlaceable is on
     */
    public static synchronized int getPlaceableIllumination(NWObject oPlaceable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPlaceableIllumination");
        pushObject(oPlaceable);
        callFunction(506, 1);
        return popInteger();
    }

    /**
     * @param oPlaceable
     * @param nPlaceableAction PLACEABLE_ACTION_*
     * * Returns TRUE if nPlacebleAction is valid for oPlaceable.
     */
    public static synchronized boolean getIsPlaceableObjectActionPossible(NWObject oPlaceable, int nPlaceableAction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsPlaceableObjectActionPossible");
        pushInteger(nPlaceableAction);
        pushObject(oPlaceable);
        callFunction(507, 2);
        return popInteger() > 0;
    }

    /**
     * The caller performs nPlaceableAction on oPlaceable.
     * @param oPlaceable
     * @param nPlaceableAction PLACEABLE_ACTION_*
     */
    public static synchronized void doPlaceableObjectAction(NWObject oPlaceable, int nPlaceableAction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling doPlaceableObjectAction");
        pushInteger(nPlaceableAction);
        pushObject(oPlaceable);
        callFunction(508, 2);
    }

    /**
     * Get the first PC in the player list.
     * This resets the position in the player list for GetNextPC().
     */
    public static synchronized NWObject getFirstPC() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstPC");
        callFunction(509, 0);
        return popObject();
    }

    /**
     * Get the next PC in the player list.
     * This picks up where the last GetFirstPC() or GetNextPC() left off.
     */
    public static synchronized NWObject getNextPC() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextPC");
        callFunction(510, 0);
        return popObject();
    }

    /**
     * Set whether or not the creature oDetector has detected the trapped object oTrap.
     * @param oTrap A trapped trigger, placeable or door object.
     * @param oDetector This is the creature that the detected status of the trap is being adjusted for.
     * @param bDetected A Boolean that sets whether the trapped object has been detected or not.
     */
    public static synchronized int setTrapDetectedBy(NWObject oTrap, NWObject oDetector, boolean bDetected) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDetectedBy");
        pushInteger(bDetected ? 1 : 0);
        pushObject(oDetector);
        pushObject(oTrap);
        callFunction(511, 3);
        return popInteger();
    }

    /**
     * Note: Only placeables, doors and triggers can be trapped.
     * * Returns TRUE if oObject is trapped.
     */
    public static synchronized boolean getIsTrapped(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsTrapped");
        pushObject(oObject);
        callFunction(512, 1);
        return popInteger() > 0;
    }

    /**
     * Create a Turn Resistance Decrease effect.
     * @param nHitDice a positive number representing the number of hit dice for the
     * /  decrease
     */
    public static synchronized NWEffect effectTurnResistanceDecrease(int nHitDice) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTurnResistanceDecrease");
        pushInteger(nHitDice);
        callFunction(513, 1);
        return popEffect();
    }

    /**
     * Create a Turn Resistance Increase effect.
     * @param nHitDice a positive number representing the number of hit dice for the
     * increase
     */
    public static synchronized NWEffect effectTurnResistanceIncrease(int nHitDice) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectTurnResistanceIncrease");
        pushInteger(nHitDice);
        callFunction(514, 1);
        return popEffect();
    }

    /**
     * Spawn in the Death GUI.
     * The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
     * if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
     * function to use.
     * @param oPC
     * @param bRespawnButtonEnabled if this is TRUE, the "Respawn" button will be enabled
     * on the Death GUI.
     * @param bWaitForHelpButtonEnabled if this is TRUE, the "Wait For Help" button will
     * be enabled on the Death GUI (Note: This button will not appear in single player games).
     * @param nHelpStringReference
     * @param sHelpString
     */
    public static synchronized void popUpDeathGUIPanel(NWObject oPC, boolean bRespawnButtonEnabled, boolean bWaitForHelpButtonEnabled, int nHelpStringReference, String sHelpString) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling popUpDeathGUIPanel");
        pushString(sHelpString);
        pushInteger(nHelpStringReference);
        pushInteger(bWaitForHelpButtonEnabled ? 1 : 0);
        pushInteger(bRespawnButtonEnabled ? 1 : 0);
        pushObject(oPC);
        callFunction(515, 5);
    }

    /**
     * Disable oTrap.
     * @param oTrap a placeable, door or trigger.
     */
    public static synchronized void setTrapDisabled(NWObject oTrap) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDisabled");
        pushObject(oTrap);
        callFunction(516, 1);
    }

    /**
     * Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
     * GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
     * creature is pickpocketed).
     * Note: Return values may only ever be:
     * 1) A Creature
     * 2) Plot Characters will never have this value set
     * 3) Area of Effect Objects will return the AOE creator if they are registered
     * as this value, otherwise they will return INVALID_OBJECT_ID
     * 4) Traps will not return the creature that set the trap.
     * 5) This value will never be overwritten by another non-creature object.
     * 6) This value will never be a dead/destroyed creature
     */
    public static synchronized NWObject getLastHostileActor(NWObject oVictim) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastHostileActor");
        pushObject(oVictim);
        callFunction(517, 1);
        return popObject();
    }

    /**
     * Force all the characters of the players who are currently in the game to
     * be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
     */
    public static synchronized void exportAllCharacters() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling exportAllCharacters");
        callFunction(518, 0);
    }

    /**
     * Get the Day Track for oArea.
     */
    public static synchronized int musicBackgroundGetDayTrack(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundGetDayTrack");
        pushObject(oArea);
        callFunction(519, 1);
        return popInteger();
    }

    /**
     * Get the Night Track for oArea.
     */
    public static synchronized int musicBackgroundGetNightTrack(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundGetNightTrack");
        pushObject(oArea);
        callFunction(520, 1);
        return popInteger();
    }

    /**
     * Write sLogEntry as a timestamped entry into the log file
     */
    public static synchronized void writeTimestampedLogEntry(String sLogEntry) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling writeTimestampedLogEntry");
        pushString(sLogEntry);
        callFunction(521, 1);
    }

    /**
     * Get the module's name in the language of the server that's running it.
     * * If there is no entry for the language of the server, it will return an
     * empty string
     */
    public static synchronized String getModuleName() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleName");
        callFunction(522, 0);
        return popString();
    }

    /**
     * Get the player leader of the faction of which oMemberOfFaction is a member.
     * * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
     * or oMemberOfFaction is a member of a NPC faction.
     */
    public static synchronized NWObject getFactionLeader(NWObject oMemberOfFaction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFactionLeader");
        pushObject(oMemberOfFaction);
        callFunction(523, 1);
        return popObject();
    }

    /**
     * Sends szMessage to all the Dungeon Masters currently on the server.
     */
    public static synchronized void sendMessageToAllDMs(String szMessage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling sendMessageToAllDMs");
        pushString(szMessage);
        callFunction(524, 1);
    }

    /**
     * End the currently running game, play sEndMovie then return all players to the
     * game's main menu.
     */
    public static synchronized void endGame(String sEndMovie) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling endGame");
        pushString(sEndMovie);
        callFunction(525, 1);
    }

    /**
     * Remove oPlayer from the server.
     */
    public static synchronized void bootPC(NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling bootPC");
        pushObject(oPlayer);
        callFunction(526, 1);
    }

    /**
     * Counterspell oCounterSpellTarget.
     */
    public static synchronized void actionCounterSpell(NWObject oCounterSpellTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionCounterSpell");
        pushObject(oCounterSpellTarget);
        callFunction(527, 1);
    }

    /**
     * Set the ambient day volume for oArea to nVolume.
     * @param oArea
     * @param nVolume 0 - 100
     */
    public static synchronized void ambientSoundSetDayVolume(NWObject oArea, int nVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundSetDayVolume");
        pushInteger(nVolume);
        pushObject(oArea);
        callFunction(528, 2);
    }

    /**
     * Set the ambient night volume for oArea to nVolume.
     * @param oArea
     * @param nVolume 0 - 100
     */
    public static synchronized void ambientSoundSetNightVolume(NWObject oArea, int nVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling ambientSoundSetNightVolume");
        pushInteger(nVolume);
        pushObject(oArea);
        callFunction(529, 2);
    }

    /**
     * Get the Battle Track for oArea.
     */
    public static synchronized int musicBackgroundGetBattleTrack(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling musicBackgroundGetBattleTrack");
        pushObject(oArea);
        callFunction(530, 1);
        return popInteger();
    }

    /**
     * Determine whether oObject has an inventory.
     * * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
     * * Returns FALSE for all other object types.
     */
    public static synchronized boolean getHasInventory(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHasInventory");
        pushObject(oObject);
        callFunction(531, 1);
        return popInteger() > 0;
    }

    /**
     * Get the duration (in seconds) of the sound attached to nStrRef
     * * Returns 0.0f if no duration is stored or if no sound is attached
     */
    public static synchronized float getStrRefSoundDuration(int nStrRef) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStrRefSoundDuration");
        pushInteger(nStrRef);
        callFunction(532, 1);
        return popFloat();
    }

    /**
     * Add oPC to oPartyLeader's party.  This will only work on two PCs.
     * @param oPC player to add to a party
     * @param oPartyLeader player already in the party
     */
    public static synchronized void addToParty(NWObject oPC, NWObject oPartyLeader) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling addToParty");
        pushObject(oPartyLeader);
        pushObject(oPC);
        callFunction(533, 2);
    }

    /**
     * Remove oPC from their current party. This will only work on a PC.
     * @param oPC removes this player from whatever party they're currently in.
     */
    public static synchronized void removeFromParty(NWObject oPC) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeFromParty");
        pushObject(oPC);
        callFunction(534, 1);
    }

    /**
     * Returns the stealth mode of the specified creature.
     * @param oCreature
     * * Returns a constant STEALTH_MODE_*
     */
    public static synchronized int getStealthMode(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStealthMode");
        pushObject(oCreature);
        callFunction(535, 1);
        return popInteger();
    }

    /**
     * Returns the detection mode of the specified creature.
     * @param oCreature
     * * Returns a constant DETECT_MODE_*
     */
    public static synchronized int getDetectMode(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDetectMode");
        pushObject(oCreature);
        callFunction(536, 1);
        return popInteger();
    }

    /**
     * Returns the defensive casting mode of the specified creature.
     * @param oCreature
     * * Returns a constant DEFENSIVE_CASTING_MODE_*
     */
    public static synchronized int getDefensiveCastingMode(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDefensiveCastingMode");
        pushObject(oCreature);
        callFunction(537, 1);
        return popInteger();
    }

    /**
     * returns the appearance type of the specified creature.
     * * returns a constant APPEARANCE_TYPE_* for valid creatures
     * * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
     */
    public static synchronized int getAppearanceType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAppearanceType");
        pushObject(oCreature);
        callFunction(538, 1);
        return popInteger();
    }

    /**
     * SpawnScriptDebugger() will cause the script debugger to be executed
     * after this command is executed!
     * In order to compile the script for debugging go to Tools->Options->Script Editor
     * and check the box labeled "Generate Debug Information When Compiling Scripts"
     * After you have checked the above box, recompile the script that you want to debug.
     * If the script file isn't compiled for debugging, this command will do nothing.
     * Remove any SpawnScriptDebugger() calls once you have finished
     * debugging the script.
     */
    public static synchronized void spawnScriptDebugger() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling spawnScriptDebugger");
        callFunction(539, 0);
    }

    /**
     * in an onItemAcquired script, returns the size of the stack of the item
     * that was just acquired.
     * * returns the stack size of the item acquired
     */
    public static synchronized int getModuleItemAcquiredStackSize() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemAcquiredStackSize");
        callFunction(540, 0);
        return popInteger();
    }

    /**
     * Decrement the remaining uses per day for this creature by one.
     * @param oCreature creature to modify
     * @param nFeat constant FEAT_*
     */
    public static synchronized void decrementRemainingFeatUses(NWObject oCreature, int nFeat) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling decrementRemainingFeatUses");
        pushInteger(nFeat);
        pushObject(oCreature);
        callFunction(541, 2);
    }

    /**
     * Decrement the remaining uses per day for this creature by one.
     * @param oCreature creature to modify
     * @param nSpell constant SPELL_*
     */
    public static synchronized void decrementRemainingSpellUses(NWObject oCreature, int nSpell) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling decrementRemainingSpellUses");
        pushInteger(nSpell);
        pushObject(oCreature);
        callFunction(542, 2);
    }

    /**
     * returns the template used to create this object (if appropriate)
     * * returns an empty string when no template found
     */
    public static synchronized String getResRef(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getResRef");
        pushObject(oObject);
        callFunction(543, 1);
        return popString();
    }

    /**
     * returns an effect that will petrify the target
     * * currently applies EffectParalyze and the stoneskin visual effect.
     */
    public static synchronized NWEffect effectPetrify() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectPetrify");
        callFunction(544, 0);
        return popEffect();
    }

    /**
     * duplicates the item and returns a new object
     * oItem @param item to copy
     * oTargetInventory @param create item in this object's inventory. If this parameter
     * is not valid, the item will be created in oItem's location
     * bCopyVars @param copy the local variables from the old item to the new one
     * * returns the new item
     * * returns OBJECT_INVALID for non-items.
     * * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
     * other items.
     * * if it is possible to merge this item with any others in the target location,
     * then it will do so and return the merged object.
     */
    public static synchronized NWObject copyItem(NWObject oItem, NWObject oTargetInventory, boolean bCopyVars) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling copyItem");
        pushInteger(bCopyVars ? 1 : 0);
        pushObject(oTargetInventory);
        pushObject(oItem);
        callFunction(545, 3);
        return popObject();
    }

    /**
     * returns an effect that is guaranteed to paralyze a creature.
     * this effect is identical to EffectParalyze except that it cannot be resisted.
     */
    public static synchronized NWEffect effectCutsceneParalyze() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCutsceneParalyze");
        callFunction(546, 0);
        return popEffect();
    }

    /**
     * returns TRUE if the item CAN be dropped
     * Droppable items will appear on a creature's remains when the creature is killed.
     */
    public static synchronized boolean getDroppableFlag(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDroppableFlag");
        pushObject(oItem);
        callFunction(547, 1);
        return popInteger() > 0;
    }

    /**
     * returns TRUE if the placeable object is usable
     */
    public static synchronized boolean getUseableFlag(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getUseableFlag");
        pushObject(oObject);
        callFunction(548, 1);
        return popInteger() > 0;
    }

    /**
     * returns TRUE if the item is stolen
     */
    public static synchronized boolean getStolenFlag(NWObject oStolen) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStolenFlag");
        pushObject(oStolen);
        callFunction(549, 1);
        return popInteger() > 0;
    }

    /**
     * This stores a float out to the specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized void setCampaignFloat(String sCampaignName, String sVarName, float flFloat, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCampaignFloat");
        pushObject(oPlayer);
        pushFloat(flFloat);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(550, 4);
    }

    /**
     * This stores an int out to the specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized void setCampaignInt(String sCampaignName, String sVarName, int nInt, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCampaignInt");
        pushObject(oPlayer);
        pushInteger(nInt);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(551, 4);
    }

    /**
     * This stores a vector out to the specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized void setCampaignVector(String sCampaignName, String sVarName, NWVector vVector, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCampaignVector");
        pushObject(oPlayer);
        pushVector(vVector);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(552, 4);
    }

    /**
     * This stores a location out to the specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized void setCampaignLocation(String sCampaignName, String sVarName, NWLocation locLocation, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCampaignLocation");
        pushObject(oPlayer);
        pushLocation(locLocation);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(553, 4);
    }

    /**
     * This stores a string out to the specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized void setCampaignString(String sCampaignName, String sVarName, String sString, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCampaignString");
        pushObject(oPlayer);
        pushString(sString);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(554, 4);
    }

    /**
     * This will delete the entire campaign database if it exists.
     */
    public static synchronized void destroyCampaignDatabase(String sCampaignName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling destroyCampaignDatabase");
        pushString(sCampaignName);
        callFunction(555, 1);
    }

    /**
     * This will read a float from the  specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized float getCampaignFloat(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCampaignFloat");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(556, 3);
        return popFloat();
    }

    /**
     * This will read an int from the  specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized int getCampaignInt(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCampaignInt");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(557, 3);
        return popInteger();
    }

    /**
     * This will read a vector from the  specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized NWVector getCampaignVector(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCampaignVector");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(558, 3);
        return popVector();
    }

    /**
     * This will read a location from the  specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized NWLocation getCampaignLocation(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCampaignLocation");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(559, 3);
        return popLocation();
    }

    /**
     * This will read a string from the  specified campaign database
     * The database name IS case sensitive and it must be the same for both set and get functions.
     * The var name must be unique across the entire database, regardless of the variable type.
     * If you want a variable to pertain to a specific player in the game, provide a player object.
     */
    public static synchronized String getCampaignString(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCampaignString");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(560, 3);
        return popString();
    }

    /**
     * Duplicates the object specified by oSource.
     * ONLY creatures and items can be specified.
     * If an owner is specified and the object is an item, it will be put into their inventory
     * If the object is a creature, they will be created at the location.
     * If a new tag is specified, it will be assigned to the new object.
     */
    public static synchronized NWObject copyObject(NWObject oSource, NWLocation locLocation, NWObject oOwner, String sNewTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling copyObject");
        pushString(sNewTag);
        pushObject(oOwner);
        pushLocation(locLocation);
        pushObject(oSource);
        callFunction(561, 4);
        return popObject();
    }

    /**
     * This will remove ANY campaign variable. Regardless of type.
     * Note that by normal database standards, deleting does not actually removed the entry from
     * the database, but flags it as deleted. Do not expect the database files to shrink in size
     * from this command. If you want to 'pack' the database, you will have to do it externally
     * from the game.
     */
    public static synchronized void deleteCampaignVariable(String sCampaignName, String sVarName, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling deleteCampaignVariable");
        pushObject(oPlayer);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(562, 3);
    }

    /**
     * Stores an object with the given id.
     * NOTE: this command can only be used for storing Creatures and Items.
     * Returns 0 if it failled, 1 if it worked.
     */
    public static synchronized int storeCampaignObject(String sCampaignName, String sVarName, NWObject oObject, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling storeCampaignObject");
        pushObject(oPlayer);
        pushObject(oObject);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(563, 4);
        return popInteger();
    }

    /**
     * Use RetrieveCampaign with the given id to restore it.
     * If you specify an owner, the object will try to be created in their repository
     * If the owner can't handle the item (or if it's a creature) it will be created on the ground.
     */
    public static synchronized NWObject retrieveCampaignObject(String sCampaignName, String sVarName, NWLocation locLocation, NWObject oOwner, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling retrieveCampaignObject");
        pushObject(oPlayer);
        pushObject(oOwner);
        pushLocation(locLocation);
        pushString(sVarName);
        pushString(sCampaignName);
        callFunction(564, 5);
        return popObject();
    }

    /**
     * Returns an effect that is guaranteed to dominate a creature
     * Like EffectDominated but cannot be resisted
     */
    public static synchronized NWEffect effectCutsceneDominated() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCutsceneDominated");
        callFunction(565, 0);
        return popEffect();
    }

    /**
     * Returns stack size of an item
     * @param oItem item to query
     */
    public static synchronized int getItemStackSize(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemStackSize");
        pushObject(oItem);
        callFunction(566, 1);
        return popInteger();
    }

    /**
     * Sets stack size of an item.
     * @param oItem item to change
     * @param nSize new size of stack.  Will be restricted to be between 1 and the
     * maximum stack size for the item type.  If a value less than 1 is passed it
     * will set the stack to 1.  If a value greater than the max is passed
     * then it will set the stack to the maximum size
     */
    public static synchronized void setItemStackSize(NWObject oItem, int nSize) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setItemStackSize");
        pushInteger(nSize);
        pushObject(oItem);
        callFunction(567, 2);
    }

    /**
     * Returns charges left on an item
     * @param oItem item to query
     */
    public static synchronized int getItemCharges(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemCharges");
        pushObject(oItem);
        callFunction(568, 1);
        return popInteger();
    }

    /**
     * Sets charges left on an item.
     * @param oItem item to change
     * @param nCharges number of charges.  If value below 0 is passed, # charges will
     * be set to 0.  If value greater than maximum is passed, # charges will
     * be set to maximum.  If the # charges drops to 0 the item
     * will be destroyed.
     */
    public static synchronized void setItemCharges(NWObject oItem, int nCharges) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setItemCharges");
        pushInteger(nCharges);
        pushObject(oItem);
        callFunction(569, 2);
    }

    /**
     * ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************
     *
     * adds an item property to the specified item
     * Only temporary and permanent duration types are allowed.
     */
    public static synchronized void addItemProperty(int nDurationType, NWItemProperty ipProperty, NWObject oItem, float fDuration) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling addItemProperty");
        pushFloat(fDuration);
        pushObject(oItem);
        pushItemProperty(ipProperty);
        pushInteger(nDurationType);
        callFunction(570, 4);
    }

    /**
     * removes an item property from the specified item
     */
    public static synchronized void removeItemProperty(NWObject oItem, NWItemProperty ipProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling removeItemProperty");
        pushItemProperty(ipProperty);
        pushObject(oItem);
        callFunction(571, 2);
    }

    /**
     * if the item property is valid this will return true
     */
    public static synchronized boolean getIsItemPropertyValid(NWItemProperty ipProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsItemPropertyValid");
        pushItemProperty(ipProperty);
        callFunction(572, 1);
        return popInteger() > 0;
    }

    /**
     * Gets the first item property on an item
     */
    public static synchronized NWItemProperty getFirstItemProperty(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstItemProperty");
        pushObject(oItem);
        callFunction(573, 1);
        return popItemProperty();
    }

    /**
     * Will keep retrieving the next and the next item property on an Item,
     * will return an invalid item property when the list is empty.
     */
    public static synchronized NWItemProperty getNextItemProperty(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextItemProperty");
        pushObject(oItem);
        callFunction(574, 1);
        return popItemProperty();
    }

    /**
     * will return the item property type (ie. holy avenger)
     */
    public static synchronized int getItemPropertyType(NWItemProperty ip) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyType");
        pushItemProperty(ip);
        callFunction(575, 1);
        return popInteger();
    }

    /**
     * will return the duration type of the item property
     */
    public static synchronized int getItemPropertyDurationType(NWItemProperty ip) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyDurationType");
        pushItemProperty(ip);
        callFunction(576, 1);
        return popInteger();
    }

    /**
     * Returns Item property ability bonus.  You need to specify an
     * ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
     * be a positive integer between 1 and 12.
     */
    public static synchronized NWItemProperty itemPropertyAbilityBonus(int nAbility, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAbilityBonus");
        pushInteger(nBonus);
        pushInteger(nAbility);
        callFunction(577, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property AC bonus.  You need to specify the bonus.
     * The bonus should be a positive integer between 1 and 20. The modifier
     * type depends on the item it is being applied to.
     */
    public static synchronized NWItemProperty itemPropertyACBonus(int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyACBonus");
        pushInteger(nBonus);
        callFunction(578, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property AC bonus vs. alignment group.  An example of
     * an alignment group is Chaotic, or Good.  You need to specify the
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
     * The AC bonus should be an integer between 1 and 20.  The modifier
     * type depends on the item it is being applied to.
     */
    public static synchronized NWItemProperty itemPropertyACBonusVsAlign(int nIPAlignGroup, int nACBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyACBonusVsAlign");
        pushInteger(nACBonus);
        pushInteger(nIPAlignGroup);
        callFunction(579, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property AC bonus vs. Damage type (ie. piercing).  You
     * need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
     * AC bonus.  The AC bonus should be an integer between 1 and 20.  The
     * modifier type depends on the item it is being applied to.
     * NOTE: Only the first 3 damage types may be used here, the 3 basic
     * physical types.
     */
    public static synchronized NWItemProperty itemPropertyACBonusVsDmgType(int nIPDamageType, int nACBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyACBonusVsDmgType");
        pushInteger(nACBonus);
        pushInteger(nIPDamageType);
        callFunction(580, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property AC bonus vs. Racial group.  You need to specify
     * the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
     * bonus should be an integer between 1 and 20.  The modifier type depends
     * on the item it is being applied to.
     */
    public static synchronized NWItemProperty itemPropertyACBonusVsRace(int nIPRacialType, int nACBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyACBonusVsRace");
        pushInteger(nACBonus);
        pushInteger(nIPRacialType);
        callFunction(581, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property AC bonus vs. Specific alignment.  You need to
     * specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
     * bonus.  The AC bonus should be an integer between 1 and 20.  The
     * modifier type depends on the item it is being applied to.
     */
    public static synchronized NWItemProperty itemPropertyACBonusVsSAlign(int nAlignment, int nACBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyACBonusVsSAlign");
        pushInteger(nACBonus);
        pushInteger(nAlignment);
        callFunction(582, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Enhancement bonus.  You need to specify the
     * enhancement bonus.  The Enhancement bonus should be an integer between
     * 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyEnhancementBonus(int nEnhancementBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyEnhancementBonus");
        pushInteger(nEnhancementBonus);
        callFunction(583, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Enhancement bonus vs. an Alignment group.  You
     * need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
     * and the enhancement bonus.  The Enhancement bonus should be an integer
     * between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyEnhancementBonusVsAlign(int nIPAlignGroup, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyEnhancementBonusVsAlign");
        pushInteger(nBonus);
        pushInteger(nIPAlignGroup);
        callFunction(584, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Enhancement bonus vs. Racial group.  You need
     * to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
     * enhancement bonus.  The enhancement bonus should be an integer between
     * 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyEnhancementBonusVsRace(int nIPRacialType, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyEnhancementBonusVsRace");
        pushInteger(nBonus);
        pushInteger(nIPRacialType);
        callFunction(585, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Enhancement bonus vs. a specific alignment.  You
     * need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
     * enhancement bonus.  The enhancement bonus should be an integer between
     * 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyEnhancementBonusVsSAlign(int nAlignment, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyEnhancementBonusVsSAlign");
        pushInteger(nBonus);
        pushInteger(nAlignment);
        callFunction(586, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Enhancment penalty.  You need to specify the
     * enhancement penalty.  The enhancement penalty should be a POSITIVE
     * integer between 1 and 5 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyEnhancementPenalty(int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyEnhancementPenalty");
        pushInteger(nPenalty);
        callFunction(587, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property weight reduction.  You need to specify the weight
     * reduction constant(IP_CONST_REDUCEDWEIGHT_*).
     */
    public static synchronized NWItemProperty itemPropertyWeightReduction(int nReduction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyWeightReduction");
        pushInteger(nReduction);
        callFunction(588, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Bonus Feat.  You need to specify the the feat
     * constant(IP_CONST_FEAT_*).
     */
    public static synchronized NWItemProperty itemPropertyBonusFeat(int nFeat) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyBonusFeat");
        pushInteger(nFeat);
        callFunction(589, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Bonus level spell (Bonus spell of level).  You must
     * specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
     * spell casting class) and the level of the bonus spell.  The level of the
     * bonus spell should be an integer between 0 and 9.
     */
    public static synchronized NWItemProperty itemPropertyBonusLevelSpell(int nClass, int nSpellLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyBonusLevelSpell");
        pushInteger(nSpellLevel);
        pushInteger(nClass);
        callFunction(590, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Cast spell.  You must specify the spell constant
     * (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
     * NOTE: The number after the name of the spell in the constant is the level
     * at which the spell will be cast.  Sometimes there are multiple copies
     * of the same spell but they each are cast at a different level.  The higher
     * the level, the more cost will be added to the item.
     * NOTE: The list of spells that can be applied to an item will depend on the
     * item type.  For instance there are spells that can be applied to a wand
     * that cannot be applied to a potion.  Below is a list of the types and the
     * spells that are allowed to be placed on them.  If you try to put a cast
     * spell effect on an item that is not allowed to have that effect it will
     * not work.
     * NOTE: Even if spells have multiple versions of different levels they are only
     * listed below once.
     *
     * WANDS:
     * Acid_Splash
     * Activate_Item
     * Aid
     * Amplify
     * Animate_Dead
     * AuraOfGlory
     * BalagarnsIronHorn
     * Bane
     * Banishment
     * Barkskin
     * Bestow_Curse
     * Bigbys_Clenched_Fist
     * Bigbys_Crushing_Hand
     * Bigbys_Forceful_Hand
     * Bigbys_Grasping_Hand
     * Bigbys_Interposing_Hand
     * Bless
     * Bless_Weapon
     * Blindness/Deafness
     * Blood_Frenzy
     * Bombardment
     * Bulls_Strength
     * Burning_Hands
     * Call_Lightning
     * Camoflage
     * Cats_Grace
     * Charm_Monster
     * Charm_Person
     * Charm_Person_or_Animal
     * Clairaudience/Clairvoyance
     * Clarity
     * Color_Spray
     * Confusion
     * Continual_Flame
     * Cure_Critical_Wounds
     * Cure_Light_Wounds
     * Cure_Minor_Wounds
     * Cure_Moderate_Wounds
     * Cure_Serious_Wounds
     * Darkness
     * Darkvision
     * Daze
     * Death_Ward
     * Dirge
     * Dismissal
     * Dispel_Magic
     * Displacement
     * Divine_Favor
     * Divine_Might
     * Divine_Power
     * Divine_Shield
     * Dominate_Animal
     * Dominate_Person
     * Doom
     * Dragon_Breath_Acid
     * Dragon_Breath_Cold
     * Dragon_Breath_Fear
     * Dragon_Breath_Fire
     * Dragon_Breath_Gas
     * Dragon_Breath_Lightning
     * Dragon_Breath_Paralyze
     * Dragon_Breath_Sleep
     * Dragon_Breath_Slow
     * Dragon_Breath_Weaken
     * Drown
     * Eagle_Spledor
     * Earthquake
     * Electric_Jolt
     * Elemental_Shield
     * Endurance
     * Endure_Elements
     * Enervation
     * Entangle
     * Entropic_Shield
     * Etherealness
     * Expeditious_Retreat
     * Fear
     * Find_Traps
     * Fireball
     * Firebrand
     * Flame_Arrow
     * Flame_Lash
     * Flame_Strike
     * Flare
     * Foxs_Cunning
     * Freedom_of_Movement
     * Ghostly_Visage
     * Ghoul_Touch
     * Grease
     * Greater_Magic_Fang
     * Greater_Magic_Weapon
     * Grenade_Acid
     * Grenade_Caltrops
     * Grenade_Chicken
     * Grenade_Choking
     * Grenade_Fire
     * Grenade_Holy
     * Grenade_Tangle
     * Grenade_Thunderstone
     * Gust_of_wind
     * Hammer_of_the_Gods
     * Haste
     * Hold_Animal
     * Hold_Monster
     * Hold_Person
     * Ice_Storm
     * Identify
     * Improved_Invisibility
     * Inferno
     * Inflict_Critical_Wounds
     * Inflict_Light_Wounds
     * Inflict_Minor_Wounds
     * Inflict_Moderate_Wounds
     * Inflict_Serious_Wounds
     * Invisibility
     * Invisibility_Purge
     * Invisibility_Sphere
     * Isaacs_Greater_Missile_Storm
     * Isaacs_Lesser_Missile_Storm
     * Knock
     * Lesser_Dispel
     * Lesser_Restoration
     * Lesser_Spell_Breach
     * Light
     * Lightning_Bolt
     * Mage_Armor
     * Magic_Circle_against_Alignment
     * Magic_Fang
     * Magic_Missile
     * Manipulate_Portal_Stone
     * Mass_Camoflage
     * Melfs_Acid_Arrow
     * Meteor_Swarm
     * Mind_Blank
     * Mind_Fog
     * Negative_Energy_Burst
     * Negative_Energy_Protection
     * Negative_Energy_Ray
     * Neutralize_Poison
     * One_With_The_Land
     * Owls_Insight
     * Owls_Wisdom
     * Phantasmal_Killer
     * Planar_Ally
     * Poison
     * Polymorph_Self
     * Prayer
     * Protection_from_Alignment
     * Protection_From_Elements
     * Quillfire
     * Ray_of_Enfeeblement
     * Ray_of_Frost
     * Remove_Blindness/Deafness
     * Remove_Curse
     * Remove_Disease
     * Remove_Fear
     * Remove_Paralysis
     * Resist_Elements
     * Resistance
     * Restoration
     * Sanctuary
     * Scare
     * Searing_Light
     * See_Invisibility
     * Shadow_Conjuration
     * Shield
     * Shield_of_Faith
     * Silence
     * Sleep
     * Slow
     * Sound_Burst
     * Spike_Growth
     * Stinking_Cloud
     * Stoneskin
     * Summon_Creature_I
     * Summon_Creature_I
     * Summon_Creature_II
     * Summon_Creature_III
     * Summon_Creature_IV
     * Sunburst
     * Tashas_Hideous_Laughter
     * True_Strike
     * Undeaths_Eternal_Foe
     * Unique_Power
     * Unique_Power_Self_Only
     * Vampiric_Touch
     * Virtue
     * Wall_of_Fire
     * Web
     * Wounding_Whispers
     *
     * POTIONS:
     * Activate_Item
     * Aid
     * Amplify
     * AuraOfGlory
     * Bane
     * Barkskin
     * Barkskin
     * Barkskin
     * Bless
     * Bless_Weapon
     * Bless_Weapon
     * Blood_Frenzy
     * Bulls_Strength
     * Bulls_Strength
     * Bulls_Strength
     * Camoflage
     * Cats_Grace
     * Cats_Grace
     * Cats_Grace
     * Clairaudience/Clairvoyance
     * Clairaudience/Clairvoyance
     * Clairaudience/Clairvoyance
     * Clarity
     * Continual_Flame
     * Cure_Critical_Wounds
     * Cure_Critical_Wounds
     * Cure_Critical_Wounds
     * Cure_Light_Wounds
     * Cure_Light_Wounds
     * Cure_Minor_Wounds
     * Cure_Moderate_Wounds
     * Cure_Moderate_Wounds
     * Cure_Moderate_Wounds
     * Cure_Serious_Wounds
     * Cure_Serious_Wounds
     * Cure_Serious_Wounds
     * Darkness
     * Darkvision
     * Darkvision
     * Death_Ward
     * Dispel_Magic
     * Dispel_Magic
     * Displacement
     * Divine_Favor
     * Divine_Might
     * Divine_Power
     * Divine_Shield
     * Dragon_Breath_Acid
     * Dragon_Breath_Cold
     * Dragon_Breath_Fear
     * Dragon_Breath_Fire
     * Dragon_Breath_Gas
     * Dragon_Breath_Lightning
     * Dragon_Breath_Paralyze
     * Dragon_Breath_Sleep
     * Dragon_Breath_Slow
     * Dragon_Breath_Weaken
     * Eagle_Spledor
     * Eagle_Spledor
     * Eagle_Spledor
     * Elemental_Shield
     * Elemental_Shield
     * Endurance
     * Endurance
     * Endurance
     * Endure_Elements
     * Entropic_Shield
     * Ethereal_Visage
     * Ethereal_Visage
     * Etherealness
     * Expeditious_Retreat
     * Find_Traps
     * Foxs_Cunning
     * Foxs_Cunning
     * Foxs_Cunning
     * Freedom_of_Movement
     * Ghostly_Visage
     * Ghostly_Visage
     * Ghostly_Visage
     * Globe_of_Invulnerability
     * Greater_Bulls_Strength
     * Greater_Cats_Grace
     * Greater_Dispelling
     * Greater_Dispelling
     * Greater_Eagles_Splendor
     * Greater_Endurance
     * Greater_Foxs_Cunning
     * Greater_Magic_Weapon
     * Greater_Owls_Wisdom
     * Greater_Restoration
     * Greater_Spell_Mantle
     * Greater_Stoneskin
     * Grenade_Acid
     * Grenade_Caltrops
     * Grenade_Chicken
     * Grenade_Choking
     * Grenade_Fire
     * Grenade_Holy
     * Grenade_Tangle
     * Grenade_Thunderstone
     * Haste
     * Haste
     * Heal
     * Hold_Animal
     * Hold_Monster
     * Hold_Person
     * Identify
     * Invisibility
     * Lesser_Dispel
     * Lesser_Dispel
     * Lesser_Mind_Blank
     * Lesser_Restoration
     * Lesser_Spell_Mantle
     * Light
     * Light
     * Mage_Armor
     * Manipulate_Portal_Stone
     * Mass_Camoflage
     * Mind_Blank
     * Minor_Globe_of_Invulnerability
     * Minor_Globe_of_Invulnerability
     * Mordenkainens_Disjunction
     * Negative_Energy_Protection
     * Negative_Energy_Protection
     * Negative_Energy_Protection
     * Neutralize_Poison
     * One_With_The_Land
     * Owls_Insight
     * Owls_Wisdom
     * Owls_Wisdom
     * Owls_Wisdom
     * Polymorph_Self
     * Prayer
     * Premonition
     * Protection_From_Elements
     * Protection_From_Elements
     * Protection_from_Spells
     * Protection_from_Spells
     * Raise_Dead
     * Remove_Blindness/Deafness
     * Remove_Curse
     * Remove_Disease
     * Remove_Fear
     * Remove_Paralysis
     * Resist_Elements
     * Resist_Elements
     * Resistance
     * Resistance
     * Restoration
     * Resurrection
     * Rogues_Cunning
     * See_Invisibility
     * Shadow_Shield
     * Shapechange
     * Shield
     * Shield_of_Faith
     * Special_Alcohol_Beer
     * Special_Alcohol_Spirits
     * Special_Alcohol_Wine
     * Special_Herb_Belladonna
     * Special_Herb_Garlic
     * Spell_Mantle
     * Spell_Resistance
     * Spell_Resistance
     * Stoneskin
     * Tensers_Transformation
     * True_Seeing
     * True_Strike
     * Unique_Power
     * Unique_Power_Self_Only
     * Virtue
     *
     * GENERAL USE (ie. everything else):
     * Just about every spell is useable by all the general use items so instead we
     * will only list the ones that are not allowed:
     * Special_Alcohol_Beer
     * Special_Alcohol_Spirits
     * Special_Alcohol_Wine
     *
     */
    public static synchronized NWItemProperty itemPropertyCastSpell(int nSpell, int nNumUses) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyCastSpell");
        pushInteger(nNumUses);
        pushInteger(nSpell);
        callFunction(591, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property damage bonus.  You must specify the damage type constant
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.
     */
    public static synchronized NWItemProperty itemPropertyDamageBonus(int nIPDamageType, int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageBonus");
        pushInteger(nDamage);
        pushInteger(nIPDamageType);
        callFunction(592, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property damage bonus vs. Alignment groups.  You must specify the
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.
     */
    public static synchronized NWItemProperty itemPropertyDamageBonusVsAlign(int nIPAlignGroup, int nIPDamageType, int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageBonusVsAlign");
        pushInteger(nDamage);
        pushInteger(nIPDamageType);
        pushInteger(nIPAlignGroup);
        callFunction(593, 3);
        return popItemProperty();
    }

    /**
     * Returns Item property damage bonus vs. specific race.  You must specify the
     * racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.
     */
    public static synchronized NWItemProperty itemPropertyDamageBonusVsRace(int nIPRacialType, int nIPDamageType, int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageBonusVsRace");
        pushInteger(nDamage);
        pushInteger(nIPDamageType);
        pushInteger(nIPRacialType);
        callFunction(594, 3);
        return popItemProperty();
    }

    /**
     * Returns Item property damage bonus vs. specific alignment.  You must specify the
     * specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
     * (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.
     */
    public static synchronized NWItemProperty itemPropertyDamageBonusVsSAlign(int nAlignment, int nIPDamageType, int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageBonusVsSAlign");
        pushInteger(nDamage);
        pushInteger(nIPDamageType);
        pushInteger(nAlignment);
        callFunction(595, 3);
        return popItemProperty();
    }

    /**
     * Returns Item property damage immunity.  You must specify the damage type constant
     * (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
     * constant(IP_CONST_DAMAGEIMMUNITY_*).
     * NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
     * Cold, Electrical, Fire, Piercing, Slashing, Sonic.
     */
    public static synchronized NWItemProperty itemPropertyDamageImmunity(int nIPDamageType, int nImmuneBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageImmunity");
        pushInteger(nImmuneBonus);
        pushInteger(nIPDamageType);
        callFunction(596, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property damage penalty.  You must specify the damage penalty.
     * The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyDamagePenalty(int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamagePenalty");
        pushInteger(nPenalty);
        callFunction(597, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property damage reduction.  You must specify the enhancment level
     * (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
     * and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
     * up if your weapon is not of high enough enhancement.
     */
    public static synchronized NWItemProperty itemPropertyDamageReduction(int nEnhancement, int nHPSoak) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageReduction");
        pushInteger(nHPSoak);
        pushInteger(nEnhancement);
        callFunction(598, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property damage resistance.  You must specify the damage type
     * constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
     * (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
     */
    public static synchronized NWItemProperty itemPropertyDamageResistance(int nIPDamageType, int nHPResist) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageResistance");
        pushInteger(nHPResist);
        pushInteger(nIPDamageType);
        callFunction(599, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property damage vulnerability.  You must specify the damage type
     * constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
     * and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
     */
    public static synchronized NWItemProperty itemPropertyDamageVulnerability(int nIPDamageType, int nVulnerability) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDamageVulnerability");
        pushInteger(nVulnerability);
        pushInteger(nIPDamageType);
        callFunction(600, 2);
        return popItemProperty();
    }

    /**
     * Return Item property Darkvision.
     */
    public static synchronized NWItemProperty itemPropertyDarkvision() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDarkvision");
        callFunction(601, 0);
        return popItemProperty();
    }

    /**
     * Return Item property decrease ability score.  You must specify the ability
     * constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
     * a POSITIVE integer between 1 and 10 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyDecreaseAbility(int nAbility, int nModifier) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDecreaseAbility");
        pushInteger(nModifier);
        pushInteger(nAbility);
        callFunction(602, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property decrease Armor Class.  You must specify the armor
     * modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
     * The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyDecreaseAC(int nModifierType, int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDecreaseAC");
        pushInteger(nPenalty);
        pushInteger(nModifierType);
        callFunction(603, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property decrease skill.  You must specify the constant for the
     * skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
     * must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyDecreaseSkill(int nSkill, int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyDecreaseSkill");
        pushInteger(nPenalty);
        pushInteger(nSkill);
        callFunction(604, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property container reduced weight.  This is used for special
     * containers that reduce the weight of the objects inside them.  You must
     * specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
     */
    public static synchronized NWItemProperty itemPropertyContainerReducedWeight(int nContainerType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyContainerReducedWeight");
        pushInteger(nContainerType);
        callFunction(605, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property extra melee damage type.  You must specify the extra
     * melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
     * NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
     * here.
     * NOTE: It is also only applicable to melee weapons.
     */
    public static synchronized NWItemProperty itemPropertyExtraMeleeDamageType(int nIPDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyExtraMeleeDamageType");
        pushInteger(nIPDamageType);
        callFunction(606, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property extra ranged damage type.  You must specify the extra
     * melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
     * NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
     * here.
     * NOTE: It is also only applicable to ranged weapons.
     */
    public static synchronized NWItemProperty itemPropertyExtraRangeDamageType(int nIPDamageType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyExtraRangeDamageType");
        pushInteger(nIPDamageType);
        callFunction(607, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property haste.
     */
    public static synchronized NWItemProperty itemPropertyHaste() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyHaste");
        callFunction(608, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property Holy Avenger.
     */
    public static synchronized NWItemProperty itemPropertyHolyAvenger() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyHolyAvenger");
        callFunction(609, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property immunity to miscellaneous effects.  You must specify the
     * effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
     */
    public static synchronized NWItemProperty itemPropertyImmunityMisc(int nIPMiscImmunityType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyImmunityMisc");
        pushInteger(nIPMiscImmunityType);
        callFunction(610, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property improved evasion.
     */
    public static synchronized NWItemProperty itemPropertyImprovedEvasion() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyImprovedEvasion");
        callFunction(611, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property bonus spell resistance.  You must specify the bonus spell
     * resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
     */
    public static synchronized NWItemProperty itemPropertyBonusSpellResistance(int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyBonusSpellResistance");
        pushInteger(nBonus);
        callFunction(612, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property saving throw bonus vs. a specific effect or damage type.
     * You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
     * applied to and the bonus that is be applied.  The bonus must be an integer
     * between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyBonusSavingThrowVsX(int nBonusType, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyBonusSavingThrowVsX");
        pushInteger(nBonus);
        pushInteger(nBonusType);
        callFunction(613, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property saving throw bonus to the base type (ie. will, reflex,
     * fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
     * to which the user gets the bonus and the bonus that he/she will get.  The
     * bonus must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyBonusSavingThrow(int nBaseSaveType, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyBonusSavingThrow");
        pushInteger(nBonus);
        pushInteger(nBaseSaveType);
        callFunction(614, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property keen.  This means a critical threat range of 19-20 on a
     * weapon will be increased to 17-20 etc.
     */
    public static synchronized NWItemProperty itemPropertyKeen() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyKeen");
        callFunction(615, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property light.  You must specify the intesity constant of the
     * light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
     * (IP_CONST_LIGHTCOLOR_*).
     */
    public static synchronized NWItemProperty itemPropertyLight(int nBrightness, int nColor) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyLight");
        pushInteger(nColor);
        pushInteger(nBrightness);
        callFunction(616, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property Max range strength modification (ie. mighty).  You must
     * specify the maximum modifier for strength that is allowed on a ranged weapon.
     * The modifier must be a positive integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyMaxRangeStrengthMod(int nModifier) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyMaxRangeStrengthMod");
        pushInteger(nModifier);
        callFunction(617, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property no damage.  This means the weapon will do no damage in
     * combat.
     */
    public static synchronized NWItemProperty itemPropertyNoDamage() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyNoDamage");
        callFunction(618, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property on hit -> do effect property.  You must specify the on
     * hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
     * Some of the item properties require a special parameter as well.  If the
     * property does not require one you may leave out the last one.  The list of
     * the ones with 3 parameters and what they are are as follows:
     * ABILITYDRAIN      :nSpecial is the ability it is to drain.
     * constant(IP_CONST_ABILITY_*)
     * BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * CONFUSION         :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * DAZE              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * DISEASE           :nSpecial is the type of desease that will effect the victim.
     * constant(DISEASE_*)
     * DOOM              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * FEAR              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * HOLD              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
     * constant(IP_CONST_POISON_*)
     * SILENCE           :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * SLAYRACE          :nSpecial is the race that will be slain.
     * constant(IP_CONST_RACIALTYPE_*)
     * SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
     * constant(IP_CONST_ALIGNMENTGROUP_*)
     * SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
     * constant(IP_CONST_ALIGNMENT_*)
     * SLEEP             :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * SLOW              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     * STUN              :nSpecial is the duration/percentage of effecting victim.
     * constant(IP_CONST_ONHIT_DURATION_*)
     */
    public static synchronized NWItemProperty itemPropertyOnHitProps(int nProperty, int nSaveDC, int nSpecial) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyOnHitProps");
        pushInteger(nSpecial);
        pushInteger(nSaveDC);
        pushInteger(nProperty);
        callFunction(619, 3);
        return popItemProperty();
    }

    /**
     * Returns Item property reduced saving throw vs. an effect or damage type.  You must
     * specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
     * penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
     * (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyReducedSavingThrowVsX(int nBaseSaveType, int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyReducedSavingThrowVsX");
        pushInteger(nPenalty);
        pushInteger(nBaseSaveType);
        callFunction(620, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property reduced saving to base type.  You must specify the base
     * type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
     * to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
     * The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyReducedSavingThrow(int nBonusType, int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyReducedSavingThrow");
        pushInteger(nPenalty);
        pushInteger(nBonusType);
        callFunction(621, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property regeneration.  You must specify the regeneration amount.
     * The amount must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyRegeneration(int nRegenAmount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyRegeneration");
        pushInteger(nRegenAmount);
        callFunction(622, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property skill bonus.  You must specify the skill to which the user
     * will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
     * be an integer between 1 and 50.
     */
    public static synchronized NWItemProperty itemPropertySkillBonus(int nSkill, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertySkillBonus");
        pushInteger(nBonus);
        pushInteger(nSkill);
        callFunction(623, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property spell immunity vs. specific spell.  You must specify the
     * spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
     */
    public static synchronized NWItemProperty itemPropertySpellImmunitySpecific(int nSpell) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertySpellImmunitySpecific");
        pushInteger(nSpell);
        callFunction(624, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property spell immunity vs. spell school.  You must specify the
     * school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
     */
    public static synchronized NWItemProperty itemPropertySpellImmunitySchool(int nIPSpellSchool) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertySpellImmunitySchool");
        pushInteger(nIPSpellSchool);
        callFunction(625, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Thieves tools.  You must specify the modifier you wish
     * the tools to have.  The modifier must be an integer between 1 and 12.
     */
    public static synchronized NWItemProperty itemPropertyThievesTools(int nModifier) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyThievesTools");
        pushInteger(nModifier);
        callFunction(626, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
     * must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyAttackBonus(int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAttackBonus");
        pushInteger(nBonus);
        callFunction(627, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Attack bonus vs. alignment group.  You must specify the
     * alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
     * bonus must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyAttackBonusVsAlign(int nIPAlignGroup, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAttackBonusVsAlign");
        pushInteger(nBonus);
        pushInteger(nIPAlignGroup);
        callFunction(628, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property attack bonus vs. racial group.  You must specify the
     * racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
     * must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyAttackBonusVsRace(int nIPRacialType, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAttackBonusVsRace");
        pushInteger(nBonus);
        pushInteger(nIPRacialType);
        callFunction(629, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property attack bonus vs. a specific alignment.  You must specify
     * the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
     * attack bonus.  The bonus must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyAttackBonusVsSAlign(int nAlignment, int nBonus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAttackBonusVsSAlign");
        pushInteger(nBonus);
        pushInteger(nAlignment);
        callFunction(630, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property attack penalty.  You must specify the attack penalty.
     * The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
     */
    public static synchronized NWItemProperty itemPropertyAttackPenalty(int nPenalty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAttackPenalty");
        pushInteger(nPenalty);
        callFunction(631, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property unlimited ammo.  If you leave the parameter field blank
     * it will be just a normal bolt, arrow, or bullet.  However you may specify that
     * you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
     * bonus).  For this parmeter you use the constants beginning with:
     * (IP_CONST_UNLIMITEDAMMO_*).
     */
    public static synchronized NWItemProperty itemPropertyUnlimitedAmmo(int nAmmoDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyUnlimitedAmmo");
        pushInteger(nAmmoDamage);
        callFunction(632, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property limit use by alignment group.  You must specify the
     * alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
     */
    public static synchronized NWItemProperty itemPropertyLimitUseByAlign(int nIPAlignGroup) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyLimitUseByAlign");
        pushInteger(nIPAlignGroup);
        callFunction(633, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property limit use by class.  You must specify the class(es) who
     * are able to use this item(IP_CONST_CLASS_*).
     */
    public static synchronized NWItemProperty itemPropertyLimitUseByClass(int nClass) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyLimitUseByClass");
        pushInteger(nClass);
        callFunction(634, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property limit use by race.  You must specify the race(s) who are
     * allowed to use this item(IP_CONST_RACIALTYPE_*).
     */
    public static synchronized NWItemProperty itemPropertyLimitUseByRace(int nIPRacialType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyLimitUseByRace");
        pushInteger(nIPRacialType);
        callFunction(635, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property limit use by specific alignment.  You must specify the
     * alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
     */
    public static synchronized NWItemProperty itemPropertyLimitUseBySAlign(int nAlignment) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyLimitUseBySAlign");
        pushInteger(nAlignment);
        callFunction(636, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property vampiric regeneration.  You must specify the amount of
     * regeneration.  The regen amount must be an integer between 1 and 20.
     */
    public static synchronized NWItemProperty itemPropertyVampiricRegeneration(int nRegenAmount) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyVampiricRegeneration");
        pushInteger(nRegenAmount);
        callFunction(638, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Trap.  You must specify the trap level constant
     * (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
     */
    public static synchronized NWItemProperty itemPropertyTrap(int nTrapLevel, int nIPTrapType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyTrap");
        pushInteger(nIPTrapType);
        pushInteger(nTrapLevel);
        callFunction(639, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property true seeing.
     */
    public static synchronized NWItemProperty itemPropertyTrueSeeing() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyTrueSeeing");
        callFunction(640, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property Monster on hit apply effect property.  You must specify
     * the property that you want applied on hit.  There are some properties that
     * require an additional special parameter to be specified.  The others that
     * don't require any additional parameter you may just put in the one.  The
     * special cases are as follows:
     * ABILITYDRAIN:nSpecial is the ability to drain.
     * constant(IP_CONST_ABILITY_*)
     * DISEASE     :nSpecial is the disease that you want applied.
     * constant(DISEASE_*)
     * LEVELDRAIN  :nSpecial is the number of levels that you want drained.
     * integer between 1 and 5.
     * POISON      :nSpecial is the type of poison that will effect the victim.
     * constant(IP_CONST_POISON_*)
     * WOUNDING    :nSpecial is the amount of wounding.
     * integer between 1 and 5.
     * NOTE: Any that do not appear in the above list do not require the second
     * parameter.
     * NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
     * gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
     */
    public static synchronized NWItemProperty itemPropertyOnMonsterHitProperties(int nProperty, int nSpecial) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyOnMonsterHitProperties");
        pushInteger(nSpecial);
        pushInteger(nProperty);
        callFunction(641, 2);
        return popItemProperty();
    }

    /**
     * Returns Item property turn resistance.  You must specify the resistance bonus.
     * The bonus must be an integer between 1 and 50.
     */
    public static synchronized NWItemProperty itemPropertyTurnResistance(int nModifier) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyTurnResistance");
        pushInteger(nModifier);
        callFunction(642, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Massive Critical.  You must specify the extra damage
     * constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
     */
    public static synchronized NWItemProperty itemPropertyMassiveCritical(int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyMassiveCritical");
        pushInteger(nDamage);
        callFunction(643, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property free action.
     */
    public static synchronized NWItemProperty itemPropertyFreeAction() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyFreeAction");
        callFunction(644, 0);
        return popItemProperty();
    }

    /**
     * Returns Item property monster damage.  You must specify the amount of damage
     * the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
     * NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
     * gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
     */
    public static synchronized NWItemProperty itemPropertyMonsterDamage(int nDamage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyMonsterDamage");
        pushInteger(nDamage);
        callFunction(645, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property immunity to spell level.  You must specify the level of
     * which that and below the user will be immune.  The level must be an integer
     * between 1 and 9.  By putting in a 3 it will mean the user is immune to all
     * 3rd level and lower spells.
     */
    public static synchronized NWItemProperty itemPropertyImmunityToSpellLevel(int nLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyImmunityToSpellLevel");
        pushInteger(nLevel);
        callFunction(646, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property special walk.  If no parameters are specified it will
     * automatically use the zombie walk.  This will apply the special walk animation
     * to the user.
     */
    public static synchronized NWItemProperty itemPropertySpecialWalk(int nWalkType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertySpecialWalk");
        pushInteger(nWalkType);
        callFunction(647, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property healers kit.  You must specify the level of the kit.
     * The modifier must be an integer between 1 and 12.
     */
    public static synchronized NWItemProperty itemPropertyHealersKit(int nModifier) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyHealersKit");
        pushInteger(nModifier);
        callFunction(648, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property weight increase.  You must specify the weight increase
     * constant(IP_CONST_WEIGHTINCREASE_*).
     */
    public static synchronized NWItemProperty itemPropertyWeightIncrease(int nWeight) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyWeightIncrease");
        pushInteger(nWeight);
        callFunction(649, 1);
        return popItemProperty();
    }

    /**
     * ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************
     *
     * Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
     * @param oTarget the creature using the skill
     * @param nSkill the skill being used
     * @param nDifficulty Difficulty class of skill
     */
    public static synchronized boolean getIsSkillSuccessful(NWObject oTarget, int nSkill, int nDifficulty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsSkillSuccessful");
        pushInteger(nDifficulty);
        pushInteger(nSkill);
        pushObject(oTarget);
        callFunction(650, 3);
        return popInteger() > 0;
    }

    /**
     * Creates an effect that inhibits spells
     * @param nPercent - percentage of failure
     * @param nSpellSchool - the school of spells affected.
     */
    public static synchronized NWEffect effectSpellFailure(int nPercent, int nSpellSchool) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectSpellFailure");
        pushInteger(nSpellSchool);
        pushInteger(nPercent);
        callFunction(651, 2);
        return popEffect();
    }

    /**
     * Causes the object to instantly speak a translated string.
     * (not an action, not blocked when uncommandable)
     * @param nStrRef Reference of the string in the talk table
     * @param nTalkVolume TALKVOLUME_*
     */
    public static synchronized void speakStringByStrRef(int nStrRef, int nTalkVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling speakStringByStrRef");
        pushInteger(nTalkVolume);
        pushInteger(nStrRef);
        callFunction(652, 2);
    }

    /**
     * Sets the given creature into cutscene mode.  This prevents the player from
     * using the GUI and camera controls.
     * @param oCreature creature in a cutscene
     * @param bInCutscene TRUE to move them into cutscene, FALSE to remove cutscene mode
     * @param bLeftClickingEnabled TRUE to allow the user to interact with the game world using the left mouse button only.
     * FALSE to stop the user from interacting with the game world.
     * Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
     * SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
     * was when SetCutsceneMode(oPlayer, TRUE) was called.
     */
    public static synchronized void setCutsceneMode(NWObject oCreature, boolean bInCutscene, boolean bLeftClickingEnabled) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCutsceneMode");
        pushInteger(bLeftClickingEnabled ? 1 : 0);
        pushInteger(bInCutscene ? 1 : 0);
        pushObject(oCreature);
        callFunction(653, 3);
    }

    /**
     * Gets the last player character to cancel from a cutscene.
     */
    public static synchronized NWObject getLastPCToCancelCutscene() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastPCToCancelCutscene");
        callFunction(654, 0);
        return popObject();
    }

    /**
     * Gets the length of the specified wavefile, in seconds
     * Only works for sounds used for dialog.
     */
    public static synchronized float getDialogSoundLength(int nStrRef) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDialogSoundLength");
        pushInteger(nStrRef);
        callFunction(655, 1);
        return popFloat();
    }

    /**
     * Fades the screen for the given creature/player from black to regular screen
     * @param oCreature creature controlled by player that should fade from black
     */
    public static synchronized void fadeFromBlack(NWObject oCreature, float fSpeed) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling fadeFromBlack");
        pushFloat(fSpeed);
        pushObject(oCreature);
        callFunction(656, 2);
    }

    /**
     * Fades the screen for the given creature/player from regular screen to black
     * @param oCreature creature controlled by player that should fade to black
     */
    public static synchronized void fadeToBlack(NWObject oCreature, float fSpeed) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling fadeToBlack");
        pushFloat(fSpeed);
        pushObject(oCreature);
        callFunction(657, 2);
    }

    /**
     * Removes any fading or black screen.
     * @param oCreature creature controlled by player that should be cleared
     */
    public static synchronized void stopFade(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling stopFade");
        pushObject(oCreature);
        callFunction(658, 1);
    }

    /**
     * Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
     * Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
     * @param oCreature creature controlled by player that should see black screen
     */
    public static synchronized void blackScreen(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling blackScreen");
        pushObject(oCreature);
        callFunction(659, 1);
    }

    /**
     * Returns the base attach bonus for the given creature.
     */
    public static synchronized int getBaseAttackBonus(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getBaseAttackBonus");
        pushObject(oCreature);
        callFunction(660, 1);
        return popInteger();
    }

    /**
     * Set a creature's immortality flag.
     * -oCreature: creature affected
     * -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
     * FALSE = creature is not immortal and is damaged normally.
     * This scripting command only works on Creature objects.
     */
    public static synchronized void setImmortal(NWObject oCreature, boolean bImmortal) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setImmortal");
        pushInteger(bImmortal ? 1 : 0);
        pushObject(oCreature);
        callFunction(661, 2);
    }

    /**
     * Open's this creature's inventory panel for this player
     * @param oCreature creature to view
     * @param oPlayer the owner of this creature will see the panel pop up
     * * DM's can view any creature's inventory
     * * Players can view their own inventory, or that of their henchman, familiar or animal companion
     */
    public static synchronized void openInventory(NWObject oCreature, NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling openInventory");
        pushObject(oPlayer);
        pushObject(oCreature);
        callFunction(662, 2);
    }

    /**
     * Stores the current camera mode and position so that it can be restored (using
     * RestoreCameraFacing())
     */
    public static synchronized void storeCameraFacing() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling storeCameraFacing");
        callFunction(663, 0);
    }

    /**
     * Restores the camera mode and position to what they were last time StoreCameraFacing
     * was called.  RestoreCameraFacing can only be called once, and must correspond to a
     * previous call to StoreCameraFacing.
     */
    public static synchronized void restoreCameraFacing() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling restoreCameraFacing");
        callFunction(664, 0);
    }

    /**
     * Levels up a creature using default settings.
     * If successfull it returns the level the creature now is, or 0 if it fails.
     * If you want to give them a different level (ie: Give a Fighter a level of Wizard)
     * you can specify that in the nClass.
     * However, if you specify a class to which the creature no package specified,
     * they will use the default package for that class for their levelup choices.
     * (ie: no Barbarian Savage/Wizard Divination combinations)
     * If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
     * if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
     */
    public static synchronized int levelUpHenchman(NWObject oCreature, int nClass, boolean bReadyAllSpells, int nPackage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling levelUpHenchman");
        pushInteger(nPackage);
        pushInteger(bReadyAllSpells ? 1 : 0);
        pushInteger(nClass);
        pushObject(oCreature);
        callFunction(665, 4);
        return popInteger();
    }

    /**
     * Sets the droppable flag on an item
     * @param oItem the item to change
     * @param bDroppable TRUE or FALSE, whether the item should be droppable
     * Droppable items will appear on a creature's remains when the creature is killed.
     */
    public static synchronized void setDroppableFlag(NWObject oItem, boolean bDroppable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setDroppableFlag");
        pushInteger(bDroppable ? 1 : 0);
        pushObject(oItem);
        callFunction(666, 2);
    }

    /**
     * Gets the weight of an item, or the total carried weight of a creature in tenths
     * of pounds (as per the baseitems.2da).
     * @param oTarget the item or creature for which the weight is needed
     */
    public static synchronized int getWeight(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getWeight");
        pushObject(oTarget);
        callFunction(667, 1);
        return popInteger();
    }

    /**
     * Gets the object that acquired the module item.  May be a creature, item, or placeable
     */
    public static synchronized NWObject getModuleItemAcquiredBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleItemAcquiredBy");
        callFunction(668, 0);
        return popObject();
    }

    /**
     * Get the immortal flag on a creature
     */
    public static synchronized boolean getImmortal(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getImmortal");
        pushObject(oTarget);
        callFunction(669, 1);
        return popInteger() > 0;
    }

    /**
     * Does a single attack on every hostile creature within 10ft. of the attacker
     * and determines damage accordingly.  If the attacker has a ranged weapon
     * equipped, this will have no effect.
     * ** NOTE ** This is meant to be called inside the spell script for whirlwind
     * attack, it is not meant to be used to queue up a new whirlwind attack.  To do
     * that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
     * @param int bDisplayFeedback TRUE or FALSE, whether or not feedback should be
     * displayed
     * @param int bImproved If TRUE, the improved version of whirlwind is used
     */
    public static synchronized void doWhirlwindAttack(boolean bDisplayFeedback, boolean bImproved) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling doWhirlwindAttack");
        pushInteger(bImproved ? 1 : 0);
        pushInteger(bDisplayFeedback ? 1 : 0);
        callFunction(670, 2);
    }

    /**
     * Gets a value from a 2DA file on the server and returns it as a string
     * avoid using this function in loops
     * @param s2DA the name of the 2da file, 16 chars max
     * @param sColumn the name of the column in the 2da
     * @param nRow the row in the 2da
     * * returns an empty string if file, row, or column not found
     */
    public static synchronized String get2DAString(String s2DA, String sColumn, int nRow) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling get2DAString");
        pushInteger(nRow);
        pushString(sColumn);
        pushString(s2DA);
        callFunction(671, 3);
        return popString();
    }

    /**
     * Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
     * except that the observers get no saving throw
     */
    public static synchronized NWEffect effectEthereal() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectEthereal");
        callFunction(672, 0);
        return popEffect();
    }

    /**
     * Gets the current AI Level that the creature is running at.
     * Returns one of the following:
     * AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
     */
    public static synchronized int getAILevel(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAILevel");
        pushObject(oTarget);
        callFunction(673, 1);
        return popInteger();
    }

    /**
     * Sets the current AI Level of the creature to the value specified. Does not work on Players.
     * The game by default will choose an appropriate AI level for
     * creatures based on the circumstances that the creature is in.
     * Explicitly setting an AI level will over ride the game AI settings.
     * The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
     * AI_LEVEL_DEFAULT  @param Default setting. The game will take over seting the appropriate AI level when required.
     * AI_LEVEL_VERY_LOW @param Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
     * AI_LEVEL_LOW      @param Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
     * AI_LEVEL_NORMAL   @param Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
     * AI_LEVEL_HIGH     @param High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
     */
    public static synchronized void setAILevel(NWObject oTarget, int nAILevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setAILevel");
        pushInteger(nAILevel);
        pushObject(oTarget);
        callFunction(674, 2);
    }

    /**
     * This will return TRUE if the creature running the script is a familiar currently
     * possessed by his master.
     * returns FALSE if not or if the creature object is invalid
     */
    public static synchronized boolean getIsPossessedFamiliar(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsPossessedFamiliar");
        pushObject(oCreature);
        callFunction(675, 1);
        return popInteger() > 0;
    }

    /**
     * This will cause a Player Creature to unpossess his/her familiar.  It will work if run
     * on the player creature or the possessed familiar.  It does not work in conjunction with
     * any DM possession.
     */
    public static synchronized void unpossessFamiliar(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling unpossessFamiliar");
        pushObject(oCreature);
        callFunction(676, 1);
    }

    /**
     * This will return TRUE if the area is flagged as either interior or underground.
     */
    public static synchronized boolean getIsAreaInterior(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsAreaInterior");
        pushObject(oArea);
        callFunction(677, 1);
        return popInteger() > 0;
    }

    /**
     * Send a server message (szMessage) to the oPlayer.
     */
    public static synchronized void sendMessageToPCByStrRef(NWObject oPlayer, int nStrRef) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling sendMessageToPCByStrRef");
        pushInteger(nStrRef);
        pushObject(oPlayer);
        callFunction(678, 2);
    }

    /**
     * Increment the remaining uses per day for this creature by one.
     * Total number of feats per day can not exceed the maximum.
     * @param oCreature creature to modify
     * @param nFeat constant FEAT_*
     */
    public static synchronized void incrementRemainingFeatUses(NWObject oCreature, int nFeat) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling incrementRemainingFeatUses");
        pushInteger(nFeat);
        pushObject(oCreature);
        callFunction(679, 2);
    }

    /**
     * Force the character of the player specified to be exported to its respective directory
     * i.e. LocalVault/ServerVault/ etc.
     */
    public static synchronized void exportSingleCharacter(NWObject oPlayer) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling exportSingleCharacter");
        pushObject(oPlayer);
        callFunction(680, 1);
    }

    /**
     * This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
     * if nRunAsAction is off then the sound is forced to play intantly.
     */
    public static synchronized void playSoundByStrRef(int nStrRef, int nRunAsAction) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling playSoundByStrRef");
        pushInteger(nRunAsAction);
        pushInteger(nStrRef);
        callFunction(681, 2);
    }

    /**
     * Set the name of oCreature's sub race to sSubRace.
     */
    public static synchronized void setSubRace(NWObject oCreature, String sSubRace) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setSubRace");
        pushString(sSubRace);
        pushObject(oCreature);
        callFunction(682, 2);
    }

    /**
     * Set the name of oCreature's Deity to sDeity.
     */
    public static synchronized void setDeity(NWObject oCreature, String sDeity) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setDeity");
        pushString(sDeity);
        pushObject(oCreature);
        callFunction(683, 2);
    }

    /**
     * Returns TRUE if the creature oCreature is currently possessed by a DM character.
     * Returns FALSE otherwise.
     * Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
     * To determine if oCreature is a DM character use GetIsDM()
     */
    public static synchronized boolean getIsDMPossessed(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsDMPossessed");
        pushObject(oCreature);
        callFunction(684, 1);
        return popInteger() > 0;
    }

    /**
     * Gets the current weather conditions for the area oArea.
     * Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
     * Note: If called on an Interior area, this will always return WEATHER_CLEAR.
     */
    public static synchronized int getWeather(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getWeather");
        pushObject(oArea);
        callFunction(685, 1);
        return popInteger();
    }

    /**
     * Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
     * Returns AREA_INVALID, on an error.
     */
    public static synchronized boolean getIsAreaNatural(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsAreaNatural");
        pushObject(oArea);
        callFunction(686, 1);
        return popInteger() > 0;
    }

    /**
     * Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
     * Returns AREA_INVALID, on an error.
     */
    public static synchronized boolean getIsAreaAboveGround(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsAreaAboveGround");
        pushObject(oArea);
        callFunction(687, 1);
        return popInteger() > 0;
    }

    /**
     * Use this to get the item last equipped by a player character in OnPlayerEquipItem..
     */
    public static synchronized NWObject getPCItemLastEquipped() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCItemLastEquipped");
        callFunction(688, 0);
        return popObject();
    }

    /**
     * Use this to get the player character who last equipped an item in OnPlayerEquipItem..
     */
    public static synchronized NWObject getPCItemLastEquippedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCItemLastEquippedBy");
        callFunction(689, 0);
        return popObject();
    }

    /**
     * Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
     */
    public static synchronized NWObject getPCItemLastUnequipped() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCItemLastUnequipped");
        callFunction(690, 0);
        return popObject();
    }

    /**
     * Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
     */
    public static synchronized NWObject getPCItemLastUnequippedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCItemLastUnequippedBy");
        callFunction(691, 0);
        return popObject();
    }

    /**
     * Creates a new copy of an item, while making a single change to the appearance of the item.
     * Helmet models and simple items ignore iIndex.
     * iType                            iIndex                              iNewValue
     * ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
     * ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            1-4
     * ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
     * ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
     * ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-175 [1]
     *
     * [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
     * desired, the following equation can be used for nIndex to achieve that:
     *
     * ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
     *
     * For example, to change the CLOTH1 channel of the torso, nIndex would be:
     *
     * 6 + (7 * 6) + 2 = 50
     *
     * [1] When specifying per-part coloring, the value 255 is allowed and corresponds with the logical
     * function 'clear colour override', which clears the per-part override for that part.
     */
    public static synchronized NWObject copyItemAndModify(NWObject oItem, int nType, int nIndex, int nNewValue, boolean bCopyVars) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling copyItemAndModify");
        pushInteger(bCopyVars ? 1 : 0);
        pushInteger(nNewValue);
        pushInteger(nIndex);
        pushInteger(nType);
        pushObject(oItem);
        callFunction(692, 5);
        return popObject();
    }

    /**
     * Queries the current value of the appearance settings on an item. The parameters are
     * identical to those of CopyItemAndModify().
     */
    public static synchronized int getItemAppearance(NWObject oItem, int nType, int nIndex) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemAppearance");
        pushInteger(nIndex);
        pushInteger(nType);
        pushObject(oItem);
        callFunction(693, 3);
        return popInteger();
    }

    /**
     * Creates an item property that (when applied to a weapon item) causes a spell to be cast
     * when a successful strike is made, or (when applied to armor) is struck by an opponent.
     * @param nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
     */
    public static synchronized NWItemProperty itemPropertyOnHitCastSpell(int nSpell, int nLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyOnHitCastSpell");
        pushInteger(nLevel);
        pushInteger(nSpell);
        callFunction(694, 2);
        return popItemProperty();
    }

    /**
     * Returns the SubType number of the item property. See the 2DA files for value definitions.
     */
    public static synchronized int getItemPropertySubType(NWItemProperty iProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertySubType");
        pushItemProperty(iProperty);
        callFunction(695, 1);
        return popInteger();
    }

    /**
     * Gets the status of ACTION_MODE_* modes on a creature.
     */
    public static synchronized boolean getActionMode(NWObject oCreature, int nActionMode) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getActionMode");
        pushInteger(nActionMode);
        pushObject(oCreature);
        callFunction(696, 2);
        return popInteger() > 0;
    }

    /**
     * Sets the status of modes ACTION_MODE_* on a creature.
     */
    public static synchronized void setActionMode(NWObject oCreature, int nActionMode, boolean bStatus) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setActionMode");
        pushInteger(bStatus ? 1 : 0);
        pushInteger(nActionMode);
        pushObject(oCreature);
        callFunction(697, 3);
    }

    /**
     * Returns the current arcane spell failure factor of a creature
     */
    public static synchronized int getArcaneSpellFailure(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getArcaneSpellFailure");
        pushObject(oCreature);
        callFunction(698, 1);
        return popInteger();
    }

    /**
     * Makes a player examine the object oExamine. This causes the examination
     * pop-up box to appear for the object specified.
     */
    public static synchronized void actionExamine(NWObject oExamine) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling actionExamine");
        pushObject(oExamine);
        callFunction(699, 1);
    }

    /**
     * Creates a visual effect (ITEM_VISUAL_*) that may be applied to
     * melee weapons only.
     */
    public static synchronized NWItemProperty itemPropertyVisualEffect(int nEffect) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyVisualEffect");
        pushInteger(nEffect);
        callFunction(700, 1);
        return popItemProperty();
    }

    /**
     * Sets the lootable state of a *living* NPC creature.
     * This function will *not* work on players or dead creatures.
     */
    public static synchronized void setLootable(NWObject oCreature, boolean bLootable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLootable");
        pushInteger(bLootable ? 1 : 0);
        pushObject(oCreature);
        callFunction(701, 2);
    }

    /**
     * Returns the lootable state of a creature.
     */
    public static synchronized boolean getLootable(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLootable");
        pushObject(oCreature);
        callFunction(702, 1);
        return popInteger() > 0;
    }

    /**
     * Returns the current movement rate factor
     * of the cutscene 'camera man'.
     * NOTE: This will be a value between 0.1, 2.0 (10%-200%)
     */
    public static synchronized float getCutsceneCameraMoveRate(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCutsceneCameraMoveRate");
        pushObject(oCreature);
        callFunction(703, 1);
        return popFloat();
    }

    /**
     * Sets the current movement rate factor for the cutscene
     * camera man.
     * NOTE: You can only set values between 0.1, 2.0 (10%-200%)
     */
    public static synchronized void setCutsceneCameraMoveRate(NWObject oCreature, float fRate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCutsceneCameraMoveRate");
        pushFloat(fRate);
        pushObject(oCreature);
        callFunction(704, 2);
    }

    /**
     * Returns TRUE if the item is cursed and cannot be dropped
     */
    public static synchronized boolean getItemCursedFlag(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemCursedFlag");
        pushObject(oItem);
        callFunction(705, 1);
        return popInteger() > 0;
    }

    /**
     * When cursed, items cannot be dropped
     */
    public static synchronized void setItemCursedFlag(NWObject oItem, boolean bCursed) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setItemCursedFlag");
        pushInteger(bCursed ? 1 : 0);
        pushObject(oItem);
        callFunction(706, 2);
    }

    /**
     * Sets the maximum number of henchmen
     */
    public static synchronized void setMaxHenchmen(int nNumHenchmen) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setMaxHenchmen");
        pushInteger(nNumHenchmen);
        callFunction(707, 1);
    }

    /**
     * Gets the maximum number of henchmen
     */
    public static synchronized int getMaxHenchmen() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getMaxHenchmen");
        callFunction(708, 0);
        return popInteger();
    }

    /**
     * Returns the associate type of the specified creature.
     * @param Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
     */
    public static synchronized int getAssociateType(NWObject oAssociate) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAssociateType");
        pushObject(oAssociate);
        callFunction(709, 1);
        return popInteger();
    }

    /**
     * Returns the spell resistance of the specified creature.
     * @param Returns 0 if the creature has no spell resistance or an invalid
     * creature is passed in.
     */
    public static synchronized int getSpellResistance(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSpellResistance");
        pushObject(oCreature);
        callFunction(710, 1);
        return popInteger();
    }

    /**
     * Changes the current Day/Night cycle for this player to night
     * @param oPlayer which player to change the lighting for
     * @param fTransitionTime how long the transition should take
     */
    public static synchronized void dayToNight(NWObject oPlayer, float fTransitionTime) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling dayToNight");
        pushFloat(fTransitionTime);
        pushObject(oPlayer);
        callFunction(711, 2);
    }

    /**
     * Changes the current Day/Night cycle for this player to daylight
     * @param oPlayer which player to change the lighting for
     * @param fTransitionTime how long the transition should take
     */
    public static synchronized void nightToDay(NWObject oPlayer, float fTransitionTime) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling nightToDay");
        pushFloat(fTransitionTime);
        pushObject(oPlayer);
        callFunction(712, 2);
    }

    /**
     * Returns whether or not there is a direct line of sight
     * between the two objects. (Not blocked by any geometry).
     *
     * PLEASE NOTE: This is an expensive function and may
     * degrade performance if used frequently.
     */
    public static synchronized int lineOfSightObject(NWObject oSource, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling lineOfSightObject");
        pushObject(oTarget);
        pushObject(oSource);
        callFunction(713, 2);
        return popInteger();
    }

    /**
     * Returns whether or not there is a direct line of sight
     * between the two vectors. (Not blocked by any geometry).
     *
     * This function must be run on a valid object in the area
     * it will not work on the module or area.
     *
     * PLEASE NOTE: This is an expensive function and may
     * degrade performance if used frequently.
     */
    public static synchronized int lineOfSightVector(NWVector vSource, NWVector vTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling lineOfSightVector");
        pushVector(vTarget);
        pushVector(vSource);
        callFunction(714, 2);
        return popInteger();
    }

    /**
     * Returns the class that the spellcaster cast the
     * spell as.
     * @param Returns CLASS_TYPE_INVALID if the caster has
     * no valid class (placeables, etc...)
     */
    public static synchronized int getLastSpellCastClass() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getLastSpellCastClass");
        callFunction(715, 0);
        return popInteger();
    }

    /**
     * Sets the number of base attacks for the specified
     * creatures. The range of values accepted are from
     * 1 to 6
     * Note: This function does not work on Player Characters
     */
    public static synchronized void setBaseAttackBonus(int nBaseAttackBonus, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setBaseAttackBonus");
        pushObject(oCreature);
        pushInteger(nBaseAttackBonus);
        callFunction(716, 2);
    }

    /**
     * Restores the number of base attacks back to it's
     * original state.
     */
    public static synchronized void restoreBaseAttackBonus(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling restoreBaseAttackBonus");
        pushObject(oCreature);
        callFunction(717, 1);
    }

    /**
     * Creates a cutscene ghost effect, this will allow creatures
     * to pathfind through other creatures without bumping into them
     * for the duration of the effect.
     */
    public static synchronized NWEffect effectCutsceneGhost() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCutsceneGhost");
        callFunction(718, 0);
        return popEffect();
    }

    /**
     * Creates an item property that offsets the effect on arcane spell failure
     * that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
     */
    public static synchronized NWItemProperty itemPropertyArcaneSpellFailure(int nModLevel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyArcaneSpellFailure");
        pushInteger(nModLevel);
        callFunction(719, 1);
        return popItemProperty();
    }

    /**
     * Returns the amount of gold a store currently has. -1 indicates it is not using gold.
     * -2 indicates the store could not be located.
     */
    public static synchronized int getStoreGold(NWObject oidStore) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStoreGold");
        pushObject(oidStore);
        callFunction(720, 1);
        return popInteger();
    }

    /**
     * Sets the amount of gold a store has. -1 means the store does not use gold.
     */
    public static synchronized void setStoreGold(NWObject oidStore, int nGold) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setStoreGold");
        pushInteger(nGold);
        pushObject(oidStore);
        callFunction(721, 2);
    }

    /**
     * Gets the maximum amount a store will pay for any item. -1 means price unlimited.
     * -2 indicates the store could not be located.
     */
    public static synchronized int getStoreMaxBuyPrice(NWObject oidStore) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStoreMaxBuyPrice");
        pushObject(oidStore);
        callFunction(722, 1);
        return popInteger();
    }

    /**
     * Sets the maximum amount a store will pay for any item. -1 means price unlimited.
     */
    public static synchronized void setStoreMaxBuyPrice(NWObject oidStore, int nMaxBuy) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setStoreMaxBuyPrice");
        pushInteger(nMaxBuy);
        pushObject(oidStore);
        callFunction(723, 2);
    }

    /**
     * Gets the amount a store charges for identifying an item. Default is 100. -1 means
     * the store will not identify items.
     * -2 indicates the store could not be located.
     */
    public static synchronized int getStoreIdentifyCost(NWObject oidStore) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getStoreIdentifyCost");
        pushObject(oidStore);
        callFunction(724, 1);
        return popInteger();
    }

    /**
     * Sets the amount a store charges for identifying an item. Default is 100. -1 means
     * the store will not identify items.
     */
    public static synchronized void setStoreIdentifyCost(NWObject oidStore, int nCost) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setStoreIdentifyCost");
        pushInteger(nCost);
        pushObject(oidStore);
        callFunction(725, 2);
    }

    /**
     * Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
     */
    public static synchronized void setCreatureAppearanceType(NWObject oCreature, int nAppearanceType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCreatureAppearanceType");
        pushInteger(nAppearanceType);
        pushObject(oCreature);
        callFunction(726, 2);
    }

    /**
     * Returns the default package selected for this creature to level up with
     * @param returns PACKAGE_INVALID if error occurs
     */
    public static synchronized int getCreatureStartingPackage(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCreatureStartingPackage");
        pushObject(oCreature);
        callFunction(727, 1);
        return popInteger();
    }

    /**
     * Returns an effect that when applied will paralyze the target's legs, rendering
     * them unable to walk but otherwise unpenalized. This effect cannot be resisted.
     */
    public static synchronized NWEffect effectCutsceneImmobilize() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling effectCutsceneImmobilize");
        callFunction(728, 0);
        return popEffect();
    }

    /**
     * Is this creature in the given subarea? (trigger, area of effect object, etc..)
     * This function will tell you if the creature has triggered an onEnter event,
     * not if it is physically within the space of the subarea
     */
    public static synchronized boolean getIsInSubArea(NWObject oCreature, NWObject oSubArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsInSubArea");
        pushObject(oSubArea);
        pushObject(oCreature);
        callFunction(729, 2);
        return popInteger() > 0;
    }

    /**
     * Returns the Cost Table number of the item property. See the 2DA files for value definitions.
     */
    public static synchronized int getItemPropertyCostTable(NWItemProperty iProp) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyCostTable");
        pushItemProperty(iProp);
        callFunction(730, 1);
        return popInteger();
    }

    /**
     * Returns the Cost Table value (index of the cost table) of the item property.
     * See the 2DA files for value definitions.
     */
    public static synchronized int getItemPropertyCostTableValue(NWItemProperty iProp) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyCostTableValue");
        pushItemProperty(iProp);
        callFunction(731, 1);
        return popInteger();
    }

    /**
     * Returns the Param1 number of the item property. See the 2DA files for value definitions.
     */
    public static synchronized int getItemPropertyParam1(NWItemProperty iProp) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyParam1");
        pushItemProperty(iProp);
        callFunction(732, 1);
        return popInteger();
    }

    /**
     * Returns the Param1 value of the item property. See the 2DA files for value definitions.
     */
    public static synchronized int getItemPropertyParam1Value(NWItemProperty iProp) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyParam1Value");
        pushItemProperty(iProp);
        callFunction(733, 1);
        return popInteger();
    }

    /**
     * Is this creature able to be disarmed? (checks disarm flag on creature, and if
     * the creature actually has a weapon equipped in their right hand that is droppable)
     */
    public static synchronized boolean getIsCreatureDisarmable(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getIsCreatureDisarmable");
        pushObject(oCreature);
        callFunction(734, 1);
        return popInteger() > 0;
    }

    /**
     * Sets whether this item is 'stolen' or not
     */
    public static synchronized void setStolenFlag(NWObject oItem, boolean bStolenFlag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setStolenFlag");
        pushInteger(bStolenFlag ? 1 : 0);
        pushObject(oItem);
        callFunction(735, 2);
    }

    /**
     * Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
     */
    public static synchronized void forceRest(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling forceRest");
        pushObject(oCreature);
        callFunction(736, 1);
    }

    /**
     * Forces this player's camera to be set to this height. Setting this value to zero will
     * restore the camera to the racial default height.
     */
    public static synchronized void setCameraHeight(NWObject oPlayer, float fHeight) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCameraHeight");
        pushFloat(fHeight);
        pushObject(oPlayer);
        callFunction(737, 2);
    }

    /**
     * Changes the sky that is displayed in the specified area.
     * nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized void setSkyBox(int nSkyBox, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setSkyBox");
        pushObject(oArea);
        pushInteger(nSkyBox);
        callFunction(738, 2);
    }

    /**
     * Returns the creature's currently set PhenoType (body type).
     */
    public static synchronized int getPhenoType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPhenoType");
        pushObject(oCreature);
        callFunction(739, 1);
        return popInteger();
    }

    /**
     * Sets the creature's PhenoType (body type) to the type specified.
     * nPhenoType = PHENOTYPE_NORMAL
     * nPhenoType = PHENOTYPE_BIG
     * nPhenoType = PHENOTYPE_CUSTOM* @param The custom PhenoTypes should only ever
     * be used if you have specifically created your own custom content that
     * requires the use of a new PhenoType and you have specified the appropriate
     * custom PhenoType in your custom content.
     * SetPhenoType will only work on part based creature (i.e. the starting
     * default playable races).
     */
    public static synchronized void setPhenoType(int nPhenoType, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPhenoType");
        pushObject(oCreature);
        pushInteger(nPhenoType);
        callFunction(740, 2);
    }

    /**
     * Sets the fog color in the area specified.
     * nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
     * nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
     * The fog color can also be represented as a hex RGB number if specific color shades
     * are desired.
     * The format of a hex specified color would be 0xFFEEDD where
     * FF would represent the amount of red in the color
     * EE would represent the amount of green in the color
     * DD would represent the amount of blue in the color.
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized void setFogColor(int nFogType, int nFogColor, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFogColor");
        pushObject(oArea);
        pushInteger(nFogColor);
        pushInteger(nFogType);
        callFunction(741, 3);
    }

    /**
     * Gets the current cutscene state of the player specified by oCreature.
     * Returns TRUE if the player is in cutscene mode.
     * Returns FALSE if the player is not in cutscene mode, or on an error
     * (such as specifying a non creature object).
     */
    public static synchronized boolean getCutsceneMode(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCutsceneMode");
        pushObject(oCreature);
        callFunction(742, 1);
        return popInteger() > 0;
    }

    /**
     * Gets the skybox that is currently displayed in the specified area.
     * Returns:
     * SKYBOX_* constant
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized int getSkyBox(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getSkyBox");
        pushObject(oArea);
        callFunction(743, 1);
        return popInteger();
    }

    /**
     * Gets the fog color in the area specified.
     * nFogType specifies wether the Sun, or Moon fog type is returned.
     * Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized int getFogColor(int nFogType, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFogColor");
        pushObject(oArea);
        pushInteger(nFogType);
        callFunction(744, 2);
        return popInteger();
    }

    /**
     * Sets the fog amount in the area specified.
     * nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
     * nFogAmount = specifies the density that the fog is being set to.
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized void setFogAmount(int nFogType, int nFogAmount, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFogAmount");
        pushObject(oArea);
        pushInteger(nFogAmount);
        pushInteger(nFogType);
        callFunction(745, 3);
    }

    /**
     * Gets the fog amount in the area specified.
     * nFogType = nFogType specifies wether the Sun, or Moon fog type is returned.
     * Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
     * If no valid area (or object) is specified, it uses the area of caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized int getFogAmount(int nFogType, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFogAmount");
        pushObject(oArea);
        pushInteger(nFogType);
        callFunction(746, 2);
        return popInteger();
    }

    /**
     * returns TRUE if the item CAN be pickpocketed
     */
    public static synchronized boolean getPickpocketableFlag(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPickpocketableFlag");
        pushObject(oItem);
        callFunction(747, 1);
        return popInteger() > 0;
    }

    /**
     * Sets the Pickpocketable flag on an item
     * @param oItem the item to change
     * @param bPickpocketable TRUE or FALSE, whether the item can be pickpocketed.
     */
    public static synchronized void setPickpocketableFlag(NWObject oItem, boolean bPickpocketable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPickpocketableFlag");
        pushInteger(bPickpocketable ? 1 : 0);
        pushObject(oItem);
        callFunction(748, 2);
    }

    /**
     * returns the footstep type of the creature specified.
     * The footstep type determines what the creature's footsteps sound
     * like when ever they take a step.
     * returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
     * used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
     */
    public static synchronized int getFootstepType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFootstepType");
        pushObject(oCreature);
        callFunction(749, 1);
        return popInteger();
    }

    /**
     * Sets the footstep type of the creature specified.
     * Changing a creature's footstep type will change the sound that
     * its feet make when ever the creature makes takes a step.
     * By default a creature's footsteps are detemined by the appearance
     * type of the creature. SetFootstepType() allows you to make a
     * creature use a difference footstep type than it would use by default
     * for its given appearance.
     * @param nFootstepType (FOOTSTEP_TYPE_*):
     * FOOTSTEP_TYPE_NORMAL
     * FOOTSTEP_TYPE_LARGE
     * FOOTSTEP_TYPE_DRAGON
     * FOOTSTEP_TYPE_SoFT
     * FOOTSTEP_TYPE_HOOF
     * FOOTSTEP_TYPE_HOOF_LARGE
     * FOOTSTEP_TYPE_BEETLE
     * FOOTSTEP_TYPE_SPIDER
     * FOOTSTEP_TYPE_SKELETON
     * FOOTSTEP_TYPE_LEATHER_WING
     * FOOTSTEP_TYPE_FEATHER_WING
     * FOOTSTEP_TYPE_DEFAULT @param Makes the creature use its original default footstep sounds.
     * FOOTSTEP_TYPE_NONE
     * @param oCreature the creature to change the footstep sound for.
     */
    public static synchronized void setFootstepType(int nFootstepType, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFootstepType");
        pushObject(oCreature);
        pushInteger(nFootstepType);
        callFunction(750, 2);
    }

    /**
     * returns the Wing type of the creature specified.
     * CREATURE_WING_TYPE_NONE
     * CREATURE_WING_TYPE_DEMON
     * CREATURE_WING_TYPE_ANGEL
     * CREATURE_WING_TYPE_BAT
     * CREATURE_WING_TYPE_DRAGON
     * CREATURE_WING_TYPE_BUTTERFLY
     * CREATURE_WING_TYPE_BIRD
     * returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
     * if the creature has no wings, or if the creature can not have its
     * wing type changed in the toolset.
     */
    public static synchronized int getCreatureWingType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCreatureWingType");
        pushObject(oCreature);
        callFunction(751, 1);
        return popInteger();
    }

    /**
     * Sets the Wing type of the creature specified.
     * @param nWingType (CREATURE_WING_TYPE_*)
     * CREATURE_WING_TYPE_NONE
     * CREATURE_WING_TYPE_DEMON
     * CREATURE_WING_TYPE_ANGEL
     * CREATURE_WING_TYPE_BAT
     * CREATURE_WING_TYPE_DRAGON
     * CREATURE_WING_TYPE_BUTTERFLY
     * CREATURE_WING_TYPE_BIRD
     * @param oCreature the creature to change the wing type for.
     * Note: Only two creature model types will support wings.
     * The MODELTYPE for the part based (playable races) 'P'
     * and MODELTYPE 'W'in the appearance.2da
     */
    public static synchronized void setCreatureWingType(int nWingType, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCreatureWingType");
        pushObject(oCreature);
        pushInteger(nWingType);
        callFunction(752, 2);
    }

    /**
     * returns the model number being used for the body part and creature specified
     * The model number returned is for the body part when the creature is not wearing
     * armor (i.e. whether or not the creature is wearing armor does not affect
     * the return value).
     * Note: Only works on part based creatures, which is typically restricted to
     * the playable races (unless some new part based custom content has been
     * added to the module).
     *
     * returns CREATURE_PART_INVALID if used on a non-creature object,
     * or if the creature does not use a part based model.
     *
     * @param nPart (CREATURE_PART_*)
     * CREATURE_PART_RIGHT_FOOT
     * CREATURE_PART_LEFT_FOOT
     * CREATURE_PART_RIGHT_SHIN
     * CREATURE_PART_LEFT_SHIN
     * CREATURE_PART_RIGHT_THIGH
     * CREATURE_PART_LEFT_THIGH
     * CREATURE_PART_PELVIS
     * CREATURE_PART_TORSO
     * CREATURE_PART_BELT
     * CREATURE_PART_NECK
     * CREATURE_PART_RIGHT_FOREARM
     * CREATURE_PART_LEFT_FOREARM
     * CREATURE_PART_RIGHT_BICEP
     * CREATURE_PART_LEFT_BICEP
     * CREATURE_PART_RIGHT_SHOULDER
     * CREATURE_PART_LEFT_SHOULDER
     * CREATURE_PART_RIGHT_HAND
     * CREATURE_PART_LEFT_HAND
     * CREATURE_PART_HEAD
     */
    public static synchronized int getCreatureBodyPart(int nCreaturePart, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCreatureBodyPart");
        pushObject(oCreature);
        pushInteger(nCreaturePart);
        callFunction(753, 2);
        return popInteger();
    }

    /**
     * Sets the body part model to be used on the creature specified.
     * The model names for parts need to be in the following format:
     * p<m/f><race letter><phenotype>_<body part><model number>.mdl
     *
     * @param nPart (CREATURE_PART_*)
     * CREATURE_PART_RIGHT_FOOT
     * CREATURE_PART_LEFT_FOOT
     * CREATURE_PART_RIGHT_SHIN
     * CREATURE_PART_LEFT_SHIN
     * CREATURE_PART_RIGHT_THIGH
     * CREATURE_PART_LEFT_THIGH
     * CREATURE_PART_PELVIS
     * CREATURE_PART_TORSO
     * CREATURE_PART_BELT
     * CREATURE_PART_NECK
     * CREATURE_PART_RIGHT_FOREARM
     * CREATURE_PART_LEFT_FOREARM
     * CREATURE_PART_RIGHT_BICEP
     * CREATURE_PART_LEFT_BICEP
     * CREATURE_PART_RIGHT_SHOULDER
     * CREATURE_PART_LEFT_SHOULDER
     * CREATURE_PART_RIGHT_HAND
     * CREATURE_PART_LEFT_HAND
     * CREATURE_PART_HEAD
     * @param nModelNumber CREATURE_MODEL_TYPE_*
     * CREATURE_MODEL_TYPE_NONE
     * CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
     * CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
     * CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
     * @param oCreature the creature to change the body part for.
     * Note: Only part based creature appearance types are supported.
     * i.e. The model types for the playable races ('P') in the appearance.2da
     */
    public static synchronized void setCreatureBodyPart(int nCreaturePart, int nModelNumber, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCreatureBodyPart");
        pushObject(oCreature);
        pushInteger(nModelNumber);
        pushInteger(nCreaturePart);
        callFunction(754, 3);
    }

    /**
     * returns the Tail type of the creature specified.
     * CREATURE_TAIL_TYPE_NONE
     * CREATURE_TAIL_TYPE_LIZARD
     * CREATURE_TAIL_TYPE_BONE
     * CREATURE_TAIL_TYPE_DEVIL
     * returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
     * if the creature has no Tail, or if the creature can not have its
     * Tail type changed in the toolset.
     */
    public static synchronized int getCreatureTailType(NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getCreatureTailType");
        pushObject(oCreature);
        callFunction(755, 1);
        return popInteger();
    }

    /**
     * Sets the Tail type of the creature specified.
     * @param nTailType (CREATURE_TAIL_TYPE_*)
     * CREATURE_TAIL_TYPE_NONE
     * CREATURE_TAIL_TYPE_LIZARD
     * CREATURE_TAIL_TYPE_BONE
     * CREATURE_TAIL_TYPE_DEVIL
     * @param oCreature the creature to change the Tail type for.
     * Note: Only two creature model types will support Tails.
     * The MODELTYPE for the part based (playable) races 'P'
     * and MODELTYPE 'T'in the appearance.2da
     */
    public static synchronized void setCreatureTailType(int nTailType, NWObject oCreature) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setCreatureTailType");
        pushObject(oCreature);
        pushInteger(nTailType);
        callFunction(756, 2);
    }

    /**
     * returns the Hardness of a Door or Placeable object.
     * @param oObject a door or placeable object.
     * returns -1 on an error or if used on an object that is
     * neither a door nor a placeable object.
     */
    public static synchronized int getHardness(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHardness");
        pushObject(oObject);
        callFunction(757, 1);
        return popInteger();
    }

    /**
     * Sets the Hardness of a Door or Placeable object.
     * @param nHardness must be between 0 and 250.
     * @param oObject a door or placeable object.
     * Does nothing if used on an object that is neither
     * a door nor a placeable.
     */
    public static synchronized void setHardness(int nHardness, NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setHardness");
        pushObject(oObject);
        pushInteger(nHardness);
        callFunction(758, 2);
    }

    /**
     * When set the object can not be opened unless the
     * opener possesses the required key. The key tag required
     * can be specified either in the toolset, or by using
     * the SetLockKeyTag() scripting command.
     * @param oObject a door, or placeable.
     * @param bKeyRequired TRUE/FALSE
     */
    public static synchronized void setLockKeyRequired(NWObject oObject, boolean bKeyRequired) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLockKeyRequired");
        pushInteger(bKeyRequired ? 1 : 0);
        pushObject(oObject);
        callFunction(759, 2);
    }

    /**
     * Set the key tag required to open object oObject.
     * This will only have an effect if the object is set to
     * "Key required to unlock or lock" either in the toolset
     * or by using the scripting command SetLockKeyRequired().
     * @param oObject a door, placeable or trigger.
     * @param sNewKeyTag the key tag required to open the locked object.
     */
    public static synchronized void setLockKeyTag(NWObject oObject, String sNewKeyTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLockKeyTag");
        pushString(sNewKeyTag);
        pushObject(oObject);
        callFunction(760, 2);
    }

    /**
     * Sets whether or not the object can be locked.
     * @param oObject a door or placeable.
     * @param bLockable TRUE/FALSE
     */
    public static synchronized void setLockLockable(NWObject oObject, boolean bLockable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLockLockable");
        pushInteger(bLockable ? 1 : 0);
        pushObject(oObject);
        callFunction(761, 2);
    }

    /**
     * Sets the DC for unlocking the object.
     * @param oObject a door or placeable object.
     * @param nNewUnlockDC must be between 0 and 250.
     */
    public static synchronized void setLockUnlockDC(NWObject oObject, int nNewUnlockDC) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLockUnlockDC");
        pushInteger(nNewUnlockDC);
        pushObject(oObject);
        callFunction(762, 2);
    }

    /**
     * Sets the DC for locking the object.
     * @param oObject a door or placeable object.
     * @param nNewLockDC must be between 0 and 250.
     */
    public static synchronized void setLockLockDC(NWObject oObject, int nNewLockDC) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setLockLockDC");
        pushInteger(nNewLockDC);
        pushObject(oObject);
        callFunction(763, 2);
    }

    /**
     * Sets whether or not the trapped object can be disarmed.
     * @param oTrapObject a placeable, door or trigger
     * @param bDisarmable TRUE/FALSE
     */
    public static synchronized void setTrapDisarmable(NWObject oTrapObject, boolean bDisarmable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDisarmable");
        pushInteger(bDisarmable ? 1 : 0);
        pushObject(oTrapObject);
        callFunction(764, 2);
    }

    /**
     * Sets whether or not the trapped object can be detected.
     * @param oTrapObject a placeable, door or trigger
     * @param bDetectable TRUE/FALSE
     * Note: Setting a trapped object to not be detectable will
     * not make the trap disappear if it has already been detected.
     */
    public static synchronized void setTrapDetectable(NWObject oTrapObject, boolean bDetectable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDetectable");
        pushInteger(bDetectable ? 1 : 0);
        pushObject(oTrapObject);
        callFunction(765, 2);
    }

    /**
     * Sets whether or not the trap is a one-shot trap
     * (i.e. whether or not the trap resets itself after firing).
     * @param oTrapObject a placeable, door or trigger
     * @param bOneShot TRUE/FALSE
     */
    public static synchronized void setTrapOneShot(NWObject oTrapObject, boolean bOneShot) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapOneShot");
        pushInteger(bOneShot ? 1 : 0);
        pushObject(oTrapObject);
        callFunction(766, 2);
    }

    /**
     * Set the tag of the key that will disarm oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized void setTrapKeyTag(NWObject oTrapObject, String sKeyTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapKeyTag");
        pushString(sKeyTag);
        pushObject(oTrapObject);
        callFunction(767, 2);
    }

    /**
     * Set the DC for disarming oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     * @param nDisarmDC must be between 0 and 250.
     */
    public static synchronized void setTrapDisarmDC(NWObject oTrapObject, int nDisarmDC) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDisarmDC");
        pushInteger(nDisarmDC);
        pushObject(oTrapObject);
        callFunction(768, 2);
    }

    /**
     * Set the DC for detecting oTrapObject.
     * @param oTrapObject a placeable, door or trigger
     * @param nDetectDC must be between 0 and 250.
     */
    public static synchronized void setTrapDetectDC(NWObject oTrapObject, int nDetectDC) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapDetectDC");
        pushInteger(nDetectDC);
        pushObject(oTrapObject);
        callFunction(769, 2);
    }

    /**
     * Creates a square Trap object.
     * @param nTrapType The base type of trap (TRAP_BASE_TYPE_*)
     * @param lLocation The location and orientation that the trap will be created at.
     * @param fSize The size of the trap. Minimum size allowed is 1.0f.
     * @param sTag The tag of the trap being created.
     * @param nStandardFaction The faction of the trap (STANDARD_FACTION_*).
     * @param sOnDisarmScript The OnDisarm script that will fire when the trap is disarmed.
     * If "" no script will fire.
     * @param sOnTrapTriggeredScript The OnTrapTriggered script that will fire when the
     * trap is triggered.
     * If "" the default OnTrapTriggered script for the trap
     * type specified will fire instead (as specified in the
     * traps.2da).
     */
    public static synchronized NWObject createTrapAtLocation(int nTrapType, NWLocation lLocation, float fSize, String sTag, int nStandardFaction, String sOnDisarmScript, String sOnTrapTriggeredScript) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling createTrapAtLocation");
        pushString(sOnTrapTriggeredScript);
        pushString(sOnDisarmScript);
        pushInteger(nStandardFaction);
        pushString(sTag);
        pushFloat(fSize);
        pushLocation(lLocation);
        pushInteger(nTrapType);
        callFunction(770, 7);
        return popObject();
    }

    /**
     * Creates a Trap on the object specified.
     * @param nTrapType The base type of trap (TRAP_BASE_TYPE_*)
     * @param oObject The object that the trap will be created on. Works only on Doors and Placeables.
     * @param nStandardFaction The faction of the trap (STANDARD_FACTION_*).
     * @param sOnDisarmScript The OnDisarm script that will fire when the trap is disarmed.
     * If "" no script will fire.
     * @param sOnTrapTriggeredScript The OnTrapTriggered script that will fire when the
     * trap is triggered.
     * If "" the default OnTrapTriggered script for the trap
     * type specified will fire instead (as specified in the
     * traps.2da).
     * Note: After creating a trap on an object, you can change the trap's properties
     * using the various SetTrap* scripting commands by passing in the object
     * that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
     */
    public static synchronized void createTrapOnObject(int nTrapType, NWObject oObject, int nStandardFaction, String sOnDisarmScript, String sOnTrapTriggeredScript) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling createTrapOnObject");
        pushString(sOnTrapTriggeredScript);
        pushString(sOnDisarmScript);
        pushInteger(nStandardFaction);
        pushObject(oObject);
        pushInteger(nTrapType);
        callFunction(771, 5);
    }

    /**
     * Set the Will saving throw value of the Door or Placeable object oObject.
     * @param oObject a door or placeable object.
     * @param nWillSave must be between 0 and 250.
     */
    public static synchronized void setWillSavingThrow(NWObject oObject, int nWillSave) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setWillSavingThrow");
        pushInteger(nWillSave);
        pushObject(oObject);
        callFunction(772, 2);
    }

    /**
     * Set the Reflex saving throw value of the Door or Placeable object oObject.
     * @param oObject a door or placeable object.
     * @param nReflexSave must be between 0 and 250.
     */
    public static synchronized void setReflexSavingThrow(NWObject oObject, int nReflexSave) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setReflexSavingThrow");
        pushInteger(nReflexSave);
        pushObject(oObject);
        callFunction(773, 2);
    }

    /**
     * Set the Fortitude saving throw value of the Door or Placeable object oObject.
     * @param oObject a door or placeable object.
     * @param nFortitudeSave must be between 0 and 250.
     */
    public static synchronized void setFortitudeSavingThrow(NWObject oObject, int nFortitudeSave) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setFortitudeSavingThrow");
        pushInteger(nFortitudeSave);
        pushObject(oObject);
        callFunction(774, 2);
    }

    /**
     * returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
     * TILESET_RESREF_BEHOLDER_CAVES
     * TILESET_RESREF_CASTLE_INTERIOR
     * TILESET_RESREF_CITY_EXTERIOR
     * TILESET_RESREF_CITY_INTERIOR
     * TILESET_RESREF_CRYPT
     * TILESET_RESREF_DESERT
     * TILESET_RESREF_DROW_INTERIOR
     * TILESET_RESREF_DUNGEON
     * TILESET_RESREF_FOREST
     * TILESET_RESREF_FROZEN_WASTES
     * TILESET_RESREF_ILLITHID_INTERIOR
     * TILESET_RESREF_MICROSET
     * TILESET_RESREF_MINES_AND_CAVERNS
     * TILESET_RESREF_RUINS
     * TILESET_RESREF_RURAL
     * TILESET_RESREF_RURAL_WINTER
     * TILESET_RESREF_SEWERS
     * TILESET_RESREF_UNDERDARK
     * * returns an empty string on an error.
     */
    public static synchronized String getTilesetResRef(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTilesetResRef");
        pushObject(oArea);
        callFunction(775, 1);
        return popString();
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject can be recovered.
     */
    public static synchronized boolean getTrapRecoverable(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapRecoverable");
        pushObject(oTrapObject);
        callFunction(776, 1);
        return popInteger() > 0;
    }

    /**
     * Sets whether or not the trapped object can be recovered.
     * @param oTrapObject a placeable, door or trigger
     */
    public static synchronized void setTrapRecoverable(NWObject oTrapObject, boolean bRecoverable) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapRecoverable");
        pushInteger(bRecoverable ? 1 : 0);
        pushObject(oTrapObject);
        callFunction(777, 2);
    }

    /**
     * Get the XP scale being used for the module.
     */
    public static synchronized int getModuleXPScale() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getModuleXPScale");
        callFunction(778, 0);
        return popInteger();
    }

    /**
     * Set the XP scale used by the module.
     * @param nXPScale The XP scale to be used. Must be between 0 and 200.
     */
    public static synchronized void setModuleXPScale(int nXPScale) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setModuleXPScale");
        pushInteger(nXPScale);
        callFunction(779, 1);
    }

    /**
     * Get the feedback message that will be displayed when trying to unlock the object oObject.
     * @param oObject a door or placeable.
     * Returns an empty string "" on an error or if the game's default feedback message is being used
     */
    public static synchronized String getKeyRequiredFeedback(NWObject oObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getKeyRequiredFeedback");
        pushObject(oObject);
        callFunction(780, 1);
        return popString();
    }

    /**
     * Set the feedback message that is displayed when trying to unlock the object oObject.
     * This will only have an effect if the object is set to
     * "Key required to unlock or lock" either in the toolset
     * or by using the scripting command SetLockKeyRequired().
     * @param oObject a door or placeable.
     * @param sFeedbackMessage the string to be displayed in the player's text window.
     * to use the game's default message, set sFeedbackMessage to ""
     */
    public static synchronized void setKeyRequiredFeedback(NWObject oObject, String sFeedbackMessage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setKeyRequiredFeedback");
        pushString(sFeedbackMessage);
        pushObject(oObject);
        callFunction(781, 2);
    }

    /**
     * @param oTrapObject a placeable, door or trigger
     * * Returns TRUE if oTrapObject is active
     */
    public static synchronized boolean getTrapActive(NWObject oTrapObject) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getTrapActive");
        pushObject(oTrapObject);
        callFunction(782, 1);
        return popInteger() > 0;
    }

    /**
     * Sets whether or not the trap is an active trap
     * @param oTrapObject a placeable, door or trigger
     * @param bActive TRUE/FALSE
     * Notes:
     * Setting a trap as inactive will not make the
     * trap disappear if it has already been detected.
     * Call SetTrapDetectedBy() to make a detected trap disappear.
     * To make an inactive trap not detectable call SetTrapDetectable()
     */
    public static synchronized void setTrapActive(NWObject oTrapObject, boolean bActive) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTrapActive");
        pushInteger(bActive ? 1 : 0);
        pushObject(oTrapObject);
        callFunction(783, 2);
    }

    /**
     * Locks the player's camera pitch to its current pitch setting,
     * or unlocks the player's camera pitch.
     * Stops the player from tilting their camera angle.
     * @param oPlayer A player object.
     * @param bLocked TRUE/FALSE.
     */
    public static synchronized void lockCameraPitch(NWObject oPlayer, boolean bLocked) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling lockCameraPitch");
        pushInteger(bLocked ? 1 : 0);
        pushObject(oPlayer);
        callFunction(784, 2);
    }

    /**
     * Locks the player's camera distance to its current distance setting,
     * or unlocks the player's camera distance.
     * Stops the player from being able to zoom in/out the camera.
     * @param oPlayer A player object.
     * @param bLocked TRUE/FALSE.
     */
    public static synchronized void lockCameraDistance(NWObject oPlayer, boolean bLocked) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling lockCameraDistance");
        pushInteger(bLocked ? 1 : 0);
        pushObject(oPlayer);
        callFunction(785, 2);
    }

    /**
     * Locks the player's camera direction to its current direction,
     * or unlocks the player's camera direction to enable it to move
     * freely again.
     * Stops the player from being able to rotate the camera direction.
     * @param oPlayer A player object.
     * @param bLocked TRUE/FALSE.
     */
    public static synchronized void lockCameraDirection(NWObject oPlayer, boolean bLocked) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling lockCameraDirection");
        pushInteger(bLocked ? 1 : 0);
        pushObject(oPlayer);
        callFunction(786, 2);
    }

    /**
     * Get the last object that default clicked (left clicked) on the placeable object
     * that is calling this function.
     * Should only be called from a placeables OnClick event.
     * * Returns OBJECT_INVALID if it is called by something other than a placeable.
     */
    public static synchronized NWObject getPlaceableLastClickedBy() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPlaceableLastClickedBy");
        callFunction(787, 0);
        return popObject();
    }

    /**
     * returns TRUE if the item is flagged as infinite.
     * @param oItem an item.
     * The infinite property affects the buying/selling behavior of the item in a store.
     * An infinite item will still be available to purchase from a store after a player
     * buys the item (non-infinite items will disappear from the store when purchased).
     */
    public static synchronized boolean getInfiniteFlag(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getInfiniteFlag");
        pushObject(oItem);
        callFunction(788, 1);
        return popInteger() > 0;
    }

    /**
     * Sets the Infinite flag on an item
     * @param oItem the item to change
     * @param bInfinite TRUE or FALSE, whether the item should be Infinite
     * The infinite property affects the buying/selling behavior of the item in a store.
     * An infinite item will still be available to purchase from a store after a player
     * buys the item (non-infinite items will disappear from the store when purchased).
     */
    public static synchronized void setInfiniteFlag(NWObject oItem, boolean bInfinite) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setInfiniteFlag");
        pushInteger(bInfinite ? 1 : 0);
        pushObject(oItem);
        callFunction(789, 2);
    }

    /**
     * Gets the size of the area.
     * @param nAreaDimension The area dimension that you wish to determine.
     * AREA_HEIGHT
     * AREA_WIDTH
     * @param oArea The area that you wish to get the size of.
     * Returns: The number of tiles that the area is wide/high, or zero on an error.
     * If no valid area (or object) is specified, it uses the area of the caller.
     * If an object other than an area is specified, will use the area that the object is currently in.
     */
    public static synchronized int getAreaSize(int nAreaDimension, NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getAreaSize");
        pushObject(oArea);
        pushInteger(nAreaDimension);
        callFunction(790, 2);
        return popInteger();
    }

    /**
     * Set the name of oObject.
     * @param oObject the object for which you are changing the name (a creature, placeable, item, or door).
     * @param sNewName the new name that the object will use.
     * Note: SetName() does not work on player objects.
     * Setting an object's name to "" will make the object
     * revert to using the name it had originally before any
     * SetName() calls were made on the object.
     */
    public static synchronized void setName(NWObject oObject, String sNewName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setName");
        pushString(sNewName);
        pushObject(oObject);
        callFunction(791, 2);
    }

    /**
     * Get the PortraitId of oTarget.
     * @param oTarget the object for which you are getting the portrait Id.
     * Returns: The Portrait Id number being used for the object oTarget.
     * The Portrait Id refers to the row number of the Portraits.2da
     * that this portrait is from.
     * If a custom portrait is being used, oTarget is a player object,
     * or on an error returns PORTRAIT_INVALID. In these instances
     * try using GetPortraitResRef() instead.
     */
    public static synchronized int getPortraitId(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPortraitId");
        pushObject(oTarget);
        callFunction(792, 1);
        return popInteger();
    }

    /**
     * Change the portrait of oTarget to use the Portrait Id specified.
     * @param oTarget the object for which you are changing the portrait.
     * @param nPortraitId The Id of the new portrait to use.
     * nPortraitId refers to a row in the Portraits.2da
     * Note: Not all portrait Ids are suitable for use with all object types.
     * Setting the portrait Id will also cause the portrait ResRef
     * to be set to the appropriate portrait ResRef for the Id specified.
     */
    public static synchronized void setPortraitId(NWObject oTarget, int nPortraitId) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPortraitId");
        pushInteger(nPortraitId);
        pushObject(oTarget);
        callFunction(793, 2);
    }

    /**
     * Get the Portrait ResRef of oTarget.
     * @param oTarget the object for which you are getting the portrait ResRef.
     * Returns: The Portrait ResRef being used for the object oTarget.
     * The Portrait ResRef will not include a trailing size letter.
     */
    public static synchronized String getPortraitResRef(NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPortraitResRef");
        pushObject(oTarget);
        callFunction(794, 1);
        return popString();
    }

    /**
     * Change the portrait of oTarget to use the Portrait ResRef specified.
     * @param oTarget the object for which you are changing the portrait.
     * @param sPortraitResRef The ResRef of the new portrait to use.
     * The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
     * Note: Not all portrait ResRefs are suitable for use with all object types.
     * Setting the portrait ResRef will also cause the portrait Id
     * to be set to PORTRAIT_INVALID.
     */
    public static synchronized void setPortraitResRef(NWObject oTarget, String sPortraitResRef) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPortraitResRef");
        pushString(sPortraitResRef);
        pushObject(oTarget);
        callFunction(795, 2);
    }

    /**
     * Set oPlaceable's useable object status.
     * Note: Only works on non-static placeables.
     */
    public static synchronized void setUseableFlag(NWObject oPlaceable, boolean bUseableFlag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setUseableFlag");
        pushInteger(bUseableFlag ? 1 : 0);
        pushObject(oPlaceable);
        callFunction(796, 2);
    }

    /**
     * Get the description of oObject.
     * @param oObject the object from which you are obtaining the description.
     * Can be a creature, item, placeable, door, trigger or module object.
     * @param bOriginalDescription  if set to true any new description specified via a SetDescription scripting command
     * is ignored and the original object's description is returned instead.
     * @param bIdentified If oObject is an item, setting this to TRUE will return the identified description,
     * setting this to FALSE will return the unidentified description. This flag has no
     * effect on objects other than items.
     */
    public static synchronized String getDescription(NWObject oObject, boolean bOriginalDescription, boolean bIdentifiedDescription) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getDescription");
        pushInteger(bIdentifiedDescription ? 1 : 0);
        pushInteger(bOriginalDescription ? 1 : 0);
        pushObject(oObject);
        callFunction(797, 3);
        return popString();
    }

    /**
     * Set the description of oObject.
     * @param oObject the object for which you are changing the description
     * Can be a creature, placeable, item, door, or trigger.
     * @param sNewDescription the new description that the object will use.
     * @param bIdentified If oObject is an item, setting this to TRUE will set the identified description,
     * setting this to FALSE will set the unidentified description. This flag has no
     * effect on objects other than items.
     * Note: Setting an object's description to "" will make the object
     * revert to using the description it originally had before any
     * SetDescription() calls were made on the object.
     */
    public static synchronized void setDescription(NWObject oObject, String sNewDescription, boolean bIdentifiedDescription) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setDescription");
        pushInteger(bIdentifiedDescription ? 1 : 0);
        pushString(sNewDescription);
        pushObject(oObject);
        callFunction(798, 3);
    }

    /**
     * Get the PC that sent the last player chat(text) message.
     * Should only be called from a module's OnPlayerChat event script.
     * * Returns OBJECT_INVALID on error.
     * Note: Private tells do not trigger a OnPlayerChat event.
     */
    public static synchronized NWObject getPCChatSpeaker() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCChatSpeaker");
        callFunction(799, 0);
        return popObject();
    }

    /**
     * Get the last player chat(text) message that was sent.
     * Should only be called from a module's OnPlayerChat event script.
     * * Returns empty string "" on error.
     * Note: Private tells do not trigger a OnPlayerChat event.
     */
    public static synchronized String getPCChatMessage() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCChatMessage");
        callFunction(800, 0);
        return popString();
    }

    /**
     * Get the volume of the last player chat(text) message that was sent.
     * Returns one of the following TALKVOLUME_* constants based on the volume setting
     * that the player used to send the chat message.
     * TALKVOLUME_TALK
     * TALKVOLUME_WHISPER
     * TALKVOLUME_SHOUT
     * TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
     * TALKVOLUME_PARTY
     * Should only be called from a module's OnPlayerChat event script.
     * * Returns -1 on error.
     * Note: Private tells do not trigger a OnPlayerChat event.
     */
    public static synchronized int getPCChatVolume() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getPCChatVolume");
        callFunction(801, 0);
        return popInteger();
    }

    /**
     * Set the last player chat(text) message before it gets sent to other players.
     * @param sNewChatMessage The new chat text to be sent onto other players.
     * Setting the player chat message to an empty string "",
     * will cause the chat message to be discarded
     * (i.e. it will not be sent to other players).
     * Note: The new chat message gets sent after the OnPlayerChat script exits.
     */
    public static synchronized void setPCChatMessage(String sNewChatMessage) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPCChatMessage");
        pushString(sNewChatMessage);
        callFunction(802, 1);
    }

    /**
     * Set the last player chat(text) volume before it gets sent to other players.
     * @param nTalkVolume The new volume of the chat text to be sent onto other players.
     * TALKVOLUME_TALK
     * TALKVOLUME_WHISPER
     * TALKVOLUME_SHOUT
     * TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
     * TALKVOLUME_PARTY
     * TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
     * Note: The new chat message gets sent after the OnPlayerChat script exits.
     */
    public static synchronized void setPCChatVolume(int nTalkVolume) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setPCChatVolume");
        pushInteger(nTalkVolume);
        callFunction(803, 1);
    }

    /**
     * Get the Color of oObject from the color channel specified.
     * @param oObject the object from which you are obtaining the color.
     * Can be a creature that has color information (i.e. the playable races).
     * @param nColorChannel The color channel that you want to get the color value of.
     * COLOR_CHANNEL_SKIN
     * COLOR_CHANNEL_HAIR
     * COLOR_CHANNEL_TATTOO_1
     * COLOR_CHANNEL_TATTOO_2
     * * Returns -1 on error.
     */
    public static synchronized int getColor(NWObject oObject, int nColorChannel) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getColor");
        pushInteger(nColorChannel);
        pushObject(oObject);
        callFunction(804, 2);
        return popInteger();
    }

    /**
     * Set the color channel of oObject to the color specified.
     * @param oObject the object for which you are changing the color.
     * Can be a creature that has color information (i.e. the playable races).
     * @param nColorChannel The color channel that you want to set the color value of.
     * COLOR_CHANNEL_SKIN
     * COLOR_CHANNEL_HAIR
     * COLOR_CHANNEL_TATTOO_1
     * COLOR_CHANNEL_TATTOO_2
     * @param nColorValue The color you want to set (0-175).
     */
    public static synchronized void setColor(NWObject oObject, int nColorChannel, int nColorValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setColor");
        pushInteger(nColorValue);
        pushInteger(nColorChannel);
        pushObject(oObject);
        callFunction(805, 3);
    }

    /**
     * Returns Item property Material.  You need to specify the Material Type.
     * @param nMasterialType The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
     * Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
     */
    public static synchronized NWItemProperty itemPropertyMaterial(int nMaterialType) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyMaterial");
        pushInteger(nMaterialType);
        callFunction(806, 1);
        return popItemProperty();
    }

    /**
     * Returns Item property Quality. You need to specify the Quality.
     * @param nQuality  The Quality of the item property to create (see iprp_qualcost.2da).
     * IP_CONST_QUALITY_*
     * Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
     */
    public static synchronized NWItemProperty itemPropertyQuality(int nQuality) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyQuality");
        pushInteger(nQuality);
        callFunction(807, 1);
        return popItemProperty();
    }

    /**
     * Returns a generic Additional Item property. You need to specify the Additional property.
     * @param nProperty The item property to create (see iprp_addcost.2da).
     * IP_CONST_ADDITIONAL_*
     * Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
     */
    public static synchronized NWItemProperty itemPropertyAdditional(int nAdditionalProperty) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling itemPropertyAdditional");
        pushInteger(nAdditionalProperty);
        callFunction(808, 1);
        return popItemProperty();
    }

    /**
     * Sets a new tag for oObject.
     * Will do nothing for invalid objects or the module object.
     *
     * Note: Care needs to be taken with this function.
     * Changing the tag for creature with waypoints will make them stop walking them.
     * Changing waypoint, door or trigger tags will break their area transitions.
     */
    public static synchronized void setTag(NWObject oObject, String sNewTag) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTag");
        pushString(sNewTag);
        pushObject(oObject);
        callFunction(809, 2);
    }

    /**
     * Returns the string tag set for the provided effect.
     * @param If no tag has been set, returns an empty string.
     */
    public static synchronized String getEffectTag(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectTag");
        pushEffect(eEffect);
        callFunction(810, 1);
        return popString();
    }

    /**
     * Tags the effect with the provided string.
     * @param Any other tags in the link will be overwritten.
     */
    public static synchronized NWEffect tagEffect(NWEffect eEffect, String sNewTag) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling tagEffect");
        pushString(sNewTag);
        pushEffect(eEffect);
        callFunction(811, 2);
        return popEffect();
    }

    /**
     * Returns the caster level of the creature who created the effect.
     * @param If not created by a creature, returns 0.
     * @param If created by a spell-like ability, returns 0.
     */
    public static synchronized int getEffectCasterLevel(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectCasterLevel");
        pushEffect(eEffect);
        callFunction(812, 1);
        return popInteger();
    }

    /**
     * Returns the total duration of the effect in seconds.
     * @param Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
     */
    public static synchronized int getEffectDuration(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectDuration");
        pushEffect(eEffect);
        callFunction(813, 1);
        return popInteger();
    }

    /**
     * Returns the remaining duration of the effect in seconds.
     * @param Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
     */
    public static synchronized int getEffectDurationRemaining(NWEffect eEffect) throws NWNotInContextException, NWInvalidEffectException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getEffectDurationRemaining");
        pushEffect(eEffect);
        callFunction(814, 1);
        return popInteger();
    }

    /**
     * Returns the string tag set for the provided item property.
     * @param If no tag has been set, returns an empty string.
     */
    public static synchronized String getItemPropertyTag(NWItemProperty nProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyTag");
        pushItemProperty(nProperty);
        callFunction(815, 1);
        return popString();
    }

    /**
     * Tags the item property with the provided string.
     * @param Any tags currently set on the item property will be overwritten.
     */
    public static synchronized NWItemProperty tagItemProperty(NWItemProperty nProperty, String sNewTag) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling tagItemProperty");
        pushString(sNewTag);
        pushItemProperty(nProperty);
        callFunction(816, 2);
        return popItemProperty();
    }

    /**
     * Returns the total duration of the item property in seconds.
     * @param Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
     */
    public static synchronized int getItemPropertyDuration(NWItemProperty nProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyDuration");
        pushItemProperty(nProperty);
        callFunction(817, 1);
        return popInteger();
    }

    /**
     * Returns the remaining duration of the item property in seconds.
     * @param Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
     */
    public static synchronized int getItemPropertyDurationRemaining(NWItemProperty nProperty) throws NWNotInContextException, NWInvalidItemPropertyException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getItemPropertyDurationRemaining");
        pushItemProperty(nProperty);
        callFunction(818, 1);
        return popInteger();
    }

    /**
     * Instances a new area from the given resref, which needs to be a existing module area.
     * Will optionally set a new area tag and displayed name. The new area is accessible
     * immediately, but initialisation scripts for the area and all contained creatures will only
     * run after the current script finishes (so you can clean up objects before returning).
     *
     * Returns the new area, or OBJECT_INVALID on failure.
     *
     * Note: When spawning a second instance of a existing area, you will have to manually
     * adjust all transitions (doors, triggers) with the relevant script commands,
     * or players might end up in the wrong area.
     */
    public static synchronized NWObject createArea(String sResRef, String sNewTag, String sNewName) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling createArea");
        pushString(sNewName);
        pushString(sNewTag);
        pushString(sResRef);
        callFunction(819, 3);
        return popObject();
    }

    /**
     * Destroys the given area object and everything in it.
     *
     * Return values:
     * 0: Object not an area or invalid.
     * -1: Area contains spawn location and removal would leave module without entrypoint.
     * -2: Players in area.
     * 1: Area destroyed successfully.
     */
    public static synchronized int destroyArea(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling destroyArea");
        pushObject(oArea);
        callFunction(820, 1);
        return popInteger();
    }

    /**
     * Creates a copy of a existing area, including everything inside of it (except players).
     *
     * Returns the new area, or OBJECT_INVALID on error.
     *
     * Note: You will have to manually adjust all transitions (doors, triggers) with the
     * relevant script commands, or players might end up in the wrong area.
     */
    public static synchronized NWObject copyArea(NWObject oArea) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling copyArea");
        pushObject(oArea);
        callFunction(821, 1);
        return popObject();
    }

    /**
     * Returns the first area in the module.
     */
    public static synchronized NWObject getFirstArea() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getFirstArea");
        callFunction(822, 0);
        return popObject();
    }

    /**
     * Returns the next area in the module (after GetFirstArea), or OBJECT_INVALID if no more
     * areas are loaded.
     */
    public static synchronized NWObject getNextArea() throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getNextArea");
        callFunction(823, 0);
        return popObject();
    }

    /**
     * Sets the transition target for oTransition.
     *
     * Notes:
     * @param oTransition can be any valid game object, except areas.
     * @param oTarget can be any valid game object with a location, or OBJECT_INVALID (to unlink).
     * @param Rebinding a transition will NOT change the other end of the transition; for example,
     * with normal doors you will have to do either end separately.
     * @param Any valid game object can hold a transition target, but only some are used by the game engine
     * (doors and triggers). This might change in the future. You can still set and query them for
     * other game objects from nwscript.
     * @param Transition target objects are cached The toolset-configured destination tag is
     * used for a lookup only once, at first use. Thus, attempting to use SetTag() to change the
     * destination for a transition will not work in a predictable fashion.
     */
    public static synchronized void setTransitionTarget(NWObject oTransition, NWObject oTarget) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setTransitionTarget");
        pushObject(oTarget);
        pushObject(oTransition);
        callFunction(824, 2);
    }

    /**
     * Sets whether the provided item should be hidden when equipped.
     * @param The intended usage of this function is to provide an easy way to hide helmets, but it
     * can be used equally for any slot which has creature mesh visibility when equipped,
     * e.g.: armour, helm, cloak, left hand, and right hand.
     * @param nValue should be TRUE or FALSE.
     */
    public static synchronized void setHiddenWhenEquipped(NWObject oItem, boolean bValue) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling setHiddenWhenEquipped");
        pushInteger(bValue ? 1 : 0);
        pushObject(oItem);
        callFunction(825, 2);
    }

    /**
     * Returns whether the provided item is hidden when equipped.
     */
    public static synchronized boolean getHiddenWhenEquipped(NWObject oItem) throws NWNotInContextException {
        if (!canCallVM()) throw new NWNotInContextException("Not on VM thread while calling getHiddenWhenEquipped");
        pushObject(oItem);
        callFunction(826, 1);
        return popInteger() > 0;
    }

}
