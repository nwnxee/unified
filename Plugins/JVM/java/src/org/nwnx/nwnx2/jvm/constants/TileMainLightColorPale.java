package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN_LIGHT_COLOR_PALE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMainLightColorPale {
  private TileMainLightColorPale() {}

  public final static int AQUA = 14;
  public final static int BLUE = 18;
  public final static int DARK_AQUA = 12;
  public final static int DARK_BLUE = 16;
  public final static int DARK_GREEN = 8;
  public final static int DARK_ORANGE = 28;
  public final static int DARK_PURPLE = 20;
  public final static int DARK_RED = 24;
  public final static int DARK_YELLOW = 4;
  public final static int GREEN = 10;
  public final static int ORANGE = 30;
  public final static int PURPLE = 22;
  public final static int RED = 26;
  public final static int YELLOW = 6;

  public static String nameOf(int value) {
    if (value == 14) return "TileMainLightColorPale.AQUA";
    if (value == 18) return "TileMainLightColorPale.BLUE";
    if (value == 12) return "TileMainLightColorPale.DARK_AQUA";
    if (value == 16) return "TileMainLightColorPale.DARK_BLUE";
    if (value == 8) return "TileMainLightColorPale.DARK_GREEN";
    if (value == 28) return "TileMainLightColorPale.DARK_ORANGE";
    if (value == 20) return "TileMainLightColorPale.DARK_PURPLE";
    if (value == 24) return "TileMainLightColorPale.DARK_RED";
    if (value == 4) return "TileMainLightColorPale.DARK_YELLOW";
    if (value == 10) return "TileMainLightColorPale.GREEN";
    if (value == 30) return "TileMainLightColorPale.ORANGE";
    if (value == 22) return "TileMainLightColorPale.PURPLE";
    if (value == 26) return "TileMainLightColorPale.RED";
    if (value == 6) return "TileMainLightColorPale.YELLOW";
    return "TileMainLightColorPale.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMainLightColorPale.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMainLightColorPale.(not found: " + value + ")";
  }
}
