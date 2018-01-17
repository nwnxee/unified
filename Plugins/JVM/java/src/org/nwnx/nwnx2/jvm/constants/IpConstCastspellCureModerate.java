package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CURE_MODERATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCureModerate {
  private IpConstCastspellCureModerate() {}

  public final static int WOUNDS_10 = 71;
  public final static int WOUNDS_3 = 69;
  public final static int WOUNDS_6 = 70;

  public static String nameOf(int value) {
    if (value == 71) return "IpConstCastspellCureModerate.WOUNDS_10";
    if (value == 69) return "IpConstCastspellCureModerate.WOUNDS_3";
    if (value == 70) return "IpConstCastspellCureModerate.WOUNDS_6";
    return "IpConstCastspellCureModerate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCureModerate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCureModerate.(not found: " + value + ")";
  }
}
