package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_OCHRE_JELLY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeOchreJelly {
  private AppearanceTypeOchreJelly() {}

  public final static int LARGE = 394;
  public final static int MEDIUM = 396;
  public final static int SMALL = 398;

  public static String nameOf(int value) {
    if (value == 394) return "AppearanceTypeOchreJelly.LARGE";
    if (value == 396) return "AppearanceTypeOchreJelly.MEDIUM";
    if (value == 398) return "AppearanceTypeOchreJelly.SMALL";
    return "AppearanceTypeOchreJelly.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeOchreJelly.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeOchreJelly.(not found: " + value + ")";
  }
}
