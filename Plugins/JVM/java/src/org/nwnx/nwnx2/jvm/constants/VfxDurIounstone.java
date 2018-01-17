package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_IOUNSTONE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurIounstone {
  private VfxDurIounstone() {}

  public final static int BLUE = 500;
  public final static int GREEN = 502;
  public final static int RED = 499;
  public final static int VFX_DUR_IOUNSTONE = 403;
  public final static int YELLOW = 501;

  public static String nameOf(int value) {
    if (value == 500) return "VfxDurIounstone.BLUE";
    if (value == 502) return "VfxDurIounstone.GREEN";
    if (value == 499) return "VfxDurIounstone.RED";
    if (value == 403) return "VfxDurIounstone.VFX_DUR_IOUNSTONE";
    if (value == 501) return "VfxDurIounstone.YELLOW";
    return "VfxDurIounstone.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurIounstone.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurIounstone.(not found: " + value + ")";
  }
}
