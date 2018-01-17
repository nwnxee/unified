package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "REPUTATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Reputation {
  private Reputation() {}

  public final static int TYPE_ENEMY = 1;
  public final static int TYPE_FRIEND = 0;
  public final static int TYPE_NEUTRAL = 2;

  public static String nameOf(int value) {
    if (value == 1) return "Reputation.TYPE_ENEMY";
    if (value == 0) return "Reputation.TYPE_FRIEND";
    if (value == 2) return "Reputation.TYPE_NEUTRAL";
    return "Reputation.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Reputation.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Reputation.(not found: " + value + ")";
  }
}
