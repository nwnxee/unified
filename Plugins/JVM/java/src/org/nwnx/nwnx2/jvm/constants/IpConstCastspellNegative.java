package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_NEGATIVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellNegative {
  private IpConstCastspellNegative() {}

  public final static int ENERGY_BURST_10 = 315;
  public final static int ENERGY_BURST_5 = 314;
  public final static int ENERGY_PROTECTION_10 = 202;
  public final static int ENERGY_PROTECTION_15 = 203;
  public final static int ENERGY_PROTECTION_5 = 201;
  public final static int ENERGY_RAY_1 = 316;
  public final static int ENERGY_RAY_3 = 317;
  public final static int ENERGY_RAY_5 = 318;
  public final static int ENERGY_RAY_7 = 319;
  public final static int ENERGY_RAY_9 = 320;

  public static String nameOf(int value) {
    if (value == 315) return "IpConstCastspellNegative.ENERGY_BURST_10";
    if (value == 314) return "IpConstCastspellNegative.ENERGY_BURST_5";
    if (value == 202) return "IpConstCastspellNegative.ENERGY_PROTECTION_10";
    if (value == 203) return "IpConstCastspellNegative.ENERGY_PROTECTION_15";
    if (value == 201) return "IpConstCastspellNegative.ENERGY_PROTECTION_5";
    if (value == 316) return "IpConstCastspellNegative.ENERGY_RAY_1";
    if (value == 317) return "IpConstCastspellNegative.ENERGY_RAY_3";
    if (value == 318) return "IpConstCastspellNegative.ENERGY_RAY_5";
    if (value == 319) return "IpConstCastspellNegative.ENERGY_RAY_7";
    if (value == 320) return "IpConstCastspellNegative.ENERGY_RAY_9";
    return "IpConstCastspellNegative.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellNegative.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellNegative.(not found: " + value + ")";
  }
}
