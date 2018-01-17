package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_NEGATIVE_ENERGY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellNegativeEnergy {
  private IpConstCastspellNegativeEnergy() {}

  public final static int BURST_10 = 315;
  public final static int BURST_5 = 314;
  public final static int PROTECTION_10 = 202;
  public final static int PROTECTION_15 = 203;
  public final static int PROTECTION_5 = 201;
  public final static int RAY_1 = 316;
  public final static int RAY_3 = 317;
  public final static int RAY_5 = 318;
  public final static int RAY_7 = 319;
  public final static int RAY_9 = 320;

  public static String nameOf(int value) {
    if (value == 315) return "IpConstCastspellNegativeEnergy.BURST_10";
    if (value == 314) return "IpConstCastspellNegativeEnergy.BURST_5";
    if (value == 202) return "IpConstCastspellNegativeEnergy.PROTECTION_10";
    if (value == 203) return "IpConstCastspellNegativeEnergy.PROTECTION_15";
    if (value == 201) return "IpConstCastspellNegativeEnergy.PROTECTION_5";
    if (value == 316) return "IpConstCastspellNegativeEnergy.RAY_1";
    if (value == 317) return "IpConstCastspellNegativeEnergy.RAY_3";
    if (value == 318) return "IpConstCastspellNegativeEnergy.RAY_5";
    if (value == 319) return "IpConstCastspellNegativeEnergy.RAY_7";
    if (value == 320) return "IpConstCastspellNegativeEnergy.RAY_9";
    return "IpConstCastspellNegativeEnergy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellNegativeEnergy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellNegativeEnergy.(not found: " + value + ")";
  }
}
