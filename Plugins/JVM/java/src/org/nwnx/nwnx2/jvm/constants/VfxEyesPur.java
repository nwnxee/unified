package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_PUR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesPur {
  private VfxEyesPur() {}

  public final static int DWARF_FEMALE = 583;
  public final static int DWARF_MALE = 582;
  public final static int ELF_FEMALE = 585;
  public final static int ELF_MALE = 584;
  public final static int GNOME_FEMALE = 587;
  public final static int GNOME_MALE = 586;
  public final static int HALFLING_FEMALE = 589;
  public final static int HALFLING_MALE = 588;
  public final static int HALFORC_FEMALE = 591;
  public final static int HALFORC_MALE = 590;
  public final static int HUMAN_FEMALE = 581;
  public final static int HUMAN_MALE = 580;
  public final static int TROGLODYTE = 592;

  public static String nameOf(int value) {
    if (value == 583) return "VfxEyesPur.DWARF_FEMALE";
    if (value == 582) return "VfxEyesPur.DWARF_MALE";
    if (value == 585) return "VfxEyesPur.ELF_FEMALE";
    if (value == 584) return "VfxEyesPur.ELF_MALE";
    if (value == 587) return "VfxEyesPur.GNOME_FEMALE";
    if (value == 586) return "VfxEyesPur.GNOME_MALE";
    if (value == 589) return "VfxEyesPur.HALFLING_FEMALE";
    if (value == 588) return "VfxEyesPur.HALFLING_MALE";
    if (value == 591) return "VfxEyesPur.HALFORC_FEMALE";
    if (value == 590) return "VfxEyesPur.HALFORC_MALE";
    if (value == 581) return "VfxEyesPur.HUMAN_FEMALE";
    if (value == 580) return "VfxEyesPur.HUMAN_MALE";
    if (value == 592) return "VfxEyesPur.TROGLODYTE";
    return "VfxEyesPur.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesPur.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesPur.(not found: " + value + ")";
  }
}
