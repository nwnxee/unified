package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_IMPROVED_STUNNING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicImprovedStunning {
  private FeatEpicImprovedStunning() {}

  public final static int FIST_1 = 844;
  public final static int FIST_10 = 853;
  public final static int FIST_2 = 845;
  public final static int FIST_3 = 846;
  public final static int FIST_4 = 847;
  public final static int FIST_5 = 848;
  public final static int FIST_6 = 849;
  public final static int FIST_7 = 850;
  public final static int FIST_8 = 851;
  public final static int FIST_9 = 852;

  public static String nameOf(int value) {
    if (value == 844) return "FeatEpicImprovedStunning.FIST_1";
    if (value == 853) return "FeatEpicImprovedStunning.FIST_10";
    if (value == 845) return "FeatEpicImprovedStunning.FIST_2";
    if (value == 846) return "FeatEpicImprovedStunning.FIST_3";
    if (value == 847) return "FeatEpicImprovedStunning.FIST_4";
    if (value == 848) return "FeatEpicImprovedStunning.FIST_5";
    if (value == 849) return "FeatEpicImprovedStunning.FIST_6";
    if (value == 850) return "FeatEpicImprovedStunning.FIST_7";
    if (value == 851) return "FeatEpicImprovedStunning.FIST_8";
    if (value == 852) return "FeatEpicImprovedStunning.FIST_9";
    return "FeatEpicImprovedStunning.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicImprovedStunning.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicImprovedStunning.(not found: " + value + ")";
  }
}
