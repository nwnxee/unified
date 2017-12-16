package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_EYES_YEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxEyesYel {
  private VfxEyesYel() {}

  public final static int DWARF_FEMALE = 376;
  public final static int DWARF_MALE = 375;
  public final static int ELF_FEMALE = 378;
  public final static int ELF_MALE = 377;
  public final static int GNOME_FEMALE = 380;
  public final static int GNOME_MALE = 379;
  public final static int HALFLING_FEMALE = 382;
  public final static int HALFLING_MALE = 381;
  public final static int HALFORC_FEMALE = 384;
  public final static int HALFORC_MALE = 383;
  public final static int HUMAN_FEMALE = 374;
  public final static int HUMAN_MALE = 373;
  public final static int TROGLODYTE = 385;

  public static String nameOf(int value) {
    if (value == 376) return "VfxEyesYel.DWARF_FEMALE";
    if (value == 375) return "VfxEyesYel.DWARF_MALE";
    if (value == 378) return "VfxEyesYel.ELF_FEMALE";
    if (value == 377) return "VfxEyesYel.ELF_MALE";
    if (value == 380) return "VfxEyesYel.GNOME_FEMALE";
    if (value == 379) return "VfxEyesYel.GNOME_MALE";
    if (value == 382) return "VfxEyesYel.HALFLING_FEMALE";
    if (value == 381) return "VfxEyesYel.HALFLING_MALE";
    if (value == 384) return "VfxEyesYel.HALFORC_FEMALE";
    if (value == 383) return "VfxEyesYel.HALFORC_MALE";
    if (value == 374) return "VfxEyesYel.HUMAN_FEMALE";
    if (value == 373) return "VfxEyesYel.HUMAN_MALE";
    if (value == 385) return "VfxEyesYel.TROGLODYTE";
    return "VfxEyesYel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxEyesYel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxEyesYel.(not found: " + value + ")";
  }
}
