package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DELAYED_BLAST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDelayedBlast {
  private IpConstCastspellDelayedBlast() {}

  public final static int FIREBALL_13 = 78;
  public final static int FIREBALL_15 = 79;
  public final static int FIREBALL_20 = 80;

  public static String nameOf(int value) {
    if (value == 78) return "IpConstCastspellDelayedBlast.FIREBALL_13";
    if (value == 79) return "IpConstCastspellDelayedBlast.FIREBALL_15";
    if (value == 80) return "IpConstCastspellDelayedBlast.FIREBALL_20";
    return "IpConstCastspellDelayedBlast.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDelayedBlast.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDelayedBlast.(not found: " + value + ")";
  }
}
