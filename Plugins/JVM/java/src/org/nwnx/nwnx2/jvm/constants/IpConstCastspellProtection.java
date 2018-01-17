package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_PROTECTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellProtection {
  private IpConstCastspellProtection() {}

  public final static int FROM_ALIGNMENT_2 = 284;
  public final static int FROM_ALIGNMENT_5 = 285;
  public final static int FROM_ELEMENTS_10 = 217;
  public final static int FROM_ELEMENTS_3 = 216;
  public final static int FROM_SPELLS_13 = 224;
  public final static int FROM_SPELLS_20 = 225;

  public static String nameOf(int value) {
    if (value == 284) return "IpConstCastspellProtection.FROM_ALIGNMENT_2";
    if (value == 285) return "IpConstCastspellProtection.FROM_ALIGNMENT_5";
    if (value == 217) return "IpConstCastspellProtection.FROM_ELEMENTS_10";
    if (value == 216) return "IpConstCastspellProtection.FROM_ELEMENTS_3";
    if (value == 224) return "IpConstCastspellProtection.FROM_SPELLS_13";
    if (value == 225) return "IpConstCastspellProtection.FROM_SPELLS_20";
    return "IpConstCastspellProtection.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellProtection.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellProtection.(not found: " + value + ")";
  }
}
