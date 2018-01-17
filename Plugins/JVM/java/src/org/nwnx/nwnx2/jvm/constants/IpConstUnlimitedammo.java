package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_UNLIMITEDAMMO".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstUnlimitedammo {
  private IpConstUnlimitedammo() {}

  public final static int BASIC = 1;
  public final static int PLUS1 = 11;
  public final static int PLUS2 = 12;
  public final static int PLUS3 = 13;
  public final static int PLUS4 = 14;
  public final static int PLUS5 = 15;
  public final static int _1D6COLD = 3;
  public final static int _1D6FIRE = 2;
  public final static int _1D6LIGHT = 4;

  public static String nameOf(int value) {
    if (value == 1) return "IpConstUnlimitedammo.BASIC";
    if (value == 11) return "IpConstUnlimitedammo.PLUS1";
    if (value == 12) return "IpConstUnlimitedammo.PLUS2";
    if (value == 13) return "IpConstUnlimitedammo.PLUS3";
    if (value == 14) return "IpConstUnlimitedammo.PLUS4";
    if (value == 15) return "IpConstUnlimitedammo.PLUS5";
    if (value == 3) return "IpConstUnlimitedammo._1D6COLD";
    if (value == 2) return "IpConstUnlimitedammo._1D6FIRE";
    if (value == 4) return "IpConstUnlimitedammo._1D6LIGHT";
    return "IpConstUnlimitedammo.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstUnlimitedammo.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstUnlimitedammo.(not found: " + value + ")";
  }
}
