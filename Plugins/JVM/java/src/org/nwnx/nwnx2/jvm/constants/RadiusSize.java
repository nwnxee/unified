package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "RADIUS_SIZE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class RadiusSize {
  private RadiusSize() {}

  public final static float COLOSSAL = 10.0f;
  public final static float GARGANTUAN = 8.33f;
  public final static float HUGE = 6.67f;
  public final static float LARGE = 5.0f;
  public final static float MEDIUM = 3.33f;
  public final static float SMALL = 1.67f;

  public static String nameOf(int value) {
    return "RadiusSize.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    if (value == 10.0f) return "RadiusSize.COLOSSAL";
    if (value == 8.33f) return "RadiusSize.GARGANTUAN";
    if (value == 6.67f) return "RadiusSize.HUGE";
    if (value == 5.0f) return "RadiusSize.LARGE";
    if (value == 3.33f) return "RadiusSize.MEDIUM";
    if (value == 1.67f) return "RadiusSize.SMALL";
    return "RadiusSize.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "RadiusSize.(not found: " + value + ")";
  }
}
