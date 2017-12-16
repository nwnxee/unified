package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellSpell {
  private IpConstCastspellSpell() {}

  public final static int MANTLE_13 = 257;
  public final static int RESISTANCE_15 = 256;
  public final static int RESISTANCE_9 = 255;

  public static String nameOf(int value) {
    if (value == 257) return "IpConstCastspellSpell.MANTLE_13";
    if (value == 256) return "IpConstCastspellSpell.RESISTANCE_15";
    if (value == 255) return "IpConstCastspellSpell.RESISTANCE_9";
    return "IpConstCastspellSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellSpell.(not found: " + value + ")";
  }
}
