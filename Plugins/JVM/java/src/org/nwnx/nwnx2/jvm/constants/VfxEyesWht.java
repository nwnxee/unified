package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_WHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesWht {
  private VfxEyesWht() {}

  public final static int DWARF_FEMALE = 609;
  public final static int DWARF_MALE = 608;
  public final static int ELF_FEMALE = 611;
  public final static int ELF_MALE = 610;
  public final static int GNOME_FEMALE = 613;
  public final static int GNOME_MALE = 612;
  public final static int HALFLING_FEMALE = 615;
  public final static int HALFLING_MALE = 614;
  public final static int HALFORC_FEMALE = 617;
  public final static int HALFORC_MALE = 616;
  public final static int HUMAN_FEMALE = 607;
  public final static int HUMAN_MALE = 606;
  public final static int TROGLODYTE = 618;

  public static String nameOf(int value) {
    if (value == 609) return "VfxEyesWht.DWARF_FEMALE";
    if (value == 608) return "VfxEyesWht.DWARF_MALE";
    if (value == 611) return "VfxEyesWht.ELF_FEMALE";
    if (value == 610) return "VfxEyesWht.ELF_MALE";
    if (value == 613) return "VfxEyesWht.GNOME_FEMALE";
    if (value == 612) return "VfxEyesWht.GNOME_MALE";
    if (value == 615) return "VfxEyesWht.HALFLING_FEMALE";
    if (value == 614) return "VfxEyesWht.HALFLING_MALE";
    if (value == 617) return "VfxEyesWht.HALFORC_FEMALE";
    if (value == 616) return "VfxEyesWht.HALFORC_MALE";
    if (value == 607) return "VfxEyesWht.HUMAN_FEMALE";
    if (value == 606) return "VfxEyesWht.HUMAN_MALE";
    if (value == 618) return "VfxEyesWht.TROGLODYTE";
    return "VfxEyesWht.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesWht.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesWht.(not found: " + value + ")";
  }
}
