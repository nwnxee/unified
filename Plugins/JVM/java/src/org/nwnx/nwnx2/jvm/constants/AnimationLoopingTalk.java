package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_LOOPING_TALK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationLoopingTalk {
  private AnimationLoopingTalk() {}

  public final static int FORCEFUL = 10;
  public final static int LAUGHING = 11;
  public final static int NORMAL = 8;
  public final static int PLEADING = 9;

  public static String nameOf(int value) {
    if (value == 10) return "AnimationLoopingTalk.FORCEFUL";
    if (value == 11) return "AnimationLoopingTalk.LAUGHING";
    if (value == 8) return "AnimationLoopingTalk.NORMAL";
    if (value == 9) return "AnimationLoopingTalk.PLEADING";
    return "AnimationLoopingTalk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationLoopingTalk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationLoopingTalk.(not found: " + value + ")";
  }
}
