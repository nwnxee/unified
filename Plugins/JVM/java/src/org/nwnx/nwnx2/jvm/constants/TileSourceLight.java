package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_SOURCE_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileSourceLight {
  private TileSourceLight() {}

  public final static int COLOR_BLACK = 0;
  public final static int COLOR_PALE_AQUA = 7;
  public final static int COLOR_PALE_BLUE = 9;
  public final static int COLOR_PALE_DARK_AQUA = 6;
  public final static int COLOR_PALE_DARK_BLUE = 8;
  public final static int COLOR_PALE_DARK_GREEN = 4;
  public final static int COLOR_PALE_DARK_ORANGE = 14;
  public final static int COLOR_PALE_DARK_PURPLE = 10;
  public final static int COLOR_PALE_DARK_RED = 12;
  public final static int COLOR_PALE_DARK_YELLOW = 2;
  public final static int COLOR_PALE_GREEN = 5;
  public final static int COLOR_PALE_ORANGE = 15;
  public final static int COLOR_PALE_PURPLE = 11;
  public final static int COLOR_PALE_RED = 13;
  public final static int COLOR_PALE_YELLOW = 3;
  public final static int COLOR_WHITE = 1;

  public static String nameOf(int value) {
    if (value == 0) return "TileSourceLight.COLOR_BLACK";
    if (value == 7) return "TileSourceLight.COLOR_PALE_AQUA";
    if (value == 9) return "TileSourceLight.COLOR_PALE_BLUE";
    if (value == 6) return "TileSourceLight.COLOR_PALE_DARK_AQUA";
    if (value == 8) return "TileSourceLight.COLOR_PALE_DARK_BLUE";
    if (value == 4) return "TileSourceLight.COLOR_PALE_DARK_GREEN";
    if (value == 14) return "TileSourceLight.COLOR_PALE_DARK_ORANGE";
    if (value == 10) return "TileSourceLight.COLOR_PALE_DARK_PURPLE";
    if (value == 12) return "TileSourceLight.COLOR_PALE_DARK_RED";
    if (value == 2) return "TileSourceLight.COLOR_PALE_DARK_YELLOW";
    if (value == 5) return "TileSourceLight.COLOR_PALE_GREEN";
    if (value == 15) return "TileSourceLight.COLOR_PALE_ORANGE";
    if (value == 11) return "TileSourceLight.COLOR_PALE_PURPLE";
    if (value == 13) return "TileSourceLight.COLOR_PALE_RED";
    if (value == 3) return "TileSourceLight.COLOR_PALE_YELLOW";
    if (value == 1) return "TileSourceLight.COLOR_WHITE";
    return "TileSourceLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileSourceLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileSourceLight.(not found: " + value + ")";
  }
}
