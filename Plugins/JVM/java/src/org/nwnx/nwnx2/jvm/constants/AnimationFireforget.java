package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_FIREFORGET".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationFireforget {
  private AnimationFireforget() {}

  public final static int BOW = 105;
  public final static int DODGE_DUCK = 115;
  public final static int DODGE_SIDE = 114;
  public final static int DRINK = 113;
  public final static int GREETING = 107;
  public final static int HEAD_TURN_LEFT = 100;
  public final static int HEAD_TURN_RIGHT = 101;
  public final static int PAUSE_BORED = 103;
  public final static int PAUSE_SCRATCH_HEAD = 102;
  public final static int READ = 112;
  public final static int SALUTE = 104;
  public final static int SPASM = 116;
  public final static int STEAL = 106;
  public final static int TAUNT = 108;
  public final static int VICTORY1 = 109;
  public final static int VICTORY2 = 110;
  public final static int VICTORY3 = 111;

  public static String nameOf(int value) {
    if (value == 105) return "AnimationFireforget.BOW";
    if (value == 115) return "AnimationFireforget.DODGE_DUCK";
    if (value == 114) return "AnimationFireforget.DODGE_SIDE";
    if (value == 113) return "AnimationFireforget.DRINK";
    if (value == 107) return "AnimationFireforget.GREETING";
    if (value == 100) return "AnimationFireforget.HEAD_TURN_LEFT";
    if (value == 101) return "AnimationFireforget.HEAD_TURN_RIGHT";
    if (value == 103) return "AnimationFireforget.PAUSE_BORED";
    if (value == 102) return "AnimationFireforget.PAUSE_SCRATCH_HEAD";
    if (value == 112) return "AnimationFireforget.READ";
    if (value == 104) return "AnimationFireforget.SALUTE";
    if (value == 116) return "AnimationFireforget.SPASM";
    if (value == 106) return "AnimationFireforget.STEAL";
    if (value == 108) return "AnimationFireforget.TAUNT";
    if (value == 109) return "AnimationFireforget.VICTORY1";
    if (value == 110) return "AnimationFireforget.VICTORY2";
    if (value == 111) return "AnimationFireforget.VICTORY3";
    return "AnimationFireforget.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationFireforget.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationFireforget.(not found: " + value + ")";
  }
}
