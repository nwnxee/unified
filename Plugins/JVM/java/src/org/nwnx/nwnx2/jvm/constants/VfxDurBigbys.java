package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_BIGBYS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurBigbys {
  private VfxDurBigbys() {}

  public final static int CLENCHED_FIST = 316;
  public final static int CRUSHING_HAND = 317;
  public final static int GRASPING_HAND = 318;
  public final static int INTERPOSING_HAND = 314;

  public static String nameOf(int value) {
    if (value == 316) return "VfxDurBigbys.CLENCHED_FIST";
    if (value == 317) return "VfxDurBigbys.CRUSHING_HAND";
    if (value == 318) return "VfxDurBigbys.GRASPING_HAND";
    if (value == 314) return "VfxDurBigbys.INTERPOSING_HAND";
    return "VfxDurBigbys.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurBigbys.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurBigbys.(not found: " + value + ")";
  }
}
