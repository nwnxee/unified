package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "NAME_FIRST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class NameFirst {
  private NameFirst() {}

  public final static int DWARF_FEMALE = 3;
  public final static int DWARF_MALE = 2;
  public final static int ELF_FEMALE = 6;
  public final static int ELF_MALE = 5;
  public final static int GENERIC_MALE = -1;
  public final static int GNOME_FEMALE = 9;
  public final static int GNOME_MALE = 8;
  public final static int HALFELF_FEMALE = 12;
  public final static int HALFELF_MALE = 11;
  public final static int HALFLING_FEMALE = 15;
  public final static int HALFLING_MALE = 14;
  public final static int HALFORC_FEMALE = 18;
  public final static int HALFORC_MALE = 17;
  public final static int HUMAN_FEMALE = 21;
  public final static int HUMAN_MALE = 20;

  public static String nameOf(int value) {
    if (value == 3) return "NameFirst.DWARF_FEMALE";
    if (value == 2) return "NameFirst.DWARF_MALE";
    if (value == 6) return "NameFirst.ELF_FEMALE";
    if (value == 5) return "NameFirst.ELF_MALE";
    if (value == -1) return "NameFirst.GENERIC_MALE";
    if (value == 9) return "NameFirst.GNOME_FEMALE";
    if (value == 8) return "NameFirst.GNOME_MALE";
    if (value == 12) return "NameFirst.HALFELF_FEMALE";
    if (value == 11) return "NameFirst.HALFELF_MALE";
    if (value == 15) return "NameFirst.HALFLING_FEMALE";
    if (value == 14) return "NameFirst.HALFLING_MALE";
    if (value == 18) return "NameFirst.HALFORC_FEMALE";
    if (value == 17) return "NameFirst.HALFORC_MALE";
    if (value == 21) return "NameFirst.HUMAN_FEMALE";
    if (value == 20) return "NameFirst.HUMAN_MALE";
    return "NameFirst.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "NameFirst.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "NameFirst.(not found: " + value + ")";
  }
}
