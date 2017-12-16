package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Animation {
  private Animation() {}

  public final static int DISMOUNT1 = 42;
  public final static int DOOR_CLOSE = 204;
  public final static int DOOR_DESTROY = 207;
  public final static int DOOR_OPEN1 = 205;
  public final static int DOOR_OPEN2 = 206;
  public final static int FIREFORGET_BOW = 105;
  public final static int FIREFORGET_DODGE_DUCK = 115;
  public final static int FIREFORGET_DODGE_SIDE = 114;
  public final static int FIREFORGET_DRINK = 113;
  public final static int FIREFORGET_GREETING = 107;
  public final static int FIREFORGET_HEAD_TURN_LEFT = 100;
  public final static int FIREFORGET_HEAD_TURN_RIGHT = 101;
  public final static int FIREFORGET_PAUSE_BORED = 103;
  public final static int FIREFORGET_PAUSE_SCRATCH_HEAD = 102;
  public final static int FIREFORGET_READ = 112;
  public final static int FIREFORGET_SALUTE = 104;
  public final static int FIREFORGET_SPASM = 116;
  public final static int FIREFORGET_STEAL = 106;
  public final static int FIREFORGET_TAUNT = 108;
  public final static int FIREFORGET_VICTORY1 = 109;
  public final static int FIREFORGET_VICTORY2 = 110;
  public final static int FIREFORGET_VICTORY3 = 111;
  public final static int LOOPING_CONJURE1 = 18;
  public final static int LOOPING_CONJURE2 = 19;
  public final static int LOOPING_CUSTOM1 = 21;
  public final static int LOOPING_CUSTOM10 = 30;
  public final static int LOOPING_CUSTOM11 = 31;
  public final static int LOOPING_CUSTOM12 = 32;
  public final static int LOOPING_CUSTOM13 = 33;
  public final static int LOOPING_CUSTOM14 = 34;
  public final static int LOOPING_CUSTOM15 = 35;
  public final static int LOOPING_CUSTOM16 = 36;
  public final static int LOOPING_CUSTOM17 = 37;
  public final static int LOOPING_CUSTOM18 = 38;
  public final static int LOOPING_CUSTOM19 = 39;
  public final static int LOOPING_CUSTOM2 = 22;
  public final static int LOOPING_CUSTOM20 = 40;
  public final static int LOOPING_CUSTOM3 = 23;
  public final static int LOOPING_CUSTOM4 = 24;
  public final static int LOOPING_CUSTOM5 = 25;
  public final static int LOOPING_CUSTOM6 = 26;
  public final static int LOOPING_CUSTOM7 = 27;
  public final static int LOOPING_CUSTOM8 = 28;
  public final static int LOOPING_CUSTOM9 = 29;
  public final static int LOOPING_DEAD_BACK = 17;
  public final static int LOOPING_DEAD_FRONT = 16;
  public final static int LOOPING_GET_LOW = 12;
  public final static int LOOPING_GET_MID = 13;
  public final static int LOOPING_LISTEN = 2;
  public final static int LOOPING_LOOK_FAR = 5;
  public final static int LOOPING_MEDITATE = 3;
  public final static int LOOPING_PAUSE = 0;
  public final static int LOOPING_PAUSE2 = 1;
  public final static int LOOPING_PAUSE_DRUNK = 15;
  public final static int LOOPING_PAUSE_TIRED = 14;
  public final static int LOOPING_SIT_CHAIR = 6;
  public final static int LOOPING_SIT_CROSS = 7;
  public final static int LOOPING_SPASM = 20;
  public final static int LOOPING_TALK_FORCEFUL = 10;
  public final static int LOOPING_TALK_LAUGHING = 11;
  public final static int LOOPING_TALK_NORMAL = 8;
  public final static int LOOPING_TALK_PLEADING = 9;
  public final static int LOOPING_WORSHIP = 4;
  public final static int MOUNT1 = 41;
  public final static int PLACEABLE_ACTIVATE = 200;
  public final static int PLACEABLE_CLOSE = 203;
  public final static int PLACEABLE_DEACTIVATE = 201;
  public final static int PLACEABLE_OPEN = 202;

  public static String nameOf(int value) {
    if (value == 42) return "Animation.DISMOUNT1";
    if (value == 204) return "Animation.DOOR_CLOSE";
    if (value == 207) return "Animation.DOOR_DESTROY";
    if (value == 205) return "Animation.DOOR_OPEN1";
    if (value == 206) return "Animation.DOOR_OPEN2";
    if (value == 105) return "Animation.FIREFORGET_BOW";
    if (value == 115) return "Animation.FIREFORGET_DODGE_DUCK";
    if (value == 114) return "Animation.FIREFORGET_DODGE_SIDE";
    if (value == 113) return "Animation.FIREFORGET_DRINK";
    if (value == 107) return "Animation.FIREFORGET_GREETING";
    if (value == 100) return "Animation.FIREFORGET_HEAD_TURN_LEFT";
    if (value == 101) return "Animation.FIREFORGET_HEAD_TURN_RIGHT";
    if (value == 103) return "Animation.FIREFORGET_PAUSE_BORED";
    if (value == 102) return "Animation.FIREFORGET_PAUSE_SCRATCH_HEAD";
    if (value == 112) return "Animation.FIREFORGET_READ";
    if (value == 104) return "Animation.FIREFORGET_SALUTE";
    if (value == 116) return "Animation.FIREFORGET_SPASM";
    if (value == 106) return "Animation.FIREFORGET_STEAL";
    if (value == 108) return "Animation.FIREFORGET_TAUNT";
    if (value == 109) return "Animation.FIREFORGET_VICTORY1";
    if (value == 110) return "Animation.FIREFORGET_VICTORY2";
    if (value == 111) return "Animation.FIREFORGET_VICTORY3";
    if (value == 18) return "Animation.LOOPING_CONJURE1";
    if (value == 19) return "Animation.LOOPING_CONJURE2";
    if (value == 21) return "Animation.LOOPING_CUSTOM1";
    if (value == 30) return "Animation.LOOPING_CUSTOM10";
    if (value == 31) return "Animation.LOOPING_CUSTOM11";
    if (value == 32) return "Animation.LOOPING_CUSTOM12";
    if (value == 33) return "Animation.LOOPING_CUSTOM13";
    if (value == 34) return "Animation.LOOPING_CUSTOM14";
    if (value == 35) return "Animation.LOOPING_CUSTOM15";
    if (value == 36) return "Animation.LOOPING_CUSTOM16";
    if (value == 37) return "Animation.LOOPING_CUSTOM17";
    if (value == 38) return "Animation.LOOPING_CUSTOM18";
    if (value == 39) return "Animation.LOOPING_CUSTOM19";
    if (value == 22) return "Animation.LOOPING_CUSTOM2";
    if (value == 40) return "Animation.LOOPING_CUSTOM20";
    if (value == 23) return "Animation.LOOPING_CUSTOM3";
    if (value == 24) return "Animation.LOOPING_CUSTOM4";
    if (value == 25) return "Animation.LOOPING_CUSTOM5";
    if (value == 26) return "Animation.LOOPING_CUSTOM6";
    if (value == 27) return "Animation.LOOPING_CUSTOM7";
    if (value == 28) return "Animation.LOOPING_CUSTOM8";
    if (value == 29) return "Animation.LOOPING_CUSTOM9";
    if (value == 17) return "Animation.LOOPING_DEAD_BACK";
    if (value == 16) return "Animation.LOOPING_DEAD_FRONT";
    if (value == 12) return "Animation.LOOPING_GET_LOW";
    if (value == 13) return "Animation.LOOPING_GET_MID";
    if (value == 2) return "Animation.LOOPING_LISTEN";
    if (value == 5) return "Animation.LOOPING_LOOK_FAR";
    if (value == 3) return "Animation.LOOPING_MEDITATE";
    if (value == 0) return "Animation.LOOPING_PAUSE";
    if (value == 1) return "Animation.LOOPING_PAUSE2";
    if (value == 15) return "Animation.LOOPING_PAUSE_DRUNK";
    if (value == 14) return "Animation.LOOPING_PAUSE_TIRED";
    if (value == 6) return "Animation.LOOPING_SIT_CHAIR";
    if (value == 7) return "Animation.LOOPING_SIT_CROSS";
    if (value == 20) return "Animation.LOOPING_SPASM";
    if (value == 10) return "Animation.LOOPING_TALK_FORCEFUL";
    if (value == 11) return "Animation.LOOPING_TALK_LAUGHING";
    if (value == 8) return "Animation.LOOPING_TALK_NORMAL";
    if (value == 9) return "Animation.LOOPING_TALK_PLEADING";
    if (value == 4) return "Animation.LOOPING_WORSHIP";
    if (value == 41) return "Animation.MOUNT1";
    if (value == 200) return "Animation.PLACEABLE_ACTIVATE";
    if (value == 203) return "Animation.PLACEABLE_CLOSE";
    if (value == 201) return "Animation.PLACEABLE_DEACTIVATE";
    if (value == 202) return "Animation.PLACEABLE_OPEN";
    return "Animation.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Animation.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Animation.(not found: " + value + ")";
  }
}
