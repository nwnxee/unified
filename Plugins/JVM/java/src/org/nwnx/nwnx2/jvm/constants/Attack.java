package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ATTACK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Attack {
  private Attack() {}

  public final static int BONUS_MISC = 0;
  public final static int BONUS_OFFHAND = 2;
  public final static int BONUS_ONHAND = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Attack.BONUS_MISC";
    if (value == 2) return "Attack.BONUS_OFFHAND";
    if (value == 1) return "Attack.BONUS_ONHAND";
    return "Attack.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Attack.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Attack.(not found: " + value + ")";
  }
}
