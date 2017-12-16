package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TILE_SOURCE_LIGHT_COLOR_PALE_DARK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TileSourceLightColorPaleDark {
  private TileSourceLightColorPaleDark() {}

  public final static int AQUA = 6;
  public final static int BLUE = 8;
  public final static int GREEN = 4;
  public final static int ORANGE = 14;
  public final static int PURPLE = 10;
  public final static int RED = 12;
  public final static int YELLOW = 2;

  public static String nameOf(int value) {
    if (value == 6) return "TileSourceLightColorPaleDark.AQUA";
    if (value == 8) return "TileSourceLightColorPaleDark.BLUE";
    if (value == 4) return "TileSourceLightColorPaleDark.GREEN";
    if (value == 14) return "TileSourceLightColorPaleDark.ORANGE";
    if (value == 10) return "TileSourceLightColorPaleDark.PURPLE";
    if (value == 12) return "TileSourceLightColorPaleDark.RED";
    if (value == 2) return "TileSourceLightColorPaleDark.YELLOW";
    return "TileSourceLightColorPaleDark.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TileSourceLightColorPaleDark.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TileSourceLightColorPaleDark.(not found: " + value + ")";
  }
}
