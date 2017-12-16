package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CREATE_GREATER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCreateGreater {
  private IpConstCastspellCreateGreater() {}

  public final static int UNDEAD_15 = 57;
  public final static int UNDEAD_16 = 58;
  public final static int UNDEAD_18 = 59;

  public static String nameOf(int value) {
    if (value == 57) return "IpConstCastspellCreateGreater.UNDEAD_15";
    if (value == 58) return "IpConstCastspellCreateGreater.UNDEAD_16";
    if (value == 59) return "IpConstCastspellCreateGreater.UNDEAD_18";
    return "IpConstCastspellCreateGreater.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCreateGreater.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCreateGreater.(not found: " + value + ")";
  }
}
