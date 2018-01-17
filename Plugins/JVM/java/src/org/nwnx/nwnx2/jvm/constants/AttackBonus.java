package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ATTACK_BONUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AttackBonus {
  private AttackBonus() {}

  public final static int MISC = 0;
  public final static int OFFHAND = 2;
  public final static int ONHAND = 1;

  public static String nameOf(int value) {
    if (value == 0) return "AttackBonus.MISC";
    if (value == 2) return "AttackBonus.OFFHAND";
    if (value == 1) return "AttackBonus.ONHAND";
    return "AttackBonus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AttackBonus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AttackBonus.(not found: " + value + ")";
  }
}
