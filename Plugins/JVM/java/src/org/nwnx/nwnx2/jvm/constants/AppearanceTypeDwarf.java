package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_DWARF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeDwarf {
  private AppearanceTypeDwarf() {}

  public final static int APPEARANCE_TYPE_DWARF = 0;
  public final static int GOLEM = 474;
  public final static int HALFORC = 475;
  public final static int NPC_FEMALE = 248;
  public final static int NPC_MALE = 249;

  public static String nameOf(int value) {
    if (value == 0) return "AppearanceTypeDwarf.APPEARANCE_TYPE_DWARF";
    if (value == 474) return "AppearanceTypeDwarf.GOLEM";
    if (value == 475) return "AppearanceTypeDwarf.HALFORC";
    if (value == 248) return "AppearanceTypeDwarf.NPC_FEMALE";
    if (value == 249) return "AppearanceTypeDwarf.NPC_MALE";
    return "AppearanceTypeDwarf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeDwarf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeDwarf.(not found: " + value + ")";
  }
}
