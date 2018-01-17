package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_RED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesRed {
  private VfxEyesRed() {}

  public final static int FLAME_DWARF_FEMALE = 363;
  public final static int FLAME_DWARF_MALE = 362;
  public final static int FLAME_ELF_FEMALE = 365;
  public final static int FLAME_ELF_MALE = 364;
  public final static int FLAME_GNOME_FEMALE = 367;
  public final static int FLAME_GNOME_MALE = 366;
  public final static int FLAME_HALFELF_FEMALE = 361;
  public final static int FLAME_HALFELF_MALE = 360;
  public final static int FLAME_HALFLING_FEMALE = 369;
  public final static int FLAME_HALFLING_MALE = 368;
  public final static int FLAME_HALFORC_FEMALE = 371;
  public final static int FLAME_HALFORC_MALE = 370;
  public final static int FLAME_HUMAN_FEMALE = 361;
  public final static int FLAME_HUMAN_MALE = 360;
  public final static int FLAME_TROGLODYTE = 372;

  public static String nameOf(int value) {
    if (value == 363) return "VfxEyesRed.FLAME_DWARF_FEMALE";
    if (value == 362) return "VfxEyesRed.FLAME_DWARF_MALE";
    if (value == 365) return "VfxEyesRed.FLAME_ELF_FEMALE";
    if (value == 364) return "VfxEyesRed.FLAME_ELF_MALE";
    if (value == 367) return "VfxEyesRed.FLAME_GNOME_FEMALE";
    if (value == 366) return "VfxEyesRed.FLAME_GNOME_MALE";
    if (value == 361) return "VfxEyesRed.FLAME_HALFELF_FEMALE";
    if (value == 360) return "VfxEyesRed.FLAME_HALFELF_MALE";
    if (value == 369) return "VfxEyesRed.FLAME_HALFLING_FEMALE";
    if (value == 368) return "VfxEyesRed.FLAME_HALFLING_MALE";
    if (value == 371) return "VfxEyesRed.FLAME_HALFORC_FEMALE";
    if (value == 370) return "VfxEyesRed.FLAME_HALFORC_MALE";
    if (value == 361) return "VfxEyesRed.FLAME_HUMAN_FEMALE";
    if (value == 360) return "VfxEyesRed.FLAME_HUMAN_MALE";
    if (value == 372) return "VfxEyesRed.FLAME_TROGLODYTE";
    return "VfxEyesRed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesRed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesRed.(not found: " + value + ")";
  }
}
