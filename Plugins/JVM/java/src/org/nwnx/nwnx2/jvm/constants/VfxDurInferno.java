package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_INFERNO".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurInferno {
  private VfxDurInferno() {}

  public final static int CHEST = 498;
  public final static int NO_SOUND = 505;
  public final static int VFX_DUR_INFERNO = 474;

  public static String nameOf(int value) {
    if (value == 498) return "VfxDurInferno.CHEST";
    if (value == 505) return "VfxDurInferno.NO_SOUND";
    if (value == 474) return "VfxDurInferno.VFX_DUR_INFERNO";
    return "VfxDurInferno.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurInferno.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurInferno.(not found: " + value + ")";
  }
}
