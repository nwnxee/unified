package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_GNOME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeGnome {
  private AppearanceTypeGnome() {}

  public final static int APPEARANCE_TYPE_GNOME = 2;
  public final static int NPC_FEMALE = 243;
  public final static int NPC_MALE = 244;

  public static String nameOf(int value) {
    if (value == 2) return "AppearanceTypeGnome.APPEARANCE_TYPE_GNOME";
    if (value == 243) return "AppearanceTypeGnome.NPC_FEMALE";
    if (value == 244) return "AppearanceTypeGnome.NPC_MALE";
    return "AppearanceTypeGnome.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeGnome.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeGnome.(not found: " + value + ")";
  }
}
