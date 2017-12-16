package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AREA_TRANSITION_CARAVAN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AreaTransitionCaravan {
  private AreaTransitionCaravan() {}

  public final static int DESERT = 84;
  public final static int RURAL = 85;
  public final static int WINTER = 83;

  public static String nameOf(int value) {
    if (value == 84) return "AreaTransitionCaravan.DESERT";
    if (value == 85) return "AreaTransitionCaravan.RURAL";
    if (value == 83) return "AreaTransitionCaravan.WINTER";
    return "AreaTransitionCaravan.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AreaTransitionCaravan.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AreaTransitionCaravan.(not found: " + value + ")";
  }
}
