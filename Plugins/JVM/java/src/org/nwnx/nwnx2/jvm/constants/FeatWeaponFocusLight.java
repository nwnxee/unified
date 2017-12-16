package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_FOCUS_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponFocusLight {
  private FeatWeaponFocusLight() {}

  public final static int CROSSBOW = 93;
  public final static int FLAIL = 114;
  public final static int HAMMER = 113;
  public final static int MACE = 94;

  public static String nameOf(int value) {
    if (value == 93) return "FeatWeaponFocusLight.CROSSBOW";
    if (value == 114) return "FeatWeaponFocusLight.FLAIL";
    if (value == 113) return "FeatWeaponFocusLight.HAMMER";
    if (value == 94) return "FeatWeaponFocusLight.MACE";
    return "FeatWeaponFocusLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponFocusLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponFocusLight.(not found: " + value + ")";
  }
}
