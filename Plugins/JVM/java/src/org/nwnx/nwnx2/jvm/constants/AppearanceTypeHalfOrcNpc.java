package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_HALF_ORC_NPC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeHalfOrcNpc {
  private AppearanceTypeHalfOrcNpc() {}

  public final static int FEMALE = 252;
  public final static int MALE_01 = 253;
  public final static int MALE_02 = 254;

  public static String nameOf(int value) {
    if (value == 252) return "AppearanceTypeHalfOrcNpc.FEMALE";
    if (value == 253) return "AppearanceTypeHalfOrcNpc.MALE_01";
    if (value == 254) return "AppearanceTypeHalfOrcNpc.MALE_02";
    return "AppearanceTypeHalfOrcNpc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeHalfOrcNpc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeHalfOrcNpc.(not found: " + value + ")";
  }
}
