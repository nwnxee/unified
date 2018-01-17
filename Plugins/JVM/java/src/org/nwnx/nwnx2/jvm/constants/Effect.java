package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EFFECT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Effect {
  private Effect() {}

  public final static int TYPE_ABILITY_DECREASE = 39;
  public final static int TYPE_ABILITY_INCREASE = 38;
  public final static int TYPE_AC_DECREASE = 47;
  public final static int TYPE_AC_INCREASE = 46;
  public final static int TYPE_ARCANE_SPELL_FAILURE = 18;
  public final static int TYPE_AREA_OF_EFFECT = 20;
  public final static int TYPE_ATTACK_DECREASE = 41;
  public final static int TYPE_ATTACK_INCREASE = 40;
  public final static int TYPE_BEAM = 21;
  public final static int TYPE_BLINDNESS = 67;
  public final static int TYPE_CHARMED = 23;
  public final static int TYPE_CONCEALMENT = 72;
  public final static int TYPE_CONFUSED = 24;
  public final static int TYPE_CURSE = 33;
  public final static int TYPE_CUTSCENEGHOST = 83;
  public final static int TYPE_CUTSCENEIMMOBILIZE = 84;
  public final static int TYPE_CUTSCENE_PARALYZE = 80;
  public final static int TYPE_DAMAGE_DECREASE = 43;
  public final static int TYPE_DAMAGE_IMMUNITY_DECREASE = 45;
  public final static int TYPE_DAMAGE_IMMUNITY_INCREASE = 44;
  public final static int TYPE_DAMAGE_INCREASE = 42;
  public final static int TYPE_DAMAGE_REDUCTION = 7;
  public final static int TYPE_DAMAGE_RESISTANCE = 1;
  public final static int TYPE_DARKNESS = 58;
  public final static int TYPE_DAZED = 28;
  public final static int TYPE_DEAF = 13;
  public final static int TYPE_DISAPPEARAPPEAR = 75;
  public final static int TYPE_DISEASE = 32;
  public final static int TYPE_DISPELMAGICALL = 59;
  public final static int TYPE_DISPELMAGICBEST = 69;
  public final static int TYPE_DOMINATED = 26;
  public final static int TYPE_ELEMENTALSHIELD = 60;
  public final static int TYPE_ENEMY_ATTACK_BONUS = 17;
  public final static int TYPE_ENTANGLE = 11;
  public final static int TYPE_ETHEREAL = 81;
  public final static int TYPE_FRIGHTENED = 25;
  public final static int TYPE_HASTE = 36;
  public final static int TYPE_IMMUNITY = 15;
  public final static int TYPE_IMPROVEDINVISIBILITY = 57;
  public final static int TYPE_INVALIDEFFECT = 0;
  public final static int TYPE_INVISIBILITY = 56;
  public final static int TYPE_INVULNERABLE = 12;
  public final static int TYPE_MISS_CHANCE = 71;
  public final static int TYPE_MOVEMENT_SPEED_DECREASE = 49;
  public final static int TYPE_MOVEMENT_SPEED_INCREASE = 48;
  public final static int TYPE_NEGATIVELEVEL = 61;
  public final static int TYPE_PARALYZE = 27;
  public final static int TYPE_PETRIFY = 79;
  public final static int TYPE_POISON = 31;
  public final static int TYPE_POLYMORPH = 62;
  public final static int TYPE_REGENERATE = 3;
  public final static int TYPE_RESURRECTION = 14;
  public final static int TYPE_SANCTUARY = 63;
  public final static int TYPE_SAVING_THROW_DECREASE = 51;
  public final static int TYPE_SAVING_THROW_INCREASE = 50;
  public final static int TYPE_SEEINVISIBLE = 65;
  public final static int TYPE_SILENCE = 34;
  public final static int TYPE_SKILL_DECREASE = 55;
  public final static int TYPE_SKILL_INCREASE = 54;
  public final static int TYPE_SLEEP = 30;
  public final static int TYPE_SLOW = 37;
  public final static int TYPE_SPELLLEVELABSORPTION = 68;
  public final static int TYPE_SPELL_FAILURE = 82;
  public final static int TYPE_SPELL_IMMUNITY = 73;
  public final static int TYPE_SPELL_RESISTANCE_DECREASE = 53;
  public final static int TYPE_SPELL_RESISTANCE_INCREASE = 52;
  public final static int TYPE_STUNNED = 29;
  public final static int TYPE_SWARM = 76;
  public final static int TYPE_TEMPORARY_HITPOINTS = 9;
  public final static int TYPE_TIMESTOP = 66;
  public final static int TYPE_TRUESEEING = 64;
  public final static int TYPE_TURNED = 35;
  public final static int TYPE_TURN_RESISTANCE_DECREASE = 77;
  public final static int TYPE_TURN_RESISTANCE_INCREASE = 78;
  public final static int TYPE_ULTRAVISION = 70;
  public final static int TYPE_VISUALEFFECT = 74;

  public static String nameOf(int value) {
    if (value == 39) return "Effect.TYPE_ABILITY_DECREASE";
    if (value == 38) return "Effect.TYPE_ABILITY_INCREASE";
    if (value == 47) return "Effect.TYPE_AC_DECREASE";
    if (value == 46) return "Effect.TYPE_AC_INCREASE";
    if (value == 18) return "Effect.TYPE_ARCANE_SPELL_FAILURE";
    if (value == 20) return "Effect.TYPE_AREA_OF_EFFECT";
    if (value == 41) return "Effect.TYPE_ATTACK_DECREASE";
    if (value == 40) return "Effect.TYPE_ATTACK_INCREASE";
    if (value == 21) return "Effect.TYPE_BEAM";
    if (value == 67) return "Effect.TYPE_BLINDNESS";
    if (value == 23) return "Effect.TYPE_CHARMED";
    if (value == 72) return "Effect.TYPE_CONCEALMENT";
    if (value == 24) return "Effect.TYPE_CONFUSED";
    if (value == 33) return "Effect.TYPE_CURSE";
    if (value == 83) return "Effect.TYPE_CUTSCENEGHOST";
    if (value == 84) return "Effect.TYPE_CUTSCENEIMMOBILIZE";
    if (value == 80) return "Effect.TYPE_CUTSCENE_PARALYZE";
    if (value == 43) return "Effect.TYPE_DAMAGE_DECREASE";
    if (value == 45) return "Effect.TYPE_DAMAGE_IMMUNITY_DECREASE";
    if (value == 44) return "Effect.TYPE_DAMAGE_IMMUNITY_INCREASE";
    if (value == 42) return "Effect.TYPE_DAMAGE_INCREASE";
    if (value == 7) return "Effect.TYPE_DAMAGE_REDUCTION";
    if (value == 1) return "Effect.TYPE_DAMAGE_RESISTANCE";
    if (value == 58) return "Effect.TYPE_DARKNESS";
    if (value == 28) return "Effect.TYPE_DAZED";
    if (value == 13) return "Effect.TYPE_DEAF";
    if (value == 75) return "Effect.TYPE_DISAPPEARAPPEAR";
    if (value == 32) return "Effect.TYPE_DISEASE";
    if (value == 59) return "Effect.TYPE_DISPELMAGICALL";
    if (value == 69) return "Effect.TYPE_DISPELMAGICBEST";
    if (value == 26) return "Effect.TYPE_DOMINATED";
    if (value == 60) return "Effect.TYPE_ELEMENTALSHIELD";
    if (value == 17) return "Effect.TYPE_ENEMY_ATTACK_BONUS";
    if (value == 11) return "Effect.TYPE_ENTANGLE";
    if (value == 81) return "Effect.TYPE_ETHEREAL";
    if (value == 25) return "Effect.TYPE_FRIGHTENED";
    if (value == 36) return "Effect.TYPE_HASTE";
    if (value == 15) return "Effect.TYPE_IMMUNITY";
    if (value == 57) return "Effect.TYPE_IMPROVEDINVISIBILITY";
    if (value == 0) return "Effect.TYPE_INVALIDEFFECT";
    if (value == 56) return "Effect.TYPE_INVISIBILITY";
    if (value == 12) return "Effect.TYPE_INVULNERABLE";
    if (value == 71) return "Effect.TYPE_MISS_CHANCE";
    if (value == 49) return "Effect.TYPE_MOVEMENT_SPEED_DECREASE";
    if (value == 48) return "Effect.TYPE_MOVEMENT_SPEED_INCREASE";
    if (value == 61) return "Effect.TYPE_NEGATIVELEVEL";
    if (value == 27) return "Effect.TYPE_PARALYZE";
    if (value == 79) return "Effect.TYPE_PETRIFY";
    if (value == 31) return "Effect.TYPE_POISON";
    if (value == 62) return "Effect.TYPE_POLYMORPH";
    if (value == 3) return "Effect.TYPE_REGENERATE";
    if (value == 14) return "Effect.TYPE_RESURRECTION";
    if (value == 63) return "Effect.TYPE_SANCTUARY";
    if (value == 51) return "Effect.TYPE_SAVING_THROW_DECREASE";
    if (value == 50) return "Effect.TYPE_SAVING_THROW_INCREASE";
    if (value == 65) return "Effect.TYPE_SEEINVISIBLE";
    if (value == 34) return "Effect.TYPE_SILENCE";
    if (value == 55) return "Effect.TYPE_SKILL_DECREASE";
    if (value == 54) return "Effect.TYPE_SKILL_INCREASE";
    if (value == 30) return "Effect.TYPE_SLEEP";
    if (value == 37) return "Effect.TYPE_SLOW";
    if (value == 68) return "Effect.TYPE_SPELLLEVELABSORPTION";
    if (value == 82) return "Effect.TYPE_SPELL_FAILURE";
    if (value == 73) return "Effect.TYPE_SPELL_IMMUNITY";
    if (value == 53) return "Effect.TYPE_SPELL_RESISTANCE_DECREASE";
    if (value == 52) return "Effect.TYPE_SPELL_RESISTANCE_INCREASE";
    if (value == 29) return "Effect.TYPE_STUNNED";
    if (value == 76) return "Effect.TYPE_SWARM";
    if (value == 9) return "Effect.TYPE_TEMPORARY_HITPOINTS";
    if (value == 66) return "Effect.TYPE_TIMESTOP";
    if (value == 64) return "Effect.TYPE_TRUESEEING";
    if (value == 35) return "Effect.TYPE_TURNED";
    if (value == 77) return "Effect.TYPE_TURN_RESISTANCE_DECREASE";
    if (value == 78) return "Effect.TYPE_TURN_RESISTANCE_INCREASE";
    if (value == 70) return "Effect.TYPE_ULTRAVISION";
    if (value == 74) return "Effect.TYPE_VISUALEFFECT";
    return "Effect.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Effect.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Effect.(not found: " + value + ")";
  }
}
