package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_FLAG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurFlag {
  private VfxDurFlag() {}

  public final static int BLUE = 304;
  public final static int GOLD = 305;
  public final static int GOLD_FIXED = 306;
  public final static int PURPLE = 306;
  public final static int PURPLE_FIXED = 305;
  public final static int RED = 303;

  public static String nameOf(int value) {
    if (value == 304) return "VfxDurFlag.BLUE";
    if (value == 305) return "VfxDurFlag.GOLD";
    if (value == 306) return "VfxDurFlag.GOLD_FIXED";
    if (value == 306) return "VfxDurFlag.PURPLE";
    if (value == 305) return "VfxDurFlag.PURPLE_FIXED";
    if (value == 303) return "VfxDurFlag.RED";
    return "VfxDurFlag.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurFlag.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurFlag.(not found: " + value + ")";
  }
}
