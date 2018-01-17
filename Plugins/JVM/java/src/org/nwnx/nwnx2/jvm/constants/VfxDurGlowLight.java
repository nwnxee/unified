package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_GLOW_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurGlowLight {
  private VfxDurGlowLight() {}

  public final static int BLUE = 408;
  public final static int BROWN = 420;
  public final static int GREEN = 416;
  public final static int ORANGE = 418;
  public final static int PURPLE = 423;
  public final static int RED = 412;
  public final static int YELLOW = 414;

  public static String nameOf(int value) {
    if (value == 408) return "VfxDurGlowLight.BLUE";
    if (value == 420) return "VfxDurGlowLight.BROWN";
    if (value == 416) return "VfxDurGlowLight.GREEN";
    if (value == 418) return "VfxDurGlowLight.ORANGE";
    if (value == 423) return "VfxDurGlowLight.PURPLE";
    if (value == 412) return "VfxDurGlowLight.RED";
    if (value == 414) return "VfxDurGlowLight.YELLOW";
    return "VfxDurGlowLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurGlowLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurGlowLight.(not found: " + value + ")";
  }
}
