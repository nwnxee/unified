package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_MINOTAUR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeMinotaur {
  private AppearanceTypeMinotaur() {}

  public final static int APPEARANCE_TYPE_MINOTAUR = 120;
  public final static int CHIEFTAIN = 121;
  public final static int SHAMAN = 122;

  public static String nameOf(int value) {
    if (value == 120) return "AppearanceTypeMinotaur.APPEARANCE_TYPE_MINOTAUR";
    if (value == 121) return "AppearanceTypeMinotaur.CHIEFTAIN";
    if (value == 122) return "AppearanceTypeMinotaur.SHAMAN";
    return "AppearanceTypeMinotaur.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeMinotaur.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeMinotaur.(not found: " + value + ")";
  }
}
