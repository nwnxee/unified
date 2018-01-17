package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_RED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraRed {
  private VfxDurAuraRed() {}

  public final static int DARK = 560;
  public final static int LIGHT = 561;
  public final static int VFX_DUR_AURA_RED = 548;

  public static String nameOf(int value) {
    if (value == 560) return "VfxDurAuraRed.DARK";
    if (value == 561) return "VfxDurAuraRed.LIGHT";
    if (value == 548) return "VfxDurAuraRed.VFX_DUR_AURA_RED";
    return "VfxDurAuraRed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraRed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraRed.(not found: " + value + ")";
  }
}
