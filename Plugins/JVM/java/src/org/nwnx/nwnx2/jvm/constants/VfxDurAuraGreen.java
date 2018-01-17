package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_GREEN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraGreen {
  private VfxDurAuraGreen() {}

  public final static int DARK = 558;
  public final static int LIGHT = 559;
  public final static int VFX_DUR_AURA_GREEN = 549;

  public static String nameOf(int value) {
    if (value == 558) return "VfxDurAuraGreen.DARK";
    if (value == 559) return "VfxDurAuraGreen.LIGHT";
    if (value == 549) return "VfxDurAuraGreen.VFX_DUR_AURA_GREEN";
    return "VfxDurAuraGreen.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraGreen.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraGreen.(not found: " + value + ")";
  }
}
