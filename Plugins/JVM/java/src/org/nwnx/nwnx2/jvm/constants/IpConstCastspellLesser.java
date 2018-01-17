package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_LESSER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellLesser {
  private IpConstCastspellLesser() {}

  public final static int DISPEL_3 = 155;
  public final static int DISPEL_5 = 156;
  public final static int MIND_BLANK_9 = 157;
  public final static int PLANAR_BINDING_9 = 158;
  public final static int RESTORATION_3 = 159;
  public final static int SPELL_BREACH_7 = 160;
  public final static int SPELL_MANTLE_9 = 161;

  public static String nameOf(int value) {
    if (value == 155) return "IpConstCastspellLesser.DISPEL_3";
    if (value == 156) return "IpConstCastspellLesser.DISPEL_5";
    if (value == 157) return "IpConstCastspellLesser.MIND_BLANK_9";
    if (value == 158) return "IpConstCastspellLesser.PLANAR_BINDING_9";
    if (value == 159) return "IpConstCastspellLesser.RESTORATION_3";
    if (value == 160) return "IpConstCastspellLesser.SPELL_BREACH_7";
    if (value == 161) return "IpConstCastspellLesser.SPELL_MANTLE_9";
    return "IpConstCastspellLesser.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellLesser.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellLesser.(not found: " + value + ")";
  }
}
