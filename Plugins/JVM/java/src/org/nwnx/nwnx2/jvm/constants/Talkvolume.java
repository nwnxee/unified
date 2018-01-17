package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALKVOLUME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Talkvolume {
  private Talkvolume() {}

  public final static int PARTY = 5;
  public final static int SHOUT = 2;
  public final static int SILENT_SHOUT = 4;
  public final static int SILENT_TALK = 3;
  public final static int TALK = 0;
  public final static int TELL = 6;
  public final static int WHISPER = 1;

  public static String nameOf(int value) {
    if (value == 5) return "Talkvolume.PARTY";
    if (value == 2) return "Talkvolume.SHOUT";
    if (value == 4) return "Talkvolume.SILENT_SHOUT";
    if (value == 3) return "Talkvolume.SILENT_TALK";
    if (value == 0) return "Talkvolume.TALK";
    if (value == 6) return "Talkvolume.TELL";
    if (value == 1) return "Talkvolume.WHISPER";
    return "Talkvolume.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Talkvolume.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Talkvolume.(not found: " + value + ")";
  }
}
