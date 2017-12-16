package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_LIZARDFOLK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeLizardfolk {
  private AppearanceTypeLizardfolk() {}

  public final static int A = 134;
  public final static int B = 135;
  public final static int SHAMAN_A = 132;
  public final static int SHAMAN_B = 133;
  public final static int WARRIOR_A = 130;
  public final static int WARRIOR_B = 131;

  public static String nameOf(int value) {
    if (value == 134) return "AppearanceTypeLizardfolk.A";
    if (value == 135) return "AppearanceTypeLizardfolk.B";
    if (value == 132) return "AppearanceTypeLizardfolk.SHAMAN_A";
    if (value == 133) return "AppearanceTypeLizardfolk.SHAMAN_B";
    if (value == 130) return "AppearanceTypeLizardfolk.WARRIOR_A";
    if (value == 131) return "AppearanceTypeLizardfolk.WARRIOR_B";
    return "AppearanceTypeLizardfolk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeLizardfolk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeLizardfolk.(not found: " + value + ")";
  }
}
