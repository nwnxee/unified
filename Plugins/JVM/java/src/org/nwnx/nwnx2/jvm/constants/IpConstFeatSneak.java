package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_SNEAK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatSneak {
  private IpConstFeatSneak() {}

  public final static int ATTACK_1D6 = 32;
  public final static int ATTACK_2D6 = 33;
  public final static int ATTACK_3D6 = 34;
  public final static int ATTACK_5D6 = 39;

  public static String nameOf(int value) {
    if (value == 32) return "IpConstFeatSneak.ATTACK_1D6";
    if (value == 33) return "IpConstFeatSneak.ATTACK_2D6";
    if (value == 34) return "IpConstFeatSneak.ATTACK_3D6";
    if (value == 39) return "IpConstFeatSneak.ATTACK_5D6";
    return "IpConstFeatSneak.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatSneak.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatSneak.(not found: " + value + ")";
  }
}
