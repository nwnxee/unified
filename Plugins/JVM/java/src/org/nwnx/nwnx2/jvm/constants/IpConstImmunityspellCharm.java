package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_CHARM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellCharm {
  private IpConstImmunityspellCharm() {}

  public final static int MONSTER = 13;
  public final static int PERSON = 14;
  public final static int PERSON_OR_ANIMAL = 15;

  public static String nameOf(int value) {
    if (value == 13) return "IpConstImmunityspellCharm.MONSTER";
    if (value == 14) return "IpConstImmunityspellCharm.PERSON";
    if (value == 15) return "IpConstImmunityspellCharm.PERSON_OR_ANIMAL";
    return "IpConstImmunityspellCharm.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellCharm.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellCharm.(not found: " + value + ")";
  }
}
