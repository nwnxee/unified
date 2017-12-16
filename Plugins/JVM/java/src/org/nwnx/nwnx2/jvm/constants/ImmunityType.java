package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IMMUNITY_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ImmunityType {
  private ImmunityType() {}

  public final static int ABILITY_DECREASE = 19;
  public final static int AC_DECREASE = 23;
  public final static int ATTACK_DECREASE = 20;
  public final static int BLINDNESS = 7;
  public final static int CHARM = 14;
  public final static int CONFUSED = 16;
  public final static int CRITICAL_HIT = 31;
  public final static int CURSED = 17;
  public final static int DAMAGE_DECREASE = 21;
  public final static int DAMAGE_IMMUNITY_DECREASE = 22;
  public final static int DAZED = 18;
  public final static int DEAFNESS = 8;
  public final static int DEATH = 32;
  public final static int DISEASE = 3;
  public final static int DOMINATE = 15;
  public final static int ENTANGLE = 10;
  public final static int FEAR = 4;
  public final static int KNOCKDOWN = 28;
  public final static int MIND_SPELLS = 1;
  public final static int MOVEMENT_SPEED_DECREASE = 24;
  public final static int NEGATIVE_LEVEL = 29;
  public final static int NONE = 0;
  public final static int PARALYSIS = 6;
  public final static int POISON = 2;
  public final static int SAVING_THROW_DECREASE = 25;
  public final static int SILENCE = 11;
  public final static int SKILL_DECREASE = 27;
  public final static int SLEEP = 13;
  public final static int SLOW = 9;
  public final static int SNEAK_ATTACK = 30;
  public final static int SPELL_RESISTANCE_DECREASE = 26;
  public final static int STUN = 12;
  public final static int TRAP = 5;

  public static String nameOf(int value) {
    if (value == 19) return "ImmunityType.ABILITY_DECREASE";
    if (value == 23) return "ImmunityType.AC_DECREASE";
    if (value == 20) return "ImmunityType.ATTACK_DECREASE";
    if (value == 7) return "ImmunityType.BLINDNESS";
    if (value == 14) return "ImmunityType.CHARM";
    if (value == 16) return "ImmunityType.CONFUSED";
    if (value == 31) return "ImmunityType.CRITICAL_HIT";
    if (value == 17) return "ImmunityType.CURSED";
    if (value == 21) return "ImmunityType.DAMAGE_DECREASE";
    if (value == 22) return "ImmunityType.DAMAGE_IMMUNITY_DECREASE";
    if (value == 18) return "ImmunityType.DAZED";
    if (value == 8) return "ImmunityType.DEAFNESS";
    if (value == 32) return "ImmunityType.DEATH";
    if (value == 3) return "ImmunityType.DISEASE";
    if (value == 15) return "ImmunityType.DOMINATE";
    if (value == 10) return "ImmunityType.ENTANGLE";
    if (value == 4) return "ImmunityType.FEAR";
    if (value == 28) return "ImmunityType.KNOCKDOWN";
    if (value == 1) return "ImmunityType.MIND_SPELLS";
    if (value == 24) return "ImmunityType.MOVEMENT_SPEED_DECREASE";
    if (value == 29) return "ImmunityType.NEGATIVE_LEVEL";
    if (value == 0) return "ImmunityType.NONE";
    if (value == 6) return "ImmunityType.PARALYSIS";
    if (value == 2) return "ImmunityType.POISON";
    if (value == 25) return "ImmunityType.SAVING_THROW_DECREASE";
    if (value == 11) return "ImmunityType.SILENCE";
    if (value == 27) return "ImmunityType.SKILL_DECREASE";
    if (value == 13) return "ImmunityType.SLEEP";
    if (value == 9) return "ImmunityType.SLOW";
    if (value == 30) return "ImmunityType.SNEAK_ATTACK";
    if (value == 26) return "ImmunityType.SPELL_RESISTANCE_DECREASE";
    if (value == 12) return "ImmunityType.STUN";
    if (value == 5) return "ImmunityType.TRAP";
    return "ImmunityType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ImmunityType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ImmunityType.(not found: " + value + ")";
  }
}
