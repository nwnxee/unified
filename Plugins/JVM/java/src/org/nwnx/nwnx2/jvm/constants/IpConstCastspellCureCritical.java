package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CURE_CRITICAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCureCritical {
  private IpConstCastspellCureCritical() {}

  public final static int WOUNDS_12 = 64;
  public final static int WOUNDS_15 = 65;
  public final static int WOUNDS_7 = 63;

  public static String nameOf(int value) {
    if (value == 64) return "IpConstCastspellCureCritical.WOUNDS_12";
    if (value == 65) return "IpConstCastspellCureCritical.WOUNDS_15";
    if (value == 63) return "IpConstCastspellCureCritical.WOUNDS_7";
    return "IpConstCastspellCureCritical.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCureCritical.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCureCritical.(not found: " + value + ")";
  }
}
