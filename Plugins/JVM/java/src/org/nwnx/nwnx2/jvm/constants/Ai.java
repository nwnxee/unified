package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AI".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Ai {
  private Ai() {}

  public final static int LEVEL_DEFAULT = -1;
  public final static int LEVEL_HIGH = 3;
  public final static int LEVEL_INVALID = -1;
  public final static int LEVEL_LOW = 1;
  public final static int LEVEL_NORMAL = 2;
  public final static int LEVEL_VERY_HIGH = 4;
  public final static int LEVEL_VERY_LOW = 0;

  public static String nameOf(int value) {
    if (value == -1) return "Ai.LEVEL_DEFAULT";
    if (value == 3) return "Ai.LEVEL_HIGH";
    if (value == -1) return "Ai.LEVEL_INVALID";
    if (value == 1) return "Ai.LEVEL_LOW";
    if (value == 2) return "Ai.LEVEL_NORMAL";
    if (value == 4) return "Ai.LEVEL_VERY_HIGH";
    if (value == 0) return "Ai.LEVEL_VERY_LOW";
    return "Ai.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Ai.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Ai.(not found: " + value + ")";
  }
}
