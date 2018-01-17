package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ELF_NPC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeElfNpc {
  private AppearanceTypeElfNpc() {}

  public final static int FEMALE = 245;
  public final static int MALE_01 = 246;
  public final static int MALE_02 = 247;

  public static String nameOf(int value) {
    if (value == 245) return "AppearanceTypeElfNpc.FEMALE";
    if (value == 246) return "AppearanceTypeElfNpc.MALE_01";
    if (value == 247) return "AppearanceTypeElfNpc.MALE_02";
    return "AppearanceTypeElfNpc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeElfNpc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeElfNpc.(not found: " + value + ")";
  }
}
