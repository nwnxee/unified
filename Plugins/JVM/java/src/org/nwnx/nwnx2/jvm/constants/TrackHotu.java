package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRACK_HOTU".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrackHotu {
  private TrackHotu() {}

  public final static int BATTLE_BOSS1 = 74;
  public final static int BATTLE_BOSS2 = 75;
  public final static int BATTLE_HELL = 73;
  public final static int BATTLE_LARGE = 72;
  public final static int BATTLE_MED = 71;
  public final static int BATTLE_SMALL = 70;
  public final static int DRACOLICH = 69;
  public final static int FIREPLANE = 66;
  public final static int HELLFROZEOVER = 68;
  public final static int QUEEN = 67;
  public final static int REBELCAMP = 65;
  public final static int THEME = 62;
  public final static int UNDERMOUNTAIN = 64;
  public final static int WATERDEEP = 63;

  public static String nameOf(int value) {
    if (value == 74) return "TrackHotu.BATTLE_BOSS1";
    if (value == 75) return "TrackHotu.BATTLE_BOSS2";
    if (value == 73) return "TrackHotu.BATTLE_HELL";
    if (value == 72) return "TrackHotu.BATTLE_LARGE";
    if (value == 71) return "TrackHotu.BATTLE_MED";
    if (value == 70) return "TrackHotu.BATTLE_SMALL";
    if (value == 69) return "TrackHotu.DRACOLICH";
    if (value == 66) return "TrackHotu.FIREPLANE";
    if (value == 68) return "TrackHotu.HELLFROZEOVER";
    if (value == 67) return "TrackHotu.QUEEN";
    if (value == 65) return "TrackHotu.REBELCAMP";
    if (value == 62) return "TrackHotu.THEME";
    if (value == 64) return "TrackHotu.UNDERMOUNTAIN";
    if (value == 63) return "TrackHotu.WATERDEEP";
    return "TrackHotu.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrackHotu.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrackHotu.(not found: " + value + ")";
  }
}
