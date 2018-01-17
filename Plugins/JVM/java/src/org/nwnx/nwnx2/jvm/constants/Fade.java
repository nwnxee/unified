package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FADE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Fade {
  private Fade() {}

  public final static float SPEED_FAST = 0.017f;
  public final static float SPEED_FASTEST = 0.25f;
  public final static float SPEED_MEDIUM = 0.01f;
  public final static float SPEED_SLOW = 0.005f;
  public final static float SPEED_SLOWEST = 0.003f;

  public static String nameOf(int value) {
    return "Fade.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    if (value == 0.017) return "Fade.SPEED_FAST";
    if (value == 0.25) return "Fade.SPEED_FASTEST";
    if (value == 0.01) return "Fade.SPEED_MEDIUM";
    if (value == 0.005) return "Fade.SPEED_SLOW";
    if (value == 0.003) return "Fade.SPEED_SLOWEST";
    return "Fade.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Fade.(not found: " + value + ")";
  }
}
