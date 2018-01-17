package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_BLOOD_CRT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComBloodCrt {
  private VfxComBloodCrt() {}

  public final static int GREEN = 116 ;
  public final static int RED = 115 ;
  public final static int WIMP = 108 ;
  public final static int YELLOW = 117 ;

  public static String nameOf(int value) {
    if (value == 116 ) return "VfxComBloodCrt.GREEN";
    if (value == 115 ) return "VfxComBloodCrt.RED";
    if (value == 108 ) return "VfxComBloodCrt.WIMP";
    if (value == 117 ) return "VfxComBloodCrt.YELLOW";
    return "VfxComBloodCrt.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComBloodCrt.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComBloodCrt.(not found: " + value + ")";
  }
}
