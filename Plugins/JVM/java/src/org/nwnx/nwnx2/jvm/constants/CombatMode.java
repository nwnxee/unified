package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "COMBAT_MODE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CombatMode {
  private CombatMode() {}

  public final static int DEFENSIVE_CASTING = 8;
  public final static int DEFENSIVE_STANCE = 10;
  public final static int DIRTY_FIGHTING = 9;
  public final static int EXPERTISE = 6;
  public final static int FLURRY_OF_BLOWS = 4;
  public final static int IMPROVED_EXPERTISE = 7;
  public final static int IMPROVED_POWER_ATTACK = 3;
  public final static int INVALID = 0;
  public final static int PARRY = 1;
  public final static int POWER_ATTACK = 2;
  public final static int RAPID_SHOT = 5;

  public static String nameOf(int value) {
    if (value == 8) return "CombatMode.DEFENSIVE_CASTING";
    if (value == 10) return "CombatMode.DEFENSIVE_STANCE";
    if (value == 9) return "CombatMode.DIRTY_FIGHTING";
    if (value == 6) return "CombatMode.EXPERTISE";
    if (value == 4) return "CombatMode.FLURRY_OF_BLOWS";
    if (value == 7) return "CombatMode.IMPROVED_EXPERTISE";
    if (value == 3) return "CombatMode.IMPROVED_POWER_ATTACK";
    if (value == 0) return "CombatMode.INVALID";
    if (value == 1) return "CombatMode.PARRY";
    if (value == 2) return "CombatMode.POWER_ATTACK";
    if (value == 5) return "CombatMode.RAPID_SHOT";
    return "CombatMode.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CombatMode.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CombatMode.(not found: " + value + ")";
  }
}
