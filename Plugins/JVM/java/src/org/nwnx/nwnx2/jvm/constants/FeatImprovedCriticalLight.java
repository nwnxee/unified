package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_IMPROVED_CRITICAL_LIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatImprovedCriticalLight {
  private FeatImprovedCriticalLight() {}

  public final static int CROSSBOW = 55;
  public final static int FLAIL = 76;
  public final static int HAMMER = 75;
  public final static int MACE = 56;

  public static String nameOf(int value) {
    if (value == 55) return "FeatImprovedCriticalLight.CROSSBOW";
    if (value == 76) return "FeatImprovedCriticalLight.FLAIL";
    if (value == 75) return "FeatImprovedCriticalLight.HAMMER";
    if (value == 56) return "FeatImprovedCriticalLight.MACE";
    return "FeatImprovedCriticalLight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatImprovedCriticalLight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatImprovedCriticalLight.(not found: " + value + ")";
  }
}
