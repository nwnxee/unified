package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_MASS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellMass {
  private IpConstImmunityspellMass() {}

  public final static int BLINDNESS_AND_DEAFNESS = 100;
  public final static int CHARM = 101;
  public final static int HEAL = 104;

  public static String nameOf(int value) {
    if (value == 100) return "IpConstImmunityspellMass.BLINDNESS_AND_DEAFNESS";
    if (value == 101) return "IpConstImmunityspellMass.CHARM";
    if (value == 104) return "IpConstImmunityspellMass.HEAL";
    return "IpConstImmunityspellMass.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellMass.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellMass.(not found: " + value + ")";
  }
}
