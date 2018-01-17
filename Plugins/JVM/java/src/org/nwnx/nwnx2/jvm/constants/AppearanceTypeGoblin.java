package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_GOBLIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeGoblin {
  private AppearanceTypeGoblin() {}

  public final static int A = 86;
  public final static int B = 87;
  public final static int CHIEF_A = 82;
  public final static int CHIEF_B = 83;
  public final static int SHAMAN_A = 84;
  public final static int SHAMAN_B = 85;

  public static String nameOf(int value) {
    if (value == 86) return "AppearanceTypeGoblin.A";
    if (value == 87) return "AppearanceTypeGoblin.B";
    if (value == 82) return "AppearanceTypeGoblin.CHIEF_A";
    if (value == 83) return "AppearanceTypeGoblin.CHIEF_B";
    if (value == 84) return "AppearanceTypeGoblin.SHAMAN_A";
    if (value == 85) return "AppearanceTypeGoblin.SHAMAN_B";
    return "AppearanceTypeGoblin.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeGoblin.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeGoblin.(not found: " + value + ")";
  }
}
