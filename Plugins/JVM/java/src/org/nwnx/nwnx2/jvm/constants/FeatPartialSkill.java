package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PARTIAL_SKILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPartialSkill {
  private FeatPartialSkill() {}

  public final static int AFFINITY_LISTEN = 244;
  public final static int AFFINITY_SEARCH = 245;
  public final static int AFFINITY_SPOT = 246;

  public static String nameOf(int value) {
    if (value == 244) return "FeatPartialSkill.AFFINITY_LISTEN";
    if (value == 245) return "FeatPartialSkill.AFFINITY_SEARCH";
    if (value == 246) return "FeatPartialSkill.AFFINITY_SPOT";
    return "FeatPartialSkill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPartialSkill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPartialSkill.(not found: " + value + ")";
  }
}
