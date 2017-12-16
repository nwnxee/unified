package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TALENT_CATEGORY_HARMFUL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TalentCategoryHarmful {
  private TalentCategoryHarmful() {}

  public final static int AREAEFFECT_DISCRIMINANT = 1;
  public final static int AREAEFFECT_INDISCRIMINANT = 11;
  public final static int MELEE = 22;
  public final static int RANGED = 2;
  public final static int TOUCH = 3;

  public static String nameOf(int value) {
    if (value == 1) return "TalentCategoryHarmful.AREAEFFECT_DISCRIMINANT";
    if (value == 11) return "TalentCategoryHarmful.AREAEFFECT_INDISCRIMINANT";
    if (value == 22) return "TalentCategoryHarmful.MELEE";
    if (value == 2) return "TalentCategoryHarmful.RANGED";
    if (value == 3) return "TalentCategoryHarmful.TOUCH";
    return "TalentCategoryHarmful.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TalentCategoryHarmful.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TalentCategoryHarmful.(not found: " + value + ")";
  }
}
