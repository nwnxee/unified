package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_BEETLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeBeetle {
  private AppearanceTypeBeetle() {}

  public final static int FIRE = 18;
  public final static int SLICER = 17;
  public final static int STAG = 19;
  public final static int STINK = 20;

  public static String nameOf(int value) {
    if (value == 18) return "AppearanceTypeBeetle.FIRE";
    if (value == 17) return "AppearanceTypeBeetle.SLICER";
    if (value == 19) return "AppearanceTypeBeetle.STAG";
    if (value == 20) return "AppearanceTypeBeetle.STINK";
    return "AppearanceTypeBeetle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeBeetle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeBeetle.(not found: " + value + ")";
  }
}
