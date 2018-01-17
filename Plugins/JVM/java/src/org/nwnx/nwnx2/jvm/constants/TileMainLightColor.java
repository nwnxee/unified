package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN_LIGHT_COLOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMainLightColor {
  private TileMainLightColor() {}

  public final static int AQUA = 15;
  public final static int BLACK = 0;
  public final static int BLUE = 19;
  public final static int BRIGHT_WHITE = 3;
  public final static int DARK_AQUA = 13;
  public final static int DARK_BLUE = 17;
  public final static int DARK_GREEN = 9;
  public final static int DARK_ORANGE = 29;
  public final static int DARK_PURPLE = 21;
  public final static int DARK_RED = 25;
  public final static int DARK_YELLOW = 5;
  public final static int DIM_WHITE = 1;
  public final static int GREEN = 11;
  public final static int ORANGE = 31;
  public final static int PALE_AQUA = 14;
  public final static int PALE_BLUE = 18;
  public final static int PALE_DARK_AQUA = 12;
  public final static int PALE_DARK_BLUE = 16;
  public final static int PALE_DARK_GREEN = 8;
  public final static int PALE_DARK_ORANGE = 28;
  public final static int PALE_DARK_PURPLE = 20;
  public final static int PALE_DARK_RED = 24;
  public final static int PALE_DARK_YELLOW = 4;
  public final static int PALE_GREEN = 10;
  public final static int PALE_ORANGE = 30;
  public final static int PALE_PURPLE = 22;
  public final static int PALE_RED = 26;
  public final static int PALE_YELLOW = 6;
  public final static int PURPLE = 23;
  public final static int RED = 27;
  public final static int WHITE = 2;
  public final static int YELLOW = 7;

  public static String nameOf(int value) {
    if (value == 15) return "TileMainLightColor.AQUA";
    if (value == 0) return "TileMainLightColor.BLACK";
    if (value == 19) return "TileMainLightColor.BLUE";
    if (value == 3) return "TileMainLightColor.BRIGHT_WHITE";
    if (value == 13) return "TileMainLightColor.DARK_AQUA";
    if (value == 17) return "TileMainLightColor.DARK_BLUE";
    if (value == 9) return "TileMainLightColor.DARK_GREEN";
    if (value == 29) return "TileMainLightColor.DARK_ORANGE";
    if (value == 21) return "TileMainLightColor.DARK_PURPLE";
    if (value == 25) return "TileMainLightColor.DARK_RED";
    if (value == 5) return "TileMainLightColor.DARK_YELLOW";
    if (value == 1) return "TileMainLightColor.DIM_WHITE";
    if (value == 11) return "TileMainLightColor.GREEN";
    if (value == 31) return "TileMainLightColor.ORANGE";
    if (value == 14) return "TileMainLightColor.PALE_AQUA";
    if (value == 18) return "TileMainLightColor.PALE_BLUE";
    if (value == 12) return "TileMainLightColor.PALE_DARK_AQUA";
    if (value == 16) return "TileMainLightColor.PALE_DARK_BLUE";
    if (value == 8) return "TileMainLightColor.PALE_DARK_GREEN";
    if (value == 28) return "TileMainLightColor.PALE_DARK_ORANGE";
    if (value == 20) return "TileMainLightColor.PALE_DARK_PURPLE";
    if (value == 24) return "TileMainLightColor.PALE_DARK_RED";
    if (value == 4) return "TileMainLightColor.PALE_DARK_YELLOW";
    if (value == 10) return "TileMainLightColor.PALE_GREEN";
    if (value == 30) return "TileMainLightColor.PALE_ORANGE";
    if (value == 22) return "TileMainLightColor.PALE_PURPLE";
    if (value == 26) return "TileMainLightColor.PALE_RED";
    if (value == 6) return "TileMainLightColor.PALE_YELLOW";
    if (value == 23) return "TileMainLightColor.PURPLE";
    if (value == 27) return "TileMainLightColor.RED";
    if (value == 2) return "TileMainLightColor.WHITE";
    if (value == 7) return "TileMainLightColor.YELLOW";
    return "TileMainLightColor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMainLightColor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMainLightColor.(not found: " + value + ")";
  }
}
