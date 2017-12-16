package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRACK_HOTU_BATTLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrackHotuBattle {
  private TrackHotuBattle() {}

  public final static int BOSS1 = 74;
  public final static int BOSS2 = 75;
  public final static int HELL = 73;
  public final static int LARGE = 72;
  public final static int MED = 71;
  public final static int SMALL = 70;

  public static String nameOf(int value) {
    if (value == 74) return "TrackHotuBattle.BOSS1";
    if (value == 75) return "TrackHotuBattle.BOSS2";
    if (value == 73) return "TrackHotuBattle.HELL";
    if (value == 72) return "TrackHotuBattle.LARGE";
    if (value == 71) return "TrackHotuBattle.MED";
    if (value == 70) return "TrackHotuBattle.SMALL";
    return "TrackHotuBattle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrackHotuBattle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrackHotuBattle.(not found: " + value + ")";
  }
}
