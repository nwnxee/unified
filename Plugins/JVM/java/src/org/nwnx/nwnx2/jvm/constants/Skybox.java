package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SKYBOX".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Skybox {
  private Skybox() {}

  public final static int DESERT_CLEAR = 3;
  public final static int GRASS_CLEAR = 1;
  public final static int GRASS_STORM = 2;
  public final static int ICY = 5;
  public final static int NONE = 0;
  public final static int WINTER_CLEAR = 4;

  public static String nameOf(int value) {
    if (value == 3) return "Skybox.DESERT_CLEAR";
    if (value == 1) return "Skybox.GRASS_CLEAR";
    if (value == 2) return "Skybox.GRASS_STORM";
    if (value == 5) return "Skybox.ICY";
    if (value == 0) return "Skybox.NONE";
    if (value == 4) return "Skybox.WINTER_CLEAR";
    return "Skybox.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Skybox.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Skybox.(not found: " + value + ")";
  }
}
