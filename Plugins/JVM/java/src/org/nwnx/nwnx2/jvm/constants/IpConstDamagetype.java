package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_DAMAGETYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstDamagetype {
  private IpConstDamagetype() {}

  public final static int ACID = 6;
  public final static int BLUDGEONING = 0;
  public final static int COLD = 7;
  public final static int DIVINE = 8;
  public final static int ELECTRICAL = 9;
  public final static int FIRE = 10;
  public final static int MAGICAL = 5;
  public final static int NEGATIVE = 11;
  public final static int PHYSICAL = 4;
  public final static int PIERCING = 1;
  public final static int POSITIVE = 12;
  public final static int SLASHING = 2;
  public final static int SONIC = 13;
  public final static int SUBDUAL = 3;

  public static String nameOf(int value) {
    if (value == 6) return "IpConstDamagetype.ACID";
    if (value == 0) return "IpConstDamagetype.BLUDGEONING";
    if (value == 7) return "IpConstDamagetype.COLD";
    if (value == 8) return "IpConstDamagetype.DIVINE";
    if (value == 9) return "IpConstDamagetype.ELECTRICAL";
    if (value == 10) return "IpConstDamagetype.FIRE";
    if (value == 5) return "IpConstDamagetype.MAGICAL";
    if (value == 11) return "IpConstDamagetype.NEGATIVE";
    if (value == 4) return "IpConstDamagetype.PHYSICAL";
    if (value == 1) return "IpConstDamagetype.PIERCING";
    if (value == 12) return "IpConstDamagetype.POSITIVE";
    if (value == 2) return "IpConstDamagetype.SLASHING";
    if (value == 13) return "IpConstDamagetype.SONIC";
    if (value == 3) return "IpConstDamagetype.SUBDUAL";
    return "IpConstDamagetype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstDamagetype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstDamagetype.(not found: " + value + ")";
  }
}
