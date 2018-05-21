-- Start NWN Functions	
--ENGINE_STRUCTURE_EFFECT 0
--ENGINE_STRUCTURE_EVENT 1
--ENGINE_STRUCTURE_LOCATION 2
--ENGINE_STRUCTURE_TALENT 3
--ENGINE_STRUCTURE_ITEMPROPERTY 4

--helper function to push booleans
function StackPushBoolean(bCond)
	StackPushInteger(bCond and 1 or 0)
end

--helper function to pop booleans
function StackPopBoolean()
	return StackPopInteger() > 0
end

--  Get an integer between 0 and nMaxInteger-1.
--  Return value on error: 0
function Random(nMaxInteger) 
	StackPushInteger(nMaxInteger)
	VM_ExecuteCommand(0, 1)
	return StackPopInteger()
end

--  Output sString to the log file.
function PrintString(sString)  
	StackPushString(sString)
	VM_ExecuteCommand(1, 1)
end

--  Output a formatted float to the log file.
--  - nWidth should be a value from 0 to 18 inclusive.
--  - nDecimals should be a value from 0 to 9 inclusive.
function PrintFloat(fFloat, nWidth, nDecimals)
	nWidth = nWidth or 18
	nDecimals = nDecimals or 9
  
	StackPushInteger(nDecimals)
	StackPushInteger(nWidth)
	StackPushFloat(fFloat)
	VM_ExecuteCommand(2, 3)
end

--  Convert fFloat into a string.
--  - nWidth should be a value from 0 to 18 inclusive.
--  - nDecimals should be a value from 0 to 9 inclusive.
function FloatToString(fFloat, nWidth, nDecimals)
	nWidth = nWidth or 18
	nDecimals = nDecimals or 9
  
	StackPushInteger(nDecimals)
	StackPushInteger(nWidth)
	StackPushFloat(fFloat)
	VM_ExecuteCommand(3, 3)
	return StackPopString()
end

--  Output nInteger to the log file.
function PrintInteger(nInteger)
	StackPushInteger(nInteger)
	VM_ExecuteCommand(4, 1)
end

--  Output oObject's ID to the log file.
function PrintObject(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(5, 1)
end

--  Make oTarget run sScript and then return execution to the calling script.
--  If sScript does not specify a compiled script, nothing happens.
function ExecuteScript(sScript, oTarget)
	StackPushObject(oTarget)
	StackPushString(sScript)
	VM_ExecuteCommand(8, 2)
end

--  Clear all the actions of the caller.
--  * No return value, but if an error occurs, the log file will contain
--    "ClearAllActions failed.".
--  - nClearCombatState: if true, this will immediately clear the combat state
--    on a creature, which will stop the combat music and allow them to rest,
--    engage in dialog, or other actions that they would normally have to wait for.
function ClearAllActions(bClearCombatState)
	bClearCombatState = bClearCombatState or false
  
	StackPushBoolean(bClearCombatState)
	VM_ExecuteCommand(9, 1)
end

--  Cause the caller to face fDirection.
--  - fDirection is expressed as anticlockwise degrees from Due East.
--    DIRECTION_EAST, DIRECTION_NORTH, DIRECTION_WEST and DIRECTION_SOUTH are
--    predefined. (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
function SetFacing(fDirection)
	StackPushFloat(fDirection)
	VM_ExecuteCommand(10, 1)
end

--  Set the calendar to the specified date.
--  - nYear should be from 0 to 32000 inclusive
--  - nMonth should be from 1 to 12 inclusive
--  - nDay should be from 1 to 28 inclusive
--  1) Time can only be advanced forwards attempting to set the time backwards
--     will result in no change to the calendar.
--  2) If values larger than the month or day are specified, they will be wrapped
--     around and the overflow will be used to advance the next field.
--     e.g. Specifying a year of 1350, month of 33 and day of 10 will result in
--     the calender being set to a year of 1352, a month of 9 and a day of 10.
function SetCalendar(nYear, nMonth, nDay)
	StackPushInteger(nDay)
	StackPushInteger(nMonth)
	StackPushInteger(nYear)
	VM_ExecuteCommand(11, 3)
end

--  Set the time to the time specified.
--  - nHour should be from 0 to 23 inclusive
--  - nMinute should be from 0 to 59 inclusive
--  - nSecond should be from 0 to 59 inclusive
--  - nMillisecond should be from 0 to 999 inclusive
--  1) Time can only be advanced forwards attempting to set the time backwards
--     will result in the day advancing and then the time being set to that
--     specified, e.g. if the current hour is 15 and then the hour is set to 3,
--     the day will be advanced by 1 and the hour will be set to 3.
--  2) If values larger than the max hour, minute, second or millisecond are
--     specified, they will be wrapped around and the overflow will be used to
--     advance the next field, e.g. specifying 62 hours, 250 minutes, 10 seconds
--     and 10 milliseconds will result in the calendar day being advanced by 2
--     and the time being set to 18 hours, 10 minutes, 10 milliseconds.
function SetTime(nHour, nMinute, nSecond, nMillisecond)  
	StackPushInteger(nMillisecond)
	StackPushInteger(nSecond)
	StackPushInteger(nMinute)
	StackPushInteger(nHour)
	VM_ExecuteCommand(12, 4)
end

--  Get the current calendar year.
function GetCalendarYear()
	VM_ExecuteCommand(13, 0)
	return StackPopInteger()
end

--  Get the current calendar month.
function GetCalendarMonth()
	VM_ExecuteCommand(14, 0)
	return StackPopInteger()
end

--  Get the current calendar day.
function GetCalendarDay()
	VM_ExecuteCommand(15, 0)
	return StackPopInteger()
end

--  Get the current hour.
function GetTimeHour()
	VM_ExecuteCommand(16, 0)
	return StackPopInteger()
end

--  Get the current minute
function GetTimeMinute()
	VM_ExecuteCommand(17, 0)
	return StackPopInteger()
end

--  Get the current second
function GetTimeSecond()
	VM_ExecuteCommand(18, 0)
	return StackPopInteger()
end

--  Get the current millisecond
function GetTimeMillisecond()
	VM_ExecuteCommand(19, 0)
	return StackPopInteger()
end

--  The action subject will generate a random location near its current location
--  and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
--  to call ClearAllActions in order to allow a creature to perform any other action
--  once ActionRandomWalk has been called.
--  * No return value, but if an error occurs the log file will contain
--    "ActionRandomWalk failed."
function ActionRandomWalk()
	VM_ExecuteCommand(20, 0)
end

--  The action subject will move to lDestination.
--  - lDestination: The object will move to this location.  If the location is
--    invalid or a path cannot be found to it, the command does nothing.
--  - bRun: If this is TRUE, the action subject will run rather than walk
--  * No return value, but if an error occurs the log file will contain
--    "MoveToPoint failed."
function ActionMoveToLocation(lDestination, bRun)
  	bRun = bRun or false
	
	StackPushBoolean(bRun)
	StackPushLocation(lDestination)
	VM_ExecuteCommand(21, 2)
end

--  Cause the action subject to move to a certain distance from oMoveTo.
--  If there is no path to oMoveTo, this command will do nothing.
--  - oMoveTo: This is the object we wish the action subject to move to
--  - bRun: If this is TRUE, the action subject will run rather than walk
--  - fRange: This is the desired distance between the action subject and oMoveTo
--  * No return value, but if an error occurs the log file will contain
--    "ActionMoveToObject failed."
function ActionMoveToObject(oMoveTo, bRun, fRange)
	bRun = bRun or false
	fRange = fRange or 1.0

	StackPushFloat(fRange)
	StackPushBoolean(bRun)
	StackPushObject(oMoveTo)
	VM_ExecuteCommand(22, 3)
end

--  Cause the action subject to move to a certain distance away from oFleeFrom.
--  - oFleeFrom: This is the object we wish the action subject to move away from.
--    If oFleeFrom is not in the same area as the action subject, nothing will
--    happen.
--  - bRun: If this is TRUE, the action subject will run rather than walk
--  - fMoveAwayRange: This is the distance we wish the action subject to put
--    between themselves and oFleeFrom
--  * No return value, but if an error occurs the log file will contain
--    "ActionMoveAwayFromObject failed."
function ActionMoveAwayFromObject(oFleeFrom, bRun, fMoveAwayRange)
	bRun = bRun or false
	fMoveAwayRange = fMoveAwayRange or 40.0

	StackPushFloat(fMoveAwayRange)
	StackPushBoolean(bRun)
	StackPushObject(oFleeFrom)
	VM_ExecuteCommand(23, 3)	
end

--  Get the area that oTarget is currently in
--  * Return value on error: OBJECT_INVALID
function GetArea(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(24, 1)
	return StackPopObject()
end

--  The value returned by this function depends on the object type of the caller:
--  1) If the caller is a door it returns the object that last
--     triggered it.
--  2) If the caller is a trigger, area of effect, module, area or encounter it
--     returns the object that last entered it.
--  * Return value on error: OBJECT_INVALID
--   When used for doors, this should only be called from the OnAreaTransitionClick
--   event.  Otherwise, it should only be called in OnEnter scripts.
function GetEnteringObject()
	VM_ExecuteCommand(25, 0)
	return StackPopObject()
end

--  Get the object that last left the caller.  This function works on triggers,
--  areas of effect, modules, areas and encounters.
--  * Return value on error: OBJECT_INVALID
--  Should only be called in OnExit scripts.
function GetExitingObject()
	VM_ExecuteCommand(26, 0)
	return StackPopObject()
end

--  Get the position of oTarget
--  * Return value on error: vector (0.0f, 0.0f, 0.0f)
function GetPosition(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(27, 1)
	return StackPopVector()
end

--  Get the direction in which oTarget is facing, expressed as a float between
--  0.0f and 360.0f
--  * Return value on error: -1.0f
function GetFacing(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(28, 1)
	return StackPopFloat()
end

--  Get the possessor of oItem
--  * Return value on error: OBJECT_INVALID
function GetItemPossessor(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(29, 1)
	return StackPopObject()
end

--  Get the object possessed by oCreature with the tag sItemTag
--  * Return value on error: OBJECT_INVALID
function GetItemPossessedBy(oCreature, sItemTag)
	StackPushString(sItemTag)
	StackPushObject(oCreature)
	VM_ExecuteCommand(30, 2)
	return StackPopObject()
end

--  Create an item with the template sItemTemplate in oTarget's inventory.
--  - nStackSize: This is the stack size of the item to be created
--  - sNewTag: If this string is not empty, it will replace the default tag from the template
--  * Return value: The object that has been created.  On error, this returns
--    OBJECT_INVALID.
--  If the item created was merged into an existing stack of similar items,
--  the function will return the merged stack object. If the merged stack
--  overflowed, the function will return the overflowed stack that was created.
function CreateItemOnObject(sItemTemplate, oTarget, nStackSize, sNewTag)
	oTarget = oTarget or OBJECT_SELF
	nStackSize = nStackSize or 1
	sNewTag =  sNewTag or ""

	StackPushString(sNewTag)
	StackPushInteger(nStackSize)
	StackPushObject(oTarget)
	StackPushString(sItemTemplate)
	VM_ExecuteCommand(31, 4)
	return StackPopObject()
end

--  Equip oItem into nInventorySlot.
--  - nInventorySlot: INVENTORY_SLOT_*
--  * No return value, but if an error occurs the log file will contain
--    "ActionEquipItem failed."
-- 
--  Note: 
--        If the creature already has an item equipped in the slot specified, it will be 
--        unequipped automatically by the call to ActionEquipItem.
--      
--        In order for ActionEquipItem to succeed the creature must be able to equip the
--        item oItem normally. This means that:
--        1) The item is in the creature's inventory.
--        2) The item must already be identified (if magical). 
--        3) The creature has the level required to equip the item (if magical and ILR is on).
--        4) The creature possesses the required feats to equip the item (such as weapon proficiencies).
function ActionEquipItem(oItem, nInventorySlot)
	StackPushInteger(nInventorySlot)
	StackPushObject(oItem)
	VM_ExecuteCommand(32, 2)	
end

--  Unequip oItem from whatever slot it is currently in.
function ActionUnequipItem(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(33, 1)	
end

--  Pick up oItem from the ground.
--  * No return value, but if an error occurs the log file will contain
--    "ActionPickUpItem failed."
function ActionPickUpItem(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(34, 1)
end

--  Put down oItem on the ground.
--  * No return value, but if an error occurs the log file will contain
--    "ActionPutDownItem failed."
function ActionPutDownItem(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(35, 1)	
end

--  Get the last attacker of oAttackee.  This should only be used ONLY in the
--  OnAttacked events for creatures, placeables and doors.
--  * Return value on error: OBJECT_INVALID
function GetLastAttacker(oAttackee)
	oAttackee = oAttackee or OBJECT_SELF

	StackPushObject(oAttackee)
	VM_ExecuteCommand(36, 1)
	return StackPopObject()
end

--  Attack oAttackee.
--  - bPassive: If this is TRUE, attack is in passive mode.
function ActionAttack(oAttackee, bPassive)
	bPassive = bPassive or false

	StackPushBoolean(bPassive)
	StackPushObject(oAttackee)
	VM_ExecuteCommand(37, 2)	
end

--  Get the creature nearest to oTarget, subject to all the criteria specified.
--  - nFirstCriteriaType: CREATURE_TYPE_*
--  - nFirstCriteriaValue:
--    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
--    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
--       or CREATURE_TYPE_HAS_SPELL_EFFECT
--    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
--    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
--    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
--       CREATURE_TYPE_PLAYER_CHAR
--    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
--    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
--    For example, to get the nearest PC, use:
--    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
--  - oTarget: We're trying to find the creature of the specified type that is
--    nearest to oTarget
--  - nNth: We don't have to find the first nearest: we can find the Nth nearest...
--  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
--    further specify the type of creature that we are looking for.
--  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
--    to further specify the type of creature that we are looking for.
--  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
--    further specify the type of creature that we are looking for.
--  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
--    further specify the type of creature that we are looking for.
--  * Return value on error: OBJECT_INVALID
function GetNearestCreature(nFirstCriteriaType, nFirstCriteriaValue, oTarget, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue)
	oTarget = oTarget or OBJECT_SELF
	nNth = nNth or 1
	nSecondCriteriaType = nSecondCriteriaType or -1
	nSecondCriteriaValue = nSecondCriteriaValue or -1
	nThirdCriteriaType = nThirdCriteriaType or -1
	nThirdCriteriaValue = nThirdCriteriaValue or -1
	
	StackPushInteger(nThirdCriteriaValue)
	StackPushInteger(nThirdCriteriaType)
	StackPushInteger(nSecondCriteriaValue)
	StackPushInteger(nSecondCriteriaType)
	StackPushInteger(nNth)
	StackPushObject(oTarget)
	StackPushInteger(nFirstCriteriaValue)
	StackPushInteger(nFirstCriteriaType)
	VM_ExecuteCommand(38, 8)
	return StackPopObject()
end

--  Add a speak action to the action subject.
--  - sStringToSpeak: String to be spoken
--  - nTalkVolume: TALKVOLUME_*
function ActionSpeakString(sStringToSpeak, nTalkVolume)
	nTalkVolume = nTalkVolume or 0 --TALKVOLUME_TALK
	
	StackPushInteger(nTalkVolume)
	StackPushString(sStringToSpeak)
	VM_ExecuteCommand(39, 2)	
end

--  Cause the action subject to play an animation
--  - nAnimation: ANIMATION_*
--  - fSpeed: Speed of the animation
--  - fDurationSeconds: Duration of the animation (this is not used for Fire and
--    Forget animations)
function ActionPlayAnimation(nAnimation, fSpeed, fDurationSeconds)
	fSpeed = fSpeed or 1.0
	fDurationSeconds = fDurationSeconds or 1.0

	StackPushFloat(fDurationSeconds)
	StackPushFloat(fSpeed)
	StackPushInteger(nAnimation)
	VM_ExecuteCommand(40, 3)	
end

--  Get the distance from the caller to oObject in metres.
--  * Return value on error: -1.0f
function GetDistanceToObject(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(41, 1)
	return StackPopFloat()
end

--  * Returns TRUE if oObject is a valid object.
function GetIsObjectValid(oObject) 
	StackPushObject(oObject)
	VM_ExecuteCommand(42, 1)
	return StackPopBoolean()
end

--  Cause the action subject to open oDoor
function ActionOpenDoor(oDoor)
	StackPushObject(oDoor)
	VM_ExecuteCommand(43, 1)	
end

--  Cause the action subject to close oDoor
function ActionCloseDoor(oDoor) 
	StackPushObject(oDoor)
	VM_ExecuteCommand(44, 1)	
end

--  Change the direction in which the camera is facing
--  - fDirection is expressed as anticlockwise degrees from Due East.
--    (0.0f=East, 90.0f=North, 180.0f=West, 270.0f=South)
--  A value of -1.0f for any parameter will be ignored and instead it will
--  use the current camera value.
--  This can be used to change the way the camera is facing after the player
--  emerges from an area transition.
--  - nTransitionType: CAMERA_TRANSITION_TYPE_*  SNAP will immediately move the
--    camera to the new position, while the other types will result in the camera moving gradually into position
--  Pitch and distance are limited to valid values for the current camera mode:
--  Top Down: Distance = 5-20, Pitch = 1-50
--  Driving camera: Distance = 6 (can't be changed), Pitch = 1-62
--  Chase: Distance = 5-20, Pitch = 1-50
--  *** NOTE *** In NWN:Hordes of the Underdark the camera limits have been relaxed to the following:
--  Distance 1-25
--  Pitch 1-89
function SetCameraFacing(fDirection, fDistance, fPitch, nTransitionType)
	fDistance  = fDistance or -1.0
	fPitch  = fPitch or -1.0
	nTransitionType = nTransitionType or 0 --CAMERA_TRANSITION_TYPE_SNAP
	
	StackPushInteger(nTransitionType)
	StackPushFloat(fPitch)
	StackPushFloat(fDistance)
	StackPushFloat(fDirection)
	VM_ExecuteCommand(45, 4)	
end

--  Play sSoundName
--  - sSoundName: TBD - SS
--  This will play a mono sound from the location of the object running the command.
function PlaySound(sSoundName)
	StackPushString(sSoundName)
	VM_ExecuteCommand(46, 1)	
end

--  Get the object at which the caller last cast a spell
--  * Return value on error: OBJECT_INVALID
function GetSpellTargetObject()
	VM_ExecuteCommand(47, 0)
	return StackPopObject()
end

--  This action casts a spell at oTarget.
--  - nSpell: SPELL_*
--  - oTarget: Target for the spell
--  - nMetamagic: METAMAGIC_*
--  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
--    able to cast the spell.
--  - nDomainLevel: TBD - SS
--  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
--  - bInstantSpell: If this is TRUE, the spell is cast immediately. This allows
--    the end-user to simulate a high-level magic-user having lots of advance
--    warning of impending trouble
function ActionCastSpellAtObject(nSpell, oTarget, nMetaMagic, bCheat, nDomainLevel, nProjectilePathType, bInstantSpell)
	nMetaMagic = nMetaMagic or 255 --METAMAGIC_ANY
	bCheat = bCheat or false
	nDomainLevel = nDomainLevel or 0
	nProjectilePathType = nProjectilePathType or 0 --PROJECTILE_PATH_TYPE_DEFAULT
	bInstantSpell = bInstantSpell or false

	StackPushBoolean(bInstantSpell)
	StackPushInteger(nProjectilePathType)
	StackPushInteger(nDomainLevel)
	StackPushBoolean(bCheat)
	StackPushInteger(nMetaMagic)
	StackPushObject(oTarget)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(48, 7)
end

--  Get the current hitpoints of oObject
--  * Return value on error: 0
function GetCurrentHitPoints(oObject)
	oObject = oObject or OBJECT_SELF  
	StackPushObject(oObject)
	VM_ExecuteCommand(49, 1)
	return StackPopInteger()
end

--  Get the maximum hitpoints of oObject
--  * Return value on error: 0
function GetMaxHitPoints(oObject)
	oObject = oObject or OBJECT_SELF 
	StackPushObject(oObject)
	VM_ExecuteCommand(50, 1)
	return StackPopInteger()
end

--  Get oObject's local integer variable sVarName
--  * Return value on error: 0
function GetLocalInt(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(51, 2)
	return StackPopInteger()
end

--  Get oObject's local float variable sVarName
--  * Return value on error: 0.0f
function GetLocalFloat(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(52, 2)
	return StackPopFloat()
end

--  Get oObject's local string variable sVarName
--  * Return value on error: ""
function GetLocalString(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(53, 2)
	return StackPopString()
end

--  Get oObject's local object variable sVarName
--  * Return value on error: OBJECT_INVALID
function GetLocalObject(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(54, 2)
	return StackPopObject()
end

--  Set oObject's local integer variable sVarName to nValue
function SetLocalInt(oObject, sVarName, nValue) 
	StackPushInteger(nValue)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(55, 3)	
end

--  Set oObject's local float variable sVarName to nValue
function SetLocalFloat(oObject, sVarName, fValue)
	StackPushFloat(fValue)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(56, 3)	
end

--  Set oObject's local string variable sVarName to nValue
function SetLocalString(oObject, sVarName, sValue)
	StackPushString(sValue)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(57, 3)
end

--  Set oObject's local object variable sVarName to nValue
function SetLocalObject(oObject, sVarName, oValue)
	StackPushObject(oValue)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(58, 3)	
end

--  Get the length of sString
--  * Return value on error: -1
function GetStringLength(sString)
	StackPushString(sString)
	VM_ExecuteCommand(59, 1)
	return StackPopInteger()
end

--  Convert sString into upper case
--  * Return value on error: ""
function GetStringUpperCase(sString)
	StackPushString(sString)
	VM_ExecuteCommand(60, 1)
	return StackPopString()
end

--  Convert sString into lower case
--  * Return value on error: ""
function GetStringLowerCase(sString)
	StackPushString(sString)
	VM_ExecuteCommand(61, 1)
	return StackPopString()
end

--  Get nCount characters from the right end of sString
--  * Return value on error: ""
function GetStringRight(sString, nCount)
	StackPushInteger(nCount)
	StackPushString(sString)
	VM_ExecuteCommand(62, 2)
	return StackPopString()
end

--  Get nCounter characters from the left end of sString
--  * Return value on error: ""
function GetStringLeft(sString, nCount)
	StackPushInteger(nCount)
	StackPushString(sString)
	VM_ExecuteCommand(63, 2)
	return StackPopString()
end

--  Insert sString into sDestination at nPosition
--  * Return value on error: ""
function InsertString(sDestination, sString, nPosition)
	StackPushInteger(nPosition)
	StackPushString(sString)
	StackPushString(sDestination)
	VM_ExecuteCommand(64, 3)
	return StackPopString()
end

--  Get nCount characters from sString, starting at nStart
--  * Return value on error: ""
function GetSubString(sString, nStart, nCount)
	StackPushInteger(nCount)
	StackPushInteger(nStart)
	StackPushString(sString)
	VM_ExecuteCommand(65, 3)
	return StackPopString()
end

--  Find the position of sSubstring inside sString
--  - nStart: The character position to start searching at (from the left end of the string). 
--  * Return value on error: -1
function FindSubString(sString, sSubString, nStart)
	nStart = nStart or 0
  
	StackPushInteger(nStart)
	StackPushString(sSubString)
	StackPushString(sString)
	VM_ExecuteCommand(66, 3)
	return StackPopInteger()
end

--  math operations
--  Maths operation: absolute value of fValue
function fabs(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(67, 1)
	return StackPopFloat()
end

--  Maths operation: cosine of fValue
function cos(fValue) 
	StackPushFloat(fValue)
	VM_ExecuteCommand(68, 1)
	return StackPopFloat()
end

--  Maths operation: sine of fValue
function sin(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(69, 1)
	return StackPopFloat()
end

--  Maths operation: tan of fValue
function tan(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(70, 1)
	return StackPopFloat()
end

--  Maths operation: arccosine of fValue
--  * Returns zero if fValue > 1 or fValue < -1
function acos(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(71, 1)
	return StackPopFloat()
end

--  Maths operation: arcsine of fValue
--  * Returns zero if fValue >1 or fValue < -1
function asin(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(72, 1)
	return StackPopFloat()
end

--  Maths operation: arctan of fValue
function atan(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(73, 1)
	return StackPopFloat()
end

--  Maths operation: log of fValue
--  * Returns zero if fValue <= zero
function log(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(74, 1)
	return StackPopFloat()
end

--  Maths operation: fValue is raised to the power of fExponent
--  * Returns zero if fValue ==0 and fExponent <0
function pow(fValue, fExponent)
	StackPushFloat(fExponent)
	StackPushFloat(fValue)
	VM_ExecuteCommand(75, 2)
	return StackPopFloat()
end

--  Maths operation: square root of fValue
--  * Returns zero if fValue <0
function sqrt(fValue)
	StackPushFloat(fValue)
	VM_ExecuteCommand(76, 1)
	return StackPopFloat()
end

--  Maths operation: integer absolute value of nValue
--  * Return value on error: 0
function abs(nValue)
	StackPushInteger(nValue)
	VM_ExecuteCommand(77, 1)
	return StackPopInteger()
end

--  Create a Heal effect. This should be applied as an instantaneous effect.
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDamageToHeal < 0.
function EffectHeal(nDamageToHeal)
	StackPushInteger(nDamageToHeal)
	VM_ExecuteCommand(78, 1)
	return StackPopEffect()
end

--  Create a Damage effect
--  - nDamageAmount: amount of damage to be dealt. This should be applied as an
--    instantaneous effect.
--  - nDamageType: DAMAGE_TYPE_*
--  - nDamagePower: DAMAGE_POWER_*
function EffectDamage(nDamageAmount, nDamageType, nDamagePower)
	nDamageType = nDamageType or 8 --DAMAGE_TYPE_MAGICAL
	nDamagePower = nDamagePower or 0 --DAMAGE_POWER_NORMAL

	StackPushInteger(nDamagePower)
	StackPushInteger(nDamageType)
	StackPushInteger(nDamageAmount)
	VM_ExecuteCommand(79, 3)
	return StackPopEffect()
end

--  Create an Ability Increase effect
--  - bAbilityToIncrease: ABILITY_*
function EffectAbilityIncrease(nAbilityToIncrease, nModifyBy)
	StackPushInteger(nModifyBy)
	StackPushInteger(nAbilityToIncrease)
	VM_ExecuteCommand(80, 2)
	return StackPopEffect()
end

--  Create a Damage Resistance effect that removes the first nAmount points of
--  damage of type nDamageType, up to nLimit (or infinite if nLimit is 0)
--  - nDamageType: DAMAGE_TYPE_*
--  - nAmount
--  - nLimit
function EffectDamageResistance(nDamageType, nAmount, nLimit)
	nLimit = nLimit or 0

	StackPushInteger(nLimit)
	StackPushInteger(nAmount)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(81, 3)
	return StackPopEffect()
end

--  Create a Resurrection effect. This should be applied as an instantaneous effect.
function EffectResurrection()
	VM_ExecuteCommand(82, 0)
	return StackPopEffect()
end

--  Create a Summon Creature effect.  The creature is created and placed into the
--  caller's party/faction.
--  - sCreatureResref: Identifies the creature to be summoned
--  - nVisualEffectId: VFX_*
--  - fDelaySeconds: There can be delay between the visual effect being played, and the
--    creature being added to the area
--  - nUseAppearAnimation: should this creature play it's "appear" animation when it is
--    summoned. If zero, it will just fade in somewhere near the target.  If the value is 1
--    it will use the appear animation, and if it's 2 it will use appear2 (which doesn't exist for most creatures)
function EffectSummonCreature(sCreatureResref, nVisualEffectId, fDelaySeconds, bUseAppearAnimation)
	nVisualEffectId = nVisualEffectId or -1 --VFX_NONE
	fDelaySeconds = fDelaySeconds or 0.0
	bUseAppearAnimation = bUseAppearAnimation or false

	StackPushBoolean(bUseAppearAnimation)
	StackPushFloat(fDelaySeconds)
	StackPushInteger(nVisualEffectId)
	StackPushString(sCreatureResref)
	VM_ExecuteCommand(83, 4)
	return StackPopEffect()
end

--  Get the level at which this creature cast it's last spell (or spell-like ability)
--  * Return value on error, or if oCreature has not yet cast a spell: 0
function GetCasterLevel(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(84, 1)
	return StackPopInteger()
end

--  Get the first in-game effect on oCreature.
function GetFirstEffect(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(85, 1)
	return StackPopEffect()
end

--  Get the next in-game effect on oCreature.
function GetNextEffect(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(86, 1)
	return StackPopEffect()
end

--  Remove eEffect from oCreature.
--  * No return value
function RemoveEffect(oCreature, eEffect)
	StackPushEffect(eEffect)
	StackPushObject(oCreature)
	VM_ExecuteCommand(87, 2)	
end

--  * Returns TRUE if eEffect is a valid effect. The effect must have been applied to
--  * an object or else it will return FALSE
function GetIsEffectValid(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(88, 1)
	return StackPopBoolean()
end

--  Get the duration type (DURATION_TYPE_*) of eEffect.
--  * Return value if eEffect is not valid: -1
function GetEffectDurationType(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(89, 1)
	return StackPopInteger()
end

--  Get the subtype (SUBTYPE_*) of eEffect.
--  * Return value on error: 0
function GetEffectSubType(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(90, 1)
	return StackPopInteger()
end

--  Get the object that created eEffect.
--  * Returns OBJECT_INVALID if eEffect is not a valid effect.
function GetEffectCreator(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(91, 1)
	return StackPopObject()
end

--  Convert nInteger into a string.
--  * Return value on error: ""
function IntToString(nInteger)
	StackPushInteger(nInteger)
	VM_ExecuteCommand(92, 1)
	return StackPopString()
end

--  Get the first object in oArea.
--  If no valid area is specified, it will use the caller's area.
--  * Return value on error: OBJECT_INVALID
function GetFirstObjectInArea(oArea)
	oArea = oArea or OBJECT_INVALID
  
	StackPushObject(oArea)
	VM_ExecuteCommand(93, 1)
	return StackPopObject()
end

--  Get the next object in oArea.
--  If no valid area is specified, it will use the caller's area.
--  * Return value on error: OBJECT_INVALID
function GetNextObjectInArea(oArea)
	oArea = oArea or OBJECT_INVALID
  
	StackPushObject(oArea)
	VM_ExecuteCommand(94, 1)
	return StackPopObject()
end

--  Get the total from rolling (nNumDice x d2 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d2(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(95, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d3 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d3(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(96, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d4 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d4(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(97, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d6 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d6(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(98, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d8 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d8(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(99, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d10 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d10(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(100, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d12 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d12(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(101, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d20 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d20(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(102, 1)
	return StackPopInteger()
end

--  Get the total from rolling (nNumDice x d100 dice).
--  - nNumDice: If this is less than 1, the value 1 will be used.
function d100(nNumDice)
	nNumDice = nNumDice or 1
  
	StackPushInteger(nNumDice)
	VM_ExecuteCommand(103, 1)
	return StackPopInteger()
end

--  Get the magnitude of vVector this can be used to determine the
--  distance between two points.
--  * Return value on error: 0.0f
function VectorMagnitude(vVector)
	StackPushVector(vVector)
	VM_ExecuteCommand(104, 1)
	return StackPopFloat()
end

--  Get the metamagic type (METAMAGIC_*) of the last spell cast by the caller
--  * Return value if the caster is not a valid object: -1
function GetMetaMagicFeat()
	VM_ExecuteCommand(105, 0)
	return StackPopInteger()
end

--  Get the object type (OBJECT_TYPE_*) of oTarget
--  * Return value if oTarget is not a valid object: -1
function GetObjectType(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(106, 1)
	return StackPopInteger()
end

--  Get the racial type (RACIAL_TYPE_*) of oCreature
--  * Return value if oCreature is not a valid creature: RACIAL_TYPE_INVALID
function GetRacialType(oCreature) 
	StackPushObject(oCreature)
	VM_ExecuteCommand(107, 1)
	return StackPopInteger()
end

--  Do a Fortitude Save check for the given DC
--  - oCreature
--  - nDC: Difficulty check
--  - nSaveType: SAVING_THROW_TYPE_*
--  - oSaveVersus
--  Returns: 0 if the saving throw roll failed
--  Returns: 1 if the saving throw roll succeeded
--  Returns: 2 if the target was immune to the save type specified
--  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
--  GetAreaOfEffectCreator() into oSaveVersus!!
function FortitudeSave(oCreature, nDC, nSaveType, oSaveVersus)
	nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_NONE
	oSaveVersus = oSaveVersus or OBJECT_SELF

	StackPushObject(oSaveVersus)
	StackPushInteger(nSaveType)
	StackPushInteger(nDC)
	StackPushObject(oCreature)
	VM_ExecuteCommand(108, 4)
	return StackPopInteger()
end

--  Does a Reflex Save check for the given DC
--  - oCreature
--  - nDC: Difficulty check
--  - nSaveType: SAVING_THROW_TYPE_*
--  - oSaveVersus
--  Returns: 0 if the saving throw roll failed
--  Returns: 1 if the saving throw roll succeeded
--  Returns: 2 if the target was immune to the save type specified
--  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
--  GetAreaOfEffectCreator() into oSaveVersus!!
function ReflexSave(oCreature, nDC, nSaveType, oSaveVersus)
	nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_NONE
	oSaveVersus = oSaveVersus or OBJECT_SELF

	StackPushObject(oSaveVersus)
	StackPushInteger(nSaveType)
	StackPushInteger(nDC)
	StackPushObject(oCreature)
	VM_ExecuteCommand(109, 4)
	return StackPopInteger()
end

--  Does a Will Save check for the given DC
--  - oCreature
--  - nDC: Difficulty check
--  - nSaveType: SAVING_THROW_TYPE_*
--  - oSaveVersus
--  Returns: 0 if the saving throw roll failed
--  Returns: 1 if the saving throw roll succeeded
--  Returns: 2 if the target was immune to the save type specified
--  Note: If used within an Area of Effect Object Script (On Enter, OnExit, OnHeartbeat), you MUST pass
--  GetAreaOfEffectCreator() into oSaveVersus!!
function WillSave(oCreature, nDC, nSaveType, oSaveVersus)
	nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_NONE
	oSaveVersus = oSaveVersus or OBJECT_SELF
	
	StackPushObject(oSaveVersus)
	StackPushInteger(nSaveType)
	StackPushInteger(nDC)
	StackPushObject(oCreature)
	VM_ExecuteCommand(110, 4)
	return StackPopInteger()
end

--  Get the DC to save against for a spell (10 + spell level + relevant ability
--  bonus).  This can be called by a creature or by an Area of Effect object.
function GetSpellSaveDC()
	VM_ExecuteCommand(111, 0)
	return StackPopInteger()
end

--  Set the subtype of eEffect to Magical and return eEffect.
--  (Effects default to magical if the subtype is not set)
--  Magical effects are removed by resting, and by dispel magic
function MagicalEffect(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(112, 1)
	return StackPopEffect()
end

--  Set the subtype of eEffect to Supernatural and return eEffect.
--  (Effects default to magical if the subtype is not set)
--  Permanent supernatural effects are not removed by resting
function SupernaturalEffect(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(113, 1)
	return StackPopEffect()
end

--  Set the subtype of eEffect to Extraordinary and return eEffect.
--  (Effects default to magical if the subtype is not set)
--  Extraordinary effects are removed by resting, but not by dispel magic
function ExtraordinaryEffect(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(114, 1)
	return StackPopEffect()
end

--  Create an AC Increase effect
--  - nValue: size of AC increase
--  - nModifyType: AC_*_BONUS
--  - nDamageType: DAMAGE_TYPE_*
--    * Default value for nDamageType should only ever be used in this function prototype.
function EffectACIncrease(nValue, nModifyType, nDamageType)
	nModifyType = nModifyType or 0 --AC_DODGE_BONUS
	nDamageType = nDamageType or 4103 --AC_VS_DAMAGE_TYPE_ALL
	
	StackPushInteger(nDamageType)
	StackPushInteger(nModifyType)
	StackPushInteger(nValue)
	VM_ExecuteCommand(115, 3)
	return StackPopEffect()
end

--  If oObject is a creature, this will return that creature's armour class
--  If oObject is an item, door or placeable, this will return zero.
--  - nForFutureUse: this parameter is not currently used
--  * Return value if oObject is not a creature, item, door or placeable: -1
function GetAC(oObject, nForFutureUse)
	nForFutureUse = nForFutureUse or 0

	StackPushInteger(nForFutureUse)
	StackPushObject(oObject)
	VM_ExecuteCommand(116, 2)
	return StackPopInteger()
end

--  Create a Saving Throw Increase effect
--  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
--           SAVING_THROW_ALL
--           SAVING_THROW_FORT
--           SAVING_THROW_REFLEX
--           SAVING_THROW_WILL 
--  - nValue: size of the Saving Throw increase
--  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
function EffectSavingThrowIncrease(nSave, nValue, nSaveType)
    nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_ALL

    StackPushInteger(nSaveType)
    StackPushInteger(nValue)
    StackPushInteger(nSave)
    VM_ExecuteCommand(117, 3)
    return StackPopEffect()
end

--  Create an Attack Increase effect
--  - nBonus: size of attack bonus
--  - nModifierType: ATTACK_BONUS_*
function EffectAttackIncrease(nBonus, nModifierType)
	nModifierType = nModifierType or 0 --ATTACK_BONUS_MISC

	StackPushInteger(nModifierType)
	StackPushInteger(nBonus)
	VM_ExecuteCommand(118, 2)
	return StackPopEffect()
end

--  Create a Damage Reduction effect
--  - nAmount: amount of damage reduction
--  - nDamagePower: DAMAGE_POWER_*
--  - nLimit: How much damage the effect can absorb before disappearing.
--    Set to zero for infinite
function EffectDamageReduction(nAmount, nDamagePower, nLimit)
	nLimit = nLimit or 0

	StackPushInteger(nLimit)
	StackPushInteger(nDamagePower)
	StackPushInteger(nAmount)
	VM_ExecuteCommand(119, 3)
	return StackPopEffect()
end

--  Create a Damage Increase effect
--  - nBonus: DAMAGE_BONUS_*
--  - nDamageType: DAMAGE_TYPE_*
--  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
--        result in odd behaviour.
function EffectDamageIncrease(nBonus, nDamageType)
	nDamageType = nDamageType or 8 --DAMAGE_TYPE_MAGICAL

	StackPushInteger(nDamageType)
	StackPushInteger(nBonus)
	VM_ExecuteCommand(120, 2)
	return StackPopEffect()
end

--  Convert nRounds into a number of seconds
--  A round is always 6.0 seconds
function RoundsToSeconds(nRounds)
	StackPushInteger(nRounds)
	VM_ExecuteCommand(121, 1)
	return StackPopFloat()
end

--  Convert nHours into a number of seconds
--  The result will depend on how many minutes there are per hour (game-time)
function HoursToSeconds(nHours)
	StackPushInteger(nHours)
	VM_ExecuteCommand(122, 1)
	return StackPopFloat()
end

--  Convert nTurns into a number of seconds
--  A turn is always 60.0 seconds
function TurnsToSeconds(nTurns)
	StackPushInteger(nTurns)
	VM_ExecuteCommand(123, 1)
	return StackPopFloat()
end

--  Get an integer between 0 and 100 (inclusive) to represent oCreature's
--  Law/Chaos alignment
--  (100=law, 0=chaos)
--  * Return value if oCreature is not a valid creature: -1
function GetLawChaosValue(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(124, 1)
	return StackPopInteger()
end

--  Get an integer between 0 and 100 (inclusive) to represent oCreature's
--  Good/Evil alignment
--  (100=good, 0=evil)
--  * Return value if oCreature is not a valid creature: -1
function GetGoodEvilValue(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(125, 1)
	return StackPopInteger()
end

--  Return an ALIGNMENT_* constant to represent oCreature's law/chaos alignment
--  * Return value if oCreature is not a valid creature: -1
function GetAlignmentLawChaos(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(126, 1)
	return StackPopInteger()
end

--  Return an ALIGNMENT_* constant to represent oCreature's good/evil alignment
--  * Return value if oCreature is not a valid creature: -1
function GetAlignmentGoodEvil(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(127, 1)
	return StackPopInteger()
end

--  Create an Entangle effect
--  When applied, this effect will restrict the creature's movement and apply a
--  (-2) to all attacks and a -4 to AC.
function EffectEntangle()
	VM_ExecuteCommand(130, 0)
	return StackPopEffect()
end

--  Causes object oObject to run the event evToRun. The script on the object that is
--  associated with the event specified will run.
--  Events can be created using the following event functions:
--     EventActivateItem() - This creates an OnActivateItem module event. The script for handling
--                           this event can be set in Module Properties on the Event Tab.
--     EventConversation() - This creates on OnConversation creature event. The script for handling
--                           this event can be set by viewing the Creature Properties on a 
--                           creature and then clicking on the Scripts Tab.
--     EventSpellCastAt()  - This creates an OnSpellCastAt event. The script for handling this
--                           event can be set in the Scripts Tab of the Properties menu 
--                           for the object.
--     EventUserDefined()  - This creates on OnUserDefined event. The script for handling this event
--                           can be set in the Scripts Tab of the Properties menu for the object/area/module.
function SignalEvent(oObject, eEvent)
  	StackPushEvent(eEvent)
	StackPushObject(oObject)
	VM_ExecuteCommand(131, 2)	
end

--  Create an event of the type nUserDefinedEventNumber
--  Note: This only creates the event. The event wont actually trigger until SignalEvent()
--  is called using this created UserDefined event as an argument.
--  For example:
--      SignalEvent(oObject, EventUserDefined(9999))
--  Once the event has been signaled. The script associated with the OnUserDefined event will
--  run on the object oObject.
-- 
--  To specify the OnUserDefined script that should run, view the object's Properties
--  and click on the Scripts Tab. Then specify a script for the OnUserDefined event.
--  From inside the OnUserDefined script call:
--     GetUserDefinedEventNumber() to retrieve the value of nUserDefinedEventNumber
--     that was used when the event was signaled.
function EventUserDefined(nUserDefinedEventNumber)
	StackPushInteger(nUserDefinedEventNumber)
	VM_ExecuteCommand(132, 1)
	return StackPopEvent()
end

--  Create a Death effect
--  - nSpectacularDeath: if this is TRUE, the creature to which this effect is
--    applied will die in an extraordinary fashion
--  - nDisplayFeedback
function EffectDeath(bSpectacularDeath, bDisplayFeedback)
	bSpectacularDeath = bSpectacularDeath or false
	if bDisplayFeedback == nil then bDisplayFeedback = true end

	StackPushBoolean(bDisplayFeedback)
	StackPushBoolean(bSpectacularDeath)
	VM_ExecuteCommand(133, 2)
	return StackPopEffect()
end

--  Create a Knockdown effect
--  This effect knocks creatures off their feet, they will sit until the effect
--  is removed. This should be applied as a temporary effect with a 3 second
--  duration minimum (1 second to fall, 1 second sitting, 1 second to get up).
function EffectKnockdown()
	VM_ExecuteCommand(134, 0)
	return StackPopEffect()
end

--  Give oItem to oGiveTo
--  If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
--  happen.
function ActionGiveItem(oItem, oGiveTo)  
	StackPushObject(oGiveTo)
	StackPushObject(oItem)
	VM_ExecuteCommand(135, 2)
end

--  Take oItem from oTakeFrom
--  If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
--  will happen.
function ActionTakeItem(oItem, oTakeFrom)
	StackPushObject(oTakeFrom)
	StackPushObject(oItem)
	VM_ExecuteCommand(136, 2)	
end

--  Normalize vVector
function VectorNormalize(vVector)
	StackPushVector(vVector)
	VM_ExecuteCommand(137, 1)
	return StackPopVector()
end

--  Create a Curse effect.
--  - nStrMod: strength modifier
--  - nDexMod: dexterity modifier
--  - nConMod: constitution modifier
--  - nIntMod: intelligence modifier
--  - nWisMod: wisdom modifier
--  - nChaMod: charisma modifier
function EffectCurse(nStrMod, nDexMod, nConMod, nIntMod, nWisMod, nChaMod)
	nStrMod = nStrMod or 1
	nDexMod = nDexMod or 1
	nConMod = nConMod or 1
	nIntMod = nIntMod or 1
	nWisMod = nWisMod or 1
	nChaMod = nChaMod or 1

	StackPushInteger(nChaMod)
	StackPushInteger(nWisMod)
	StackPushInteger(nIntMod)
	StackPushInteger(nConMod)
	StackPushInteger(nDexMod)
	StackPushInteger(nStrMod)
	VM_ExecuteCommand(138, 6)
	return StackPopEffect()
end

--  Get the ability score of type nAbility for a creature (otherwise 0)
--  - oCreature: the creature whose ability score we wish to find out
--  - nAbilityType: ABILITY_*
--  - nBaseAbilityScore: if set to true will return the base ability score without
--                       bonuses (e.g. ability bonuses granted from equipped items).
--  Return value on error: 0
function GetAbilityScore(oCreature, nAbilityType, bBaseAbilityScore)
	bBaseAbilityScore = bBaseAbilityScore or false

	StackPushBoolean(bBaseAbilityScore)
	StackPushInteger(nAbilityType)
	StackPushObject(oCreature)
	VM_ExecuteCommand(139, 3)
	return StackPopInteger()
end

--  * Returns TRUE if oCreature is a dead NPC, dead PC or a dying PC.
function GetIsDead(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(140, 1)
	return StackPopBoolean()
end

--  Output vVector to the logfile.
--  - vVector
--  - bPrepend: if this is TRUE, the message will be prefixed with "PRINTVECTOR:"
function PrintVector(vVector, bPrepend)
	StackPushBoolean(bPrepend)
	StackPushVector(vVector)
	VM_ExecuteCommand(141, 2)
end

--  Create a vector with the specified values for x, y and z
function Vector(x, y, z)
	x = x or 0.0
	y = y or 0.0
	z = z or 0.0

	StackPushFloat(z)
	StackPushFloat(y)
	StackPushFloat(x)
	VM_ExecuteCommand(142, 3)
	return StackPopVector()
end

--  Cause the caller to face vTarget
function SetFacingPoint(vTarget)
	StackPushVector(vTarget)
	VM_ExecuteCommand(143, 1)	
end

--  Convert fAngle to a vector
function AngleToVector(fAngle)
	StackPushFloat(fAngle)
	VM_ExecuteCommand(144, 1)
	return StackPopVector()
end

--  Convert vVector to an angle
function VectorToAngle(vVector)
	StackPushVector(vVector)
	VM_ExecuteCommand(145, 1)
	return StackPopFloat()
end

--  The caller will perform a Melee Touch Attack on oTarget
--  This is not an action, and it assumes the caller is already within range of
--  oTarget
--  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
function TouchAttackMelee(oTarget, bDisplayFeedback)
	if bDisplayFeedback == nil then bDisplayFeedback = true end

	StackPushBoolean(bDisplayFeedback)
	StackPushObject(oTarget)
	VM_ExecuteCommand(146, 2)
	return StackPopInteger()
end

--  The caller will perform a Ranged Touch Attack on oTarget
--  * Returns 0 on a miss, 1 on a hit and 2 on a critical hit
function TouchAttackRanged(oTarget, bDisplayFeedback)
	if bDisplayFeedback == nil then bDisplayFeedback = true end

	StackPushBoolean(bDisplayFeedback)
	StackPushObject(oTarget)
	VM_ExecuteCommand(147, 2)
	return StackPopInteger()
end

--  Create a Paralyze effect
function EffectParalyze()
	VM_ExecuteCommand(148, 0)
	return StackPopEffect()
end

--  Create a Spell Immunity effect.
--  There is a known bug with this function. There *must* be a parameter specified
--  when this is called (even if the desired parameter is SPELL_ALL_SPELLS),
--  otherwise an effect of type EFFECT_TYPE_INVALIDEFFECT will be returned.
--  - nImmunityToSpell: SPELL_*
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nImmunityToSpell is
--    invalid.
function EffectSpellImmunity(nImmunityToSpell)
	nImmunityToSpell = nImmunityToSpell or -1 --SPELL_ALL_SPELLS

	StackPushInteger(nImmunityToSpell)
	VM_ExecuteCommand(149, 1)
	return StackPopEffect()
end

--  Create a Deaf effect
function EffectDeaf()
	VM_ExecuteCommand(150, 0)
	return StackPopEffect()
end

--  Get the distance in metres between oObjectA and oObjectB.
--  * Return value if either object is invalid: 0.0f
function GetDistanceBetween(oObjectA, oObjectB) 
	StackPushObject(oObjectB)
	StackPushObject(oObjectA)
	VM_ExecuteCommand(151, 2)
	return StackPopFloat()
end

--  Set oObject's local location variable sVarname to lValue
function SetLocalLocation(oObject, sVarName, lValue)
	StackPushLocation(lValue)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(152, 3)	
end

--  Get oObject's local location variable sVarname
function GetLocalLocation(oObject, sVarName) 
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(153, 2)
	return StackPopLocation()
end

--  Create a Sleep effect
function EffectSleep()
	VM_ExecuteCommand(154, 0)
	return StackPopEffect()
end

--  Get the object which is in oCreature's specified inventory slot
--  - nInventorySlot: INVENTORY_SLOT_*
--  - oCreature
--  * Returns OBJECT_INVALID if oCreature is not a valid creature or there is no
--    item in nInventorySlot.
function GetItemInSlot(nInventorySlot, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushInteger(nInventorySlot)
	VM_ExecuteCommand(155, 2)
	return StackPopObject()
end

--  Create a Charm effect
function EffectCharmed()
	VM_ExecuteCommand(156, 0)
	return StackPopEffect()
end

--  Create a Confuse effect
function EffectConfused()
	VM_ExecuteCommand(157, 0)
	return StackPopEffect()
end

--  Create a Frighten effect
function EffectFrightened()
	VM_ExecuteCommand(158, 0)
	return StackPopEffect()
end

--  Create a Dominate effect
function EffectDominated()
	VM_ExecuteCommand(159, 0)
	return StackPopEffect()
end

--  Create a Daze effect
function EffectDazed()
	VM_ExecuteCommand(160, 0)
	return StackPopEffect()
end

--  Create a Stun effect
function EffectStunned()
	VM_ExecuteCommand(161, 0)
	return StackPopEffect()
end

--  Set whether oTarget's action stack can be modified
function SetCommandable(bCommandable, oTarget)
	oTarget = oTarget or OBJECT_SELF

	StackPushObject(oTarget)
	StackPushBoolean(bCommandable)
	VM_ExecuteCommand(162, 2)
end

--  Determine whether oTarget's action stack can be modified.
function GetCommandable()
	oTarget = oTarget or OBJECT_SELF

	StackPushObject(oTarget)
	VM_ExecuteCommand(163, 1)
	return StackPopInteger()
end

--  Create a Regenerate effect.
--  - nAmount: amount of damage to be regenerated per time interval
--  - fIntervalSeconds: length of interval in seconds
function EffectRegenerate(nAmount, fIntervalSeconds)
	StackPushFloat(fIntervalSeconds)
	StackPushInteger(nAmount)
	VM_ExecuteCommand(164, 2)
	return StackPopEffect()
end

--  Create a Movement Speed Increase effect.
--  - nPercentChange - range 0 through 99
--  eg.
--     0 = no change in speed
--    50 = 50% faster
--    99 = almost twice as fast
function EffectMovementSpeedIncrease(nPercentChange)
	StackPushInteger(nPercentChange)
	VM_ExecuteCommand(165, 1)
	return StackPopEffect()
end

--  Get the number of hitdice for oCreature.
--  * Return value if oCreature is not a valid creature: 0
function GetHitDice(oCreature) 
	StackPushObject(oCreature)
	VM_ExecuteCommand(166, 1)
	return StackPopInteger()
end

--  The action subject will follow oFollow until a ClearAllActions() is called.
--  - oFollow: this is the object to be followed
--  - fFollowDistance: follow distance in metres
--  * No return value
function ActionForceFollowObject(oFollow, fFollowDistance)
	fFollowDistance = fFollowDistance or 0.0

	StackPushFloat(fFollowDistance)
	StackPushObject(oFollow)
	VM_ExecuteCommand(167, 2)	
end

--  Get the Tag of oObject
--  * Return value if oObject is not a valid object: ""
function GetTag(oCreature) 
	StackPushObject(oCreature)
	VM_ExecuteCommand(168, 1)
	return StackPopString()
end

--  Do a Spell Resistance check between oCaster and oTarget, returning TRUE if
--  the spell was resisted.
--  * Return value if oCaster or oTarget is an invalid object: FALSE
--  * Return value if spell cast is not a player spell: - 1
--  * Return value if spell resisted: 1
--  * Return value if spell resisted via magic immunity: 2
--  * Return value if spell resisted via spell absorption: 3
function ResistSpell(oCaster, oTarget)
	StackPushObject(oTarget)
	StackPushObject(oCaster)
	VM_ExecuteCommand(169, 2)
	return StackPopInteger()
end

--  Get the effect type (EFFECT_TYPE_*) of eEffect.
--  * Return value if eEffect is invalid: EFFECT_INVALIDEFFECT
function GetEffectType(eEffect) 
	StackPushEffect(eEffect)
	VM_ExecuteCommand(170, 1)
	return StackPopInteger()
end

--  Create an Area Of Effect effect in the area of the creature it is applied to.
--  If the scripts are not specified, default ones will be used.
function EffectAreaOfEffect(nAreaEffectId, sOnEnterScript, sHeartbeatScript, sOnExitScript)
	sOnEnterScript = sOnEnterScript or ""
	sHeartbeatScript = sHeartbeatScript or ""
	sOnExitScript = sOnExitScript or ""
	
	StackPushString(sOnExitScript)
	StackPushString(sHeartbeatScript)
	StackPushString(sOnEnterScript)
	StackPushInteger(nAreaEffectId)
	VM_ExecuteCommand(171, 4)
	return StackPopEffect()
end

--  * Returns TRUE if the Faction Ids of the two objects are the same
function GetFactionEqual(oFirstObject, oSecondObject)
	oSecondObject = oSecondObject or OBJECT_SELF
	
	StackPushObject(oSecondObject)
	StackPushObject(oFirstObject)
	VM_ExecuteCommand(172, 2)
	return StackPopBoolean()
end

--  Make oObjectToChangeFaction join the faction of oMemberOfFactionToJoin.
--  NB. ** This will only work for two NPCs **
function ChangeFaction(oObjectToChangeFaction, oMemberOfFactionToJoin)
	StackPushObject(oMemberOfFactionToJoin)
	StackPushObject(oObjectToChangeFaction)
	VM_ExecuteCommand(173, 2)
end

--  * Returns TRUE if oObject is listening for something
function GetIsListening(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(174, 1)
	return StackPopBoolean()
end

--  Set whether oObject is listening.
function SetListening(oObject, bValue)
 	StackPushBoolean(bValue)
	StackPushObject(oObject)
	VM_ExecuteCommand(175, 2)
end

--  Set the string for oObject to listen for.
--  Note: this does not set oObject to be listening.
function SetListenPattern(oObject, sPattern, nNumber)
	nNumber = nNumber or 0

	StackPushInteger(nNumber)
	StackPushString(sPattern)
	StackPushObject(oObject)
	VM_ExecuteCommand(176, 3)
end

--  * Returns TRUE if sStringToTest matches sPattern.
function TestStringAgainstPattern(sPattern, sStringToTest)
	StackPushString(sStringToTest)
	StackPushString(sPattern)
	VM_ExecuteCommand(177, 2)
	return StackPopBoolean()
end

--  Get the appropriate matched string (this should only be used in
--  OnConversation scripts).
--  * Returns the appropriate matched string, otherwise returns ""
function GetMatchedSubstring(nString) 
 	StackPushInteger(nString)
	VM_ExecuteCommand(178, 1)
	return StackPopString()
end

--  Get the number of string parameters available.
--  * Returns -1 if no string matched (this could be because of a dialogue event)
function GetMatchedSubstringsCount()
	VM_ExecuteCommand(179, 0)
	return StackPopInteger()
end

--  * Create a Visual Effect that can be applied to an object.
--  - nVisualEffectId
--  - nMissEffect: if this is TRUE, a random vector near or past the target will
--    be generated, on which to play the effect
function EffectVisualEffect(nVisualEffectId, bMissEffect)
	bMissEffect = bMissEffect or false
	
	StackPushBoolean(nMissEffect)
	StackPushInteger(nVisualEffectId)
	VM_ExecuteCommand(180, 2)
	return StackPopEffect()
end

--  Get the weakest member of oFactionMember's faction.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionWeakestMember(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end

	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(181, 2)
	return StackPopObject()
end

--  Get the strongest member of oFactionMember's faction.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionStrongestMember(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end
	
	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(182, 2)
	return StackPopObject()
end

--  Get the member of oFactionMember's faction that has taken the most hit points
--  of damage.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionMostDamagedMember(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end
	
	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(183, 2)
	return StackPopObject()
end

--  Get the member of oFactionMember's faction that has taken the fewest hit
--  points of damage.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionLeastDamagedMember(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end
	
	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(184, 2)
	return StackPopObject()
end

--  Get the amount of gold held by oFactionMember's faction.
--  * Returns -1 if oFactionMember's faction is invalid.
function GetFactionGold(oFactionMember)
  	StackPushObject(oFactionMember)
	VM_ExecuteCommand(185, 1)
	return StackPopInteger()
end

--  Get an integer between 0 and 100 (inclusive) that represents how
--  oSourceFactionMember's faction feels about oTarget.
--  * Return value on error: -1
function GetFactionAverageReputation(oSourceFactionMember, oTarget)
 	StackPushObject(oTarget)
	StackPushObject(oSourceFactionMember)
	VM_ExecuteCommand(186, 2)
	return StackPopInteger()
end

--  Get an integer between 0 and 100 (inclusive) that represents the average
--  good/evil alignment of oFactionMember's faction.
--  * Return value on error: -1
function GetFactionAverageGoodEvilAlignment(oFactionMember)
 	StackPushObject(oFactionMember)
	VM_ExecuteCommand(187, 1)
	return StackPopInteger()
end

--  Get an integer between 0 and 100 (inclusive) that represents the average
--  law/chaos alignment of oFactionMember's faction.
--  * Return value on error: -1
function GetFactionAverageLawChaosAlignment(oFactionMember)  
 	StackPushObject(oFactionMember)
	VM_ExecuteCommand(188, 1)
	return StackPopInteger()
end

--  Get the average level of the members of the faction.
--  * Return value on error: -1
function GetFactionAverageLevel(oFactionMember)  
 	StackPushObject(oFactionMember)
	VM_ExecuteCommand(189, 1)
	return StackPopInteger()
end

--  Get the average XP of the members of the faction.
--  * Return value on error: -1
function GetFactionAverageXP(oFactionMember) 
 	StackPushObject(oFactionMember)
	VM_ExecuteCommand(190, 1)
	return StackPopInteger()
end

--  Get the most frequent class in the faction - this can be compared with the
--  constants CLASS_TYPE_*.
--  * Return value on error: -1
function GetFactionMostFrequentClass(oFactionMember) 
 	StackPushObject(oFactionMember)
	VM_ExecuteCommand(191, 1)
	return StackPopInteger()
end

--  Get the object faction member with the lowest armour class.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionWorstAC(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end
	
	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(192, 2)
	return StackPopObject()
end

--  Get the object faction member with the highest armour class.
--  * Returns OBJECT_INVALID if oFactionMember's faction is invalid.
function GetFactionBestAC(oFactionMember, bMustBeVisible)
	oFactionMember = oFactionMember or OBJECT_SELF
	if bMustBeVisible == nil then bMustBeVisible = true end
	
	StackPushBoolean(bMustBeVisible)
	StackPushObject(oFactionMember)
	VM_ExecuteCommand(193, 2)
	return StackPopObject()
end

--  Sit in oChair.
--  Note: Not all creatures will be able to sit and not all
--        objects can be sat on.
--        The object oChair must also be marked as usable in the toolset.
-- 
--  For Example: To get a player to sit in oChair when they click on it,
--  place the following script in the OnUsed event for the object oChair.
--  void main()
--  {
--     object oChair = OBJECT_SELF
--     AssignCommand(GetLastUsedBy(),ActionSit(oChair))
--  end
function ActionSit(oChair) 
 	StackPushObject(oChair)
	VM_ExecuteCommand(194, 1)
end

--  In an onConversation script this gets the number of the string pattern
--  matched (the one that triggered the script).
--  * Returns -1 if no string matched
function GetListenPatternNumber()
	VM_ExecuteCommand(195, 0)
	return StackPopInteger()
end

--  Jump to an object ID, or as near to it as possible.
function ActionJumpToObject(oToJumpTo, bWalkStraightLineToPoint)
	if bWalkStraightLineToPoint == nil then bWalkStraightLineToPoint = true end

	StackPushBoolean(bWalkStraightLineToPoint)
	StackPushObject(oToJumpTo)
	VM_ExecuteCommand(196, 2)	
end

--  Get the first waypoint with the specified tag.
--  * Returns OBJECT_INVALID if the waypoint cannot be found.
function GetWaypointByTag(sWaypointTag) 
 	StackPushString(sWaypointTag)
	VM_ExecuteCommand(197, 1)
	return StackPopObject()
end

--  Get the destination object for the given object.
-- 
--  All objects can hold a transition target, but only Doors and Triggers
--  will be made clickable by the game engine (This may change in the
--  future). You can set and query transition targets on other objects for
--  your own scripted purposes.
-- 
--  * Returns OBJECT_INVALID if oTransition does not hold a target.
function GetTransitionTarget(oTransition)  
 	StackPushObject(oTransition)
	VM_ExecuteCommand(198, 1)
	return StackPopObject()
end

--  Link the two supplied effects, returning eChildEffect as a child of
--  eParentEffect.
--  Note: When applying linked effects if the target is immune to all valid
--  effects all other effects will be removed as well. This means that if you
--  apply a visual effect and a silence effect (in a link) and the target is
--  immune to the silence effect that the visual effect will get removed as well.
--  Visual Effects are not considered "valid" effects for the purposes of
--  determining if an effect will be removed or not and as such should never be
--  packaged *only* with other visual effects in a link.
function EffectLinkEffects(eChildEffect, eParentEffect)
 	StackPushEffect(eParentEffect)
	StackPushEffect(eChildEffect)
	VM_ExecuteCommand(199, 2)
	return StackPopEffect()
end

--  Get the nNth object with the specified tag.
--  - sTag
--  - nNth: the nth object with this tag may be requested
--  * Returns OBJECT_INVALID if the object cannot be found.
--  Note: The module cannot be retrieved by GetObjectByTag(), use GetModule() instead.
function GetObjectByTag(sTag, nNth)
	nNth = nNth or 0
	
	StackPushInteger(nNth)
	StackPushString(sTag)
	VM_ExecuteCommand(200, 2)
	return StackPopObject()
end

--  Adjust the alignment of oSubject.
--  - oSubject
--  - nAlignment:
--    -> ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_GOOD/ALIGNMENT_EVIL: oSubject's
--       alignment will be shifted in the direction specified
--    -> ALIGNMENT_ALL: nShift will be added to oSubject's law/chaos and
--       good/evil alignment values
--    -> ALIGNMENT_NEUTRAL: nShift is applied to oSubject's law/chaos and
--       good/evil alignment values in the direction which is towards neutrality.
--      e.g. If oSubject has a law/chaos value of 10 (i.e. chaotic) and a
--           good/evil value of 80 (i.e. good) then if nShift is 15, the
--           law/chaos value will become (10+15)=25 and the good/evil value will
--           become (80-25)=55
--      Furthermore, the shift will at most take the alignment value to 50 and
--      not beyond.
--      e.g. If oSubject has a law/chaos value of 40 and a good/evil value of 70,
--           then if nShift is 15, the law/chaos value will become 50 and the
--           good/evil value will become 55
--  - nShift: this is the desired shift in alignment
--  - bAllPartyMembers: when TRUE the alignment shift of oSubject also has a 
--                      diminished affect all members of oSubject's party (if oSubject is a Player).
--                      When FALSE the shift only affects oSubject.
--  * No return value
function AdjustAlignment(oSubject, nAlignment, nShift, bAllPartyMembers)
	if bAllPartyMembers == nil then bAllPartyMembers = true end

	StackPushBoolean(bAllPartyMembers)
	StackPushInteger(nShift)
	StackPushInteger(nAlignment)
	StackPushObject(oSubject)
	VM_ExecuteCommand(201, 4)
end

--  Do nothing for fSeconds seconds.
function ActionWait(fSeconds)
  	StackPushFloat(fSeconds)
	VM_ExecuteCommand(202, 1)
end

--  Set the transition bitmap of a player this should only be called in area
--  transition scripts. This action should be run by the person "clicking" the
--  area transition via AssignCommand.
--  - nPredefinedAreaTransition:
--    -> To use a predefined area transition bitmap, use one of AREA_TRANSITION_*
--    -> To use a custom, user-defined area transition bitmap, use
--       AREA_TRANSITION_USER_DEFINED and specify the filename in the second
--       parameter
--  - sCustomAreaTransitionBMP: this is the filename of a custom, user-defined
--    area transition bitmap
function SetAreaTransitionBMP(nPredefinedAreaTransition, sCustomAreaTransitionBMP)
	sCustomAreaTransitionBMP = sCustomAreaTransitionBMP or ""

	StackPushString(sCustomAreaTransitionBMP)
	StackPushInteger(nPredefinedAreaTransition)
	VM_ExecuteCommand(203, 2)	
end

--  Starts a conversation with oObjectToConverseWith - this will cause their
--  OnDialog event to fire.
--  - oObjectToConverseWith
--  - sDialogResRef: If this is blank, the creature's own dialogue file will be used
--  - bPrivateConversation
--  Turn off bPlayHello if you don't want the initial greeting to play
function ActionStartConversation(oObjectToConverseWith, sDialogResRef, bPrivateConversation, bPlayHello)
	sDialogResRef = sDialogResRef or ""
	bPrivateConversation = bPrivateConversation or false
	if bPlayHello == nil then bPlayHello = true end
  
	StackPushBoolean(bPlayHello)
	StackPushBoolean(bPrivateConversation)
	StackPushString(sDialogResRef)
	StackPushObject(oObjectToConverseWith)
	VM_ExecuteCommand(204, 4)	
end

--  Pause the current conversation.
function ActionPauseConversation()
	VM_ExecuteCommand(205, 0)	
end

--  Resume a conversation after it has been paused.
function ActionResumeConversation()
	VM_ExecuteCommand(206, 0)	
end

--  Create a Beam effect.
--  - nBeamVisualEffect: VFX_BEAM_*
--  - oEffector: the beam is emitted from this creature
--  - nBodyPart: BODY_NODE_*
--  - bMissEffect: If this is TRUE, the beam will fire to a random vector near or
--    past the target
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nBeamVisualEffect is
--    not valid.
function EffectBeam(nBeamVisualEffect, oEffector, nBodyPart, bMissEffect)
	bMissEffect = bMissEffect or false
	
	StackPushBoolean(bMissEffect)
	StackPushInteger(nBodyPart)
	StackPushObject(oEffector)
	StackPushInteger(nBeamVisualEffect)
	VM_ExecuteCommand(207, 4)
	return StackPopEffect()
end

--  Get an integer between 0 and 100 (inclusive) that represents how oSource
--  feels about oTarget.
--  -> 0-10 means oSource is hostile to oTarget
--  -> 11-89 means oSource is neutral to oTarget
--  -> 90-100 means oSource is friendly to oTarget
--  * Returns -1 if oSource or oTarget does not identify a valid object
function GetReputation(oSource, oTarget)
  	StackPushObject(oTarget)
	StackPushObject(oSource)
	VM_ExecuteCommand(208, 2)
	return StackPopInteger()
end

--  Adjust how oSourceFactionMember's faction feels about oTarget by the
--  specified amount.
--  Note: This adjusts Faction Reputation, how the entire faction that
--  oSourceFactionMember is in, feels about oTarget.
--  * No return value
--  Note: You can't adjust a player character's (PC) faction towards
--        NPCs, so attempting to make an NPC hostile by passing in a PC object
--        as oSourceFactionMember in the following call will fail:
--        AdjustReputation(oNPC,oPC,-100)
--        Instead you should pass in the PC object as the first
--        parameter as in the following call which should succeed: 
--        AdjustReputation(oPC,oNPC,-100)
--  Note: Will fail if oSourceFactionMember is a plot object.
function AdjustReputation(oTarget, oSourceFactionMember, nAdjustment)  
	StackPushInteger(nAdjustment)
	StackPushObject(oSourceFactionMember)
	StackPushObject(oTarget)
	VM_ExecuteCommand(209, 3)
end

--  Get the creature that is currently sitting on the specified object.
--  - oChair
--  * Returns OBJECT_INVALID if oChair is not a valid placeable.
function GetSittingCreature(oChair)
	StackPushObject(oChair)
	VM_ExecuteCommand(210, 1)
	return StackPopObject()
end

--  Get the creature that is going to attack oTarget.
--  Note: This value is cleared out at the end of every combat round and should
--  not be used in any case except when getting a "going to be attacked" shout
--  from the master creature (and this creature is a henchman)
--  * Returns OBJECT_INVALID if oTarget is not a valid creature.
function GetGoingToBeAttackedBy(oTarget) 
	StackPushObject(oTarget)
	VM_ExecuteCommand(211, 1)
	return StackPopObject()
end

--  Create a Spell Resistance Increase effect.
--  - nValue: size of spell resistance increase
function EffectSpellResistanceIncrease(nValue)
	StackPushInteger(nValue)
	VM_ExecuteCommand(212, 1)
	return StackPopEffect()
end

--  Get the location of oObject.
function GetLocation(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(213, 1)
	return StackPopLocation()
end

--  The subject will jump to lLocation instantly (even between areas).
--  If lLocation is invalid, nothing will happen.
function ActionJumpToLocation(lLocation)
	StackPushLocation(lLocation)
	VM_ExecuteCommand(214, 1)
end

--  Create a location.
function Location(oArea, vPosition, fOrientation)	
	StackPushFloat(fOrientation)
	StackPushVector(vPosition)
	StackPushObject(oArea)
	VM_ExecuteCommand(215, 3)
	return StackPopLocation()
end

--  Apply eEffect at lLocation.
function ApplyEffectAtLocation(nDurationType, eEffect, lLocation, fDuration)
	fDuration = fDuration or 0.0

	StackPushFloat(fDuration)
	StackPushLocation(lLocation)
	StackPushEffect(eEffect)
	StackPushInteger(nDurationType)
	VM_ExecuteCommand(216, 4)	
end

--  * Returns TRUE if oCreature is a Player Controlled character.
function GetIsPC(oCreature) 
	StackPushObject(oCreature)
	VM_ExecuteCommand(217, 1)
	return StackPopBoolean()
end

--  Convert fFeet into a number of meters.
function FeetToMeters(fFeet)
	StackPushFloat(fFeet)
	VM_ExecuteCommand(218, 1)
	return StackPopFloat()
end

--  Convert fYards into a number of meters.
function YardsToMeters(fYards)
	StackPushFloat(fYards)
	VM_ExecuteCommand(219, 1)
	return StackPopFloat()
end

--  Apply eEffect to oTarget.
function ApplyEffectToObject(nDurationType, eEffect, oTarget, fDuration)
	fDuration = fDuration or 0.0
	StackPushFloat(fDuration)
	StackPushObject(oTarget)
	StackPushEffect(eEffect)
	StackPushInteger(nDurationType)
	VM_ExecuteCommand(220, 4)
end

--  The caller will immediately speak sStringToSpeak (this is different from
--  ActionSpeakString)
--  - sStringToSpeak
--  - nTalkVolume: TALKVOLUME_*
function SpeakString(sStringToSpeak, nTalkVolume)
	nTalkVolume = nTalkVolume or 0 --TALKVOLUME_TALK

	StackPushInteger(nTalkVolume)
	StackPushString(sStringToSpeak)
	VM_ExecuteCommand(221, 2)
end

--  Get the location of the caller's last spell target.
function GetSpellTargetLocation()
	VM_ExecuteCommand(222, 0)
	return StackPopLocation()
end

--  Get the position vector from lLocation.
function GetPositionFromLocation(lLocation) 
	StackPushLocation(lLocation)
	VM_ExecuteCommand(223, 1)
	return StackPopVector()
end

--  Get the area's object ID from lLocation.
function GetAreaFromLocation(lLocation)  
	StackPushLocation(lLocation)
	VM_ExecuteCommand(224, 1)
	return StackPopObject()
end

--  Get the orientation value from lLocation.
function GetFacingFromLocation(lLocation) 
	StackPushLocation(lLocation)
	VM_ExecuteCommand(225, 1)
	return StackPopFloat()
end

--  Get the creature nearest to lLocation, subject to all the criteria specified.
--  - nFirstCriteriaType: CREATURE_TYPE_*
--  - nFirstCriteriaValue:
--    -> CLASS_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_CLASS
--    -> SPELL_* if nFirstCriteriaType was CREATURE_TYPE_DOES_NOT_HAVE_SPELL_EFFECT
--       or CREATURE_TYPE_HAS_SPELL_EFFECT
--    -> TRUE or FALSE if nFirstCriteriaType was CREATURE_TYPE_IS_ALIVE
--    -> PERCEPTION_* if nFirstCriteriaType was CREATURE_TYPE_PERCEPTION
--    -> PLAYER_CHAR_IS_PC or PLAYER_CHAR_NOT_PC if nFirstCriteriaType was
--       CREATURE_TYPE_PLAYER_CHAR
--    -> RACIAL_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_RACIAL_TYPE
--    -> REPUTATION_TYPE_* if nFirstCriteriaType was CREATURE_TYPE_REPUTATION
--    For example, to get the nearest PC, use
--    (CREATURE_TYPE_PLAYER_CHAR, PLAYER_CHAR_IS_PC)
--  - lLocation: We're trying to find the creature of the specified type that is
--    nearest to lLocation
--  - nNth: We don't have to find the first nearest: we can find the Nth nearest....
--  - nSecondCriteriaType: This is used in the same way as nFirstCriteriaType to
--    further specify the type of creature that we are looking for.
--  - nSecondCriteriaValue: This is used in the same way as nFirstCriteriaValue
--    to further specify the type of creature that we are looking for.
--  - nThirdCriteriaType: This is used in the same way as nFirstCriteriaType to
--    further specify the type of creature that we are looking for.
--  - nThirdCriteriaValue: This is used in the same way as nFirstCriteriaValue to
--    further specify the type of creature that we are looking for.
--  * Return value on error: OBJECT_INVALID
function GetNearestCreatureToLocation(nFirstCriteriaType, nFirstCriteriaValue, lLocation, nNth, nSecondCriteriaType, nSecondCriteriaValue, nThirdCriteriaType, nThirdCriteriaValue)
	nNth = nNth or 1
	nSecondCriteriaType = nSecondCriteriaType or -1
	nSecondCriteriaValue = nSecondCriteriaValue or -1
	nThirdCriteriaType = nThirdCriteriaType or -1
	nThirdCriteriaValue = nThirdCriteriaValue or -1
	
	StackPushInteger(nThirdCriteriaValue)
	StackPushInteger(nThirdCriteriaType)
	StackPushInteger(nSecondCriteriaValue)
	StackPushInteger(nSecondCriteriaType)
	StackPushInteger(nNth)
	StackPushLocation(lLocation)
	StackPushInteger(nFirstCriteriaValue)
	StackPushInteger(nFirstCriteriaType)
	VM_ExecuteCommand(226, 8)
	return StackPopObject()
end

--  Get the Nth object nearest to oTarget that is of the specified type.
--  - nObjectType: OBJECT_TYPE_*
--  - oTarget
--  - nNth
--  * Return value on error: OBJECT_INVALID
function GetNearestObject(nObjectType, oTarget, nNth)

	nObjectType = nObjectType or 32767 --OBJECT_TYPE_ALL
	oTarget = oTarget or OBJECT_SELF
	nNth = nNth or 1
	
	StackPushInteger(nNth)
	StackPushObject(oTarget)
	StackPushInteger(nObjectType)
	VM_ExecuteCommand(227, 3)
	return StackPopObject()
end

--  Get the nNth object nearest to lLocation that is of the specified type.
--  - nObjectType: OBJECT_TYPE_*
--  - lLocation
--  - nNth
--  * Return value on error: OBJECT_INVALID
function GetNearestObjectToLocation(nObjectType, lLocation, nNth)
	nNth = nNth or 1

	StackPushInteger(nNth)
	StackPushLocation(lLocation)
	StackPushInteger(nObjectType)
	VM_ExecuteCommand(228, 3)
	return StackPopObject()
end

--  Get the nth Object nearest to oTarget that has sTag as its tag.
--  * Return value on error: OBJECT_INVALID
function GetNearestObjectByTag(sTag, oTarget, nNth)
	oTarget = oTarget or OBJECT_SELF
	nNth = nNth or 1
	
	StackPushInteger(nNth)
	StackPushObject(oTarget)
	StackPushString(sTag)
	VM_ExecuteCommand(229, 3)
	return StackPopObject()
end

--  Convert nInteger into a floating point number.
function IntToFloat(nInteger)
	StackPushInteger(nInteger)
	VM_ExecuteCommand(230, 1)
	return StackPopFloat()
end

--  Convert fFloat into the nearest integer.
function FloatToInt()
	StackPushFloat(fFloat)
	VM_ExecuteCommand(231, 1)
	return StackPopInteger()
end

--  Convert sNumber into an integer.
function StringToInt(sNumber)
	StackPushString(sNumber)
	VM_ExecuteCommand(232, 1)
	return StackPopInteger()
end

--  Convert sNumber into a floating point number.
function StringToFloat(sNumber)
	StackPushString(sNumber)
	VM_ExecuteCommand(233, 1)
	return StackPopFloat(fRetVal)
end

--  Cast spell nSpell at lTargetLocation.
--  - nSpell: SPELL_*
--  - lTargetLocation
--  - nMetaMagic: METAMAGIC_*
--  - bCheat: If this is TRUE, then the executor of the action doesn't have to be
--    able to cast the spell.
--  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
--  - bInstantSpell: If this is TRUE, the spell is cast immediately this allows
--    the end-user to simulate
--    a high-level magic user having lots of advance warning of impending trouble.
function ActionCastSpellAtLocation(nSpell, lTargetLocation, nMetaMagic, bCheat, nProjectilePathType, bInstantSpell)
	nMetaMagic = nMetaMagic or 255 --METAMAGIC_ANY
	bCheat = bCheat or false
	nProjectilePathType = nProjectilePathType or 0 --PROJECTILE_PATH_TYPE_DEFAULT
	bInstantSpell = bInstantSpell or false
	
	StackPushBoolean(bInstantSpell)
	StackPushInteger(nProjectilePathType)
	StackPushBoolean(bCheat)
	StackPushInteger(nMetaMagic)
	StackPushLocation(lTargetLocation)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(234, 6)	
end

--  * Returns TRUE if oSource considers oTarget as an enemy.
function GetIsEnemy(oTarget, oSource)
	oSource = oSource or OBJECT_SELF

	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(235, 2)
	return StackPopBoolean()
end

--  * Returns TRUE if oSource considers oTarget as a friend.
function GetIsFriend(oTarget, oSource)
	oSource = oSource or OBJECT_SELF

	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(236, 2)
	return StackPopBoolean()
end

--  * Returns TRUE if oSource considers oTarget as neutral.
function GetIsNeutral(oTarget, oSource)
	oSource = oSource or OBJECT_SELF

	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(237, 2)
	return StackPopBoolean()
end

--  Get the PC that is involved in the conversation.
--  * Returns OBJECT_INVALID on error.
function GetPCSpeaker()
	VM_ExecuteCommand(238, 0)
	return StackPopObject()
end

--  Get a string from the talk table using nStrRef.
function GetStringByStrRef(nStrRef, nGender)
	nGender = nGender or 0 --GENDER_MALE

	StackPushInteger(nGender)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(239, 2)
	return StackPopString()
end

--  Causes the creature to speak a translated string.
--  - nStrRef: Reference of the string in the talk table
--  - nTalkVolume: TALKVOLUME_*
function ActionSpeakStringByStrRef(nStrRef, nTalkVolume)
	nTalkVolume = nTalkVolume or 0 --TALKVOLUME_TALK

	StackPushInteger(nTalkVolume)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(240, 2)
end

--  Destroy oObject (irrevocably).
--  This will not work on modules and areas.
function DestroyObject(oDestroy, fDelay)
	fDelay = fDelay or 0.0

	StackPushFloat(fDelay)
	StackPushObject(oDestroy)
	VM_ExecuteCommand(241, 2)
end

--  Get the module.
--  * Return value on error: OBJECT_INVALID
function GetModule()
	VM_ExecuteCommand(242, 0)
	return StackPopObject()
end

--  Create an object of the specified type at lLocation.
--  - nObjectType: OBJECT_TYPE_ITEM, OBJECT_TYPE_CREATURE, OBJECT_TYPE_PLACEABLE,
--    OBJECT_TYPE_STORE, OBJECT_TYPE_WAYPOINT
--  - sTemplate
--  - lLocation
--  - bUseAppearAnimation
--  - sNewTag - if this string is not empty, it will replace the default tag from the template
function CreateObject(nObjectType, sTemplate, lLocation, bUseAppearAnimation, sNewTag)
	bUseAppearAnimation = bUseAppearAnimation or false
	sNewTag = sNewTag or ""

	StackPushString(sNewTag)
	StackPushBoolean(bUseAppearAnimation)
	StackPushLocation(lLocation)
	StackPushString(sTemplate)
	StackPushInteger(nObjectType)
	VM_ExecuteCommand(243, 5)
	return StackPopObject()
end

--  Create an event which triggers the "SpellCastAt" script
--  Note: This only creates the event. The event wont actually trigger until SignalEvent()
--  is called using this created SpellCastAt event as an argument.
--  For example:
--      SignalEvent(oCreature, EventSpellCastAt(oCaster, SPELL_MAGIC_MISSILE, TRUE))
--  This function doesn't cast the spell specified, it only creates an event so that
--  when the event is signaled on an object, the object will use its OnSpellCastAt script
--  to react to the spell being cast.
-- 
--  To specify the OnSpellCastAt script that should run, view the Object's Properties 
--  and click on the Scripts Tab. Then specify a script for the OnSpellCastAt event.
--  From inside the OnSpellCastAt script call:
--      GetLastSpellCaster() to get the object that cast the spell (oCaster).
--      GetLastSpell() to get the type of spell cast (nSpell)
--      GetLastSpellHarmful() to determine if the spell cast at the object was harmful.
function EventSpellCastAt(oCaster, nSpell, bHarmful)
	if bHarmful == nil then bHarmful = true end

	StackPushBoolean(bHarmful)
	StackPushInteger(nSpell)
	StackPushObject(oCaster)
	VM_ExecuteCommand(244, 3)
  	return StackPopEvent()
end

--  This is for use in a "Spell Cast" script, it gets who cast the spell.
--  The spell could have been cast by a creature, placeable or door.
--  * Returns OBJECT_INVALID if the caller is not a creature, placeable or door.
function GetLastSpellCaster()
	VM_ExecuteCommand(245, 0)
	return StackPopObject()
end

--  This is for use in a "Spell Cast" script, it gets the ID of the spell that
--  was cast.
function GetLastSpell()
	VM_ExecuteCommand(246, 0)
	return StackPopInteger()
end

--  This is for use in a user-defined script, it gets the event number.
function GetUserDefinedEventNumber()
	VM_ExecuteCommand(247, 0)
	return StackPopInteger()
end

--  This is for use in a Spell script, it gets the ID of the spell that is being
--  cast (SPELL_*).
function GetSpellId()
	VM_ExecuteCommand(248, 0)
	return StackPopInteger()
end

--  Generate a random name.
--  nNameType: The type of random name to be generated (NAME_*)
function RandomName()
	nNameType = nNameType or -1 --NAME_FIRST_GENERIC_MALE

	StackPushInteger(nNameType)
	VM_ExecuteCommand(249, 1)
	return StackPopString()
end

--  Create a Poison effect.
--  - nPoisonType: POISON_*
function EffectPoison(nPoisonType)
	StackPushInteger(nPoisonType)
	VM_ExecuteCommand(250, 1)
	return StackPopEffect()
end

--  Create a Disease effect.
--  - nDiseaseType: DISEASE_*
function EffectDisease(nDiseaseType)
	StackPushInteger(nDiseaseType)
	VM_ExecuteCommand(251, 1)
	return StackPopEffect()
end

--  Create a Silence effect.
function EffectSilence()
	VM_ExecuteCommand(252, 0)
	return StackPopEffect()
end

--  Set the name of oObject.
-- 
--  - oObject: the object for which you are changing the name (area, creature, placeable, item, or door).
--  - sNewName: the new name that the object will use.
--  Note: SetName() does not work on player objects.
--        Setting an object's name to "" will make the object
--        revert to using the name it had originally before any
--        SetName() calls were made on the object.
function GetName(oObject, bOriginalName)
	bOriginalName = bOriginalName or false

	StackPushBoolean(bOriginalName)
	StackPushObject(oObject)
	VM_ExecuteCommand(253, 2)
	return StackPopString()
end

--  Use this in a conversation script to get the person with whom you are conversing.
--  * Returns OBJECT_INVALID if the caller is not a valid creature.
function GetLastSpeaker()
	VM_ExecuteCommand(254, 0)
	return StackPopObject()
end

--  Use this in an OnDialog script to start up the dialog tree.
--  - sResRef: if this is not specified, the default dialog file will be used
--  - oObjectToDialog: if this is not specified the person that triggered the
--    event will be used
function BeginConversation(sResRef, oObjectToDialog)
	sResRef = sResRef or ""
	oObjectToDialog = oObjectToDialog or OBJECT_INVALID

	StackPushObject(oObjectToDialog)
	StackPushString(sResRef)
	VM_ExecuteCommand(255, 2)
	return StackPopInteger()
end

--  Use this in an OnPerception script to get the object that was perceived.
--  * Returns OBJECT_INVALID if the caller is not a valid creature.
function GetLastPerceived()
	VM_ExecuteCommand(256, 0)
	return StackPopObject()
end

--  Use this in an OnPerception script to determine whether the object that was
--  perceived was heard.
function GetLastPerceptionHeard()
	VM_ExecuteCommand(257, 0)
	return StackPopInteger()
end

--  Use this in an OnPerception script to determine whether the object that was
--  perceived has become inaudible.
function GetLastPerceptionInaudible()
	VM_ExecuteCommand(258, 0)
	return StackPopInteger()
end

--  Use this in an OnPerception script to determine whether the object that was
--  perceived was seen.
function GetLastPerceptionSeen()
	VM_ExecuteCommand(259, 0)
	return StackPopInteger()
end

--  Use this in an OnClosed script to get the object that closed the door or placeable.
--  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
function GetLastClosedBy()
	VM_ExecuteCommand(260, 0)
	return StackPopObject()
end

--  Use this in an OnPerception script to determine whether the object that was
--  perceived has vanished.
function GetLastPerceptionVanished()
	VM_ExecuteCommand(261, 0)
	return StackPopInteger()
end

--  Get the first object within oPersistentObject.
--  - oPersistentObject
--  - nResidentObjectType: OBJECT_TYPE_*
--  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
--    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
--  * Returns OBJECT_INVALID if no object is found.
function GetFirstInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone)
	oPersistentObject = oPersistentObject or OBJECT_SELF
	nResidentObjectType = nResidentObjectType or 1 --OBJECT_TYPE_CREATURE
	nPersistentZone = nPersistentZone or 0 --PERSISTENT_ZONE_ACTIVE
	
	StackPushInteger(nPersistentZone)
	StackPushInteger(nResidentObjectType)
	StackPushObject(oPersistentObject)
	VM_ExecuteCommand(262, 3)
	return StackPopObject()
end

--  Get the next object within oPersistentObject.
--  - oPersistentObject
--  - nResidentObjectType: OBJECT_TYPE_*
--  - nPersistentZone: PERSISTENT_ZONE_ACTIVE. [This could also take the value
--    PERSISTENT_ZONE_FOLLOW, but this is no longer used.]
--  * Returns OBJECT_INVALID if no object is found.
function GetNextInPersistentObject(oPersistentObject, nResidentObjectType, nPersistentZone)
	oPersistentObject = oPersistentObject or OBJECT_SELF
	nResidentObjectType = nResidentObjectType or 1 --OBJECT_TYPE_CREATURE
	nPersistentZone = nPersistentZone or 0 --PERSISTENT_ZONE_ACTIVE
	
	StackPushInteger(nPersistentZone)
	StackPushInteger(nResidentObjectType)
	StackPushObject(oPersistentObject)
	VM_ExecuteCommand(263, 3)
	return StackPopObject()
end

--  This returns the creator of oAreaOfEffectObject.
--  * Returns OBJECT_INVALID if oAreaOfEffectObject is not a valid Area of Effect object.
function GetAreaOfEffectCreator(oAreaOfEffectObject)
	oAreaOfEffectObject = oAreaOfEffectObject or OBJECT_SELF

	StackPushObject(oAreaOfEffectObject)
	VM_ExecuteCommand(264, 1)
	return StackPopObject()
end

--  Delete oObject's local integer variable sVarName
function DeleteLocalInt(oObject, sVarName) 
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(265, 2)	
end

--  Delete oObject's local float variable sVarName
function DeleteLocalFloat(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(266, 2)	
end

--  Delete oObject's local string variable sVarName
function DeleteLocalString(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(267, 2)
end

--  Delete oObject's local object variable sVarName
function DeleteLocalObject(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(268, 2)
end

--  Delete oObject's local location variable sVarName
function DeleteLocalLocation(oObject, sVarName)
	StackPushString(sVarName)
	StackPushObject(oObject)
	VM_ExecuteCommand(269, 2)
end

--  Create a Haste effect.
function EffectHaste()
	VM_ExecuteCommand(270, 0)
	return StackPopEffect()
end

--  Create a Slow effect.
function EffectSlow()
	VM_ExecuteCommand(271, 0)
	return StackPopEffect()
end

--  Convert oObject into a hexadecimal string.
function ObjectToString(oObject) 
	StackPushObject(oObject)
	VM_ExecuteCommand(272, 1)
	return StackPopString()
end

--  Create an Immunity effect.
--  - nImmunityType: IMMUNITY_TYPE_*
function EffectImmunity(nImmunityType)
	StackPushInteger(nImmunityType)
	VM_ExecuteCommand(273, 1)
	return StackPopEffect()
end

--  - oCreature
--  - nImmunityType: IMMUNITY_TYPE_*
--  - oVersus: if this is specified, then we also check for the race and
--    alignment of oVersus
--  * Returns TRUE if oCreature has immunity of type nImmunity versus oVersus.
function GetIsImmune(oCreature, nImmunityType, oVersus)
	oVersus = oVersus or OBJECT_INVALID

	StackPushObject(oVersus)
	StackPushInteger(nImmunityType)
	StackPushObject(oCreature)
	VM_ExecuteCommand(274, 3)
	return StackPopBoolean()
end

--  Creates a Damage Immunity Increase effect.
--  - nDamageType: DAMAGE_TYPE_*
--  - nPercentImmunity
function EffectDamageImmunityIncrease(nDamageType, nPercentImmunity)
	StackPushInteger(nPercentImmunity)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(275, 2)
	return StackPopEffect()
end

--  Determine whether oEncounter is active.
function GetEncounterActive(oEncounter)
	oEncounter = oEncounter or OBJECT_SELF

	StackPushObject(oEncounter)
	VM_ExecuteCommand(276, 1)
	return StackPopBoolean()
end

--  Set oEncounter's active state to nNewValue.
--  - nNewValue: TRUE/FALSE
--  - oEncounter
function SetEncounterActive(bNewValue, oEncounter)
	oEncounter = oEncounter or OBJECT_SELF

	StackPushObject(oEncounter)
	StackPushBoolean(bNewValue)
	VM_ExecuteCommand(277, 2)	
end

--  Get the maximum number of times that oEncounter will spawn.
function GetEncounterSpawnsMax(oEncounter)
	oEncounter = oEncounter or OBJECT_SELF

	StackPushObject(oEncounter)
	VM_ExecuteCommand(278, 1)
	return StackPopInteger()
end

--  Set the maximum number of times that oEncounter can spawn
function SetEncounterSpawnsMax(nNewValue, oEncounter)
	oEncounter = oEncounter or OBJECT_SELF
	
	StackPushObject(oEncounter)
	StackPushInteger(nNewValue)
	VM_ExecuteCommand(279, 2)	
end

--  Get the number of times that oEncounter has spawned so far
function GetEncounterSpawnsCurrent(oEncounter)
	oEncounter = oEncounter or OBJECT_SELF

	StackPushObject(oEncounter)
	VM_ExecuteCommand(280, 1)
	return StackPopInteger()
end

--  Set the number of times that oEncounter has spawned so far
function SetEncounterSpawnsCurrent(nNewValue, oEncounter)
	oEncounter = oEncounter or OBJECT_SELF

	StackPushObject(oEncounter)
	StackPushInteger(nNewValue)
	VM_ExecuteCommand(281, 2)
end

--  Use this in an OnItemAcquired script to get the item that was acquired.
--  * Returns OBJECT_INVALID if the module is not valid.
function GetModuleItemAcquired()
	VM_ExecuteCommand(282, 0)
	return StackPopObject()
end

--  Use this in an OnItemAcquired script to get the creatre that previously
--  possessed the item.
--  * Returns OBJECT_INVALID if the item was picked up from the ground.
function GetModuleItemAcquiredFrom()
	VM_ExecuteCommand(283, 0)
	return StackPopObject()
end

--  Set the value for a custom token.
function SetCustomToken(nCustomTokenNumber, sTokenValue) 
	StackPushString(sTokenValue)
	StackPushInteger(nCustomTokenNumber)
	VM_ExecuteCommand(284, 2)	
end

--  Determine whether oCreature has nFeat, and nFeat is useable.
--  - nFeat: FEAT_*
--  - oCreature
function GetHasFeat(nFeat, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushInteger(nFeat)
	VM_ExecuteCommand(285, 2)
	return StackPopBoolean()
end

--  Determine whether oCreature has nSkill, and nSkill is useable.
--  - nSkill: SKILL_*
--  - oCreature
function GetHasSkill(nSkill, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(286, 2)
	return StackPopBoolean()
end

--  Use nFeat on oTarget.
--  - nFeat: FEAT_*
--  - oTarget
function ActionUseFeat(nFeat, oTarget) 
	StackPushObject(oTarget)
	StackPushInteger(nFeat)
	VM_ExecuteCommand(287, 2)
end

--  Runs the action "UseSkill" on the current creature
--  Use nSkill on oTarget.
--  - nSkill: SKILL_*
--  - oTarget
--  - nSubSkill: SUBSKILL_*
--  - oItemUsed: Item to use in conjunction with the skill
function ActionUseSkill(nSkill, oTarget, nSubSkill, oItemUsed)
	nSubSkill = nSubSkill or 0
	oItemUsed = oItemUsed or OBJECT_INVALID
	
	StackPushObject(oItemUsed)
	StackPushInteger(nSubSkill)
	StackPushObject(oTarget)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(288, 4)	
end

--  Determine whether oSource sees oTarget.
--  NOTE: This *only* works on creatures, as visibility lists are not
--        maintained for non-creature objects.
function GetObjectSeen(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(289, 2)
	return StackPopBoolean()
end

--  Determine whether oSource hears oTarget.
--  NOTE: This *only* works on creatures, as visibility lists are not
--        maintained for non-creature objects.
function GetObjectHeard(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(290, 2)
	return StackPopBoolean()
end

--  Use this in an OnPlayerDeath module script to get the last player that died.
function GetLastPlayerDied()
	VM_ExecuteCommand(291, 0)
	return StackPopObject()
end

--  Use this in an OnItemLost script to get the item that was lost/dropped.
--  * Returns OBJECT_INVALID if the module is not valid.
function GetModuleItemLost()
	VM_ExecuteCommand(292, 0)
	return StackPopObject()
end

--  Use this in an OnItemLost script to get the creature that lost the item.
--  * Returns OBJECT_INVALID if the module is not valid.
function GetModuleItemLostBy()
	VM_ExecuteCommand(293, 0)
	return StackPopObject()
end
--[[
function ActionDoCommand(VALUE aActionToDo)

	//ERROR: Undefined variable type: action
	VM_ExecuteCommand(294, 1)
	
end
--]]
--  Do aActionToDo.
--  Creates a conversation event.
--  Note: This only creates the event. The event wont actually trigger until SignalEvent()
--  is called using this created conversation event as an argument.
--  For example:
--      SignalEvent(oCreature, EventConversation())
--  Once the event has been signaled. The script associated with the OnConversation event will
--  run on the creature oCreature.
-- 
--  To specify the OnConversation script that should run, view the Creature Properties on
--  the creature and click on the Scripts Tab. Then specify a script for the OnConversation event.
function EventConversation()
	VM_ExecuteCommand(295, 0)
	return StackPopEvent()
end

--  Set the difficulty level of oEncounter.
--  - nEncounterDifficulty: ENCOUNTER_DIFFICULTY_*
--  - oEncounter
function SetEncounterDifficulty(nEncounterDifficulty, oEncounter)
	oEncounter = oEncounter or OBJECT_SELF
	
	StackPushObject(oEncounter)
	StackPushInteger(nEncounterDifficulty)
	VM_ExecuteCommand(296, 2)	
end

--  Get the difficulty level of oEncounter.
function GetEncounterDifficulty()
	oEncounter = oEncounter or OBJECT_SELF
	
	StackPushObject(oEncounter)
	VM_ExecuteCommand(297, 1)
	return StackPopInteger()
end

--  Get the distance between lLocationA and lLocationB.
function GetDistanceBetweenLocations(lLocationA, lLocationB)
	StackPushLocation(lLocationB)
	StackPushLocation(lLocationA)
	VM_ExecuteCommand(298, 2)
	return StackPopFloat()
end

--  Use this in spell scripts to get nDamage adjusted by oTarget's reflex and
--  evasion saves.
--  - nDamage
--  - oTarget
--  - nDC: Difficulty check
--  - nSaveType: SAVING_THROW_TYPE_*
--  - oSaveVersus
function GetReflexAdjustedDamage(nDamage, oTarget, nDC, nSaveType, oSaveVersus)
	nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_NONE
	oSaveVersus = oSaveVersus or OBJECT_SELF
	
	StackPushObject(oSaveVersus)
	StackPushInteger(nSaveType)
	StackPushInteger(nDC)
	StackPushObject(oTarget)
	StackPushInteger(nDamage)
	VM_ExecuteCommand(299, 5)
	return StackPopInteger()
end

--  Play nAnimation immediately.
--  - nAnimation: ANIMATION_*
--  - fSpeed
--  - fSeconds
function PlayAnimation(nAnimation, fSpeed, fSeconds)
	fSpeed = fSpeed or 1.0
	fSeconds = fSeconds or 0.0
	
	StackPushFloat(fSeconds)
	StackPushFloat(fSpeed)
	StackPushInteger(nAnimation)
	VM_ExecuteCommand(300, 3)
end

--  Create a Spell Talent.
--  - nSpell: SPELL_*
function TalentSpell(nSpell)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(301, 1)
	return StackPopTalent()
end

--  Create a Feat Talent.
--  - nFeat: FEAT_*
function TalentFeat(nFeat)
	StackPushInteger(nFeat)
	VM_ExecuteCommand(302, 1)
	return StackPopTalent()
end

--  Create a Skill Talent.
--  - nSkill: SKILL_*
function TalentSkill(nSkill) 
	StackPushInteger(nSkill)
	VM_ExecuteCommand(303, 1)
	return StackPopTalent()
end

--  Determines whether oObject has any effects applied by nSpell
--  - nSpell: SPELL_*
--  - oObject
--  * The spell id on effects is only valid if the effect is created
--    when the spell script runs. If it is created in a delayed command
--    then the spell id on the effect will be invalid.
function GetHasSpellEffect(nSpell, oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(304, 2)
	return StackPopBoolean()
end

--  Get the spell (SPELL_*) that applied eSpellEffect.
--  * Returns -1 if eSpellEffect was applied outside a spell script.
function GetEffectSpellId(eSpellEffect)
	StackPushEffect(eSpellEffect)
	VM_ExecuteCommand(305, 1)
	return StackPopInteger()
end

--  Determine whether oCreature has tTalent.
function GetCreatureHasTalent(tTalent, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushTalent(tTalent)
	VM_ExecuteCommand(306, 2)
	return StackPopBoolean()
end

--  Get a random talent of oCreature, within nCategory.
--  - nCategory: TALENT_CATEGORY_*
--  - oCreature
function GetCreatureTalentRandom(nCategory, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushInteger(nCategory)
	VM_ExecuteCommand(307, 2)
	return StackPopTalent()
end

--  Get the best talent (i.e. closest to nCRMax without going over) of oCreature,
--  within nCategory.
--  - nCategory: TALENT_CATEGORY_*
--  - nCRMax: Challenge Rating of the talent
--  - oCreature
function GetCreatureTalentBest(nCategory, nCRMax, oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	StackPushInteger(nCRMax)
	StackPushInteger(nCategory)
	VM_ExecuteCommand(308, 3)
	return StackPopTalent()
end

--  Use tChosenTalent on oTarget.
function ActionUseTalentOnObject(tChosenTalent, oTarget)
	StackPushObject(oTarget)
	StackPushTalent(tChosenTalent)
	VM_ExecuteCommand(309, 2)
end

--  Use tChosenTalent at lTargetLocation.
function ActionUseTalentAtLocation(tChosenTalent, lTargetLocation)
	StackPushLocation(lTargetLocation)
	StackPushTalent(tChosenTalent)
	VM_ExecuteCommand(310, 2)
end

--  Get the gold piece value of oItem.
--  * Returns 0 if oItem is not a valid item.
function GetGoldPieceValue(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(311, 1)
	return StackPopInteger()
end

--  * Returns TRUE if oCreature is of a playable racial type.
function GetIsPlayableRacialType(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(312, 1)
	return StackPopBoolean()
end

--  Jump to lDestination.  The action is added to the TOP of the action queue.
function JumpToLocation(lDestination)
	StackPushLocation(lDestination)
	VM_ExecuteCommand(313, 1)
end

--  Create a Temporary Hitpoints effect.
--  - nHitPoints: a positive integer
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nHitPoints < 0.
function EffectTemporaryHitpoints(nHitPoints)
	StackPushInteger(nHitPoints)
	VM_ExecuteCommand(314, 1)
	return StackPopEffect()
end

--  Get the number of ranks that oTarget has in nSkill.
--  - nSkill: SKILL_*
--  - oTarget
--  - nBaseSkillRank: if set to true returns the number of base skill ranks the target
--                    has (i.e. not including any bonuses from ability scores, feats, etc).
--  * Returns -1 if oTarget doesn't have nSkill.
--  * Returns 0 if nSkill is untrained.
function GetSkillRank(nSkill, oTarget, nBaseSkillRank)
	oTarget = oTarget or OBJECT_SELF
	nBaseSkillRank = nBaseSkillRank or false
	
	StackPushBoolean(nBaseSkillRank)
	StackPushObject(oTarget)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(315, 3)
	return StackPopInteger()
end

--  Get the attack target of oCreature.
--  This only works when oCreature is in combat.
function GetAttackTarget(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(316, 1)
	return StackPopObject()
end

--  Get the attack type (SPECIAL_ATTACK_*) of oCreature's last attack.
--  This only works when oCreature is in combat.
function GetLastAttackType(oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	VM_ExecuteCommand(317, 1)
	return StackPopInteger()
end

--  Get the attack mode (COMBAT_MODE_*) of oCreature's last attack.
--  This only works when oCreature is in combat.
function GetLastAttackMode(oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	VM_ExecuteCommand(318, 1)
	return StackPopInteger()
end

--  Get the master of oAssociate.
function GetMaster(oAssociate)
	oAssociate = oAssociate or OBJECT_SELF
	
	StackPushObject(oAssociate)
	VM_ExecuteCommand(319, 1)
	return StackPopObject()
end

--  * Returns TRUE if oCreature is in combat.
function GetIsInCombat(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(320, 1)
	return StackPopBoolean()
end

--  Get the last command (ASSOCIATE_COMMAND_*) issued to oAssociate.
function GetLastAssociateCommand(oAssociate)
	oAssociate = oAssociate or OBJECT_SELF

	StackPushObject(oAssociate)
	VM_ExecuteCommand(321, 1)
	return StackPopInteger()
end

--  Give nGP gold to oCreature.
function GiveGoldToCreature(oCreature, nGP)
	StackPushInteger(nGP)
	StackPushObject(oCreature)
	VM_ExecuteCommand(322, 2)
end

--  Set the destroyable status of the caller.
--  - bDestroyable: If this is FALSE, the caller does not fade out on death, but
--    sticks around as a corpse.
--  - bRaiseable: If this is TRUE, the caller can be raised via resurrection.
--  - bSelectableWhenDead: If this is TRUE, the caller is selectable after death.
function SetIsDestroyable(bDestroyable, bRaiseable, bSelectableWhenDead)
	if bRaiseable == nil then bRaiseable = true end
	bSelectableWhenDead = bSelectableWhenDead or false
	
	StackPushBoolean(bSelectableWhenDead)
	StackPushBoolean(bRaiseable)
	StackPushBoolean(bDestroyable)
	VM_ExecuteCommand(323, 3)
end

--  Set the locked state of oTarget, which can be a door or a placeable object.
function SetLocked(oTarget, bLocked)
	StackPushBoolean(bLocked)
	StackPushObject(oTarget)
	VM_ExecuteCommand(324, 2)
end

--  Get the locked state of oTarget, which can be a door or a placeable object.
function GetLocked(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(325, 1)
	return StackPopBoolean()
end

--  Use this in a trigger's OnClick event script to get the object that last
--  clicked on it.
--  This is identical to GetEnteringObject.
--  GetClickingObject() should not be called from a placeable's OnClick event,
--  instead use GetPlaceableLastClickedBy()
function GetClickingObject()
	VM_ExecuteCommand(326, 0)
	return StackPopObject()
end

--  Initialise oTarget to listen for the standard Associates commands.
function SetAssociateListenPatterns(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(327, 1)
end

--  Get the last weapon that oCreature used in an attack.
--  * Returns OBJECT_INVALID if oCreature did not attack, or has no weapon equipped.
function GetLastWeaponUsed(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(328, 1)
	return StackPopObject()
end

--  Use oPlaceable.
function ActionInteractObject(oPlaceable)
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(329, 1)
end

--  Get the last object that used the placeable object that is calling this function.
--  * Returns OBJECT_INVALID if it is called by something other than a placeable or
--    a door.
function GetLastUsedBy()
	VM_ExecuteCommand(330, 0)
	return StackPopObject()
end

--  Returns the ability modifier for the specified ability
--  Get oCreature's ability modifier for nAbility.
--  - nAbility: ABILITY_*
--  - oCreature
function GetAbilityModifier(nAbility)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nAbility)
	VM_ExecuteCommand(331, 2)
	return StackPopInteger()
end

--  Determined whether oItem has been identified.
function GetIdentified(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(332, 1)
	return StackPopBoolean()
end

--  Set whether oItem has been identified.
function SetIdentified(oItem, bIdentified)
	StackPushBoolean(bIdentified)
	StackPushObject(oItem)
	VM_ExecuteCommand(333, 2)
end

--  Summon an Animal Companion
function SummonAnimalCompanion(oMaster)
	oMaster = oMaster or OBJECT_SELF
	
	StackPushObject(oMaster)
	VM_ExecuteCommand(334, 1)
end

--  Summon a Familiar
function SummonFamiliar(oMaster)
	oMaster = oMaster or OBJECT_SELF
	
	StackPushObject(oMaster)
	VM_ExecuteCommand(335, 1)
end

--  Get the last blocking door encountered by the caller of this function.
--  * Returns OBJECT_INVALID if the caller is not a valid creature.
function GetBlockingDoor()
	VM_ExecuteCommand(336, 0)
	return StackPopObject()
end

--  - oTargetDoor
--  - nDoorAction: DOOR_ACTION_*
--  * Returns TRUE if nDoorAction can be performed on oTargetDoor.
function GetIsDoorActionPossible(oTargetDoor, nDoorAction)
	StackPushInteger(nDoorAction)
	StackPushObject(oTargetDoor)
	VM_ExecuteCommand(337, 2)
	return StackPopBoolean()
end

--  Perform nDoorAction on oTargetDoor.
function DoDoorAction(oTargetDoor, nDoorAction)
	StackPushInteger(nDoorAction)
	StackPushObject(oTargetDoor)
	VM_ExecuteCommand(338, 2)
end

--  Get the first item in oTarget's inventory (start to cycle through oTarget's
--  inventory).
--  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
--    or if no item is found.
function GetFirstItemInInventory(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(339, 1)
	return StackPopObject()
end

--  Get the next item in oTarget's inventory (continue to cycle through oTarget's
--  inventory).
--  * Returns OBJECT_INVALID if the caller is not a creature, item, placeable or store,
--    or if no item is found.
function GetNextItemInInventory(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(340, 1)
	return StackPopObject()
end

--  A creature can have up to three classes.  This function determines the
--  creature's class (CLASS_TYPE_*) based on nClassPosition.
--  - nClassPosition: 1, 2 or 3
--  - oCreature
--  * Returns CLASS_TYPE_INVALID if the oCreature does not have a class in
--    nClassPosition (i.e. a single-class creature will only have a value in
--    nClassLocation=1) or if oCreature is not a valid creature.
function GetClassByPosition(nClassPosition, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nClassPosition)
	VM_ExecuteCommand(341, 2)
	return StackPopInteger()
end

--  A creature can have up to three classes.  This function determines the
--  creature's class level based on nClass Position.
--  - nClassPosition: 1, 2 or 3
--  - oCreature
--  * Returns 0 if oCreature does not have a class in nClassPosition
--    (i.e. a single-class creature will only have a value in nClassLocation=1)
--    or if oCreature is not a valid creature.
function GetLevelByPosition(nClassPosition, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nClassPosition)
	VM_ExecuteCommand(342, 2)
	return StackPopInteger()
end

--  Determine the levels that oCreature holds in nClassType.
--  - nClassType: CLASS_TYPE_*
--  - oCreature
function GetLevelByClass(nClassType, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nClassType)
	VM_ExecuteCommand(343, 2)
	return StackPopInteger()
end

--  Get the amount of damage of type nDamageType that has been dealt to the caller.
--  - nDamageType: DAMAGE_TYPE_*
function GetDamageDealtByType(nDamageType)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(344, 1)
	return StackPopInteger()
end

--  Get the total amount of damage that has been dealt to the caller.
function GetTotalDamageDealt()
	VM_ExecuteCommand(345, 0)
	return StackPopInteger()
end

--  Get the last object that damaged oObject
--  * Returns OBJECT_INVALID if the passed in object is not a valid object.
function GetLastDamager(oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	VM_ExecuteCommand(346, 1)
	return StackPopObject()
end

--  Get the last object that disarmed the trap on the caller.
--  * Returns OBJECT_INVALID if the caller is not a valid placeable, trigger or
--    door.
function GetLastDisarmed()
	VM_ExecuteCommand(347, 0)
	return StackPopObject()
end

--  Get the last object that disturbed the inventory of the caller.
--  * Returns OBJECT_INVALID if the caller is not a valid creature or placeable.
function GetLastDisturbed()
	VM_ExecuteCommand(348, 0)
	return StackPopObject()
end

--  Get the last object that locked the caller.
--  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
function GetLastLocked()
	VM_ExecuteCommand(349, 0)
	return StackPopObject()
end

--  Get the last object that unlocked the caller.
--  * Returns OBJECT_INVALID if the caller is not a valid door or placeable.
function GetLastUnlocked()
	VM_ExecuteCommand(350, 0)
	return StackPopObject()
end

--  Create a Skill Increase effect.
--  - nSkill: SKILL_*
--  - nValue
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
function EffectSkillIncrease(nSkill, nValue)
	StackPushInteger(nValue)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(351, 2)
	return StackPopEffect()
end

--  Get the type of disturbance (INVENTORY_DISTURB_*) that caused the caller's
--  OnInventoryDisturbed script to fire.  This will only work for creatures and
--  placeables.
function GetInventoryDisturbType()
	VM_ExecuteCommand(352, 0)
	return StackPopInteger()
end

--  get the item that caused the caller's OnInventoryDisturbed script to fire.
--  * Returns OBJECT_INVALID if the caller is not a valid object.
function GetInventoryDisturbItem()
	VM_ExecuteCommand(353, 0)
	return StackPopObject()
end

--  Get the henchman belonging to oMaster.
--  * Return OBJECT_INVALID if oMaster does not have a henchman.
--  -nNth: Which henchman to return.
function GetHenchman(oMaster, nNth)
	oMaster = oMaster or OBJECT_SELF
	nNth = nNth or 1
	
	StackPushInteger(nNth)
	StackPushObject(oMaster)
	VM_ExecuteCommand(354, 2)
	return StackPopObject()
end

--  Set eEffect to be versus a specific alignment.
--  - eEffect
--  - nLawChaos: ALIGNMENT_LAWFUL/ALIGNMENT_CHAOTIC/ALIGNMENT_ALL
--  - nGoodEvil: ALIGNMENT_GOOD/ALIGNMENT_EVIL/ALIGNMENT_ALL
function VersusAlignmentEffect(eEffect, nLawChaos, nGoodEvil)
	nLawChaos = nLawChaos or 0 --ALIGNMENT_ALL
	nGoodEvil = nGoodEvil or 0 --ALIGNMENT_ALL
	
	StackPushInteger(nGoodEvil)
	StackPushInteger(nLawChaos)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(355, 3)
	return StackPopEffect()
end

--  Set eEffect to be versus nRacialType.
--  - eEffect
--  - nRacialType: RACIAL_TYPE_*
function VersusRacialTypeEffect(eEffect, nRacialType)
	StackPushInteger(nRacialType)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(356, 2)
	return StackPopEffect()
end

--  Set eEffect to be versus traps.
function VersusTrapEffect(eEffect)
	StackPushEffect(eEffect)
	VM_ExecuteCommand(357, 1)
	return StackPopEffect()
end

--  Get the gender of oCreature.
function GetGender(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(358, 1)
	return StackPopInteger()
end

--  * Returns TRUE if tTalent is valid.
function GetIsTalentValid(tTalent)
	StackPushTalent(tTalent)
	VM_ExecuteCommand(359, 1)
	return StackPopBoolean()
end

--  Causes the action subject to move away from lMoveAwayFrom.
function ActionMoveAwayFromLocation(lMoveAwayFrom, bRun, fMoveAwayRange)
	bRun = bRun or false
	fMoveAwayRange = fMoveAwayRange or 40.0
	
	StackPushFloat(fMoveAwayRange)
	StackPushBoolean(bRun)
	StackPushLocation(lMoveAwayFrom)
	VM_ExecuteCommand(360, 3)
end

--  Get the target that the caller attempted to attack - this should be used in
--  conjunction with GetAttackTarget(). This value is set every time an attack is
--  made, and is reset at the end of combat.
--  * Returns OBJECT_INVALID if the caller is not a valid creature.
function GetAttemptedAttackTarget()
	VM_ExecuteCommand(361, 0)
	return StackPopObject()
end

--  Get the type (TALENT_TYPE_*) of tTalent.
function GetTypeFromTalent(tTalent)
	StackPushTalent(tTalent)
	VM_ExecuteCommand(362, 1)
	return StackPopInteger()
end

--  Get the ID of tTalent.  This could be a SPELL_*, FEAT_* or SKILL_*.
function GetIdFromTalent(tTalent) 
	StackPushTalent(tTalent)
	VM_ExecuteCommand(363, 1)
	return StackPopInteger()
end

--  Get the associate of type nAssociateType belonging to oMaster.
--  - nAssociateType: ASSOCIATE_TYPE_*
--  - nMaster
--  - nTh: Which associate of the specified type to return
--  * Returns OBJECT_INVALID if no such associate exists.
function GetAssociate(nAssociateType, oMaster, nNth)
	oMaster = oMaster or OBJECT_SELF
	inNth = nNth or 1
	
	StackPushInteger(nNth)
	StackPushObject(oMaster)
	StackPushInteger(nAssociateType)
	VM_ExecuteCommand(364, 3)
	return StackPopObject()
end

--  Add oHenchman as a henchman to oMaster
--  If oHenchman is either a DM or a player character, this will have no effect.
function AddHenchman(oMaster, oHenchman)
	oHenchman = oHenchman or OBJECT_SELF
	
	StackPushObject(oHenchman)
	StackPushObject(oMaster)
	VM_ExecuteCommand(365, 2)
end

--  Remove oHenchman from the service of oMaster, returning them to their original faction.
function RemoveHenchman(oMaster, oHenchman)
	oHenchman = oHenchman or OBJECT_SELF
	
	StackPushObject(oHenchman)
	StackPushObject(oMaster)
	VM_ExecuteCommand(366, 2)
	
end

--  Add a journal quest entry to oCreature.
--  - szPlotID: the plot identifier used in the toolset's Journal Editor
--  - nState: the state of the plot as seen in the toolset's Journal Editor
--  - oCreature
--  - bAllPartyMembers: If this is TRUE, the entry will show up in the journal of
--    everyone in the party
--  - bAllPlayers: If this is TRUE, the entry will show up in the journal of
--    everyone in the world
--  - bAllowOverrideHigher: If this is TRUE, you can set the state to a lower
--    number than the one it is currently on
function AddJournalQuestEntry(szPlotID, nState, oCreature, bAllPartyMembers, bAllPlayers, bAllowOverrideHigher)
	if bAllPartyMembers == nil then bAllPartyMembers = true end
	bAllPlayers = bAllPlayers or false
	bAllowOverrideHigher = bAllowOverrideHigher or false
	
	StackPushBoolean(bAllowOverrideHigher)
	StackPushBoolean(bAllPlayers)
	StackPushBoolean(bAllPartyMembers)
	StackPushObject(oCreature)
	StackPushInteger(nState)
	StackPushString(szPlotID)
	VM_ExecuteCommand(367, 6)
end

--  Remove a journal quest entry from oCreature.
--  - szPlotID: the plot identifier used in the toolset's Journal Editor
--  - oCreature
--  - bAllPartyMembers: If this is TRUE, the entry will be removed from the
--    journal of everyone in the party
--  - bAllPlayers: If this is TRUE, the entry will be removed from the journal of
--    everyone in the world
function RemoveJournalQuestEntry(szPlotID, oCreature, bAllPartyMembers, bAllPlayers)
	if bAllPartyMembers == nil then bAllPartyMembers = true end
	bAllPlayers = bAllPlayers or false
	
	StackPushBoolean(bAllPlayers)
	StackPushBoolean(bAllPartyMembers)
	StackPushObject(oCreature)
	StackPushString(szPlotID)
	VM_ExecuteCommand(368, 4)
end

--  Get the public part of the CD Key that oPlayer used when logging in.
--  - nSinglePlayerCDKey: If set to TRUE, the player's public CD Key will 
--    be returned when the player is playing in single player mode 
--    (otherwise returns an empty string in single player mode).
function GetPCPublicCDKey(oPlayer, bSinglePlayerCDKey)
	bSinglePlayerCDKey = bSinglePlayerCDKey or false
	
	StackPushBoolean(bSinglePlayerCDKey)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(369, 2)
	return StackPopString()
end

--  Get the IP address from which oPlayer has connected.
function GetPCIPAddress(oPlayer)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(370, 1)
	return StackPopString()
end

--  Get the name of oPlayer.
function GetPCPlayerName(oPlayer)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(371, 1)
	return StackPopString()
end

--  Sets oPlayer and oTarget to like each other.
function SetPCLike(oPlayer, oTarget)
	StackPushObject(oTarget)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(372, 2)
end

--  Sets oPlayer and oTarget to dislike each other.
function SetPCDislike(oPlayer, oTarget)
	StackPushObject(oTarget)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(373, 2)
end

--  Send a server message (szMessage) to the oPlayer.
function SendMessageToPC(oPlayer, sMessage) 
	StackPushString(sMessage)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(374, 2)
end

--  Get the target at which the caller attempted to cast a spell.
--  This value is set every time a spell is cast and is reset at the end of
--  combat.
--  * Returns OBJECT_INVALID if the caller is not a valid creature.
function GetAttemptedSpellTarget()
	VM_ExecuteCommand(375, 0)
	return StackPopObject()
end

--  Get the last creature that opened the caller.
--  * Returns OBJECT_INVALID if the caller is not a valid door, placeable or store.
function GetLastOpenedBy()
	VM_ExecuteCommand(376, 0)
	return StackPopObject()
end

--  Determines the number of times that oCreature has nSpell memorised.
--  - nSpell: SPELL_*
--  - oCreature
function GetHasSpell(nSpell, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(377, 2)
	return StackPopInteger()
end

--  Open oStore for oPC.
--  - nBonusMarkUp is added to the stores default mark up percentage on items sold (-100 to 100)
--  - nBonusMarkDown is added to the stores default mark down percentage on items bought (-100 to 100)
function OpenStore(oStore, oPC, nBonusMarkUp, nBonusMarkDown)
	nBonusMarkUp = nBonusMarkUp or 0
	nBonusMarkDown = nBonusMarkDown or 0
	
	StackPushInteger(nBonusMarkDown)
	StackPushInteger(nBonusMarkUp)
	StackPushObject(oPC)
	StackPushObject(oStore)
	VM_ExecuteCommand(378, 4)
end

--  Create a Turned effect.
--  Turned effects are supernatural by default.
function EffectTurned()
	VM_ExecuteCommand(379, 0)
	return StackPopEffect()
end

--  Get the first member of oMemberOfFaction's faction (start to cycle through
--  oMemberOfFaction's faction).
--  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
function GetFirstFactionMember(oMemberOfFaction, bPCOnly)
	if bPCOnly == nil then bPCOnly = true end
	
	StackPushInteger(bPCOnly)
	StackPushObject(oMemberOfFaction)
	VM_ExecuteCommand(380, 2)
	return StackPopObject()
end

--  Get the next member of oMemberOfFaction's faction (continue to cycle through
--  oMemberOfFaction's faction).
--  * Returns OBJECT_INVALID if oMemberOfFaction's faction is invalid.
function GetNextFactionMember(oMemberOfFaction, bPCOnly)
	if bPCOnly == nil then bPCOnly = true end
	
	StackPushBoolean(bPCOnly)
	StackPushObject(oMemberOfFaction)
	VM_ExecuteCommand(381, 2)
	return StackPopObject()
end

--  Force the action subject to move to lDestination.
function ActionForceMoveToLocation(lDestination, bRun, fTimeout)
	bRun = bRun or false
	fTimeout = fTimeout or 30.0
	
	StackPushFloat(fTimeout)
	StackPushInteger(bRun)
	StackPushLocation(lDestination)
	VM_ExecuteCommand(382, 3)
end

--  Force the action subject to move to oMoveTo.
function ActionForceMoveToObject(oMoveTo, bRun, fRange, fTimeout)
	bRun = bRun or false
	fRange = fRange or 1.0
	fTimeout = fTimeout or 30.0
	
	StackPushFloat(fTimeout)
	StackPushFloat(fRange)
	StackPushInteger(bRun)
	StackPushObject(oMoveTo)
	VM_ExecuteCommand(383, 4)
end

--  Get the experience assigned in the journal editor for szPlotID.
function GetJournalQuestExperience(szPlotID)
	StackPushString(szPlotID)
	VM_ExecuteCommand(384, 1)
	return StackPopInteger()
end

--  Jump to oToJumpTo (the action is added to the top of the action queue).
function JumpToObject(oToJumpTo, bWalkStraightLineToPoint)
	if bWalkStraightLineToPoint == nil then bWalkStraightLineToPoint = true end
	
	StackPushBoolean(bWalkStraightLineToPoint)
	StackPushObject(oToJumpTo)
	VM_ExecuteCommand(385, 2)
	
end

--  Set whether oMapPin is enabled.
--  - oMapPin
--  - nEnabled: 0=Off, 1=On
function SetMapPinEnabled(oMapPin, bEnabled)
	StackPushBoolean(bEnabled)
	StackPushObject(oMapPin)
	VM_ExecuteCommand(386, 2)
end

--  Create a Hit Point Change When Dying effect.
--  - fHitPointChangePerRound: this can be positive or negative, but not zero.
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if fHitPointChangePerRound is 0.
function EffectHitPointChangeWhenDying(fHitPointChangePerRound)
	StackPushFloat(fHitPointChangePerRound)
	VM_ExecuteCommand(387, 1)
	return StackPopEffect()
end

--  Spawn a GUI panel for the client that controls oPC.
--  - oPC
--  - nGUIPanel: GUI_PANEL_*
--  * Nothing happens if oPC is not a player character or if an invalid value is
--    used for nGUIPanel.
function PopUpGUIPanel(oPC, nGUIPanel)
	StackPushInteger(nGUIPanel)
	StackPushObject(oPC)
	VM_ExecuteCommand(388, 2)
end

--  Clear all personal feelings that oSource has about oTarget.
function ClearPersonalReputation(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(389, 2)
end

--  oSource will temporarily be friends towards oTarget.
--  bDecays determines whether the personal reputation value decays over time
--  fDurationInSeconds is the length of time that the temporary friendship lasts
--  Make oSource into a temporary friend of oTarget using personal reputation.
--  - oTarget
--  - oSource
--  - bDecays: If this is TRUE, the friendship decays over fDurationInSeconds
--    otherwise it is indefinite.
--  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
--    the friendship lasts.
--  Note: If bDecays is TRUE, the personal reputation amount decreases in size
--  over fDurationInSeconds. Friendship will only be in effect as long as
--  (faction reputation + total personal reputation) >= REPUTATION_TYPE_FRIEND.
function SetIsTemporaryFriend(oTarget, oSource, bDecays, fDurationInSeconds)
	oSource = oSource or OBJECT_SELF
	bDecays = bDecays or false
	fDurationInSeconds = fDurationInSeconds or 180.0
	
	StackPushFloat(fDurationInSeconds)
	StackPushBoolean(bDecays)
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(390, 4)
end

--  Make oSource into a temporary enemy of oTarget using personal reputation.
--  - oTarget
--  - oSource
--  - bDecays: If this is TRUE, the enmity decays over fDurationInSeconds
--    otherwise it is indefinite.
--  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
--    the enmity lasts.
--  Note: If bDecays is TRUE, the personal reputation amount decreases in size
--  over fDurationInSeconds. Enmity will only be in effect as long as
--  (faction reputation + total personal reputation) <= REPUTATION_TYPE_ENEMY.
function SetIsTemporaryEnemy(oTarget, oSource, bDecays, fDurationInSeconds)
	oSource = oSource or OBJECT_SELF
	bDecays = bDecays or false
	fDurationInSeconds = fDurationInSeconds or 180.0
	
	StackPushFloat(fDurationInSeconds)
	StackPushBoolean(bDecays)
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(391, 4)
end

--  Make oSource temporarily neutral to oTarget using personal reputation.
--  - oTarget
--  - oSource
--  - bDecays: If this is TRUE, the neutrality decays over fDurationInSeconds
--    otherwise it is indefinite.
--  - fDurationInSeconds: This is only used if bDecays is TRUE, it is how long
--    the neutrality lasts.
--  Note: If bDecays is TRUE, the personal reputation amount decreases in size
--  over fDurationInSeconds. Neutrality will only be in effect as long as
--  (faction reputation + total personal reputation) > REPUTATION_TYPE_ENEMY and
--  (faction reputation + total personal reputation) < REPUTATION_TYPE_FRIEND.
function SetIsTemporaryNeutral(oTarget, oSource, bDecays, fDurationInSeconds)
	oSource = oSource or OBJECT_SELF
	bDecays = bDecays or false
	fDurationInSeconds = fDurationInSeconds or 180.0
	
	StackPushFloat(fDurationInSeconds)
	StackPushBoolean(bDecays)
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(392, 4)
end

--  Gives nXpAmount to oCreature.
function GiveXPToCreature(oCreature, nXpAmount)
	StackPushInteger(nXpAmount)
	StackPushObject(oCreature)
	VM_ExecuteCommand(393, 2)
end

--  Sets oCreature's experience to nXpAmount.
function SetXP(oCreature, nXpAmount)
	StackPushInteger(nXpAmount)
	StackPushObject(oCreature)
	VM_ExecuteCommand(394, 2)
end

--  Get oCreature's experience.
function GetXP(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(395, 1)
	return StackPopInteger()
end

--  Convert nInteger to hex, returning the hex value as a string.
--  * Return value has the format "0x????????" where each ? will be a hex digit
--    (8 digits in total).
function IntToHexString(nInteger)
	StackPushInteger(nInteger)
	VM_ExecuteCommand(396, 1)
	return StackPopString()
end

--  Get the base item type (BASE_ITEM_*) of oItem.
--  * Returns BASE_ITEM_INVALID if oItem is an invalid item.
function GetBaseItemType(oItem) 
	StackPushObject(oItem)
	VM_ExecuteCommand(397, 1)
	return StackPopInteger()
end

--  Determines whether oItem has nProperty.
--  - oItem
--  - nProperty: ITEM_PROPERTY_*
--  * Returns FALSE if oItem is not a valid item, or if oItem does not have
--    nProperty.
function GetItemHasItemProperty(oItem, nProperty)
	StackPushInteger(nProperty)
	StackPushObject(oItem)
	VM_ExecuteCommand(398, 2)
	return StackPopBoolean()
end

--  The creature will equip the melee weapon in its possession that can do the
--  most damage. If no valid melee weapon is found, it will equip the most
--  damaging range weapon. This function should only ever be called in the
--  EndOfCombatRound scripts, because otherwise it would have to stop the combat
--  round to run simulation.
--  - oVersus: You can try to get the most damaging weapon against oVersus
--  - bOffHand
function ActionEquipMostDamagingMelee(oVersus, bOffHand)
	oVersus = oVersus or OBJECT_INVALID
	bOffHand = bOffHand or false
	
	StackPushBoolean(bOffHand)
	StackPushObject(oVersus)
	VM_ExecuteCommand(399, 2)
end

--  The creature will equip the range weapon in its possession that can do the
--  most damage.
--  If no valid range weapon can be found, it will equip the most damaging melee
--  weapon.
--  - oVersus: You can try to get the most damaging weapon against oVersus
function ActionEquipMostDamagingRanged(oVersus)
	oVersus = oVersus or OBJECT_INVALID
	
	StackPushObject(oVersus)
	VM_ExecuteCommand(400, 1)
end

--  Get the Armour Class of oItem.
--  * Return 0 if the oItem is not a valid item, or if oItem has no armour value.
function GetItemACValue(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(401, 1)
	return StackPopInteger()
end

--  The creature will rest if not in combat and no enemies are nearby.
--  - bCreatureToEnemyLineOfSightCheck: TRUE to allow the creature to rest if enemies
--                                      are nearby, but the creature can't see the enemy.
--                                      FALSE the creature will not rest if enemies are
--                                      nearby regardless of whether or not the creature
--                                      can see them, such as if an enemy is close by,
--                                      but is in a different room behind a closed door.
function ActionRest(bCreatureToEnemyLineOfSightCheck)
	bCreatureToEnemyLineOfSightCheck = bCreatureToEnemyLineOfSightCheck or false
	
	StackPushBoolean(bCreatureToEnemyLineOfSightCheck)
	VM_ExecuteCommand(402, 1)
end

--  Expose/Hide the entire map of oArea for oPlayer.
--  - oArea: The area that the map will be exposed/hidden for.
--  - oPlayer: The player the map will be exposed/hidden for.
--  - bExplored: TRUE/FALSE. Whether the map should be completely explored or hidden.
function ExploreAreaForPlayer(oArea, oPlayer, bExplored)
	if bExplored == nil then bExplored = true end
	
	StackPushBoolean(bExplored)
	StackPushObject(oPlayer)
	StackPushObject(oArea)
	VM_ExecuteCommand(403, 3)
end

--  The creature will equip the armour in its possession that has the highest
--  armour class.
function ActionEquipMostEffectiveArmor()
	VM_ExecuteCommand(404, 0)
end

--  * Returns TRUE if it is currently day.
function GetIsDay()
	VM_ExecuteCommand(405, 0)
	return StackPopBoolean()
end

--  * Returns TRUE if it is currently night.
function GetIsNight()
	VM_ExecuteCommand(406, 0)
	return StackPopBoolean()
end

--  * Returns TRUE if it is currently dawn.
function GetIsDawn()
	VM_ExecuteCommand(407, 0)
	return StackPopBoolean()
end

--  * Returns TRUE if it is currently dusk.
function GetIsDusk()
	VM_ExecuteCommand(408, 0)
	return StackPopBoolean()
end

--  * Returns TRUE if oCreature was spawned from an encounter.
function GetIsEncounterCreature(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(409, 1)
	return StackPopBoolean()
end

--  Use this in an OnPlayerDying module script to get the last player who is dying.
function GetLastPlayerDying()
	VM_ExecuteCommand(410, 0)
	return StackPopObject()
end

--  Get the starting location of the module.
function GetStartingLocation()
	VM_ExecuteCommand(411, 0)
	return StackPopLocation()
end

--  Make oCreatureToChange join one of the standard factions.
--  ** This will only work on an NPC **
--  - nStandardFaction: STANDARD_FACTION_*
function ChangeToStandardFaction(oCreatureToChange,nStandardFaction )
	StackPushInteger(nStandardFaction)
	StackPushObject(oCreatureToChange)
	VM_ExecuteCommand(412, 2)
end

--  Play oSound.
function SoundObjectPlay(oSound) 
	StackPushObject(oSound)
	VM_ExecuteCommand(413, 1)
end

--  Stop playing oSound.
function SoundObjectStop(oSound) 
	StackPushObject(oSound)
	VM_ExecuteCommand(414, 1)
end

--  Set the volume of oSound.
--  - oSound
--  - nVolume: 0-127
function SoundObjectSetVolume(oSound, nVolume) 
	StackPushInteger(nVolume)
	StackPushObject(oSound)
	VM_ExecuteCommand(415, 2)
end

--  Set the position of oSound.
function SoundObjectSetPosition(oSound, vPosition)
	StackPushVector(vPosition)
	StackPushObject(oSound)
	VM_ExecuteCommand(416, 2)
end

--  Immediately speak a conversation one-liner.
--  - sDialogResRef
--  - oTokenTarget: This must be specified if there are creature-specific tokens
--    in the string.
function SpeakOneLinerConversation(sDialogResRef, oTokenTarget)
	sDialogResRef = sDialogResRef or ""
	oTokenTarget = oTokenTarget or 32767 --OBJECT_TYPE_INVALID
	
	StackPushObject(oTokenTarget)
	StackPushString(sDialogResRef)
	VM_ExecuteCommand(417, 2)
end

--  Get the amount of gold possessed by oTarget.
function GetGold(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(418, 1)
	return StackPopInteger()
end

--  Use this in an OnRespawnButtonPressed module script to get the object id of
--  the player who last pressed the respawn button.
function GetLastRespawnButtonPresser()
	VM_ExecuteCommand(419, 0)
	return StackPopObject()
end

--  * Returns TRUE if oCreature is the Dungeon Master.
--  Note: This will return FALSE if oCreature is a DM Possessed creature.
--  To determine if oCreature is a DM Possessed creature, use GetIsDMPossessed()
function GetIsDM(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(420, 1)
	return StackPopBoolean()
end

--  Play a voice chat.
--  - nVoiceChatID: VOICE_CHAT_*
--  - oTarget
function PlayVoiceChat(nVoiceChatID, oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	StackPushInteger(nVoiceChatID)
	VM_ExecuteCommand(421, 2)
end

--  * Returns TRUE if the weapon equipped is capable of damaging oVersus.
function GetIsWeaponEffective(oVersus, bOffHand)
	oVersus = oVersus or OBJECT_INVALID
	bOffHand = bOffHand or false
	
	StackPushBoolean(bOffHand)
	StackPushObject(oVersus)
	VM_ExecuteCommand(422, 2)
	return StackPopBoolean()
end

--  Use this in a SpellCast script to determine whether the spell was considered
--  harmful.
--  * Returns TRUE if the last spell cast was harmful.
function GetLastSpellHarmful()
	VM_ExecuteCommand(423, 0)
	return StackPopBoolean()
end

--  Activate oItem.
function EventActivateItem(oItem, lTarget, oTarget)
	oTarget = oTarget or OBJECT_INVALID

	StackPushObject(oTarget)
	StackPushLocation(lTarget)
	StackPushObject(oItem)
	VM_ExecuteCommand(424, 3)
	return StackPopEvent()
end

--  Play the background music for oArea.
function MusicBackgroundPlay(oArea) 
	StackPushObject(oArea)
	VM_ExecuteCommand(425, 1)
end

--  Stop the background music for oArea.
function MusicBackgroundStop(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(426, 1)
end

--  Set the delay for the background music for oArea.
--  - oArea
--  - nDelay: delay in milliseconds
function MusicBackgroundSetDelay(oArea, nDelay)
	StackPushInteger(nDelay)
	StackPushObject(oArea)
	VM_ExecuteCommand(427, 2)
end

--  Change the background day track for oArea to nTrack.
--  - oArea
--  - nTrack
function MusicBackgroundChangeDay(oArea, nTrack)
	StackPushInteger(nTrack)
	StackPushObject(oArea)
	VM_ExecuteCommand(428, 2)
end

--  Change the background night track for oArea to nTrack.
--  - oArea
--  - nTrack
function MusicBackgroundChangeNight(oArea, nTrack)
	StackPushInteger(nTrack)
	StackPushObject(oArea)
	VM_ExecuteCommand(429, 2)
end

--  Play the battle music for oArea.
function MusicBattlePlay(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(430, 1)
end

--  Stop the battle music for oArea.
function MusicBattleStop(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(431, 1)
end

--  Change the battle track for oArea.
--  - oArea
--  - nTrack
function MusicBattleChange(oArea, nTrack)
	StackPushInteger(nTrack)
	StackPushObject(oArea)
	VM_ExecuteCommand(432, 2)
end

--  Play the ambient sound for oArea.
function AmbientSoundPlay(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(433, 1)
end

--  Stop the ambient sound for oArea.
function AmbientSoundStop(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(434, 1)
end

--  Change the ambient day track for oArea to nTrack.
--  - oArea
--  - nTrack
function AmbientSoundChangeDay(oArea, nTrack)
	StackPushInteger(nTrack)
	StackPushObject(oArea)
	VM_ExecuteCommand(435, 2)
end

--  Change the ambient night track for oArea to nTrack.
--  - oArea
--  - nTrack
function AmbientSoundChangeNight(oArea, nTrack)
	StackPushInteger(nTrack)
	StackPushObject(oArea)
	VM_ExecuteCommand(436, 2)
end

--  Get the object that killed the caller.
function GetLastKiller()
	VM_ExecuteCommand(437, 0)
	return StackPopObject()
end

--  Use this in a spell script to get the item used to cast the spell.
function GetSpellCastItem()
	VM_ExecuteCommand(438, 0)
	return StackPopObject()
end

--  Use this in an OnItemActivated module script to get the item that was activated.
function GetItemActivated()
	VM_ExecuteCommand(439, 0)
	return StackPopObject()
end

--  Use this in an OnItemActivated module script to get the creature that
--  activated the item.
function GetItemActivator()
	VM_ExecuteCommand(440, 0)
	return StackPopObject()
end

--  Use this in an OnItemActivated module script to get the location of the item's
--  target.
function GetItemActivatedTargetLocation()
	VM_ExecuteCommand(441, 0)
	return StackPopLocation()
end

--  Use this in an OnItemActivated module script to get the item's target.
function GetItemActivatedTarget()
	VM_ExecuteCommand(442, 0)
	return StackPopObject()
end

--  * Returns TRUE if oObject (which is a placeable or a door) is currently open.
function GetIsOpen(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(443, 1)
	return StackPopBoolean()
end

--  Take nAmount of gold from oCreatureToTakeFrom.
--  - nAmount
--  - oCreatureToTakeFrom: If this is not a valid creature, nothing will happen.
--  - bDestroy: If this is TRUE, the caller will not get the gold.  Instead, the
--    gold will be destroyed and will vanish from the game.
function TakeGoldFromCreature(nAmount, oCreatureToTakeFrom, bDestroy)
	bDestroy = bDestroy or false
	
	StackPushBoolean(bDestroy)
	StackPushObject(oCreatureToTakeFrom)
	StackPushInteger(nAmount)
	VM_ExecuteCommand(444, 3)
end

--  Determine whether oObject is in conversation.
function IsInConversation(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(445, 1)
	return StackPopBoolean()
end

--  Create an Ability Decrease effect.
--  - nAbility: ABILITY_*
--  - nModifyBy: This is the amount by which to decrement the ability
function EffectAbilityDecrease(nAbility, nModifyBy)
	StackPushInteger(nModifyBy)
	StackPushInteger(nAbility)
	VM_ExecuteCommand(446, 2)
	return StackPopEffect()
end

--  Create an Attack Decrease effect.
--  - nPenalty
--  - nModifierType: ATTACK_BONUS_*
function EffectAttackDecrease(nPenalty, nModifierType)
	nModifierType = nModifierType or 0 --ATTACK_BONUS_MISC
	
	StackPushInteger(nModifierType)
	StackPushInteger(nPenalty)
	VM_ExecuteCommand(447, 2)
	return StackPopEffect()
end

--  Create a Damage Decrease effect.
--  - nPenalty
--  - nDamageType: DAMAGE_TYPE_*
function EffectDamageDecrease(nPenalty, nDamageType)
	nDamageType = nDamageType or 8 --DAMAGE_TYPE_MAGICAL

	StackPushInteger(nDamageType)
	StackPushInteger(nPenalty)
	VM_ExecuteCommand(448, 2)
	return StackPopEffect()
end

--  Create a Damage Immunity Decrease effect.
--  - nDamageType: DAMAGE_TYPE_*
--  - nPercentImmunity
function EffectDamageImmunityDecrease(nDamageType, nPercentImmunity)
	StackPushInteger(nPercentImmunity)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(449, 2)
	return StackPopEffect()
end

--  Create an AC Decrease effect.
--  - nValue
--  - nModifyType: AC_*
--  - nDamageType: DAMAGE_TYPE_*
--    * Default value for nDamageType should only ever be used in this function prototype.
function EffectACDecrease(nValue, nModifyType, nDamageType)
	nModifyType = nModifyType or 0 --AC_DODGE_BONUS
	nDamageType = nDamageType or 4103 --AC_VS_DAMAGE_TYPE_ALL
	
	StackPushInteger(nDamageType)
	StackPushInteger(nModifyType)
	StackPushInteger(nValue)
	VM_ExecuteCommand(450, 3)
	return StackPopEffect()
end

--  Create a Movement Speed Decrease effect.
--  - nPercentChange - range 0 through 99
--  eg.
--     0 = no change in speed
--    50 = 50% slower
--    99 = almost immobile
function EffectMovementSpeedDecrease(nPercentChange)
	StackPushInteger(nPercentChange)
	VM_ExecuteCommand(451, 1)
	return StackPopEffect()
end

--  Create a Saving Throw Decrease effect.
--  - nSave: SAVING_THROW_* (not SAVING_THROW_TYPE_*)
--           SAVING_THROW_ALL
--           SAVING_THROW_FORT
--           SAVING_THROW_REFLEX
--           SAVING_THROW_WILL 
--  - nValue: size of the Saving Throw decrease
--  - nSaveType: SAVING_THROW_TYPE_* (e.g. SAVING_THROW_TYPE_ACID )
function EffectSavingThrowDecrease(nSave, nValue, nSaveType)
	nSaveType = nSaveType or 0 --SAVING_THROW_TYPE_ALL
	
	StackPushInteger(nSaveType)
	StackPushInteger(nValue)
	StackPushInteger(nSave)
	VM_ExecuteCommand(452, 3)
	return StackPopEffect()
end

--  Create a Skill Decrease effect.
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nSkill is invalid.
function EffectSkillDecrease(nSkill, nValue)
	StackPushInteger(nValue)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(453, 2)
	return StackPopEffect()
end

--  Create a Spell Resistance Decrease effect.
function EffectSpellResistanceDecrease(nValue)  
	StackPushInteger(nValue)
	VM_ExecuteCommand(454, 1)
	return StackPopEffect()
end

--  Determine whether oTarget is a plot object.
function GetPlotFlag(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(455, 1)
	return StackPopBoolean()
end

--  Set oTarget's plot object status.
function SetPlotFlag(oTarget, bPlotFlag)
	StackPushBoolean(bPlotFlag)
	StackPushObject(oTarget)
	VM_ExecuteCommand(456, 2)
end

--  Create an Invisibility effect.
--  - nInvisibilityType: INVISIBILITY_TYPE_*
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nInvisibilityType
--    is invalid.
function EffectInvisibility(nInvisibilityType)
	StackPushInteger(nInvisibilityType)
	VM_ExecuteCommand(457, 1)
	return StackPopEffect()
end

--  Create a Concealment effect.
--  - nPercentage: 1-100 inclusive
--  - nMissChanceType: MISS_CHANCE_TYPE_*
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
--    nPercentage > 100.
function EffectConcealment(nPercentage, nMissType)
	nMissType = nMissType or 0 --MISS_CHANCE_TYPE_NORMAL
	
	StackPushInteger(nMissType)
	StackPushInteger(nPercentage)
	VM_ExecuteCommand(458, 2)
	return StackPopEffect()
end

--  Create a Darkness effect.
function EffectDarkness()
	VM_ExecuteCommand(459, 0)
	return StackPopEffect()
end

--  Create a Dispel Magic All effect.
--  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
--  cause the dispel effect to use the level of the creature that created the
--  effect.
function EffectDispelMagicAll(nCasterLevel)
	nCasterLevel = nCasterLevel or 0 --USE_CREATURE_LEVEL
	
	StackPushInteger(nCasterLevel)
	VM_ExecuteCommand(460, 1)
	return StackPopEffect()
end

--  Create an Ultravision effect.
function EffectUltravision()
	VM_ExecuteCommand(461, 0)
	return StackPopEffect()
end

--  Create a Negative Level effect.
--  - nNumLevels: the number of negative levels to apply.
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nNumLevels > 100.
function EffectNegativeLevel(nNumLevels, bHPBonus)
	bHPBonus = bHPBonus or false
	
	StackPushBoolean(bHPBonus)
	StackPushInteger(nNumLevels)
	VM_ExecuteCommand(462, 2)
	return StackPopEffect()
end

--  Create a Polymorph effect.
function EffectPolymorph(nPolymorphSelection, bLocked)
	bLocked = bLocked or false
	
	StackPushBoolean(bLocked)
	StackPushInteger(nPolymorphSelection)
	VM_ExecuteCommand(463, 2)
	return StackPopEffect()
end

--  Create a Sanctuary effect.
--  - nDifficultyClass: must be a non-zero, positive number
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nDifficultyClass <= 0.
function EffectSanctuary(nDifficultyClass)
	StackPushInteger(nDifficultyClass)
	VM_ExecuteCommand(464, 1)
	return StackPopEffect()
end

--  Create a True Seeing effect.
function EffectTrueSeeing()
	VM_ExecuteCommand(465, 0)
	return StackPopEffect()
end

--  Create a See Invisible effect.
function EffectSeeInvisible()
	VM_ExecuteCommand(466, 0)
	return StackPopEffect()
end

--  Create a Time Stop effect.
function EffectTimeStop()
	VM_ExecuteCommand(467, 0)
	return StackPopEffect()
end

--  Create a Blindness effect.
function EffectBlindness()
	VM_ExecuteCommand(468, 0)
	return StackPopEffect()
end

--  Determine whether oSource has a friendly reaction towards oTarget, depending
--  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
--  oSource's Like/Dislike setting for oTarget.
--  Note: If you just want to know how two objects feel about each other in terms
--  of faction and personal reputation, use GetIsFriend() instead.
--  * Returns TRUE if oSource has a friendly reaction towards oTarget
function GetIsReactionTypeFriendly(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(469, 2)
	return StackPopBoolean()
end

--  Determine whether oSource has a neutral reaction towards oTarget, depending
--  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
--  oSource's Like/Dislike setting for oTarget.
--  Note: If you just want to know how two objects feel about each other in terms
--  of faction and personal reputation, use GetIsNeutral() instead.
--  * Returns TRUE if oSource has a neutral reaction towards oTarget
function GetIsReactionTypeNeutral(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(470, 2)
	return StackPopBoolean()
end

--  Determine whether oSource has a Hostile reaction towards oTarget, depending
--  on the reputation, PVP setting and (if both oSource and oTarget are PCs),
--  oSource's Like/Dislike setting for oTarget.
--  Note: If you just want to know how two objects feel about each other in terms
--  of faction and personal reputation, use GetIsEnemy() instead.
--  * Returns TRUE if oSource has a hostile reaction towards oTarget
function GetIsReactionTypeHostile(oTarget, oSource)
	oSource = oSource or OBJECT_SELF
	
	StackPushObject(oSource)
	StackPushObject(oTarget)
	VM_ExecuteCommand(471, 2)
	return StackPopBoolean()
end

--  Create a Spell Level Absorption effect.
--  - nMaxSpellLevelAbsorbed: maximum spell level that will be absorbed by the
--    effect
--  - nTotalSpellLevelsAbsorbed: maximum number of spell levels that will be
--    absorbed by the effect
--  - nSpellSchool: SPELL_SCHOOL_*
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if:
--    nMaxSpellLevelAbsorbed is not between -1 and 9 inclusive, or nSpellSchool
--    is invalid.
function EffectSpellLevelAbsorption(nMaxSpellLevelAbsorbed, nTotalSpellLevelsAbsorbed, nSpellSchool)
	nTotalSpellLevelsAbsorbed = nTotalSpellLevelsAbsorbed or 0
	nSpellSchool = nSpellSchool or 0 --SPELL_SCHOOL_GENERAL
	
	StackPushInteger(nSpellSchool)
	StackPushInteger(nTotalSpellLevelsAbsorbed)
	StackPushInteger(nMaxSpellLevelAbsorbed)
	VM_ExecuteCommand(472, 3)
	return StackPopEffect()
end

--  Create a Dispel Magic Best effect.
--  If no parameter is specified, USE_CREATURE_LEVEL will be used. This will
--  cause the dispel effect to use the level of the creature that created the
--  effect.
function EffectDispelMagicBest(nCasterLevel)
	nCasterLevel = nCasterLevel or 0 --USE_CREATURE_LEVEL
	
	StackPushInteger(nCasterLevel)
	VM_ExecuteCommand(473, 1)
	return StackPopEffect()
end

--  Try to send oTarget to a new server defined by sIPaddress.
--  - oTarget
--  - sIPaddress: this can be numerical "192.168.0.84" or alphanumeric
--    "www.bioware.com". It can also contain a port "192.168.0.84:5121" or
--    "www.bioware.com:5121" if the port is not specified, it will default to
--    5121.
--  - sPassword: login password for the destination server
--  - sWaypointTag: if this is set, after portalling the character will be moved
--    to this waypoint if it exists
--  - bSeamless: if this is set, the client wil not be prompted with the
--    information window telling them about the server, and they will not be
--    allowed to save a copy of their character if they are using a local vault
--    character.
function ActivatePortal(oTarget, sIPaddress, sPassword, sWaypointTag, bSeemless)
	sIPaddress = sIPaddress or ""
	sPassword = sPassword or ""
	sWaypointTag = sWaypointTag or ""
	bSeemless = bSeemless or false
	
	StackPushBoolean(bSeemless)
	StackPushString(sWaypointTag)
	StackPushString(sPassword)
	StackPushString(sIPaddress)
	StackPushObject(oTarget)
	VM_ExecuteCommand(474, 5)
end

--  Get the number of stacked items that oItem comprises.
function GetNumStackedItems(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(475, 1)
	return StackPopInteger()
end

--  Use this on an NPC to cause all creatures within a 10-metre radius to stop
--  what they are doing and sets the NPC's enemies within this range to be
--  neutral towards the NPC for roughly 3 minutes. If this command is run on a PC
--  or an object that is not a creature, nothing will happen.
function SurrenderToEnemies()
	VM_ExecuteCommand(476, 0)
end

--  Create a Miss Chance effect.
--  - nPercentage: 1-100 inclusive
--  - nMissChanceType: MISS_CHANCE_TYPE_*
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nPercentage < 1 or
--    nPercentage > 100.
function EffectMissChance(nPercentage, nMissChanceType)
	nMissChanceType = nMissChanceType or 0 --MISS_CHANCE_TYPE_NORMAL
	
	StackPushInteger(nMissChanceType)
	StackPushInteger(nPercentage)
	VM_ExecuteCommand(477, 2)
	return StackPopEffect()
end

--  Get the number of Hitdice worth of Turn Resistance that oUndead may have.
--  This will only work on undead creatures.
function GetTurnResistanceHD(oUndead)
	oUndead = oUndead or OBJECT_SELF
	
	StackPushObject(oUndead)
	VM_ExecuteCommand(478, 1)
	return StackPopInteger()
end

--  Get the size (CREATURE_SIZE_*) of oCreature.
function GetCreatureSize(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(479, 1)
	return StackPopInteger()
end

--  Create a Disappear/Appear effect.
--  The object will "fly away" for the duration of the effect and will reappear
--  at lLocation.
--  - nAnimation determines which appear and disappear animations to use. Most creatures
--  only have animation 1, although a few have 2 (like beholders)
function EffectDisappearAppear(lLocation, nAnimation)
	nAnimation = nAnimation or 1
	
	StackPushInteger(nAnimation)
	StackPushLocation(lLocation)
	VM_ExecuteCommand(480, 2)
	return StackPopEffect()
end

--  Create a Disappear effect to make the object "fly away" and then destroy
--  itself.
--  - nAnimation determines which appear and disappear animations to use. Most creatures
--  only have animation 1, although a few have 2 (like beholders)
function EffectDisappear(nAnimation)
	nAnimation = nAnimation or 1

	StackPushInteger(nAnimation)
	VM_ExecuteCommand(481, 1)
	return StackPopEffect()
end

--  Create an Appear effect to make the object "fly in".
--  - nAnimation determines which appear and disappear animations to use. Most creatures
--  only have animation 1, although a few have 2 (like beholders)
function EffectAppear(nAnimation)
	nAnimation = nAnimation or 1
	
	StackPushInteger(nAnimation)
	VM_ExecuteCommand(482, 1)
	return StackPopEffect()
end

--  The action subject will unlock oTarget, which can be a door or a placeable
--  object.
function ActionUnlockObject(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(483, 1)
end

--  The action subject will lock oTarget, which can be a door or a placeable
--  object.
function ActionLockObject(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(484, 1)
end

--  Create a Modify Attacks effect to add attacks.
--  - nAttacks: maximum is 5, even with the effect stacked
--  * Returns an effect of type EFFECT_TYPE_INVALIDEFFECT if nAttacks > 5.
function EffectModifyAttacks(nAttacks)
	StackPushInteger(nAttacks)
	VM_ExecuteCommand(485, 1)
	return StackPopEffect()
end

--  Get the last trap detected by oTarget.
--  * Return value on error: OBJECT_INVALID
function GetLastTrapDetected(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(486, 1)
	return StackPopObject()
end

--  Create a Damage Shield effect which does (nDamageAmount + nRandomAmount)
--  damage to any melee attacker on a successful attack of damage type nDamageType.
--  - nDamageAmount: an integer value
--  - nRandomAmount: DAMAGE_BONUS_*
--  - nDamageType: DAMAGE_TYPE_*
--  NOTE! You *must* use the DAMAGE_BONUS_* constants! Using other values may
--        result in odd behaviour.
function EffectDamageShield(nDamageAmount, nRandomAmount, nDamageType)
	StackPushInteger(nDamageType)
	StackPushInteger(nRandomAmount)
	StackPushInteger(nDamageAmount)
	VM_ExecuteCommand(487, 3)
	return StackPopEffect()
end

--  Get the trap nearest to oTarget.
--  Note : "trap objects" are actually any trigger, placeable or door that is
--  trapped in oTarget's area.
--  - oTarget
--  - nTrapDetected: if this is TRUE, the trap returned has to have been detected
--    by oTarget.
function GetNearestTrapToObject(oTarget, bTrapDetected)
	oTarget = oTarget or OBJECT_SELF
	if bTrapDetected == nil then bTrapDetected = true end
	
	StackPushBoolean(bTrapDetected)
	StackPushObject(oTarget)
	VM_ExecuteCommand(488, 2)
	return StackPopObject()
end

--  Get the name of oCreature's deity.
--  * Returns "" if oCreature is invalid (or if the deity name is blank for
--    oCreature).
function GetDeity(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(489, 1)
	return StackPopString()
end

--  Get the name of oCreature's sub race.
--  * Returns "" if oCreature is invalid (or if sub race is blank for oCreature).
function GetSubRace(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(490, 1)
	return StackPopString()
end

--  Get oTarget's base fortitude saving throw value (this will only work for
--  creatures, doors, and placeables).
--  * Returns 0 if oTarget is invalid.
function GetFortitudeSavingThrow(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(491, 1)
	return StackPopInteger()
end

--  Get oTarget's base will saving throw value (this will only work for creatures,
--  doors, and placeables).
--  * Returns 0 if oTarget is invalid.
function GetWillSavingThrow(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(492, 1)
	return StackPopInteger()
end

--  Get oTarget's base reflex saving throw value (this will only work for
--  creatures, doors, and placeables).
--  * Returns 0 if oTarget is invalid.
function GetReflexSavingThrow(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(493, 1)
	return StackPopInteger()
end

--  Get oCreature's challenge rating.
--  * Returns 0.0 if oCreature is invalid.
function GetChallengeRating(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(494, 1)
	return StackPopFloat()
end

--  Get oCreature's age.
--  * Returns 0 if oCreature is invalid.
function GetAge(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(495, 1)
	return StackPopInteger()
end

--  Get oCreature's movement rate.
--  * Returns 0 if oCreature is invalid.
function GetMovementRate(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(496, 1)
	return StackPopInteger()
end

--  Get oCreature's familiar creature type (FAMILIAR_CREATURE_TYPE_*).
--  * Returns FAMILIAR_CREATURE_TYPE_NONE if oCreature is invalid or does not
--    currently have a familiar.
function GetFamiliarCreatureType(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(497, 1)
	return StackPopInteger()
end

--  Get oCreature's animal companion creature type
--  (ANIMAL_COMPANION_CREATURE_TYPE_*).
--  * Returns ANIMAL_COMPANION_CREATURE_TYPE_NONE if oCreature is invalid or does
--    not currently have an animal companion.
function GetAnimalCompanionCreatureType(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(498, 1)
	return StackPopInteger()
end

--  Get oCreature's familiar's name.
--  * Returns "" if oCreature is invalid, does not currently
--  have a familiar or if the familiar's name is blank.
function GetFamiliarName(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(499, 1)
	return StackPopString()
end

--  Get oCreature's animal companion's name.
--  * Returns "" if oCreature is invalid, does not currently
--  have an animal companion or if the animal companion's name is blank.
function GetAnimalCompanionName(oTarget)
	StackPushObject(oTarget)
	VM_ExecuteCommand(500, 1)
	return StackPopString()
end

--  The action subject will fake casting a spell at oTarget the conjure and cast
--  animations and visuals will occur, nothing else.
--  - nSpell
--  - oTarget
--  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
function ActionCastFakeSpellAtObject(nSpell, oTarget, nProjectilePathType)
	nProjectilePathType = nProjectilePathType or 0 --PROJECTILE_PATH_TYPE_DEFAULT
	
	StackPushInteger(nProjectilePathType)
	StackPushObject(oTarget)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(501, 3)
end

--  The action subject will fake casting a spell at lLocation the conjure and
--  cast animations and visuals will occur, nothing else.
--  - nSpell
--  - lTarget
--  - nProjectilePathType: PROJECTILE_PATH_TYPE_*
function ActionCastFakeSpellAtLocation(nSpell, lTarget, nProjectilePathType)
	nProjectilePathType = nProjectilePathType or 0 --PROJECTILE_PATH_TYPE_DEFAULT
	
	StackPushInteger(nProjectilePathType)
	StackPushLocation(lTarget)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(502, 3)
end

--  Removes oAssociate from the service of oMaster, returning them to their
--  original faction.
function RemoveSummonedAssociate(oMaster, oAssociate)
	oAssociate = oAssociate or OBJECT_SELF
	
	StackPushObject(oAssociate)
	StackPushObject(oMaster)
	VM_ExecuteCommand(503, 2)
end

--  Set the camera mode for oPlayer.
--  - oPlayer
--  - nCameraMode: CAMERA_MODE_*
--  * If oPlayer is not player-controlled or nCameraMode is invalid, nothing
--    happens.
function SetCameraMode(oPlayer, nCameraMode)
	StackPushInteger(nCameraMode)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(504, 2)
end

--  * Returns TRUE if oCreature is resting.
function GetIsResting(oCreature)
	oCreature = oCreature or OBJECT_SELF

	StackPushObject(oCreature)
	VM_ExecuteCommand(505, 1)
	return StackPopBoolean()
end

--  Get the last PC that has rested in the module.
function GetLastPCRested()
	VM_ExecuteCommand(506, 0)
	return StackPopObject()
end

--  Set the weather for oTarget.
--  - oTarget: if this is GetModule(), all outdoor areas will be modified by the
--    weather constant. If it is an area, oTarget will play the weather only if
--    it is an outdoor area.
--  - nWeather: WEATHER_*
--    -> WEATHER_USER_AREA_SETTINGS will set the area back to random weather.
--    -> WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW will make the weather go to
--       the appropriate precipitation *without stopping*.
function SetWeather(oTarget, nWeather)
	StackPushInteger(nWeather)
	StackPushObject(oTarget)
	VM_ExecuteCommand(507, 2)
end

--  Determine the type (REST_EVENTTYPE_REST_*) of the last rest event (as
--  returned from the OnPCRested module event).
function GetLastRestEventType()
	VM_ExecuteCommand(508, 0)
	return StackPopInteger()
end

--  Shut down the currently loaded module and start a new one (moving all
--  currently-connected players to the starting point.
function StartNewModule(sModuleName)
	StackPushString(sModuleName)
	VM_ExecuteCommand(509, 1)
end

--  Create a Swarm effect.
--  - nLooping: If this is TRUE, for the duration of the effect when one creature
--    created by this effect dies, the next one in the list will be created.  If
--    the last creature in the list dies, we loop back to the beginning and
--    sCreatureTemplate1 will be created, and so on...
--  - sCreatureTemplate1
--  - sCreatureTemplate2
--  - sCreatureTemplate3
--  - sCreatureTemplate4
function EffectSwarm(nLooping, sCreatureTemplate1, sCreatureTemplate2, sCreatureTemplate3, sCreatureTemplate4)
	sCreatureTemplate2 = sCreatureTemplate2 or ""
	sCreatureTemplate3 = sCreatureTemplate3 or ""
	sCreatureTemplate4 = sCreatureTemplate4 or ""
	
	StackPushString(sCreatureTemplate4)
	StackPushString(sCreatureTemplate3)
	StackPushString(sCreatureTemplate2)
	StackPushString(sCreatureTemplate1)
	StackPushInteger(nLooping)
	VM_ExecuteCommand(510, 5)
	return StackPopEffect()
end

--  * Returns TRUE if oItem is a ranged weapon.
function GetWeaponRanged(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(511, 1)
	return StackPopInteger()
end

--  Only if we are in a single player game, AutoSave the game.
function DoSinglePlayerAutoSave()
	VM_ExecuteCommand(512, 0)
end

--  Get the game difficulty (GAME_DIFFICULTY_*).
function GetGameDifficulty()
	VM_ExecuteCommand(513, 0)
	return StackPopInteger()
end

--  Set the main light color on the tile at lTileLocation.
--  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
--    the tile.
--  - nMainLight1Color: TILE_MAIN_LIGHT_COLOR_*
--  - nMainLight2Color: TILE_MAIN_LIGHT_COLOR_*
function SetTileMainLightColor(lTileLocation, nMainLight1Color, nMainLight2Color)
	StackPushInteger(nMainLight2Color)
	StackPushInteger(nMainLight1Color)
	StackPushLocation(lTileLocation)
	VM_ExecuteCommand(514, 3)
end

--  Set the source light color on the tile at lTileLocation.
--  - lTileLocation: the vector part of this is the tile grid (x,y) coordinate of
--    the tile.
--  - nSourceLight1Color: TILE_SOURCE_LIGHT_COLOR_*
--  - nSourceLight2Color: TILE_SOURCE_LIGHT_COLOR_*
function SetTileSourceLightColor(lTileLocation, nSourceLight1Color, nSourceLight2Color)
	StackPushInteger(nSourceLight2Color)
	StackPushInteger(nSourceLight1Color)
	StackPushLocation(lTileLocation)
	VM_ExecuteCommand(515, 3)
end

--  All clients in oArea will recompute the static lighting.
--  This can be used to update the lighting after changing any tile lights or if
--  placeables with lights have been added/deleted.
function RecomputeStaticLighting(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(516, 1)
end

--  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 1 of the tile at
--  lTile.
--  - lTile: the vector part of this is the tile grid (x,y) coordinate of the tile.
function GetTileMainLight1Color(lTile)
	StackPushLocation(lTile)
	VM_ExecuteCommand(517, 1)
	return StackPopInteger()
end

--  Get the color (TILE_MAIN_LIGHT_COLOR_*) for the main light 2 of the tile at
--  lTile.
--  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
--    tile.
function GetTileMainLight2Color(lTile)
	StackPushLocation(lTile)
	VM_ExecuteCommand(518, 1)
	return StackPopInteger()
end

--  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 1 of the tile
--  at lTile.
--  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
--    tile.
function GetTileSourceLight1Color(lTile)
	StackPushLocation(lTile)
	VM_ExecuteCommand(519, 1)
	return StackPopInteger()
end

--  Get the color (TILE_SOURCE_LIGHT_COLOR_*) for the source light 2 of the tile
--  at lTile.
--  - lTile: the vector part of this is the tile grid (x,y) coordinate of the
--    tile.
function GetTileSourceLight2Color(lTile)
	StackPushLocation(lTile)
	VM_ExecuteCommand(520, 1)
	return StackPopInteger()
end

--  Make the corresponding panel button on the player's client start or stop
--  flashing.
--  - oPlayer
--  - nButton: PANEL_BUTTON_*
--  - nEnableFlash: if this is TRUE nButton will start flashing.  It if is FALSE,
--    nButton will stop flashing.
function SetPanelButtonFlash(oPlayer, nButton, bEnableFlash)
	StackPushBoolean(bEnableFlash)
	StackPushInteger(nButton)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(521, 3)
end

--  Get the current action (ACTION_*) that oObject is executing.
function GetCurrentAction(oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	VM_ExecuteCommand(522, 1)
	return StackPopInteger()
end

--  Set how nStandardFaction feels about oCreature.
--  - nStandardFaction: STANDARD_FACTION_*
--  - nNewReputation: 0-100 (inclusive)
--  - oCreature
function SetStandardFactionReputation(nStandardFaction, nNewReputation, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nNewReputation)
	StackPushInteger(nStandardFaction)
	VM_ExecuteCommand(523, 3)
end

--  Find out how nStandardFaction feels about oCreature.
--  - nStandardFaction: STANDARD_FACTION_*
--  - oCreature
--  Returns -1 on an error.
--  Returns 0-100 based on the standing of oCreature within the faction nStandardFaction.
--  0-10   :  Hostile.
--  11-89  :  Neutral.
--  90-100 :  Friendly.
function GetStandardFactionReputation(nStandardFaction, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nStandardFaction)
	VM_ExecuteCommand(524, 2)
	return StackPopInteger()
end

--  Display floaty text above the specified creature.
--  The text will also appear in the chat buffer of each player that receives the
--  floaty text.
--  - nStrRefToDisplay: String ref (therefore text is translated)
--  - oCreatureToFloatAbove
--  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
--    as oCreatureToFloatAbove
--    will see the floaty text, and only if they are within range (30 metres).
function FloatingTextStrRefOnCreature(nStrRefToDisplay, oCreatureToFloatAbove, bBroadcastToFaction)
	if bBroadcastToFaction == nil then bBroadcastToFaction = true end
	
	StackPushBoolean(bBroadcastToFaction)
	StackPushObject(oCreatureToFloatAbove)
	StackPushInteger(nStrRefToDisplay)
	VM_ExecuteCommand(525, 3)
	
end

--  Display floaty text above the specified creature.
--  The text will also appear in the chat buffer of each player that receives the
--  floaty text.
--  - sStringToDisplay: String
--  - oCreatureToFloatAbove
--  - bBroadcastToFaction: If this is TRUE then only creatures in the same faction
--    as oCreatureToFloatAbove
--    will see the floaty text, and only if they are within range (30 metres).
function FloatingTextStringOnCreature(sStringToDisplay, oCreatureToFloatAbove, bBroadcastToFaction)
	if bBroadcastToFaction == nil then bBroadcastToFaction = true end
	
	StackPushBoolean(bBroadcastToFaction)
	StackPushObject(oCreatureToFloatAbove)
	StackPushString(sStringToDisplay)
	VM_ExecuteCommand(526, 3)
	
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject is disarmable.
function GetTrapDisarmable(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(527, 1)
	return StackPopBoolean()
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject is detectable.
function GetTrapDetectable(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(528, 1)
	return StackPopBoolean()
end

--  - oTrapObject: a placeable, door or trigger
--  - oCreature
--  * Returns TRUE if oCreature has detected oTrapObject
function GetTrapDetectedBy(oTrapObject, oCreature)
	StackPushObject(oCreature)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(529, 2)
	return StackPopBoolean()
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject has been flagged as visible to all creatures.
function GetTrapFlagged(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(530, 1)
	return StackPopBoolean()
end

--  Get the trap base type (TRAP_BASE_TYPE_*) of oTrapObject.
--  - oTrapObject: a placeable, door or trigger
function GetTrapBaseType(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(531, 1)
	return StackPopInteger()
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject is one-shot (i.e. it does not reset itself
--    after firing.
function GetTrapOneShot(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(532, 1)
	return StackPopBoolean()
end

--  Get the creator of oTrapObject, the creature that set the trap.
--  - oTrapObject: a placeable, door or trigger
--  * Returns OBJECT_INVALID if oTrapObject was created in the toolset.
function GetTrapCreator(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(533, 1)
	return StackPopObject()
end

--  Get the tag of the key that will disarm oTrapObject.
--  - oTrapObject: a placeable, door or trigger
function GetTrapKeyTag(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(534, 1)
	return StackPopString()
end

--  Get the DC for disarming oTrapObject.
--  - oTrapObject: a placeable, door or trigger
function GetTrapDisarmDC(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(535, 1)
	return StackPopInteger()
end

--  Get the DC for detecting oTrapObject.
--  - oTrapObject: a placeable, door or trigger
function GetTrapDetectDC(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(536, 1)
	return StackPopInteger()
end

--  * Returns TRUE if a specific key is required to open the lock on oObject.
function GetLockKeyRequired(oObject)  
	StackPushObject(oObject)
	VM_ExecuteCommand(537, 1)
	return StackPopBoolean()
end

--  Get the tag of the key that will open the lock on oObject.
function GetLockKeyTag(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(538, 1)
	return StackPopString()
end

--  * Returns TRUE if the lock on oObject is lockable.
function GetLockLockable(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(539, 1)
	return StackPopBoolean()
end

--  Get the DC for unlocking oObject.
function GetLockUnlockDC(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(540, 1)
	return StackPopInteger()
end

--  Get the DC for locking oObject.
function GetLockLockDC(oObject) 
	StackPushObject(oObject)
	VM_ExecuteCommand(541, 1)
	return StackPopInteger()
end

--  Get the last PC that levelled up.
function GetPCLevellingUp()
	VM_ExecuteCommand(542, 0)
	return StackPopObject()
end

--  - nFeat: FEAT_*
--  - oObject
--  * Returns TRUE if oObject has effects on it originating from nFeat.
function GetHasFeatEffect(nFeat, oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	StackPushInteger(nFeat)
	VM_ExecuteCommand(543, 2)
	return StackPopBoolean()
end

--  Set the status of the illumination for oPlaceable.
--  - oPlaceable
--  - bIlluminate: if this is TRUE, oPlaceable's illumination will be turned on.
--    If this is FALSE, oPlaceable's illumination will be turned off.
--  Note: You must call RecomputeStaticLighting() after calling this function in
--  order for the changes to occur visually for the players.
--  SetPlaceableIllumination() buffers the illumination changes, which are then
--  sent out to the players once RecomputeStaticLighting() is called.  As such,
--  it is best to call SetPlaceableIllumination() for all the placeables you wish
--  to set the illumination on, and then call RecomputeStaticLighting() once after
--  all the placeable illumination has been set.
--  * If oPlaceable is not a placeable object, or oPlaceable is a placeable that
--    doesn't have a light, nothing will happen.
function SetPlaceableIllumination(oPlaceable, bIlluminate)
	oPlaceable = oPlaceable or OBJECT_SELF
	if bIlluminate == nil then bIlluminate = true end
	
	StackPushBoolean(bIlluminate)
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(544, 2)
end

--  * Returns TRUE if the illumination for oPlaceable is on
function GetPlaceableIllumination(oPlaceable)
	oPlaceable = oPlaceable or OBJECT_SELF
	
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(545, 1)
	return StackPopBoolean()
end

--  - oPlaceable
--  - nPlaceableAction: PLACEABLE_ACTION_*
--  * Returns TRUE if nPlacebleAction is valid for oPlaceable.
function GetIsPlaceableObjectActionPossible(oPlaceable, nPlaceableAction)
	StackPushInteger(nPlaceableAction)
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(546, 2)
	return StackPopBoolean()
end

--  The caller performs nPlaceableAction on oPlaceable.
--  - oPlaceable
--  - nPlaceableAction: PLACEABLE_ACTION_*
function DoPlaceableObjectAction(oPlaceable, nPlaceableAction)
	StackPushInteger(nPlaceableAction)
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(547, 2)
end

--  Get the first PC in the player list.
--  This resets the position in the player list for GetNextPC().
function GetFirstPC()
	VM_ExecuteCommand(548, 0)
	return StackPopObject()
end

--  Get the next PC in the player list.
--  This picks up where the last GetFirstPC() or GetNextPC() left off.
function GetNextPC()
	VM_ExecuteCommand(549, 0)
	return StackPopObject()
end

--  Set whether or not the creature oDetector has detected the trapped object oTrap.
--  - oTrap: A trapped trigger, placeable or door object.
--  - oDetector: This is the creature that the detected status of the trap is being adjusted for.
--  - bDetected: A Boolean that sets whether the trapped object has been detected or not.
function SetTrapDetectedBy(oTrap, oDetector, bDetected)
	bDetected = bDetected or TRUE
	
	StackPushBoolean(bDetected)
	StackPushObject(oDetector)
	StackPushObject(oTrap)
	VM_ExecuteCommand(550, 3)
	return StackPopInteger()
end

--  Note: Only placeables, doors and triggers can be trapped.
--  * Returns TRUE if oObject is trapped.
function GetIsTrapped(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(551, 1)
	return StackPopBoolean()
end

--  Create a Turn Resistance Decrease effect.
--  - nHitDice: a positive number representing the number of hit dice for the
-- /  decrease
function EffectTurnResistanceDecrease(nHitDice)
	StackPushInteger(nHitDice)
	VM_ExecuteCommand(552, 1)
	return StackPopEffect()
end

--  Create a Turn Resistance Increase effect.
--  - nHitDice: a positive number representing the number of hit dice for the
--    increase
function EffectTurnResistanceIncrease(nHitDice)
	StackPushInteger(nHitDice)
	VM_ExecuteCommand(553, 1)
	return StackPopEffect()
end

--  Spawn in the Death GUI.
--  The default (as defined by BioWare) can be spawned in by PopUpGUIPanel, but
--  if you want to turn off the "Respawn" or "Wait for Help" buttons, this is the
--  function to use.
--  - oPC
--  - bRespawnButtonEnabled: if this is TRUE, the "Respawn" button will be enabled
--    on the Death GUI.
--  - bWaitForHelpButtonEnabled: if this is TRUE, the "Wait For Help" button will
--    be enabled on the Death GUI (Note: This button will not appear in single player games).
--  - nHelpStringReference
--  - sHelpString
function PopUpDeathGUIPanel(oPC, bRespawnButtonEnabled, bWaitForHelpButtonEnabled, nHelpStringReference, sHelpString)
	if bRespawnButtonEnabled == nil then bRespawnButtonEnabled = true end
	if bWaitForHelpButtonEnabled == nil then bWaitForHelpButtonEnabled = true end
	nHelpStringReference = nHelpStringReference or 0
	sHelpString = sHelpString or ""
	
	StackPushString(sHelpString)
	StackPushInteger(nHelpStringReference)
	StackPushBoolean(bWaitForHelpButtonEnabled)
	StackPushBoolean(bRespawnButtonEnabled)
	StackPushObject(oPC)
	VM_ExecuteCommand(554, 5)
end

--  Disable oTrap.
--  - oTrap: a placeable, door or trigger.
function SetTrapDisabled(oTrap)
	StackPushObject(oTrap)
	VM_ExecuteCommand(555, 1)
end

--  Get the last object that was sent as a GetLastAttacker(), GetLastDamager(),
--  GetLastSpellCaster() (for a hostile spell), or GetLastDisturbed() (when a
--  creature is pickpocketed).
--  Note: Return values may only ever be:
--  1) A Creature
--  2) Plot Characters will never have this value set
--  3) Area of Effect Objects will return the AOE creator if they are registered
--     as this value, otherwise they will return INVALID_OBJECT_ID
--  4) Traps will not return the creature that set the trap.
--  5) This value will never be overwritten by another non-creature object.
--  6) This value will never be a dead/destroyed creature
function GetLastHostileActor(oVictim)
	oVictim = oVictim or OBJECT_SELF
	
	StackPushObject(oVictim)
	VM_ExecuteCommand(556, 1)
	return StackPopObject()
end

--  Force all the characters of the players who are currently in the game to
--  be exported to their respective directories i.e. LocalVault/ServerVault/ etc.
function ExportAllCharacters()
	VM_ExecuteCommand(557, 0)
end

--  Get the Day Track for oArea.
function MusicBackgroundGetDayTrack(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(558, 1)
	return StackPopInteger()
end

--  Get the Night Track for oArea.
function MusicBackgroundGetNightTrack(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(559, 1)
	return StackPopInteger()
end

--  Write sLogEntry as a timestamped entry into the log file
function WriteTimestampedLogEntry(sLogEntry)
	StackPushString(sLogEntry)
	VM_ExecuteCommand(560, 1)
end

--  Get the module's name in the language of the server that's running it.
--  * If there is no entry for the language of the server, it will return an
--    empty string
function GetModuleName()
	VM_ExecuteCommand(561, 0)
	return StackPopString()
end

--  Get the player leader of the faction of which oMemberOfFaction is a member.
--  * Returns OBJECT_INVALID if oMemberOfFaction is not a valid creature,
--    or oMemberOfFaction is a member of a NPC faction.
function GetFactionLeader(oMemberOfFaction)
	StackPushObject(oMemberOfFaction)
	VM_ExecuteCommand(562, 1)
	return StackPopObject()
end

--  Sends szMessage to all the Dungeon Masters currently on the server.
function SendMessageToAllDMs(szMessage)
	StackPushString(szMessage)
	VM_ExecuteCommand(563, 1)
end

--  End the currently running game, play sEndMovie then return all players to the
--  game's main menu.
function EndGame(sEndMovie)
	StackPushString(sEndMovie)
	VM_ExecuteCommand(564, 1)	
end

--  Remove oPlayer from the server.
--  You can optionally specify a reason to override the text shown to the player.
function BootPC(oPlayer, sReason)
	sReason = sReason or ""
	StackPushString(sReason)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(565, 2)	
end

--  Counterspell oCounterSpellTarget.
function ActionCounterSpell(oCounterSpellTarget)
	StackPushObject(oCounterSpellTarget)
	VM_ExecuteCommand(566, 1)
end

--  Set the ambient day volume for oArea to nVolume.
--  - oArea
--  - nVolume: 0 - 100
function AmbientSoundSetDayVolume(oArea, nVolume)
	StackPushInteger(nVolume)
	StackPushObject(oArea)
	VM_ExecuteCommand(567, 2)
end

--  Set the ambient night volume for oArea to nVolume.
--  - oArea
--  - nVolume: 0 - 100
function AmbientSoundSetNightVolume(oArea, nVolume)
	StackPushInteger(nVolume)
	StackPushObject(oArea)
	VM_ExecuteCommand(568, 2)
end

--  Get the Battle Track for oArea.
function MusicBackgroundGetBattleTrack(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(569, 1)
	return StackPopInteger()
end

--  Determine whether oObject has an inventory.
--  * Returns TRUE for creatures and stores, and checks to see if an item or placeable object is a container.
--  * Returns FALSE for all other object types.
function GetHasInventory(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(570, 1)
	return StackPopBoolean()
end

--  Get the duration (in seconds) of the sound attached to nStrRef
--  * Returns 0.0f if no duration is stored or if no sound is attached
function GetStrRefSoundDuration(nStrRef)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(571, 1)
	return StackPopFloat()
end

--  Add oPC to oPartyLeader's party.  This will only work on two PCs.
--  - oPC: player to add to a party
--  - oPartyLeader: player already in the party
function AddToParty(oPC, oPartyLeader)
	StackPushObject(oPartyLeader)
	StackPushObject(oPC)
	VM_ExecuteCommand(572, 2)
end

--  Remove oPC from their current party. This will only work on a PC.
--  - oPC: removes this player from whatever party they're currently in.
function RemoveFromParty(oPC)
	StackPushObject(oPC)
	VM_ExecuteCommand(573, 1)
end

--  Returns the stealth mode of the specified creature.
--  - oCreature
--  * Returns a constant STEALTH_MODE_*
function GetStealthMode(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(574, 1)
	return StackPopInteger()
end

--  Returns the detection mode of the specified creature.
--  - oCreature
--  * Returns a constant DETECT_MODE_*
function GetDetectMode(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(575, 1)
	return StackPopInteger()
end

--  Returns the defensive casting mode of the specified creature.
--  - oCreature
--  * Returns a constant DEFENSIVE_CASTING_MODE_*
function GetDefensiveCastingMode(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(576, 1)
	return StackPopInteger()
end

--  returns the appearance type of the specified creature.
--  * returns a constant APPEARANCE_TYPE_* for valid creatures
--  * returns APPEARANCE_TYPE_INVALID for non creatures/invalid creatures
function GetAppearanceType(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(577, 1)
	return StackPopInteger()
end

--  SpawnScriptDebugger() will cause the script debugger to be executed
--  after this command is executed!  
--  In order to compile the script for debugging go to Tools->Options->Script Editor
--  and check the box labeled "Generate Debug Information When Compiling Scripts"
--  After you have checked the above box, recompile the script that you want to debug.
--  If the script file isn't compiled for debugging, this command will do nothing.
--  Remove any SpawnScriptDebugger() calls once you have finished 
--  debugging the script.
function SpawnScriptDebugger()
	VM_ExecuteCommand(578, 0)
end

--  in an onItemAcquired script, returns the size of the stack of the item
--  that was just acquired.
--  * returns the stack size of the item acquired
function GetModuleItemAcquiredStackSize()
	VM_ExecuteCommand(579, 0)
	return StackPopInteger()
end

--  Decrement the remaining uses per day for this creature by one.
--  - oCreature: creature to modify
--  - nFeat: constant FEAT_*
function DecrementRemainingFeatUses(oCreature, nFeat)
	StackPushInteger(nFeat)
	StackPushObject(oCreature)
	VM_ExecuteCommand(580, 2)
end

--  Decrement the remaining uses per day for this creature by one.
--  - oCreature: creature to modify
--  - nSpell: constant SPELL_*
function DecrementRemainingSpellUses(oCreature, nSpell)
	StackPushInteger(nSpell)
	StackPushObject(oCreature)
	VM_ExecuteCommand(581, 2)
end

--  returns the template used to create this object (if appropriate)
--  * returns an empty string when no template found
function GetResRef(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(582, 1)
	return StackPopString()
end

--  returns an effect that will petrify the target
--  * currently applies EffectParalyze and the stoneskin visual effect.
function EffectPetrify()
	VM_ExecuteCommand(583, 0)
	return StackPopEffect()
end

--  duplicates the item and returns a new object
--  oItem - item to copy
--  oTargetInventory - create item in this object's inventory. If this parameter
--                     is not valid, the item will be created in oItem's location
--  bCopyVars - copy the local variables from the old item to the new one
--  * returns the new item
--  * returns OBJECT_INVALID for non-items.
--  * can only copy empty item containers. will return OBJECT_INVALID if oItem contains
--    other items.
--  * if it is possible to merge this item with any others in the target location,
--    then it will do so and return the merged object.
function CopyItem(oItem, oTargetInventory, bCopyVars)
	oTargetInventory = oTargetInventory or OBJECT_INVALID
	bCopyVars = bCopyVars or false
	
	StackPushBoolean(bCopyVars)
	StackPushObject(oTargetInventory)
	StackPushObject(oItem)
	VM_ExecuteCommand(584, 3)
	return StackPopObject()
end

--  returns an effect that is guaranteed to paralyze a creature.
--  this effect is identical to EffectParalyze except that it cannot be resisted.
function EffectCutsceneParalyze()
	VM_ExecuteCommand(585, 0)
	return StackPopEffect()
end

--  returns TRUE if the item CAN be dropped
--  Droppable items will appear on a creature's remains when the creature is killed.
function GetDroppableFlag(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(586, 1)
	return StackPopBoolean()
end

--  returns TRUE if the placeable object is usable
function GetUseableFlag(oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	VM_ExecuteCommand(587, 1)
	return StackPopBoolean()
end

--  returns TRUE if the item is stolen
function GetStolenFlag(oStolen)
	StackPushObject(oStolen)
	VM_ExecuteCommand(588, 1)
	return StackPopBoolean()
end

--  This stores a float out to the specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function SetCampaignFloat(sCampaignName, sVarName, flFloat, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushFloat(flFloat)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(589, 4)
end

--  This stores an int out to the specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function SetCampaignInt(sCampaignName, sVarName, nInt, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushInteger(nInt)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(590, 4)
end

--  This stores a vector out to the specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function SetCampaignVector(sCampaignName, sVarName, vVector, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushVector(vVector)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(591, 4)
end

--  This stores a location out to the specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function SetCampaignLocation(sCampaignName, sVarName, locLocation, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushLocation(locLocation)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(592, 4)
end

--  This stores a string out to the specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function SetCampaignString(sCampaignName, sVarName, sString, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sString)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(593, 4)
end

--  This will delete the entire campaign database if it exists.
function DestroyCampaignDatabase(sCampaignName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(594, 1)
end

--  This will read a float from the  specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function GetCampaignFloat(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(595, 3)
	return StackPopFloat()
end

--  This will read an int from the  specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function GetCampaignInt(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(596, 3)
	return StackPopInteger()
end

--  This will read a vector from the  specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function GetCampaignVector(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(597, 3)
	return StackPopVector()
end

--  This will read a location from the  specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function GetCampaignLocation(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(598, 3)
	return StackPopLocation()
end

--  This will read a string from the  specified campaign database
--  The database name IS case sensitive and it must be the same for both set and get functions.
--  The var name must be unique across the entire database, regardless of the variable type.
--  If you want a variable to pertain to a specific player in the game, provide a player object.
function GetCampaignString(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(599, 3)
	return StackPopString()
end

--  Duplicates the object specified by oSource.
--  ONLY creatures and items can be specified.
--  If an owner is specified and the object is an item, it will be put into their inventory
--  If the object is a creature, they will be created at the location.
--  If a new tag is specified, it will be assigned to the new object.
function CopyObject(oSource, locLocation, oOwner, sNewTag)
	oOwner  = oOwner or OBJECT_INVALID
	sNewTag  = sNewTag or ""
	
	StackPushString(sNewTag)
	StackPushObject(oOwner)
	StackPushLocation(locLocation)
	StackPushObject(oSource)
	VM_ExecuteCommand(600, 4)
	return StackPopObject()
end

--  This will remove ANY campaign variable. Regardless of type.
--  Note that by normal database standards, deleting does not actually removed the entry from
--  the database, but flags it as deleted. Do not expect the database files to shrink in size
--  from this command. If you want to 'pack' the database, you will have to do it externally
--  from the game.
function DeleteCampaignVariable(sCampaignName, sVarName, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(601, 3)
end

--  Stores an object with the given id.
--  NOTE: this command can only be used for storing Creatures and Items.
--  Returns 0 if it failled, 1 if it worked.
function StoreCampaignObject(sCampaignName, sVarName, oObject, oPlayer)
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushObject(oObject)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(602, 4)
	return StackPopBoolean()
end

--  Use RetrieveCampaign with the given id to restore it.
--  If you specify an owner, the object will try to be created in their repository
--  If the owner can't handle the item (or if it's a creature) it will be created on the ground.
function RetrieveCampaignObject(sCampaignName, sVarName, locLocation, oOwner, oPlayer)
	oOwner = oOwner or OBJECT_INVALID
	oPlayer = oPlayer or OBJECT_INVALID
	
	StackPushObject(oPlayer)
	StackPushObject(oOwner)
	StackPushLocation(locLocation)
	StackPushString(sVarName)
	StackPushString(sCampaignName)
	VM_ExecuteCommand(603, 5)
	return StackPopObject()
end

--  Returns an effect that is guaranteed to dominate a creature
--  Like EffectDominated but cannot be resisted
function EffectCutsceneDominated()
	VM_ExecuteCommand(604, 0)
	return StackPopEffect()
end

--  Returns stack size of an item
--  - oItem: item to query
function GetItemStackSize(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(605, 1)
	return StackPopInteger()
end

--  Sets stack size of an item.
--  - oItem: item to change
--  - nSize: new size of stack.  Will be restricted to be between 1 and the
--    maximum stack size for the item type.  If a value less than 1 is passed it
--    will set the stack to 1.  If a value greater than the max is passed
--    then it will set the stack to the maximum size
function SetItemStackSize(oItem, nSize)
	StackPushInteger(nSize)
	StackPushObject(oItem)
	VM_ExecuteCommand(606, 2)
end

--  Returns charges left on an item
--  - oItem: item to query
function GetItemCharges(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(607, 1)
	return StackPopInteger()
end

--  Sets charges left on an item.
--  - oItem: item to change
--  - nCharges: number of charges.  If value below 0 is passed, # charges will
--    be set to 0.  If value greater than maximum is passed, # charges will
--    be set to maximum.  If the # charges drops to 0 the item
--    will be destroyed.
function SetItemCharges(oItem, nCharges)
	StackPushInteger(nCharges)
	StackPushObject(oItem)
	VM_ExecuteCommand(608, 2)
end

--  ***********************  START OF ITEM PROPERTY FUNCTIONS  **********************
--  adds an item property to the specified item
--  Only temporary and permanent duration types are allowed.
function AddItemProperty(nDurationType, ipProperty, oItem, fDuration)
	fDuration = fDuration or 0.0
	
	StackPushFloat(fDuration)
	StackPushObject(oItem)
	StackPushItemProperty(ipProperty)
	StackPushInteger(nDurationType)
	VM_ExecuteCommand(609, 4)
end

--  removes an item property from the specified item
function RemoveItemProperty(oItem, ipProperty)
	StackPushItemProperty(ipProperty)
	StackPushObject(oItem)
	VM_ExecuteCommand(610, 2)
end

--  if the item property is valid this will return true
function GetIsItemPropertyValid(ipProperty)
	StackPushItemProperty(ipProperty)
	VM_ExecuteCommand(611, 1)
	return StackPopBoolean()
end

--  Gets the first item property on an item
function GetFirstItemProperty(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(612, 1)
	return StackPopItemProperty()
end

--  Will keep retrieving the next and the next item property on an Item,
--  will return an invalid item property when the list is empty.
function GetNextItemProperty(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(613, 1)
	return StackPopItemProperty()
end

--  will return the item property type (ie. holy avenger)
function GetItemPropertyType(ip)
	StackPushItemProperty(ip)
	VM_ExecuteCommand(614, 1)
	return StackPopInteger()
end

--  will return the duration type of the item property
function GetItemPropertyDurationType(ip)
	StackPushItemProperty(ip)
	VM_ExecuteCommand(615, 1)
	return StackPopInteger()
end

--  Returns Item property ability bonus.  You need to specify an
--  ability constant(IP_CONST_ABILITY_*) and the bonus.  The bonus should
--  be a positive integer between 1 and 12.
function ItemPropertyAbilityBonus(nAbility, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nAbility)
	VM_ExecuteCommand(616, 2)
	return StackPopItemProperty()
end

--  Returns Item property AC bonus.  You need to specify the bonus.
--  The bonus should be a positive integer between 1 and 20. The modifier
--  type depends on the item it is being applied to.
function ItemPropertyACBonus(nBonus)
	StackPushInteger(nBonus)
	VM_ExecuteCommand(617, 1)
	return StackPopItemProperty() 
end

--  Returns Item property AC bonus vs. alignment group.  An example of
--  an alignment group is Chaotic, or Good.  You need to specify the
--  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the AC bonus.
--  The AC bonus should be an integer between 1 and 20.  The modifier
--  type depends on the item it is being applied to.
function ItemPropertyACBonusVsAlign(nAlignGroup, nACBonus)
	StackPushInteger(nACBonus)
	StackPushInteger(nAlignGroup)
	VM_ExecuteCommand(618, 2)
	return StackPopItemProperty() 
end

--  Returns Item property AC bonus vs. Damage type (ie. piercing).  You
--  need to specify the damage type constant(IP_CONST_DAMAGETYPE_*) and the
--  AC bonus.  The AC bonus should be an integer between 1 and 20.  The
--  modifier type depends on the item it is being applied to.
--  NOTE: Only the first 3 damage types may be used here, the 3 basic
--        physical types.
function ItemPropertyACBonusVsDmgType(nDamageType, nACBonus)
	StackPushInteger(nACBonus)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(619, 2)
	return StackPopItemProperty() 
end

--  Returns Item property AC bonus vs. Racial group.  You need to specify
--  the racial group constant(IP_CONST_RACIALTYPE_*) and the AC bonus.  The AC
--  bonus should be an integer between 1 and 20.  The modifier type depends
--  on the item it is being applied to.
function ItemPropertyACBonusVsRace(nRace, nACBonus)
	StackPushInteger(nACBonus)
	StackPushInteger(nRace)
	VM_ExecuteCommand(620, 2)
	return StackPopItemProperty() 
end

--  Returns Item property AC bonus vs. Specific alignment.  You need to
--  specify the specific alignment constant(IP_CONST_ALIGNMENT_*) and the AC
--  bonus.  The AC bonus should be an integer between 1 and 20.  The
--  modifier type depends on the item it is being applied to.
function ItemPropertyACBonusVsSAlign(nAlign, nACBonus)
	StackPushInteger(nACBonus)
	StackPushInteger(nAlign)
	VM_ExecuteCommand(621, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Enhancement bonus.  You need to specify the
--  enhancement bonus.  The Enhancement bonus should be an integer between
--  1 and 20.
function ItemPropertyEnhancementBonus(nEnhancementBonus)
	StackPushInteger(nEnhancementBonus)
	VM_ExecuteCommand(622, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Enhancement bonus vs. an Alignment group.  You
--  need to specify the alignment group constant(IP_CONST_ALIGNMENTGROUP_*)
--  and the enhancement bonus.  The Enhancement bonus should be an integer
--  between 1 and 20.
function ItemPropertyEnhancementBonusVsAlign(nAlignGroup, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nAlignGroup)
	VM_ExecuteCommand(623, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Enhancement bonus vs. Racial group.  You need
--  to specify the racial group constant(IP_CONST_RACIALTYPE_*) and the
--  enhancement bonus.  The enhancement bonus should be an integer between
--  1 and 20.
function ItemPropertyEnhancementBonusVsRace(nRace, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nRace)
	VM_ExecuteCommand(624, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Enhancement bonus vs. a specific alignment.  You
--  need to specify the alignment constant(IP_CONST_ALIGNMENT_*) and the
--  enhancement bonus.  The enhancement bonus should be an integer between
--  1 and 20.
function ItemPropertyEnhancementBonusVsSAlign(nAlign, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nAlign)
	VM_ExecuteCommand(625, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Enhancment penalty.  You need to specify the
--  enhancement penalty.  The enhancement penalty should be a POSITIVE
--  integer between 1 and 5 (ie. 1 = -1).
function ItemPropertyEnhancementPenalty(nPenalty)
	StackPushInteger(nPenalty)
	VM_ExecuteCommand(626, 1)
	return StackPopItemProperty() 
end

--  Returns Item property weight reduction.  You need to specify the weight
--  reduction constant(IP_CONST_REDUCEDWEIGHT_*).
function ItemPropertyWeightReduction(nReduction)
	StackPushInteger(nReduction)
	VM_ExecuteCommand(627, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Bonus Feat.  You need to specify the the feat
--  constant(IP_CONST_FEAT_*).
function ItemPropertyBonusFeat(nFeat) 
	StackPushInteger(nFeat)
	VM_ExecuteCommand(628, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Bonus level spell (Bonus spell of level).  You must
--  specify the class constant(IP_CONST_CLASS_*) of the bonus spell(MUST BE a
--  spell casting class) and the level of the bonus spell.  The level of the
--  bonus spell should be an integer between 0 and 9.
function ItemPropertyBonusLevelSpell(nClass, nSpellLevel)
	StackPushInteger(nSpellLevel)
	StackPushInteger(nClass)
	VM_ExecuteCommand(629, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Cast spell.  You must specify the spell constant
--  (IP_CONST_CASTSPELL_*) and the number of uses constant(IP_CONST_CASTSPELL_NUMUSES_*).
--  NOTE: The number after the name of the spell in the constant is the level
--        at which the spell will be cast.  Sometimes there are multiple copies
--        of the same spell but they each are cast at a different level.  The higher
--        the level, the more cost will be added to the item.
--  NOTE: The list of spells that can be applied to an item will depend on the
--        item type.  For instance there are spells that can be applied to a wand
--        that cannot be applied to a potion.  Below is a list of the types and the
--        spells that are allowed to be placed on them.  If you try to put a cast
--        spell effect on an item that is not allowed to have that effect it will
--        not work.
--  NOTE: Even if spells have multiple versions of different levels they are only
--        listed below once.
-- 
--  WANDS:
--           Acid_Splash
--           Activate_Item
--           Aid
--           Amplify
--           Animate_Dead
--           AuraOfGlory
--           BalagarnsIronHorn
--           Bane
--           Banishment
--           Barkskin
--           Bestow_Curse
--           Bigbys_Clenched_Fist
--           Bigbys_Crushing_Hand
--           Bigbys_Forceful_Hand
--           Bigbys_Grasping_Hand
--           Bigbys_Interposing_Hand
--           Bless
--           Bless_Weapon
--           Blindness/Deafness
--           Blood_Frenzy
--           Bombardment
--           Bulls_Strength
--           Burning_Hands
--           Call_Lightning
--           Camoflage
--           Cats_Grace
--           Charm_Monster
--           Charm_Person
--           Charm_Person_or_Animal
--           Clairaudience/Clairvoyance
--           Clarity
--           Color_Spray
--           Confusion
--           Continual_Flame
--           Cure_Critical_Wounds
--           Cure_Light_Wounds
--           Cure_Minor_Wounds
--           Cure_Moderate_Wounds
--           Cure_Serious_Wounds
--           Darkness
--           Darkvision
--           Daze
--           Death_Ward
--           Dirge
--           Dismissal
--           Dispel_Magic
--           Displacement
--           Divine_Favor
--           Divine_Might
--           Divine_Power
--           Divine_Shield
--           Dominate_Animal
--           Dominate_Person
--           Doom
--           Dragon_Breath_Acid
--           Dragon_Breath_Cold
--           Dragon_Breath_Fear
--           Dragon_Breath_Fire
--           Dragon_Breath_Gas
--           Dragon_Breath_Lightning
--           Dragon_Breath_Paralyze
--           Dragon_Breath_Sleep
--           Dragon_Breath_Slow
--           Dragon_Breath_Weaken
--           Drown
--           Eagle_Spledor
--           Earthquake
--           Electric_Jolt
--           Elemental_Shield
--           Endurance
--           Endure_Elements
--           Enervation
--           Entangle
--           Entropic_Shield
--           Etherealness
--           Expeditious_Retreat
--           Fear
--           Find_Traps
--           Fireball
--           Firebrand
--           Flame_Arrow
--           Flame_Lash
--           Flame_Strike
--           Flare
--           Foxs_Cunning
--           Freedom_of_Movement
--           Ghostly_Visage
--           Ghoul_Touch
--           Grease
--           Greater_Magic_Fang
--           Greater_Magic_Weapon
--           Grenade_Acid
--           Grenade_Caltrops
--           Grenade_Chicken
--           Grenade_Choking
--           Grenade_Fire
--           Grenade_Holy
--           Grenade_Tangle
--           Grenade_Thunderstone
--           Gust_of_wind
--           Hammer_of_the_Gods
--           Haste
--           Hold_Animal
--           Hold_Monster
--           Hold_Person
--           Ice_Storm
--           Identify
--           Improved_Invisibility
--           Inferno
--           Inflict_Critical_Wounds
--           Inflict_Light_Wounds
--           Inflict_Minor_Wounds
--           Inflict_Moderate_Wounds
--           Inflict_Serious_Wounds
--           Invisibility
--           Invisibility_Purge
--           Invisibility_Sphere
--           Isaacs_Greater_Missile_Storm
--           Isaacs_Lesser_Missile_Storm
--           Knock
--           Lesser_Dispel
--           Lesser_Restoration
--           Lesser_Spell_Breach
--           Light
--           Lightning_Bolt
--           Mage_Armor
--           Magic_Circle_against_Alignment
--           Magic_Fang
--           Magic_Missile
--           Manipulate_Portal_Stone
--           Mass_Camoflage
--           Melfs_Acid_Arrow
--           Meteor_Swarm
--           Mind_Blank
--           Mind_Fog
--           Negative_Energy_Burst
--           Negative_Energy_Protection
--           Negative_Energy_Ray
--           Neutralize_Poison
--           One_With_The_Land
--           Owls_Insight
--           Owls_Wisdom
--           Phantasmal_Killer
--           Planar_Ally
--           Poison
--           Polymorph_Self
--           Prayer
--           Protection_from_Alignment
--           Protection_From_Elements
--           Quillfire
--           Ray_of_Enfeeblement
--           Ray_of_Frost
--           Remove_Blindness/Deafness
--           Remove_Curse
--           Remove_Disease
--           Remove_Fear
--           Remove_Paralysis
--           Resist_Elements
--           Resistance
--           Restoration
--           Sanctuary
--           Scare
--           Searing_Light
--           See_Invisibility
--           Shadow_Conjuration
--           Shield
--           Shield_of_Faith
--           Silence
--           Sleep
--           Slow
--           Sound_Burst
--           Spike_Growth
--           Stinking_Cloud
--           Stoneskin
--           Summon_Creature_I
--           Summon_Creature_I
--           Summon_Creature_II
--           Summon_Creature_III
--           Summon_Creature_IV
--           Sunburst
--           Tashas_Hideous_Laughter
--           True_Strike
--           Undeaths_Eternal_Foe
--           Unique_Power
--           Unique_Power_Self_Only
--           Vampiric_Touch
--           Virtue
--           Wall_of_Fire
--           Web
--           Wounding_Whispers
-- 
--  POTIONS:
--           Activate_Item
--           Aid
--           Amplify
--           AuraOfGlory
--           Bane
--           Barkskin
--           Barkskin
--           Barkskin
--           Bless
--           Bless_Weapon
--           Bless_Weapon
--           Blood_Frenzy
--           Bulls_Strength
--           Bulls_Strength
--           Bulls_Strength
--           Camoflage
--           Cats_Grace
--           Cats_Grace
--           Cats_Grace
--           Clairaudience/Clairvoyance
--           Clairaudience/Clairvoyance
--           Clairaudience/Clairvoyance
--           Clarity
--           Continual_Flame
--           Cure_Critical_Wounds
--           Cure_Critical_Wounds
--           Cure_Critical_Wounds
--           Cure_Light_Wounds
--           Cure_Light_Wounds
--           Cure_Minor_Wounds
--           Cure_Moderate_Wounds
--           Cure_Moderate_Wounds
--           Cure_Moderate_Wounds
--           Cure_Serious_Wounds
--           Cure_Serious_Wounds
--           Cure_Serious_Wounds
--           Darkness
--           Darkvision
--           Darkvision
--           Death_Ward
--           Dispel_Magic
--           Dispel_Magic
--           Displacement
--           Divine_Favor
--           Divine_Might
--           Divine_Power
--           Divine_Shield
--           Dragon_Breath_Acid
--           Dragon_Breath_Cold
--           Dragon_Breath_Fear
--           Dragon_Breath_Fire
--           Dragon_Breath_Gas
--           Dragon_Breath_Lightning
--           Dragon_Breath_Paralyze
--           Dragon_Breath_Sleep
--           Dragon_Breath_Slow
--           Dragon_Breath_Weaken
--           Eagle_Spledor
--           Eagle_Spledor
--           Eagle_Spledor
--           Elemental_Shield
--           Elemental_Shield
--           Endurance
--           Endurance
--           Endurance
--           Endure_Elements
--           Entropic_Shield
--           Ethereal_Visage
--           Ethereal_Visage
--           Etherealness
--           Expeditious_Retreat
--           Find_Traps
--           Foxs_Cunning
--           Foxs_Cunning
--           Foxs_Cunning
--           Freedom_of_Movement
--           Ghostly_Visage
--           Ghostly_Visage
--           Ghostly_Visage
--           Globe_of_Invulnerability
--           Greater_Bulls_Strength
--           Greater_Cats_Grace
--           Greater_Dispelling
--           Greater_Dispelling
--           Greater_Eagles_Splendor
--           Greater_Endurance
--           Greater_Foxs_Cunning
--           Greater_Magic_Weapon
--           Greater_Owls_Wisdom
--           Greater_Restoration
--           Greater_Spell_Mantle
--           Greater_Stoneskin
--           Grenade_Acid
--           Grenade_Caltrops
--           Grenade_Chicken
--           Grenade_Choking
--           Grenade_Fire
--           Grenade_Holy
--           Grenade_Tangle
--           Grenade_Thunderstone
--           Haste
--           Haste
--           Heal
--           Hold_Animal
--           Hold_Monster
--           Hold_Person
--           Identify
--           Invisibility
--           Lesser_Dispel
--           Lesser_Dispel
--           Lesser_Mind_Blank
--           Lesser_Restoration
--           Lesser_Spell_Mantle
--           Light
--           Light
--           Mage_Armor
--           Manipulate_Portal_Stone
--           Mass_Camoflage
--           Mind_Blank
--           Minor_Globe_of_Invulnerability
--           Minor_Globe_of_Invulnerability
--           Mordenkainens_Disjunction
--           Negative_Energy_Protection
--           Negative_Energy_Protection
--           Negative_Energy_Protection
--           Neutralize_Poison
--           One_With_The_Land
--           Owls_Insight
--           Owls_Wisdom
--           Owls_Wisdom
--           Owls_Wisdom
--           Polymorph_Self
--           Prayer
--           Premonition
--           Protection_From_Elements
--           Protection_From_Elements
--           Protection_from_Spells
--           Protection_from_Spells
--           Raise_Dead
--           Remove_Blindness/Deafness
--           Remove_Curse
--           Remove_Disease
--           Remove_Fear
--           Remove_Paralysis
--           Resist_Elements
--           Resist_Elements
--           Resistance
--           Resistance
--           Restoration
--           Resurrection
--           Rogues_Cunning
--           See_Invisibility
--           Shadow_Shield
--           Shapechange
--           Shield
--           Shield_of_Faith
--           Special_Alcohol_Beer
--           Special_Alcohol_Spirits
--           Special_Alcohol_Wine
--           Special_Herb_Belladonna
--           Special_Herb_Garlic
--           Spell_Mantle
--           Spell_Resistance
--           Spell_Resistance
--           Stoneskin
--           Tensers_Transformation
--           True_Seeing
--           True_Strike
--           Unique_Power
--           Unique_Power_Self_Only
--           Virtue
-- 
--  GENERAL USE (ie. everything else):
--           Just about every spell is useable by all the general use items so instead we
--           will only list the ones that are not allowed:
--           Special_Alcohol_Beer
--           Special_Alcohol_Spirits
--           Special_Alcohol_Wine
-- 
function ItemPropertyCastSpell(nSpell, nNumUses)
	StackPushInteger(nNumUses)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(630, 2)
	return StackPopItemProperty() 
end

--  Returns Item property damage bonus.  You must specify the damage type constant
--  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
--  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
--        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
function ItemPropertyDamageBonus(nDamageType, nDamage)
	StackPushInteger(nDamage)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(631, 2)
	return StackPopItemProperty() 
end

--  Returns Item property damage bonus vs. Alignment groups.  You must specify the
--  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the damage type constant
--  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
--  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
--        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
function ItemPropertyDamageBonusVsAlign(nAlignGroup, nDamageType, nDamage)
	StackPushInteger(nDamage)
	StackPushInteger(nDamageType)
	StackPushInteger(nAlignGroup)
	VM_ExecuteCommand(632, 3)
	return StackPopItemProperty() 
end

--  Returns Item property damage bonus vs. specific race.  You must specify the
--  racial group constant(IP_CONST_RACIALTYPE_*) and the damage type constant
--  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
--  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
--        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
function ItemPropertyDamageBonusVsRace(nRace, nDamageType, nDamage)
	StackPushInteger(nDamage)
	StackPushInteger(nDamageType)
	StackPushInteger(nRace)
	VM_ExecuteCommand(633, 3)
	return StackPopItemProperty() 
end

--  Returns Item property damage bonus vs. specific alignment.  You must specify the
--  specific alignment constant(IP_CONST_ALIGNMENT_*) and the damage type constant
--  (IP_CONST_DAMAGETYPE_*) and the amount of damage constant(IP_CONST_DAMAGEBONUS_*).
--  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
--        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
function ItemPropertyDamageBonusVsSAlign(nAlign, nDamageType, nDamage)
	StackPushInteger(nDamage)
	StackPushInteger(nDamageType)
	StackPushInteger(nAlign)
	VM_ExecuteCommand(634, 3)
	return StackPopItemProperty() 
end

--  Returns Item property damage immunity.  You must specify the damage type constant
--  (IP_CONST_DAMAGETYPE_*) that you want to be immune to and the immune bonus percentage
--  constant(IP_CONST_DAMAGEIMMUNITY_*).
--  NOTE: not all the damage types will work, use only the following: Acid, Bludgeoning,
--        Cold, Electrical, Fire, Piercing, Slashing, Sonic.
function ItemPropertyDamageImmunity(nImmuneBonus, nDamageType)
	StackPushInteger(nImmuneBonus)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(635, 2)
	return StackPopItemProperty() 
end

--  Returns Item property damage penalty.  You must specify the damage penalty.
--  The damage penalty should be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
function ItemPropertyDamagePenalty(nPenalty)
	StackPushInteger(nPenalty)
	VM_ExecuteCommand(636, 1)
	return StackPopItemProperty() 
end

--  Returns Item property damage reduction.  You must specify the enhancment level
--  (IP_CONST_DAMAGEREDUCTION_*) that is required to get past the damage reduction
--  and the amount of HP of damage constant(IP_CONST_DAMAGESOAK_*) will be soaked
--  up if your weapon is not of high enough enhancement.
function ItemPropertyDamageReduction(nEnhancement, nHPSoak)
	StackPushInteger(nHPSoak)
	StackPushInteger(nEnhancement)
	VM_ExecuteCommand(637, 2)
	return StackPopItemProperty() 
end

--  Returns Item property damage resistance.  You must specify the damage type
--  constant(IP_CONST_DAMAGETYPE_*) and the amount of HP of damage constant
--  (IP_CONST_DAMAGERESIST_*) that will be resisted against each round.
function ItemPropertyDamageResistance(nDamageType, nHPResist)
	StackPushInteger(nHPResist)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(638, 2)
	return StackPopItemProperty() 
end

--  Returns Item property damage vulnerability.  You must specify the damage type
--  constant(IP_CONST_DAMAGETYPE_*) that you want the user to be extra vulnerable to
--  and the percentage vulnerability constant(IP_CONST_DAMAGEVULNERABILITY_*).
function ItemPropertyDamageVulnerability(nDamageType, nVulnerability)
	StackPushInteger(nVulnerability)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(639, 2)
	return StackPopItemProperty() 
end

--  Return Item property Darkvision.
function ItemPropertyDarkvision()
	VM_ExecuteCommand(640, 0)
	return StackPopItemProperty() 
end

--  Return Item property decrease ability score.  You must specify the ability
--  constant(IP_CONST_ABILITY_*) and the modifier constant.  The modifier must be
--  a POSITIVE integer between 1 and 10 (ie. 1 = -1).
function ItemPropertyDecreaseAbility(nAbility, nModifier)
	StackPushInteger(nModifier)
	StackPushInteger(nAbility)
	VM_ExecuteCommand(641, 2)
	return StackPopItemProperty() 
end

--  Returns Item property decrease Armor Class.  You must specify the armor
--  modifier type constant(IP_CONST_ACMODIFIERTYPE_*) and the armor class penalty.
--  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
function ItemPropertyDecreaseAC(nModifierType, nPenalty)
	StackPushInteger(nPenalty)
	StackPushInteger(nModifierType)
	VM_ExecuteCommand(642, 2)
	return StackPopItemProperty() 
end

--  Returns Item property decrease skill.  You must specify the constant for the
--  skill to be decreased(SKILL_*) and the amount of the penalty.  The penalty
--  must be a POSITIVE integer between 1 and 10 (ie. 1 = -1).
function ItemPropertyDecreaseSkill(nSkill, nPenalty)
	StackPushInteger(nPenalty)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(643, 2)
	return StackPopItemProperty() 
end

--  Returns Item property container reduced weight.  This is used for special
--  containers that reduce the weight of the objects inside them.  You must
--  specify the container weight reduction type constant(IP_CONST_CONTAINERWEIGHTRED_*).
function ItemPropertyContainerReducedWeight(nContainerType)
	StackPushInteger(nContainerType)
	VM_ExecuteCommand(644, 1)
	return StackPopItemProperty() 
end

--  Returns Item property extra melee damage type.  You must specify the extra
--  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
--  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
--        here.
--  NOTE: It is also only applicable to melee weapons.
function ItemPropertyExtraMeleeDamageType(nDamageType)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(645, 1)
	return StackPopItemProperty() 
end

--  Returns Item property extra ranged damage type.  You must specify the extra
--  melee base damage type that you want applied.  It is a constant(IP_CONST_DAMAGETYPE_*).
--  NOTE: only the first 3 base types (piercing, slashing, & bludgeoning are applicable
--        here.
--  NOTE: It is also only applicable to ranged weapons.
function ItemPropertyExtraRangeDamageType(nDamageType)
	StackPushInteger(nDamageType)
	VM_ExecuteCommand(646, 1)
	return StackPopItemProperty() 
end

--  Returns Item property haste.
function ItemPropertyHaste()
	VM_ExecuteCommand(647, 0)
	return StackPopItemProperty() 
end

--  Returns Item property Holy Avenger.
function ItemPropertyHolyAvenger()
	VM_ExecuteCommand(648, 0)
	return StackPopItemProperty() 
end

--  Returns Item property immunity to miscellaneous effects.  You must specify the
--  effect to which the user is immune, it is a constant(IP_CONST_IMMUNITYMISC_*).
function ItemPropertyImmunityMisc(nImmunityType)
	StackPushInteger(nImmunityType)
	VM_ExecuteCommand(649, 1)
	return StackPopItemProperty() 
end

--  Returns Item property improved evasion.
function ItemPropertyImprovedEvasion()
	VM_ExecuteCommand(650, 0)
	return StackPopItemProperty() 
end

--  Returns Item property bonus spell resistance.  You must specify the bonus spell
--  resistance constant(IP_CONST_SPELLRESISTANCEBONUS_*).
function ItemPropertyBonusSpellResistance(nBonus)
	StackPushInteger(nBonus)
	VM_ExecuteCommand(651, 1)
	return StackPopItemProperty() 
end

--  Returns Item property saving throw bonus vs. a specific effect or damage type.
--  You must specify the save type constant(IP_CONST_SAVEVS_*) that the bonus is
--  applied to and the bonus that is be applied.  The bonus must be an integer
--  between 1 and 20.
function ItemPropertyBonusSavingThrowVsX(nBonusType, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nBonusType)
	VM_ExecuteCommand(652, 2)
	return StackPopItemProperty() 
end

--  Returns Item property saving throw bonus to the base type (ie. will, reflex,
--  fortitude).  You must specify the base type constant(IP_CONST_SAVEBASETYPE_*)
--  to which the user gets the bonus and the bonus that he/she will get.  The
--  bonus must be an integer between 1 and 20.
function ItemPropertyBonusSavingThrow(nBaseSaveType, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nBaseSaveType)
	VM_ExecuteCommand(653, 2)
	return StackPopItemProperty() 
end

--  Returns Item property keen.  This means a critical threat range of 19-20 on a
--  weapon will be increased to 17-20 etc.
function ItemPropertyKeen()
	VM_ExecuteCommand(654, 0)
	return StackPopItemProperty() 
end

--  Returns Item property light.  You must specify the intesity constant of the
--  light(IP_CONST_LIGHTBRIGHTNESS_*) and the color constant of the light
--  (IP_CONST_LIGHTCOLOR_*).
function ItemPropertyLight(nBrightness, nColor)
	StackPushInteger(nColor)
	StackPushInteger(nBrightness)
	VM_ExecuteCommand(655, 2)
	return StackPopItemProperty() 
end

--  Returns Item property Max range strength modification (ie. mighty).  You must
--  specify the maximum modifier for strength that is allowed on a ranged weapon.
--  The modifier must be a positive integer between 1 and 20.
function ItemPropertyMaxRangeStrengthMod(nModifier)
	StackPushInteger(nModifier)
	VM_ExecuteCommand(656, 1)
	return StackPopItemProperty() 
end

--  Returns Item property no damage.  This means the weapon will do no damage in
--  combat.
function ItemPropertyNoDamage()
	VM_ExecuteCommand(657, 0)
	return StackPopItemProperty() 
end

--  Returns Item property on hit -> do effect property.  You must specify the on
--  hit property constant(IP_CONST_ONHIT_*) and the save DC constant(IP_CONST_ONHIT_SAVEDC_*).
--  Some of the item properties require a special parameter as well.  If the
--  property does not require one you may leave out the last one.  The list of
--  the ones with 3 parameters and what they are are as follows:
--       ABILITYDRAIN      :nSpecial is the ability it is to drain.
--                          constant(IP_CONST_ABILITY_*)
--       BLINDNESS         :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       CONFUSION         :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       DAZE              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       DEAFNESS          :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       DISEASE           :nSpecial is the type of desease that will effect the victim.
--                          constant(DISEASE_*)
--       DOOM              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       FEAR              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       HOLD              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       ITEMPOISON        :nSpecial is the type of poison that will effect the victim.
--                          constant(IP_CONST_POISON_*)
--       SILENCE           :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       SLAYRACE          :nSpecial is the race that will be slain.
--                          constant(IP_CONST_RACIALTYPE_*)
--       SLAYALIGNMENTGROUP:nSpecial is the alignment group that will be slain(ie. chaotic).
--                          constant(IP_CONST_ALIGNMENTGROUP_*)
--       SLAYALIGNMENT     :nSpecial is the specific alignment that will be slain.
--                          constant(IP_CONST_ALIGNMENT_*)
--       SLEEP             :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       SLOW              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
--       STUN              :nSpecial is the duration/percentage of effecting victim.
--                          constant(IP_CONST_ONHIT_DURATION_*)
function ItemPropertyOnHitProps(nProperty, nSaveDC, nSpecial)
	nSpecial = nSpecial or 0

	StackPushInteger(nSpecial)
	StackPushInteger(nSaveDC)
	StackPushInteger(nProperty)
	VM_ExecuteCommand(658, 3)
	return StackPopItemProperty() 
end

--  Returns Item property reduced saving throw vs. an effect or damage type.  You must
--  specify the constant to which the penalty applies(IP_CONST_SAVEVS_*) and the
--  penalty to be applied.  The penalty must be a POSITIVE integer between 1 and 20
--  (ie. 1 = -1).
function ItemPropertyReducedSavingThrowVsX(nBaseSaveType, nPenalty)
	StackPushInteger(nPenalty)
	StackPushInteger(nBaseSaveType)
	VM_ExecuteCommand(659, 2)
	return StackPopItemProperty() 
end

--  Returns Item property reduced saving to base type.  You must specify the base
--  type to which the penalty applies (ie. will, reflex, or fortitude) and the penalty
--  to be applied.  The constant for the base type starts with (IP_CONST_SAVEBASETYPE_*).
--  The penalty must be a POSITIVE integer between 1 and 20 (ie. 1 = -1).
function ItemPropertyReducedSavingThrow(nBonusType, nPenalty)
	StackPushInteger(nPenalty)
	StackPushInteger(nBonusType)
	VM_ExecuteCommand(660, 2)
	return StackPopItemProperty() 
end

--  Returns Item property regeneration.  You must specify the regeneration amount.
--  The amount must be an integer between 1 and 20.
function ItemPropertyRegeneration(nRegenAmount)
	StackPushInteger(nRegenAmount)
	VM_ExecuteCommand(661, 1)
	return StackPopItemProperty() 
end

--  Returns Item property skill bonus.  You must specify the skill to which the user
--  will get a bonus(SKILL_*) and the amount of the bonus.  The bonus amount must
--  be an integer between 1 and 50.
function ItemPropertySkillBonus(nSkill, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nSkill)
	VM_ExecuteCommand(662, 2)
	return StackPopItemProperty() 
end

--  Returns Item property spell immunity vs. specific spell.  You must specify the
--  spell to which the user will be immune(IP_CONST_IMMUNITYSPELL_*).
function ItemPropertySpellImmunitySpecific(nSpell)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(663, 1)
	return StackPopItemProperty() 
end

--  Returns Item property spell immunity vs. spell school.  You must specify the
--  school to which the user will be immune(IP_CONST_SPELLSCHOOL_*).
function ItemPropertySpellImmunitySchool(nSchool)
	StackPushInteger(nSchool)
	VM_ExecuteCommand(664, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Thieves tools.  You must specify the modifier you wish
--  the tools to have.  The modifier must be an integer between 1 and 12.
function ItemPropertyThievesTools(nModifier)
	StackPushInteger(nModifier)
	VM_ExecuteCommand(665, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Attack bonus.  You must specify an attack bonus.  The bonus
--  must be an integer between 1 and 20.
function ItemPropertyAttackBonus(nBonus)
	StackPushInteger(nBonus)
	VM_ExecuteCommand(666, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Attack bonus vs. alignment group.  You must specify the
--  alignment group constant(IP_CONST_ALIGNMENTGROUP_*) and the attack bonus.  The
--  bonus must be an integer between 1 and 20.
function ItemPropertyAttackBonusVsAlign(nAlignGroup, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nAlignGroup)
	VM_ExecuteCommand(667, 2)
	return StackPopItemProperty() 
end

--  Returns Item property attack bonus vs. racial group.  You must specify the
--  racial group constant(IP_CONST_RACIALTYPE_*) and the attack bonus.  The bonus
--  must be an integer between 1 and 20.
function ItemPropertyAttackBonusVsRace(nRace, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nRace)
	VM_ExecuteCommand(668, 2)
	return StackPopItemProperty() 
end

--  Returns Item property attack bonus vs. a specific alignment.  You must specify
--  the alignment you want the bonus to work against(IP_CONST_ALIGNMENT_*) and the
--  attack bonus.  The bonus must be an integer between 1 and 20.
function ItemPropertyAttackBonusVsSAlign(nAlignment, nBonus)
	StackPushInteger(nBonus)
	StackPushInteger(nAlignment)
	VM_ExecuteCommand(669, 2)
	return StackPopItemProperty() 
end

--  Returns Item property attack penalty.  You must specify the attack penalty.
--  The penalty must be a POSITIVE integer between 1 and 5 (ie. 1 = -1).
function ItemPropertyAttackPenalty(nPenalty)
	StackPushInteger(nPenalty)
	VM_ExecuteCommand(670, 1)
	return StackPopItemProperty() 
end

--  Returns Item property unlimited ammo.  If you leave the parameter field blank
--  it will be just a normal bolt, arrow, or bullet.  However you may specify that
--  you want the ammunition to do special damage (ie. +1d6 Fire, or +1 enhancement
--  bonus).  For this parmeter you use the constants beginning with:
--       (IP_CONST_UNLIMITEDAMMO_*).
function ItemPropertyUnlimitedAmmo(nAmmoDamage)
	nAmmoDamage = nAmmoDamage or 1 --IP_CONST_UNLIMITEDAMMO_BASIC

	StackPushInteger(nAmmoDamage)
	VM_ExecuteCommand(671, 1)
	return StackPopItemProperty() 
end

--  Returns Item property limit use by alignment group.  You must specify the
--  alignment group(s) that you want to be able to use this item(IP_CONST_ALIGNMENTGROUP_*).
function ItemPropertyLimitUseByAlign(nAlignGroup)
	StackPushInteger(nAlignGroup)
	VM_ExecuteCommand(672, 1)
	return StackPopItemProperty() 
end

--  Returns Item property limit use by class.  You must specify the class(es) who
--  are able to use this item(IP_CONST_CLASS_*).
function ItemPropertyLimitUseByClass(nClass)
	StackPushInteger(nClass)
	VM_ExecuteCommand(673, 1)
	return StackPopItemProperty() 
end

--  Returns Item property limit use by race.  You must specify the race(s) who are
--  allowed to use this item(IP_CONST_RACIALTYPE_*).
function ItemPropertyLimitUseByRace(nRace)
	StackPushInteger(nRace)
	VM_ExecuteCommand(674, 1)
	return StackPopItemProperty() 
end

--  Returns Item property limit use by specific alignment.  You must specify the
--  alignment(s) of those allowed to use the item(IP_CONST_ALIGNMENT_*).
function ItemPropertyLimitUseBySAlign(nAlignment)
	StackPushInteger(nAlignment)
	VM_ExecuteCommand(675, 1)
	return StackPopItemProperty() 
end

--  replace this function it does nothing.
function BadBadReplaceMeThisDoesNothing()
	VM_ExecuteCommand(676, 0)
	return StackPopItemProperty() 
end

--  Returns Item property vampiric regeneration.  You must specify the amount of
--  regeneration.  The regen amount must be an integer between 1 and 20.
function ItemPropertyVampiricRegeneration(nRegenAmount)
	StackPushInteger(nRegenAmount)
	VM_ExecuteCommand(677, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Trap.  You must specify the trap level constant
--  (IP_CONST_TRAPSTRENGTH_*) and the trap type constant(IP_CONST_TRAPTYPE_*).
function ItemPropertyTrap(nTrapLevel, nTrapType)
	StackPushInteger(nTrapType)
	StackPushInteger(nTrapLevel)
	VM_ExecuteCommand(678, 2)
	return StackPopItemProperty() 
end

--  Returns Item property true seeing.
function ItemPropertyTrueSeeing()
	VM_ExecuteCommand(679, 0)
	return StackPopItemProperty() 
end

--  Returns Item property Monster on hit apply effect property.  You must specify
--  the property that you want applied on hit.  There are some properties that
--  require an additional special parameter to be specified.  The others that
--  don't require any additional parameter you may just put in the one.  The
--  special cases are as follows:
--       ABILITYDRAIN:nSpecial is the ability to drain.
--                    constant(IP_CONST_ABILITY_*)
--       DISEASE     :nSpecial is the disease that you want applied.
--                    constant(DISEASE_*)
--       LEVELDRAIN  :nSpecial is the number of levels that you want drained.
--                    integer between 1 and 5.
--       POISON      :nSpecial is the type of poison that will effect the victim.
--                    constant(IP_CONST_POISON_*)
--       WOUNDING    :nSpecial is the amount of wounding.
--                    integer between 1 and 5.
--  NOTE: Any that do not appear in the above list do not require the second
--        parameter.
--  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
--        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
function ItemPropertyOnMonsterHitProperties(nProperty, nSpecial)
	nSpecial = nSpecial or 0

	StackPushInteger(nSpecial)
	StackPushInteger(nProperty)
	VM_ExecuteCommand(680, 2)
	return StackPopItemProperty() 
end

--  Returns Item property turn resistance.  You must specify the resistance bonus.
--  The bonus must be an integer between 1 and 50.
function ItemPropertyTurnResistance(nModifier)
	StackPushInteger(nModifier)
	VM_ExecuteCommand(681, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Massive Critical.  You must specify the extra damage
--  constant(IP_CONST_DAMAGEBONUS_*) of the criticals.
function ItemPropertyMassiveCritical(nDamage)
	StackPushInteger(nDamage)
	VM_ExecuteCommand(682, 1)
	return StackPopItemProperty() 
end

--  Returns Item property free action.
function ItemPropertyFreeAction()
	VM_ExecuteCommand(683, 0)
	return StackPopItemProperty() 
end

--  Returns Item property monster damage.  You must specify the amount of damage
--  the monster's attack will do(IP_CONST_MONSTERDAMAGE_*).
--  NOTE: These can only be applied to monster NATURAL weapons (ie. bite, claw,
--        gore, and slam).  IT WILL NOT WORK ON NORMAL WEAPONS.
function ItemPropertyMonsterDamage(nDamage) 
	StackPushInteger(nDamage)
	VM_ExecuteCommand(684, 1)
	return StackPopItemProperty() 
end

--  Returns Item property immunity to spell level.  You must specify the level of
--  which that and below the user will be immune.  The level must be an integer
--  between 1 and 9.  By putting in a 3 it will mean the user is immune to all
--  3rd level and lower spells.
function ItemPropertyImmunityToSpellLevel(nLevel)
	StackPushInteger(nLevel)
	VM_ExecuteCommand(685, 1)
	return StackPopItemProperty() 
end

--  Returns Item property special walk.  If no parameters are specified it will
--  automatically use the zombie walk.  This will apply the special walk animation
--  to the user.
function ItemPropertySpecialWalk(nWalkType)
	nWalkType = nWalkType or 0

	StackPushInteger(nWalkType)
	VM_ExecuteCommand(686, 1)
	return StackPopItemProperty() 
end

--  Returns Item property healers kit.  You must specify the level of the kit.
--  The modifier must be an integer between 1 and 12.
function ItemPropertyHealersKit(nModifier)
	StackPushInteger(nModifier)
	VM_ExecuteCommand(687, 1)
	return StackPopItemProperty() 
end

--  Returns Item property weight increase.  You must specify the weight increase
--  constant(IP_CONST_WEIGHTINCREASE_*).
function ItemPropertyWeightIncrease(nWeight)
	StackPushInteger(nWeight)
	VM_ExecuteCommand(688, 1)
	return StackPopItemProperty() 
end

--  ***********************  END OF ITEM PROPERTY FUNCTIONS  **************************
--  Returns true if 1d20 roll + skill rank is greater than or equal to difficulty
--  - oTarget: the creature using the skill
--  - nSkill: the skill being used
--  - nDifficulty: Difficulty class of skill
function GetIsSkillSuccessful(oTarget, nSkill, nDifficulty)
	StackPushInteger(nDifficulty)
	StackPushInteger(nSkill)
	StackPushObject(oTarget)
	VM_ExecuteCommand(689, 3)
	return StackPopBoolean()
end

--  Creates an effect that inhibits spells
--  - nPercent - percentage of failure
--  - nSpellSchool - the school of spells affected.
function EffectSpellFailure(nPercent, nSpellSchool)
	nPercent = nPercent or 100
	nSpellSchool = nSpellSchool or 0 --SPELL_SCHOOL_GENERAL

	StackPushInteger(nSpellSchool)
	StackPushInteger(nPercent)
	VM_ExecuteCommand(690, 2)
	return StackPopEffect()
end

--  Causes the object to instantly speak a translated string.
--  (not an action, not blocked when uncommandable)
--  - nStrRef: Reference of the string in the talk table
--  - nTalkVolume: TALKVOLUME_*
function SpeakStringByStrRef(nStrRef, nTalkVolume)
	nTalkVolume = nTalkVolume or 0 --TALKVOLUME_TALK

	StackPushInteger(nTalkVolume)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(691, 2)
end

--  Sets the given creature into cutscene mode.  This prevents the player from
--  using the GUI and camera controls.
--  - oCreature: creature in a cutscene
--  - nInCutscene: TRUE to move them into cutscene, FALSE to remove cutscene mode
--  - nLeftClickingEnabled: TRUE to allow the user to interact with the game world using the left mouse button only.
--                          FALSE to stop the user from interacting with the game world.
--  Note: SetCutsceneMode(oPlayer, TRUE) will also make the player 'plot' (unkillable).
--  SetCutsceneMode(oPlayer, FALSE) will restore the player's plot flag to what it
--  was when SetCutsceneMode(oPlayer, TRUE) was called.
function SetCutsceneMode(oCreature, bInCutscene, bLeftClickingEnabled)
	if bInCutscene == nil then bInCutscene = true end
	bLeftClickingEnabled = bLeftClickingEnabled or false

	StackPushBoolean(bLeftClickingEnabled)
	StackPushBoolean(bInCutscene)
	StackPushObject(oCreature)
	VM_ExecuteCommand(692, 3)
end

--  Gets the last player character to cancel from a cutscene.
function GetLastPCToCancelCutscene()
	VM_ExecuteCommand(693, 0)
	return StackPopObject()
end

--  Gets the length of the specified wavefile, in seconds
--  Only works for sounds used for dialog.
function GetDialogSoundLength(nStrRef)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(694, 1)
	return StackPopFloat()
end

--  Fades the screen for the given creature/player from black to regular screen
--  - oCreature: creature controlled by player that should fade from black
function FadeFromBlack(oCreature, fSpeed)
	fSpeed = fSpeed or 0.01 --FADE_SPEED_MEDIUM

	StackPushFloat(fSpeed)
	StackPushObject(oCreature)
	VM_ExecuteCommand(695, 2)
end

--  Fades the screen for the given creature/player from regular screen to black
--  - oCreature: creature controlled by player that should fade to black
function FadeToBlack(oCreature, fSpeed)
	fSpeed = fSpeed or 0.01 --FADE_SPEED_MEDIUM

	StackPushFloat(fSpeed)
	StackPushObject(oCreature)
	VM_ExecuteCommand(696, 2)
end

--  Removes any fading or black screen.
--  - oCreature: creature controlled by player that should be cleared
function StopFade(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(697, 1)
end

--  Sets the screen to black.  Can be used in preparation for a fade-in (FadeFromBlack)
--  Can be cleared by either doing a FadeFromBlack, or by calling StopFade.
--  - oCreature: creature controlled by player that should see black screen
function BlackScreen(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(698, 1)
end

--  Returns the base attach bonus for the given creature.
function GetBaseAttackBonus(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(699, 1)
	return StackPopInteger()
end

--  Set a creature's immortality flag.
--  -oCreature: creature affected
--  -bImmortal: TRUE = creature is immortal and cannot be killed (but still takes damage)
--              FALSE = creature is not immortal and is damaged normally.
--  This scripting command only works on Creature objects.
function SetImmortal(oCreature, bImmortal)
	StackPushBoolean(bImmortal)
	StackPushObject(oCreature)
	VM_ExecuteCommand(700, 2)
end

--  Open's this creature's inventory panel for this player
--  - oCreature: creature to view
--  - oPlayer: the owner of this creature will see the panel pop up
--  * DM's can view any creature's inventory
--  * Players can view their own inventory, or that of their henchman, familiar or animal companion
function OpenInventory(oCreature, oPlayer) 
	StackPushObject(oPlayer)
	StackPushObject(oCreature)
	VM_ExecuteCommand(701, 2)
end

--  Stores the current camera mode and position so that it can be restored (using
--  RestoreCameraFacing())
function StoreCameraFacing()
	VM_ExecuteCommand(702, 0)
end

--  Restores the camera mode and position to what they were last time StoreCameraFacing
--  was called.  RestoreCameraFacing can only be called once, and must correspond to a
--  previous call to StoreCameraFacing.
function RestoreCameraFacing()
	VM_ExecuteCommand(703, 0)
end

--  Levels up a creature using default settings.
--  If successfull it returns the level the creature now is, or 0 if it fails.
--  If you want to give them a different level (ie: Give a Fighter a level of Wizard)
--     you can specify that in the nClass.
--  However, if you specify a class to which the creature no package specified,
--    they will use the default package for that class for their levelup choices.
--    (ie: no Barbarian Savage/Wizard Divination combinations)
--  If you turn on bReadyAllSpells, all memorized spells will be ready to cast without resting.
--  if nPackage is PACKAGE_INVALID then it will use the starting package assigned to that class or just the class package
function LevelUpHenchman(oCreature, nClass, bReadyAllSpells, nPackage)
	nClass  = nClass or 255 --CLASS_TYPE_INVALID
	bReadyAllSpells  = bReadyAllSpells or false
	nPackage  = nPackage or 255 --PACKAGE_INVALID
	
	StackPushInteger(nPackage )
	StackPushBoolean(bReadyAllSpells )
	StackPushInteger(nClass )
	StackPushObject(oCreature)
	VM_ExecuteCommand(704, 4)
	return StackPopInteger()
end

--  Sets the droppable flag on an item
--  - oItem: the item to change
--  - bDroppable: TRUE or FALSE, whether the item should be droppable
--  Droppable items will appear on a creature's remains when the creature is killed.
function SetDroppableFlag(oItem, bDroppable)
	StackPushBoolean(bDroppable)
	StackPushObject(oItem)
	VM_ExecuteCommand(705, 2)
end

--  Gets the weight of an item, or the total carried weight of a creature in tenths
--  of pounds (as per the baseitems.2da).
--  - oTarget: the item or creature for which the weight is needed
function GetWeight(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(706, 1)
	return StackPopInteger()
end

--  Gets the object that acquired the module item.  May be a creature, item, or placeable
function GetModuleItemAcquiredBy()
	VM_ExecuteCommand(707, 0)
	return StackPopObject()
end

--  Get the immortal flag on a creature
function GetImmortal(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(708, 1)
	return StackPopBoolean()
end

--  Does a single attack on every hostile creature within 10ft. of the attacker
--  and determines damage accordingly.  If the attacker has a ranged weapon
--  equipped, this will have no effect.
--  ** NOTE ** This is meant to be called inside the spell script for whirlwind
--  attack, it is not meant to be used to queue up a new whirlwind attack.  To do
--  that you need to call ActionUseFeat(FEAT_WHIRLWIND_ATTACK, oEnemy)
--  - int bDisplayFeedback: TRUE or FALSE, whether or not feedback should be
--    displayed
--  - int bImproved: If TRUE, the improved version of whirlwind is used
function DoWhirlwindAttack(bDisplayFeedback, bImproved)
	if bDisplayFeedback == nil then bDisplayFeedback = true end
	bImproved = bImproved or false
	
	StackPushBoolean(bImproved)
	StackPushBoolean(bDisplayFeedback)
	VM_ExecuteCommand(709, 2)
end

--  Gets a value from a 2DA file on the server and returns it as a string
--  avoid using this function in loops
--  - s2DA: the name of the 2da file, 16 chars max
--  - sColumn: the name of the column in the 2da
--  - nRow: the row in the 2da
--  * returns an empty string if file, row, or column not found
function Get2DAString(s2DA, sColumn, nRow)
	StackPushInteger(nRow)
	StackPushString(sColumn)
	StackPushString(s2DA)
	VM_ExecuteCommand(710, 3)
	return StackPopString()
end

--  Returns an effect of type EFFECT_TYPE_ETHEREAL which works just like EffectSanctuary
--  except that the observers get no saving throw
function EffectEthereal()
	VM_ExecuteCommand(711, 0)
	return StackPopEffect()
end

--  Gets the current AI Level that the creature is running at.
--  Returns one of the following:
--  AI_LEVEL_INVALID, AI_LEVEL_VERY_LOW, AI_LEVEL_LOW, AI_LEVEL_NORMAL, AI_LEVEL_HIGH, AI_LEVEL_VERY_HIGH
function GetAILevel(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(712, 1)
	return StackPopInteger()
end

--  Sets the current AI Level of the creature to the value specified. Does not work on Players.
--  The game by default will choose an appropriate AI level for
--  creatures based on the circumstances that the creature is in.
--  Explicitly setting an AI level will over ride the game AI settings.
--  The new setting will last until SetAILevel is called again with the argument AI_LEVEL_DEFAULT.
--  AI_LEVEL_DEFAULT  - Default setting. The game will take over seting the appropriate AI level when required.
--  AI_LEVEL_VERY_LOW - Very Low priority, very stupid, but low CPU usage for AI. Typically used when no players are in the area.
--  AI_LEVEL_LOW      - Low priority, mildly stupid, but slightly more CPU usage for AI. Typically used when not in combat, but a player is in the area.
--  AI_LEVEL_NORMAL   - Normal priority, average AI, but more CPU usage required for AI. Typically used when creature is in combat.
--  AI_LEVEL_HIGH     - High priority, smartest AI, but extremely high CPU usage required for AI. Avoid using this. It is most likely only ever needed for cutscenes.
function SetAILevel(oTarget, nAILevel)
	StackPushInteger(nAILevel)
	StackPushObject(oTarget)
	VM_ExecuteCommand(713, 2)
end

--  This will return TRUE if the creature running the script is a familiar currently
--  possessed by his master.
--  returns FALSE if not or if the creature object is invalid
function GetIsPossessedFamiliar(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(714, 1)
	return StackPopBoolean()
end

--  This will cause a Player Creature to unpossess his/her familiar.  It will work if run
--  on the player creature or the possessed familiar.  It does not work in conjunction with
--  any DM possession.
function UnpossessFamiliar(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(715, 1)
end

--  This will return TRUE if the area is flagged as either interior or underground.
function GetIsAreaInterior(oArea)
	oArea  = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	VM_ExecuteCommand(716, 1)
	return StackPopBoolean()
end

--  Send a server message (szMessage) to the oPlayer.
function SendMessageToPCByStrRef(oPlayer, nStrRef)
	StackPushInteger(nStrRef)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(717, 2)
end

--  Increment the remaining uses per day for this creature by one.
--  Total number of feats per day can not exceed the maximum.
--  - oCreature: creature to modify
--  - nFeat: constant FEAT_*
function IncrementRemainingFeatUses(oCreature, nFeat)
	StackPushInteger(nFeat)
	StackPushObject(oCreature)
	VM_ExecuteCommand(718, 2)
end

--  Force the character of the player specified to be exported to its respective directory
--  i.e. LocalVault/ServerVault/ etc.
function ExportSingleCharacter(oPlayer)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(719, 1)
end

--  This will play a sound that is associated with a stringRef, it will be a mono sound from the location of the object running the command.
--  if nRunAsAction is off then the sound is forced to play intantly.
function PlaySoundByStrRef(nStrRef, bRunAsAction)
	if bRunAsAction == nil then bRunAsAction = true end
	
	StackPushBoolean(bRunAsAction)
	StackPushInteger(nStrRef)
	VM_ExecuteCommand(720, 2)
end

--  Set the name of oCreature's sub race to sSubRace.
function SetSubRace(oCreature, sSubRace)
	StackPushString(sSubRace)
	StackPushObject(oCreature)
	VM_ExecuteCommand(721, 2)
end

--  Set the name of oCreature's Deity to sDeity.
function SetDeity(oCreature, sDeity)
	StackPushString(sDeity)
	StackPushObject(oCreature)
	VM_ExecuteCommand(722, 2)
end

--  Returns TRUE if the creature oCreature is currently possessed by a DM character.
--  Returns FALSE otherwise.
--  Note: GetIsDMPossessed() will return FALSE if oCreature is the DM character.
--  To determine if oCreature is a DM character use GetIsDM()
function GetIsDMPossessed(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(723, 1)
	return StackPopBoolean()
end

--  Gets the current weather conditions for the area oArea.
--    Returns: WEATHER_CLEAR, WEATHER_RAIN, WEATHER_SNOW, WEATHER_INVALID
--    Note: If called on an Interior area, this will always return WEATHER_CLEAR.
function GetWeather(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(724, 1)
	return StackPopInteger()
end

--  Returns AREA_NATURAL if the area oArea is natural, AREA_ARTIFICIAL otherwise.
--  Returns AREA_INVALID, on an error.
function GetIsAreaNatural(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(725, 1)
	return StackPopInteger()
end

--  Returns AREA_ABOVEGROUND if the area oArea is above ground, AREA_UNDERGROUND otherwise.
--  Returns AREA_INVALID, on an error.
function GetIsAreaAboveGround(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(726, 1)
	return StackPopInteger()
end

--  Use this to get the item last equipped by a player character in OnPlayerEquipItem..
function GetPCItemLastEquipped()
	VM_ExecuteCommand(727, 0)
	return StackPopObject()
end

--  Use this to get the player character who last equipped an item in OnPlayerEquipItem..
function GetPCItemLastEquippedBy()
	VM_ExecuteCommand(728, 0)
	return StackPopObject()
end

--  Use this to get the item last unequipped by a player character in OnPlayerEquipItem..
function GetPCItemLastUnequipped()
	VM_ExecuteCommand(729, 0)
	return StackPopObject()
end

--  Use this to get the player character who last unequipped an item in OnPlayerUnEquipItem..
function GetPCItemLastUnequippedBy()
	VM_ExecuteCommand(730, 0)
	return StackPopObject()
end

--  Creates a new copy of an item, while making a single change to the appearance of the item.
--  Helmet models and simple items ignore iIndex.
--  iType                            iIndex                              iNewValue
--  ITEM_APPR_TYPE_SIMPLE_MODEL      [Ignored]                           Model #
--  ITEM_APPR_TYPE_WEAPON_COLOR      ITEM_APPR_WEAPON_COLOR_*            1-4
--  ITEM_APPR_TYPE_WEAPON_MODEL      ITEM_APPR_WEAPON_MODEL_*            Model #
--  ITEM_APPR_TYPE_ARMOR_MODEL       ITEM_APPR_ARMOR_MODEL_*             Model #
--  ITEM_APPR_TYPE_ARMOR_COLOR       ITEM_APPR_ARMOR_COLOR_* [0]         0-175 [1]
-- 
--  [0] Alternatively, where ITEM_APPR_TYPE_ARMOR_COLOR is specified, if per-part coloring is
--  desired, the following equation can be used for nIndex to achieve that:
-- 
--    ITEM_APPR_ARMOR_NUM_COLORS + (ITEM_APPR_ARMOR_MODEL_ * ITEM_APPR_ARMOR_NUM_COLORS) + ITEM_APPR_ARMOR_COLOR_
-- 
--  For example, to change the CLOTH1 channel of the torso, nIndex would be:
-- 
--    6 + (7 * 6) + 2 = 50
-- 
--  [1] When specifying per-part coloring, the value 255 is allowed and corresponds with the logical
--  function 'clear colour override', which clears the per-part override for that part.
function CopyItemAndModify(oItem, nType, nIndex, nNewValue, bCopyVars)
	bCopyVars = bCopyVars or false
	
	StackPushBoolean(bCopyVars)
	StackPushInteger(nNewValue)
	StackPushInteger(nIndex)
	StackPushInteger(nType)
	StackPushObject(oItem)
	VM_ExecuteCommand(731, 5)
	return StackPopObject()
end

--  Queries the current value of the appearance settings on an item. The parameters are
--  identical to those of CopyItemAndModify().
function GetItemAppearance(oItem, nType, nIndex)
	StackPushInteger(nIndex)
	StackPushInteger(nType)
	StackPushObject(oItem)
	VM_ExecuteCommand(732, 3)
	return StackPopInteger()
end

--  Creates an item property that (when applied to a weapon item) causes a spell to be cast
--  when a successful strike is made, or (when applied to armor) is struck by an opponent.
--  - nSpell uses the IP_CONST_ONHIT_CASTSPELL_* constants
function ItemPropertyOnHitCastSpell(nSpell, nLevel)
	StackPushInteger(nLevel)
	StackPushInteger(nSpell)
	VM_ExecuteCommand(733, 2)
	return StackPopItemProperty() 
end

--  Returns the SubType number of the item property. See the 2DA files for value definitions.
function GetItemPropertySubType(iProperty)
	StackPushItemProperty(iProperty)
	VM_ExecuteCommand(734, 1)
	return StackPopInteger()
end

--  Gets the status of ACTION_MODE_* modes on a creature.
function GetActionMode(oCreature, nMode)
	StackPushInteger(nMode)
	StackPushObject(oCreature)
	VM_ExecuteCommand(735, 2)
	return StackPopBoolean()
end

--  Sets the status of modes ACTION_MODE_* on a creature.
function SetActionMode(oCreature, nMode, bStatus)
	StackPushBoolean(bStatus)
	StackPushInteger(nMode)
	StackPushObject(oCreature)
	VM_ExecuteCommand(736, 3)
end

--  Returns the current arcane spell failure factor of a creature
function GetArcaneSpellFailure(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(737, 1)
	return StackPopInteger()
end

--  Makes a player examine the object oExamine. This causes the examination
--  pop-up box to appear for the object specified.
function ActionExamine(oExamine)
	StackPushObject(oExamine)
	VM_ExecuteCommand(738, 1)
end

--  Creates a visual effect (ITEM_VISUAL_*) that may be applied to
--  melee weapons only.
function ItemPropertyVisualEffect(nEffect)
	StackPushInteger(nEffect)
	VM_ExecuteCommand(739, 1)
	return StackPopItemProperty() 
end

--  Sets the lootable state of a *living* NPC creature.
--  This function will *not* work on players or dead creatures.
function SetLootable(oCreature, bLootable)
	StackPushBoolean(bLootable)
	StackPushObject(oCreature)
	VM_ExecuteCommand(740, 2)
end

--  Returns the lootable state of a creature.
function GetLootable(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(741, 1)
	return StackPopBoolean()
end

--  Returns the current movement rate factor
--  of the cutscene 'camera man'.
--  NOTE: This will be a value between 0.1, 2.0 (10%-200%)
function GetCutsceneCameraMoveRate(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(742, 1)
	return StackPopFloat()
end

--  Sets the current movement rate factor for the cutscene
--  camera man.
--  NOTE: You can only set values between 0.1, 2.0 (10%-200%)
function SetCutsceneCameraMoveRate(oCreature, fRate)
	StackPushFloat(fRate)
	StackPushObject(oCreature)
	VM_ExecuteCommand(743, 2)
end

--  Returns TRUE if the item is cursed and cannot be dropped
function GetItemCursedFlag(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(744, 1)
	return StackPopBoolean()
end

--  When cursed, items cannot be dropped
function SetItemCursedFlag(oItem, bCursed)
	StackPushBoolean(bCursed)
	StackPushObject(oItem)
	VM_ExecuteCommand(745, 2)
end

--  Sets the maximum number of henchmen
function SetMaxHenchmen(nNumHenchmen)
	StackPushInteger(nNumHenchmen)
	VM_ExecuteCommand(746, 1)
end

--  Gets the maximum number of henchmen
function GetMaxHenchmen()
	VM_ExecuteCommand(747, 0)
	return StackPopInteger()
end

--  Returns the associate type of the specified creature.
--  - Returns ASSOCIATE_TYPE_NONE if the creature is not the associate of anyone.
function GetAssociateType(oAssociate)
	StackPushObject(oAssociate)
	VM_ExecuteCommand(748, 1)
	return StackPopInteger()
end

--  Returns the spell resistance of the specified creature.
--  - Returns 0 if the creature has no spell resistance or an invalid
--    creature is passed in.
function GetSpellResistance(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(749, 1)
	return StackPopInteger()
end

--  Changes the current Day/Night cycle for this player to night
--  - oPlayer: which player to change the lighting for
--  - fTransitionTime: how long the transition should take
function DayToNight(oPlayer, fTransitionTime)
	fTransitionTime = fTransitionTime or 0.0
	
	StackPushFloat(fTransitionTime)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(750, 2)
end

--  Changes the current Day/Night cycle for this player to daylight
--  - oPlayer: which player to change the lighting for
--  - fTransitionTime: how long the transition should take
function NightToDay(oPlayer, fTransitionTime)
	fTransitionTime = fTransitionTime or 0.0
	
	StackPushFloat(fTransitionTime)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(751, 2)
end

--  Returns whether or not there is a direct line of sight
--  between the two objects. (Not blocked by any geometry).
-- 
--  PLEASE NOTE: This is an expensive function and may
--               degrade performance if used frequently.
function LineOfSightObject(oSource, oTarget)
	StackPushObject(oTarget)
	StackPushObject(oSource)
	VM_ExecuteCommand(752, 2)
	return StackPopBoolean()
end

--  Returns whether or not there is a direct line of sight
--  between the two vectors. (Not blocked by any geometry).
-- 
--  This function must be run on a valid object in the area
--  it will not work on the module or area.
-- 
--  PLEASE NOTE: This is an expensive function and may
--               degrade performance if used frequently.
function LineOfSightVector(vSource, vTarget)
	StackPushVector(vTarget)
	StackPushVector(vSource)
	VM_ExecuteCommand(753, 2)
	return StackPopBoolean()
end

--  Returns the class that the spellcaster cast the
--  spell as.
--  - Returns CLASS_TYPE_INVALID if the caster has
--    no valid class (placeables, etc...)
function GetLastSpellCastClass()
	VM_ExecuteCommand(754, 0)
	return StackPopInteger()
end

--  Sets the number of base attacks for the specified
--  creatures. The range of values accepted are from
--  1 to 6
--  Note: This function does not work on Player Characters
function SetBaseAttackBonus(nBaseAttackBonus, oCreature)
	oCreature  = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nBaseAttackBonus)
	VM_ExecuteCommand(755, 2)
end

--  Restores the number of base attacks back to it's
--  original state.
function RestoreBaseAttackBonus(oCreature)
	oCreature  = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(756, 1)
end

--  Creates a cutscene ghost effect, this will allow creatures
--  to pathfind through other creatures without bumping into them
--  for the duration of the effect.
function EffectCutsceneGhost()
	VM_ExecuteCommand(757, 0)
	return StackPopEffect()
end

--  Creates an item property that offsets the effect on arcane spell failure
--  that a particular item has. Parameters come from the ITEM_PROP_ASF_* group.
function ItemPropertyArcaneSpellFailure(nModLevel)
	StackPushInteger(nModLevel)
	VM_ExecuteCommand(758, 1)
	return StackPopItemProperty() 
end

--  Returns the amount of gold a store currently has. -1 indicates it is not using gold.
--  -2 indicates the store could not be located.
function GetStoreGold(oidStore)
	StackPushObject(oidStore)
	VM_ExecuteCommand(759, 1)
	return StackPopInteger()
end

--  Sets the amount of gold a store has. -1 means the store does not use gold.
function SetStoreGold(oidStore, nGold)
	StackPushInteger(nGold)
	StackPushObject(oidStore)
	VM_ExecuteCommand(760, 2)
end

--  Gets the maximum amount a store will pay for any item. -1 means price unlimited.
--  -2 indicates the store could not be located.
function GetStoreMaxBuyPrice(oidStore)
	StackPushObject(oidStore)
	VM_ExecuteCommand(761, 1)
	return StackPopInteger()
end

--  Sets the maximum amount a store will pay for any item. -1 means price unlimited.
function SetStoreMaxBuyPrice(oidStore, nMaxBuy)
	StackPushInteger(nMaxBuy)
	StackPushObject(oidStore)
	VM_ExecuteCommand(762, 2)
end

--  Gets the amount a store charges for identifying an item. Default is 100. -1 means
--  the store will not identify items.
--  -2 indicates the store could not be located.
function GetStoreIdentifyCost(oidStore)
	StackPushObject(oidStore)
	VM_ExecuteCommand(763, 1)
	return StackPopInteger()
end

--  Sets the amount a store charges for identifying an item. Default is 100. -1 means
--  the store will not identify items.
function SetStoreIdentifyCost(oidStore, nCost)
	StackPushInteger(nCost)
	StackPushObject(oidStore)
	VM_ExecuteCommand(764, 2)
end

--  Sets the creature's appearance type to the value specified (uses the APPEARANCE_TYPE_XXX constants)
function SetCreatureAppearanceType(oCreature, nAppearanceType)
	StackPushInteger(nAppearanceType)
	StackPushObject(oCreature)
	VM_ExecuteCommand(765, 2)
end

--  Returns the default package selected for this creature to level up with
--  - returns PACKAGE_INVALID if error occurs
function GetCreatureStartingPackage(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(766, 1)
	return StackPopInteger()
end

--  Returns an effect that when applied will paralyze the target's legs, rendering
--  them unable to walk but otherwise unpenalized. This effect cannot be resisted.
function EffectCutsceneImmobilize()
	VM_ExecuteCommand(767, 0)
	return StackPopEffect()
end

--  Is this creature in the given subarea? (trigger, area of effect object, etc..)
--  This function will tell you if the creature has triggered an onEnter event,
--  not if it is physically within the space of the subarea
function GetIsInSubArea(oCreature, oSubArea)
	oSubArea = oSubArea or OBJECT_SELF
	
	StackPushObject(oSubArea)
	StackPushObject(oCreature)
	VM_ExecuteCommand(768, 2)
	return StackPopBoolean()
end

--  Returns the Cost Table number of the item property. See the 2DA files for value definitions.
function GetItemPropertyCostTable(iProp)
	StackPushItemProperty(iProp)
	VM_ExecuteCommand(769, 1)
	return StackPopInteger()
end

--  Returns the Cost Table value (index of the cost table) of the item property.
--  See the 2DA files for value definitions.
function GetItemPropertyCostTableValue(iProp)
	StackPushItemProperty(iProp)
	VM_ExecuteCommand(770, 1)
	return StackPopInteger()
end

--  Returns the Param1 number of the item property. See the 2DA files for value definitions.
function GetItemPropertyParam1(iProp)
	StackPushItemProperty(iProp)
	VM_ExecuteCommand(771, 1)
	return StackPopInteger()
end

--  Returns the Param1 value of the item property. See the 2DA files for value definitions.
function GetItemPropertyParam1Value(iProp)
	StackPushItemProperty(iProp)
	VM_ExecuteCommand(772, 1)
	return StackPopInteger()
end

--  Is this creature able to be disarmed? (checks disarm flag on creature, and if
--  the creature actually has a weapon equipped in their right hand that is droppable)
function GetIsCreatureDisarmable(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(773, 1)
	return StackPopBoolean()
end

--  Sets whether this item is 'stolen' or not
function SetStolenFlag(oItem, bStolenFlag)
	StackPushBoolean(bStolenFlag)
	StackPushObject(oItem)
	VM_ExecuteCommand(774, 2)
end

--  Instantly gives this creature the benefits of a rest (restored hitpoints, spells, feats, etc..)
function ForceRest(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(775, 1)
end

--  Forces this player's camera to be set to this height. Setting this value to zero will
--  restore the camera to the racial default height.
function SetCameraHeight(oPlayer, fHeight)
	fHeight = fHeight or 0.0
	
	StackPushFloat(fHeight)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(776, 2)
end

--  Changes the sky that is displayed in the specified area.
--  nSkyBox = SKYBOX_* constants (associated with skyboxes.2da)
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function SetSkyBox(nSkyBox, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nSkyBox)
	VM_ExecuteCommand(777, 2)
end

--  Returns the creature's currently set PhenoType (body type).
function GetPhenoType(oCreature)
	StackPushObject(oCreature)
	VM_ExecuteCommand(778, 1)
	return StackPopInteger()
end

--  Sets the creature's PhenoType (body type) to the type specified.
--  nPhenoType = PHENOTYPE_NORMAL
--  nPhenoType = PHENOTYPE_BIG
--  nPhenoType = PHENOTYPE_CUSTOM* - The custom PhenoTypes should only ever
--  be used if you have specifically created your own custom content that
--  requires the use of a new PhenoType and you have specified the appropriate
--  custom PhenoType in your custom content.
--  SetPhenoType will only work on part based creature (i.e. the starting
--  default playable races).
function SetPhenoType(nPhenoType, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nPhenoType)
	VM_ExecuteCommand(779, 2)
end

--  Sets the fog color in the area specified.
--  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
--  nFogColor = FOG_COLOR_* specifies the color the fog is being set to.
--  The fog color can also be represented as a hex RGB number if specific color shades
--  are desired.
--  The format of a hex specified color would be 0xFFEEDD where
--  FF would represent the amount of red in the color
--  EE would represent the amount of green in the color
--  DD would represent the amount of blue in the color.
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function SetFogColor(nFogType, nFogColor, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nFogColor)
	StackPushInteger(nFogType)
	VM_ExecuteCommand(780, 3)
end

--  Gets the current cutscene state of the player specified by oCreature.
--  Returns TRUE if the player is in cutscene mode.
--  Returns FALSE if the player is not in cutscene mode, or on an error
--  (such as specifying a non creature object).
function GetCutsceneMode(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(781, 1)
	return StackPopInteger()
end

--  Gets the skybox that is currently displayed in the specified area.
--  Returns:
--      SKYBOX_* constant
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function GetSkyBox(oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	VM_ExecuteCommand(782, 1)
	return StackPopInteger()
end

--  Gets the fog color in the area specified.
--  nFogType specifies wether the Sun, or Moon fog type is returned. 
--     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function GetFogColor(nFogType, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nFogType)
	VM_ExecuteCommand(783, 2)
	return StackPopInteger()
end

--  Sets the fog amount in the area specified.
--  nFogType = FOG_TYPE_* specifies wether the Sun, Moon, or both fog types are set.
--  nFogAmount = specifies the density that the fog is being set to.
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function SetFogAmount(nFogType, nFogAmount, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nFogAmount)
	StackPushInteger(nFogType)
	VM_ExecuteCommand(784, 3)
end

--  Gets the fog amount in the area specified.
--  nFogType = nFogType specifies wether the Sun, or Moon fog type is returned. 
--     Valid values for nFogType are FOG_TYPE_SUN or FOG_TYPE_MOON.
--  If no valid area (or object) is specified, it uses the area of caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function GetFogAmount(nFogType, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nFogType)
	VM_ExecuteCommand(785, 2)
	return StackPopInteger()
end

--  returns TRUE if the item CAN be pickpocketed
function GetPickpocketableFlag(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(786, 1)
	return StackPopBoolean()
end

--  Sets the Pickpocketable flag on an item
--  - oItem: the item to change
--  - bPickpocketable: TRUE or FALSE, whether the item can be pickpocketed.
function SetPickpocketableFlag(oItem, bPickpocketable)
	StackPushBoolean(bPickpocketable)
	StackPushObject(oItem)
	VM_ExecuteCommand(787, 2)
end

--  returns the footstep type of the creature specified.
--  The footstep type determines what the creature's footsteps sound
--  like when ever they take a step.
--  returns FOOTSTEP_TYPE_INVALID if used on a non-creature object, or if
--  used on creature that has no footstep sounds by default (e.g. Will-O'-Wisp).
function GetFootstepType(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(788, 1)
	return StackPopInteger()
end

--  Sets the footstep type of the creature specified.
--  Changing a creature's footstep type will change the sound that
--  its feet make when ever the creature makes takes a step.
--  By default a creature's footsteps are detemined by the appearance
--  type of the creature. SetFootstepType() allows you to make a
--  creature use a difference footstep type than it would use by default
--  for its given appearance.
--  - nFootstepType (FOOTSTEP_TYPE_*):
--       FOOTSTEP_TYPE_NORMAL
--       FOOTSTEP_TYPE_LARGE
--       FOOTSTEP_TYPE_DRAGON
--       FOOTSTEP_TYPE_SoFT
--       FOOTSTEP_TYPE_HOOF
--       FOOTSTEP_TYPE_HOOF_LARGE
--       FOOTSTEP_TYPE_BEETLE
--       FOOTSTEP_TYPE_SPIDER
--       FOOTSTEP_TYPE_SKELETON
--       FOOTSTEP_TYPE_LEATHER_WING
--       FOOTSTEP_TYPE_FEATHER_WING
--       FOOTSTEP_TYPE_DEFAULT - Makes the creature use its original default footstep sounds.
--       FOOTSTEP_TYPE_NONE
--  - oCreature: the creature to change the footstep sound for.
function SetFootstepType(nFootstepType, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nFootstepType)
	VM_ExecuteCommand(789, 2)
end

--  returns the Wing type of the creature specified.
--       CREATURE_WING_TYPE_NONE
--       CREATURE_WING_TYPE_DEMON
--       CREATURE_WING_TYPE_ANGEL
--       CREATURE_WING_TYPE_BAT
--       CREATURE_WING_TYPE_DRAGON
--       CREATURE_WING_TYPE_BUTTERFLY
--       CREATURE_WING_TYPE_BIRD
--  returns CREATURE_WING_TYPE_NONE if used on a non-creature object,
--  if the creature has no wings, or if the creature can not have its
--  wing type changed in the toolset.
function GetCreatureWingType(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(790, 1)
	return StackPopInteger()
end

--  Sets the Wing type of the creature specified.
--  - nWingType (CREATURE_WING_TYPE_*)
--       CREATURE_WING_TYPE_NONE
--       CREATURE_WING_TYPE_DEMON
--       CREATURE_WING_TYPE_ANGEL
--       CREATURE_WING_TYPE_BAT
--       CREATURE_WING_TYPE_DRAGON
--       CREATURE_WING_TYPE_BUTTERFLY
--       CREATURE_WING_TYPE_BIRD
--  - oCreature: the creature to change the wing type for.
--  Note: Only two creature model types will support wings. 
--  The MODELTYPE for the part based (playable races) 'P' 
--  and MODELTYPE 'W'in the appearance.2da
function SetCreatureWingType(nWingType, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nWingType)
	VM_ExecuteCommand(791, 2)
end

--  returns the model number being used for the body part and creature specified
--  The model number returned is for the body part when the creature is not wearing
--  armor (i.e. whether or not the creature is wearing armor does not affect
--  the return value).
--  Note: Only works on part based creatures, which is typically restricted to
--  the playable races (unless some new part based custom content has been 
--  added to the module).
-- 
--  returns CREATURE_PART_INVALID if used on a non-creature object,
--  or if the creature does not use a part based model.
-- 
--  - nPart (CREATURE_PART_*)
--       CREATURE_PART_RIGHT_FOOT
--       CREATURE_PART_LEFT_FOOT
--       CREATURE_PART_RIGHT_SHIN
--       CREATURE_PART_LEFT_SHIN
--       CREATURE_PART_RIGHT_THIGH
--       CREATURE_PART_LEFT_THIGH
--       CREATURE_PART_PELVIS
--       CREATURE_PART_TORSO
--       CREATURE_PART_BELT
--       CREATURE_PART_NECK
--       CREATURE_PART_RIGHT_FOREARM
--       CREATURE_PART_LEFT_FOREARM
--       CREATURE_PART_RIGHT_BICEP
--       CREATURE_PART_LEFT_BICEP
--       CREATURE_PART_RIGHT_SHOULDER
--       CREATURE_PART_LEFT_SHOULDER
--       CREATURE_PART_RIGHT_HAND
--       CREATURE_PART_LEFT_HAND
--       CREATURE_PART_HEAD
function GetCreatureBodyPart(nPart, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nPart)
	VM_ExecuteCommand(792, 2)
	return StackPopInteger()
end

--  Sets the body part model to be used on the creature specified.
--  The model names for parts need to be in the following format:
--    p<m/f><race letter><phenotype>_<body part><model number>.mdl
-- 
--  - nPart (CREATURE_PART_*)
--       CREATURE_PART_RIGHT_FOOT
--       CREATURE_PART_LEFT_FOOT
--       CREATURE_PART_RIGHT_SHIN
--       CREATURE_PART_LEFT_SHIN
--       CREATURE_PART_RIGHT_THIGH
--       CREATURE_PART_LEFT_THIGH
--       CREATURE_PART_PELVIS
--       CREATURE_PART_TORSO
--       CREATURE_PART_BELT
--       CREATURE_PART_NECK
--       CREATURE_PART_RIGHT_FOREARM
--       CREATURE_PART_LEFT_FOREARM
--       CREATURE_PART_RIGHT_BICEP
--       CREATURE_PART_LEFT_BICEP
--       CREATURE_PART_RIGHT_SHOULDER
--       CREATURE_PART_LEFT_SHOULDER
--       CREATURE_PART_RIGHT_HAND
--       CREATURE_PART_LEFT_HAND
--       CREATURE_PART_HEAD
--  - nModelNumber: CREATURE_MODEL_TYPE_*
--       CREATURE_MODEL_TYPE_NONE
--       CREATURE_MODEL_TYPE_SKIN (not for use on shoulders, pelvis or head).
--       CREATURE_MODEL_TYPE_TATTOO (for body parts that support tattoos, i.e. not heads/feet/hands).
--       CREATURE_MODEL_TYPE_UNDEAD (undead model only exists for the right arm parts).
--  - oCreature: the creature to change the body part for.
--  Note: Only part based creature appearance types are supported. 
--  i.e. The model types for the playable races ('P') in the appearance.2da
function SetCreatureBodyPart(nPart, nModelNumber, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nModelNumber)
	StackPushInteger(nPart)
	VM_ExecuteCommand(793, 3)
end

--  returns the Tail type of the creature specified.
--       CREATURE_TAIL_TYPE_NONE
--       CREATURE_TAIL_TYPE_LIZARD
--       CREATURE_TAIL_TYPE_BONE
--       CREATURE_TAIL_TYPE_DEVIL
--  returns CREATURE_TAIL_TYPE_NONE if used on a non-creature object,
--  if the creature has no Tail, or if the creature can not have its
--  Tail type changed in the toolset.
function GetCreatureTailType(oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	VM_ExecuteCommand(794, 1)
	return StackPopInteger()
end

--  Sets the Tail type of the creature specified.
--  - nTailType (CREATURE_TAIL_TYPE_*)
--       CREATURE_TAIL_TYPE_NONE
--       CREATURE_TAIL_TYPE_LIZARD
--       CREATURE_TAIL_TYPE_BONE
--       CREATURE_TAIL_TYPE_DEVIL
--  - oCreature: the creature to change the Tail type for.
--  Note: Only two creature model types will support Tails. 
--  The MODELTYPE for the part based (playable) races 'P' 
--  and MODELTYPE 'T'in the appearance.2da
function SetCreatureTailType(nTailType, oCreature)
	oCreature = oCreature or OBJECT_SELF
	
	StackPushObject(oCreature)
	StackPushInteger(nTailType)
	VM_ExecuteCommand(795, 2)
end

--  returns the Hardness of a Door or Placeable object.
--  - oObject: a door or placeable object.
--  returns -1 on an error or if used on an object that is
--  neither a door nor a placeable object.
function GetHardness(oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	VM_ExecuteCommand(796, 1)
	return StackPopInteger()
end

--  Sets the Hardness of a Door or Placeable object.
--  - nHardness: must be between 0 and 250.
--  - oObject: a door or placeable object.
--  Does nothing if used on an object that is neither
--  a door nor a placeable.
function SetHardness(nHardness, oObject)
	oObject = oObject or OBJECT_SELF
	
	StackPushObject(oObject)
	StackPushInteger(nHardness)
	VM_ExecuteCommand(797, 2)
end

--  When set the object can not be opened unless the
--  opener possesses the required key. The key tag required
--  can be specified either in the toolset, or by using
--  the SetLockKeyTag() scripting command.
--  - oObject: a door, or placeable.
--  - nKeyRequired: TRUE/FALSE
function SetLockKeyRequired(oObject, bKeyRequired)
	if bKeyRequired == nil then bKeyRequired = true end
	
	StackPushBoolean(bKeyRequired)
	StackPushObject(oObject)
	VM_ExecuteCommand(798, 2)
end

--  Set the key tag required to open object oObject.
--  This will only have an effect if the object is set to
--  "Key required to unlock or lock" either in the toolset
--  or by using the scripting command SetLockKeyRequired().
--  - oObject: a door, placeable or trigger.
--  - sNewKeyTag: the key tag required to open the locked object.
function SetLockKeyTag(oObject, sNewKeyTag)
	StackPushString(sNewKeyTag)
	StackPushObject(oObject)
	VM_ExecuteCommand(799, 2)
end

--  Sets whether or not the object can be locked.
--  - oObject: a door or placeable.
--  - nLockable: TRUE/FALSE
function SetLockLockable(oObject, bLockable)
	if bLockable == nil then bLockable = true end
	
	StackPushBoolean(bLockable)
	StackPushObject(oObject)
	VM_ExecuteCommand(800, 2)
end

--  Sets the DC for unlocking the object.
--  - oObject: a door or placeable object.
--  - nNewUnlockDC: must be between 0 and 250.
function SetLockUnlockDC(oObject, nNewUnlockDC)
	StackPushInteger(nNewUnlockDC)
	StackPushObject(oObject)
	VM_ExecuteCommand(801, 2)
end

--  Sets the DC for locking the object.
--  - oObject: a door or placeable object.
--  - nNewLockDC: must be between 0 and 250.
function SetLockLockDC(oObject, nNewLockDC)
	StackPushInteger(nNewLockDC)
	StackPushObject(oObject)
	VM_ExecuteCommand(802, 2)
end

--  Sets whether or not the trapped object can be disarmed.
--  - oTrapObject: a placeable, door or trigger
--  - nDisarmable: TRUE/FALSE
function SetTrapDisarmable(oTrapObject, bDisarmable)
	if bDisarmable == nil then bDisarmable = true end
	
	StackPushInteger(bDisarmable)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(803, 2)
end

--  Sets whether or not the trapped object can be detected.
--  - oTrapObject: a placeable, door or trigger
--  - nDetectable: TRUE/FALSE
--  Note: Setting a trapped object to not be detectable will
--  not make the trap disappear if it has already been detected.
function SetTrapDetectable(oTrapObject, bDetectable)
	if bDetectable == nil then bDetectable = true end
	
	StackPushBoolean(bDetectable)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(804, 2)
end

--  Sets whether or not the trap is a one-shot trap
--  (i.e. whether or not the trap resets itself after firing).
--  - oTrapObject: a placeable, door or trigger
--  - nOneShot: TRUE/FALSE
function SetTrapOneShot(oTrapObject, bOneShot)
	if bOneShot == nil then bOneShot = true end
	
	StackPushBoolean(bOneShot)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(805, 2)
end

--  Set the tag of the key that will disarm oTrapObject.
--  - oTrapObject: a placeable, door or trigger
function SetTrapKeyTag(oTrapObject, sKeyTag)
	StackPushString(sKeyTag)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(806, 2)
end

--  Set the DC for disarming oTrapObject.
--  - oTrapObject: a placeable, door or trigger
--  - nDisarmDC: must be between 0 and 250.
function SetTrapDisarmDC(oTrapObject, nDisarmDC)
	StackPushInteger(nDisarmDC)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(807, 2)
end

--  Set the DC for detecting oTrapObject.
--  - oTrapObject: a placeable, door or trigger
--  - nDetectDC: must be between 0 and 250.
function SetTrapDetectDC(oTrapObject, nDetectDC)
	StackPushInteger(nDetectDC)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(808, 2)
end

--  Creates a square Trap object.
--  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
--  - lLocation: The location and orientation that the trap will be created at.
--  - fSize: The size of the trap. Minimum size allowed is 1.0f.
--  - sTag: The tag of the trap being created.
--  - nFaction: The faction of the trap (STANDARD_FACTION_*).
--  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
--                     If "" no script will fire.
--  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
--                            trap is triggered.
--                            If "" the default OnTrapTriggered script for the trap
--                            type specified will fire instead (as specified in the
--                            traps.2da).
function CreateTrapAtLocation(nTrapType, lLocation, fSize, sTag, nFaction, sOnDisarmScript, sOnTrapTriggeredScript)
	fSize = fSize or 2.0
	sTag = sTag or ""
	nFaction = nFaction or 0 --STANDARD_FACTION_HOSTILE
	sOnDisarmScript = sOnDisarmScript or ""
	sOnTrapTriggeredScript = sOnTrapTriggeredScript or ""
	
	StackPushString(sOnTrapTriggeredScript)
	StackPushString(sOnDisarmScript)
	StackPushInteger(nFaction)
	StackPushString(sTag)
	StackPushFloat(fSize)
	StackPushLocation(lLocation)
	StackPushInteger(nTrapType)
	VM_ExecuteCommand(809, 7)
	return StackPopObject()
end

--  Creates a Trap on the object specified.
--  - nTrapType: The base type of trap (TRAP_BASE_TYPE_*)
--  - oObject: The object that the trap will be created on. Works only on Doors and Placeables.
--  - nFaction: The faction of the trap (STANDARD_FACTION_*).
--  - sOnDisarmScript: The OnDisarm script that will fire when the trap is disarmed.
--                     If "" no script will fire.
--  - sOnTrapTriggeredScript: The OnTrapTriggered script that will fire when the
--                            trap is triggered.
--                            If "" the default OnTrapTriggered script for the trap
--                            type specified will fire instead (as specified in the
--                            traps.2da).
--  Note: After creating a trap on an object, you can change the trap's properties
--        using the various SetTrap* scripting commands by passing in the object
--        that the trap was created on (i.e. oObject) to any subsequent SetTrap* commands.
function CreateTrapOnObject(nTrapType, oObject, nFaction, sOnDisarmScript, sOnTrapTriggeredScript)
	nFaction = nFaction or 0 --STANDARD_FACTION_HOSTILE
	sOnDisarmScript = sOnDisarmScript or ""
	sOnTrapTriggeredScript = sOnTrapTriggeredScript or ""
	
	StackPushString(sOnTrapTriggeredScript)
	StackPushString(sOnDisarmScript)
	StackPushInteger(nFaction)
	StackPushObject(oObject)
	StackPushInteger(nTrapType)
	VM_ExecuteCommand(810, 5)
end

--  Set the Will saving throw value of the Door or Placeable object oObject.
--  - oObject: a door or placeable object.
--  - nWillSave: must be between 0 and 250.
function SetWillSavingThrow(oObject, nWillSave)
	StackPushInteger(nWillSave)
	StackPushObject(oObject)
	VM_ExecuteCommand(811, 2)
end

--  Set the Reflex saving throw value of the Door or Placeable object oObject.
--  - oObject: a door or placeable object.
--  - nReflexSave: must be between 0 and 250.
function SetReflexSavingThrow(oObject, nReflexSave)
	StackPushInteger(nReflexSave)
	StackPushObject(oObject)
	VM_ExecuteCommand(812, 2)
end

--  Set the Fortitude saving throw value of the Door or Placeable object oObject.
--  - oObject: a door or placeable object.
--  - nFortitudeSave: must be between 0 and 250.
function SetFortitudeSavingThrow(oObject, nFortitudeSave)
	StackPushInteger(nFortitudeSave)
	StackPushObject(oObject)
	VM_ExecuteCommand(813, 2)
end

--  returns the resref (TILESET_RESREF_*) of the tileset used to create area oArea.
--       TILESET_RESREF_BEHOLDER_CAVES
--       TILESET_RESREF_CASTLE_INTERIOR
--       TILESET_RESREF_CITY_EXTERIOR
--       TILESET_RESREF_CITY_INTERIOR
--       TILESET_RESREF_CRYPT
--       TILESET_RESREF_DESERT
--       TILESET_RESREF_DROW_INTERIOR
--       TILESET_RESREF_DUNGEON
--       TILESET_RESREF_FOREST
--       TILESET_RESREF_FROZEN_WASTES
--       TILESET_RESREF_ILLITHID_INTERIOR
--       TILESET_RESREF_MICROSET
--       TILESET_RESREF_MINES_AND_CAVERNS
--       TILESET_RESREF_RUINS
--       TILESET_RESREF_RURAL
--       TILESET_RESREF_RURAL_WINTER
--       TILESET_RESREF_SEWERS
--       TILESET_RESREF_UNDERDARK
--  * returns an empty string on an error.
function GetTilesetResRef(oArea)
	StackPushObject(oArea)
	VM_ExecuteCommand(814, 1)
	return StackPopString()
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject can be recovered.
function GetTrapRecoverable(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(815, 1)
	return StackPopBoolean()
end

--  Sets whether or not the trapped object can be recovered.
--  - oTrapObject: a placeable, door or trigger
function SetTrapRecoverable(oTrapObject, bRecoverable)
	if bRecoverable == nil then bRecoverable = true end
	
	StackPushBoolean(bRecoverable)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(816, 2)
end

--  Get the XP scale being used for the module.
function GetModuleXPScale()
	VM_ExecuteCommand(817, 0)
	return StackPopInteger()
end

--  Set the XP scale used by the module.
--  - nXPScale: The XP scale to be used. Must be between 0 and 200.
function SetModuleXPScale(nXPScale)
	StackPushInteger(nXPScale)
	VM_ExecuteCommand(818, 1)
end

--  Get the feedback message that will be displayed when trying to unlock the object oObject.
--  - oObject: a door or placeable.
--  Returns an empty string "" on an error or if the game's default feedback message is being used
function GetKeyRequiredFeedback(oObject)
	StackPushObject(oObject)
	VM_ExecuteCommand(819, 1)
	return StackPopString()
end

--  Set the feedback message that is displayed when trying to unlock the object oObject.
--  This will only have an effect if the object is set to
--  "Key required to unlock or lock" either in the toolset
--  or by using the scripting command SetLockKeyRequired().
--  - oObject: a door or placeable.
--  - sFeedbackMessage: the string to be displayed in the player's text window.
--                      to use the game's default message, set sFeedbackMessage to ""
function SetKeyRequiredFeedback(oObject, sFeedbackMessage)
	StackPushString(sFeedbackMessage)
	StackPushObject(oObject)
	VM_ExecuteCommand(820, 2)
end

--  - oTrapObject: a placeable, door or trigger
--  * Returns TRUE if oTrapObject is active
function GetTrapActive(oTrapObject)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(821, 1)
	return StackPopBoolean()
end

--  Sets whether or not the trap is an active trap
--  - oTrapObject: a placeable, door or trigger
--  - nActive: TRUE/FALSE
--  Notes:
--  Setting a trap as inactive will not make the
--  trap disappear if it has already been detected.
--  Call SetTrapDetectedBy() to make a detected trap disappear.
--  To make an inactive trap not detectable call SetTrapDetectable()
function SetTrapActive(oTrapObject, bActive)
	if bActive == nil then bActive = true end
	
	StackPushBoolean(bActive)
	StackPushObject(oTrapObject)
	VM_ExecuteCommand(822, 2)
end

--  Locks the player's camera pitch to its current pitch setting,
--  or unlocks the player's camera pitch.
--  Stops the player from tilting their camera angle. 
--  - oPlayer: A player object.
--  - bLocked: TRUE/FALSE.
function LockCameraPitch(oPlayer, bLocked)
	if bLocked == nil then bLocked = true end
	
	StackPushBoolean(bLocked)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(823, 2)
end

--  Locks the player's camera distance to its current distance setting,
--  or unlocks the player's camera distance.
--  Stops the player from being able to zoom in/out the camera.
--  - oPlayer: A player object.
--  - bLocked: TRUE/FALSE.
function LockCameraDistance(oPlayer, bLocked)
	if bLocked == nil then bLocked = true end
	
	StackPushBoolean(bLocked)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(824, 2)
end

--  Locks the player's camera direction to its current direction,
--  or unlocks the player's camera direction to enable it to move
--  freely again.
--  Stops the player from being able to rotate the camera direction.
--  - oPlayer: A player object.
--  - bLocked: TRUE/FALSE.
function LockCameraDirection(oPlayer, bLocked)
	if bLocked == nil then bLocked = true end
	
	StackPushBoolean(bLocked)
	StackPushObject(oPlayer)
	VM_ExecuteCommand(825, 2)
end

--  Get the last object that default clicked (left clicked) on the placeable object
--  that is calling this function.
--  Should only be called from a placeables OnClick event.
--  * Returns OBJECT_INVALID if it is called by something other than a placeable.
function GetPlaceableLastClickedBy()
	VM_ExecuteCommand(826, 0)
	return StackPopObject()
end

--  returns TRUE if the item is flagged as infinite.
--  - oItem: an item.
--  The infinite property affects the buying/selling behavior of the item in a store.
--  An infinite item will still be available to purchase from a store after a player
--  buys the item (non-infinite items will disappear from the store when purchased).
function GetInfiniteFlag(oItem)
	StackPushObject(oItem)
	VM_ExecuteCommand(827, 1)
	return StackPopBoolean()
end

--  Sets the Infinite flag on an item
--  - oItem: the item to change
--  - bInfinite: TRUE or FALSE, whether the item should be Infinite
--  The infinite property affects the buying/selling behavior of the item in a store.
--  An infinite item will still be available to purchase from a store after a player
--  buys the item (non-infinite items will disappear from the store when purchased).
function SetInfiniteFlag(oItem, bInfinite)
	if bInfinite == nil then bInfinite = true end
	
	StackPushBoolean(bInfinite)
	StackPushObject(oItem)
	VM_ExecuteCommand(828, 2)
end

--  Gets the size of the area.
--  - nAreaDimension: The area dimension that you wish to determine.
--       AREA_HEIGHT
--       AREA_WIDTH
--  - oArea: The area that you wish to get the size of.
--  Returns: The number of tiles that the area is wide/high, or zero on an error.
--  If no valid area (or object) is specified, it uses the area of the caller.
--  If an object other than an area is specified, will use the area that the object is currently in.
function GetAreaSize(nAreaDimension, oArea)
	oArea = oArea or OBJECT_INVALID
	
	StackPushObject(oArea)
	StackPushInteger(nAreaDimension)
	VM_ExecuteCommand(829, 2)
	return StackPopInteger()
end

--  Set the name of oObject.
--  - oObject: the object for which you are changing the name (a creature, placeable, item, or door).
--  - sNewName: the new name that the object will use.
--  Note: SetName() does not work on player objects.
--        Setting an object's name to "" will make the object
--        revert to using the name it had originally before any
--        SetName() calls were made on the object.
function SetName(oObject, sNewName)
	sNewName = sNewName or ""
	
	StackPushString(sNewName)
	StackPushObject(oObject)
	VM_ExecuteCommand(830, 2)
end

--  Get the PortraitId of oTarget.
--  - oTarget: the object for which you are getting the portrait Id.
--  Returns: The Portrait Id number being used for the object oTarget.
--           The Portrait Id refers to the row number of the Portraits.2da
--           that this portrait is from.
--           If a custom portrait is being used, oTarget is a player object,
--           or on an error returns PORTRAIT_INVALID. In these instances
--           try using GetPortraitResRef() instead.
function GetPortraitId(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(831, 1)
	return StackPopInteger()
end

--  Change the portrait of oTarget to use the Portrait Id specified.
--  - oTarget: the object for which you are changing the portrait.
--  - nPortraitId: The Id of the new portrait to use. 
--                 nPortraitId refers to a row in the Portraits.2da
--  Note: Not all portrait Ids are suitable for use with all object types.
--        Setting the portrait Id will also cause the portrait ResRef
--        to be set to the appropriate portrait ResRef for the Id specified.
function SetPortraitId(oTarget, nPortraitId)
	StackPushInteger(nPortraitId)
	StackPushObject(oTarget)
	VM_ExecuteCommand(832, 2)
end

--  Get the Portrait ResRef of oTarget.
--  - oTarget: the object for which you are getting the portrait ResRef.
--  Returns: The Portrait ResRef being used for the object oTarget.
--           The Portrait ResRef will not include a trailing size letter.
function GetPortraitResRef(oTarget)
	oTarget = oTarget or OBJECT_SELF
	
	StackPushObject(oTarget)
	VM_ExecuteCommand(833, 1)
	return StackPopString()
end

--  Change the portrait of oTarget to use the Portrait ResRef specified.
--  - oTarget: the object for which you are changing the portrait.
--  - sPortraitResRef: The ResRef of the new portrait to use. 
--                     The ResRef should not include any trailing size letter ( e.g. po_el_f_09_ ).
--  Note: Not all portrait ResRefs are suitable for use with all object types.
--        Setting the portrait ResRef will also cause the portrait Id
--        to be set to PORTRAIT_INVALID.
function SetPortraitResRef(oTarget, sPortraitResRef)  
	StackPushString(sPortraitResRef)
	StackPushObject(oTarget)
	VM_ExecuteCommand(834, 2)
end

--  Set oPlaceable's useable object status.
--  Note: Only works on non-static placeables.
function SetUseableFlag(oPlaceable, bUseableFlag)
	StackPushBoolean(bUseableFlag)
	StackPushObject(oPlaceable)
	VM_ExecuteCommand(835, 2)
end

--  Get the description of oObject.
--  - oObject: the object from which you are obtaining the description. 
--             Can be a creature, item, placeable, door, trigger or module object.
--  - bOriginalDescription:  if set to true any new description specified via a SetDescription scripting command
--                    is ignored and the original object's description is returned instead.
--  - bIdentified: If oObject is an item, setting this to TRUE will return the identified description,
--                 setting this to FALSE will return the unidentified description. This flag has no
--                 effect on objects other than items.
function GetDescription(oObject, bOriginalDescription, bIdentifiedDescription)
	bOriginalDescription = bOriginalDescription or false
	if bIdentifiedDescription == nil then bIdentifiedDescription = true end
	
	StackPushBoolean(bIdentifiedDescription)
	StackPushBoolean(bOriginalDescription)
	StackPushObject(oObject)
	VM_ExecuteCommand(836, 3)
	return StackPopString()
end

--  Set the description of oObject.
--  - oObject: the object for which you are changing the description 
--             Can be a creature, placeable, item, door, or trigger.
--  - sNewDescription: the new description that the object will use.
--  - bIdentified: If oObject is an item, setting this to TRUE will set the identified description,
--                 setting this to FALSE will set the unidentified description. This flag has no
--                 effect on objects other than items.
--  Note: Setting an object's description to "" will make the object
--        revert to using the description it originally had before any
--        SetDescription() calls were made on the object.
function SetDescription(oObject, sNewDescription, bIdentifiedDescription)
	sNewDescription = sNewDescription or ""
	if bIdentifiedDescription == nil then bIdentifiedDescription = true end
	
	StackPushBoolean(bIdentifiedDescription)
	StackPushString(sNewDescription)
	StackPushObject(oObject)
	VM_ExecuteCommand(837, 3)
end

--  Get the PC that sent the last player chat(text) message.
--  Should only be called from a module's OnPlayerChat event script.
--  * Returns OBJECT_INVALID on error.
--  Note: Private tells do not trigger a OnPlayerChat event.
function GetPCChatSpeaker()
	VM_ExecuteCommand(838, 0)
	return StackPopObject()
end

--  Get the last player chat(text) message that was sent.
--  Should only be called from a module's OnPlayerChat event script.
--  * Returns empty string "" on error.
--  Note: Private tells do not trigger a OnPlayerChat event.
function GetPCChatMessage()
	VM_ExecuteCommand(839, 0)
	return StackPopString()
end

--  Get the volume of the last player chat(text) message that was sent.
--  Returns one of the following TALKVOLUME_* constants based on the volume setting
--  that the player used to send the chat message.
--                 TALKVOLUME_TALK
--                 TALKVOLUME_WHISPER
--                 TALKVOLUME_SHOUT
--                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
--                 TALKVOLUME_PARTY
--  Should only be called from a module's OnPlayerChat event script.
--  * Returns -1 on error.
--  Note: Private tells do not trigger a OnPlayerChat event.
function GetPCChatVolume()
	VM_ExecuteCommand(840, 0)
	return StackPopInteger()
end

--  Set the last player chat(text) message before it gets sent to other players.
--  - sNewChatMessage: The new chat text to be sent onto other players.
--                     Setting the player chat message to an empty string "",
--                     will cause the chat message to be discarded 
--                     (i.e. it will not be sent to other players).
--  Note: The new chat message gets sent after the OnPlayerChat script exits.
function SetPCChatMessage(sNewChatMessage)
	sNewChatMessage = sNewChatMessage or ""
	
	StackPushString(sNewChatMessage)
	VM_ExecuteCommand(841, 1)
end

--  Set the last player chat(text) volume before it gets sent to other players.
--  - nTalkVolume: The new volume of the chat text to be sent onto other players.
--                 TALKVOLUME_TALK
--                 TALKVOLUME_WHISPER
--                 TALKVOLUME_SHOUT
--                 TALKVOLUME_SILENT_SHOUT (used for DM chat channel)
--                 TALKVOLUME_PARTY
--                 TALKVOLUME_TELL (sends the chat message privately back to the original speaker)
--  Note: The new chat message gets sent after the OnPlayerChat script exits.
function SetPCChatVolume(nTalkVolume)
	nTalkVolume = nTalkVolume or 0 --TALKVOLUME_TALK
	
	StackPushInteger(nTalkVolume)
	VM_ExecuteCommand(842, 1)
end

--  Get the Color of oObject from the color channel specified.
--  - oObject: the object from which you are obtaining the color. 
--             Can be a creature that has color information (i.e. the playable races).
--  - nColorChannel: The color channel that you want to get the color value of.
--                    COLOR_CHANNEL_SKIN
--                    COLOR_CHANNEL_HAIR
--                    COLOR_CHANNEL_TATTOO_1
--                    COLOR_CHANNEL_TATTOO_2
--  * Returns -1 on error.
function GetColor(oObject, nColorChannel)
	StackPushInteger(nColorChannel)
	StackPushObject(oObject)
	VM_ExecuteCommand(843, 2)
	return StackPopInteger()
end

--  Set the color channel of oObject to the color specified.
--  - oObject: the object for which you are changing the color.
--             Can be a creature that has color information (i.e. the playable races).
--  - nColorChannel: The color channel that you want to set the color value of.
--                    COLOR_CHANNEL_SKIN
--                    COLOR_CHANNEL_HAIR
--                    COLOR_CHANNEL_TATTOO_1
--                    COLOR_CHANNEL_TATTOO_2
--  - nColorValue: The color you want to set (0-175).
function SetColor(oObject, nColorChannel, nColorValue)
	StackPushInteger(nColorValue)
	StackPushInteger(nColorChannel)
	StackPushObject(oObject)
	VM_ExecuteCommand(844, 3)
end

--  Returns Item property Material.  You need to specify the Material Type.
--  - nMasterialType: The Material Type should be a positive integer between 0 and 77 (see iprp_matcost.2da).
--  Note: The Material Type property will only affect the cost of the item if you modify the cost in the iprp_matcost.2da.
function ItemPropertyMaterial(nMaterialType)
	StackPushInteger(nMaterialType)
	VM_ExecuteCommand(845, 1)
	return StackPopItemProperty() 
end

--  Returns Item property Quality. You need to specify the Quality.
--  - nQuality:  The Quality of the item property to create (see iprp_qualcost.2da).
--               IP_CONST_QUALITY_*
--  Note: The quality property will only affect the cost of the item if you modify the cost in the iprp_qualcost.2da.
function ItemPropertyQuality(nQuality)
	StackPushInteger(nQuality)
	VM_ExecuteCommand(846, 1)
	return StackPopItemProperty() 
end

--  Returns a generic Additional Item property. You need to specify the Additional property.
--  - nProperty: The item property to create (see iprp_addcost.2da).
--               IP_CONST_ADDITIONAL_*
--  Note: The additional property only affects the cost of the item if you modify the cost in the iprp_addcost.2da.
function ItemPropertyAdditional(nAdditionalProperty)
	StackPushInteger(nAdditionalProperty)
	VM_ExecuteCommand(847, 1)
	return StackPopItemProperty() 
end

-- NEW EE Functions

--  Sets a new tag for oObject.
--  Will do nothing for invalid objects or the module object.
-- 
--  Note: Care needs to be taken with this function.
--        Changing the tag for creature with waypoints will make them stop walking them.
--        Changing waypoint, door or trigger tags will break their area transitions.
function SetTag(oObject, sNewTag)
    StackPushString(sNewTag)
    StackPushObject(oObject)
    VM_ExecuteCommand(848, 2)
end

--  Returns the string tag set for the provided effect.
--  - If no tag has been set, returns an empty string.
function GetEffectTag(eEffect)
    StackPushEffect(eEffect)
    VM_ExecuteCommand(849, 1)
    return StackPopString()
end

--  Tags the effect with the provided string.
--  - Any other tags in the link will be overwritten.
function TagEffect(eEffect, sNewTag)
    StackPushString(sNewTag)
    StackPushEffect(eEffect)
    VM_ExecuteCommand(850, 2)
    return StackPopEffect()
end

--  Returns the caster level of the creature who created the effect.
--  - If not created by a creature, returns 0.
--  - If created by a spell-like ability, returns 0.
function GetEffectCasterLevel(eEffect)
    StackPushEffect(eEffect)
    VM_ExecuteCommand(851, 1)
    return StackPopInteger()
end

--  Returns the total duration of the effect in seconds.
--  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
function GetEffectDuration(eEffect)
    StackPushEffect(eEffect)
    VM_ExecuteCommand(852, 1)
    return StackPopInteger()
end

--  Returns the remaining duration of the effect in seconds.
--  - Returns 0 if the duration type of the effect is not DURATION_TYPE_TEMPORARY.
function GetEffectDurationRemaining(eEffect)
    StackPushEffect(eEffect)
    VM_ExecuteCommand(853, 1)
    return StackPopInteger()
end

--  Returns the string tag set for the provided item property.
--  - If no tag has been set, returns an empty string.
function GetItemPropertyTag(nProperty)
    StackPushItemProperty(nProperty)
    VM_ExecuteCommand(854, 1)
    return StackPopString()
end

--  Tags the item property with the provided string.
--  - Any tags currently set on the item property will be overwritten.
function TagItemProperty(nProperty, sNewTag)
    StackPushString(sNewTag)
    StackPushItemProperty(nProperty)
    VM_ExecuteCommand(855, 2)
    return StackPopItemProperty()
end

--  Returns the total duration of the item property in seconds.
--  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
function GetItemPropertyDuration(nProperty)
    StackPushItemProperty(nProperty)
    VM_ExecuteCommand(856, 1)
    return StackPopInteger()
end

--  Returns the remaining duration of the item property in seconds.
--  - Returns 0 if the duration type of the item property is not DURATION_TYPE_TEMPORARY.
function GetItemPropertyDurationRemaining(nProperty)
    StackPushItemProperty(nProperty)
    VM_ExecuteCommand(857, 1)
    return StackPopInteger()
end

--  Instances a new area from the given resref, which needs to be a existing module area.
--  Will optionally set a new area tag and displayed name. The new area is accessible
--  immediately, but initialisation scripts for the area and all contained creatures will only
--  run after the current script finishes (so you can clean up objects before returning).
-- 
--  Returns the new area, or OBJECT_INVALID on failure.
-- 
--  Note: When spawning a second instance of a existing area, you will have to manually
--        adjust all transitions (doors, triggers) with the relevant script commands,
--        or players might end up in the wrong area.
function CreateArea(sResRef, sNewTag, sNewName)
	sNewTag = sNewTag or ""
	sNewName = sNewName or ""
    StackPushString(sNewName)
    StackPushString(sNewTag)
    StackPushString(sResRef)
    VM_ExecuteCommand(858, 3)
    return StackPopObject()
end

--  Destroys the given area object and everything in it.
-- 
--  Return values:
--     0: Object not an area or invalid.
--    -1: Area contains spawn location and removal would leave module without entrypoint.
--    -2: Players in area.
--     1: Area destroyed successfully.
function DestroyArea(oArea)
    StackPushObject(oArea)
    VM_ExecuteCommand(859, 1)
    return StackPopInteger()
end

--  Creates a copy of a existing area, including everything inside of it (except players).
-- 
--  Returns the new area, or OBJECT_INVALID on error.
-- 
--  Note: You will have to manually adjust all transitions (doors, triggers) with the
--        relevant script commands, or players might end up in the wrong area.
function CopyArea(oArea)
    StackPushObject(oArea)
    VM_ExecuteCommand(860, 1)
    return StackPopObject()
end

--  Returns the first area in the module.
function GetFirstArea()
    VM_ExecuteCommand(861, 0)
    return StackPopObject()
end

--  Returns the next area in the module (after GetFirstArea), or OBJECT_INVALID if no more
--  areas are loaded.
function GetNextArea()
    VM_ExecuteCommand(862, 0)
    return StackPopObject()
end

--  Sets the transition target for oTransition.
-- 
--  Notes:
--  - oTransition can be any valid game object, except areas.
--  - oTarget can be any valid game object with a location, or OBJECT_INVALID (to unlink).
--  - Rebinding a transition will NOT change the other end of the transition for example,
--    with normal doors you will have to do either end separately.
--  - Any valid game object can hold a transition target, but only some are used by the game engine
--    (doors and triggers). This might change in the future. You can still set and query them for
--    other game objects from nwscript.
--  - Transition target objects are cached: The toolset-configured destination tag is
--    used for a lookup only once, at first use. Thus, attempting to use SetTag() to change the
--    destination for a transition will not work in a predictable fashion.
function SetTransitionTarget(oTransition, oTarget)
    StackPushObject(oTarget)
    StackPushObject(oTransition)
    VM_ExecuteCommand(863, 2)
end

--  Sets whether the provided item should be hidden when equipped.
--  - The intended usage of this function is to provide an easy way to hide helmets, but it
--    can be used equally for any slot which has creature mesh visibility when equipped,
--    e.g.: armour, helm, cloak, left hand, and right hand.
--  - nValue should be TRUE or FALSE.
function SetHiddenWhenEquipped(oItem, bValue)
    StackPushBoolean(bValue)
    StackPushObject(oItem)
    VM_ExecuteCommand(864, 2)
end

--  Returns whether the provided item is hidden when equipped.
function GetHiddenWhenEquipped(oItem)
    StackPushObject(oItem)
    VM_ExecuteCommand(865, 1)
    return StackPopBoolean()
end

--  Sets if the given creature has explored tile at x, y of the given area.
--  Note that creature needs to be a player- or player-possessed creature.
-- 
--  Keep in mind that tile exploration also controls object visibility in areas
--  and the fog of war for interior and underground areas.
-- 
--  Return values:
--   -1: Area or creature invalid.
--    0: Tile was not explored before setting newState.
--    1: Tile was explored before setting newState.
function SetTileExplored(creature, area, x, y, bnewState)
    StackPushBoolean(bnewState)
    StackPushInteger(y)
    StackPushInteger(x)
    StackPushObject(area)
    StackPushObject(creature)
    VM_ExecuteCommand(866, 5)
    return StackPopInteger()
end

--  Returns whether the given tile at x, y, for the given creature in the stated
--  area is visible on the map.
--  Note that creature needs to be a player- or player-possessed creature.
-- 
--  Keep in mind that tile exploration also controls object visibility in areas
--  and the fog of war for interior and underground areas.
-- 
--  Return values:
--   -1: Area or creature invalid.
--    0: Tile is not explored yet.
--    1: Tile is explored.
function GetTileExplored(creature, area, x, y)
    StackPushInteger(y)
    StackPushInteger(x)
    StackPushObject(area)
    StackPushObject(creature)
    VM_ExecuteCommand(867, 4)
    return StackPopInteger()
end

--  Sets the creature to auto-explore the map as it walks around.
-- 
--  Keep in mind that tile exploration also controls object visibility in areas
--  and the fog of war for interior and underground areas.
-- 
--  This means that if you turn off auto exploration, it falls to you to manage this
--  through SetTileExplored() otherwise, the player will not be able to see anything.
-- 
--  Valid arguments: TRUE and FALSE.
--  Does nothing for non-creatures.
--  Returns the previous state (or -1 if non-creature).
function SetCreatureExploresMinimap(creature, bnewState)
    StackPushBoolean(bnewState)
    StackPushObject(creature)
    VM_ExecuteCommand(868, 2)
    return StackPopInteger()
end

--  Returns TRUE if the creature is set to auto-explore the map as it walks around (on by default).
--  Returns FALSE if creature is not actually a creature.
function GetCreatureExploresMinimap(creature)
    StackPushObject(creature)
    VM_ExecuteCommand(869, 1)
    return StackPopBoolean()
end

--  Get the surface material at the given location. (This is
--  equivalent to the walkmesh type).
--  Returns 0 if the location is invalid or has no surface type.
function GetSurfaceMaterial(at)
    StackPushLocation(at)
    VM_ExecuteCommand(870, 1)
    return StackPopInteger()
end

--  Returns the z-offset at which the walkmesh is at the given location.
--  Returns -6.0 for invalid locations.
function GetGroundHeight(at)
    StackPushLocation(at)
    VM_ExecuteCommand(871, 1)
    return StackPopFloat()
end

--  Gets the attack bonus limit.
--  - The default value is 20.
function GetAttackBonusLimit()
    VM_ExecuteCommand(872, 0)
    return StackPopInteger()
end

--  Gets the damage bonus limit.
--  - The default value is 100.
function GetDamageBonusLimit()
    VM_ExecuteCommand(873, 0)
    return StackPopInteger()
end

--  Gets the saving throw bonus limit.
--  - The default value is 20.
function GetSavingThrowBonusLimit()
    VM_ExecuteCommand(874, 0)
    return StackPopInteger()
end

--  Gets the ability bonus limit.
--  - The default value is 12.
function GetAbilityBonusLimit()
    VM_ExecuteCommand(875, 0)
    return StackPopInteger()
end

--  Gets the ability penalty limit.
--  - The default value is 30.
function GetAbilityPenaltyLimit()
    VM_ExecuteCommand(876, 0)
    return StackPopInteger()
end

--  Gets the skill bonus limit.
--  - The default value is 50.
function GetSkillBonusLimit()
    VM_ExecuteCommand(877, 0)
    return StackPopInteger()
end

--  Sets the attack bonus limit.
--  - The minimum value is 0.
function SetAttackBonusLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(878, 1)
end

--  Sets the damage bonus limit.
--  - The minimum value is 0.
function SetDamageBonusLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(879, 1)
end

--  Sets the saving throw bonus limit.
--  - The minimum value is 0.
function SetSavingThrowBonusLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(880, 1)
end

--  Sets the ability bonus limit.
--  - The minimum value is 0.
function SetAbilityBonusLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(881, 1)
end

--  Sets the ability penalty limit.
--  - The minimum value is 0.
function SetAbilityPenaltyLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(882, 1)
end

--  Sets the skill bonus limit.
--  - The minimum value is 0.
function SetSkillBonusLimit(nNewLimit)
    StackPushInteger(nNewLimit)
    VM_ExecuteCommand(883, 1)
end

--  Get if oPlayer is currently connected over a relay (instead of directly).
--  Returns FALSE for any other object, including OBJECT_INVALID.
function GetIsPlayerConnectionRelayed(oPlayer)
    StackPushObject(oPlayer)
    VM_ExecuteCommand(884, 1)
    return StackPopBoolean()
end

--  Returns the event script for the given object and handler.
--  Will return "" if unset, the object is invalid, or the object cannot
--  have the requested handler.
function GetEventScript(oObject, nHandler)
    StackPushInteger(nHandler)
    StackPushObject(oObject)
    VM_ExecuteCommand(885, 2)
    return StackPopString()
end

--  Sets the given event script for the given object and handler.
--  Returns 1 on success, 0 on failure.
--  Will fail if oObject is invalid or does not have the requested handler.
function SetEventScript(oObject, nHandler, sScript)
    StackPushString(sScript)
    StackPushInteger(nHandler)
    StackPushObject(oObject)
    VM_ExecuteCommand(886, 3)
    return StackPopBoolean()
end

-- reworked functions
--  Delay aActionToDelay by fSeconds.
--  * No return value, but if an error occurs, the log file will contain
--    "DelayCommand failed.".
--  It is suggested that functions which create effects should not be used
--  as parameters to delayed actions.  Instead, the effect should be created in the
--  script and then passed into the action.  For example:
--  effect eDamage = EffectDamage(nDamage, DAMAGE_TYPE_MAGICAL)
--  DelayCommand(fDelay, ApplyEffectToObject(DURATION_TYPE_INSTANT, eDamage, oTarget)
function DelayCommand(obj, t, action, ...)
  local scmd = AddToken(action, ...)
  delaycommand(obj, scmd, t)
end

--  Assign aActionToAssign to oActionSubject.
--  * No return value, but if an error occurs, the log file will contain
--    "AssignCommand failed."
--    (If the object doesn't exist, nothing happens.)
function AssignCommand(obj, action, ...)
  local scmd = AddToken(action, ...)
  delaycommand(obj, scmd)
end

function ActionDoCommand(action, ...)
  local scmd = AddToken(action, ...)
  actiondocommand(OBJECT_SELF, scmd)
end
