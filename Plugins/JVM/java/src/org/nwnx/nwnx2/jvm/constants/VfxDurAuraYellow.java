package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_YELLOW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraYellow {
  private VfxDurAuraYellow() {}

  public final static int DARK = 564;
  public final static int LIGHT = 565;
  public final static int VFX_DUR_AURA_YELLOW = 552;

  public static String nameOf(int value) {
    if (value == 564) return "VfxDurAuraYellow.DARK";
    if (value == 565) return "VfxDurAuraYellow.LIGHT";
    if (value == 552) return "VfxDurAuraYellow.VFX_DUR_AURA_YELLOW";
    return "VfxDurAuraYellow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraYellow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraYellow.(not found: " + value + ")";
  }
}
