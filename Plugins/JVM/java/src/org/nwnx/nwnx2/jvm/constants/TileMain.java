package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMain {
  private TileMain() {}

  public final static int LIGHT_COLOR_AQUA = 15;
  public final static int LIGHT_COLOR_BLACK = 0;
  public final static int LIGHT_COLOR_BLUE = 19;
  public final static int LIGHT_COLOR_BRIGHT_WHITE = 3;
  public final static int LIGHT_COLOR_DARK_AQUA = 13;
  public final static int LIGHT_COLOR_DARK_BLUE = 17;
  public final static int LIGHT_COLOR_DARK_GREEN = 9;
  public final static int LIGHT_COLOR_DARK_ORANGE = 29;
  public final static int LIGHT_COLOR_DARK_PURPLE = 21;
  public final static int LIGHT_COLOR_DARK_RED = 25;
  public final static int LIGHT_COLOR_DARK_YELLOW = 5;
  public final static int LIGHT_COLOR_DIM_WHITE = 1;
  public final static int LIGHT_COLOR_GREEN = 11;
  public final static int LIGHT_COLOR_ORANGE = 31;
  public final static int LIGHT_COLOR_PALE_AQUA = 14;
  public final static int LIGHT_COLOR_PALE_BLUE = 18;
  public final static int LIGHT_COLOR_PALE_DARK_AQUA = 12;
  public final static int LIGHT_COLOR_PALE_DARK_BLUE = 16;
  public final static int LIGHT_COLOR_PALE_DARK_GREEN = 8;
  public final static int LIGHT_COLOR_PALE_DARK_ORANGE = 28;
  public final static int LIGHT_COLOR_PALE_DARK_PURPLE = 20;
  public final static int LIGHT_COLOR_PALE_DARK_RED = 24;
  public final static int LIGHT_COLOR_PALE_DARK_YELLOW = 4;
  public final static int LIGHT_COLOR_PALE_GREEN = 10;
  public final static int LIGHT_COLOR_PALE_ORANGE = 30;
  public final static int LIGHT_COLOR_PALE_PURPLE = 22;
  public final static int LIGHT_COLOR_PALE_RED = 26;
  public final static int LIGHT_COLOR_PALE_YELLOW = 6;
  public final static int LIGHT_COLOR_PURPLE = 23;
  public final static int LIGHT_COLOR_RED = 27;
  public final static int LIGHT_COLOR_WHITE = 2;
  public final static int LIGHT_COLOR_YELLOW = 7;

  public static String nameOf(int value) {
    if (value == 15) return "TileMain.LIGHT_COLOR_AQUA";
    if (value == 0) return "TileMain.LIGHT_COLOR_BLACK";
    if (value == 19) return "TileMain.LIGHT_COLOR_BLUE";
    if (value == 3) return "TileMain.LIGHT_COLOR_BRIGHT_WHITE";
    if (value == 13) return "TileMain.LIGHT_COLOR_DARK_AQUA";
    if (value == 17) return "TileMain.LIGHT_COLOR_DARK_BLUE";
    if (value == 9) return "TileMain.LIGHT_COLOR_DARK_GREEN";
    if (value == 29) return "TileMain.LIGHT_COLOR_DARK_ORANGE";
    if (value == 21) return "TileMain.LIGHT_COLOR_DARK_PURPLE";
    if (value == 25) return "TileMain.LIGHT_COLOR_DARK_RED";
    if (value == 5) return "TileMain.LIGHT_COLOR_DARK_YELLOW";
    if (value == 1) return "TileMain.LIGHT_COLOR_DIM_WHITE";
    if (value == 11) return "TileMain.LIGHT_COLOR_GREEN";
    if (value == 31) return "TileMain.LIGHT_COLOR_ORANGE";
    if (value == 14) return "TileMain.LIGHT_COLOR_PALE_AQUA";
    if (value == 18) return "TileMain.LIGHT_COLOR_PALE_BLUE";
    if (value == 12) return "TileMain.LIGHT_COLOR_PALE_DARK_AQUA";
    if (value == 16) return "TileMain.LIGHT_COLOR_PALE_DARK_BLUE";
    if (value == 8) return "TileMain.LIGHT_COLOR_PALE_DARK_GREEN";
    if (value == 28) return "TileMain.LIGHT_COLOR_PALE_DARK_ORANGE";
    if (value == 20) return "TileMain.LIGHT_COLOR_PALE_DARK_PURPLE";
    if (value == 24) return "TileMain.LIGHT_COLOR_PALE_DARK_RED";
    if (value == 4) return "TileMain.LIGHT_COLOR_PALE_DARK_YELLOW";
    if (value == 10) return "TileMain.LIGHT_COLOR_PALE_GREEN";
    if (value == 30) return "TileMain.LIGHT_COLOR_PALE_ORANGE";
    if (value == 22) return "TileMain.LIGHT_COLOR_PALE_PURPLE";
    if (value == 26) return "TileMain.LIGHT_COLOR_PALE_RED";
    if (value == 6) return "TileMain.LIGHT_COLOR_PALE_YELLOW";
    if (value == 23) return "TileMain.LIGHT_COLOR_PURPLE";
    if (value == 27) return "TileMain.LIGHT_COLOR_RED";
    if (value == 2) return "TileMain.LIGHT_COLOR_WHITE";
    if (value == 7) return "TileMain.LIGHT_COLOR_YELLOW";
    return "TileMain.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMain.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMain.(not found: " + value + ")";
  }
}
