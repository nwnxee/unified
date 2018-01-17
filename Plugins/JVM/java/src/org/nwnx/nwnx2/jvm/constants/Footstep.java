package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FOOTSTEP".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Footstep {
  private Footstep() {}

  public final static int TYPE_BEETLE = 6;
  public final static int TYPE_DEFAULT = 65535;
  public final static int TYPE_DRAGON = 2;
  public final static int TYPE_FEATHER_WING = 10;
  public final static int TYPE_HOOF = 4;
  public final static int TYPE_HOOF_LARGE = 5;
  public final static int TYPE_HORSE = 17;
  public final static int TYPE_INVALID = -1;
  public final static int TYPE_LARGE = 1;
  public final static int TYPE_LEATHER_WING = 9;
  public final static int TYPE_NONE = 12;
  public final static int TYPE_NORMAL = 0;
  public final static int TYPE_SEAGULL = 13;
  public final static int TYPE_SHARK = 14;
  public final static int TYPE_SKELETON = 8;
  public final static int TYPE_SOFT = 3;
  public final static int TYPE_SPIDER = 7;
  public final static int TYPE_WATER_LARGE = 16;
  public final static int TYPE_WATER_NORMAL = 15;

  public static String nameOf(int value) {
    if (value == 6) return "Footstep.TYPE_BEETLE";
    if (value == 65535) return "Footstep.TYPE_DEFAULT";
    if (value == 2) return "Footstep.TYPE_DRAGON";
    if (value == 10) return "Footstep.TYPE_FEATHER_WING";
    if (value == 4) return "Footstep.TYPE_HOOF";
    if (value == 5) return "Footstep.TYPE_HOOF_LARGE";
    if (value == 17) return "Footstep.TYPE_HORSE";
    if (value == -1) return "Footstep.TYPE_INVALID";
    if (value == 1) return "Footstep.TYPE_LARGE";
    if (value == 9) return "Footstep.TYPE_LEATHER_WING";
    if (value == 12) return "Footstep.TYPE_NONE";
    if (value == 0) return "Footstep.TYPE_NORMAL";
    if (value == 13) return "Footstep.TYPE_SEAGULL";
    if (value == 14) return "Footstep.TYPE_SHARK";
    if (value == 8) return "Footstep.TYPE_SKELETON";
    if (value == 3) return "Footstep.TYPE_SOFT";
    if (value == 7) return "Footstep.TYPE_SPIDER";
    if (value == 16) return "Footstep.TYPE_WATER_LARGE";
    if (value == 15) return "Footstep.TYPE_WATER_NORMAL";
    return "Footstep.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Footstep.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Footstep.(not found: " + value + ")";
  }
}
