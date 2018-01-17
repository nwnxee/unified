package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ELEMENTAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeElemental {
  private AppearanceTypeElemental() {}

  public final static int AIR = 52;
  public final static int AIR_ELDER = 53;
  public final static int EARTH = 56;
  public final static int EARTH_ELDER = 57;
  public final static int FIRE = 60;
  public final static int FIRE_ELDER = 61;
  public final static int WATER = 69;
  public final static int WATER_ELDER = 68;

  public static String nameOf(int value) {
    if (value == 52) return "AppearanceTypeElemental.AIR";
    if (value == 53) return "AppearanceTypeElemental.AIR_ELDER";
    if (value == 56) return "AppearanceTypeElemental.EARTH";
    if (value == 57) return "AppearanceTypeElemental.EARTH_ELDER";
    if (value == 60) return "AppearanceTypeElemental.FIRE";
    if (value == 61) return "AppearanceTypeElemental.FIRE_ELDER";
    if (value == 69) return "AppearanceTypeElemental.WATER";
    if (value == 68) return "AppearanceTypeElemental.WATER_ELDER";
    return "AppearanceTypeElemental.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeElemental.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeElemental.(not found: " + value + ")";
  }
}
