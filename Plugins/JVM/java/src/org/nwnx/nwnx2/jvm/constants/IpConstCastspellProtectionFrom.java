package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_PROTECTION_FROM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellProtectionFrom {
  private IpConstCastspellProtectionFrom() {}

  public final static int ALIGNMENT_2 = 284;
  public final static int ALIGNMENT_5 = 285;
  public final static int ELEMENTS_10 = 217;
  public final static int ELEMENTS_3 = 216;
  public final static int SPELLS_13 = 224;
  public final static int SPELLS_20 = 225;

  public static String nameOf(int value) {
    if (value == 284) return "IpConstCastspellProtectionFrom.ALIGNMENT_2";
    if (value == 285) return "IpConstCastspellProtectionFrom.ALIGNMENT_5";
    if (value == 217) return "IpConstCastspellProtectionFrom.ELEMENTS_10";
    if (value == 216) return "IpConstCastspellProtectionFrom.ELEMENTS_3";
    if (value == 224) return "IpConstCastspellProtectionFrom.SPELLS_13";
    if (value == 225) return "IpConstCastspellProtectionFrom.SPELLS_20";
    return "IpConstCastspellProtectionFrom.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellProtectionFrom.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellProtectionFrom.(not found: " + value + ")";
  }
}
