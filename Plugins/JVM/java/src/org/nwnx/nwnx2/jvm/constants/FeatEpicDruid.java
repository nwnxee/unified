package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_DRUID".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicDruid {
  private FeatEpicDruid() {}

  public final static int FEAT_EPIC_DRUID = 970;
  public final static int INFINITE_ELEMENTAL_SHAPE = 1069;
  public final static int INFINITE_WILDSHAPE = 1068;

  public static String nameOf(int value) {
    if (value == 970) return "FeatEpicDruid.FEAT_EPIC_DRUID";
    if (value == 1069) return "FeatEpicDruid.INFINITE_ELEMENTAL_SHAPE";
    if (value == 1068) return "FeatEpicDruid.INFINITE_WILDSHAPE";
    return "FeatEpicDruid.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicDruid.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicDruid.(not found: " + value + ")";
  }
}
