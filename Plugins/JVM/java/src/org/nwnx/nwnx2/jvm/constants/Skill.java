package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SKILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Skill {
  private Skill() {}

  public final static int ALL_SKILLS = 255;
  public final static int ANIMAL_EMPATHY = 0;
  public final static int APPRAISE = 20;
  public final static int BLUFF = 23;
  public final static int CONCENTRATION = 1;
  public final static int CRAFT_ARMOR = 25;
  public final static int CRAFT_TRAP = 22;
  public final static int CRAFT_WEAPON = 26;
  public final static int DISABLE_TRAP = 2;
  public final static int DISCIPLINE = 3;
  public final static int HEAL = 4;
  public final static int HIDE = 5;
  public final static int INTIMIDATE = 24;
  public final static int LISTEN = 6;
  public final static int LORE = 7;
  public final static int MOVE_SILENTLY = 8;
  public final static int OPEN_LOCK = 9;
  public final static int PARRY = 10;
  public final static int PERFORM = 11;
  public final static int PERSUADE = 12;
  public final static int PICK_POCKET = 13;
  public final static int RIDE = 27;
  public final static int SEARCH = 14;
  public final static int SET_TRAP = 15;
  public final static int SPELLCRAFT = 16;
  public final static int SPOT = 17;
  public final static int TAUNT = 18;
  public final static int TUMBLE = 21;
  public final static int USE_MAGIC_DEVICE = 19;

  public static String nameOf(int value) {
    if (value == 255) return "Skill.ALL_SKILLS";
    if (value == 0) return "Skill.ANIMAL_EMPATHY";
    if (value == 20) return "Skill.APPRAISE";
    if (value == 23) return "Skill.BLUFF";
    if (value == 1) return "Skill.CONCENTRATION";
    if (value == 25) return "Skill.CRAFT_ARMOR";
    if (value == 22) return "Skill.CRAFT_TRAP";
    if (value == 26) return "Skill.CRAFT_WEAPON";
    if (value == 2) return "Skill.DISABLE_TRAP";
    if (value == 3) return "Skill.DISCIPLINE";
    if (value == 4) return "Skill.HEAL";
    if (value == 5) return "Skill.HIDE";
    if (value == 24) return "Skill.INTIMIDATE";
    if (value == 6) return "Skill.LISTEN";
    if (value == 7) return "Skill.LORE";
    if (value == 8) return "Skill.MOVE_SILENTLY";
    if (value == 9) return "Skill.OPEN_LOCK";
    if (value == 10) return "Skill.PARRY";
    if (value == 11) return "Skill.PERFORM";
    if (value == 12) return "Skill.PERSUADE";
    if (value == 13) return "Skill.PICK_POCKET";
    if (value == 27) return "Skill.RIDE";
    if (value == 14) return "Skill.SEARCH";
    if (value == 15) return "Skill.SET_TRAP";
    if (value == 16) return "Skill.SPELLCRAFT";
    if (value == 17) return "Skill.SPOT";
    if (value == 18) return "Skill.TAUNT";
    if (value == 21) return "Skill.TUMBLE";
    if (value == 19) return "Skill.USE_MAGIC_DEVICE";
    return "Skill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Skill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Skill.(not found: " + value + ")";
  }
}
