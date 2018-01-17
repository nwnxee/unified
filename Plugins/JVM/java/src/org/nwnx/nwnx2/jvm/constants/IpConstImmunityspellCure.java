package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_CURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellCure {
  private IpConstImmunityspellCure() {}

  public final static int CRITICAL_WOUNDS = 27;
  public final static int LIGHT_WOUNDS = 28;
  public final static int MINOR_WOUNDS = 29;
  public final static int MODERATE_WOUNDS = 30;
  public final static int SERIOUS_WOUNDS = 31;

  public static String nameOf(int value) {
    if (value == 27) return "IpConstImmunityspellCure.CRITICAL_WOUNDS";
    if (value == 28) return "IpConstImmunityspellCure.LIGHT_WOUNDS";
    if (value == 29) return "IpConstImmunityspellCure.MINOR_WOUNDS";
    if (value == 30) return "IpConstImmunityspellCure.MODERATE_WOUNDS";
    if (value == 31) return "IpConstImmunityspellCure.SERIOUS_WOUNDS";
    return "IpConstImmunityspellCure.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellCure.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellCure.(not found: " + value + ")";
  }
}
