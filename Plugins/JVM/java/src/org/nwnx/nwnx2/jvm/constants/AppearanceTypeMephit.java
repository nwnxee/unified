package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_MEPHIT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeMephit {
  private AppearanceTypeMephit() {}

  public final static int AIR = 106;
  public final static int DUST = 107;
  public final static int EARTH = 108;
  public final static int FIRE = 109;
  public final static int ICE = 110;
  public final static int MAGMA = 114;
  public final static int OOZE = 112;
  public final static int SALT = 111;
  public final static int STEAM = 113;
  public final static int WATER = 115;

  public static String nameOf(int value) {
    if (value == 106) return "AppearanceTypeMephit.AIR";
    if (value == 107) return "AppearanceTypeMephit.DUST";
    if (value == 108) return "AppearanceTypeMephit.EARTH";
    if (value == 109) return "AppearanceTypeMephit.FIRE";
    if (value == 110) return "AppearanceTypeMephit.ICE";
    if (value == 114) return "AppearanceTypeMephit.MAGMA";
    if (value == 112) return "AppearanceTypeMephit.OOZE";
    if (value == 111) return "AppearanceTypeMephit.SALT";
    if (value == 113) return "AppearanceTypeMephit.STEAM";
    if (value == 115) return "AppearanceTypeMephit.WATER";
    return "AppearanceTypeMephit.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeMephit.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeMephit.(not found: " + value + ")";
  }
}
