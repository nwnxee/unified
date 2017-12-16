package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE_ELDER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphTypeElder {
  private PolymorphTypeElder() {}

  public final static int AIR_ELEMENTAL = 20;
  public final static int EARTH_ELEMENTAL = 19;
  public final static int FIRE_ELEMENTAL = 17;
  public final static int WATER_ELEMENTAL = 18;

  public static String nameOf(int value) {
    if (value == 20) return "PolymorphTypeElder.AIR_ELEMENTAL";
    if (value == 19) return "PolymorphTypeElder.EARTH_ELEMENTAL";
    if (value == 17) return "PolymorphTypeElder.FIRE_ELEMENTAL";
    if (value == 18) return "PolymorphTypeElder.WATER_ELEMENTAL";
    return "PolymorphTypeElder.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphTypeElder.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphTypeElder.(not found: " + value + ")";
  }
}
