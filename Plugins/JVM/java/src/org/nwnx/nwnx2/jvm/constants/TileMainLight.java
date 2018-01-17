package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMainLight {
  private TileMainLight() {}

  public final static int COLOR_AQUA = 15;
  public final static int COLOR_BLACK = 0;
  public final static int COLOR_BLUE = 19;
  public final static int COLOR_BRIGHT_WHITE = 3;
  public final static int COLOR_DARK_AQUA = 13;
  public final static int COLOR_DARK_BLUE = 17;
  public final static int COLOR_DARK_GREEN = 9;
  public final static int COLOR_DARK_ORANGE = 29;
  public final static int COLOR_DARK_PURPLE = 21;
  public final static int COLOR_DARK_RED = 25;
  public final static int COLOR_DARK_YELLOW = 5;
  public final static int COLOR_DIM_WHITE = 1;
  public final static int COLOR_GREEN = 11;
  public final static int COLOR_ORANGE = 31;
  public final static int COLOR_PALE_AQUA = 14;
  public final static int COLOR_PALE_BLUE = 18;
  public final static int COLOR_PALE_DARK_AQUA = 12;
  public final static int COLOR_PALE_DARK_BLUE = 16;
  public final static int COLOR_PALE_DARK_GREEN = 8;
  public final static int COLOR_PALE_DARK_ORANGE = 28;
  public final static int COLOR_PALE_DARK_PURPLE = 20;
  public final static int COLOR_PALE_DARK_RED = 24;
  public final static int COLOR_PALE_DARK_YELLOW = 4;
  public final static int COLOR_PALE_GREEN = 10;
  public final static int COLOR_PALE_ORANGE = 30;
  public final static int COLOR_PALE_PURPLE = 22;
  public final static int COLOR_PALE_RED = 26;
  public final static int COLOR_PALE_YELLOW = 6;
  public final static int COLOR_PURPLE = 23;
  public final static int COLOR_RED = 27;
  public final static int COLOR_WHITE = 2;
  public final static int COLOR_YELLOW = 7;

  public static String nameOf(int value) {
    if (value == 15) return "TileMainLight.COLOR_AQUA";
    if (value == 0) return "TileMainLight.COLOR_BLACK";
    if (value == 19) return "TileMainLight.COLOR_BLUE";
    if (value == 3) return "TileMainLight.COLOR_BRIGHT_WHITE";
    if (value == 13) return "TileMainLight.COLOR_DARK_AQUA";
    if (value == 17) return "TileMainLight.COLOR_DARK_BLUE";
    if (value == 9) return "TileMainLight.COLOR_DARK_GREEN";
    if (value == 29) return "TileMainLight.COLOR_DARK_ORANGE";
    if (value == 21) return "TileMainLight.COLOR_DARK_PURPLE";
    if (value == 25) return "TileMainLight.COLOR_DARK_RED";
    if (value == 5) return "TileMainLight.COLOR_DARK_YELLOW";
    if (value == 1) return "TileMainLight.COLOR_DIM_WHITE";
    if (value == 11) return "TileMainLight.COLOR_GREEN";
    if (value == 31) return "TileMainLight.COLOR_ORANGE";
    if (value == 14) return "TileMainLight.COLOR_PALE_AQUA";
    if (value == 18) return "TileMainLight.COLOR_PALE_BLUE";
    if (value == 12) return "TileMainLight.COLOR_PALE_DARK_AQUA";
    if (value == 16) return "TileMainLight.COLOR_PALE_DARK_BLUE";
    if (value == 8) return "TileMainLight.COLOR_PALE_DARK_GREEN";
    if (value == 28) return "TileMainLight.COLOR_PALE_DARK_ORANGE";
    if (value == 20) return "TileMainLight.COLOR_PALE_DARK_PURPLE";
    if (value == 24) return "TileMainLight.COLOR_PALE_DARK_RED";
    if (value == 4) return "TileMainLight.COLOR_PALE_DARK_YELLOW";
    if (value == 10) return "TileMainLight.COLOR_PALE_GREEN";
    if (value == 30) return "TileMainLight.COLOR_PALE_ORANGE";
    if (value == 22) return "TileMainLight.COLOR_PALE_PURPLE";
    if (value == 26) return "TileMainLight.COLOR_PALE_RED";
    if (value == 6) return "TileMainLight.COLOR_PALE_YELLOW";
    if (value == 23) return "TileMainLight.COLOR_PURPLE";
    if (value == 27) return "TileMainLight.COLOR_RED";
    if (value == 2) return "TileMainLight.COLOR_WHITE";
    if (value == 7) return "TileMainLight.COLOR_YELLOW";
    return "TileMainLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMainLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMainLight.(not found: " + value + ")";
  }
}
