package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SHIFTER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicShifter {
  private FeatEpicShifter() {}

  public final static int FEAT_EPIC_SHIFTER = 986;
  public final static int INFINITE_HUMANOID_SHAPE = 1066;
  public final static int INFINITE_WILDSHAPE_1 = 1062;
  public final static int INFINITE_WILDSHAPE_2 = 1063;
  public final static int INFINITE_WILDSHAPE_3 = 1064;
  public final static int INFINITE_WILDSHAPE_4 = 1065;

  public static String nameOf(int value) {
    if (value == 986) return "FeatEpicShifter.FEAT_EPIC_SHIFTER";
    if (value == 1066) return "FeatEpicShifter.INFINITE_HUMANOID_SHAPE";
    if (value == 1062) return "FeatEpicShifter.INFINITE_WILDSHAPE_1";
    if (value == 1063) return "FeatEpicShifter.INFINITE_WILDSHAPE_2";
    if (value == 1064) return "FeatEpicShifter.INFINITE_WILDSHAPE_3";
    if (value == 1065) return "FeatEpicShifter.INFINITE_WILDSHAPE_4";
    return "FeatEpicShifter.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicShifter.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicShifter.(not found: " + value + ")";
  }
}
