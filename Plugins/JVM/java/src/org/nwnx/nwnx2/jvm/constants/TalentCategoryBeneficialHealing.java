package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_BENEFICIAL_HEALING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryBeneficialHealing {
  private TalentCategoryBeneficialHealing() {}

  public final static int AREAEFFECT = 4;
  public final static int POTION = 17;
  public final static int TOUCH = 5;

  public static String nameOf(int value) {
    if (value == 4) return "TalentCategoryBeneficialHealing.AREAEFFECT";
    if (value == 17) return "TalentCategoryBeneficialHealing.POTION";
    if (value == 5) return "TalentCategoryBeneficialHealing.TOUCH";
    return "TalentCategoryBeneficialHealing.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryBeneficialHealing.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryBeneficialHealing.(not found: " + value + ")";
  }
}
