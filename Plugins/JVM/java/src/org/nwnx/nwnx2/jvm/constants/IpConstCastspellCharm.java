package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CHARM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCharm {
  private IpConstCastspellCharm() {}

  public final static int MONSTER_10 = 32;
  public final static int MONSTER_5 = 31;
  public final static int PERSON_10 = 34;
  public final static int PERSON_2 = 33;
  public final static int PERSON_OR_ANIMAL_10 = 36;
  public final static int PERSON_OR_ANIMAL_3 = 35;

  public static String nameOf(int value) {
    if (value == 32) return "IpConstCastspellCharm.MONSTER_10";
    if (value == 31) return "IpConstCastspellCharm.MONSTER_5";
    if (value == 34) return "IpConstCastspellCharm.PERSON_10";
    if (value == 33) return "IpConstCastspellCharm.PERSON_2";
    if (value == 36) return "IpConstCastspellCharm.PERSON_OR_ANIMAL_10";
    if (value == 35) return "IpConstCastspellCharm.PERSON_OR_ANIMAL_3";
    return "IpConstCastspellCharm.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCharm.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCharm.(not found: " + value + ")";
  }
}
