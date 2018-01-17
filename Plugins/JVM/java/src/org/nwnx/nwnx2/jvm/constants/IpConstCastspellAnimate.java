package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_ANIMATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellAnimate {
  private IpConstCastspellAnimate() {}

  public final static int DEAD_10 = 3;
  public final static int DEAD_15 = 4;
  public final static int DEAD_5 = 2;

  public static String nameOf(int value) {
    if (value == 3) return "IpConstCastspellAnimate.DEAD_10";
    if (value == 4) return "IpConstCastspellAnimate.DEAD_15";
    if (value == 2) return "IpConstCastspellAnimate.DEAD_5";
    return "IpConstCastspellAnimate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellAnimate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellAnimate.(not found: " + value + ")";
  }
}
