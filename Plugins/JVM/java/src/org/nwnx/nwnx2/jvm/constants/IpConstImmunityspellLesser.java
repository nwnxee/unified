package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_LESSER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellLesser {
  private IpConstImmunityspellLesser() {}

  public final static int DISPEL = 84;
  public final static int PLANAR_BINDING = 86;
  public final static int SPELL_BREACH = 88;

  public static String nameOf(int value) {
    if (value == 84) return "IpConstImmunityspellLesser.DISPEL";
    if (value == 86) return "IpConstImmunityspellLesser.PLANAR_BINDING";
    if (value == 88) return "IpConstImmunityspellLesser.SPELL_BREACH";
    return "IpConstImmunityspellLesser.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellLesser.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellLesser.(not found: " + value + ")";
  }
}
