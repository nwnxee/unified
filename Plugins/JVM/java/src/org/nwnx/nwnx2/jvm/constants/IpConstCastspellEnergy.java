package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_ENERGY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellEnergy {
  private IpConstCastspellEnergy() {}

  public final static int BUFFER_11 = 311;
  public final static int BUFFER_15 = 312;
  public final static int BUFFER_20 = 313;
  public final static int DRAIN_17 = 99;

  public static String nameOf(int value) {
    if (value == 311) return "IpConstCastspellEnergy.BUFFER_11";
    if (value == 312) return "IpConstCastspellEnergy.BUFFER_15";
    if (value == 313) return "IpConstCastspellEnergy.BUFFER_20";
    if (value == 99) return "IpConstCastspellEnergy.DRAIN_17";
    return "IpConstCastspellEnergy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellEnergy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellEnergy.(not found: " + value + ")";
  }
}
