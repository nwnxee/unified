package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_BUGBEAR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeBugbear {
  private AppearanceTypeBugbear() {}

  public final static int A = 29;
  public final static int B = 30;
  public final static int CHIEFTAIN_A = 25;
  public final static int CHIEFTAIN_B = 26;
  public final static int SHAMAN_A = 27;
  public final static int SHAMAN_B = 28;

  public static String nameOf(int value) {
    if (value == 29) return "AppearanceTypeBugbear.A";
    if (value == 30) return "AppearanceTypeBugbear.B";
    if (value == 25) return "AppearanceTypeBugbear.CHIEFTAIN_A";
    if (value == 26) return "AppearanceTypeBugbear.CHIEFTAIN_B";
    if (value == 27) return "AppearanceTypeBugbear.SHAMAN_A";
    if (value == 28) return "AppearanceTypeBugbear.SHAMAN_B";
    return "AppearanceTypeBugbear.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeBugbear.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeBugbear.(not found: " + value + ")";
  }
}
