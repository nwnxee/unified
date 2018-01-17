package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CATS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCats {
  private IpConstCastspellCats() {}

  public final static int GRACE_10 = 26;
  public final static int GRACE_15 = 27;
  public final static int GRACE_3 = 25;

  public static String nameOf(int value) {
    if (value == 26) return "IpConstCastspellCats.GRACE_10";
    if (value == 27) return "IpConstCastspellCats.GRACE_15";
    if (value == 25) return "IpConstCastspellCats.GRACE_3";
    return "IpConstCastspellCats.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCats.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCats.(not found: " + value + ")";
  }
}
