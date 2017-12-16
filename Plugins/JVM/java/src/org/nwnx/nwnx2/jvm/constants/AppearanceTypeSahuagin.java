package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_SAHUAGIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeSahuagin {
  private AppearanceTypeSahuagin() {}

  public final static int APPEARANCE_TYPE_SAHUAGIN = 65;
  public final static int CLERIC = 67;
  public final static int LEADER = 66;

  public static String nameOf(int value) {
    if (value == 65) return "AppearanceTypeSahuagin.APPEARANCE_TYPE_SAHUAGIN";
    if (value == 67) return "AppearanceTypeSahuagin.CLERIC";
    if (value == 66) return "AppearanceTypeSahuagin.LEADER";
    return "AppearanceTypeSahuagin.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeSahuagin.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeSahuagin.(not found: " + value + ")";
  }
}
