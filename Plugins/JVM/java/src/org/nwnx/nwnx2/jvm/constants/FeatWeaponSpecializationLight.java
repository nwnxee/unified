package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_SPECIALIZATION_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponSpecializationLight {
  private FeatWeaponSpecializationLight() {}

  public final static int CROSSBOW = 131;
  public final static int FLAIL = 152;
  public final static int HAMMER = 151;
  public final static int MACE = 132;

  public static String nameOf(int value) {
    if (value == 131) return "FeatWeaponSpecializationLight.CROSSBOW";
    if (value == 152) return "FeatWeaponSpecializationLight.FLAIL";
    if (value == 151) return "FeatWeaponSpecializationLight.HAMMER";
    if (value == 132) return "FeatWeaponSpecializationLight.MACE";
    return "FeatWeaponSpecializationLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponSpecializationLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponSpecializationLight.(not found: " + value + ")";
  }
}
