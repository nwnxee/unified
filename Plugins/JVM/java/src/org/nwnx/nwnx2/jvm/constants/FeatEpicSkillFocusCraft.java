package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SKILL_FOCUS_CRAFT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSkillFocusCraft {
  private FeatEpicSkillFocusCraft() {}

  public final static int ARMOR = 913;
  public final static int TRAP = 590;
  public final static int WEAPON = 914;

  public static String nameOf(int value) {
    if (value == 913) return "FeatEpicSkillFocusCraft.ARMOR";
    if (value == 590) return "FeatEpicSkillFocusCraft.TRAP";
    if (value == 914) return "FeatEpicSkillFocusCraft.WEAPON";
    return "FeatEpicSkillFocusCraft.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSkillFocusCraft.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSkillFocusCraft.(not found: " + value + ")";
  }
}
