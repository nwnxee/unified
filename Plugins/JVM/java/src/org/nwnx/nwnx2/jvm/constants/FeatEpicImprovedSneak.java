package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_IMPROVED_SNEAK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicImprovedSneak {
  private FeatEpicImprovedSneak() {}

  public final static int ATTACK_1 = 834;
  public final static int ATTACK_10 = 843;
  public final static int ATTACK_2 = 835;
  public final static int ATTACK_3 = 836;
  public final static int ATTACK_4 = 837;
  public final static int ATTACK_5 = 838;
  public final static int ATTACK_6 = 839;
  public final static int ATTACK_7 = 840;
  public final static int ATTACK_8 = 841;
  public final static int ATTACK_9 = 842;

  public static String nameOf(int value) {
    if (value == 834) return "FeatEpicImprovedSneak.ATTACK_1";
    if (value == 843) return "FeatEpicImprovedSneak.ATTACK_10";
    if (value == 835) return "FeatEpicImprovedSneak.ATTACK_2";
    if (value == 836) return "FeatEpicImprovedSneak.ATTACK_3";
    if (value == 837) return "FeatEpicImprovedSneak.ATTACK_4";
    if (value == 838) return "FeatEpicImprovedSneak.ATTACK_5";
    if (value == 839) return "FeatEpicImprovedSneak.ATTACK_6";
    if (value == 840) return "FeatEpicImprovedSneak.ATTACK_7";
    if (value == 841) return "FeatEpicImprovedSneak.ATTACK_8";
    if (value == 842) return "FeatEpicImprovedSneak.ATTACK_9";
    return "FeatEpicImprovedSneak.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicImprovedSneak.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicImprovedSneak.(not found: " + value + ")";
  }
}
