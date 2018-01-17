package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CASTSPELL_ELEMENTAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstCastspellElemental {
  private IpConstCastspellElemental() {}

  public final static int SHIELD_12 = 93;
  public final static int SHIELD_7 = 92;
  public final static int SWARM_17 = 94;

  public static String nameOf(int value) {
    if (value == 93) return "IpConstCastspellElemental.SHIELD_12";
    if (value == 92) return "IpConstCastspellElemental.SHIELD_7";
    if (value == 94) return "IpConstCastspellElemental.SWARM_17";
    return "IpConstCastspellElemental.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstCastspellElemental.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstCastspellElemental.(not found: " + value + ")";
  }
}
