package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FOG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Fog {
  private Fog() {}

  public final static int COLOR_BLACK = 0;
  public final static int COLOR_BLUE = 255;
  public final static int COLOR_BLUE_DARK = 102;
  public final static int COLOR_BROWN = 10053120;
  public final static int COLOR_BROWN_DARK = 6697728;
  public final static int COLOR_CYAN = 65535;
  public final static int COLOR_GREEN = 65280;
  public final static int COLOR_GREEN_DARK = 23112;
  public final static int COLOR_GREY = 10066329;
  public final static int COLOR_MAGENTA = 16711935;
  public final static int COLOR_ORANGE = 16750848;
  public final static int COLOR_ORANGE_DARK = 13395456;
  public final static int COLOR_RED = 16711680;
  public final static int COLOR_RED_DARK = 6684672;
  public final static int COLOR_WHITE = 16777215;
  public final static int COLOR_YELLOW = 16776960;
  public final static int COLOR_YELLOW_DARK = 11184640;
  public final static int TYPE_ALL = 0;
  public final static int TYPE_MOON = 2;
  public final static int TYPE_SUN = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Fog.COLOR_BLACK";
    if (value == 255) return "Fog.COLOR_BLUE";
    if (value == 102) return "Fog.COLOR_BLUE_DARK";
    if (value == 10053120) return "Fog.COLOR_BROWN";
    if (value == 6697728) return "Fog.COLOR_BROWN_DARK";
    if (value == 65535) return "Fog.COLOR_CYAN";
    if (value == 65280) return "Fog.COLOR_GREEN";
    if (value == 23112) return "Fog.COLOR_GREEN_DARK";
    if (value == 10066329) return "Fog.COLOR_GREY";
    if (value == 16711935) return "Fog.COLOR_MAGENTA";
    if (value == 16750848) return "Fog.COLOR_ORANGE";
    if (value == 13395456) return "Fog.COLOR_ORANGE_DARK";
    if (value == 16711680) return "Fog.COLOR_RED";
    if (value == 6684672) return "Fog.COLOR_RED_DARK";
    if (value == 16777215) return "Fog.COLOR_WHITE";
    if (value == 16776960) return "Fog.COLOR_YELLOW";
    if (value == 11184640) return "Fog.COLOR_YELLOW_DARK";
    if (value == 0) return "Fog.TYPE_ALL";
    if (value == 2) return "Fog.TYPE_MOON";
    if (value == 1) return "Fog.TYPE_SUN";
    return "Fog.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Fog.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Fog.(not found: " + value + ")";
  }
}
