package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SKILL_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSkillFocus {
  private FeatEpicSkillFocus() {}

  public final static int ANIMAL_EMPATHY = 587;
  public final static int APPRAISE = 588;
  public final static int BLUFF = 917;
  public final static int CONCENTRATION = 589;
  public final static int CRAFT_ARMOR = 913;
  public final static int CRAFT_TRAP = 590;
  public final static int CRAFT_WEAPON = 914;
  public final static int DISABLETRAP = 591;
  public final static int DISCIPLINE = 592;
  public final static int HEAL = 593;
  public final static int HIDE = 594;
  public final static int INTIMIDATE = 918;
  public final static int LISTEN = 595;
  public final static int LORE = 596;
  public final static int MOVESILENTLY = 597;
  public final static int OPENLOCK = 598;
  public final static int PARRY = 599;
  public final static int PERFORM = 600;
  public final static int PERSUADE = 601;
  public final static int PICKPOCKET = 602;
  public final static int SEARCH = 603;
  public final static int SETTRAP = 604;
  public final static int SPELLCRAFT = 605;
  public final static int SPOT = 606;
  public final static int TAUNT = 607;
  public final static int TUMBLE = 608;
  public final static int USEMAGICDEVICE = 609;

  public static String nameOf(int value) {
    if (value == 587) return "FeatEpicSkillFocus.ANIMAL_EMPATHY";
    if (value == 588) return "FeatEpicSkillFocus.APPRAISE";
    if (value == 917) return "FeatEpicSkillFocus.BLUFF";
    if (value == 589) return "FeatEpicSkillFocus.CONCENTRATION";
    if (value == 913) return "FeatEpicSkillFocus.CRAFT_ARMOR";
    if (value == 590) return "FeatEpicSkillFocus.CRAFT_TRAP";
    if (value == 914) return "FeatEpicSkillFocus.CRAFT_WEAPON";
    if (value == 591) return "FeatEpicSkillFocus.DISABLETRAP";
    if (value == 592) return "FeatEpicSkillFocus.DISCIPLINE";
    if (value == 593) return "FeatEpicSkillFocus.HEAL";
    if (value == 594) return "FeatEpicSkillFocus.HIDE";
    if (value == 918) return "FeatEpicSkillFocus.INTIMIDATE";
    if (value == 595) return "FeatEpicSkillFocus.LISTEN";
    if (value == 596) return "FeatEpicSkillFocus.LORE";
    if (value == 597) return "FeatEpicSkillFocus.MOVESILENTLY";
    if (value == 598) return "FeatEpicSkillFocus.OPENLOCK";
    if (value == 599) return "FeatEpicSkillFocus.PARRY";
    if (value == 600) return "FeatEpicSkillFocus.PERFORM";
    if (value == 601) return "FeatEpicSkillFocus.PERSUADE";
    if (value == 602) return "FeatEpicSkillFocus.PICKPOCKET";
    if (value == 603) return "FeatEpicSkillFocus.SEARCH";
    if (value == 604) return "FeatEpicSkillFocus.SETTRAP";
    if (value == 605) return "FeatEpicSkillFocus.SPELLCRAFT";
    if (value == 606) return "FeatEpicSkillFocus.SPOT";
    if (value == 607) return "FeatEpicSkillFocus.TAUNT";
    if (value == 608) return "FeatEpicSkillFocus.TUMBLE";
    if (value == 609) return "FeatEpicSkillFocus.USEMAGICDEVICE";
    return "FeatEpicSkillFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSkillFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSkillFocus.(not found: " + value + ")";
  }
}
