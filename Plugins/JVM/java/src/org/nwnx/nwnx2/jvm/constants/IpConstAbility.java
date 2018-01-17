package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ABILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstAbility {
  private IpConstAbility() {}

  public final static int CHA = 5;
  public final static int CON = 2;
  public final static int DEX = 1;
  public final static int INT = 3;
  public final static int STR = 0;
  public final static int WIS = 4;

  public static String nameOf(int value) {
    if (value == 5) return "IpConstAbility.CHA";
    if (value == 2) return "IpConstAbility.CON";
    if (value == 1) return "IpConstAbility.DEX";
    if (value == 3) return "IpConstAbility.INT";
    if (value == 0) return "IpConstAbility.STR";
    if (value == 4) return "IpConstAbility.WIS";
    return "IpConstAbility.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstAbility.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstAbility.(not found: " + value + ")";
  }
}
