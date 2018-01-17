package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_GLOW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurGlow {
  private VfxDurGlow() {}

  public final static int BLUE = 410;
  public final static int BROWN = 419;
  public final static int GREEN = 415;
  public final static int GREY = 421;
  public final static int LIGHT_BLUE = 408;
  public final static int LIGHT_BROWN = 420;
  public final static int LIGHT_GREEN = 416;
  public final static int LIGHT_ORANGE = 418;
  public final static int LIGHT_PURPLE = 423;
  public final static int LIGHT_RED = 412;
  public final static int LIGHT_YELLOW = 414;
  public final static int ORANGE = 417;
  public final static int PURPLE = 409;
  public final static int RED = 411;
  public final static int WHITE = 422;
  public final static int YELLOW = 413;

  public static String nameOf(int value) {
    if (value == 410) return "VfxDurGlow.BLUE";
    if (value == 419) return "VfxDurGlow.BROWN";
    if (value == 415) return "VfxDurGlow.GREEN";
    if (value == 421) return "VfxDurGlow.GREY";
    if (value == 408) return "VfxDurGlow.LIGHT_BLUE";
    if (value == 420) return "VfxDurGlow.LIGHT_BROWN";
    if (value == 416) return "VfxDurGlow.LIGHT_GREEN";
    if (value == 418) return "VfxDurGlow.LIGHT_ORANGE";
    if (value == 423) return "VfxDurGlow.LIGHT_PURPLE";
    if (value == 412) return "VfxDurGlow.LIGHT_RED";
    if (value == 414) return "VfxDurGlow.LIGHT_YELLOW";
    if (value == 417) return "VfxDurGlow.ORANGE";
    if (value == 409) return "VfxDurGlow.PURPLE";
    if (value == 411) return "VfxDurGlow.RED";
    if (value == 422) return "VfxDurGlow.WHITE";
    if (value == 413) return "VfxDurGlow.YELLOW";
    return "VfxDurGlow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurGlow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurGlow.(not found: " + value + ")";
  }
}
