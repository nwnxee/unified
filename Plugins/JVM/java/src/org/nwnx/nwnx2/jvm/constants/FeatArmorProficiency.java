package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_ARMOR_PROFICIENCY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatArmorProficiency {
  private FeatArmorProficiency() {}

  public final static int HEAVY = 2;
  public final static int LIGHT = 3;
  public final static int MEDIUM = 4;

  public static String nameOf(int value) {
    if (value == 2) return "FeatArmorProficiency.HEAVY";
    if (value == 3) return "FeatArmorProficiency.LIGHT";
    if (value == 4) return "FeatArmorProficiency.MEDIUM";
    return "FeatArmorProficiency.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatArmorProficiency.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatArmorProficiency.(not found: " + value + ")";
  }
}
