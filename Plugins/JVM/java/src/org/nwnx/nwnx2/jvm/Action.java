// Generated on 2017-12-16 13:11:04 +0100 from

package org.nwnx.nwnx2.jvm;

import java.lang.Runnable;

/**
 * This singleton-class provides convenient wrappers around all
 * NWScript action-type method calls that modify the action queue.
 */
public final class Action {
    private Action() {}

    /**
     * Clears all actions for the given object.
     */
    public final static void clear(NWObject objectSelf, final boolean combatToo) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.clearAllActions(combatToo);
            }
        });
    }

    /**
     * The action subject will generate a random location near its current location
     * and pathfind to it.  ActionRandomwalk never ends, which means it is neccessary
     * to call ClearAllActions in order to allow a creature to perform any other action
     * once ActionRandomWalk has been called.
     * * No return value, but if an error occurs the log file will contain
     * "ActionRandomWalk failed."
     */
    public final static void randomWalk(NWObject objectSelf) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionRandomWalk();
            }
        });
    }

    /**
     * The action subject will move to lDestination.
     * @param lDestination The object will move to this location.  If the location is
     * invalid or a path cannot be found to it, the command does nothing.
     * @param bRun If this is TRUE, the action subject will run rather than walk
     * * No return value, but if an error occurs the log file will contain
     * "MoveToPoint failed."
     */
    public final static void moveToLocation(NWObject objectSelf, final NWLocation lDestination, final boolean bRun) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionMoveToLocation(lDestination, bRun);
            }
        });
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
    public final static void moveToObject(NWObject objectSelf, final NWObject oMoveTo, final boolean bRun, final float fRange) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionMoveToObject(oMoveTo, bRun, fRange);
            }
        });
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
    public final static void moveAwayFromObject(NWObject objectSelf, final NWObject oFleeFrom, final boolean bRun, final float fMoveAwayRange) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionMoveAwayFromObject(oFleeFrom, bRun, fMoveAwayRange);
            }
        });
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
    public final static void equipItem(NWObject objectSelf, final NWObject oItem, final int nInventorySlot) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionEquipItem(oItem, nInventorySlot);
            }
        });
    }

    /**
     * Unequip oItem from whatever slot it is currently in.
     */
    public final static void unequipItem(NWObject objectSelf, final NWObject oItem) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionUnequipItem(oItem);
            }
        });
    }

    /**
     * Pick up oItem from the ground.
     * * No return value, but if an error occurs the log file will contain
     * "ActionPickUpItem failed."
     */
    public final static void pickUpItem(NWObject objectSelf, final NWObject oItem) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionPickUpItem(oItem);
            }
        });
    }

    /**
     * Put down oItem on the ground.
     * * No return value, but if an error occurs the log file will contain
     * "ActionPutDownItem failed."
     */
    public final static void putDownItem(NWObject objectSelf, final NWObject oItem) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionPutDownItem(oItem);
            }
        });
    }

    /**
     * Attack oAttackee.
     * @param bPassive If this is TRUE, attack is in passive mode.
     */
    public final static void attack(NWObject objectSelf, final NWObject oAttackee, final boolean bPassive) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionAttack(oAttackee, bPassive);
            }
        });
    }

    /**
     * Add a speak action to the action subject.
     * @param sStringToSpeak String to be spoken
     * @param nTalkVolume TALKVOLUME_*
     */
    public final static void speakString(NWObject objectSelf, final String sStringToSpeak, final int nTalkVolume) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionSpeakString(sStringToSpeak, nTalkVolume);
            }
        });
    }

    /**
     * Cause the action subject to play an animation
     * @param nAnimation ANIMATION_*
     * @param fSpeed Speed of the animation
     * @param fDurationSeconds Duration of the animation (this is not used for Fire and
     * Forget animations)
     */
    public final static void playAnimation(NWObject objectSelf, final int nAnimation, final float fSpeed, final float fDurationSeconds) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionPlayAnimation(nAnimation, fSpeed, fDurationSeconds);
            }
        });
    }

    /**
     * Cause the action subject to open oDoor
     */
    public final static void openDoor(NWObject objectSelf, final NWObject oDoor) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionOpenDoor(oDoor);
            }
        });
    }

    /**
     * Cause the action subject to close oDoor
     */
    public final static void closeDoor(NWObject objectSelf, final NWObject oDoor) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCloseDoor(oDoor);
            }
        });
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
    public final static void castSpellAtObject(NWObject objectSelf, final int nSpell, final NWObject oTarget, final int nMetaMagic, final boolean bCheat, final int nDomainLevel, final int nProjectilePathType, final boolean bInstantSpell) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCastSpellAtObject(nSpell, oTarget, nMetaMagic, bCheat, nDomainLevel, nProjectilePathType, bInstantSpell);
            }
        });
    }

    /**
     * Give oItem to oGiveTo
     * If oItem is not a valid item, or oGiveTo is not a valid object, nothing will
     * happen.
     */
    public final static void giveItem(NWObject objectSelf, final NWObject oItem, final NWObject oGiveTo) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionGiveItem(oItem, oGiveTo);
            }
        });
    }

    /**
     * Take oItem from oTakeFrom
     * If oItem is not a valid item, or oTakeFrom is not a valid object, nothing
     * will happen.
     */
    public final static void takeItem(NWObject objectSelf, final NWObject oItem, final NWObject oTakeFrom) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionTakeItem(oItem, oTakeFrom);
            }
        });
    }

    /**
     * The action subject will follow oFollow until a ClearAllActions() is called.
     * @param oFollow this is the object to be followed
     * @param fFollowDistance follow distance in metres
     * * No return value
     */
    public final static void forceFollowObject(NWObject objectSelf, final NWObject oFollow, final float fFollowDistance) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionForceFollowObject(oFollow, fFollowDistance);
            }
        });
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
    public final static void sit(NWObject objectSelf, final NWObject oChair) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionSit(oChair);
            }
        });
    }

    /**
     * Jump to an object ID, or as near to it as possible.
     */
    public final static void jumpToObject(NWObject objectSelf, final NWObject oToJumpTo, final boolean bWalkStraightLineToPoint) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionJumpToObject(oToJumpTo, bWalkStraightLineToPoint);
            }
        });
    }

    /**
     * Do nothing for fSeconds seconds.
     */
    public final static void wait(NWObject objectSelf, final float fSeconds) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionWait(fSeconds);
            }
        });
    }

    /**
     * Starts a conversation with oObjectToConverseWith @param this will cause their
     * OnDialog event to fire.
     * @param oObjectToConverseWith
     * @param sDialogResRef If this is blank, the creature's own dialogue file will be used
     * @param bPrivateConversation
     * Turn off bPlayHello if you don't want the initial greeting to play
     */
    public final static void startConversation(NWObject objectSelf, final NWObject oObjectToConverseWith, final String sDialogResRef, final boolean bPrivateConversation, final boolean bPlayHello) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionStartConversation(oObjectToConverseWith, sDialogResRef, bPrivateConversation, bPlayHello);
            }
        });
    }

    /**
     * Pause the current conversation.
     */
    public final static void pauseConversation(NWObject objectSelf) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionPauseConversation();
            }
        });
    }

    /**
     * Resume a conversation after it has been paused.
     */
    public final static void resumeConversation(NWObject objectSelf) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionResumeConversation();
            }
        });
    }

    /**
     * The subject will jump to lLocation instantly (even between areas).
     * If lLocation is invalid, nothing will happen.
     */
    public final static void jumpToLocation(NWObject objectSelf, final NWLocation lLocation) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionJumpToLocation(lLocation);
            }
        });
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
    public final static void castSpellAtLocation(NWObject objectSelf, final int nSpell, final NWLocation lTargetLocation, final int nMetaMagic, final boolean bCheat, final int nProjectilePathType, final boolean bInstantSpell) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCastSpellAtLocation(nSpell, lTargetLocation, nMetaMagic, bCheat, nProjectilePathType, bInstantSpell);
            }
        });
    }

    /**
     * Causes the creature to speak a translated string.
     * @param nStrRef Reference of the string in the talk table
     * @param nTalkVolume TALKVOLUME_*
     */
    public final static void speakStringByStrRef(NWObject objectSelf, final int nStrRef, final int nTalkVolume) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionSpeakStringByStrRef(nStrRef, nTalkVolume);
            }
        });
    }

    /**
     * Use nFeat on oTarget.
     * @param nFeat FEAT_*
     * @param oTarget
     */
    public final static void useFeat(NWObject objectSelf, final int nFeat, final NWObject oTarget) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionUseFeat(nFeat, oTarget);
            }
        });
    }

    /**
     * Runs the action "UseSkill" on the current creature
     * Use nSkill on oTarget.
     * @param nSkill SKILL_*
     * @param oTarget
     * @param nSubSkill SUBSKILL_*
     * @param oItemUsed Item to use in conjunction with the skill
     */
    public final static void useSkill(NWObject objectSelf, final int nSkill, final NWObject oTarget, final int nSubSkill, final NWObject oItemUsed) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionUseSkill(nSkill, oTarget, nSubSkill, oItemUsed);
            }
        });
    }

    /**
     * Use oPlaceable.
     */
    public final static void interactObject(NWObject objectSelf, final NWObject oPlaceable) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionInteractObject(oPlaceable);
            }
        });
    }

    /**
     * Causes the action subject to move away from lMoveAwayFrom.
     */
    public final static void moveAwayFromLocation(NWObject objectSelf, final NWLocation lMoveAwayFrom, final boolean bRun, final float fMoveAwayRange) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionMoveAwayFromLocation(lMoveAwayFrom, bRun, fMoveAwayRange);
            }
        });
    }

    /**
     * Force the action subject to move to lDestination.
     */
    public final static void forceMoveToLocation(NWObject objectSelf, final NWLocation lDestination, final boolean bRun, final float fTimeout) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionForceMoveToLocation(lDestination, bRun, fTimeout);
            }
        });
    }

    /**
     * Force the action subject to move to oMoveTo.
     */
    public final static void forceMoveToObject(NWObject objectSelf, final NWObject oMoveTo, final boolean bRun, final float fRange, final float fTimeout) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionForceMoveToObject(oMoveTo, bRun, fRange, fTimeout);
            }
        });
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
    public final static void equipMostDamagingMelee(NWObject objectSelf, final NWObject oVersus, final boolean bOffHand) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionEquipMostDamagingMelee(oVersus, bOffHand);
            }
        });
    }

    /**
     * The creature will equip the range weapon in its possession that can do the
     * most damage.
     * If no valid range weapon can be found, it will equip the most damaging melee
     * weapon.
     * @param oVersus You can try to get the most damaging weapon against oVersus
     */
    public final static void equipMostDamagingRanged(NWObject objectSelf, final NWObject oVersus) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionEquipMostDamagingRanged(oVersus);
            }
        });
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
    public final static void rest(NWObject objectSelf, final boolean bCreatureToEnemyLineOfSightCheck) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionRest(bCreatureToEnemyLineOfSightCheck);
            }
        });
    }

    /**
     * The creature will equip the armour in its possession that has the highest
     * armour class.
     */
    public final static void equipMostEffectiveArmor(NWObject objectSelf) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionEquipMostEffectiveArmor();
            }
        });
    }

    /**
     * The action subject will unlock oTarget, which can be a door or a placeable
     * object.
     */
    public final static void unlockObject(NWObject objectSelf, final NWObject oTarget) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionUnlockObject(oTarget);
            }
        });
    }

    /**
     * The action subject will lock oTarget, which can be a door or a placeable
     * object.
     */
    public final static void lockObject(NWObject objectSelf, final NWObject oTarget) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionLockObject(oTarget);
            }
        });
    }

    /**
     * The action subject will fake casting a spell at oTarget; the conjure and cast
     * animations and visuals will occur, nothing else.
     * @param nSpell
     * @param oTarget
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     */
    public final static void castFakeSpellAtObject(NWObject objectSelf, final int nSpell, final NWObject oTarget, final int nProjectilePathType) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCastFakeSpellAtObject(nSpell, oTarget, nProjectilePathType);
            }
        });
    }

    /**
     * The action subject will fake casting a spell at lLocation; the conjure and
     * cast animations and visuals will occur, nothing else.
     * @param nSpell
     * @param lTarget
     * @param nProjectilePathType PROJECTILE_PATH_TYPE_*
     */
    public final static void castFakeSpellAtLocation(NWObject objectSelf, final int nSpell, final NWLocation lTarget, final int nProjectilePathType) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCastFakeSpellAtLocation(nSpell, lTarget, nProjectilePathType);
            }
        });
    }

    /**
     * Counterspell oCounterSpellTarget.
     */
    public final static void counterSpell(NWObject objectSelf, final NWObject oCounterSpellTarget) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionCounterSpell(oCounterSpellTarget);
            }
        });
    }

    /**
     * Makes a player examine the object oExamine. This causes the examination
     * pop-up box to appear for the object specified.
     */
    public final static void examine(NWObject objectSelf, final NWObject oExamine) {
        Scheduler.assign(objectSelf, new Runnable() {
            @Override public void run() {
                NWScript.actionExamine(oExamine);
            }
        });
    }
}
