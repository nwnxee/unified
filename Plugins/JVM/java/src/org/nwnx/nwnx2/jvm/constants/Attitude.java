package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ATTITUDE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Attitude {
  private Attitude() {}

  public final static int AGGRESSIVE = 1;
  public final static int DEFENSIVE = 2;
  public final static int NEUTRAL = 0;
  public final static int SPECIAL = 3;

  public static String nameOf(int value) {
    if (value == 1) return "Attitude.AGGRESSIVE";
    if (value == 2) return "Attitude.DEFENSIVE";
    if (value == 0) return "Attitude.NEUTRAL";
    if (value == 3) return "Attitude.SPECIAL";
    return "Attitude.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Attitude.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Attitude.(not found: " + value + ")";
  }
}
