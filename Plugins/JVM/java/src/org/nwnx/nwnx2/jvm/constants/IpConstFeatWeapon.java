package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_WEAPON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatWeapon {
  private IpConstFeatWeapon() {}

  public final static int PROF_CREATURE = 38;
  public final static int PROF_EXOTIC = 21;
  public final static int PROF_MARTIAL = 22;
  public final static int PROF_SIMPLE = 23;

  public static String nameOf(int value) {
    if (value == 38) return "IpConstFeatWeapon.PROF_CREATURE";
    if (value == 21) return "IpConstFeatWeapon.PROF_EXOTIC";
    if (value == 22) return "IpConstFeatWeapon.PROF_MARTIAL";
    if (value == 23) return "IpConstFeatWeapon.PROF_SIMPLE";
    return "IpConstFeatWeapon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatWeapon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatWeapon.(not found: " + value + ")";
  }
}
