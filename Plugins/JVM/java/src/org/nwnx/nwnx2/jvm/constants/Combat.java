package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "COMBAT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Combat {
  private Combat() {}

  public final static int MODE_DEFENSIVE_CASTING = 8;
  public final static int MODE_DEFENSIVE_STANCE = 10;
  public final static int MODE_DIRTY_FIGHTING = 9;
  public final static int MODE_EXPERTISE = 6;
  public final static int MODE_FLURRY_OF_BLOWS = 4;
  public final static int MODE_IMPROVED_EXPERTISE = 7;
  public final static int MODE_IMPROVED_POWER_ATTACK = 3;
  public final static int MODE_INVALID = 0;
  public final static int MODE_PARRY = 1;
  public final static int MODE_POWER_ATTACK = 2;
  public final static int MODE_RAPID_SHOT = 5;

  public static String nameOf(int value) {
    if (value == 8) return "Combat.MODE_DEFENSIVE_CASTING";
    if (value == 10) return "Combat.MODE_DEFENSIVE_STANCE";
    if (value == 9) return "Combat.MODE_DIRTY_FIGHTING";
    if (value == 6) return "Combat.MODE_EXPERTISE";
    if (value == 4) return "Combat.MODE_FLURRY_OF_BLOWS";
    if (value == 7) return "Combat.MODE_IMPROVED_EXPERTISE";
    if (value == 3) return "Combat.MODE_IMPROVED_POWER_ATTACK";
    if (value == 0) return "Combat.MODE_INVALID";
    if (value == 1) return "Combat.MODE_PARRY";
    if (value == 2) return "Combat.MODE_POWER_ATTACK";
    if (value == 5) return "Combat.MODE_RAPID_SHOT";
    return "Combat.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Combat.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Combat.(not found: " + value + ")";
  }
}
