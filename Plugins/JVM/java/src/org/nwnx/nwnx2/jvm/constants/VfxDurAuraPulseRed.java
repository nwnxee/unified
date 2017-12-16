package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_RED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseRed {
  private VfxDurAuraPulseRed() {}

  public final static int BLACK = 530;
  public final static int BLUE = 524;
  public final static int GREEN = 527;
  public final static int ORANGE = 546;
  public final static int WHITE = 512;
  public final static int YELLOW = 525;

  public static String nameOf(int value) {
    if (value == 530) return "VfxDurAuraPulseRed.BLACK";
    if (value == 524) return "VfxDurAuraPulseRed.BLUE";
    if (value == 527) return "VfxDurAuraPulseRed.GREEN";
    if (value == 546) return "VfxDurAuraPulseRed.ORANGE";
    if (value == 512) return "VfxDurAuraPulseRed.WHITE";
    if (value == 525) return "VfxDurAuraPulseRed.YELLOW";
    return "VfxDurAuraPulseRed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseRed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseRed.(not found: " + value + ")";
  }
}
