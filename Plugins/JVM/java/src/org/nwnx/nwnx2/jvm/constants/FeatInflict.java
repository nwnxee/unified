package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_INFLICT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatInflict {
  private FeatInflict() {}

  public final static int CRITICAL_WOUNDS = 477;
  public final static int LIGHT_WOUNDS = 474;
  public final static int MODERATE_WOUNDS = 475;
  public final static int SERIOUS_WOUNDS = 476;

  public static String nameOf(int value) {
    if (value == 477) return "FeatInflict.CRITICAL_WOUNDS";
    if (value == 474) return "FeatInflict.LIGHT_WOUNDS";
    if (value == 475) return "FeatInflict.MODERATE_WOUNDS";
    if (value == 476) return "FeatInflict.SERIOUS_WOUNDS";
    return "FeatInflict.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatInflict.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatInflict.(not found: " + value + ")";
  }
}
