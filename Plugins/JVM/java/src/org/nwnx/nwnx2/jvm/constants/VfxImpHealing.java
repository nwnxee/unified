package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_HEALING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpHealing {
  private VfxImpHealing() {}

  public final static int G = 66 ;
  public final static int L = 67 ;
  public final static int M = 68 ;
  public final static int S = 69 ;
  public final static int X = 70 ;

  public static String nameOf(int value) {
    if (value == 66 ) return "VfxImpHealing.G";
    if (value == 67 ) return "VfxImpHealing.L";
    if (value == 68 ) return "VfxImpHealing.M";
    if (value == 69 ) return "VfxImpHealing.S";
    if (value == 70 ) return "VfxImpHealing.X";
    return "VfxImpHealing.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpHealing.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpHealing.(not found: " + value + ")";
  }
}
