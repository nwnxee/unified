package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_SPECIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComSpecial {
  private VfxComSpecial() {}

  public final static int BLUE_RED = 100 ;
  public final static int PINK_ORANGE = 101 ;
  public final static int RED_ORANGE = 103 ;
  public final static int RED_WHITE = 102 ;
  public final static int WHITE_BLUE = 104 ;
  public final static int WHITE_ORANGE = 105 ;

  public static String nameOf(int value) {
    if (value == 100 ) return "VfxComSpecial.BLUE_RED";
    if (value == 101 ) return "VfxComSpecial.PINK_ORANGE";
    if (value == 103 ) return "VfxComSpecial.RED_ORANGE";
    if (value == 102 ) return "VfxComSpecial.RED_WHITE";
    if (value == 104 ) return "VfxComSpecial.WHITE_BLUE";
    if (value == 105 ) return "VfxComSpecial.WHITE_ORANGE";
    return "VfxComSpecial.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComSpecial.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComSpecial.(not found: " + value + ")";
  }
}
