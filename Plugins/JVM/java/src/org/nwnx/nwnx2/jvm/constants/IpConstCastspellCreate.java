package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CREATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCreate {
  private IpConstCastspellCreate() {}

  public final static int GREATER_UNDEAD_15 = 57;
  public final static int GREATER_UNDEAD_16 = 58;
  public final static int GREATER_UNDEAD_18 = 59;
  public final static int UNDEAD_11 = 60;
  public final static int UNDEAD_14 = 61;
  public final static int UNDEAD_16 = 62;

  public static String nameOf(int value) {
    if (value == 57) return "IpConstCastspellCreate.GREATER_UNDEAD_15";
    if (value == 58) return "IpConstCastspellCreate.GREATER_UNDEAD_16";
    if (value == 59) return "IpConstCastspellCreate.GREATER_UNDEAD_18";
    if (value == 60) return "IpConstCastspellCreate.UNDEAD_11";
    if (value == 61) return "IpConstCastspellCreate.UNDEAD_14";
    if (value == 62) return "IpConstCastspellCreate.UNDEAD_16";
    return "IpConstCastspellCreate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCreate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCreate.(not found: " + value + ")";
  }
}
