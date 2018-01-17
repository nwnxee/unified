package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_CYN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesCyn {
  private VfxEyesCyn() {}

  public final static int DWARF_FEMALE = 596;
  public final static int DWARF_MALE = 595;
  public final static int ELF_FEMALE = 598;
  public final static int ELF_MALE = 597;
  public final static int GNOME_FEMALE = 600;
  public final static int GNOME_MALE = 599;
  public final static int HALFLING_FEMALE = 602;
  public final static int HALFLING_MALE = 601;
  public final static int HALFORC_FEMALE = 604;
  public final static int HALFORC_MALE = 603;
  public final static int HUMAN_FEMALE = 594;
  public final static int HUMAN_MALE = 593;
  public final static int TROGLODYTE = 605;

  public static String nameOf(int value) {
    if (value == 596) return "VfxEyesCyn.DWARF_FEMALE";
    if (value == 595) return "VfxEyesCyn.DWARF_MALE";
    if (value == 598) return "VfxEyesCyn.ELF_FEMALE";
    if (value == 597) return "VfxEyesCyn.ELF_MALE";
    if (value == 600) return "VfxEyesCyn.GNOME_FEMALE";
    if (value == 599) return "VfxEyesCyn.GNOME_MALE";
    if (value == 602) return "VfxEyesCyn.HALFLING_FEMALE";
    if (value == 601) return "VfxEyesCyn.HALFLING_MALE";
    if (value == 604) return "VfxEyesCyn.HALFORC_FEMALE";
    if (value == 603) return "VfxEyesCyn.HALFORC_MALE";
    if (value == 594) return "VfxEyesCyn.HUMAN_FEMALE";
    if (value == 593) return "VfxEyesCyn.HUMAN_MALE";
    if (value == 605) return "VfxEyesCyn.TROGLODYTE";
    return "VfxEyesCyn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesCyn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesCyn.(not found: " + value + ")";
  }
}
