package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_HALF_ORC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeHalfOrc {
  private AppearanceTypeHalfOrc() {}

  public final static int APPEARANCE_TYPE_HALF_ORC = 5;
  public final static int NPC_FEMALE = 252;
  public final static int NPC_MALE_01 = 253;
  public final static int NPC_MALE_02 = 254;

  public static String nameOf(int value) {
    if (value == 5) return "AppearanceTypeHalfOrc.APPEARANCE_TYPE_HALF_ORC";
    if (value == 252) return "AppearanceTypeHalfOrc.NPC_FEMALE";
    if (value == 253) return "AppearanceTypeHalfOrc.NPC_MALE_01";
    if (value == 254) return "AppearanceTypeHalfOrc.NPC_MALE_02";
    return "AppearanceTypeHalfOrc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeHalfOrc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeHalfOrc.(not found: " + value + ")";
  }
}
