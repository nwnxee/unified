package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_BIGBYS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellBigbys {
  private IpConstCastspellBigbys() {}

  public final static int CLENCHED_FIST_20 = 393;
  public final static int CRUSHING_HAND_20 = 394;
  public final static int FORCEFUL_HAND_15 = 391;
  public final static int GRASPING_HAND_17 = 392;
  public final static int INTERPOSING_HAND_15 = 390;

  public static String nameOf(int value) {
    if (value == 393) return "IpConstCastspellBigbys.CLENCHED_FIST_20";
    if (value == 394) return "IpConstCastspellBigbys.CRUSHING_HAND_20";
    if (value == 391) return "IpConstCastspellBigbys.FORCEFUL_HAND_15";
    if (value == 392) return "IpConstCastspellBigbys.GRASPING_HAND_17";
    if (value == 390) return "IpConstCastspellBigbys.INTERPOSING_HAND_15";
    return "IpConstCastspellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellBigbys.(not found: " + value + ")";
  }
}
