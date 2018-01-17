package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SKILL_FOCUS_CRAFT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSkillFocusCraft {
  private FeatSkillFocusCraft() {}

  public final static int ARMOR = 911;
  public final static int TRAP = 407;
  public final static int WEAPON = 912;

  public static String nameOf(int value) {
    if (value == 911) return "FeatSkillFocusCraft.ARMOR";
    if (value == 407) return "FeatSkillFocusCraft.TRAP";
    if (value == 912) return "FeatSkillFocusCraft.WEAPON";
    return "FeatSkillFocusCraft.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSkillFocusCraft.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSkillFocusCraft.(not found: " + value + ")";
  }
}
