package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_SUMMON_CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellSummonCreature {
  private IpConstCastspellSummonCreature() {}

  public final static int III_5 = 265;
  public final static int II_3 = 264;
  public final static int IV_7 = 266;
  public final static int IX_17 = 267;
  public final static int I_2 = 262;
  public final static int I_5 = 263;
  public final static int VIII_15 = 271;
  public final static int VII_13 = 270;
  public final static int VI_11 = 269;
  public final static int V_9 = 268;

  public static String nameOf(int value) {
    if (value == 265) return "IpConstCastspellSummonCreature.III_5";
    if (value == 264) return "IpConstCastspellSummonCreature.II_3";
    if (value == 266) return "IpConstCastspellSummonCreature.IV_7";
    if (value == 267) return "IpConstCastspellSummonCreature.IX_17";
    if (value == 262) return "IpConstCastspellSummonCreature.I_2";
    if (value == 263) return "IpConstCastspellSummonCreature.I_5";
    if (value == 271) return "IpConstCastspellSummonCreature.VIII_15";
    if (value == 270) return "IpConstCastspellSummonCreature.VII_13";
    if (value == 269) return "IpConstCastspellSummonCreature.VI_11";
    if (value == 268) return "IpConstCastspellSummonCreature.V_9";
    return "IpConstCastspellSummonCreature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellSummonCreature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellSummonCreature.(not found: " + value + ")";
  }
}
