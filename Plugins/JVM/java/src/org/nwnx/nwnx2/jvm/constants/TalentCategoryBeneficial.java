package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_BENEFICIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryBeneficial {
  private TalentCategoryBeneficial() {}

  public final static int CONDITIONAL_AREAEFFECT = 6;
  public final static int CONDITIONAL_POTION = 18;
  public final static int CONDITIONAL_SINGLE = 7;
  public final static int ENHANCEMENT_AREAEFFECT = 8;
  public final static int ENHANCEMENT_POTION = 21;
  public final static int ENHANCEMENT_SELF = 10;
  public final static int ENHANCEMENT_SINGLE = 9;
  public final static int HEALING_AREAEFFECT = 4;
  public final static int HEALING_POTION = 17;
  public final static int HEALING_TOUCH = 5;
  public final static int OBTAIN_ALLIES = 15;
  public final static int PROTECTION_AREAEFFECT = 14;
  public final static int PROTECTION_POTION = 20;
  public final static int PROTECTION_SELF = 12;
  public final static int PROTECTION_SINGLE = 13;

  public static String nameOf(int value) {
    if (value == 6) return "TalentCategoryBeneficial.CONDITIONAL_AREAEFFECT";
    if (value == 18) return "TalentCategoryBeneficial.CONDITIONAL_POTION";
    if (value == 7) return "TalentCategoryBeneficial.CONDITIONAL_SINGLE";
    if (value == 8) return "TalentCategoryBeneficial.ENHANCEMENT_AREAEFFECT";
    if (value == 21) return "TalentCategoryBeneficial.ENHANCEMENT_POTION";
    if (value == 10) return "TalentCategoryBeneficial.ENHANCEMENT_SELF";
    if (value == 9) return "TalentCategoryBeneficial.ENHANCEMENT_SINGLE";
    if (value == 4) return "TalentCategoryBeneficial.HEALING_AREAEFFECT";
    if (value == 17) return "TalentCategoryBeneficial.HEALING_POTION";
    if (value == 5) return "TalentCategoryBeneficial.HEALING_TOUCH";
    if (value == 15) return "TalentCategoryBeneficial.OBTAIN_ALLIES";
    if (value == 14) return "TalentCategoryBeneficial.PROTECTION_AREAEFFECT";
    if (value == 20) return "TalentCategoryBeneficial.PROTECTION_POTION";
    if (value == 12) return "TalentCategoryBeneficial.PROTECTION_SELF";
    if (value == 13) return "TalentCategoryBeneficial.PROTECTION_SINGLE";
    return "TalentCategoryBeneficial.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryBeneficial.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryBeneficial.(not found: " + value + ")";
  }
}
