package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRACK_THEME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrackTheme {
  private TrackTheme() {}

  public final static int ARIBETH1 = 51;
  public final static int ARIBETH2 = 52;
  public final static int CHAPTER1 = 30;
  public final static int CHAPTER2 = 31;
  public final static int CHAPTER3 = 32;
  public final static int CHAPTER4 = 33;
  public final static int GEND = 53;
  public final static int MAUGRIM = 54;
  public final static int MORAG = 55;
  public final static int NWN = 29;

  public static String nameOf(int value) {
    if (value == 51) return "TrackTheme.ARIBETH1";
    if (value == 52) return "TrackTheme.ARIBETH2";
    if (value == 30) return "TrackTheme.CHAPTER1";
    if (value == 31) return "TrackTheme.CHAPTER2";
    if (value == 32) return "TrackTheme.CHAPTER3";
    if (value == 33) return "TrackTheme.CHAPTER4";
    if (value == 53) return "TrackTheme.GEND";
    if (value == 54) return "TrackTheme.MAUGRIM";
    if (value == 55) return "TrackTheme.MORAG";
    if (value == 29) return "TrackTheme.NWN";
    return "TrackTheme.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrackTheme.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrackTheme.(not found: " + value + ")";
  }
}
