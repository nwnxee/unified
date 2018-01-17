package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_DROW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeDrow {
  private AppearanceTypeDrow() {}

  public final static int CLERIC = 215;
  public final static int FEMALE_1 = 478;
  public final static int FEMALE_2 = 479;
  public final static int FIGHTER = 216;
  public final static int MATRON = 410;
  public final static int SLAVE = 408;
  public final static int WARRIOR_1 = 476;
  public final static int WARRIOR_2 = 477;
  public final static int WARRIOR_3 = 480;
  public final static int WIZARD = 409;

  public static String nameOf(int value) {
    if (value == 215) return "AppearanceTypeDrow.CLERIC";
    if (value == 478) return "AppearanceTypeDrow.FEMALE_1";
    if (value == 479) return "AppearanceTypeDrow.FEMALE_2";
    if (value == 216) return "AppearanceTypeDrow.FIGHTER";
    if (value == 410) return "AppearanceTypeDrow.MATRON";
    if (value == 408) return "AppearanceTypeDrow.SLAVE";
    if (value == 476) return "AppearanceTypeDrow.WARRIOR_1";
    if (value == 477) return "AppearanceTypeDrow.WARRIOR_2";
    if (value == 480) return "AppearanceTypeDrow.WARRIOR_3";
    if (value == 409) return "AppearanceTypeDrow.WIZARD";
    return "AppearanceTypeDrow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeDrow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeDrow.(not found: " + value + ")";
  }
}
