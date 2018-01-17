package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EFFECT_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EffectType {
  private EffectType() {}

  public final static int ABILITY_DECREASE = 39;
  public final static int ABILITY_INCREASE = 38;
  public final static int AC_DECREASE = 47;
  public final static int AC_INCREASE = 46;
  public final static int ARCANE_SPELL_FAILURE = 18;
  public final static int AREA_OF_EFFECT = 20;
  public final static int ATTACK_DECREASE = 41;
  public final static int ATTACK_INCREASE = 40;
  public final static int BEAM = 21;
  public final static int BLINDNESS = 67;
  public final static int CHARMED = 23;
  public final static int CONCEALMENT = 72;
  public final static int CONFUSED = 24;
  public final static int CURSE = 33;
  public final static int CUTSCENEGHOST = 83;
  public final static int CUTSCENEIMMOBILIZE = 84;
  public final static int CUTSCENE_PARALYZE = 80;
  public final static int DAMAGE_DECREASE = 43;
  public final static int DAMAGE_IMMUNITY_DECREASE = 45;
  public final static int DAMAGE_IMMUNITY_INCREASE = 44;
  public final static int DAMAGE_INCREASE = 42;
  public final static int DAMAGE_REDUCTION = 7;
  public final static int DAMAGE_RESISTANCE = 1;
  public final static int DARKNESS = 58;
  public final static int DAZED = 28;
  public final static int DEAF = 13;
  public final static int DISAPPEARAPPEAR = 75;
  public final static int DISEASE = 32;
  public final static int DISPELMAGICALL = 59;
  public final static int DISPELMAGICBEST = 69;
  public final static int DOMINATED = 26;
  public final static int ELEMENTALSHIELD = 60;
  public final static int ENEMY_ATTACK_BONUS = 17;
  public final static int ENTANGLE = 11;
  public final static int ETHEREAL = 81;
  public final static int FRIGHTENED = 25;
  public final static int HASTE = 36;
  public final static int IMMUNITY = 15;
  public final static int IMPROVEDINVISIBILITY = 57;
  public final static int INVALIDEFFECT = 0;
  public final static int INVISIBILITY = 56;
  public final static int INVULNERABLE = 12;
  public final static int MISS_CHANCE = 71;
  public final static int MOVEMENT_SPEED_DECREASE = 49;
  public final static int MOVEMENT_SPEED_INCREASE = 48;
  public final static int NEGATIVELEVEL = 61;
  public final static int PARALYZE = 27;
  public final static int PETRIFY = 79;
  public final static int POISON = 31;
  public final static int POLYMORPH = 62;
  public final static int REGENERATE = 3;
  public final static int RESURRECTION = 14;
  public final static int SANCTUARY = 63;
  public final static int SAVING_THROW_DECREASE = 51;
  public final static int SAVING_THROW_INCREASE = 50;
  public final static int SEEINVISIBLE = 65;
  public final static int SILENCE = 34;
  public final static int SKILL_DECREASE = 55;
  public final static int SKILL_INCREASE = 54;
  public final static int SLEEP = 30;
  public final static int SLOW = 37;
  public final static int SPELLLEVELABSORPTION = 68;
  public final static int SPELL_FAILURE = 82;
  public final static int SPELL_IMMUNITY = 73;
  public final static int SPELL_RESISTANCE_DECREASE = 53;
  public final static int SPELL_RESISTANCE_INCREASE = 52;
  public final static int STUNNED = 29;
  public final static int SWARM = 76;
  public final static int TEMPORARY_HITPOINTS = 9;
  public final static int TIMESTOP = 66;
  public final static int TRUESEEING = 64;
  public final static int TURNED = 35;
  public final static int TURN_RESISTANCE_DECREASE = 77;
  public final static int TURN_RESISTANCE_INCREASE = 78;
  public final static int ULTRAVISION = 70;
  public final static int VISUALEFFECT = 74;

  public static String nameOf(int value) {
    if (value == 39) return "EffectType.ABILITY_DECREASE";
    if (value == 38) return "EffectType.ABILITY_INCREASE";
    if (value == 47) return "EffectType.AC_DECREASE";
    if (value == 46) return "EffectType.AC_INCREASE";
    if (value == 18) return "EffectType.ARCANE_SPELL_FAILURE";
    if (value == 20) return "EffectType.AREA_OF_EFFECT";
    if (value == 41) return "EffectType.ATTACK_DECREASE";
    if (value == 40) return "EffectType.ATTACK_INCREASE";
    if (value == 21) return "EffectType.BEAM";
    if (value == 67) return "EffectType.BLINDNESS";
    if (value == 23) return "EffectType.CHARMED";
    if (value == 72) return "EffectType.CONCEALMENT";
    if (value == 24) return "EffectType.CONFUSED";
    if (value == 33) return "EffectType.CURSE";
    if (value == 83) return "EffectType.CUTSCENEGHOST";
    if (value == 84) return "EffectType.CUTSCENEIMMOBILIZE";
    if (value == 80) return "EffectType.CUTSCENE_PARALYZE";
    if (value == 43) return "EffectType.DAMAGE_DECREASE";
    if (value == 45) return "EffectType.DAMAGE_IMMUNITY_DECREASE";
    if (value == 44) return "EffectType.DAMAGE_IMMUNITY_INCREASE";
    if (value == 42) return "EffectType.DAMAGE_INCREASE";
    if (value == 7) return "EffectType.DAMAGE_REDUCTION";
    if (value == 1) return "EffectType.DAMAGE_RESISTANCE";
    if (value == 58) return "EffectType.DARKNESS";
    if (value == 28) return "EffectType.DAZED";
    if (value == 13) return "EffectType.DEAF";
    if (value == 75) return "EffectType.DISAPPEARAPPEAR";
    if (value == 32) return "EffectType.DISEASE";
    if (value == 59) return "EffectType.DISPELMAGICALL";
    if (value == 69) return "EffectType.DISPELMAGICBEST";
    if (value == 26) return "EffectType.DOMINATED";
    if (value == 60) return "EffectType.ELEMENTALSHIELD";
    if (value == 17) return "EffectType.ENEMY_ATTACK_BONUS";
    if (value == 11) return "EffectType.ENTANGLE";
    if (value == 81) return "EffectType.ETHEREAL";
    if (value == 25) return "EffectType.FRIGHTENED";
    if (value == 36) return "EffectType.HASTE";
    if (value == 15) return "EffectType.IMMUNITY";
    if (value == 57) return "EffectType.IMPROVEDINVISIBILITY";
    if (value == 0) return "EffectType.INVALIDEFFECT";
    if (value == 56) return "EffectType.INVISIBILITY";
    if (value == 12) return "EffectType.INVULNERABLE";
    if (value == 71) return "EffectType.MISS_CHANCE";
    if (value == 49) return "EffectType.MOVEMENT_SPEED_DECREASE";
    if (value == 48) return "EffectType.MOVEMENT_SPEED_INCREASE";
    if (value == 61) return "EffectType.NEGATIVELEVEL";
    if (value == 27) return "EffectType.PARALYZE";
    if (value == 79) return "EffectType.PETRIFY";
    if (value == 31) return "EffectType.POISON";
    if (value == 62) return "EffectType.POLYMORPH";
    if (value == 3) return "EffectType.REGENERATE";
    if (value == 14) return "EffectType.RESURRECTION";
    if (value == 63) return "EffectType.SANCTUARY";
    if (value == 51) return "EffectType.SAVING_THROW_DECREASE";
    if (value == 50) return "EffectType.SAVING_THROW_INCREASE";
    if (value == 65) return "EffectType.SEEINVISIBLE";
    if (value == 34) return "EffectType.SILENCE";
    if (value == 55) return "EffectType.SKILL_DECREASE";
    if (value == 54) return "EffectType.SKILL_INCREASE";
    if (value == 30) return "EffectType.SLEEP";
    if (value == 37) return "EffectType.SLOW";
    if (value == 68) return "EffectType.SPELLLEVELABSORPTION";
    if (value == 82) return "EffectType.SPELL_FAILURE";
    if (value == 73) return "EffectType.SPELL_IMMUNITY";
    if (value == 53) return "EffectType.SPELL_RESISTANCE_DECREASE";
    if (value == 52) return "EffectType.SPELL_RESISTANCE_INCREASE";
    if (value == 29) return "EffectType.STUNNED";
    if (value == 76) return "EffectType.SWARM";
    if (value == 9) return "EffectType.TEMPORARY_HITPOINTS";
    if (value == 66) return "EffectType.TIMESTOP";
    if (value == 64) return "EffectType.TRUESEEING";
    if (value == 35) return "EffectType.TURNED";
    if (value == 77) return "EffectType.TURN_RESISTANCE_DECREASE";
    if (value == 78) return "EffectType.TURN_RESISTANCE_INCREASE";
    if (value == 70) return "EffectType.ULTRAVISION";
    if (value == 74) return "EffectType.VISUALEFFECT";
    return "EffectType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EffectType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EffectType.(not found: " + value + ")";
  }
}
