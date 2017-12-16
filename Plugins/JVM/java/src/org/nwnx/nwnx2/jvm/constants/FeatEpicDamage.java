package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_DAMAGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicDamage {
  private FeatEpicDamage() {}

  public final static int REDUCTION_3 = 492;
  public final static int REDUCTION_6 = 493;
  public final static int REDUCTION_9 = 494;

  public static String nameOf(int value) {
    if (value == 492) return "FeatEpicDamage.REDUCTION_3";
    if (value == 493) return "FeatEpicDamage.REDUCTION_6";
    if (value == 494) return "FeatEpicDamage.REDUCTION_9";
    return "FeatEpicDamage.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicDamage.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicDamage.(not found: " + value + ")";
  }
}
