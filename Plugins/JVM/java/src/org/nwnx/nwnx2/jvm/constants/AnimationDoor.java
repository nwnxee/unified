package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ANIMATION_DOOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AnimationDoor {
  private AnimationDoor() {}

  public final static int CLOSE = 204;
  public final static int DESTROY = 207;
  public final static int OPEN1 = 205;
  public final static int OPEN2 = 206;

  public static String nameOf(int value) {
    if (value == 204) return "AnimationDoor.CLOSE";
    if (value == 207) return "AnimationDoor.DESTROY";
    if (value == 205) return "AnimationDoor.OPEN1";
    if (value == 206) return "AnimationDoor.OPEN2";
    return "AnimationDoor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AnimationDoor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AnimationDoor.(not found: " + value + ")";
  }
}
