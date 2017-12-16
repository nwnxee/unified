package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_YUAN_TI".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeYuanTi {
  private AppearanceTypeYuanTi() {}

  public final static int APPEARANCE_TYPE_YUAN_TI = 285;
  public final static int CHIEFTEN = 286;
  public final static int WIZARD = 287;

  public static String nameOf(int value) {
    if (value == 285) return "AppearanceTypeYuanTi.APPEARANCE_TYPE_YUAN_TI";
    if (value == 286) return "AppearanceTypeYuanTi.CHIEFTEN";
    if (value == 287) return "AppearanceTypeYuanTi.WIZARD";
    return "AppearanceTypeYuanTi.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeYuanTi.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeYuanTi.(not found: " + value + ")";
  }
}
