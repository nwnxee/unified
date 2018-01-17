package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "MISS_CHANCE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class MissChance {
  private MissChance() {}

  public final static int TYPE_NORMAL = 0;
  public final static int TYPE_VS_MELEE = 2;
  public final static int TYPE_VS_RANGED = 1;

  public static String nameOf(int value) {
    if (value == 0) return "MissChance.TYPE_NORMAL";
    if (value == 2) return "MissChance.TYPE_VS_MELEE";
    if (value == 1) return "MissChance.TYPE_VS_RANGED";
    return "MissChance.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "MissChance.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "MissChance.(not found: " + value + ")";
  }
}
