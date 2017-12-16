package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_WEAPON_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatWeaponFocus {
  private FeatWeaponFocus() {}

  public final static int BASTARD_SWORD = 123;
  public final static int BATTLE_AXE = 110;
  public final static int CLUB = 43;
  public final static int CREATURE = 291;
  public final static int DAGGER = 90;
  public final static int DART = 91;
  public final static int DIRE_MACE = 125;
  public final static int DOUBLE_AXE = 126;
  public final static int DWAXE = 952;
  public final static int GREAT_AXE = 111;
  public final static int GREAT_SWORD = 107;
  public final static int HALBERD = 112;
  public final static int HAND_AXE = 108;
  public final static int HEAVY_CROSSBOW = 92;
  public final static int HEAVY_FLAIL = 116;
  public final static int KAMA = 117;
  public final static int KATANA = 122;
  public final static int KUKRI = 118;
  public final static int LIGHT_CROSSBOW = 93;
  public final static int LIGHT_FLAIL = 114;
  public final static int LIGHT_HAMMER = 113;
  public final static int LIGHT_MACE = 94;
  public final static int LONGBOW = 101;
  public final static int LONG_SWORD = 106;
  public final static int MORNING_STAR = 95;
  public final static int RAPIER = 104;
  public final static int SCIMITAR = 105;
  public final static int SCYTHE = 121;
  public final static int SHORTBOW = 102;
  public final static int SHORT_SWORD = 103;
  public final static int SHURIKEN = 120;
  public final static int SICKLE = 98;
  public final static int SLING = 99;
  public final static int SPEAR = 97;
  public final static int STAFF = 96;
  public final static int THROWING_AXE = 109;
  public final static int TRIDENT = 1072;
  public final static int TWO_BLADED_SWORD = 127;
  public final static int UNARMED_STRIKE = 100;
  public final static int WAR_HAMMER = 115;
  public final static int WHIP = 993;

  public static String nameOf(int value) {
    if (value == 123) return "FeatWeaponFocus.BASTARD_SWORD";
    if (value == 110) return "FeatWeaponFocus.BATTLE_AXE";
    if (value == 43) return "FeatWeaponFocus.CLUB";
    if (value == 291) return "FeatWeaponFocus.CREATURE";
    if (value == 90) return "FeatWeaponFocus.DAGGER";
    if (value == 91) return "FeatWeaponFocus.DART";
    if (value == 125) return "FeatWeaponFocus.DIRE_MACE";
    if (value == 126) return "FeatWeaponFocus.DOUBLE_AXE";
    if (value == 952) return "FeatWeaponFocus.DWAXE";
    if (value == 111) return "FeatWeaponFocus.GREAT_AXE";
    if (value == 107) return "FeatWeaponFocus.GREAT_SWORD";
    if (value == 112) return "FeatWeaponFocus.HALBERD";
    if (value == 108) return "FeatWeaponFocus.HAND_AXE";
    if (value == 92) return "FeatWeaponFocus.HEAVY_CROSSBOW";
    if (value == 116) return "FeatWeaponFocus.HEAVY_FLAIL";
    if (value == 117) return "FeatWeaponFocus.KAMA";
    if (value == 122) return "FeatWeaponFocus.KATANA";
    if (value == 118) return "FeatWeaponFocus.KUKRI";
    if (value == 93) return "FeatWeaponFocus.LIGHT_CROSSBOW";
    if (value == 114) return "FeatWeaponFocus.LIGHT_FLAIL";
    if (value == 113) return "FeatWeaponFocus.LIGHT_HAMMER";
    if (value == 94) return "FeatWeaponFocus.LIGHT_MACE";
    if (value == 101) return "FeatWeaponFocus.LONGBOW";
    if (value == 106) return "FeatWeaponFocus.LONG_SWORD";
    if (value == 95) return "FeatWeaponFocus.MORNING_STAR";
    if (value == 104) return "FeatWeaponFocus.RAPIER";
    if (value == 105) return "FeatWeaponFocus.SCIMITAR";
    if (value == 121) return "FeatWeaponFocus.SCYTHE";
    if (value == 102) return "FeatWeaponFocus.SHORTBOW";
    if (value == 103) return "FeatWeaponFocus.SHORT_SWORD";
    if (value == 120) return "FeatWeaponFocus.SHURIKEN";
    if (value == 98) return "FeatWeaponFocus.SICKLE";
    if (value == 99) return "FeatWeaponFocus.SLING";
    if (value == 97) return "FeatWeaponFocus.SPEAR";
    if (value == 96) return "FeatWeaponFocus.STAFF";
    if (value == 109) return "FeatWeaponFocus.THROWING_AXE";
    if (value == 1072) return "FeatWeaponFocus.TRIDENT";
    if (value == 127) return "FeatWeaponFocus.TWO_BLADED_SWORD";
    if (value == 100) return "FeatWeaponFocus.UNARMED_STRIKE";
    if (value == 115) return "FeatWeaponFocus.WAR_HAMMER";
    if (value == 993) return "FeatWeaponFocus.WHIP";
    return "FeatWeaponFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatWeaponFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatWeaponFocus.(not found: " + value + ")";
  }
}
