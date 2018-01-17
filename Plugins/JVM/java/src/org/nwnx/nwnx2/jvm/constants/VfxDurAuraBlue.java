package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_BLUE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraBlue {
  private VfxDurAuraBlue() {}

  public final static int DARK = 562;
  public final static int LIGHT = 563;
  public final static int VFX_DUR_AURA_BLUE = 550;

  public static String nameOf(int value) {
    if (value == 562) return "VfxDurAuraBlue.DARK";
    if (value == 563) return "VfxDurAuraBlue.LIGHT";
    if (value == 550) return "VfxDurAuraBlue.VFX_DUR_AURA_BLUE";
    return "VfxDurAuraBlue.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraBlue.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraBlue.(not found: " + value + ")";
  }
}
