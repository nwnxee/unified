package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_GHOSTLY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellGhostly {
  private IpConstCastspellGhostly() {}

  public final static int VISAGE_15 = 194;
  public final static int VISAGE_3 = 192;
  public final static int VISAGE_9 = 193;

  public static String nameOf(int value) {
    if (value == 194) return "IpConstCastspellGhostly.VISAGE_15";
    if (value == 192) return "IpConstCastspellGhostly.VISAGE_3";
    if (value == 193) return "IpConstCastspellGhostly.VISAGE_9";
    return "IpConstCastspellGhostly.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellGhostly.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellGhostly.(not found: " + value + ")";
  }
}
