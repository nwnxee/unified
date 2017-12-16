package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_BLUE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseBlue {
  private VfxDurAuraPulseBlue() {}

  public final static int BLACK = 529;
  public final static int GREEN = 523;
  public final static int WHITE = 513;
  public final static int YELLOW = 528;

  public static String nameOf(int value) {
    if (value == 529) return "VfxDurAuraPulseBlue.BLACK";
    if (value == 523) return "VfxDurAuraPulseBlue.GREEN";
    if (value == 513) return "VfxDurAuraPulseBlue.WHITE";
    if (value == 528) return "VfxDurAuraPulseBlue.YELLOW";
    return "VfxDurAuraPulseBlue.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseBlue.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseBlue.(not found: " + value + ")";
  }
}
