package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_COM_BLOOD_REG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxComBloodReg {
  private VfxComBloodReg() {}

  public final static int GREEN = 110 ;
  public final static int RED = 109 ;
  public final static int WIMP = 106 ;
  public final static int YELLOW = 111 ;

  public static String nameOf(int value) {
    if (value == 110 ) return "VfxComBloodReg.GREEN";
    if (value == 109 ) return "VfxComBloodReg.RED";
    if (value == 106 ) return "VfxComBloodReg.WIMP";
    if (value == 111 ) return "VfxComBloodReg.YELLOW";
    return "VfxComBloodReg.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxComBloodReg.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxComBloodReg.(not found: " + value + ")";
  }
}
