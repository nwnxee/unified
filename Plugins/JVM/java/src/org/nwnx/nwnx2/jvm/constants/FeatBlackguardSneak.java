package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BLACKGUARD_SNEAK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBlackguardSneak {
  private FeatBlackguardSneak() {}

  public final static int ATTACK_10D6 = 1013;
  public final static int ATTACK_11D6 = 1014;
  public final static int ATTACK_12D6 = 1015;
  public final static int ATTACK_13D6 = 1016;
  public final static int ATTACK_14D6 = 1017;
  public final static int ATTACK_15D6 = 1018;
  public final static int ATTACK_1D6 = 460;
  public final static int ATTACK_2D6 = 461;
  public final static int ATTACK_3D6 = 462;
  public final static int ATTACK_4D6 = 1007;
  public final static int ATTACK_5D6 = 1008;
  public final static int ATTACK_6D6 = 1009;
  public final static int ATTACK_7D6 = 1010;
  public final static int ATTACK_8D6 = 1011;
  public final static int ATTACK_9D6 = 1012;

  public static String nameOf(int value) {
    if (value == 1013) return "FeatBlackguardSneak.ATTACK_10D6";
    if (value == 1014) return "FeatBlackguardSneak.ATTACK_11D6";
    if (value == 1015) return "FeatBlackguardSneak.ATTACK_12D6";
    if (value == 1016) return "FeatBlackguardSneak.ATTACK_13D6";
    if (value == 1017) return "FeatBlackguardSneak.ATTACK_14D6";
    if (value == 1018) return "FeatBlackguardSneak.ATTACK_15D6";
    if (value == 460) return "FeatBlackguardSneak.ATTACK_1D6";
    if (value == 461) return "FeatBlackguardSneak.ATTACK_2D6";
    if (value == 462) return "FeatBlackguardSneak.ATTACK_3D6";
    if (value == 1007) return "FeatBlackguardSneak.ATTACK_4D6";
    if (value == 1008) return "FeatBlackguardSneak.ATTACK_5D6";
    if (value == 1009) return "FeatBlackguardSneak.ATTACK_6D6";
    if (value == 1010) return "FeatBlackguardSneak.ATTACK_7D6";
    if (value == 1011) return "FeatBlackguardSneak.ATTACK_8D6";
    if (value == 1012) return "FeatBlackguardSneak.ATTACK_9D6";
    return "FeatBlackguardSneak.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBlackguardSneak.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBlackguardSneak.(not found: " + value + ")";
  }
}
