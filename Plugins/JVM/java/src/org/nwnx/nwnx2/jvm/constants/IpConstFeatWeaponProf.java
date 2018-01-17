package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_WEAPON_PROF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatWeaponProf {
  private IpConstFeatWeaponProf() {}

  public final static int CREATURE = 38;
  public final static int EXOTIC = 21;
  public final static int MARTIAL = 22;
  public final static int SIMPLE = 23;

  public static String nameOf(int value) {
    if (value == 38) return "IpConstFeatWeaponProf.CREATURE";
    if (value == 21) return "IpConstFeatWeaponProf.EXOTIC";
    if (value == 22) return "IpConstFeatWeaponProf.MARTIAL";
    if (value == 23) return "IpConstFeatWeaponProf.SIMPLE";
    return "IpConstFeatWeaponProf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatWeaponProf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatWeaponProf.(not found: " + value + ")";
  }
}
