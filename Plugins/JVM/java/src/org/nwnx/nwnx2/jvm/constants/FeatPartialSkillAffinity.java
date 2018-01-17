package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PARTIAL_SKILL_AFFINITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPartialSkillAffinity {
  private FeatPartialSkillAffinity() {}

  public final static int LISTEN = 244;
  public final static int SEARCH = 245;
  public final static int SPOT = 246;

  public static String nameOf(int value) {
    if (value == 244) return "FeatPartialSkillAffinity.LISTEN";
    if (value == 245) return "FeatPartialSkillAffinity.SEARCH";
    if (value == 246) return "FeatPartialSkillAffinity.SPOT";
    return "FeatPartialSkillAffinity.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPartialSkillAffinity.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPartialSkillAffinity.(not found: " + value + ")";
  }
}
