package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AI_LEVEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AiLevel {
  private AiLevel() {}

  public final static int DEFAULT = -1;
  public final static int HIGH = 3;
  public final static int INVALID = -1;
  public final static int LOW = 1;
  public final static int NORMAL = 2;
  public final static int VERY_HIGH = 4;
  public final static int VERY_LOW = 0;

  public static String nameOf(int value) {
    if (value == -1) return "AiLevel.DEFAULT";
    if (value == 3) return "AiLevel.HIGH";
    if (value == -1) return "AiLevel.INVALID";
    if (value == 1) return "AiLevel.LOW";
    if (value == 2) return "AiLevel.NORMAL";
    if (value == 4) return "AiLevel.VERY_HIGH";
    if (value == 0) return "AiLevel.VERY_LOW";
    return "AiLevel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AiLevel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AiLevel.(not found: " + value + ")";
  }
}
