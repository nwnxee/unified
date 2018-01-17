package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_CIRCLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellCircle {
  private IpConstCastspellCircle() {}

  public final static int OF_DEATH_11 = 37;
  public final static int OF_DEATH_15 = 38;
  public final static int OF_DEATH_20 = 39;
  public final static int OF_DOOM_15 = 41;
  public final static int OF_DOOM_20 = 42;
  public final static int OF_DOOM_9 = 40;

  public static String nameOf(int value) {
    if (value == 37) return "IpConstCastspellCircle.OF_DEATH_11";
    if (value == 38) return "IpConstCastspellCircle.OF_DEATH_15";
    if (value == 39) return "IpConstCastspellCircle.OF_DEATH_20";
    if (value == 41) return "IpConstCastspellCircle.OF_DOOM_15";
    if (value == 42) return "IpConstCastspellCircle.OF_DOOM_20";
    if (value == 40) return "IpConstCastspellCircle.OF_DOOM_9";
    return "IpConstCastspellCircle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellCircle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellCircle.(not found: " + value + ")";
  }
}
