package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_GHOSTLY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurGhostly {
  private VfxDurGhostly() {}

  public final static int PULSE = 240;
  public final static int VISAGE = 9;
  public final static int VISAGE_NO_SOUND = 478;

  public static String nameOf(int value) {
    if (value == 240) return "VfxDurGhostly.PULSE";
    if (value == 9) return "VfxDurGhostly.VISAGE";
    if (value == 478) return "VfxDurGhostly.VISAGE_NO_SOUND";
    return "VfxDurGhostly.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurGhostly.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurGhostly.(not found: " + value + ")";
  }
}
