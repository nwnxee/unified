package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_MASS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellMass {
  private IpConstCastspellMass() {}

  public final static int BLINDNESS_DEAFNESS_15 = 179;
  public final static int CAMOFLAGE_13 = 386;
  public final static int CHARM_15 = 180;
  public final static int HASTE_11 = 182;
  public final static int HEAL_15 = 183;

  public static String nameOf(int value) {
    if (value == 179) return "IpConstCastspellMass.BLINDNESS_DEAFNESS_15";
    if (value == 386) return "IpConstCastspellMass.CAMOFLAGE_13";
    if (value == 180) return "IpConstCastspellMass.CHARM_15";
    if (value == 182) return "IpConstCastspellMass.HASTE_11";
    if (value == 183) return "IpConstCastspellMass.HEAL_15";
    return "IpConstCastspellMass.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellMass.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellMass.(not found: " + value + ")";
  }
}
