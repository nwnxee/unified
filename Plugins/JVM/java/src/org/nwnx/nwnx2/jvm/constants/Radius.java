package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "RADIUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Radius {
  private Radius() {}

  public final static float SIZE_COLOSSAL = 10.0f;
  public final static float SIZE_GARGANTUAN = 8.33f;
  public final static float SIZE_HUGE = 6.67f;
  public final static float SIZE_LARGE = 5.0f;
  public final static float SIZE_MEDIUM = 3.33f;
  public final static float SIZE_SMALL = 1.67f;

  public static String nameOf(int value) {
    return "Radius.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    if (value == 10.0f) return "Radius.SIZE_COLOSSAL";
    if (value == 8.33f) return "Radius.SIZE_GARGANTUAN";
    if (value == 6.67f) return "Radius.SIZE_HUGE";
    if (value == 5.0f) return "Radius.SIZE_LARGE";
    if (value == 3.33f) return "Radius.SIZE_MEDIUM";
    if (value == 1.67f) return "Radius.SIZE_SMALL";
    return "Radius.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Radius.(not found: " + value + ")";
  }
}
