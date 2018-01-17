package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_RED_FLAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesRedFlame {
  private VfxEyesRedFlame() {}

  public final static int DWARF_FEMALE = 363;
  public final static int DWARF_MALE = 362;
  public final static int ELF_FEMALE = 365;
  public final static int ELF_MALE = 364;
  public final static int GNOME_FEMALE = 367;
  public final static int GNOME_MALE = 366;
  public final static int HALFELF_FEMALE = 361;
  public final static int HALFELF_MALE = 360;
  public final static int HALFLING_FEMALE = 369;
  public final static int HALFLING_MALE = 368;
  public final static int HALFORC_FEMALE = 371;
  public final static int HALFORC_MALE = 370;
  public final static int HUMAN_FEMALE = 361;
  public final static int HUMAN_MALE = 360;
  public final static int TROGLODYTE = 372;

  public static String nameOf(int value) {
    if (value == 363) return "VfxEyesRedFlame.DWARF_FEMALE";
    if (value == 362) return "VfxEyesRedFlame.DWARF_MALE";
    if (value == 365) return "VfxEyesRedFlame.ELF_FEMALE";
    if (value == 364) return "VfxEyesRedFlame.ELF_MALE";
    if (value == 367) return "VfxEyesRedFlame.GNOME_FEMALE";
    if (value == 366) return "VfxEyesRedFlame.GNOME_MALE";
    if (value == 361) return "VfxEyesRedFlame.HALFELF_FEMALE";
    if (value == 360) return "VfxEyesRedFlame.HALFELF_MALE";
    if (value == 369) return "VfxEyesRedFlame.HALFLING_FEMALE";
    if (value == 368) return "VfxEyesRedFlame.HALFLING_MALE";
    if (value == 371) return "VfxEyesRedFlame.HALFORC_FEMALE";
    if (value == 370) return "VfxEyesRedFlame.HALFORC_MALE";
    if (value == 361) return "VfxEyesRedFlame.HUMAN_FEMALE";
    if (value == 360) return "VfxEyesRedFlame.HUMAN_MALE";
    if (value == 372) return "VfxEyesRedFlame.TROGLODYTE";
    return "VfxEyesRedFlame.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesRedFlame.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesRedFlame.(not found: " + value + ")";
  }
}
