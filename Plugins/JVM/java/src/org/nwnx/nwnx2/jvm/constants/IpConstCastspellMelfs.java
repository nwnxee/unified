package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_MELFS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellMelfs {
  private IpConstCastspellMelfs() {}

  public final static int ACID_ARROW_3 = 184;
  public final static int ACID_ARROW_6 = 185;
  public final static int ACID_ARROW_9 = 186;

  public static String nameOf(int value) {
    if (value == 184) return "IpConstCastspellMelfs.ACID_ARROW_3";
    if (value == 185) return "IpConstCastspellMelfs.ACID_ARROW_6";
    if (value == 186) return "IpConstCastspellMelfs.ACID_ARROW_9";
    return "IpConstCastspellMelfs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellMelfs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellMelfs.(not found: " + value + ")";
  }
}
