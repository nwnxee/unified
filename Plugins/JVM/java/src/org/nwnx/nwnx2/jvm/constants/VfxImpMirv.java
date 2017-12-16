package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_MIRV".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpMirv {
  private VfxImpMirv() {}

  public final static int ELECTRIC = 503;
  public final static int FLAME = 233;
  public final static int VFX_IMP_MIRV = 181;

  public static String nameOf(int value) {
    if (value == 503) return "VfxImpMirv.ELECTRIC";
    if (value == 233) return "VfxImpMirv.FLAME";
    if (value == 181) return "VfxImpMirv.VFX_IMP_MIRV";
    return "VfxImpMirv.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpMirv.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpMirv.(not found: " + value + ")";
  }
}
