package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SKILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSkill {
  private FeatEpicSkill() {}

  public final static int FOCUS_ANIMAL_EMPATHY = 587;
  public final static int FOCUS_APPRAISE = 588;
  public final static int FOCUS_BLUFF = 917;
  public final static int FOCUS_CONCENTRATION = 589;
  public final static int FOCUS_CRAFT_ARMOR = 913;
  public final static int FOCUS_CRAFT_TRAP = 590;
  public final static int FOCUS_CRAFT_WEAPON = 914;
  public final static int FOCUS_DISABLETRAP = 591;
  public final static int FOCUS_DISCIPLINE = 592;
  public final static int FOCUS_HEAL = 593;
  public final static int FOCUS_HIDE = 594;
  public final static int FOCUS_INTIMIDATE = 918;
  public final static int FOCUS_LISTEN = 595;
  public final static int FOCUS_LORE = 596;
  public final static int FOCUS_MOVESILENTLY = 597;
  public final static int FOCUS_OPENLOCK = 598;
  public final static int FOCUS_PARRY = 599;
  public final static int FOCUS_PERFORM = 600;
  public final static int FOCUS_PERSUADE = 601;
  public final static int FOCUS_PICKPOCKET = 602;
  public final static int FOCUS_SEARCH = 603;
  public final static int FOCUS_SETTRAP = 604;
  public final static int FOCUS_SPELLCRAFT = 605;
  public final static int FOCUS_SPOT = 606;
  public final static int FOCUS_TAUNT = 607;
  public final static int FOCUS_TUMBLE = 608;
  public final static int FOCUS_USEMAGICDEVICE = 609;

  public static String nameOf(int value) {
    if (value == 587) return "FeatEpicSkill.FOCUS_ANIMAL_EMPATHY";
    if (value == 588) return "FeatEpicSkill.FOCUS_APPRAISE";
    if (value == 917) return "FeatEpicSkill.FOCUS_BLUFF";
    if (value == 589) return "FeatEpicSkill.FOCUS_CONCENTRATION";
    if (value == 913) return "FeatEpicSkill.FOCUS_CRAFT_ARMOR";
    if (value == 590) return "FeatEpicSkill.FOCUS_CRAFT_TRAP";
    if (value == 914) return "FeatEpicSkill.FOCUS_CRAFT_WEAPON";
    if (value == 591) return "FeatEpicSkill.FOCUS_DISABLETRAP";
    if (value == 592) return "FeatEpicSkill.FOCUS_DISCIPLINE";
    if (value == 593) return "FeatEpicSkill.FOCUS_HEAL";
    if (value == 594) return "FeatEpicSkill.FOCUS_HIDE";
    if (value == 918) return "FeatEpicSkill.FOCUS_INTIMIDATE";
    if (value == 595) return "FeatEpicSkill.FOCUS_LISTEN";
    if (value == 596) return "FeatEpicSkill.FOCUS_LORE";
    if (value == 597) return "FeatEpicSkill.FOCUS_MOVESILENTLY";
    if (value == 598) return "FeatEpicSkill.FOCUS_OPENLOCK";
    if (value == 599) return "FeatEpicSkill.FOCUS_PARRY";
    if (value == 600) return "FeatEpicSkill.FOCUS_PERFORM";
    if (value == 601) return "FeatEpicSkill.FOCUS_PERSUADE";
    if (value == 602) return "FeatEpicSkill.FOCUS_PICKPOCKET";
    if (value == 603) return "FeatEpicSkill.FOCUS_SEARCH";
    if (value == 604) return "FeatEpicSkill.FOCUS_SETTRAP";
    if (value == 605) return "FeatEpicSkill.FOCUS_SPELLCRAFT";
    if (value == 606) return "FeatEpicSkill.FOCUS_SPOT";
    if (value == 607) return "FeatEpicSkill.FOCUS_TAUNT";
    if (value == 608) return "FeatEpicSkill.FOCUS_TUMBLE";
    if (value == 609) return "FeatEpicSkill.FOCUS_USEMAGICDEVICE";
    return "FeatEpicSkill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSkill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSkill.(not found: " + value + ")";
  }
}
