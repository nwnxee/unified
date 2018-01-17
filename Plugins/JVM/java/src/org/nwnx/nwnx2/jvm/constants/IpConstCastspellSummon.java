package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_SUMMON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellSummon {
  private IpConstCastspellSummon() {}

  public final static int CREATURE_III_5 = 265;
  public final static int CREATURE_II_3 = 264;
  public final static int CREATURE_IV_7 = 266;
  public final static int CREATURE_IX_17 = 267;
  public final static int CREATURE_I_2 = 262;
  public final static int CREATURE_I_5 = 263;
  public final static int CREATURE_VIII_15 = 271;
  public final static int CREATURE_VII_13 = 270;
  public final static int CREATURE_VI_11 = 269;
  public final static int CREATURE_V_9 = 268;

  public static String nameOf(int value) {
    if (value == 265) return "IpConstCastspellSummon.CREATURE_III_5";
    if (value == 264) return "IpConstCastspellSummon.CREATURE_II_3";
    if (value == 266) return "IpConstCastspellSummon.CREATURE_IV_7";
    if (value == 267) return "IpConstCastspellSummon.CREATURE_IX_17";
    if (value == 262) return "IpConstCastspellSummon.CREATURE_I_2";
    if (value == 263) return "IpConstCastspellSummon.CREATURE_I_5";
    if (value == 271) return "IpConstCastspellSummon.CREATURE_VIII_15";
    if (value == 270) return "IpConstCastspellSummon.CREATURE_VII_13";
    if (value == 269) return "IpConstCastspellSummon.CREATURE_VI_11";
    if (value == 268) return "IpConstCastspellSummon.CREATURE_V_9";
    return "IpConstCastspellSummon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellSummon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellSummon.(not found: " + value + ")";
  }
}
