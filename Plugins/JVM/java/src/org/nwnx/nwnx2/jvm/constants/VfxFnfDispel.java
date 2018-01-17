package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_DISPEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfDispel {
  private VfxFnfDispel() {}

  public final static int DISJUNCTION = 20;
  public final static int GREATER = 21 ;
  public final static int VFX_FNF_DISPEL = 19;

  public static String nameOf(int value) {
    if (value == 20) return "VfxFnfDispel.DISJUNCTION";
    if (value == 21 ) return "VfxFnfDispel.GREATER";
    if (value == 19) return "VfxFnfDispel.VFX_FNF_DISPEL";
    return "VfxFnfDispel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfDispel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfDispel.(not found: " + value + ")";
  }
}
