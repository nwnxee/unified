package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_WYRMLING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeWyrmling {
  private AppearanceTypeWyrmling() {}

  public final static int BLACK = 378;
  public final static int BLUE = 377;
  public final static int BRASS = 381;
  public final static int BRONZE = 383;
  public final static int COPPER = 382;
  public final static int GOLD = 385;
  public final static int GREEN = 379;
  public final static int RED = 376;
  public final static int SILVER = 384;
  public final static int WHITE = 380;

  public static String nameOf(int value) {
    if (value == 378) return "AppearanceTypeWyrmling.BLACK";
    if (value == 377) return "AppearanceTypeWyrmling.BLUE";
    if (value == 381) return "AppearanceTypeWyrmling.BRASS";
    if (value == 383) return "AppearanceTypeWyrmling.BRONZE";
    if (value == 382) return "AppearanceTypeWyrmling.COPPER";
    if (value == 385) return "AppearanceTypeWyrmling.GOLD";
    if (value == 379) return "AppearanceTypeWyrmling.GREEN";
    if (value == 376) return "AppearanceTypeWyrmling.RED";
    if (value == 384) return "AppearanceTypeWyrmling.SILVER";
    if (value == 380) return "AppearanceTypeWyrmling.WHITE";
    return "AppearanceTypeWyrmling.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeWyrmling.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeWyrmling.(not found: " + value + ")";
  }
}
