package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CHAIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellChain {
  private IpConstCastspellChain() {}

  public final static int LIGHTNING_11 = 28;
  public final static int LIGHTNING_15 = 29;
  public final static int LIGHTNING_20 = 30;

  public static String nameOf(int value) {
    if (value == 28) return "IpConstCastspellChain.LIGHTNING_11";
    if (value == 29) return "IpConstCastspellChain.LIGHTNING_15";
    if (value == 30) return "IpConstCastspellChain.LIGHTNING_20";
    return "IpConstCastspellChain.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellChain.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellChain.(not found: " + value + ")";
  }
}
