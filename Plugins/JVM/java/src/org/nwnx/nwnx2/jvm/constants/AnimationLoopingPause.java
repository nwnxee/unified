package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_LOOPING_PAUSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationLoopingPause {
  private AnimationLoopingPause() {}

  public final static int ANIMATION_LOOPING_PAUSE = 0;
  public final static int DRUNK = 15;
  public final static int TIRED = 14;

  public static String nameOf(int value) {
    if (value == 0) return "AnimationLoopingPause.ANIMATION_LOOPING_PAUSE";
    if (value == 15) return "AnimationLoopingPause.DRUNK";
    if (value == 14) return "AnimationLoopingPause.TIRED";
    return "AnimationLoopingPause.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationLoopingPause.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationLoopingPause.(not found: " + value + ")";
  }
}
