package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_LOOPING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationLooping {
  private AnimationLooping() {}

  public final static int CONJURE1 = 18;
  public final static int CONJURE2 = 19;
  public final static int CUSTOM1 = 21;
  public final static int CUSTOM10 = 30;
  public final static int CUSTOM11 = 31;
  public final static int CUSTOM12 = 32;
  public final static int CUSTOM13 = 33;
  public final static int CUSTOM14 = 34;
  public final static int CUSTOM15 = 35;
  public final static int CUSTOM16 = 36;
  public final static int CUSTOM17 = 37;
  public final static int CUSTOM18 = 38;
  public final static int CUSTOM19 = 39;
  public final static int CUSTOM2 = 22;
  public final static int CUSTOM20 = 40;
  public final static int CUSTOM3 = 23;
  public final static int CUSTOM4 = 24;
  public final static int CUSTOM5 = 25;
  public final static int CUSTOM6 = 26;
  public final static int CUSTOM7 = 27;
  public final static int CUSTOM8 = 28;
  public final static int CUSTOM9 = 29;
  public final static int DEAD_BACK = 17;
  public final static int DEAD_FRONT = 16;
  public final static int GET_LOW = 12;
  public final static int GET_MID = 13;
  public final static int LISTEN = 2;
  public final static int LOOK_FAR = 5;
  public final static int MEDITATE = 3;
  public final static int PAUSE = 0;
  public final static int PAUSE2 = 1;
  public final static int PAUSE_DRUNK = 15;
  public final static int PAUSE_TIRED = 14;
  public final static int SIT_CHAIR = 6;
  public final static int SIT_CROSS = 7;
  public final static int SPASM = 20;
  public final static int TALK_FORCEFUL = 10;
  public final static int TALK_LAUGHING = 11;
  public final static int TALK_NORMAL = 8;
  public final static int TALK_PLEADING = 9;
  public final static int WORSHIP = 4;

  public static String nameOf(int value) {
    if (value == 18) return "AnimationLooping.CONJURE1";
    if (value == 19) return "AnimationLooping.CONJURE2";
    if (value == 21) return "AnimationLooping.CUSTOM1";
    if (value == 30) return "AnimationLooping.CUSTOM10";
    if (value == 31) return "AnimationLooping.CUSTOM11";
    if (value == 32) return "AnimationLooping.CUSTOM12";
    if (value == 33) return "AnimationLooping.CUSTOM13";
    if (value == 34) return "AnimationLooping.CUSTOM14";
    if (value == 35) return "AnimationLooping.CUSTOM15";
    if (value == 36) return "AnimationLooping.CUSTOM16";
    if (value == 37) return "AnimationLooping.CUSTOM17";
    if (value == 38) return "AnimationLooping.CUSTOM18";
    if (value == 39) return "AnimationLooping.CUSTOM19";
    if (value == 22) return "AnimationLooping.CUSTOM2";
    if (value == 40) return "AnimationLooping.CUSTOM20";
    if (value == 23) return "AnimationLooping.CUSTOM3";
    if (value == 24) return "AnimationLooping.CUSTOM4";
    if (value == 25) return "AnimationLooping.CUSTOM5";
    if (value == 26) return "AnimationLooping.CUSTOM6";
    if (value == 27) return "AnimationLooping.CUSTOM7";
    if (value == 28) return "AnimationLooping.CUSTOM8";
    if (value == 29) return "AnimationLooping.CUSTOM9";
    if (value == 17) return "AnimationLooping.DEAD_BACK";
    if (value == 16) return "AnimationLooping.DEAD_FRONT";
    if (value == 12) return "AnimationLooping.GET_LOW";
    if (value == 13) return "AnimationLooping.GET_MID";
    if (value == 2) return "AnimationLooping.LISTEN";
    if (value == 5) return "AnimationLooping.LOOK_FAR";
    if (value == 3) return "AnimationLooping.MEDITATE";
    if (value == 0) return "AnimationLooping.PAUSE";
    if (value == 1) return "AnimationLooping.PAUSE2";
    if (value == 15) return "AnimationLooping.PAUSE_DRUNK";
    if (value == 14) return "AnimationLooping.PAUSE_TIRED";
    if (value == 6) return "AnimationLooping.SIT_CHAIR";
    if (value == 7) return "AnimationLooping.SIT_CROSS";
    if (value == 20) return "AnimationLooping.SPASM";
    if (value == 10) return "AnimationLooping.TALK_FORCEFUL";
    if (value == 11) return "AnimationLooping.TALK_LAUGHING";
    if (value == 8) return "AnimationLooping.TALK_NORMAL";
    if (value == 9) return "AnimationLooping.TALK_PLEADING";
    if (value == 4) return "AnimationLooping.WORSHIP";
    return "AnimationLooping.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationLooping.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationLooping.(not found: " + value + ")";
  }
}
