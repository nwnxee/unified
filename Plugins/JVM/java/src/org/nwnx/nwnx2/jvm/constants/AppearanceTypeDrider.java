package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_DRIDER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeDrider {
  private AppearanceTypeDrider() {}

  public final static int APPEARANCE_TYPE_DRIDER = 406;
  public final static int CHIEF = 407;
  public final static int FEMALE = 446;

  public static String nameOf(int value) {
    if (value == 406) return "AppearanceTypeDrider.APPEARANCE_TYPE_DRIDER";
    if (value == 407) return "AppearanceTypeDrider.CHIEF";
    if (value == 446) return "AppearanceTypeDrider.FEMALE";
    return "AppearanceTypeDrider.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeDrider.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeDrider.(not found: " + value + ")";
  }
}
