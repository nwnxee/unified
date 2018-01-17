package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_DOMINATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellDominate {
  private IpConstImmunityspellDominate() {}

  public final static int ANIMAL = 39;
  public final static int MONSTER = 40;
  public final static int PERSON = 41;

  public static String nameOf(int value) {
    if (value == 39) return "IpConstImmunityspellDominate.ANIMAL";
    if (value == 40) return "IpConstImmunityspellDominate.MONSTER";
    if (value == 41) return "IpConstImmunityspellDominate.PERSON";
    return "IpConstImmunityspellDominate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellDominate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellDominate.(not found: " + value + ")";
  }
}
