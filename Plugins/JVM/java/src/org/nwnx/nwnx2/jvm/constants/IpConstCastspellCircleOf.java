package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CIRCLE_OF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCircleOf {
  private IpConstCastspellCircleOf() {}

  public final static int DEATH_11 = 37;
  public final static int DEATH_15 = 38;
  public final static int DEATH_20 = 39;
  public final static int DOOM_15 = 41;
  public final static int DOOM_20 = 42;
  public final static int DOOM_9 = 40;

  public static String nameOf(int value) {
    if (value == 37) return "IpConstCastspellCircleOf.DEATH_11";
    if (value == 38) return "IpConstCastspellCircleOf.DEATH_15";
    if (value == 39) return "IpConstCastspellCircleOf.DEATH_20";
    if (value == 41) return "IpConstCastspellCircleOf.DOOM_15";
    if (value == 42) return "IpConstCastspellCircleOf.DOOM_20";
    if (value == 40) return "IpConstCastspellCircleOf.DOOM_9";
    return "IpConstCastspellCircleOf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCircleOf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCircleOf.(not found: " + value + ")";
  }
}
