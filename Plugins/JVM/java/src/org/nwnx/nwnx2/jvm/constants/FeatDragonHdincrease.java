package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_DRAGON_HDINCREASE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatDragonHdincrease {
  private FeatDragonHdincrease() {}

  public final static int D10 = 1044;
  public final static int D6 = 1042;
  public final static int D8 = 1043;

  public static String nameOf(int value) {
    if (value == 1044) return "FeatDragonHdincrease.D10";
    if (value == 1042) return "FeatDragonHdincrease.D6";
    if (value == 1043) return "FeatDragonHdincrease.D8";
    return "FeatDragonHdincrease.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatDragonHdincrease.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatDragonHdincrease.(not found: " + value + ")";
  }
}
