package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_FOXS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellFoxs {
  private IpConstCastspellFoxs() {}

  public final static int CUNNING_10 = 295;
  public final static int CUNNING_15 = 296;
  public final static int CUNNING_3 = 294;

  public static String nameOf(int value) {
    if (value == 295) return "IpConstCastspellFoxs.CUNNING_10";
    if (value == 296) return "IpConstCastspellFoxs.CUNNING_15";
    if (value == 294) return "IpConstCastspellFoxs.CUNNING_3";
    return "IpConstCastspellFoxs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellFoxs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellFoxs.(not found: " + value + ")";
  }
}
