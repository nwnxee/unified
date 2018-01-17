package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_ASABI".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeAsabi {
  private AppearanceTypeAsabi() {}

  public final static int CHIEFTAIN = 353;
  public final static int SHAMAN = 354;
  public final static int WARRIOR = 355;

  public static String nameOf(int value) {
    if (value == 353) return "AppearanceTypeAsabi.CHIEFTAIN";
    if (value == 354) return "AppearanceTypeAsabi.SHAMAN";
    if (value == 355) return "AppearanceTypeAsabi.WARRIOR";
    return "AppearanceTypeAsabi.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeAsabi.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeAsabi.(not found: " + value + ")";
  }
}
