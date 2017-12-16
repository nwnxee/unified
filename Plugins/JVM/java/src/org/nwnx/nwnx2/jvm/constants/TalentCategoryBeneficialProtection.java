package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_BENEFICIAL_PROTECTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryBeneficialProtection {
  private TalentCategoryBeneficialProtection() {}

  public final static int AREAEFFECT = 14;
  public final static int POTION = 20;
  public final static int SELF = 12;
  public final static int SINGLE = 13;

  public static String nameOf(int value) {
    if (value == 14) return "TalentCategoryBeneficialProtection.AREAEFFECT";
    if (value == 20) return "TalentCategoryBeneficialProtection.POTION";
    if (value == 12) return "TalentCategoryBeneficialProtection.SELF";
    if (value == 13) return "TalentCategoryBeneficialProtection.SINGLE";
    return "TalentCategoryBeneficialProtection.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryBeneficialProtection.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryBeneficialProtection.(not found: " + value + ")";
  }
}
