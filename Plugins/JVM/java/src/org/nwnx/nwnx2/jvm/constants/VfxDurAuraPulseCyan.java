package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_CYAN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseCyan {
  private VfxDurAuraPulseCyan() {}

  public final static int BLACK = 534;
  public final static int BLUE = 539;
  public final static int GREEN = 538;
  public final static int RED = 540;
  public final static int WHITE = 517;
  public final static int YELLOW = 541;

  public static String nameOf(int value) {
    if (value == 534) return "VfxDurAuraPulseCyan.BLACK";
    if (value == 539) return "VfxDurAuraPulseCyan.BLUE";
    if (value == 538) return "VfxDurAuraPulseCyan.GREEN";
    if (value == 540) return "VfxDurAuraPulseCyan.RED";
    if (value == 517) return "VfxDurAuraPulseCyan.WHITE";
    if (value == 541) return "VfxDurAuraPulseCyan.YELLOW";
    return "VfxDurAuraPulseCyan.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseCyan.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseCyan.(not found: " + value + ")";
  }
}
