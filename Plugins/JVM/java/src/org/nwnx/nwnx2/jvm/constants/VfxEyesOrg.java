package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_ORG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesOrg {
  private VfxEyesOrg() {}

  public final static int DWARF_FEMALE = 389;
  public final static int DWARF_MALE = 388;
  public final static int ELF_FEMALE = 391;
  public final static int ELF_MALE = 390;
  public final static int GNOME_FEMALE = 393;
  public final static int GNOME_MALE = 392;
  public final static int HALFLING_FEMALE = 395;
  public final static int HALFLING_MALE = 394;
  public final static int HALFORC_FEMALE = 397;
  public final static int HALFORC_MALE = 396;
  public final static int HUMAN_FEMALE = 387;
  public final static int HUMAN_MALE = 386;
  public final static int TROGLODYTE = 398;

  public static String nameOf(int value) {
    if (value == 389) return "VfxEyesOrg.DWARF_FEMALE";
    if (value == 388) return "VfxEyesOrg.DWARF_MALE";
    if (value == 391) return "VfxEyesOrg.ELF_FEMALE";
    if (value == 390) return "VfxEyesOrg.ELF_MALE";
    if (value == 393) return "VfxEyesOrg.GNOME_FEMALE";
    if (value == 392) return "VfxEyesOrg.GNOME_MALE";
    if (value == 395) return "VfxEyesOrg.HALFLING_FEMALE";
    if (value == 394) return "VfxEyesOrg.HALFLING_MALE";
    if (value == 397) return "VfxEyesOrg.HALFORC_FEMALE";
    if (value == 396) return "VfxEyesOrg.HALFORC_MALE";
    if (value == 387) return "VfxEyesOrg.HUMAN_FEMALE";
    if (value == 386) return "VfxEyesOrg.HUMAN_MALE";
    if (value == 398) return "VfxEyesOrg.TROGLODYTE";
    return "VfxEyesOrg.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesOrg.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesOrg.(not found: " + value + ")";
  }
}
