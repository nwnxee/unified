package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DIVINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDivine {
  private IpConstCastspellDivine() {}

  public final static int FAVOR_5 = 345;
  public final static int MIGHT_5 = 395;
  public final static int POWER_7 = 86;
  public final static int SHIELD_5 = 396;

  public static String nameOf(int value) {
    if (value == 345) return "IpConstCastspellDivine.FAVOR_5";
    if (value == 395) return "IpConstCastspellDivine.MIGHT_5";
    if (value == 86) return "IpConstCastspellDivine.POWER_7";
    if (value == 396) return "IpConstCastspellDivine.SHIELD_5";
    return "IpConstCastspellDivine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDivine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDivine.(not found: " + value + ")";
  }
}
