package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "WEATHER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Weather {
  private Weather() {}

  public final static int CLEAR = 0;
  public final static int INVALID = -1;
  public final static int RAIN = 1;
  public final static int SNOW = 2;
  public final static int USE_AREA_SETTINGS = -1;

  public static String nameOf(int value) {
    if (value == 0) return "Weather.CLEAR";
    if (value == -1) return "Weather.INVALID";
    if (value == 1) return "Weather.RAIN";
    if (value == 2) return "Weather.SNOW";
    if (value == -1) return "Weather.USE_AREA_SETTINGS";
    return "Weather.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Weather.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Weather.(not found: " + value + ")";
  }
}
