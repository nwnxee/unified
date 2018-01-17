package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DIRECTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Direction {
  private Direction() {}

  public final static float EAST = 0.0f;
  public final static float NORTH = 90.0f;
  public final static float SOUTH = 270.0f;
  public final static float WEST = 180.0f;

  public static String nameOf(int value) {
    return "Direction.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    if (value == 0.0) return "Direction.EAST";
    if (value == 90.0) return "Direction.NORTH";
    if (value == 270.0) return "Direction.SOUTH";
    if (value == 180.0) return "Direction.WEST";
    return "Direction.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Direction.(not found: " + value + ")";
  }
}
