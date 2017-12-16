package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_POISON_1D2".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstPoison1d2 {
  private IpConstPoison1d2() {}

  public final static int CHADAMAGE = 5;
  public final static int CONDAMAGE = 2;
  public final static int DEXDAMAGE = 1;
  public final static int INTDAMAGE = 3;
  public final static int STRDAMAGE = 0;
  public final static int WISDAMAGE = 4;

  public static String nameOf(int value) {
    if (value == 5) return "IpConstPoison1d2.CHADAMAGE";
    if (value == 2) return "IpConstPoison1d2.CONDAMAGE";
    if (value == 1) return "IpConstPoison1d2.DEXDAMAGE";
    if (value == 3) return "IpConstPoison1d2.INTDAMAGE";
    if (value == 0) return "IpConstPoison1d2.STRDAMAGE";
    if (value == 4) return "IpConstPoison1d2.WISDAMAGE";
    return "IpConstPoison1d2.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstPoison1d2.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstPoison1d2.(not found: " + value + ")";
  }
}
