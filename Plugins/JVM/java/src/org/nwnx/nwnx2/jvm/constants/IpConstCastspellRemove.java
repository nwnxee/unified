package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_REMOVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellRemove {
  private IpConstCastspellRemove() {}

  public final static int BLINDNESS_DEAFNESS_5 = 229;
  public final static int CURSE_5 = 230;
  public final static int DISEASE_5 = 231;
  public final static int FEAR_2 = 232;
  public final static int PARALYSIS_3 = 233;

  public static String nameOf(int value) {
    if (value == 229) return "IpConstCastspellRemove.BLINDNESS_DEAFNESS_5";
    if (value == 230) return "IpConstCastspellRemove.CURSE_5";
    if (value == 231) return "IpConstCastspellRemove.DISEASE_5";
    if (value == 232) return "IpConstCastspellRemove.FEAR_2";
    if (value == 233) return "IpConstCastspellRemove.PARALYSIS_3";
    return "IpConstCastspellRemove.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellRemove.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellRemove.(not found: " + value + ")";
  }
}
