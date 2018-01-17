package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ELF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeElf {
  private AppearanceTypeElf() {}

  public final static int APPEARANCE_TYPE_ELF = 1;
  public final static int NPC_FEMALE = 245;
  public final static int NPC_MALE_01 = 246;
  public final static int NPC_MALE_02 = 247;

  public static String nameOf(int value) {
    if (value == 1) return "AppearanceTypeElf.APPEARANCE_TYPE_ELF";
    if (value == 245) return "AppearanceTypeElf.NPC_FEMALE";
    if (value == 246) return "AppearanceTypeElf.NPC_MALE_01";
    if (value == 247) return "AppearanceTypeElf.NPC_MALE_02";
    return "AppearanceTypeElf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeElf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeElf.(not found: " + value + ")";
  }
}
