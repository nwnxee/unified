package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Polymorph {
  private Polymorph() {}

  public final static int TYPE_ANCIENT_BLUE_DRAGON = 71;
  public final static int TYPE_ANCIENT_GREEN_DRAGON = 73;
  public final static int TYPE_ANCIENT_RED_DRAGON = 72;
  public final static int TYPE_BADGER = 25;
  public final static int TYPE_BALOR = 10;
  public final static int TYPE_BASILISK = 61;
  public final static int TYPE_BEHOLDER = 63;
  public final static int TYPE_BOAR = 24;
  public final static int TYPE_BROWN_BEAR = 21;
  public final static int TYPE_CELESTIAL_AVENGER = 38;
  public final static int TYPE_CHICKEN = 40;
  public final static int TYPE_COW = 27;
  public final static int TYPE_DEATH_SLAAD = 11;
  public final static int TYPE_DIRETIGER = 69;
  public final static int TYPE_DIRE_BADGER = 37;
  public final static int TYPE_DIRE_BOAR = 36;
  public final static int TYPE_DIRE_BROWN_BEAR = 33;
  public final static int TYPE_DIRE_PANTHER = 34;
  public final static int TYPE_DIRE_WOLF = 35;
  public final static int TYPE_DOOM_KNIGHT = 28;
  public final static int TYPE_DRIDER = 62;
  public final static int TYPE_ELDER_AIR_ELEMENTAL = 20;
  public final static int TYPE_ELDER_EARTH_ELEMENTAL = 19;
  public final static int TYPE_ELDER_FIRE_ELEMENTAL = 17;
  public final static int TYPE_ELDER_WATER_ELEMENTAL = 18;
  public final static int TYPE_FEMALE_DROW = 70;
  public final static int TYPE_FIRE_GIANT = 9;
  public final static int TYPE_FROST_GIANT_FEMALE = 42;
  public final static int TYPE_FROST_GIANT_MALE = 41;
  public final static int TYPE_GARGOYLE = 65;
  public final static int TYPE_GIANT_SPIDER = 3;
  public final static int TYPE_GOLEM_AUTOMATON = 57;
  public final static int TYPE_HARPY = 60;
  public final static int TYPE_HEURODIS = 43;
  public final static int TYPE_HUGE_AIR_ELEMENTAL = 16;
  public final static int TYPE_HUGE_EARTH_ELEMENTAL = 15;
  public final static int TYPE_HUGE_FIRE_ELEMENTAL = 13;
  public final static int TYPE_HUGE_WATER_ELEMENTAL = 14;
  public final static int TYPE_IMP = 30;
  public final static int TYPE_IRON_GOLEM = 12;
  public final static int TYPE_JNAH_GIANT_FEMAL = 45;
  public final static int TYPE_JNAH_GIANT_MALE = 44;
  public final static int TYPE_MALE_DROW = 59;
  public final static int TYPE_MANTICORE = 58;
  public final static int TYPE_MEDUSA = 64;
  public final static int TYPE_MINDFLAYER = 68;
  public final static int TYPE_MINOTAUR = 66;
  public final static int TYPE_NULL_HUMAN = 78;
  public final static int TYPE_PANTHER = 22;
  public final static int TYPE_PENGUIN = 26;
  public final static int TYPE_PIXIE = 6;
  public final static int TYPE_QUASIT = 31;
  public final static int TYPE_RED_DRAGON = 8;
  public final static int TYPE_RISEN_LORD = 75;
  public final static int TYPE_SPECTRE = 76;
  public final static int TYPE_SUCCUBUS = 32;
  public final static int TYPE_SUPER_CHICKEN = 67;
  public final static int TYPE_TROLL = 4;
  public final static int TYPE_UMBER_HULK = 5;
  public final static int TYPE_VAMPIRE_FEMALE = 77;
  public final static int TYPE_VAMPIRE_MALE = 74;
  public final static int TYPE_VROCK = 39;
  public final static int TYPE_WERECAT = 2;
  public final static int TYPE_WERERAT = 1;
  public final static int TYPE_WEREWOLF = 0;
  public final static int TYPE_WOLF = 23;
  public final static int TYPE_WYRMLING_BLACK = 56;
  public final static int TYPE_WYRMLING_BLUE = 53;
  public final static int TYPE_WYRMLING_GREEN = 55;
  public final static int TYPE_WYRMLING_RED = 54;
  public final static int TYPE_WYRMLING_WHITE = 52;
  public final static int TYPE_YUANTI = 29;
  public final static int TYPE_ZOMBIE = 7;

  public static String nameOf(int value) {
    if (value == 71) return "Polymorph.TYPE_ANCIENT_BLUE_DRAGON";
    if (value == 73) return "Polymorph.TYPE_ANCIENT_GREEN_DRAGON";
    if (value == 72) return "Polymorph.TYPE_ANCIENT_RED_DRAGON";
    if (value == 25) return "Polymorph.TYPE_BADGER";
    if (value == 10) return "Polymorph.TYPE_BALOR";
    if (value == 61) return "Polymorph.TYPE_BASILISK";
    if (value == 63) return "Polymorph.TYPE_BEHOLDER";
    if (value == 24) return "Polymorph.TYPE_BOAR";
    if (value == 21) return "Polymorph.TYPE_BROWN_BEAR";
    if (value == 38) return "Polymorph.TYPE_CELESTIAL_AVENGER";
    if (value == 40) return "Polymorph.TYPE_CHICKEN";
    if (value == 27) return "Polymorph.TYPE_COW";
    if (value == 11) return "Polymorph.TYPE_DEATH_SLAAD";
    if (value == 69) return "Polymorph.TYPE_DIRETIGER";
    if (value == 37) return "Polymorph.TYPE_DIRE_BADGER";
    if (value == 36) return "Polymorph.TYPE_DIRE_BOAR";
    if (value == 33) return "Polymorph.TYPE_DIRE_BROWN_BEAR";
    if (value == 34) return "Polymorph.TYPE_DIRE_PANTHER";
    if (value == 35) return "Polymorph.TYPE_DIRE_WOLF";
    if (value == 28) return "Polymorph.TYPE_DOOM_KNIGHT";
    if (value == 62) return "Polymorph.TYPE_DRIDER";
    if (value == 20) return "Polymorph.TYPE_ELDER_AIR_ELEMENTAL";
    if (value == 19) return "Polymorph.TYPE_ELDER_EARTH_ELEMENTAL";
    if (value == 17) return "Polymorph.TYPE_ELDER_FIRE_ELEMENTAL";
    if (value == 18) return "Polymorph.TYPE_ELDER_WATER_ELEMENTAL";
    if (value == 70) return "Polymorph.TYPE_FEMALE_DROW";
    if (value == 9) return "Polymorph.TYPE_FIRE_GIANT";
    if (value == 42) return "Polymorph.TYPE_FROST_GIANT_FEMALE";
    if (value == 41) return "Polymorph.TYPE_FROST_GIANT_MALE";
    if (value == 65) return "Polymorph.TYPE_GARGOYLE";
    if (value == 3) return "Polymorph.TYPE_GIANT_SPIDER";
    if (value == 57) return "Polymorph.TYPE_GOLEM_AUTOMATON";
    if (value == 60) return "Polymorph.TYPE_HARPY";
    if (value == 43) return "Polymorph.TYPE_HEURODIS";
    if (value == 16) return "Polymorph.TYPE_HUGE_AIR_ELEMENTAL";
    if (value == 15) return "Polymorph.TYPE_HUGE_EARTH_ELEMENTAL";
    if (value == 13) return "Polymorph.TYPE_HUGE_FIRE_ELEMENTAL";
    if (value == 14) return "Polymorph.TYPE_HUGE_WATER_ELEMENTAL";
    if (value == 30) return "Polymorph.TYPE_IMP";
    if (value == 12) return "Polymorph.TYPE_IRON_GOLEM";
    if (value == 45) return "Polymorph.TYPE_JNAH_GIANT_FEMAL";
    if (value == 44) return "Polymorph.TYPE_JNAH_GIANT_MALE";
    if (value == 59) return "Polymorph.TYPE_MALE_DROW";
    if (value == 58) return "Polymorph.TYPE_MANTICORE";
    if (value == 64) return "Polymorph.TYPE_MEDUSA";
    if (value == 68) return "Polymorph.TYPE_MINDFLAYER";
    if (value == 66) return "Polymorph.TYPE_MINOTAUR";
    if (value == 78) return "Polymorph.TYPE_NULL_HUMAN";
    if (value == 22) return "Polymorph.TYPE_PANTHER";
    if (value == 26) return "Polymorph.TYPE_PENGUIN";
    if (value == 6) return "Polymorph.TYPE_PIXIE";
    if (value == 31) return "Polymorph.TYPE_QUASIT";
    if (value == 8) return "Polymorph.TYPE_RED_DRAGON";
    if (value == 75) return "Polymorph.TYPE_RISEN_LORD";
    if (value == 76) return "Polymorph.TYPE_SPECTRE";
    if (value == 32) return "Polymorph.TYPE_SUCCUBUS";
    if (value == 67) return "Polymorph.TYPE_SUPER_CHICKEN";
    if (value == 4) return "Polymorph.TYPE_TROLL";
    if (value == 5) return "Polymorph.TYPE_UMBER_HULK";
    if (value == 77) return "Polymorph.TYPE_VAMPIRE_FEMALE";
    if (value == 74) return "Polymorph.TYPE_VAMPIRE_MALE";
    if (value == 39) return "Polymorph.TYPE_VROCK";
    if (value == 2) return "Polymorph.TYPE_WERECAT";
    if (value == 1) return "Polymorph.TYPE_WERERAT";
    if (value == 0) return "Polymorph.TYPE_WEREWOLF";
    if (value == 23) return "Polymorph.TYPE_WOLF";
    if (value == 56) return "Polymorph.TYPE_WYRMLING_BLACK";
    if (value == 53) return "Polymorph.TYPE_WYRMLING_BLUE";
    if (value == 55) return "Polymorph.TYPE_WYRMLING_GREEN";
    if (value == 54) return "Polymorph.TYPE_WYRMLING_RED";
    if (value == 52) return "Polymorph.TYPE_WYRMLING_WHITE";
    if (value == 29) return "Polymorph.TYPE_YUANTI";
    if (value == 7) return "Polymorph.TYPE_ZOMBIE";
    return "Polymorph.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Polymorph.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Polymorph.(not found: " + value + ")";
  }
}
