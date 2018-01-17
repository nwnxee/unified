package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ONHIT_CASTSPELL_INFLICT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstOnhitCastspellInflict {
  private IpConstOnhitCastspellInflict() {}

  public final static int CRITICAL_WOUNDS = 90;
  public final static int LIGHT_WOUNDS = 87;
  public final static int MINOR_WOUNDS = 86;
  public final static int MODERATE_WOUNDS = 88;
  public final static int SERIOUS_WOUNDS = 89;

  public static String nameOf(int value) {
    if (value == 90) return "IpConstOnhitCastspellInflict.CRITICAL_WOUNDS";
    if (value == 87) return "IpConstOnhitCastspellInflict.LIGHT_WOUNDS";
    if (value == 86) return "IpConstOnhitCastspellInflict.MINOR_WOUNDS";
    if (value == 88) return "IpConstOnhitCastspellInflict.MODERATE_WOUNDS";
    if (value == 89) return "IpConstOnhitCastspellInflict.SERIOUS_WOUNDS";
    return "IpConstOnhitCastspellInflict.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstOnhitCastspellInflict.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstOnhitCastspellInflict.(not found: " + value + ")";
  }
}
