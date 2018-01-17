package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_DRAGON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeDragon {
  private AppearanceTypeDragon() {}

  public final static int BLACK = 41;
  public final static int BLUE = 47;
  public final static int BRASS = 42;
  public final static int BRONZE = 45;
  public final static int COPPER = 43;
  public final static int GOLD = 46;
  public final static int GREEN = 48;
  public final static int PRIS = 425;
  public final static int RED = 49;
  public final static int SHADOW = 418;
  public final static int SILVER = 44;
  public final static int WHITE = 50;

  public static String nameOf(int value) {
    if (value == 41) return "AppearanceTypeDragon.BLACK";
    if (value == 47) return "AppearanceTypeDragon.BLUE";
    if (value == 42) return "AppearanceTypeDragon.BRASS";
    if (value == 45) return "AppearanceTypeDragon.BRONZE";
    if (value == 43) return "AppearanceTypeDragon.COPPER";
    if (value == 46) return "AppearanceTypeDragon.GOLD";
    if (value == 48) return "AppearanceTypeDragon.GREEN";
    if (value == 425) return "AppearanceTypeDragon.PRIS";
    if (value == 49) return "AppearanceTypeDragon.RED";
    if (value == 418) return "AppearanceTypeDragon.SHADOW";
    if (value == 44) return "AppearanceTypeDragon.SILVER";
    if (value == 50) return "AppearanceTypeDragon.WHITE";
    return "AppearanceTypeDragon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeDragon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeDragon.(not found: " + value + ")";
  }
}
