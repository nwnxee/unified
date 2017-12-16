package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CLASS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Class {
  private Class() {}

  public final static int TYPE_ABERRATION = 11;
  public final static int TYPE_ANIMAL = 12;
  public final static int TYPE_ARCANE_ARCHER = 29;
  public final static int TYPE_ASSASSIN = 30;
  public final static int TYPE_BARBARIAN = 0;
  public final static int TYPE_BARD = 1;
  public final static int TYPE_BEAST = 21;
  public final static int TYPE_BLACKGUARD = 31;
  public final static int TYPE_CLERIC = 2;
  public final static int TYPE_COMMONER = 20;
  public final static int TYPE_CONSTRUCT = 13;
  public final static int TYPE_DIVINECHAMPION = 32;
  public final static int TYPE_DIVINE_CHAMPION = 32;
  public final static int TYPE_DRAGON = 18;
  public final static int TYPE_DRAGONDISCIPLE = 37;
  public final static int TYPE_DRAGON_DISCIPLE = 37;
  public final static int TYPE_DRUID = 3;
  public final static int TYPE_DWARVENDEFENDER = 36;
  public final static int TYPE_DWARVEN_DEFENDER = 36;
  public final static int TYPE_ELEMENTAL = 16;
  public final static int TYPE_EYE_OF_GRUUMSH = 39;
  public final static int TYPE_FEY = 17;
  public final static int TYPE_FIGHTER = 4;
  public final static int TYPE_GIANT = 22;
  public final static int TYPE_HARPER = 28;
  public final static int TYPE_HUMANOID = 14;
  public final static int TYPE_INVALID = 255;
  public final static int TYPE_MAGICAL_BEAST = 23;
  public final static int TYPE_MONK = 5;
  public final static int TYPE_MONSTROUS = 15;
  public final static int TYPE_OOZE = 38;
  public final static int TYPE_OUTSIDER = 24;
  public final static int TYPE_PALADIN = 6;
  public final static int TYPE_PALEMASTER = 34;
  public final static int TYPE_PALE_MASTER = 34;
  public final static int TYPE_PURPLE_DRAGON_KNIGHT = 41;
  public final static int TYPE_RANGER = 7;
  public final static int TYPE_ROGUE = 8;
  public final static int TYPE_SHADOWDANCER = 27;
  public final static int TYPE_SHAPECHANGER = 25;
  public final static int TYPE_SHIFTER = 35;
  public final static int TYPE_SHOU_DISCIPLE = 40;
  public final static int TYPE_SORCERER = 9;
  public final static int TYPE_UNDEAD = 19;
  public final static int TYPE_VERMIN = 26;
  public final static int TYPE_WEAPON_MASTER = 33;
  public final static int TYPE_WIZARD = 10;

  public static String nameOf(int value) {
    if (value == 11) return "Class.TYPE_ABERRATION";
    if (value == 12) return "Class.TYPE_ANIMAL";
    if (value == 29) return "Class.TYPE_ARCANE_ARCHER";
    if (value == 30) return "Class.TYPE_ASSASSIN";
    if (value == 0) return "Class.TYPE_BARBARIAN";
    if (value == 1) return "Class.TYPE_BARD";
    if (value == 21) return "Class.TYPE_BEAST";
    if (value == 31) return "Class.TYPE_BLACKGUARD";
    if (value == 2) return "Class.TYPE_CLERIC";
    if (value == 20) return "Class.TYPE_COMMONER";
    if (value == 13) return "Class.TYPE_CONSTRUCT";
    if (value == 32) return "Class.TYPE_DIVINECHAMPION";
    if (value == 32) return "Class.TYPE_DIVINE_CHAMPION";
    if (value == 18) return "Class.TYPE_DRAGON";
    if (value == 37) return "Class.TYPE_DRAGONDISCIPLE";
    if (value == 37) return "Class.TYPE_DRAGON_DISCIPLE";
    if (value == 3) return "Class.TYPE_DRUID";
    if (value == 36) return "Class.TYPE_DWARVENDEFENDER";
    if (value == 36) return "Class.TYPE_DWARVEN_DEFENDER";
    if (value == 16) return "Class.TYPE_ELEMENTAL";
    if (value == 39) return "Class.TYPE_EYE_OF_GRUUMSH";
    if (value == 17) return "Class.TYPE_FEY";
    if (value == 4) return "Class.TYPE_FIGHTER";
    if (value == 22) return "Class.TYPE_GIANT";
    if (value == 28) return "Class.TYPE_HARPER";
    if (value == 14) return "Class.TYPE_HUMANOID";
    if (value == 255) return "Class.TYPE_INVALID";
    if (value == 23) return "Class.TYPE_MAGICAL_BEAST";
    if (value == 5) return "Class.TYPE_MONK";
    if (value == 15) return "Class.TYPE_MONSTROUS";
    if (value == 38) return "Class.TYPE_OOZE";
    if (value == 24) return "Class.TYPE_OUTSIDER";
    if (value == 6) return "Class.TYPE_PALADIN";
    if (value == 34) return "Class.TYPE_PALEMASTER";
    if (value == 34) return "Class.TYPE_PALE_MASTER";
    if (value == 41) return "Class.TYPE_PURPLE_DRAGON_KNIGHT";
    if (value == 7) return "Class.TYPE_RANGER";
    if (value == 8) return "Class.TYPE_ROGUE";
    if (value == 27) return "Class.TYPE_SHADOWDANCER";
    if (value == 25) return "Class.TYPE_SHAPECHANGER";
    if (value == 35) return "Class.TYPE_SHIFTER";
    if (value == 40) return "Class.TYPE_SHOU_DISCIPLE";
    if (value == 9) return "Class.TYPE_SORCERER";
    if (value == 19) return "Class.TYPE_UNDEAD";
    if (value == 26) return "Class.TYPE_VERMIN";
    if (value == 33) return "Class.TYPE_WEAPON_MASTER";
    if (value == 10) return "Class.TYPE_WIZARD";
    return "Class.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Class.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Class.(not found: " + value + ")";
  }
}
