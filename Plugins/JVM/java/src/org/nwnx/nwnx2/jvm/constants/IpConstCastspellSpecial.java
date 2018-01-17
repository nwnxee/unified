package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_SPECIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellSpecial {
  private IpConstCastspellSpecial() {}

  public final static int ALCOHOL_BEER = 330;
  public final static int ALCOHOL_SPIRITS = 332;
  public final static int ALCOHOL_WINE = 331;
  public final static int HERB_BELLADONNA = 333;
  public final static int HERB_GARLIC = 334;

  public static String nameOf(int value) {
    if (value == 330) return "IpConstCastspellSpecial.ALCOHOL_BEER";
    if (value == 332) return "IpConstCastspellSpecial.ALCOHOL_SPIRITS";
    if (value == 331) return "IpConstCastspellSpecial.ALCOHOL_WINE";
    if (value == 333) return "IpConstCastspellSpecial.HERB_BELLADONNA";
    if (value == 334) return "IpConstCastspellSpecial.HERB_GARLIC";
    return "IpConstCastspellSpecial.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellSpecial.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellSpecial.(not found: " + value + ")";
  }
}
