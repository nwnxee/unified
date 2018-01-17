package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PROJECTILE_PATH_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ProjectilePathType {
  private ProjectilePathType() {}

  public final static int ACCELERATING = 4;
  public final static int BALLISTIC = 2;
  public final static int DEFAULT = 0;
  public final static int HIGH_BALLISTIC = 3;
  public final static int HOMING = 1;

  public static String nameOf(int value) {
    if (value == 4) return "ProjectilePathType.ACCELERATING";
    if (value == 2) return "ProjectilePathType.BALLISTIC";
    if (value == 0) return "ProjectilePathType.DEFAULT";
    if (value == 3) return "ProjectilePathType.HIGH_BALLISTIC";
    if (value == 1) return "ProjectilePathType.HOMING";
    return "ProjectilePathType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ProjectilePathType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ProjectilePathType.(not found: " + value + ")";
  }
}
