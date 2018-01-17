package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_GIANT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeGiant {
  private AppearanceTypeGiant() {}

  public final static int FIRE = 80;
  public final static int FIRE_FEMALE = 351;
  public final static int FROST = 81;
  public final static int FROST_FEMALE = 350;
  public final static int HILL = 78;
  public final static int MOUNTAIN = 79;

  public static String nameOf(int value) {
    if (value == 80) return "AppearanceTypeGiant.FIRE";
    if (value == 351) return "AppearanceTypeGiant.FIRE_FEMALE";
    if (value == 81) return "AppearanceTypeGiant.FROST";
    if (value == 350) return "AppearanceTypeGiant.FROST_FEMALE";
    if (value == 78) return "AppearanceTypeGiant.HILL";
    if (value == 79) return "AppearanceTypeGiant.MOUNTAIN";
    return "AppearanceTypeGiant.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeGiant.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeGiant.(not found: " + value + ")";
  }
}
