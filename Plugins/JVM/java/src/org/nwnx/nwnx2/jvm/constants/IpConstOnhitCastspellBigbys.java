package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ONHIT_CASTSPELL_BIGBYS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstOnhitCastspellBigbys {
  private IpConstOnhitCastspellBigbys() {}

  public final static int CLENCHED_FIST = 106;
  public final static int CRUSHING_HAND = 107;
  public final static int FORCEFUL_HAND = 104;
  public final static int GRASPING_HAND = 105;
  public final static int INTERPOSING_HAND = 103;

  public static String nameOf(int value) {
    if (value == 106) return "IpConstOnhitCastspellBigbys.CLENCHED_FIST";
    if (value == 107) return "IpConstOnhitCastspellBigbys.CRUSHING_HAND";
    if (value == 104) return "IpConstOnhitCastspellBigbys.FORCEFUL_HAND";
    if (value == 105) return "IpConstOnhitCastspellBigbys.GRASPING_HAND";
    if (value == 103) return "IpConstOnhitCastspellBigbys.INTERPOSING_HAND";
    return "IpConstOnhitCastspellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstOnhitCastspellBigbys.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstOnhitCastspellBigbys.(not found: " + value + ")";
  }
}
