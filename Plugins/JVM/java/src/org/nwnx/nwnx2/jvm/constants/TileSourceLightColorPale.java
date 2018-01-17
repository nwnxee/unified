package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_SOURCE_LIGHT_COLOR_PALE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileSourceLightColorPale {
  private TileSourceLightColorPale() {}

  public final static int AQUA = 7;
  public final static int BLUE = 9;
  public final static int DARK_AQUA = 6;
  public final static int DARK_BLUE = 8;
  public final static int DARK_GREEN = 4;
  public final static int DARK_ORANGE = 14;
  public final static int DARK_PURPLE = 10;
  public final static int DARK_RED = 12;
  public final static int DARK_YELLOW = 2;
  public final static int GREEN = 5;
  public final static int ORANGE = 15;
  public final static int PURPLE = 11;
  public final static int RED = 13;
  public final static int YELLOW = 3;

  public static String nameOf(int value) {
    if (value == 7) return "TileSourceLightColorPale.AQUA";
    if (value == 9) return "TileSourceLightColorPale.BLUE";
    if (value == 6) return "TileSourceLightColorPale.DARK_AQUA";
    if (value == 8) return "TileSourceLightColorPale.DARK_BLUE";
    if (value == 4) return "TileSourceLightColorPale.DARK_GREEN";
    if (value == 14) return "TileSourceLightColorPale.DARK_ORANGE";
    if (value == 10) return "TileSourceLightColorPale.DARK_PURPLE";
    if (value == 12) return "TileSourceLightColorPale.DARK_RED";
    if (value == 2) return "TileSourceLightColorPale.DARK_YELLOW";
    if (value == 5) return "TileSourceLightColorPale.GREEN";
    if (value == 15) return "TileSourceLightColorPale.ORANGE";
    if (value == 11) return "TileSourceLightColorPale.PURPLE";
    if (value == 13) return "TileSourceLightColorPale.RED";
    if (value == 3) return "TileSourceLightColorPale.YELLOW";
    return "TileSourceLightColorPale.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileSourceLightColorPale.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileSourceLightColorPale.(not found: " + value + ")";
  }
}
