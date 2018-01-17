package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_YUAN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeYuan {
  private AppearanceTypeYuan() {}

  public final static int TI = 285;
  public final static int TI_CHIEFTEN = 286;
  public final static int TI_WIZARD = 287;

  public static String nameOf(int value) {
    if (value == 285) return "AppearanceTypeYuan.TI";
    if (value == 286) return "AppearanceTypeYuan.TI_CHIEFTEN";
    if (value == 287) return "AppearanceTypeYuan.TI_WIZARD";
    return "AppearanceTypeYuan.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeYuan.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeYuan.(not found: " + value + ")";
  }
}
