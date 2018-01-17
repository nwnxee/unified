package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PRESTIGE_ENCHANT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPrestigeEnchant {
  private FeatPrestigeEnchant() {}

  public final static int ARROW_1 = 445;
  public final static int ARROW_10 = 1049;
  public final static int ARROW_11 = 1050;
  public final static int ARROW_12 = 1051;
  public final static int ARROW_13 = 1052;
  public final static int ARROW_14 = 1053;
  public final static int ARROW_15 = 1054;
  public final static int ARROW_16 = 1055;
  public final static int ARROW_17 = 1056;
  public final static int ARROW_18 = 1057;
  public final static int ARROW_19 = 1058;
  public final static int ARROW_2 = 446;
  public final static int ARROW_20 = 1059;
  public final static int ARROW_3 = 447;
  public final static int ARROW_4 = 448;
  public final static int ARROW_5 = 449;
  public final static int ARROW_6 = 1045;
  public final static int ARROW_7 = 1046;
  public final static int ARROW_8 = 1047;
  public final static int ARROW_9 = 1048;

  public static String nameOf(int value) {
    if (value == 445) return "FeatPrestigeEnchant.ARROW_1";
    if (value == 1049) return "FeatPrestigeEnchant.ARROW_10";
    if (value == 1050) return "FeatPrestigeEnchant.ARROW_11";
    if (value == 1051) return "FeatPrestigeEnchant.ARROW_12";
    if (value == 1052) return "FeatPrestigeEnchant.ARROW_13";
    if (value == 1053) return "FeatPrestigeEnchant.ARROW_14";
    if (value == 1054) return "FeatPrestigeEnchant.ARROW_15";
    if (value == 1055) return "FeatPrestigeEnchant.ARROW_16";
    if (value == 1056) return "FeatPrestigeEnchant.ARROW_17";
    if (value == 1057) return "FeatPrestigeEnchant.ARROW_18";
    if (value == 1058) return "FeatPrestigeEnchant.ARROW_19";
    if (value == 446) return "FeatPrestigeEnchant.ARROW_2";
    if (value == 1059) return "FeatPrestigeEnchant.ARROW_20";
    if (value == 447) return "FeatPrestigeEnchant.ARROW_3";
    if (value == 448) return "FeatPrestigeEnchant.ARROW_4";
    if (value == 449) return "FeatPrestigeEnchant.ARROW_5";
    if (value == 1045) return "FeatPrestigeEnchant.ARROW_6";
    if (value == 1046) return "FeatPrestigeEnchant.ARROW_7";
    if (value == 1047) return "FeatPrestigeEnchant.ARROW_8";
    if (value == 1048) return "FeatPrestigeEnchant.ARROW_9";
    return "FeatPrestigeEnchant.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPrestigeEnchant.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPrestigeEnchant.(not found: " + value + ")";
  }
}
