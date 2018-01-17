package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DELAYED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDelayed {
  private IpConstCastspellDelayed() {}

  public final static int BLAST_FIREBALL_13 = 78;
  public final static int BLAST_FIREBALL_15 = 79;
  public final static int BLAST_FIREBALL_20 = 80;

  public static String nameOf(int value) {
    if (value == 78) return "IpConstCastspellDelayed.BLAST_FIREBALL_13";
    if (value == 79) return "IpConstCastspellDelayed.BLAST_FIREBALL_15";
    if (value == 80) return "IpConstCastspellDelayed.BLAST_FIREBALL_20";
    return "IpConstCastspellDelayed.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDelayed.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDelayed.(not found: " + value + ")";
  }
}
