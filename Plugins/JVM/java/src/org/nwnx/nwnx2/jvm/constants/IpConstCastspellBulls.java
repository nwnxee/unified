package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_BULLS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellBulls {
  private IpConstCastspellBulls() {}

  public final static int STRENGTH_10 = 16;
  public final static int STRENGTH_15 = 17;
  public final static int STRENGTH_3 = 15;

  public static String nameOf(int value) {
    if (value == 16) return "IpConstCastspellBulls.STRENGTH_10";
    if (value == 17) return "IpConstCastspellBulls.STRENGTH_15";
    if (value == 15) return "IpConstCastspellBulls.STRENGTH_3";
    return "IpConstCastspellBulls.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellBulls.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellBulls.(not found: " + value + ")";
  }
}
