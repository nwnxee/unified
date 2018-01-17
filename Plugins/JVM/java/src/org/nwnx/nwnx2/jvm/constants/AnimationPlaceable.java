package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_PLACEABLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationPlaceable {
  private AnimationPlaceable() {}

  public final static int ACTIVATE = 200;
  public final static int CLOSE = 203;
  public final static int DEACTIVATE = 201;
  public final static int OPEN = 202;

  public static String nameOf(int value) {
    if (value == 200) return "AnimationPlaceable.ACTIVATE";
    if (value == 203) return "AnimationPlaceable.CLOSE";
    if (value == 201) return "AnimationPlaceable.DEACTIVATE";
    if (value == 202) return "AnimationPlaceable.OPEN";
    return "AnimationPlaceable.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationPlaceable.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationPlaceable.(not found: " + value + ")";
  }
}
