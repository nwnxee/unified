package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_TROGLODYTE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeTroglodyte {
  private AppearanceTypeTroglodyte() {}

  public final static int APPEARANCE_TYPE_TROGLODYTE = 451;
  public final static int CLERIC = 453;
  public final static int WARRIOR = 452;

  public static String nameOf(int value) {
    if (value == 451) return "AppearanceTypeTroglodyte.APPEARANCE_TYPE_TROGLODYTE";
    if (value == 453) return "AppearanceTypeTroglodyte.CLERIC";
    if (value == 452) return "AppearanceTypeTroglodyte.WARRIOR";
    return "AppearanceTypeTroglodyte.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeTroglodyte.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeTroglodyte.(not found: " + value + ")";
  }
}
