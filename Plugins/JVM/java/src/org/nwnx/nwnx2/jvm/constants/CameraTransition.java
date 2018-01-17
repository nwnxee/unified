package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CAMERA_TRANSITION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CameraTransition {
  private CameraTransition() {}

  public final static int TYPE_CRAWL = 2;
  public final static int TYPE_FAST = 70;
  public final static int TYPE_MEDIUM = 40;
  public final static int TYPE_SLOW = 20;
  public final static int TYPE_SNAP = 0;
  public final static int TYPE_VERY_FAST = 100;
  public final static int TYPE_VERY_SLOW = 5;

  public static String nameOf(int value) {
    if (value == 2) return "CameraTransition.TYPE_CRAWL";
    if (value == 70) return "CameraTransition.TYPE_FAST";
    if (value == 40) return "CameraTransition.TYPE_MEDIUM";
    if (value == 20) return "CameraTransition.TYPE_SLOW";
    if (value == 0) return "CameraTransition.TYPE_SNAP";
    if (value == 100) return "CameraTransition.TYPE_VERY_FAST";
    if (value == 5) return "CameraTransition.TYPE_VERY_SLOW";
    return "CameraTransition.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CameraTransition.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CameraTransition.(not found: " + value + ")";
  }
}
