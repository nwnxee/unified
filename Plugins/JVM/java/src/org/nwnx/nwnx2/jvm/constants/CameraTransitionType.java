package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CAMERA_TRANSITION_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CameraTransitionType {
  private CameraTransitionType() {}

  public final static int CRAWL = 2;
  public final static int FAST = 70;
  public final static int MEDIUM = 40;
  public final static int SLOW = 20;
  public final static int SNAP = 0;
  public final static int VERY_FAST = 100;
  public final static int VERY_SLOW = 5;

  public static String nameOf(int value) {
    if (value == 2) return "CameraTransitionType.CRAWL";
    if (value == 70) return "CameraTransitionType.FAST";
    if (value == 40) return "CameraTransitionType.MEDIUM";
    if (value == 20) return "CameraTransitionType.SLOW";
    if (value == 0) return "CameraTransitionType.SNAP";
    if (value == 100) return "CameraTransitionType.VERY_FAST";
    if (value == 5) return "CameraTransitionType.VERY_SLOW";
    return "CameraTransitionType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CameraTransitionType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CameraTransitionType.(not found: " + value + ")";
  }
}
