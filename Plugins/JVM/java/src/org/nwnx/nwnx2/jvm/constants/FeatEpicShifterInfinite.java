package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SHIFTER_INFINITE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicShifterInfinite {
  private FeatEpicShifterInfinite() {}

  public final static int HUMANOID_SHAPE = 1066;
  public final static int WILDSHAPE_1 = 1062;
  public final static int WILDSHAPE_2 = 1063;
  public final static int WILDSHAPE_3 = 1064;
  public final static int WILDSHAPE_4 = 1065;

  public static String nameOf(int value) {
    if (value == 1066) return "FeatEpicShifterInfinite.HUMANOID_SHAPE";
    if (value == 1062) return "FeatEpicShifterInfinite.WILDSHAPE_1";
    if (value == 1063) return "FeatEpicShifterInfinite.WILDSHAPE_2";
    if (value == 1064) return "FeatEpicShifterInfinite.WILDSHAPE_3";
    if (value == 1065) return "FeatEpicShifterInfinite.WILDSHAPE_4";
    return "FeatEpicShifterInfinite.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicShifterInfinite.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicShifterInfinite.(not found: " + value + ")";
  }
}
