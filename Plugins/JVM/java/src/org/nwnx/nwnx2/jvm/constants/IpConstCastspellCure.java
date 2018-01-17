package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCure {
  private IpConstCastspellCure() {}

  public final static int CRITICAL_WOUNDS_12 = 64;
  public final static int CRITICAL_WOUNDS_15 = 65;
  public final static int CRITICAL_WOUNDS_7 = 63;
  public final static int LIGHT_WOUNDS_2 = 66;
  public final static int LIGHT_WOUNDS_5 = 67;
  public final static int MINOR_WOUNDS_1 = 68;
  public final static int MODERATE_WOUNDS_10 = 71;
  public final static int MODERATE_WOUNDS_3 = 69;
  public final static int MODERATE_WOUNDS_6 = 70;
  public final static int SERIOUS_WOUNDS_10 = 73;
  public final static int SERIOUS_WOUNDS_5 = 72;

  public static String nameOf(int value) {
    if (value == 64) return "IpConstCastspellCure.CRITICAL_WOUNDS_12";
    if (value == 65) return "IpConstCastspellCure.CRITICAL_WOUNDS_15";
    if (value == 63) return "IpConstCastspellCure.CRITICAL_WOUNDS_7";
    if (value == 66) return "IpConstCastspellCure.LIGHT_WOUNDS_2";
    if (value == 67) return "IpConstCastspellCure.LIGHT_WOUNDS_5";
    if (value == 68) return "IpConstCastspellCure.MINOR_WOUNDS_1";
    if (value == 71) return "IpConstCastspellCure.MODERATE_WOUNDS_10";
    if (value == 69) return "IpConstCastspellCure.MODERATE_WOUNDS_3";
    if (value == 70) return "IpConstCastspellCure.MODERATE_WOUNDS_6";
    if (value == 73) return "IpConstCastspellCure.SERIOUS_WOUNDS_10";
    if (value == 72) return "IpConstCastspellCure.SERIOUS_WOUNDS_5";
    return "IpConstCastspellCure.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCure.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCure.(not found: " + value + ")";
  }
}
