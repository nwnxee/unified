package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_AMMOTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstAmmotype {
  private IpConstAmmotype() {}

  public final static int ARROW = 0;
  public final static int BOLT = 1;
  public final static int BULLET = 2;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstAmmotype.ARROW";
    if (value == 1) return "IpConstAmmotype.BOLT";
    if (value == 2) return "IpConstAmmotype.BULLET";
    return "IpConstAmmotype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstAmmotype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstAmmotype.(not found: " + value + ")";
  }
}
