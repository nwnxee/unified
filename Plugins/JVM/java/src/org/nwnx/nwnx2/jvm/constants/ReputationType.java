package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "REPUTATION_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ReputationType {
  private ReputationType() {}

  public final static int ENEMY = 1;
  public final static int FRIEND = 0;
  public final static int NEUTRAL = 2;

  public static String nameOf(int value) {
    if (value == 1) return "ReputationType.ENEMY";
    if (value == 0) return "ReputationType.FRIEND";
    if (value == 2) return "ReputationType.NEUTRAL";
    return "ReputationType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ReputationType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ReputationType.(not found: " + value + ")";
  }
}
