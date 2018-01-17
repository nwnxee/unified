package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ZOMBIE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeZombie {
  private AppearanceTypeZombie() {}

  public final static int APPEARANCE_TYPE_ZOMBIE = 198;
  public final static int ROTTING = 195;
  public final static int TYRANT_FOG = 199;
  public final static int WARRIOR_1 = 196;
  public final static int WARRIOR_2 = 197;

  public static String nameOf(int value) {
    if (value == 198) return "AppearanceTypeZombie.APPEARANCE_TYPE_ZOMBIE";
    if (value == 195) return "AppearanceTypeZombie.ROTTING";
    if (value == 199) return "AppearanceTypeZombie.TYRANT_FOG";
    if (value == 196) return "AppearanceTypeZombie.WARRIOR_1";
    if (value == 197) return "AppearanceTypeZombie.WARRIOR_2";
    return "AppearanceTypeZombie.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeZombie.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeZombie.(not found: " + value + ")";
  }
}
