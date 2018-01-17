package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRACK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Track {
  private Track() {}

  public final static int BATTLE_ARIBETH = 47;
  public final static int BATTLE_CITY1 = 40;
  public final static int BATTLE_CITY2 = 41;
  public final static int BATTLE_CITY3 = 42;
  public final static int BATTLE_CITYBOSS = 43;
  public final static int BATTLE_DESERT = 57;
  public final static int BATTLE_DRAGON = 46;
  public final static int BATTLE_DUNGEON1 = 37;
  public final static int BATTLE_DUNGEON2 = 38;
  public final static int BATTLE_DUNGEON3 = 39;
  public final static int BATTLE_ENDBOSS = 48;
  public final static int BATTLE_FOREST1 = 35;
  public final static int BATTLE_FOREST2 = 36;
  public final static int BATTLE_FORESTBOSS = 44;
  public final static int BATTLE_LIZARDBOSS = 45;
  public final static int BATTLE_RURAL1 = 34;
  public final static int BATTLE_WINTER = 60;
  public final static int CASTLE = 50;
  public final static int CITYDOCKDAY = 17;
  public final static int CITYDOCKNIGHT = 18;
  public final static int CITYMARKET = 20;
  public final static int CITYNIGHT = 21;
  public final static int CITYSLUMDAY = 15;
  public final static int CITYSLUMNIGHT = 16;
  public final static int CITYWEALTHY = 19;
  public final static int CRYPT1 = 11;
  public final static int CRYPT2 = 12;
  public final static int DESERT_DAY = 58;
  public final static int DESERT_NIGHT = 61;
  public final static int DUNGEON1 = 7;
  public final static int EVILDUNGEON1 = 13;
  public final static int EVILDUNGEON2 = 14;
  public final static int FORESTDAY1 = 4;
  public final static int FORESTDAY2 = 5;
  public final static int FORESTNIGHT = 6;
  public final static int HOTU_BATTLE_BOSS1 = 74;
  public final static int HOTU_BATTLE_BOSS2 = 75;
  public final static int HOTU_BATTLE_HELL = 73;
  public final static int HOTU_BATTLE_LARGE = 72;
  public final static int HOTU_BATTLE_MED = 71;
  public final static int HOTU_BATTLE_SMALL = 70;
  public final static int HOTU_DRACOLICH = 69;
  public final static int HOTU_FIREPLANE = 66;
  public final static int HOTU_HELLFROZEOVER = 68;
  public final static int HOTU_QUEEN = 67;
  public final static int HOTU_REBELCAMP = 65;
  public final static int HOTU_THEME = 62;
  public final static int HOTU_UNDERMOUNTAIN = 64;
  public final static int HOTU_WATERDEEP = 63;
  public final static int MINES1 = 9;
  public final static int MINES2 = 10;
  public final static int RICHHOUSE = 25;
  public final static int RURALDAY1 = 1;
  public final static int RURALDAY2 = 2;
  public final static int RURALNIGHT = 3;
  public final static int SEWER = 8;
  public final static int STORE = 26;
  public final static int TAVERN1 = 22;
  public final static int TAVERN2 = 23;
  public final static int TAVERN3 = 24;
  public final static int TAVERN4 = 56;
  public final static int TEMPLEEVIL = 28;
  public final static int TEMPLEGOOD = 27;
  public final static int TEMPLEGOOD2 = 49;
  public final static int THEME_ARIBETH1 = 51;
  public final static int THEME_ARIBETH2 = 52;
  public final static int THEME_CHAPTER1 = 30;
  public final static int THEME_CHAPTER2 = 31;
  public final static int THEME_CHAPTER3 = 32;
  public final static int THEME_CHAPTER4 = 33;
  public final static int THEME_GEND = 53;
  public final static int THEME_MAUGRIM = 54;
  public final static int THEME_MORAG = 55;
  public final static int THEME_NWN = 29;
  public final static int WINTER_DAY = 59;

  public static String nameOf(int value) {
    if (value == 47) return "Track.BATTLE_ARIBETH";
    if (value == 40) return "Track.BATTLE_CITY1";
    if (value == 41) return "Track.BATTLE_CITY2";
    if (value == 42) return "Track.BATTLE_CITY3";
    if (value == 43) return "Track.BATTLE_CITYBOSS";
    if (value == 57) return "Track.BATTLE_DESERT";
    if (value == 46) return "Track.BATTLE_DRAGON";
    if (value == 37) return "Track.BATTLE_DUNGEON1";
    if (value == 38) return "Track.BATTLE_DUNGEON2";
    if (value == 39) return "Track.BATTLE_DUNGEON3";
    if (value == 48) return "Track.BATTLE_ENDBOSS";
    if (value == 35) return "Track.BATTLE_FOREST1";
    if (value == 36) return "Track.BATTLE_FOREST2";
    if (value == 44) return "Track.BATTLE_FORESTBOSS";
    if (value == 45) return "Track.BATTLE_LIZARDBOSS";
    if (value == 34) return "Track.BATTLE_RURAL1";
    if (value == 60) return "Track.BATTLE_WINTER";
    if (value == 50) return "Track.CASTLE";
    if (value == 17) return "Track.CITYDOCKDAY";
    if (value == 18) return "Track.CITYDOCKNIGHT";
    if (value == 20) return "Track.CITYMARKET";
    if (value == 21) return "Track.CITYNIGHT";
    if (value == 15) return "Track.CITYSLUMDAY";
    if (value == 16) return "Track.CITYSLUMNIGHT";
    if (value == 19) return "Track.CITYWEALTHY";
    if (value == 11) return "Track.CRYPT1";
    if (value == 12) return "Track.CRYPT2";
    if (value == 58) return "Track.DESERT_DAY";
    if (value == 61) return "Track.DESERT_NIGHT";
    if (value == 7) return "Track.DUNGEON1";
    if (value == 13) return "Track.EVILDUNGEON1";
    if (value == 14) return "Track.EVILDUNGEON2";
    if (value == 4) return "Track.FORESTDAY1";
    if (value == 5) return "Track.FORESTDAY2";
    if (value == 6) return "Track.FORESTNIGHT";
    if (value == 74) return "Track.HOTU_BATTLE_BOSS1";
    if (value == 75) return "Track.HOTU_BATTLE_BOSS2";
    if (value == 73) return "Track.HOTU_BATTLE_HELL";
    if (value == 72) return "Track.HOTU_BATTLE_LARGE";
    if (value == 71) return "Track.HOTU_BATTLE_MED";
    if (value == 70) return "Track.HOTU_BATTLE_SMALL";
    if (value == 69) return "Track.HOTU_DRACOLICH";
    if (value == 66) return "Track.HOTU_FIREPLANE";
    if (value == 68) return "Track.HOTU_HELLFROZEOVER";
    if (value == 67) return "Track.HOTU_QUEEN";
    if (value == 65) return "Track.HOTU_REBELCAMP";
    if (value == 62) return "Track.HOTU_THEME";
    if (value == 64) return "Track.HOTU_UNDERMOUNTAIN";
    if (value == 63) return "Track.HOTU_WATERDEEP";
    if (value == 9) return "Track.MINES1";
    if (value == 10) return "Track.MINES2";
    if (value == 25) return "Track.RICHHOUSE";
    if (value == 1) return "Track.RURALDAY1";
    if (value == 2) return "Track.RURALDAY2";
    if (value == 3) return "Track.RURALNIGHT";
    if (value == 8) return "Track.SEWER";
    if (value == 26) return "Track.STORE";
    if (value == 22) return "Track.TAVERN1";
    if (value == 23) return "Track.TAVERN2";
    if (value == 24) return "Track.TAVERN3";
    if (value == 56) return "Track.TAVERN4";
    if (value == 28) return "Track.TEMPLEEVIL";
    if (value == 27) return "Track.TEMPLEGOOD";
    if (value == 49) return "Track.TEMPLEGOOD2";
    if (value == 51) return "Track.THEME_ARIBETH1";
    if (value == 52) return "Track.THEME_ARIBETH2";
    if (value == 30) return "Track.THEME_CHAPTER1";
    if (value == 31) return "Track.THEME_CHAPTER2";
    if (value == 32) return "Track.THEME_CHAPTER3";
    if (value == 33) return "Track.THEME_CHAPTER4";
    if (value == 53) return "Track.THEME_GEND";
    if (value == 54) return "Track.THEME_MAUGRIM";
    if (value == 55) return "Track.THEME_MORAG";
    if (value == 29) return "Track.THEME_NWN";
    if (value == 59) return "Track.WINTER_DAY";
    return "Track.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Track.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Track.(not found: " + value + ")";
  }
}
