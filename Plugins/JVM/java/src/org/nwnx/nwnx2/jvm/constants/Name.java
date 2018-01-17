package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "NAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Name {
  private Name() {}

  public final static int ANIMAL = 0;
  public final static int FAMILIAR = 1;
  public final static int FIRST_DWARF_FEMALE = 3;
  public final static int FIRST_DWARF_MALE = 2;
  public final static int FIRST_ELF_FEMALE = 6;
  public final static int FIRST_ELF_MALE = 5;
  public final static int FIRST_GENERIC_MALE = -1;
  public final static int FIRST_GNOME_FEMALE = 9;
  public final static int FIRST_GNOME_MALE = 8;
  public final static int FIRST_HALFELF_FEMALE = 12;
  public final static int FIRST_HALFELF_MALE = 11;
  public final static int FIRST_HALFLING_FEMALE = 15;
  public final static int FIRST_HALFLING_MALE = 14;
  public final static int FIRST_HALFORC_FEMALE = 18;
  public final static int FIRST_HALFORC_MALE = 17;
  public final static int FIRST_HUMAN_FEMALE = 21;
  public final static int FIRST_HUMAN_MALE = 20;
  public final static int LAST_DWARF = 4;
  public final static int LAST_ELF = 7;
  public final static int LAST_GNOME = 10;
  public final static int LAST_HALFELF = 13;
  public final static int LAST_HALFLING = 16;
  public final static int LAST_HALFORC = 19;
  public final static int LAST_HUMAN = 22;

  public static String nameOf(int value) {
    if (value == 0) return "Name.ANIMAL";
    if (value == 1) return "Name.FAMILIAR";
    if (value == 3) return "Name.FIRST_DWARF_FEMALE";
    if (value == 2) return "Name.FIRST_DWARF_MALE";
    if (value == 6) return "Name.FIRST_ELF_FEMALE";
    if (value == 5) return "Name.FIRST_ELF_MALE";
    if (value == -1) return "Name.FIRST_GENERIC_MALE";
    if (value == 9) return "Name.FIRST_GNOME_FEMALE";
    if (value == 8) return "Name.FIRST_GNOME_MALE";
    if (value == 12) return "Name.FIRST_HALFELF_FEMALE";
    if (value == 11) return "Name.FIRST_HALFELF_MALE";
    if (value == 15) return "Name.FIRST_HALFLING_FEMALE";
    if (value == 14) return "Name.FIRST_HALFLING_MALE";
    if (value == 18) return "Name.FIRST_HALFORC_FEMALE";
    if (value == 17) return "Name.FIRST_HALFORC_MALE";
    if (value == 21) return "Name.FIRST_HUMAN_FEMALE";
    if (value == 20) return "Name.FIRST_HUMAN_MALE";
    if (value == 4) return "Name.LAST_DWARF";
    if (value == 7) return "Name.LAST_ELF";
    if (value == 10) return "Name.LAST_GNOME";
    if (value == 13) return "Name.LAST_HALFELF";
    if (value == 16) return "Name.LAST_HALFLING";
    if (value == 19) return "Name.LAST_HALFORC";
    if (value == 22) return "Name.LAST_HUMAN";
    return "Name.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Name.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Name.(not found: " + value + ")";
  }
}
