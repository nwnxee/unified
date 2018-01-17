package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_OBJECT_FLAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeObjectFlame {
  private AppearanceTypeObjectFlame() {}

  public final static int LARGE = 445;
  public final static int MEDIUM = 444;
  public final static int SMALL = 443;

  public static String nameOf(int value) {
    if (value == 445) return "AppearanceTypeObjectFlame.LARGE";
    if (value == 444) return "AppearanceTypeObjectFlame.MEDIUM";
    if (value == 443) return "AppearanceTypeObjectFlame.SMALL";
    return "AppearanceTypeObjectFlame.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeObjectFlame.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeObjectFlame.(not found: " + value + ")";
  }
}
