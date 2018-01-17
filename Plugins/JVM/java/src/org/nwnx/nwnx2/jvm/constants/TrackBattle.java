package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRACK_BATTLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrackBattle {
  private TrackBattle() {}

  public final static int ARIBETH = 47;
  public final static int CITY1 = 40;
  public final static int CITY2 = 41;
  public final static int CITY3 = 42;
  public final static int CITYBOSS = 43;
  public final static int DESERT = 57;
  public final static int DRAGON = 46;
  public final static int DUNGEON1 = 37;
  public final static int DUNGEON2 = 38;
  public final static int DUNGEON3 = 39;
  public final static int ENDBOSS = 48;
  public final static int FOREST1 = 35;
  public final static int FOREST2 = 36;
  public final static int FORESTBOSS = 44;
  public final static int LIZARDBOSS = 45;
  public final static int RURAL1 = 34;
  public final static int WINTER = 60;

  public static String nameOf(int value) {
    if (value == 47) return "TrackBattle.ARIBETH";
    if (value == 40) return "TrackBattle.CITY1";
    if (value == 41) return "TrackBattle.CITY2";
    if (value == 42) return "TrackBattle.CITY3";
    if (value == 43) return "TrackBattle.CITYBOSS";
    if (value == 57) return "TrackBattle.DESERT";
    if (value == 46) return "TrackBattle.DRAGON";
    if (value == 37) return "TrackBattle.DUNGEON1";
    if (value == 38) return "TrackBattle.DUNGEON2";
    if (value == 39) return "TrackBattle.DUNGEON3";
    if (value == 48) return "TrackBattle.ENDBOSS";
    if (value == 35) return "TrackBattle.FOREST1";
    if (value == 36) return "TrackBattle.FOREST2";
    if (value == 44) return "TrackBattle.FORESTBOSS";
    if (value == 45) return "TrackBattle.LIZARDBOSS";
    if (value == 34) return "TrackBattle.RURAL1";
    if (value == 60) return "TrackBattle.WINTER";
    return "TrackBattle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrackBattle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrackBattle.(not found: " + value + ")";
  }
}
