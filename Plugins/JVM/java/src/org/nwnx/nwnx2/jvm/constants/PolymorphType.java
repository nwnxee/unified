package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphType {
  private PolymorphType() {}

  public final static int ANCIENT_BLUE_DRAGON = 71;
  public final static int ANCIENT_GREEN_DRAGON = 73;
  public final static int ANCIENT_RED_DRAGON = 72;
  public final static int BADGER = 25;
  public final static int BALOR = 10;
  public final static int BASILISK = 61;
  public final static int BEHOLDER = 63;
  public final static int BOAR = 24;
  public final static int BROWN_BEAR = 21;
  public final static int CELESTIAL_AVENGER = 38;
  public final static int CHICKEN = 40;
  public final static int COW = 27;
  public final static int DEATH_SLAAD = 11;
  public final static int DIRETIGER = 69;
  public final static int DIRE_BADGER = 37;
  public final static int DIRE_BOAR = 36;
  public final static int DIRE_BROWN_BEAR = 33;
  public final static int DIRE_PANTHER = 34;
  public final static int DIRE_WOLF = 35;
  public final static int DOOM_KNIGHT = 28;
  public final static int DRIDER = 62;
  public final static int ELDER_AIR_ELEMENTAL = 20;
  public final static int ELDER_EARTH_ELEMENTAL = 19;
  public final static int ELDER_FIRE_ELEMENTAL = 17;
  public final static int ELDER_WATER_ELEMENTAL = 18;
  public final static int FEMALE_DROW = 70;
  public final static int FIRE_GIANT = 9;
  public final static int FROST_GIANT_FEMALE = 42;
  public final static int FROST_GIANT_MALE = 41;
  public final static int GARGOYLE = 65;
  public final static int GIANT_SPIDER = 3;
  public final static int GOLEM_AUTOMATON = 57;
  public final static int HARPY = 60;
  public final static int HEURODIS = 43;
  public final static int HUGE_AIR_ELEMENTAL = 16;
  public final static int HUGE_EARTH_ELEMENTAL = 15;
  public final static int HUGE_FIRE_ELEMENTAL = 13;
  public final static int HUGE_WATER_ELEMENTAL = 14;
  public final static int IMP = 30;
  public final static int IRON_GOLEM = 12;
  public final static int JNAH_GIANT_FEMAL = 45;
  public final static int JNAH_GIANT_MALE = 44;
  public final static int MALE_DROW = 59;
  public final static int MANTICORE = 58;
  public final static int MEDUSA = 64;
  public final static int MINDFLAYER = 68;
  public final static int MINOTAUR = 66;
  public final static int NULL_HUMAN = 78;
  public final static int PANTHER = 22;
  public final static int PENGUIN = 26;
  public final static int PIXIE = 6;
  public final static int QUASIT = 31;
  public final static int RED_DRAGON = 8;
  public final static int RISEN_LORD = 75;
  public final static int SPECTRE = 76;
  public final static int SUCCUBUS = 32;
  public final static int SUPER_CHICKEN = 67;
  public final static int TROLL = 4;
  public final static int UMBER_HULK = 5;
  public final static int VAMPIRE_FEMALE = 77;
  public final static int VAMPIRE_MALE = 74;
  public final static int VROCK = 39;
  public final static int WERECAT = 2;
  public final static int WERERAT = 1;
  public final static int WEREWOLF = 0;
  public final static int WOLF = 23;
  public final static int WYRMLING_BLACK = 56;
  public final static int WYRMLING_BLUE = 53;
  public final static int WYRMLING_GREEN = 55;
  public final static int WYRMLING_RED = 54;
  public final static int WYRMLING_WHITE = 52;
  public final static int YUANTI = 29;
  public final static int ZOMBIE = 7;

  public static String nameOf(int value) {
    if (value == 71) return "PolymorphType.ANCIENT_BLUE_DRAGON";
    if (value == 73) return "PolymorphType.ANCIENT_GREEN_DRAGON";
    if (value == 72) return "PolymorphType.ANCIENT_RED_DRAGON";
    if (value == 25) return "PolymorphType.BADGER";
    if (value == 10) return "PolymorphType.BALOR";
    if (value == 61) return "PolymorphType.BASILISK";
    if (value == 63) return "PolymorphType.BEHOLDER";
    if (value == 24) return "PolymorphType.BOAR";
    if (value == 21) return "PolymorphType.BROWN_BEAR";
    if (value == 38) return "PolymorphType.CELESTIAL_AVENGER";
    if (value == 40) return "PolymorphType.CHICKEN";
    if (value == 27) return "PolymorphType.COW";
    if (value == 11) return "PolymorphType.DEATH_SLAAD";
    if (value == 69) return "PolymorphType.DIRETIGER";
    if (value == 37) return "PolymorphType.DIRE_BADGER";
    if (value == 36) return "PolymorphType.DIRE_BOAR";
    if (value == 33) return "PolymorphType.DIRE_BROWN_BEAR";
    if (value == 34) return "PolymorphType.DIRE_PANTHER";
    if (value == 35) return "PolymorphType.DIRE_WOLF";
    if (value == 28) return "PolymorphType.DOOM_KNIGHT";
    if (value == 62) return "PolymorphType.DRIDER";
    if (value == 20) return "PolymorphType.ELDER_AIR_ELEMENTAL";
    if (value == 19) return "PolymorphType.ELDER_EARTH_ELEMENTAL";
    if (value == 17) return "PolymorphType.ELDER_FIRE_ELEMENTAL";
    if (value == 18) return "PolymorphType.ELDER_WATER_ELEMENTAL";
    if (value == 70) return "PolymorphType.FEMALE_DROW";
    if (value == 9) return "PolymorphType.FIRE_GIANT";
    if (value == 42) return "PolymorphType.FROST_GIANT_FEMALE";
    if (value == 41) return "PolymorphType.FROST_GIANT_MALE";
    if (value == 65) return "PolymorphType.GARGOYLE";
    if (value == 3) return "PolymorphType.GIANT_SPIDER";
    if (value == 57) return "PolymorphType.GOLEM_AUTOMATON";
    if (value == 60) return "PolymorphType.HARPY";
    if (value == 43) return "PolymorphType.HEURODIS";
    if (value == 16) return "PolymorphType.HUGE_AIR_ELEMENTAL";
    if (value == 15) return "PolymorphType.HUGE_EARTH_ELEMENTAL";
    if (value == 13) return "PolymorphType.HUGE_FIRE_ELEMENTAL";
    if (value == 14) return "PolymorphType.HUGE_WATER_ELEMENTAL";
    if (value == 30) return "PolymorphType.IMP";
    if (value == 12) return "PolymorphType.IRON_GOLEM";
    if (value == 45) return "PolymorphType.JNAH_GIANT_FEMAL";
    if (value == 44) return "PolymorphType.JNAH_GIANT_MALE";
    if (value == 59) return "PolymorphType.MALE_DROW";
    if (value == 58) return "PolymorphType.MANTICORE";
    if (value == 64) return "PolymorphType.MEDUSA";
    if (value == 68) return "PolymorphType.MINDFLAYER";
    if (value == 66) return "PolymorphType.MINOTAUR";
    if (value == 78) return "PolymorphType.NULL_HUMAN";
    if (value == 22) return "PolymorphType.PANTHER";
    if (value == 26) return "PolymorphType.PENGUIN";
    if (value == 6) return "PolymorphType.PIXIE";
    if (value == 31) return "PolymorphType.QUASIT";
    if (value == 8) return "PolymorphType.RED_DRAGON";
    if (value == 75) return "PolymorphType.RISEN_LORD";
    if (value == 76) return "PolymorphType.SPECTRE";
    if (value == 32) return "PolymorphType.SUCCUBUS";
    if (value == 67) return "PolymorphType.SUPER_CHICKEN";
    if (value == 4) return "PolymorphType.TROLL";
    if (value == 5) return "PolymorphType.UMBER_HULK";
    if (value == 77) return "PolymorphType.VAMPIRE_FEMALE";
    if (value == 74) return "PolymorphType.VAMPIRE_MALE";
    if (value == 39) return "PolymorphType.VROCK";
    if (value == 2) return "PolymorphType.WERECAT";
    if (value == 1) return "PolymorphType.WERERAT";
    if (value == 0) return "PolymorphType.WEREWOLF";
    if (value == 23) return "PolymorphType.WOLF";
    if (value == 56) return "PolymorphType.WYRMLING_BLACK";
    if (value == 53) return "PolymorphType.WYRMLING_BLUE";
    if (value == 55) return "PolymorphType.WYRMLING_GREEN";
    if (value == 54) return "PolymorphType.WYRMLING_RED";
    if (value == 52) return "PolymorphType.WYRMLING_WHITE";
    if (value == 29) return "PolymorphType.YUANTI";
    if (value == 7) return "PolymorphType.ZOMBIE";
    return "PolymorphType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphType.(not found: " + value + ")";
  }
}
