package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SELF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSelf {
  private FeatEpicSelf() {}

  public final static int CONCEALMENT_10 = 748;
  public final static int CONCEALMENT_20 = 749;
  public final static int CONCEALMENT_30 = 750;
  public final static int CONCEALMENT_40 = 751;
  public final static int CONCEALMENT_50 = 752;

  public static String nameOf(int value) {
    if (value == 748) return "FeatEpicSelf.CONCEALMENT_10";
    if (value == 749) return "FeatEpicSelf.CONCEALMENT_20";
    if (value == 750) return "FeatEpicSelf.CONCEALMENT_30";
    if (value == 751) return "FeatEpicSelf.CONCEALMENT_40";
    if (value == 752) return "FeatEpicSelf.CONCEALMENT_50";
    return "FeatEpicSelf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSelf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSelf.(not found: " + value + ")";
  }
}
