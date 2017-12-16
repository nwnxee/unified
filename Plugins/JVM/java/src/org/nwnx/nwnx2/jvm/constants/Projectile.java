package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PROJECTILE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Projectile {
  private Projectile() {}

  public final static int PATH_TYPE_ACCELERATING = 4;
  public final static int PATH_TYPE_BALLISTIC = 2;
  public final static int PATH_TYPE_DEFAULT = 0;
  public final static int PATH_TYPE_HIGH_BALLISTIC = 3;
  public final static int PATH_TYPE_HOMING = 1;

  public static String nameOf(int value) {
    if (value == 4) return "Projectile.PATH_TYPE_ACCELERATING";
    if (value == 2) return "Projectile.PATH_TYPE_BALLISTIC";
    if (value == 0) return "Projectile.PATH_TYPE_DEFAULT";
    if (value == 3) return "Projectile.PATH_TYPE_HIGH_BALLISTIC";
    if (value == 1) return "Projectile.PATH_TYPE_HOMING";
    return "Projectile.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Projectile.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Projectile.(not found: " + value + ")";
  }
}
