package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_DOG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeDog {
  private AppearanceTypeDog() {}

  public final static int APPEARANCE_TYPE_DOG = 176;
  public final static int BLINKDOG = 174;
  public final static int DIRE_WOLF = 175;
  public final static int FENHOUND = 177;
  public final static int HELL_HOUND = 179;
  public final static int SHADOW_MASTIF = 180;
  public final static int WINTER_WOLF = 184;
  public final static int WOLF = 181;
  public final static int WORG = 185;

  public static String nameOf(int value) {
    if (value == 176) return "AppearanceTypeDog.APPEARANCE_TYPE_DOG";
    if (value == 174) return "AppearanceTypeDog.BLINKDOG";
    if (value == 175) return "AppearanceTypeDog.DIRE_WOLF";
    if (value == 177) return "AppearanceTypeDog.FENHOUND";
    if (value == 179) return "AppearanceTypeDog.HELL_HOUND";
    if (value == 180) return "AppearanceTypeDog.SHADOW_MASTIF";
    if (value == 184) return "AppearanceTypeDog.WINTER_WOLF";
    if (value == 181) return "AppearanceTypeDog.WOLF";
    if (value == 185) return "AppearanceTypeDog.WORG";
    return "AppearanceTypeDog.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeDog.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeDog.(not found: " + value + ")";
  }
}
