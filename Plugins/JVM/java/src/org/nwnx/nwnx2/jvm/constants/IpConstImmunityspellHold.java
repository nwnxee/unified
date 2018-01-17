package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_IMMUNITYSPELL_HOLD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstImmunityspellHold {
  private IpConstImmunityspellHold() {}

  public final static int ANIMAL = 73;
  public final static int MONSTER = 74;
  public final static int PERSON = 75;

  public static String nameOf(int value) {
    if (value == 73) return "IpConstImmunityspellHold.ANIMAL";
    if (value == 74) return "IpConstImmunityspellHold.MONSTER";
    if (value == 75) return "IpConstImmunityspellHold.PERSON";
    return "IpConstImmunityspellHold.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstImmunityspellHold.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstImmunityspellHold.(not found: " + value + ")";
  }
}
