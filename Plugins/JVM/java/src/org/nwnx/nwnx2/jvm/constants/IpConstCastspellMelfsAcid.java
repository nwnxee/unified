package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_MELFS_ACID".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellMelfsAcid {
  private IpConstCastspellMelfsAcid() {}

  public final static int ARROW_3 = 184;
  public final static int ARROW_6 = 185;
  public final static int ARROW_9 = 186;

  public static String nameOf(int value) {
    if (value == 184) return "IpConstCastspellMelfsAcid.ARROW_3";
    if (value == 185) return "IpConstCastspellMelfsAcid.ARROW_6";
    if (value == 186) return "IpConstCastspellMelfsAcid.ARROW_9";
    return "IpConstCastspellMelfsAcid.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellMelfsAcid.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellMelfsAcid.(not found: " + value + ")";
  }
}
