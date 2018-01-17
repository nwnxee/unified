package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BLACKGUARD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBlackguard {
  private FeatBlackguard() {}

  public final static int SNEAK_ATTACK_10D6 = 1013;
  public final static int SNEAK_ATTACK_11D6 = 1014;
  public final static int SNEAK_ATTACK_12D6 = 1015;
  public final static int SNEAK_ATTACK_13D6 = 1016;
  public final static int SNEAK_ATTACK_14D6 = 1017;
  public final static int SNEAK_ATTACK_15D6 = 1018;
  public final static int SNEAK_ATTACK_1D6 = 460;
  public final static int SNEAK_ATTACK_2D6 = 461;
  public final static int SNEAK_ATTACK_3D6 = 462;
  public final static int SNEAK_ATTACK_4D6 = 1007;
  public final static int SNEAK_ATTACK_5D6 = 1008;
  public final static int SNEAK_ATTACK_6D6 = 1009;
  public final static int SNEAK_ATTACK_7D6 = 1010;
  public final static int SNEAK_ATTACK_8D6 = 1011;
  public final static int SNEAK_ATTACK_9D6 = 1012;

  public static String nameOf(int value) {
    if (value == 1013) return "FeatBlackguard.SNEAK_ATTACK_10D6";
    if (value == 1014) return "FeatBlackguard.SNEAK_ATTACK_11D6";
    if (value == 1015) return "FeatBlackguard.SNEAK_ATTACK_12D6";
    if (value == 1016) return "FeatBlackguard.SNEAK_ATTACK_13D6";
    if (value == 1017) return "FeatBlackguard.SNEAK_ATTACK_14D6";
    if (value == 1018) return "FeatBlackguard.SNEAK_ATTACK_15D6";
    if (value == 460) return "FeatBlackguard.SNEAK_ATTACK_1D6";
    if (value == 461) return "FeatBlackguard.SNEAK_ATTACK_2D6";
    if (value == 462) return "FeatBlackguard.SNEAK_ATTACK_3D6";
    if (value == 1007) return "FeatBlackguard.SNEAK_ATTACK_4D6";
    if (value == 1008) return "FeatBlackguard.SNEAK_ATTACK_5D6";
    if (value == 1009) return "FeatBlackguard.SNEAK_ATTACK_6D6";
    if (value == 1010) return "FeatBlackguard.SNEAK_ATTACK_7D6";
    if (value == 1011) return "FeatBlackguard.SNEAK_ATTACK_8D6";
    if (value == 1012) return "FeatBlackguard.SNEAK_ATTACK_9D6";
    return "FeatBlackguard.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBlackguard.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBlackguard.(not found: " + value + ")";
  }
}
