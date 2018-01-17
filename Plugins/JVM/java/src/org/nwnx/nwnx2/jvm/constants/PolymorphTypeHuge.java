package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE_HUGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphTypeHuge {
  private PolymorphTypeHuge() {}

  public final static int AIR_ELEMENTAL = 16;
  public final static int EARTH_ELEMENTAL = 15;
  public final static int FIRE_ELEMENTAL = 13;
  public final static int WATER_ELEMENTAL = 14;

  public static String nameOf(int value) {
    if (value == 16) return "PolymorphTypeHuge.AIR_ELEMENTAL";
    if (value == 15) return "PolymorphTypeHuge.EARTH_ELEMENTAL";
    if (value == 13) return "PolymorphTypeHuge.FIRE_ELEMENTAL";
    if (value == 14) return "PolymorphTypeHuge.WATER_ELEMENTAL";
    return "PolymorphTypeHuge.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphTypeHuge.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphTypeHuge.(not found: " + value + ")";
  }
}
