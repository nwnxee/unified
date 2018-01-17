package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CLASS_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ClassType {
  private ClassType() {}

  public final static int ABERRATION = 11;
  public final static int ANIMAL = 12;
  public final static int ARCANE_ARCHER = 29;
  public final static int ASSASSIN = 30;
  public final static int BARBARIAN = 0;
  public final static int BARD = 1;
  public final static int BEAST = 21;
  public final static int BLACKGUARD = 31;
  public final static int CLERIC = 2;
  public final static int COMMONER = 20;
  public final static int CONSTRUCT = 13;
  public final static int DIVINECHAMPION = 32;
  public final static int DIVINE_CHAMPION = 32;
  public final static int DRAGON = 18;
  public final static int DRAGONDISCIPLE = 37;
  public final static int DRAGON_DISCIPLE = 37;
  public final static int DRUID = 3;
  public final static int DWARVENDEFENDER = 36;
  public final static int DWARVEN_DEFENDER = 36;
  public final static int ELEMENTAL = 16;
  public final static int EYE_OF_GRUUMSH = 39;
  public final static int FEY = 17;
  public final static int FIGHTER = 4;
  public final static int GIANT = 22;
  public final static int HARPER = 28;
  public final static int HUMANOID = 14;
  public final static int INVALID = 255;
  public final static int MAGICAL_BEAST = 23;
  public final static int MONK = 5;
  public final static int MONSTROUS = 15;
  public final static int OOZE = 38;
  public final static int OUTSIDER = 24;
  public final static int PALADIN = 6;
  public final static int PALEMASTER = 34;
  public final static int PALE_MASTER = 34;
  public final static int PURPLE_DRAGON_KNIGHT = 41;
  public final static int RANGER = 7;
  public final static int ROGUE = 8;
  public final static int SHADOWDANCER = 27;
  public final static int SHAPECHANGER = 25;
  public final static int SHIFTER = 35;
  public final static int SHOU_DISCIPLE = 40;
  public final static int SORCERER = 9;
  public final static int UNDEAD = 19;
  public final static int VERMIN = 26;
  public final static int WEAPON_MASTER = 33;
  public final static int WIZARD = 10;

  public static String nameOf(int value) {
    if (value == 11) return "ClassType.ABERRATION";
    if (value == 12) return "ClassType.ANIMAL";
    if (value == 29) return "ClassType.ARCANE_ARCHER";
    if (value == 30) return "ClassType.ASSASSIN";
    if (value == 0) return "ClassType.BARBARIAN";
    if (value == 1) return "ClassType.BARD";
    if (value == 21) return "ClassType.BEAST";
    if (value == 31) return "ClassType.BLACKGUARD";
    if (value == 2) return "ClassType.CLERIC";
    if (value == 20) return "ClassType.COMMONER";
    if (value == 13) return "ClassType.CONSTRUCT";
    if (value == 32) return "ClassType.DIVINECHAMPION";
    if (value == 32) return "ClassType.DIVINE_CHAMPION";
    if (value == 18) return "ClassType.DRAGON";
    if (value == 37) return "ClassType.DRAGONDISCIPLE";
    if (value == 37) return "ClassType.DRAGON_DISCIPLE";
    if (value == 3) return "ClassType.DRUID";
    if (value == 36) return "ClassType.DWARVENDEFENDER";
    if (value == 36) return "ClassType.DWARVEN_DEFENDER";
    if (value == 16) return "ClassType.ELEMENTAL";
    if (value == 39) return "ClassType.EYE_OF_GRUUMSH";
    if (value == 17) return "ClassType.FEY";
    if (value == 4) return "ClassType.FIGHTER";
    if (value == 22) return "ClassType.GIANT";
    if (value == 28) return "ClassType.HARPER";
    if (value == 14) return "ClassType.HUMANOID";
    if (value == 255) return "ClassType.INVALID";
    if (value == 23) return "ClassType.MAGICAL_BEAST";
    if (value == 5) return "ClassType.MONK";
    if (value == 15) return "ClassType.MONSTROUS";
    if (value == 38) return "ClassType.OOZE";
    if (value == 24) return "ClassType.OUTSIDER";
    if (value == 6) return "ClassType.PALADIN";
    if (value == 34) return "ClassType.PALEMASTER";
    if (value == 34) return "ClassType.PALE_MASTER";
    if (value == 41) return "ClassType.PURPLE_DRAGON_KNIGHT";
    if (value == 7) return "ClassType.RANGER";
    if (value == 8) return "ClassType.ROGUE";
    if (value == 27) return "ClassType.SHADOWDANCER";
    if (value == 25) return "ClassType.SHAPECHANGER";
    if (value == 35) return "ClassType.SHIFTER";
    if (value == 40) return "ClassType.SHOU_DISCIPLE";
    if (value == 9) return "ClassType.SORCERER";
    if (value == 19) return "ClassType.UNDEAD";
    if (value == 26) return "ClassType.VERMIN";
    if (value == 33) return "ClassType.WEAPON_MASTER";
    if (value == 10) return "ClassType.WIZARD";
    return "ClassType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ClassType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ClassType.(not found: " + value + ")";
  }
}
