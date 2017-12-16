package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_MAGIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellMagic {
  private IpConstCastspellMagic() {}

  public final static int CIRCLE_AGAINST_ALIGNMENT_5 = 286;
  public final static int FANG_5 = 383;
  public final static int MISSILE_3 = 172;
  public final static int MISSILE_5 = 173;
  public final static int MISSILE_9 = 174;

  public static String nameOf(int value) {
    if (value == 286) return "IpConstCastspellMagic.CIRCLE_AGAINST_ALIGNMENT_5";
    if (value == 383) return "IpConstCastspellMagic.FANG_5";
    if (value == 172) return "IpConstCastspellMagic.MISSILE_3";
    if (value == 173) return "IpConstCastspellMagic.MISSILE_5";
    if (value == 174) return "IpConstCastspellMagic.MISSILE_9";
    return "IpConstCastspellMagic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellMagic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellMagic.(not found: " + value + ")";
  }
}
