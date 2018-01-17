package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_ARROW_IN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurArrowIn {
  private VfxDurArrowIn() {}

  public final static int BACK = 635;
  public final static int CHEST_LEFT = 633;
  public final static int CHEST_RIGHT = 634;
  public final static int FACE = 637;
  public final static int HEAD = 638;
  public final static int STERNUM = 632;
  public final static int TEMPLES = 636;

  public static String nameOf(int value) {
    if (value == 635) return "VfxDurArrowIn.BACK";
    if (value == 633) return "VfxDurArrowIn.CHEST_LEFT";
    if (value == 634) return "VfxDurArrowIn.CHEST_RIGHT";
    if (value == 637) return "VfxDurArrowIn.FACE";
    if (value == 638) return "VfxDurArrowIn.HEAD";
    if (value == 632) return "VfxDurArrowIn.STERNUM";
    if (value == 636) return "VfxDurArrowIn.TEMPLES";
    return "VfxDurArrowIn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurArrowIn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurArrowIn.(not found: " + value + ")";
  }
}
