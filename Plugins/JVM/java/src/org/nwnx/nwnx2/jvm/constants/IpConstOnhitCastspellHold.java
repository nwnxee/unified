package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ONHIT_CASTSPELL_HOLD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstOnhitCastspellHold {
  private IpConstOnhitCastspellHold() {}

  public final static int ANIMAL = 31;
  public final static int MONSTER = 32;
  public final static int PERSON = 33;

  public static String nameOf(int value) {
    if (value == 31) return "IpConstOnhitCastspellHold.ANIMAL";
    if (value == 32) return "IpConstOnhitCastspellHold.MONSTER";
    if (value == 33) return "IpConstOnhitCastspellHold.PERSON";
    return "IpConstOnhitCastspellHold.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstOnhitCastspellHold.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstOnhitCastspellHold.(not found: " + value + ")";
  }
}
