package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_ARMOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatArmor {
  private FeatArmor() {}

  public final static int PROFICIENCY_HEAVY = 2;
  public final static int PROFICIENCY_LIGHT = 3;
  public final static int PROFICIENCY_MEDIUM = 4;

  public static String nameOf(int value) {
    if (value == 2) return "FeatArmor.PROFICIENCY_HEAVY";
    if (value == 3) return "FeatArmor.PROFICIENCY_LIGHT";
    if (value == 4) return "FeatArmor.PROFICIENCY_MEDIUM";
    return "FeatArmor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatArmor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatArmor.(not found: " + value + ")";
  }
}
