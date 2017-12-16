package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PRESTIGE_DEFENSIVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPrestigeDefensive {
  private FeatPrestigeDefensive() {}

  public final static int AWARENESS_1 = 949;
  public final static int AWARENESS_2 = 950;
  public final static int AWARENESS_3 = 951;

  public static String nameOf(int value) {
    if (value == 949) return "FeatPrestigeDefensive.AWARENESS_1";
    if (value == 950) return "FeatPrestigeDefensive.AWARENESS_2";
    if (value == 951) return "FeatPrestigeDefensive.AWARENESS_3";
    return "FeatPrestigeDefensive.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPrestigeDefensive.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPrestigeDefensive.(not found: " + value + ")";
  }
}
