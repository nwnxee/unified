package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "MISS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Miss {
  private Miss() {}

  public final static int CHANCE_TYPE_NORMAL = 0;
  public final static int CHANCE_TYPE_VS_MELEE = 2;
  public final static int CHANCE_TYPE_VS_RANGED = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Miss.CHANCE_TYPE_NORMAL";
    if (value == 2) return "Miss.CHANCE_TYPE_VS_MELEE";
    if (value == 1) return "Miss.CHANCE_TYPE_VS_RANGED";
    return "Miss.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Miss.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Miss.(not found: " + value + ")";
  }
}
