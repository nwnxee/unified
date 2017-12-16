package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_INFLICT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellInflict {
  private IpConstCastspellInflict() {}

  public final static int CRITICAL_WOUNDS_12 = 366;
  public final static int LIGHT_WOUNDS_5 = 363;
  public final static int MINOR_WOUNDS_1 = 362;
  public final static int MODERATE_WOUNDS_7 = 364;
  public final static int SERIOUS_WOUNDS_9 = 365;

  public static String nameOf(int value) {
    if (value == 366) return "IpConstCastspellInflict.CRITICAL_WOUNDS_12";
    if (value == 363) return "IpConstCastspellInflict.LIGHT_WOUNDS_5";
    if (value == 362) return "IpConstCastspellInflict.MINOR_WOUNDS_1";
    if (value == 364) return "IpConstCastspellInflict.MODERATE_WOUNDS_7";
    if (value == 365) return "IpConstCastspellInflict.SERIOUS_WOUNDS_9";
    return "IpConstCastspellInflict.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellInflict.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellInflict.(not found: " + value + ")";
  }
}
