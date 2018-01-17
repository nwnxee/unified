package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_EAGLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellEagle {
  private IpConstCastspellEagle() {}

  public final static int SPLEDOR_10 = 289;
  public final static int SPLEDOR_15 = 290;
  public final static int SPLEDOR_3 = 288;

  public static String nameOf(int value) {
    if (value == 289) return "IpConstCastspellEagle.SPLEDOR_10";
    if (value == 290) return "IpConstCastspellEagle.SPLEDOR_15";
    if (value == 288) return "IpConstCastspellEagle.SPLEDOR_3";
    return "IpConstCastspellEagle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellEagle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellEagle.(not found: " + value + ")";
  }
}
