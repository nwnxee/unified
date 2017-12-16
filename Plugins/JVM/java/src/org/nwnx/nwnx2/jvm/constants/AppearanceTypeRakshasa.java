package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_RAKSHASA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeRakshasa {
  private AppearanceTypeRakshasa() {}

  public final static int BEAR_MALE = 294;
  public final static int TIGER_FEMALE = 290;
  public final static int TIGER_MALE = 293;
  public final static int WOLF_MALE = 295;

  public static String nameOf(int value) {
    if (value == 294) return "AppearanceTypeRakshasa.BEAR_MALE";
    if (value == 290) return "AppearanceTypeRakshasa.TIGER_FEMALE";
    if (value == 293) return "AppearanceTypeRakshasa.TIGER_MALE";
    if (value == 295) return "AppearanceTypeRakshasa.WOLF_MALE";
    return "AppearanceTypeRakshasa.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeRakshasa.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeRakshasa.(not found: " + value + ")";
  }
}
