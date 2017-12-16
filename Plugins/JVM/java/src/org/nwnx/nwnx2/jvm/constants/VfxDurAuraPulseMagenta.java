package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_AURA_PULSE_MAGENTA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurAuraPulseMagenta {
  private VfxDurAuraPulseMagenta() {}

  public final static int BLACK = 533;
  public final static int BLUE = 542;
  public final static int GREEN = 544;
  public final static int RED = 543;
  public final static int WHITE = 516;
  public final static int YELLOW = 545;

  public static String nameOf(int value) {
    if (value == 533) return "VfxDurAuraPulseMagenta.BLACK";
    if (value == 542) return "VfxDurAuraPulseMagenta.BLUE";
    if (value == 544) return "VfxDurAuraPulseMagenta.GREEN";
    if (value == 543) return "VfxDurAuraPulseMagenta.RED";
    if (value == 516) return "VfxDurAuraPulseMagenta.WHITE";
    if (value == 545) return "VfxDurAuraPulseMagenta.YELLOW";
    return "VfxDurAuraPulseMagenta.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurAuraPulseMagenta.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurAuraPulseMagenta.(not found: " + value + ")";
  }
}
