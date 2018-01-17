package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_IMPROVED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatImproved {
  private FeatImproved() {}

  public final static int CRITICAL_BASTARD_SWORD = 85;
  public final static int CRITICAL_BATTLE_AXE = 72;
  public final static int CRITICAL_CLUB = 15;
  public final static int CRITICAL_CREATURE = 292;
  public final static int CRITICAL_DAGGER = 52;
  public final static int CRITICAL_DART = 53;
  public final static int CRITICAL_DIRE_MACE = 87;
  public final static int CRITICAL_DOUBLE_AXE = 88;
  public final static int CRITICAL_DWAXE = 954;
  public final static int CRITICAL_GREAT_AXE = 73;
  public final static int CRITICAL_GREAT_SWORD = 69;
  public final static int CRITICAL_HALBERD = 74;
  public final static int CRITICAL_HAND_AXE = 70;
  public final static int CRITICAL_HEAVY_CROSSBOW = 54;
  public final static int CRITICAL_HEAVY_FLAIL = 78;
  public final static int CRITICAL_KAMA = 79;
  public final static int CRITICAL_KATANA = 84;
  public final static int CRITICAL_KUKRI = 80;
  public final static int CRITICAL_LIGHT_CROSSBOW = 55;
  public final static int CRITICAL_LIGHT_FLAIL = 76;
  public final static int CRITICAL_LIGHT_HAMMER = 75;
  public final static int CRITICAL_LIGHT_MACE = 56;
  public final static int CRITICAL_LONGBOW = 63;
  public final static int CRITICAL_LONG_SWORD = 68;
  public final static int CRITICAL_MORNING_STAR = 57;
  public final static int CRITICAL_RAPIER = 66;
  public final static int CRITICAL_SCIMITAR = 67;
  public final static int CRITICAL_SCYTHE = 83;
  public final static int CRITICAL_SHORTBOW = 64;
  public final static int CRITICAL_SHORT_SWORD = 65;
  public final static int CRITICAL_SHURIKEN = 82;
  public final static int CRITICAL_SICKLE = 60;
  public final static int CRITICAL_SLING = 61;
  public final static int CRITICAL_SPEAR = 59;
  public final static int CRITICAL_STAFF = 58;
  public final static int CRITICAL_THROWING_AXE = 71;
  public final static int CRITICAL_TRIDENT = 1074;
  public final static int CRITICAL_TWO_BLADED_SWORD = 89;
  public final static int CRITICAL_UNARMED_STRIKE = 62;
  public final static int CRITICAL_WAR_HAMMER = 77;
  public final static int CRITICAL_WHIP = 995;
  public final static int DISARM = 16;
  public final static int EVASION = 212;
  public final static int EXPERTISE = 390;
  public final static int INITIATIVE = 377;
  public final static int KNOCKDOWN = 17;
  public final static int PARRY = 18;
  public final static int POWER_ATTACK = 19;
  public final static int TWO_WEAPON_FIGHTING = 20;
  public final static int UNARMED_STRIKE = 21;
  public final static int WHIRLWIND = 868;

  public static String nameOf(int value) {
    if (value == 85) return "FeatImproved.CRITICAL_BASTARD_SWORD";
    if (value == 72) return "FeatImproved.CRITICAL_BATTLE_AXE";
    if (value == 15) return "FeatImproved.CRITICAL_CLUB";
    if (value == 292) return "FeatImproved.CRITICAL_CREATURE";
    if (value == 52) return "FeatImproved.CRITICAL_DAGGER";
    if (value == 53) return "FeatImproved.CRITICAL_DART";
    if (value == 87) return "FeatImproved.CRITICAL_DIRE_MACE";
    if (value == 88) return "FeatImproved.CRITICAL_DOUBLE_AXE";
    if (value == 954) return "FeatImproved.CRITICAL_DWAXE";
    if (value == 73) return "FeatImproved.CRITICAL_GREAT_AXE";
    if (value == 69) return "FeatImproved.CRITICAL_GREAT_SWORD";
    if (value == 74) return "FeatImproved.CRITICAL_HALBERD";
    if (value == 70) return "FeatImproved.CRITICAL_HAND_AXE";
    if (value == 54) return "FeatImproved.CRITICAL_HEAVY_CROSSBOW";
    if (value == 78) return "FeatImproved.CRITICAL_HEAVY_FLAIL";
    if (value == 79) return "FeatImproved.CRITICAL_KAMA";
    if (value == 84) return "FeatImproved.CRITICAL_KATANA";
    if (value == 80) return "FeatImproved.CRITICAL_KUKRI";
    if (value == 55) return "FeatImproved.CRITICAL_LIGHT_CROSSBOW";
    if (value == 76) return "FeatImproved.CRITICAL_LIGHT_FLAIL";
    if (value == 75) return "FeatImproved.CRITICAL_LIGHT_HAMMER";
    if (value == 56) return "FeatImproved.CRITICAL_LIGHT_MACE";
    if (value == 63) return "FeatImproved.CRITICAL_LONGBOW";
    if (value == 68) return "FeatImproved.CRITICAL_LONG_SWORD";
    if (value == 57) return "FeatImproved.CRITICAL_MORNING_STAR";
    if (value == 66) return "FeatImproved.CRITICAL_RAPIER";
    if (value == 67) return "FeatImproved.CRITICAL_SCIMITAR";
    if (value == 83) return "FeatImproved.CRITICAL_SCYTHE";
    if (value == 64) return "FeatImproved.CRITICAL_SHORTBOW";
    if (value == 65) return "FeatImproved.CRITICAL_SHORT_SWORD";
    if (value == 82) return "FeatImproved.CRITICAL_SHURIKEN";
    if (value == 60) return "FeatImproved.CRITICAL_SICKLE";
    if (value == 61) return "FeatImproved.CRITICAL_SLING";
    if (value == 59) return "FeatImproved.CRITICAL_SPEAR";
    if (value == 58) return "FeatImproved.CRITICAL_STAFF";
    if (value == 71) return "FeatImproved.CRITICAL_THROWING_AXE";
    if (value == 1074) return "FeatImproved.CRITICAL_TRIDENT";
    if (value == 89) return "FeatImproved.CRITICAL_TWO_BLADED_SWORD";
    if (value == 62) return "FeatImproved.CRITICAL_UNARMED_STRIKE";
    if (value == 77) return "FeatImproved.CRITICAL_WAR_HAMMER";
    if (value == 995) return "FeatImproved.CRITICAL_WHIP";
    if (value == 16) return "FeatImproved.DISARM";
    if (value == 212) return "FeatImproved.EVASION";
    if (value == 390) return "FeatImproved.EXPERTISE";
    if (value == 377) return "FeatImproved.INITIATIVE";
    if (value == 17) return "FeatImproved.KNOCKDOWN";
    if (value == 18) return "FeatImproved.PARRY";
    if (value == 19) return "FeatImproved.POWER_ATTACK";
    if (value == 20) return "FeatImproved.TWO_WEAPON_FIGHTING";
    if (value == 21) return "FeatImproved.UNARMED_STRIKE";
    if (value == 868) return "FeatImproved.WHIRLWIND";
    return "FeatImproved.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatImproved.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatImproved.(not found: " + value + ")";
  }
}
