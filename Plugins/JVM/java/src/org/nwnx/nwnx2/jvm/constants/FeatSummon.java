package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SUMMON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSummon {
  private FeatSummon() {}

  public final static int FAMILIAR = 303;
  public final static int GREATER_UNDEAD = 895;
  public final static int SHADOW = 435;
  public final static int UNDEAD = 890;

  public static String nameOf(int value) {
    if (value == 303) return "FeatSummon.FAMILIAR";
    if (value == 895) return "FeatSummon.GREATER_UNDEAD";
    if (value == 435) return "FeatSummon.SHADOW";
    if (value == 890) return "FeatSummon.UNDEAD";
    return "FeatSummon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSummon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSummon.(not found: " + value + ")";
  }
}
