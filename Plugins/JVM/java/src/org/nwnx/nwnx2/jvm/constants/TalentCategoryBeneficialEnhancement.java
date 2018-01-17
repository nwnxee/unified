package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_BENEFICIAL_ENHANCEMENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryBeneficialEnhancement {
  private TalentCategoryBeneficialEnhancement() {}

  public final static int AREAEFFECT = 8;
  public final static int POTION = 21;
  public final static int SELF = 10;
  public final static int SINGLE = 9;

  public static String nameOf(int value) {
    if (value == 8) return "TalentCategoryBeneficialEnhancement.AREAEFFECT";
    if (value == 21) return "TalentCategoryBeneficialEnhancement.POTION";
    if (value == 10) return "TalentCategoryBeneficialEnhancement.SELF";
    if (value == 9) return "TalentCategoryBeneficialEnhancement.SINGLE";
    return "TalentCategoryBeneficialEnhancement.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryBeneficialEnhancement.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryBeneficialEnhancement.(not found: " + value + ")";
  }
}
