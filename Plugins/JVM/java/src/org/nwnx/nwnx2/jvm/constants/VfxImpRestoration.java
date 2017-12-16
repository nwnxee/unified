package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_RESTORATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpRestoration {
  private VfxImpRestoration() {}

  public final static int GREATER = 223;
  public final static int LESSER = 221;
  public final static int VFX_IMP_RESTORATION = 222;

  public static String nameOf(int value) {
    if (value == 223) return "VfxImpRestoration.GREATER";
    if (value == 221) return "VfxImpRestoration.LESSER";
    if (value == 222) return "VfxImpRestoration.VFX_IMP_RESTORATION";
    return "VfxImpRestoration.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpRestoration.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpRestoration.(not found: " + value + ")";
  }
}
