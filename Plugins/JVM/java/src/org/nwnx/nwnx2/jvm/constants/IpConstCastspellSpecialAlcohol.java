package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_SPECIAL_ALCOHOL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellSpecialAlcohol {
  private IpConstCastspellSpecialAlcohol() {}

  public final static int BEER = 330;
  public final static int SPIRITS = 332;
  public final static int WINE = 331;

  public static String nameOf(int value) {
    if (value == 330) return "IpConstCastspellSpecialAlcohol.BEER";
    if (value == 332) return "IpConstCastspellSpecialAlcohol.SPIRITS";
    if (value == 331) return "IpConstCastspellSpecialAlcohol.WINE";
    return "IpConstCastspellSpecialAlcohol.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellSpecialAlcohol.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellSpecialAlcohol.(not found: " + value + ")";
  }
}
