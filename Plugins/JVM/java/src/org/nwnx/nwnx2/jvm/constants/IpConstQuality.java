package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_QUALITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstQuality {
  private IpConstQuality() {}

  public final static int ABOVE_AVERAGE = 7;
  public final static int AVERAGE = 6;
  public final static int BELOW_AVERAGE = 5;
  public final static int CUT = 14;
  public final static int DESTROYED = 1;
  public final static int EXCELLENT = 10;
  public final static int GOD_LIKE = 12;
  public final static int GOOD = 8;
  public final static int MASTERWORK = 11;
  public final static int POLISHED = 15;
  public final static int POOR = 4;
  public final static int RAW = 13;
  public final static int RUINED = 2;
  public final static int UNKOWN = 0;
  public final static int VERY_GOOD = 9;
  public final static int VERY_POOR = 3;

  public static String nameOf(int value) {
    if (value == 7) return "IpConstQuality.ABOVE_AVERAGE";
    if (value == 6) return "IpConstQuality.AVERAGE";
    if (value == 5) return "IpConstQuality.BELOW_AVERAGE";
    if (value == 14) return "IpConstQuality.CUT";
    if (value == 1) return "IpConstQuality.DESTROYED";
    if (value == 10) return "IpConstQuality.EXCELLENT";
    if (value == 12) return "IpConstQuality.GOD_LIKE";
    if (value == 8) return "IpConstQuality.GOOD";
    if (value == 11) return "IpConstQuality.MASTERWORK";
    if (value == 15) return "IpConstQuality.POLISHED";
    if (value == 4) return "IpConstQuality.POOR";
    if (value == 13) return "IpConstQuality.RAW";
    if (value == 2) return "IpConstQuality.RUINED";
    if (value == 0) return "IpConstQuality.UNKOWN";
    if (value == 9) return "IpConstQuality.VERY_GOOD";
    if (value == 3) return "IpConstQuality.VERY_POOR";
    return "IpConstQuality.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstQuality.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstQuality.(not found: " + value + ")";
  }
}
