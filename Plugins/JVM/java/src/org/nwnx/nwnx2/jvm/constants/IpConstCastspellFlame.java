package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_FLAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellFlame {
  private IpConstCastspellFlame() {}

  public final static int ARROW_12 = 111;
  public final static int ARROW_18 = 112;
  public final static int ARROW_5 = 110;
  public final static int LASH_10 = 114;
  public final static int LASH_3 = 113;
  public final static int STRIKE_12 = 116;
  public final static int STRIKE_18 = 117;
  public final static int STRIKE_7 = 115;

  public static String nameOf(int value) {
    if (value == 111) return "IpConstCastspellFlame.ARROW_12";
    if (value == 112) return "IpConstCastspellFlame.ARROW_18";
    if (value == 110) return "IpConstCastspellFlame.ARROW_5";
    if (value == 114) return "IpConstCastspellFlame.LASH_10";
    if (value == 113) return "IpConstCastspellFlame.LASH_3";
    if (value == 116) return "IpConstCastspellFlame.STRIKE_12";
    if (value == 117) return "IpConstCastspellFlame.STRIKE_18";
    if (value == 115) return "IpConstCastspellFlame.STRIKE_7";
    return "IpConstCastspellFlame.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellFlame.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellFlame.(not found: " + value + ")";
  }
}
