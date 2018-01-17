package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "MISS_CHANCE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class MissChanceType {
  private MissChanceType() {}

  public final static int NORMAL = 0;
  public final static int VS_MELEE = 2;
  public final static int VS_RANGED = 1;

  public static String nameOf(int value) {
    if (value == 0) return "MissChanceType.NORMAL";
    if (value == 2) return "MissChanceType.VS_MELEE";
    if (value == 1) return "MissChanceType.VS_RANGED";
    return "MissChanceType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "MissChanceType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "MissChanceType.(not found: " + value + ")";
  }
}
