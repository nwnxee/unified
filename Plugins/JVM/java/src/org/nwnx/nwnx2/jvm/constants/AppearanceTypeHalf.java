package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_HALF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeHalf {
  private AppearanceTypeHalf() {}

  public final static int ELF = 4;
  public final static int ORC = 5;
  public final static int ORC_NPC_FEMALE = 252;
  public final static int ORC_NPC_MALE_01 = 253;
  public final static int ORC_NPC_MALE_02 = 254;

  public static String nameOf(int value) {
    if (value == 4) return "AppearanceTypeHalf.ELF";
    if (value == 5) return "AppearanceTypeHalf.ORC";
    if (value == 252) return "AppearanceTypeHalf.ORC_NPC_FEMALE";
    if (value == 253) return "AppearanceTypeHalf.ORC_NPC_MALE_01";
    if (value == 254) return "AppearanceTypeHalf.ORC_NPC_MALE_02";
    return "AppearanceTypeHalf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeHalf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeHalf.(not found: " + value + ")";
  }
}
