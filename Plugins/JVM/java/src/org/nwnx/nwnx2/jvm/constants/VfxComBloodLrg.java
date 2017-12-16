package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_BLOOD_LRG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComBloodLrg {
  private VfxComBloodLrg() {}

  public final static int GREEN = 113 ;
  public final static int RED = 112 ;
  public final static int WIMP = 107 ;
  public final static int YELLOW = 114 ;

  public static String nameOf(int value) {
    if (value == 113 ) return "VfxComBloodLrg.GREEN";
    if (value == 112 ) return "VfxComBloodLrg.RED";
    if (value == 107 ) return "VfxComBloodLrg.WIMP";
    if (value == 114 ) return "VfxComBloodLrg.YELLOW";
    return "VfxComBloodLrg.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComBloodLrg.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComBloodLrg.(not found: " + value + ")";
  }
}
