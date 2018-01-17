package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_GREEN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesGreen {
  private VfxEyesGreen() {}

  public final static int DWARF_FEMALE = 570;
  public final static int DWARF_MALE = 569;
  public final static int ELF_FEMALE = 572;
  public final static int ELF_MALE = 571;
  public final static int GNOME_FEMALE = 574;
  public final static int GNOME_MALE = 573;
  public final static int HALFELF_FEMALE = 568;
  public final static int HALFELF_MALE = 567;
  public final static int HALFLING_FEMALE = 576;
  public final static int HALFLING_MALE = 575;
  public final static int HALFORC_FEMALE = 578;
  public final static int HALFORC_MALE = 577;
  public final static int HUMAN_FEMALE = 568;
  public final static int HUMAN_MALE = 567;
  public final static int TROGLODYTE = 579;

  public static String nameOf(int value) {
    if (value == 570) return "VfxEyesGreen.DWARF_FEMALE";
    if (value == 569) return "VfxEyesGreen.DWARF_MALE";
    if (value == 572) return "VfxEyesGreen.ELF_FEMALE";
    if (value == 571) return "VfxEyesGreen.ELF_MALE";
    if (value == 574) return "VfxEyesGreen.GNOME_FEMALE";
    if (value == 573) return "VfxEyesGreen.GNOME_MALE";
    if (value == 568) return "VfxEyesGreen.HALFELF_FEMALE";
    if (value == 567) return "VfxEyesGreen.HALFELF_MALE";
    if (value == 576) return "VfxEyesGreen.HALFLING_FEMALE";
    if (value == 575) return "VfxEyesGreen.HALFLING_MALE";
    if (value == 578) return "VfxEyesGreen.HALFORC_FEMALE";
    if (value == 577) return "VfxEyesGreen.HALFORC_MALE";
    if (value == 568) return "VfxEyesGreen.HUMAN_FEMALE";
    if (value == 567) return "VfxEyesGreen.HUMAN_MALE";
    if (value == 579) return "VfxEyesGreen.TROGLODYTE";
    return "VfxEyesGreen.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesGreen.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesGreen.(not found: " + value + ")";
  }
}
