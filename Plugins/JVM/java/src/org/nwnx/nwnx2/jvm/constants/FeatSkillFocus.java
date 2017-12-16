package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SKILL_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSkillFocus {
  private FeatSkillFocus() {}

  public final static int ANIMAL_EMPATHY = 34;
  public final static int BLUFF = 915;
  public final static int CONCENTRATION = 173;
  public final static int CRAFT_ARMOR = 911;
  public final static int CRAFT_TRAP = 407;
  public final static int CRAFT_WEAPON = 912;
  public final static int DISABLE_TRAP = 174;
  public final static int DISCIPLINE = 175;
  public final static int HEAL = 177;
  public final static int HIDE = 178;
  public final static int INTIMIDATE = 916;
  public final static int LISTEN = 179;
  public final static int LORE = 180;
  public final static int MOVE_SILENTLY = 181;
  public final static int OPEN_LOCK = 182;
  public final static int PARRY = 183;
  public final static int PERFORM = 184;
  public final static int PERSUADE = 185;
  public final static int PICK_POCKET = 186;
  public final static int SEARCH = 187;
  public final static int SET_TRAP = 188;
  public final static int SPELLCRAFT = 189;
  public final static int SPOT = 190;
  public final static int TAUNT = 192;
  public final static int TUMBLE = 406;
  public final static int USE_MAGIC_DEVICE = 193;

  public static String nameOf(int value) {
    if (value == 34) return "FeatSkillFocus.ANIMAL_EMPATHY";
    if (value == 915) return "FeatSkillFocus.BLUFF";
    if (value == 173) return "FeatSkillFocus.CONCENTRATION";
    if (value == 911) return "FeatSkillFocus.CRAFT_ARMOR";
    if (value == 407) return "FeatSkillFocus.CRAFT_TRAP";
    if (value == 912) return "FeatSkillFocus.CRAFT_WEAPON";
    if (value == 174) return "FeatSkillFocus.DISABLE_TRAP";
    if (value == 175) return "FeatSkillFocus.DISCIPLINE";
    if (value == 177) return "FeatSkillFocus.HEAL";
    if (value == 178) return "FeatSkillFocus.HIDE";
    if (value == 916) return "FeatSkillFocus.INTIMIDATE";
    if (value == 179) return "FeatSkillFocus.LISTEN";
    if (value == 180) return "FeatSkillFocus.LORE";
    if (value == 181) return "FeatSkillFocus.MOVE_SILENTLY";
    if (value == 182) return "FeatSkillFocus.OPEN_LOCK";
    if (value == 183) return "FeatSkillFocus.PARRY";
    if (value == 184) return "FeatSkillFocus.PERFORM";
    if (value == 185) return "FeatSkillFocus.PERSUADE";
    if (value == 186) return "FeatSkillFocus.PICK_POCKET";
    if (value == 187) return "FeatSkillFocus.SEARCH";
    if (value == 188) return "FeatSkillFocus.SET_TRAP";
    if (value == 189) return "FeatSkillFocus.SPELLCRAFT";
    if (value == 190) return "FeatSkillFocus.SPOT";
    if (value == 192) return "FeatSkillFocus.TAUNT";
    if (value == 406) return "FeatSkillFocus.TUMBLE";
    if (value == 193) return "FeatSkillFocus.USE_MAGIC_DEVICE";
    return "FeatSkillFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSkillFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSkillFocus.(not found: " + value + ")";
  }
}
