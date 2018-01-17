package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "NAME_LAST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class NameLast {
  private NameLast() {}

  public final static int DWARF = 4;
  public final static int ELF = 7;
  public final static int GNOME = 10;
  public final static int HALFELF = 13;
  public final static int HALFLING = 16;
  public final static int HALFORC = 19;
  public final static int HUMAN = 22;

  public static String nameOf(int value) {
    if (value == 4) return "NameLast.DWARF";
    if (value == 7) return "NameLast.ELF";
    if (value == 10) return "NameLast.GNOME";
    if (value == 13) return "NameLast.HALFELF";
    if (value == 16) return "NameLast.HALFLING";
    if (value == 19) return "NameLast.HALFORC";
    if (value == 22) return "NameLast.HUMAN";
    return "NameLast.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "NameLast.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "NameLast.(not found: " + value + ")";
  }
}
