package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PROJECTILE_PATH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ProjectilePath {
  private ProjectilePath() {}

  public final static int TYPE_ACCELERATING = 4;
  public final static int TYPE_BALLISTIC = 2;
  public final static int TYPE_DEFAULT = 0;
  public final static int TYPE_HIGH_BALLISTIC = 3;
  public final static int TYPE_HOMING = 1;

  public static String nameOf(int value) {
    if (value == 4) return "ProjectilePath.TYPE_ACCELERATING";
    if (value == 2) return "ProjectilePath.TYPE_BALLISTIC";
    if (value == 0) return "ProjectilePath.TYPE_DEFAULT";
    if (value == 3) return "ProjectilePath.TYPE_HIGH_BALLISTIC";
    if (value == 1) return "ProjectilePath.TYPE_HOMING";
    return "ProjectilePath.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ProjectilePath.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ProjectilePath.(not found: " + value + ")";
  }
}
