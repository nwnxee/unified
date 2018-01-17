package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IMMUNITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Immunity {
  private Immunity() {}

  public final static int TYPE_ABILITY_DECREASE = 19;
  public final static int TYPE_AC_DECREASE = 23;
  public final static int TYPE_ATTACK_DECREASE = 20;
  public final static int TYPE_BLINDNESS = 7;
  public final static int TYPE_CHARM = 14;
  public final static int TYPE_CONFUSED = 16;
  public final static int TYPE_CRITICAL_HIT = 31;
  public final static int TYPE_CURSED = 17;
  public final static int TYPE_DAZED = 18;
  public final static int TYPE_DEAFNESS = 8;
  public final static int TYPE_DEATH = 32;
  public final static int TYPE_DISEASE = 3;
  public final static int TYPE_DOMINATE = 15;
  public final static int TYPE_ENTANGLE = 10;
  public final static int TYPE_FEAR = 4;
  public final static int TYPE_KNOCKDOWN = 28;
  public final static int TYPE_MIND_SPELLS = 1;
  public final static int TYPE_MOVEMENT_SPEED_DECREASE = 24;
  public final static int TYPE_NEGATIVE_LEVEL = 29;
  public final static int TYPE_NONE = 0;
  public final static int TYPE_PARALYSIS = 6;
  public final static int TYPE_POISON = 2;
  public final static int TYPE_SAVING_THROW_DECREASE = 25;
  public final static int TYPE_SILENCE = 11;
  public final static int TYPE_SKILL_DECREASE = 27;
  public final static int TYPE_SLEEP = 13;
  public final static int TYPE_SLOW = 9;
  public final static int TYPE_SNEAK_ATTACK = 30;
  public final static int TYPE_SPELL_RESISTANCE_DECREASE = 26;
  public final static int TYPE_STUN = 12;
  public final static int TYPE_TRAP = 5;

  public static String nameOf(int value) {
    if (value == 19) return "Immunity.TYPE_ABILITY_DECREASE";
    if (value == 23) return "Immunity.TYPE_AC_DECREASE";
    if (value == 20) return "Immunity.TYPE_ATTACK_DECREASE";
    if (value == 7) return "Immunity.TYPE_BLINDNESS";
    if (value == 14) return "Immunity.TYPE_CHARM";
    if (value == 16) return "Immunity.TYPE_CONFUSED";
    if (value == 31) return "Immunity.TYPE_CRITICAL_HIT";
    if (value == 17) return "Immunity.TYPE_CURSED";
    if (value == 18) return "Immunity.TYPE_DAZED";
    if (value == 8) return "Immunity.TYPE_DEAFNESS";
    if (value == 32) return "Immunity.TYPE_DEATH";
    if (value == 3) return "Immunity.TYPE_DISEASE";
    if (value == 15) return "Immunity.TYPE_DOMINATE";
    if (value == 10) return "Immunity.TYPE_ENTANGLE";
    if (value == 4) return "Immunity.TYPE_FEAR";
    if (value == 28) return "Immunity.TYPE_KNOCKDOWN";
    if (value == 1) return "Immunity.TYPE_MIND_SPELLS";
    if (value == 24) return "Immunity.TYPE_MOVEMENT_SPEED_DECREASE";
    if (value == 29) return "Immunity.TYPE_NEGATIVE_LEVEL";
    if (value == 0) return "Immunity.TYPE_NONE";
    if (value == 6) return "Immunity.TYPE_PARALYSIS";
    if (value == 2) return "Immunity.TYPE_POISON";
    if (value == 25) return "Immunity.TYPE_SAVING_THROW_DECREASE";
    if (value == 11) return "Immunity.TYPE_SILENCE";
    if (value == 27) return "Immunity.TYPE_SKILL_DECREASE";
    if (value == 13) return "Immunity.TYPE_SLEEP";
    if (value == 9) return "Immunity.TYPE_SLOW";
    if (value == 30) return "Immunity.TYPE_SNEAK_ATTACK";
    if (value == 26) return "Immunity.TYPE_SPELL_RESISTANCE_DECREASE";
    if (value == 12) return "Immunity.TYPE_STUN";
    if (value == 5) return "Immunity.TYPE_TRAP";
    return "Immunity.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Immunity.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Immunity.(not found: " + value + ")";
  }
}
