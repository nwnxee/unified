package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_ARMOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatArmor {
  private IpConstFeatArmor() {}

  public final static int PROF_HEAVY = 24;
  public final static int PROF_LIGHT = 25;
  public final static int PROF_MEDIUM = 26;

  public static String nameOf(int value) {
    if (value == 24) return "IpConstFeatArmor.PROF_HEAVY";
    if (value == 25) return "IpConstFeatArmor.PROF_LIGHT";
    if (value == 26) return "IpConstFeatArmor.PROF_MEDIUM";
    return "IpConstFeatArmor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatArmor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatArmor.(not found: " + value + ")";
  }
}
