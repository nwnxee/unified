package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_MAIN_LIGHT_COLOR_PALE_DARK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileMainLightColorPaleDark {
  private TileMainLightColorPaleDark() {}

  public final static int AQUA = 12;
  public final static int BLUE = 16;
  public final static int GREEN = 8;
  public final static int ORANGE = 28;
  public final static int PURPLE = 20;
  public final static int RED = 24;
  public final static int YELLOW = 4;

  public static String nameOf(int value) {
    if (value == 12) return "TileMainLightColorPaleDark.AQUA";
    if (value == 16) return "TileMainLightColorPaleDark.BLUE";
    if (value == 8) return "TileMainLightColorPaleDark.GREEN";
    if (value == 28) return "TileMainLightColorPaleDark.ORANGE";
    if (value == 20) return "TileMainLightColorPaleDark.PURPLE";
    if (value == 24) return "TileMainLightColorPaleDark.RED";
    if (value == 4) return "TileMainLightColorPaleDark.YELLOW";
    return "TileMainLightColorPaleDark.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileMainLightColorPaleDark.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileMainLightColorPaleDark.(not found: " + value + ")";
  }
}
