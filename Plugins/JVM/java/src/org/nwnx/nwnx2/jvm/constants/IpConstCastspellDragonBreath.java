package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DRAGON_BREATH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDragonBreath {
  private IpConstCastspellDragonBreath() {}

  public final static int ACID_10 = 400;
  public final static int COLD_10 = 401;
  public final static int FEAR_10 = 402;
  public final static int FIRE_10 = 403;
  public final static int GAS_10 = 404;
  public final static int LIGHTNING_10 = 405;
  public final static int PARALYZE_10 = 406;
  public final static int SLEEP_10 = 407;
  public final static int SLOW_10 = 408;
  public final static int WEAKEN_10 = 409;

  public static String nameOf(int value) {
    if (value == 400) return "IpConstCastspellDragonBreath.ACID_10";
    if (value == 401) return "IpConstCastspellDragonBreath.COLD_10";
    if (value == 402) return "IpConstCastspellDragonBreath.FEAR_10";
    if (value == 403) return "IpConstCastspellDragonBreath.FIRE_10";
    if (value == 404) return "IpConstCastspellDragonBreath.GAS_10";
    if (value == 405) return "IpConstCastspellDragonBreath.LIGHTNING_10";
    if (value == 406) return "IpConstCastspellDragonBreath.PARALYZE_10";
    if (value == 407) return "IpConstCastspellDragonBreath.SLEEP_10";
    if (value == 408) return "IpConstCastspellDragonBreath.SLOW_10";
    if (value == 409) return "IpConstCastspellDragonBreath.WEAKEN_10";
    return "IpConstCastspellDragonBreath.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDragonBreath.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDragonBreath.(not found: " + value + ")";
  }
}
