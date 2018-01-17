package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PARTIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPartial {
  private FeatPartial() {}

  public final static int SKILL_AFFINITY_LISTEN = 244;
  public final static int SKILL_AFFINITY_SEARCH = 245;
  public final static int SKILL_AFFINITY_SPOT = 246;

  public static String nameOf(int value) {
    if (value == 244) return "FeatPartial.SKILL_AFFINITY_LISTEN";
    if (value == 245) return "FeatPartial.SKILL_AFFINITY_SEARCH";
    if (value == 246) return "FeatPartial.SKILL_AFFINITY_SPOT";
    return "FeatPartial.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPartial.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPartial.(not found: " + value + ")";
  }
}
