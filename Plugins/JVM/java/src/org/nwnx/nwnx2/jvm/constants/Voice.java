package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VOICE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Voice {
  private Voice() {}

  public final static int CHAT_ATTACK = 0;
  public final static int CHAT_BADIDEA = 47;
  public final static int CHAT_BATTLECRY1 = 1;
  public final static int CHAT_BATTLECRY2 = 2;
  public final static int CHAT_BATTLECRY3 = 3;
  public final static int CHAT_BORED = 39;
  public final static int CHAT_CANDO = 29;
  public final static int CHAT_CANTDO = 30;
  public final static int CHAT_CHEER = 44;
  public final static int CHAT_CUSS = 43;
  public final static int CHAT_DEATH = 18;
  public final static int CHAT_ENCUMBERED = 32;
  public final static int CHAT_ENEMIES = 6;
  public final static int CHAT_FLEE = 7;
  public final static int CHAT_FOLLOWME = 22;
  public final static int CHAT_GATTACK1 = 11;
  public final static int CHAT_GATTACK2 = 12;
  public final static int CHAT_GATTACK3 = 13;
  public final static int CHAT_GOODBYE = 40;
  public final static int CHAT_GOODIDEA = 46;
  public final static int CHAT_GROUP = 24;
  public final static int CHAT_GUARDME = 9;
  public final static int CHAT_HEALME = 4;
  public final static int CHAT_HELLO = 34;
  public final static int CHAT_HELP = 5;
  public final static int CHAT_HIDE = 28;
  public final static int CHAT_HOLD = 10;
  public final static int CHAT_LAUGH = 42;
  public final static int CHAT_LOOKHERE = 23;
  public final static int CHAT_MOVEOVER = 25;
  public final static int CHAT_NEARDEATH = 17;
  public final static int CHAT_NO = 36;
  public final static int CHAT_PAIN1 = 14;
  public final static int CHAT_PAIN2 = 15;
  public final static int CHAT_PAIN3 = 16;
  public final static int CHAT_PICKLOCK = 26;
  public final static int CHAT_POISONED = 19;
  public final static int CHAT_REST = 38;
  public final static int CHAT_SEARCH = 27;
  public final static int CHAT_SELECTED = 33;
  public final static int CHAT_SPELLFAILED = 20;
  public final static int CHAT_STOP = 37;
  public final static int CHAT_TALKTOME = 45;
  public final static int CHAT_TASKCOMPLETE = 31;
  public final static int CHAT_TAUNT = 8;
  public final static int CHAT_THANKS = 41;
  public final static int CHAT_THREATEN = 48;
  public final static int CHAT_WEAPONSUCKS = 21;
  public final static int CHAT_YES = 35;

  public static String nameOf(int value) {
    if (value == 0) return "Voice.CHAT_ATTACK";
    if (value == 47) return "Voice.CHAT_BADIDEA";
    if (value == 1) return "Voice.CHAT_BATTLECRY1";
    if (value == 2) return "Voice.CHAT_BATTLECRY2";
    if (value == 3) return "Voice.CHAT_BATTLECRY3";
    if (value == 39) return "Voice.CHAT_BORED";
    if (value == 29) return "Voice.CHAT_CANDO";
    if (value == 30) return "Voice.CHAT_CANTDO";
    if (value == 44) return "Voice.CHAT_CHEER";
    if (value == 43) return "Voice.CHAT_CUSS";
    if (value == 18) return "Voice.CHAT_DEATH";
    if (value == 32) return "Voice.CHAT_ENCUMBERED";
    if (value == 6) return "Voice.CHAT_ENEMIES";
    if (value == 7) return "Voice.CHAT_FLEE";
    if (value == 22) return "Voice.CHAT_FOLLOWME";
    if (value == 11) return "Voice.CHAT_GATTACK1";
    if (value == 12) return "Voice.CHAT_GATTACK2";
    if (value == 13) return "Voice.CHAT_GATTACK3";
    if (value == 40) return "Voice.CHAT_GOODBYE";
    if (value == 46) return "Voice.CHAT_GOODIDEA";
    if (value == 24) return "Voice.CHAT_GROUP";
    if (value == 9) return "Voice.CHAT_GUARDME";
    if (value == 4) return "Voice.CHAT_HEALME";
    if (value == 34) return "Voice.CHAT_HELLO";
    if (value == 5) return "Voice.CHAT_HELP";
    if (value == 28) return "Voice.CHAT_HIDE";
    if (value == 10) return "Voice.CHAT_HOLD";
    if (value == 42) return "Voice.CHAT_LAUGH";
    if (value == 23) return "Voice.CHAT_LOOKHERE";
    if (value == 25) return "Voice.CHAT_MOVEOVER";
    if (value == 17) return "Voice.CHAT_NEARDEATH";
    if (value == 36) return "Voice.CHAT_NO";
    if (value == 14) return "Voice.CHAT_PAIN1";
    if (value == 15) return "Voice.CHAT_PAIN2";
    if (value == 16) return "Voice.CHAT_PAIN3";
    if (value == 26) return "Voice.CHAT_PICKLOCK";
    if (value == 19) return "Voice.CHAT_POISONED";
    if (value == 38) return "Voice.CHAT_REST";
    if (value == 27) return "Voice.CHAT_SEARCH";
    if (value == 33) return "Voice.CHAT_SELECTED";
    if (value == 20) return "Voice.CHAT_SPELLFAILED";
    if (value == 37) return "Voice.CHAT_STOP";
    if (value == 45) return "Voice.CHAT_TALKTOME";
    if (value == 31) return "Voice.CHAT_TASKCOMPLETE";
    if (value == 8) return "Voice.CHAT_TAUNT";
    if (value == 41) return "Voice.CHAT_THANKS";
    if (value == 48) return "Voice.CHAT_THREATEN";
    if (value == 21) return "Voice.CHAT_WEAPONSUCKS";
    if (value == 35) return "Voice.CHAT_YES";
    return "Voice.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Voice.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Voice.(not found: " + value + ")";
  }
}
