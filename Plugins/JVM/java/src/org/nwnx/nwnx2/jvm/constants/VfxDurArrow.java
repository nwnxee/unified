package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_ARROW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurArrow {
  private VfxDurArrow() {}

  public final static int IN_BACK = 635;
  public final static int IN_CHEST_LEFT = 633;
  public final static int IN_CHEST_RIGHT = 634;
  public final static int IN_FACE = 637;
  public final static int IN_HEAD = 638;
  public final static int IN_STERNUM = 632;
  public final static int IN_TEMPLES = 636;

  public static String nameOf(int value) {
    if (value == 635) return "VfxDurArrow.IN_BACK";
    if (value == 633) return "VfxDurArrow.IN_CHEST_LEFT";
    if (value == 634) return "VfxDurArrow.IN_CHEST_RIGHT";
    if (value == 637) return "VfxDurArrow.IN_FACE";
    if (value == 638) return "VfxDurArrow.IN_HEAD";
    if (value == 632) return "VfxDurArrow.IN_STERNUM";
    if (value == 636) return "VfxDurArrow.IN_TEMPLES";
    return "VfxDurArrow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurArrow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurArrow.(not found: " + value + ")";
  }
}
