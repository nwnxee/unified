package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ORC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeOrc {
  private AppearanceTypeOrc() {}

  public final static int A = 140;
  public final static int B = 141;
  public final static int CHIEFTAIN_A = 136;
  public final static int CHIEFTAIN_B = 137;
  public final static int SHAMAN_A = 138;
  public final static int SHAMAN_B = 139;

  public static String nameOf(int value) {
    if (value == 140) return "AppearanceTypeOrc.A";
    if (value == 141) return "AppearanceTypeOrc.B";
    if (value == 136) return "AppearanceTypeOrc.CHIEFTAIN_A";
    if (value == 137) return "AppearanceTypeOrc.CHIEFTAIN_B";
    if (value == 138) return "AppearanceTypeOrc.SHAMAN_A";
    if (value == 139) return "AppearanceTypeOrc.SHAMAN_B";
    return "AppearanceTypeOrc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeOrc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeOrc.(not found: " + value + ")";
  }
}
