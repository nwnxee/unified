package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN_LIGHT_COLOR_DARK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMainLightColorDark {
  private TileMainLightColorDark() {}

  public final static int AQUA = 13;
  public final static int BLUE = 17;
  public final static int GREEN = 9;
  public final static int ORANGE = 29;
  public final static int PURPLE = 21;
  public final static int RED = 25;
  public final static int YELLOW = 5;

  public static String nameOf(int value) {
    if (value == 13) return "TileMainLightColorDark.AQUA";
    if (value == 17) return "TileMainLightColorDark.BLUE";
    if (value == 9) return "TileMainLightColorDark.GREEN";
    if (value == 29) return "TileMainLightColorDark.ORANGE";
    if (value == 21) return "TileMainLightColorDark.PURPLE";
    if (value == 25) return "TileMainLightColorDark.RED";
    if (value == 5) return "TileMainLightColorDark.YELLOW";
    return "TileMainLightColorDark.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMainLightColorDark.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMainLightColorDark.(not found: " + value + ")";
  }
}
