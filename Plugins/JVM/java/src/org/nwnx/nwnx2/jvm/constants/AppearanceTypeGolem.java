package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_GOLEM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeGolem {
  private AppearanceTypeGolem() {}

  public final static int ADAMANTIUM = 421;
  public final static int BONE = 24;
  public final static int CLAY = 91;
  public final static int DEMONFLESH = 468;
  public final static int FLESH = 88;
  public final static int IRON = 89;
  public final static int MITHRAL = 420;
  public final static int STONE = 92;

  public static String nameOf(int value) {
    if (value == 421) return "AppearanceTypeGolem.ADAMANTIUM";
    if (value == 24) return "AppearanceTypeGolem.BONE";
    if (value == 91) return "AppearanceTypeGolem.CLAY";
    if (value == 468) return "AppearanceTypeGolem.DEMONFLESH";
    if (value == 88) return "AppearanceTypeGolem.FLESH";
    if (value == 89) return "AppearanceTypeGolem.IRON";
    if (value == 420) return "AppearanceTypeGolem.MITHRAL";
    if (value == 92) return "AppearanceTypeGolem.STONE";
    return "AppearanceTypeGolem.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeGolem.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeGolem.(not found: " + value + ")";
  }
}
