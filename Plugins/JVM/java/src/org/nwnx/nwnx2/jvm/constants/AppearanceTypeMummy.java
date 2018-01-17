package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_MUMMY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeMummy {
  private AppearanceTypeMummy() {}

  public final static int COMMON = 58;
  public final static int FIGHTER_2 = 59;
  public final static int GREATER = 124;
  public final static int WARRIOR = 125;

  public static String nameOf(int value) {
    if (value == 58) return "AppearanceTypeMummy.COMMON";
    if (value == 59) return "AppearanceTypeMummy.FIGHTER_2";
    if (value == 124) return "AppearanceTypeMummy.GREATER";
    if (value == 125) return "AppearanceTypeMummy.WARRIOR";
    return "AppearanceTypeMummy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeMummy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeMummy.(not found: " + value + ")";
  }
}
