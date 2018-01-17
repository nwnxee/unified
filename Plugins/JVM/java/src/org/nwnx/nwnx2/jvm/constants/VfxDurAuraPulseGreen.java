package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_GREEN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseGreen {
  private VfxDurAuraPulseGreen() {}

  public final static int BLACK = 531;
  public final static int WHITE = 514;
  public final static int YELLOW = 526;

  public static String nameOf(int value) {
    if (value == 531) return "VfxDurAuraPulseGreen.BLACK";
    if (value == 514) return "VfxDurAuraPulseGreen.WHITE";
    if (value == 526) return "VfxDurAuraPulseGreen.YELLOW";
    return "VfxDurAuraPulseGreen.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseGreen.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseGreen.(not found: " + value + ")";
  }
}
