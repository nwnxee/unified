package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SKILL_CRAFT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SkillCraft {
  private SkillCraft() {}

  public final static int ARMOR = 25;
  public final static int TRAP = 22;
  public final static int WEAPON = 26;

  public static String nameOf(int value) {
    if (value == 25) return "SkillCraft.ARMOR";
    if (value == 22) return "SkillCraft.TRAP";
    if (value == 26) return "SkillCraft.WEAPON";
    return "SkillCraft.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SkillCraft.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SkillCraft.(not found: " + value + ")";
  }
}
