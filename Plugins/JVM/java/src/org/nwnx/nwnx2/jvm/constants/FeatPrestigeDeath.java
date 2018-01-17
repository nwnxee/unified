package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PRESTIGE_DEATH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPrestigeDeath {
  private FeatPrestigeDeath() {}

  public final static int ATTACK_1 = 455;
  public final static int ATTACK_10 = 1020;
  public final static int ATTACK_11 = 1021;
  public final static int ATTACK_12 = 1022;
  public final static int ATTACK_13 = 1023;
  public final static int ATTACK_14 = 1024;
  public final static int ATTACK_15 = 1025;
  public final static int ATTACK_16 = 1026;
  public final static int ATTACK_17 = 1027;
  public final static int ATTACK_18 = 1028;
  public final static int ATTACK_19 = 1029;
  public final static int ATTACK_2 = 456;
  public final static int ATTACK_20 = 1030;
  public final static int ATTACK_3 = 457;
  public final static int ATTACK_4 = 458;
  public final static int ATTACK_5 = 459;
  public final static int ATTACK_6 = 1004;
  public final static int ATTACK_7 = 1005;
  public final static int ATTACK_8 = 1006;
  public final static int ATTACK_9 = 1019;

  public static String nameOf(int value) {
    if (value == 455) return "FeatPrestigeDeath.ATTACK_1";
    if (value == 1020) return "FeatPrestigeDeath.ATTACK_10";
    if (value == 1021) return "FeatPrestigeDeath.ATTACK_11";
    if (value == 1022) return "FeatPrestigeDeath.ATTACK_12";
    if (value == 1023) return "FeatPrestigeDeath.ATTACK_13";
    if (value == 1024) return "FeatPrestigeDeath.ATTACK_14";
    if (value == 1025) return "FeatPrestigeDeath.ATTACK_15";
    if (value == 1026) return "FeatPrestigeDeath.ATTACK_16";
    if (value == 1027) return "FeatPrestigeDeath.ATTACK_17";
    if (value == 1028) return "FeatPrestigeDeath.ATTACK_18";
    if (value == 1029) return "FeatPrestigeDeath.ATTACK_19";
    if (value == 456) return "FeatPrestigeDeath.ATTACK_2";
    if (value == 1030) return "FeatPrestigeDeath.ATTACK_20";
    if (value == 457) return "FeatPrestigeDeath.ATTACK_3";
    if (value == 458) return "FeatPrestigeDeath.ATTACK_4";
    if (value == 459) return "FeatPrestigeDeath.ATTACK_5";
    if (value == 1004) return "FeatPrestigeDeath.ATTACK_6";
    if (value == 1005) return "FeatPrestigeDeath.ATTACK_7";
    if (value == 1006) return "FeatPrestigeDeath.ATTACK_8";
    if (value == 1019) return "FeatPrestigeDeath.ATTACK_9";
    return "FeatPrestigeDeath.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPrestigeDeath.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPrestigeDeath.(not found: " + value + ")";
  }
}
