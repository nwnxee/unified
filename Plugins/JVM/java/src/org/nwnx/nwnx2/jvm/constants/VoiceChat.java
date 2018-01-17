package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VOICE_CHAT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VoiceChat {
  private VoiceChat() {}

  public final static int ATTACK = 0;
  public final static int BADIDEA = 47;
  public final static int BATTLECRY1 = 1;
  public final static int BATTLECRY2 = 2;
  public final static int BATTLECRY3 = 3;
  public final static int BORED = 39;
  public final static int CANDO = 29;
  public final static int CANTDO = 30;
  public final static int CHEER = 44;
  public final static int CUSS = 43;
  public final static int DEATH = 18;
  public final static int ENCUMBERED = 32;
  public final static int ENEMIES = 6;
  public final static int FLEE = 7;
  public final static int FOLLOWME = 22;
  public final static int GATTACK1 = 11;
  public final static int GATTACK2 = 12;
  public final static int GATTACK3 = 13;
  public final static int GOODBYE = 40;
  public final static int GOODIDEA = 46;
  public final static int GROUP = 24;
  public final static int GUARDME = 9;
  public final static int HEALME = 4;
  public final static int HELLO = 34;
  public final static int HELP = 5;
  public final static int HIDE = 28;
  public final static int HOLD = 10;
  public final static int LAUGH = 42;
  public final static int LOOKHERE = 23;
  public final static int MOVEOVER = 25;
  public final static int NEARDEATH = 17;
  public final static int NO = 36;
  public final static int PAIN1 = 14;
  public final static int PAIN2 = 15;
  public final static int PAIN3 = 16;
  public final static int PICKLOCK = 26;
  public final static int POISONED = 19;
  public final static int REST = 38;
  public final static int SEARCH = 27;
  public final static int SELECTED = 33;
  public final static int SPELLFAILED = 20;
  public final static int STOP = 37;
  public final static int TALKTOME = 45;
  public final static int TASKCOMPLETE = 31;
  public final static int TAUNT = 8;
  public final static int THANKS = 41;
  public final static int THREATEN = 48;
  public final static int WEAPONSUCKS = 21;
  public final static int YES = 35;

  public static String nameOf(int value) {
    if (value == 0) return "VoiceChat.ATTACK";
    if (value == 47) return "VoiceChat.BADIDEA";
    if (value == 1) return "VoiceChat.BATTLECRY1";
    if (value == 2) return "VoiceChat.BATTLECRY2";
    if (value == 3) return "VoiceChat.BATTLECRY3";
    if (value == 39) return "VoiceChat.BORED";
    if (value == 29) return "VoiceChat.CANDO";
    if (value == 30) return "VoiceChat.CANTDO";
    if (value == 44) return "VoiceChat.CHEER";
    if (value == 43) return "VoiceChat.CUSS";
    if (value == 18) return "VoiceChat.DEATH";
    if (value == 32) return "VoiceChat.ENCUMBERED";
    if (value == 6) return "VoiceChat.ENEMIES";
    if (value == 7) return "VoiceChat.FLEE";
    if (value == 22) return "VoiceChat.FOLLOWME";
    if (value == 11) return "VoiceChat.GATTACK1";
    if (value == 12) return "VoiceChat.GATTACK2";
    if (value == 13) return "VoiceChat.GATTACK3";
    if (value == 40) return "VoiceChat.GOODBYE";
    if (value == 46) return "VoiceChat.GOODIDEA";
    if (value == 24) return "VoiceChat.GROUP";
    if (value == 9) return "VoiceChat.GUARDME";
    if (value == 4) return "VoiceChat.HEALME";
    if (value == 34) return "VoiceChat.HELLO";
    if (value == 5) return "VoiceChat.HELP";
    if (value == 28) return "VoiceChat.HIDE";
    if (value == 10) return "VoiceChat.HOLD";
    if (value == 42) return "VoiceChat.LAUGH";
    if (value == 23) return "VoiceChat.LOOKHERE";
    if (value == 25) return "VoiceChat.MOVEOVER";
    if (value == 17) return "VoiceChat.NEARDEATH";
    if (value == 36) return "VoiceChat.NO";
    if (value == 14) return "VoiceChat.PAIN1";
    if (value == 15) return "VoiceChat.PAIN2";
    if (value == 16) return "VoiceChat.PAIN3";
    if (value == 26) return "VoiceChat.PICKLOCK";
    if (value == 19) return "VoiceChat.POISONED";
    if (value == 38) return "VoiceChat.REST";
    if (value == 27) return "VoiceChat.SEARCH";
    if (value == 33) return "VoiceChat.SELECTED";
    if (value == 20) return "VoiceChat.SPELLFAILED";
    if (value == 37) return "VoiceChat.STOP";
    if (value == 45) return "VoiceChat.TALKTOME";
    if (value == 31) return "VoiceChat.TASKCOMPLETE";
    if (value == 8) return "VoiceChat.TAUNT";
    if (value == 41) return "VoiceChat.THANKS";
    if (value == 48) return "VoiceChat.THREATEN";
    if (value == 21) return "VoiceChat.WEAPONSUCKS";
    if (value == 35) return "VoiceChat.YES";
    return "VoiceChat.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VoiceChat.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VoiceChat.(not found: " + value + ")";
  }
}
