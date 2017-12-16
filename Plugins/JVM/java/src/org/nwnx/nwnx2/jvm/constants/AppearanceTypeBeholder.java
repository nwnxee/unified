package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_BEHOLDER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeBeholder {
  private AppearanceTypeBeholder() {}

  public final static int APPEARANCE_TYPE_BEHOLDER = 401;
  public final static int EYEBALL = 403;
  public final static int MAGE = 402;
  public final static int MOTHER = 472;

  public static String nameOf(int value) {
    if (value == 401) return "AppearanceTypeBeholder.APPEARANCE_TYPE_BEHOLDER";
    if (value == 403) return "AppearanceTypeBeholder.EYEBALL";
    if (value == 402) return "AppearanceTypeBeholder.MAGE";
    if (value == 472) return "AppearanceTypeBeholder.MOTHER";
    return "AppearanceTypeBeholder.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeBeholder.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeBeholder.(not found: " + value + ")";
  }
}
