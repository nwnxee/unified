package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_DEATH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpDeath {
  private VfxImpDeath() {}

  public final static int L = 217;
  public final static int VFX_IMP_DEATH = 50 ;
  public final static int WARD = 146;

  public static String nameOf(int value) {
    if (value == 217) return "VfxImpDeath.L";
    if (value == 50 ) return "VfxImpDeath.VFX_IMP_DEATH";
    if (value == 146) return "VfxImpDeath.WARD";
    return "VfxImpDeath.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpDeath.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpDeath.(not found: " + value + ")";
  }
}
