package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_MORDENKAINENS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellMordenkainens {
  private IpConstCastspellMordenkainens() {}

  public final static int DISJUNCTION_17 = 197;
  public final static int SWORD_13 = 198;
  public final static int SWORD_18 = 199;

  public static String nameOf(int value) {
    if (value == 197) return "IpConstCastspellMordenkainens.DISJUNCTION_17";
    if (value == 198) return "IpConstCastspellMordenkainens.SWORD_13";
    if (value == 199) return "IpConstCastspellMordenkainens.SWORD_18";
    return "IpConstCastspellMordenkainens.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellMordenkainens.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellMordenkainens.(not found: " + value + ")";
  }
}
