package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FADE_SPEED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FadeSpeed {
  private FadeSpeed() {}

  public final static float FAST = 0.017f;
  public final static float FASTEST = 0.25f;
  public final static float MEDIUM = 0.01f;
  public final static float SLOW = 0.005f;
  public final static float SLOWEST = 0.003f;

  public static String nameOf(int value) {
    return "FadeSpeed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    if (value == 0.017) return "FadeSpeed.FAST";
    if (value == 0.25) return "FadeSpeed.FASTEST";
    if (value == 0.01) return "FadeSpeed.MEDIUM";
    if (value == 0.005) return "FadeSpeed.SLOW";
    if (value == 0.003) return "FadeSpeed.SLOWEST";
    return "FadeSpeed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FadeSpeed.(not found: " + value + ")";
  }
}
