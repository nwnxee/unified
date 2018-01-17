package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_FORMIAN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeFormian {
  private AppearanceTypeFormian() {}

  public final static int MYRMARCH = 362;
  public final static int QUEEN = 363;
  public final static int WARRIOR = 361;
  public final static int WORKER = 360;

  public static String nameOf(int value) {
    if (value == 362) return "AppearanceTypeFormian.MYRMARCH";
    if (value == 363) return "AppearanceTypeFormian.QUEEN";
    if (value == 361) return "AppearanceTypeFormian.WARRIOR";
    if (value == 360) return "AppearanceTypeFormian.WORKER";
    return "AppearanceTypeFormian.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeFormian.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeFormian.(not found: " + value + ")";
  }
}
