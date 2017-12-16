package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CAMERA_MODE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CameraMode {
  private CameraMode() {}

  public final static int CHASE_CAMERA = 0;
  public final static int STIFF_CHASE_CAMERA = 2;
  public final static int TOP_DOWN = 1;

  public static String nameOf(int value) {
    if (value == 0) return "CameraMode.CHASE_CAMERA";
    if (value == 2) return "CameraMode.STIFF_CHASE_CAMERA";
    if (value == 1) return "CameraMode.TOP_DOWN";
    return "CameraMode.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CameraMode.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CameraMode.(not found: " + value + ")";
  }
}
