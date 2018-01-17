package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SACRED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSacred {
  private FeatSacred() {}

  public final static int DEFENSE_1 = 904;
  public final static int DEFENSE_2 = 905;
  public final static int DEFENSE_3 = 906;
  public final static int DEFENSE_4 = 907;
  public final static int DEFENSE_5 = 908;

  public static String nameOf(int value) {
    if (value == 904) return "FeatSacred.DEFENSE_1";
    if (value == 905) return "FeatSacred.DEFENSE_2";
    if (value == 906) return "FeatSacred.DEFENSE_3";
    if (value == 907) return "FeatSacred.DEFENSE_4";
    if (value == 908) return "FeatSacred.DEFENSE_5";
    return "FeatSacred.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSacred.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSacred.(not found: " + value + ")";
  }
}
