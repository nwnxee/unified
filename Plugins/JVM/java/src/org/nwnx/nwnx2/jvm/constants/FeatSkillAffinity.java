package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SKILL_AFFINITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSkillAffinity {
  private FeatSkillAffinity() {}

  public final static int CONCENTRATION = 243;
  public final static int LISTEN = 237;
  public final static int LORE = 234;
  public final static int MOVE_SILENTLY = 247;
  public final static int SEARCH = 238;
  public final static int SPOT = 239;

  public static String nameOf(int value) {
    if (value == 243) return "FeatSkillAffinity.CONCENTRATION";
    if (value == 237) return "FeatSkillAffinity.LISTEN";
    if (value == 234) return "FeatSkillAffinity.LORE";
    if (value == 247) return "FeatSkillAffinity.MOVE_SILENTLY";
    if (value == 238) return "FeatSkillAffinity.SEARCH";
    if (value == 239) return "FeatSkillAffinity.SPOT";
    return "FeatSkillAffinity.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSkillAffinity.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSkillAffinity.(not found: " + value + ")";
  }
}
