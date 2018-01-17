package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_DRAGON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellDragon {
  private IpConstCastspellDragon() {}

  public final static int BREATH_ACID_10 = 400;
  public final static int BREATH_COLD_10 = 401;
  public final static int BREATH_FEAR_10 = 402;
  public final static int BREATH_FIRE_10 = 403;
  public final static int BREATH_GAS_10 = 404;
  public final static int BREATH_LIGHTNING_10 = 405;
  public final static int BREATH_PARALYZE_10 = 406;
  public final static int BREATH_SLEEP_10 = 407;
  public final static int BREATH_SLOW_10 = 408;
  public final static int BREATH_WEAKEN_10 = 409;

  public static String nameOf(int value) {
    if (value == 400) return "IpConstCastspellDragon.BREATH_ACID_10";
    if (value == 401) return "IpConstCastspellDragon.BREATH_COLD_10";
    if (value == 402) return "IpConstCastspellDragon.BREATH_FEAR_10";
    if (value == 403) return "IpConstCastspellDragon.BREATH_FIRE_10";
    if (value == 404) return "IpConstCastspellDragon.BREATH_GAS_10";
    if (value == 405) return "IpConstCastspellDragon.BREATH_LIGHTNING_10";
    if (value == 406) return "IpConstCastspellDragon.BREATH_PARALYZE_10";
    if (value == 407) return "IpConstCastspellDragon.BREATH_SLEEP_10";
    if (value == 408) return "IpConstCastspellDragon.BREATH_SLOW_10";
    if (value == 409) return "IpConstCastspellDragon.BREATH_WEAKEN_10";
    return "IpConstCastspellDragon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellDragon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellDragon.(not found: " + value + ")";
  }
}
