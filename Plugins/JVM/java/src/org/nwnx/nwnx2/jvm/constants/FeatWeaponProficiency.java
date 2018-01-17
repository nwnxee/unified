package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_PROFICIENCY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponProficiency {
  private FeatWeaponProficiency() {}

  public final static int CREATURE = 289;
  public final static int DRUID = 48;
  public final static int ELF = 256;
  public final static int EXOTIC = 44;
  public final static int MARTIAL = 45;
  public final static int MONK = 49;
  public final static int ROGUE = 50;
  public final static int SIMPLE = 46;
  public final static int WIZARD = 51;

  public static String nameOf(int value) {
    if (value == 289) return "FeatWeaponProficiency.CREATURE";
    if (value == 48) return "FeatWeaponProficiency.DRUID";
    if (value == 256) return "FeatWeaponProficiency.ELF";
    if (value == 44) return "FeatWeaponProficiency.EXOTIC";
    if (value == 45) return "FeatWeaponProficiency.MARTIAL";
    if (value == 49) return "FeatWeaponProficiency.MONK";
    if (value == 50) return "FeatWeaponProficiency.ROGUE";
    if (value == 46) return "FeatWeaponProficiency.SIMPLE";
    if (value == 51) return "FeatWeaponProficiency.WIZARD";
    return "FeatWeaponProficiency.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponProficiency.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponProficiency.(not found: " + value + ")";
  }
}
