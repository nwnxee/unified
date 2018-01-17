package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DOMINATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDominate {
  private IpConstCastspellDominate() {}

  public final static int ANIMAL_5 = 87;
  public final static int MONSTER_17 = 88;
  public final static int PERSON_7 = 89;

  public static String nameOf(int value) {
    if (value == 87) return "IpConstCastspellDominate.ANIMAL_5";
    if (value == 88) return "IpConstCastspellDominate.MONSTER_17";
    if (value == 89) return "IpConstCastspellDominate.PERSON_7";
    return "IpConstCastspellDominate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDominate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDominate.(not found: " + value + ")";
  }
}
