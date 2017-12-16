package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategory {
  private TalentCategory() {}

  public final static int BENEFICIAL_CONDITIONAL_AREAEFFECT = 6;
  public final static int BENEFICIAL_CONDITIONAL_POTION = 18;
  public final static int BENEFICIAL_CONDITIONAL_SINGLE = 7;
  public final static int BENEFICIAL_ENHANCEMENT_AREAEFFECT = 8;
  public final static int BENEFICIAL_ENHANCEMENT_POTION = 21;
  public final static int BENEFICIAL_ENHANCEMENT_SELF = 10;
  public final static int BENEFICIAL_ENHANCEMENT_SINGLE = 9;
  public final static int BENEFICIAL_HEALING_AREAEFFECT = 4;
  public final static int BENEFICIAL_HEALING_POTION = 17;
  public final static int BENEFICIAL_HEALING_TOUCH = 5;
  public final static int BENEFICIAL_OBTAIN_ALLIES = 15;
  public final static int BENEFICIAL_PROTECTION_AREAEFFECT = 14;
  public final static int BENEFICIAL_PROTECTION_POTION = 20;
  public final static int BENEFICIAL_PROTECTION_SELF = 12;
  public final static int BENEFICIAL_PROTECTION_SINGLE = 13;
  public final static int DRAGONS_BREATH = 19;
  public final static int HARMFUL_AREAEFFECT_DISCRIMINANT = 1;
  public final static int HARMFUL_AREAEFFECT_INDISCRIMINANT = 11;
  public final static int HARMFUL_MELEE = 22;
  public final static int HARMFUL_RANGED = 2;
  public final static int HARMFUL_TOUCH = 3;
  public final static int PERSISTENT_AREA_OF_EFFECT = 16;

  public static String nameOf(int value) {
    if (value == 6) return "TalentCategory.BENEFICIAL_CONDITIONAL_AREAEFFECT";
    if (value == 18) return "TalentCategory.BENEFICIAL_CONDITIONAL_POTION";
    if (value == 7) return "TalentCategory.BENEFICIAL_CONDITIONAL_SINGLE";
    if (value == 8) return "TalentCategory.BENEFICIAL_ENHANCEMENT_AREAEFFECT";
    if (value == 21) return "TalentCategory.BENEFICIAL_ENHANCEMENT_POTION";
    if (value == 10) return "TalentCategory.BENEFICIAL_ENHANCEMENT_SELF";
    if (value == 9) return "TalentCategory.BENEFICIAL_ENHANCEMENT_SINGLE";
    if (value == 4) return "TalentCategory.BENEFICIAL_HEALING_AREAEFFECT";
    if (value == 17) return "TalentCategory.BENEFICIAL_HEALING_POTION";
    if (value == 5) return "TalentCategory.BENEFICIAL_HEALING_TOUCH";
    if (value == 15) return "TalentCategory.BENEFICIAL_OBTAIN_ALLIES";
    if (value == 14) return "TalentCategory.BENEFICIAL_PROTECTION_AREAEFFECT";
    if (value == 20) return "TalentCategory.BENEFICIAL_PROTECTION_POTION";
    if (value == 12) return "TalentCategory.BENEFICIAL_PROTECTION_SELF";
    if (value == 13) return "TalentCategory.BENEFICIAL_PROTECTION_SINGLE";
    if (value == 19) return "TalentCategory.DRAGONS_BREATH";
    if (value == 1) return "TalentCategory.HARMFUL_AREAEFFECT_DISCRIMINANT";
    if (value == 11) return "TalentCategory.HARMFUL_AREAEFFECT_INDISCRIMINANT";
    if (value == 22) return "TalentCategory.HARMFUL_MELEE";
    if (value == 2) return "TalentCategory.HARMFUL_RANGED";
    if (value == 3) return "TalentCategory.HARMFUL_TOUCH";
    if (value == 16) return "TalentCategory.PERSISTENT_AREA_OF_EFFECT";
    return "TalentCategory.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategory.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategory.(not found: " + value + ")";
  }
}
