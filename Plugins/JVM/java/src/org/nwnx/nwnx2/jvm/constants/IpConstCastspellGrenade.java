package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_GRENADE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellGrenade {
  private IpConstCastspellGrenade() {}

  public final static int ACID_1 = 341;
  public final static int CALTROPS_1 = 343;
  public final static int CHICKEN_1 = 342;
  public final static int CHOKING_1 = 339;
  public final static int FIRE_1 = 336;
  public final static int HOLY_1 = 338;
  public final static int TANGLE_1 = 337;
  public final static int THUNDERSTONE_1 = 340;

  public static String nameOf(int value) {
    if (value == 341) return "IpConstCastspellGrenade.ACID_1";
    if (value == 343) return "IpConstCastspellGrenade.CALTROPS_1";
    if (value == 342) return "IpConstCastspellGrenade.CHICKEN_1";
    if (value == 339) return "IpConstCastspellGrenade.CHOKING_1";
    if (value == 336) return "IpConstCastspellGrenade.FIRE_1";
    if (value == 338) return "IpConstCastspellGrenade.HOLY_1";
    if (value == 337) return "IpConstCastspellGrenade.TANGLE_1";
    if (value == 340) return "IpConstCastspellGrenade.THUNDERSTONE_1";
    return "IpConstCastspellGrenade.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellGrenade.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellGrenade.(not found: " + value + ")";
  }
}
