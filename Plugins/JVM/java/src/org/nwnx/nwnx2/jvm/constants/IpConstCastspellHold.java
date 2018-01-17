package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_HOLD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellHold {
  private IpConstCastspellHold() {}

  public final static int ANIMAL_3 = 142;
  public final static int MONSTER_7 = 143;
  public final static int PERSON_3 = 144;

  public static String nameOf(int value) {
    if (value == 142) return "IpConstCastspellHold.ANIMAL_3";
    if (value == 143) return "IpConstCastspellHold.MONSTER_7";
    if (value == 144) return "IpConstCastspellHold.PERSON_3";
    return "IpConstCastspellHold.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellHold.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellHold.(not found: " + value + ")";
  }
}
