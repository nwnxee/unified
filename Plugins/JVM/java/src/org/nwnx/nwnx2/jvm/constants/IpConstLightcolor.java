package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_LIGHTCOLOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstLightcolor {
  private IpConstLightcolor() {}

  public final static int BLUE = 0;
  public final static int GREEN = 4;
  public final static int ORANGE = 5;
  public final static int PURPLE = 2;
  public final static int RED = 3;
  public final static int WHITE = 6;
  public final static int YELLOW = 1;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstLightcolor.BLUE";
    if (value == 4) return "IpConstLightcolor.GREEN";
    if (value == 5) return "IpConstLightcolor.ORANGE";
    if (value == 2) return "IpConstLightcolor.PURPLE";
    if (value == 3) return "IpConstLightcolor.RED";
    if (value == 6) return "IpConstLightcolor.WHITE";
    if (value == 1) return "IpConstLightcolor.YELLOW";
    return "IpConstLightcolor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstLightcolor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstLightcolor.(not found: " + value + ")";
  }
}
