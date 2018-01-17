package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_PROT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurProt {
  private VfxDurProt() {}

  public final static int BARKSKIN = 11;
  public final static int EPIC_ARMOR = 495;
  public final static int EPIC_ARMOR_2 = 497;
  public final static int GREATER_STONESKIN = 12;
  public final static int PREMONITION = 13;
  public final static int SHADOW_ARMOR = 14;
  public final static int STONESKIN = 15;

  public static String nameOf(int value) {
    if (value == 11) return "VfxDurProt.BARKSKIN";
    if (value == 495) return "VfxDurProt.EPIC_ARMOR";
    if (value == 497) return "VfxDurProt.EPIC_ARMOR_2";
    if (value == 12) return "VfxDurProt.GREATER_STONESKIN";
    if (value == 13) return "VfxDurProt.PREMONITION";
    if (value == 14) return "VfxDurProt.SHADOW_ARMOR";
    if (value == 15) return "VfxDurProt.STONESKIN";
    return "VfxDurProt.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurProt.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurProt.(not found: " + value + ")";
  }
}
