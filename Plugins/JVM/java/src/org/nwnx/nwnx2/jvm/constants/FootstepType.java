package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FOOTSTEP_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FootstepType {
  private FootstepType() {}

  public final static int BEETLE = 6;
  public final static int DEFAULT = 65535;
  public final static int DRAGON = 2;
  public final static int FEATHER_WING = 10;
  public final static int HOOF = 4;
  public final static int HOOF_LARGE = 5;
  public final static int HORSE = 17;
  public final static int INVALID = -1;
  public final static int LARGE = 1;
  public final static int LEATHER_WING = 9;
  public final static int NONE = 12;
  public final static int NORMAL = 0;
  public final static int SEAGULL = 13;
  public final static int SHARK = 14;
  public final static int SKELETON = 8;
  public final static int SOFT = 3;
  public final static int SPIDER = 7;
  public final static int WATER_LARGE = 16;
  public final static int WATER_NORMAL = 15;

  public static String nameOf(int value) {
    if (value == 6) return "FootstepType.BEETLE";
    if (value == 65535) return "FootstepType.DEFAULT";
    if (value == 2) return "FootstepType.DRAGON";
    if (value == 10) return "FootstepType.FEATHER_WING";
    if (value == 4) return "FootstepType.HOOF";
    if (value == 5) return "FootstepType.HOOF_LARGE";
    if (value == 17) return "FootstepType.HORSE";
    if (value == -1) return "FootstepType.INVALID";
    if (value == 1) return "FootstepType.LARGE";
    if (value == 9) return "FootstepType.LEATHER_WING";
    if (value == 12) return "FootstepType.NONE";
    if (value == 0) return "FootstepType.NORMAL";
    if (value == 13) return "FootstepType.SEAGULL";
    if (value == 14) return "FootstepType.SHARK";
    if (value == 8) return "FootstepType.SKELETON";
    if (value == 3) return "FootstepType.SOFT";
    if (value == 7) return "FootstepType.SPIDER";
    if (value == 16) return "FootstepType.WATER_LARGE";
    if (value == 15) return "FootstepType.WATER_NORMAL";
    return "FootstepType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FootstepType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FootstepType.(not found: " + value + ")";
  }
}
