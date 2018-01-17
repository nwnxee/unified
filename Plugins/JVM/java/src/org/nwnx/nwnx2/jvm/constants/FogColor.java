package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FOG_COLOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FogColor {
  private FogColor() {}

  public final static int BLACK = 0;
  public final static int BLUE = 255;
  public final static int BLUE_DARK = 102;
  public final static int BROWN = 10053120;
  public final static int BROWN_DARK = 6697728;
  public final static int CYAN = 65535;
  public final static int GREEN = 65280;
  public final static int GREEN_DARK = 23112;
  public final static int GREY = 10066329;
  public final static int MAGENTA = 16711935;
  public final static int ORANGE = 16750848;
  public final static int ORANGE_DARK = 13395456;
  public final static int RED = 16711680;
  public final static int RED_DARK = 6684672;
  public final static int WHITE = 16777215;
  public final static int YELLOW = 16776960;
  public final static int YELLOW_DARK = 11184640;

  public static String nameOf(int value) {
    if (value == 0) return "FogColor.BLACK";
    if (value == 255) return "FogColor.BLUE";
    if (value == 102) return "FogColor.BLUE_DARK";
    if (value == 10053120) return "FogColor.BROWN";
    if (value == 6697728) return "FogColor.BROWN_DARK";
    if (value == 65535) return "FogColor.CYAN";
    if (value == 65280) return "FogColor.GREEN";
    if (value == 23112) return "FogColor.GREEN_DARK";
    if (value == 10066329) return "FogColor.GREY";
    if (value == 16711935) return "FogColor.MAGENTA";
    if (value == 16750848) return "FogColor.ORANGE";
    if (value == 13395456) return "FogColor.ORANGE_DARK";
    if (value == 16711680) return "FogColor.RED";
    if (value == 6684672) return "FogColor.RED_DARK";
    if (value == 16777215) return "FogColor.WHITE";
    if (value == 16776960) return "FogColor.YELLOW";
    if (value == 11184640) return "FogColor.YELLOW_DARK";
    return "FogColor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FogColor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FogColor.(not found: " + value + ")";
  }
}
