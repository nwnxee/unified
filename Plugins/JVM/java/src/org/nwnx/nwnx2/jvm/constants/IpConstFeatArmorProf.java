package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_ARMOR_PROF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatArmorProf {
  private IpConstFeatArmorProf() {}

  public final static int HEAVY = 24;
  public final static int LIGHT = 25;
  public final static int MEDIUM = 26;

  public static String nameOf(int value) {
    if (value == 24) return "IpConstFeatArmorProf.HEAVY";
    if (value == 25) return "IpConstFeatArmorProf.LIGHT";
    if (value == 26) return "IpConstFeatArmorProf.MEDIUM";
    return "IpConstFeatArmorProf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatArmorProf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatArmorProf.(not found: " + value + ")";
  }
}
