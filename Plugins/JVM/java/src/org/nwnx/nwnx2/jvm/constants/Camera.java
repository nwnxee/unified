package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CAMERA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Camera {
  private Camera() {}

  public final static int MODE_CHASE_CAMERA = 0;
  public final static int MODE_STIFF_CHASE_CAMERA = 2;
  public final static int MODE_TOP_DOWN = 1;
  public final static int TRANSITION_TYPE_CRAWL = 2;
  public final static int TRANSITION_TYPE_FAST = 70;
  public final static int TRANSITION_TYPE_MEDIUM = 40;
  public final static int TRANSITION_TYPE_SLOW = 20;
  public final static int TRANSITION_TYPE_SNAP = 0;
  public final static int TRANSITION_TYPE_VERY_FAST = 100;
  public final static int TRANSITION_TYPE_VERY_SLOW = 5;

  public static String nameOf(int value) {
    if (value == 0) return "Camera.MODE_CHASE_CAMERA";
    if (value == 2) return "Camera.MODE_STIFF_CHASE_CAMERA";
    if (value == 1) return "Camera.MODE_TOP_DOWN";
    if (value == 2) return "Camera.TRANSITION_TYPE_CRAWL";
    if (value == 70) return "Camera.TRANSITION_TYPE_FAST";
    if (value == 40) return "Camera.TRANSITION_TYPE_MEDIUM";
    if (value == 20) return "Camera.TRANSITION_TYPE_SLOW";
    if (value == 0) return "Camera.TRANSITION_TYPE_SNAP";
    if (value == 100) return "Camera.TRANSITION_TYPE_VERY_FAST";
    if (value == 5) return "Camera.TRANSITION_TYPE_VERY_SLOW";
    return "Camera.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Camera.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Camera.(not found: " + value + ")";
  }
}
