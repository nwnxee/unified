package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SHOU_DISCIPLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatShouDisciple {
  private FeatShouDisciple() {}

  public final static int DODGE_2 = 489;
  public final static int DODGE_3 = 1031;
  public final static int MARTIAL_FLURRY_ANY = 899;
  public final static int MARTIAL_FLURRY_LIGHT = 866;

  public static String nameOf(int value) {
    if (value == 489) return "FeatShouDisciple.DODGE_2";
    if (value == 1031) return "FeatShouDisciple.DODGE_3";
    if (value == 899) return "FeatShouDisciple.MARTIAL_FLURRY_ANY";
    if (value == 866) return "FeatShouDisciple.MARTIAL_FLURRY_LIGHT";
    return "FeatShouDisciple.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatShouDisciple.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatShouDisciple.(not found: " + value + ")";
  }
}
