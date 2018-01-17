package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_OCHRE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeOchre {
  private AppearanceTypeOchre() {}

  public final static int JELLY_LARGE = 394;
  public final static int JELLY_MEDIUM = 396;
  public final static int JELLY_SMALL = 398;

  public static String nameOf(int value) {
    if (value == 394) return "AppearanceTypeOchre.JELLY_LARGE";
    if (value == 396) return "AppearanceTypeOchre.JELLY_MEDIUM";
    if (value == 398) return "AppearanceTypeOchre.JELLY_SMALL";
    return "AppearanceTypeOchre.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeOchre.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeOchre.(not found: " + value + ")";
  }
}
