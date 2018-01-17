package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_KOBOLD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeKobold {
  private AppearanceTypeKobold() {}

  public final static int A = 302;
  public final static int B = 305;
  public final static int CHIEF_A = 300;
  public final static int CHIEF_B = 303;
  public final static int SHAMAN_A = 301;
  public final static int SHAMAN_B = 304;

  public static String nameOf(int value) {
    if (value == 302) return "AppearanceTypeKobold.A";
    if (value == 305) return "AppearanceTypeKobold.B";
    if (value == 300) return "AppearanceTypeKobold.CHIEF_A";
    if (value == 303) return "AppearanceTypeKobold.CHIEF_B";
    if (value == 301) return "AppearanceTypeKobold.SHAMAN_A";
    if (value == 304) return "AppearanceTypeKobold.SHAMAN_B";
    return "AppearanceTypeKobold.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeKobold.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeKobold.(not found: " + value + ")";
  }
}
