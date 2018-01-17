package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_YELLOW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseYellow {
  private VfxDurAuraPulseYellow() {}

  public final static int BLACK = 532;
  public final static int ORANGE = 547;
  public final static int WHITE = 515;

  public static String nameOf(int value) {
    if (value == 532) return "VfxDurAuraPulseYellow.BLACK";
    if (value == 547) return "VfxDurAuraPulseYellow.ORANGE";
    if (value == 515) return "VfxDurAuraPulseYellow.WHITE";
    return "VfxDurAuraPulseYellow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseYellow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseYellow.(not found: " + value + ")";
  }
}
