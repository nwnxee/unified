package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SHOU".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatShou {
  private FeatShou() {}

  public final static int DISCIPLE_DODGE_2 = 489;
  public final static int DISCIPLE_DODGE_3 = 1031;
  public final static int DISCIPLE_MARTIAL_FLURRY_ANY = 899;
  public final static int DISCIPLE_MARTIAL_FLURRY_LIGHT = 866;

  public static String nameOf(int value) {
    if (value == 489) return "FeatShou.DISCIPLE_DODGE_2";
    if (value == 1031) return "FeatShou.DISCIPLE_DODGE_3";
    if (value == 899) return "FeatShou.DISCIPLE_MARTIAL_FLURRY_ANY";
    if (value == 866) return "FeatShou.DISCIPLE_MARTIAL_FLURRY_LIGHT";
    return "FeatShou.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatShou.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatShou.(not found: " + value + ")";
  }
}
