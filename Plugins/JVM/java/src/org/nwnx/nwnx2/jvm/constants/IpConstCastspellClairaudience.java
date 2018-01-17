package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CLAIRAUDIENCE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellClairaudience {
  private IpConstCastspellClairaudience() {}

  public final static int CLAIRVOYANCE_10 = 44;
  public final static int CLAIRVOYANCE_15 = 45;
  public final static int CLAIRVOYANCE_5 = 43;

  public static String nameOf(int value) {
    if (value == 44) return "IpConstCastspellClairaudience.CLAIRVOYANCE_10";
    if (value == 45) return "IpConstCastspellClairaudience.CLAIRVOYANCE_15";
    if (value == 43) return "IpConstCastspellClairaudience.CLAIRVOYANCE_5";
    return "IpConstCastspellClairaudience.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellClairaudience.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellClairaudience.(not found: " + value + ")";
  }
}
