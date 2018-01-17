package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_OWLS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellOwls {
  private IpConstCastspellOwls() {}

  public final static int INSIGHT_15 = 369;
  public final static int WISDOM_10 = 292;
  public final static int WISDOM_15 = 293;
  public final static int WISDOM_3 = 291;

  public static String nameOf(int value) {
    if (value == 369) return "IpConstCastspellOwls.INSIGHT_15";
    if (value == 292) return "IpConstCastspellOwls.WISDOM_10";
    if (value == 293) return "IpConstCastspellOwls.WISDOM_15";
    if (value == 291) return "IpConstCastspellOwls.WISDOM_3";
    return "IpConstCastspellOwls.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellOwls.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellOwls.(not found: " + value + ")";
  }
}
