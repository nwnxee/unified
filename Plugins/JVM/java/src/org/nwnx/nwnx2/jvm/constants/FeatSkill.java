package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SKILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSkill {
  private FeatSkill() {}

  public final static int AFFINITY_CONCENTRATION = 243;
  public final static int AFFINITY_LISTEN = 237;
  public final static int AFFINITY_LORE = 234;
  public final static int AFFINITY_MOVE_SILENTLY = 247;
  public final static int AFFINITY_SEARCH = 238;
  public final static int AFFINITY_SPOT = 239;
  public final static int FOCUS_ANIMAL_EMPATHY = 34;
  public final static int FOCUS_BLUFF = 915;
  public final static int FOCUS_CONCENTRATION = 173;
  public final static int FOCUS_CRAFT_ARMOR = 911;
  public final static int FOCUS_CRAFT_TRAP = 407;
  public final static int FOCUS_CRAFT_WEAPON = 912;
  public final static int FOCUS_DISABLE_TRAP = 174;
  public final static int FOCUS_DISCIPLINE = 175;
  public final static int FOCUS_HEAL = 177;
  public final static int FOCUS_HIDE = 178;
  public final static int FOCUS_INTIMIDATE = 916;
  public final static int FOCUS_LISTEN = 179;
  public final static int FOCUS_LORE = 180;
  public final static int FOCUS_MOVE_SILENTLY = 181;
  public final static int FOCUS_OPEN_LOCK = 182;
  public final static int FOCUS_PARRY = 183;
  public final static int FOCUS_PERFORM = 184;
  public final static int FOCUS_PERSUADE = 185;
  public final static int FOCUS_PICK_POCKET = 186;
  public final static int FOCUS_SEARCH = 187;
  public final static int FOCUS_SET_TRAP = 188;
  public final static int FOCUS_SPELLCRAFT = 189;
  public final static int FOCUS_SPOT = 190;
  public final static int FOCUS_TAUNT = 192;
  public final static int FOCUS_TUMBLE = 406;
  public final static int FOCUS_USE_MAGIC_DEVICE = 193;
  public final static int MASTERY = 225;

  public static String nameOf(int value) {
    if (value == 243) return "FeatSkill.AFFINITY_CONCENTRATION";
    if (value == 237) return "FeatSkill.AFFINITY_LISTEN";
    if (value == 234) return "FeatSkill.AFFINITY_LORE";
    if (value == 247) return "FeatSkill.AFFINITY_MOVE_SILENTLY";
    if (value == 238) return "FeatSkill.AFFINITY_SEARCH";
    if (value == 239) return "FeatSkill.AFFINITY_SPOT";
    if (value == 34) return "FeatSkill.FOCUS_ANIMAL_EMPATHY";
    if (value == 915) return "FeatSkill.FOCUS_BLUFF";
    if (value == 173) return "FeatSkill.FOCUS_CONCENTRATION";
    if (value == 911) return "FeatSkill.FOCUS_CRAFT_ARMOR";
    if (value == 407) return "FeatSkill.FOCUS_CRAFT_TRAP";
    if (value == 912) return "FeatSkill.FOCUS_CRAFT_WEAPON";
    if (value == 174) return "FeatSkill.FOCUS_DISABLE_TRAP";
    if (value == 175) return "FeatSkill.FOCUS_DISCIPLINE";
    if (value == 177) return "FeatSkill.FOCUS_HEAL";
    if (value == 178) return "FeatSkill.FOCUS_HIDE";
    if (value == 916) return "FeatSkill.FOCUS_INTIMIDATE";
    if (value == 179) return "FeatSkill.FOCUS_LISTEN";
    if (value == 180) return "FeatSkill.FOCUS_LORE";
    if (value == 181) return "FeatSkill.FOCUS_MOVE_SILENTLY";
    if (value == 182) return "FeatSkill.FOCUS_OPEN_LOCK";
    if (value == 183) return "FeatSkill.FOCUS_PARRY";
    if (value == 184) return "FeatSkill.FOCUS_PERFORM";
    if (value == 185) return "FeatSkill.FOCUS_PERSUADE";
    if (value == 186) return "FeatSkill.FOCUS_PICK_POCKET";
    if (value == 187) return "FeatSkill.FOCUS_SEARCH";
    if (value == 188) return "FeatSkill.FOCUS_SET_TRAP";
    if (value == 189) return "FeatSkill.FOCUS_SPELLCRAFT";
    if (value == 190) return "FeatSkill.FOCUS_SPOT";
    if (value == 192) return "FeatSkill.FOCUS_TAUNT";
    if (value == 406) return "FeatSkill.FOCUS_TUMBLE";
    if (value == 193) return "FeatSkill.FOCUS_USE_MAGIC_DEVICE";
    if (value == 225) return "FeatSkill.MASTERY";
    return "FeatSkill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSkill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSkill.(not found: " + value + ")";
  }
}
