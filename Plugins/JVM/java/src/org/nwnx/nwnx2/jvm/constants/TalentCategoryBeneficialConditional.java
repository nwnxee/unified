package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_BENEFICIAL_CONDITIONAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryBeneficialConditional {
  private TalentCategoryBeneficialConditional() {}

  public final static int AREAEFFECT = 6;
  public final static int POTION = 18;
  public final static int SINGLE = 7;

  public static String nameOf(int value) {
    if (value == 6) return "TalentCategoryBeneficialConditional.AREAEFFECT";
    if (value == 18) return "TalentCategoryBeneficialConditional.POTION";
    if (value == 7) return "TalentCategoryBeneficialConditional.SINGLE";
    return "TalentCategoryBeneficialConditional.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryBeneficialConditional.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryBeneficialConditional.(not found: " + value + ")";
  }
}
