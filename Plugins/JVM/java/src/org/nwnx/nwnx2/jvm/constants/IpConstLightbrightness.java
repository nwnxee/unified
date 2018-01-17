package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_LIGHTBRIGHTNESS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstLightbrightness {
  private IpConstLightbrightness() {}

  public final static int BRIGHT = 4;
  public final static int DIM = 1;
  public final static int LOW = 2;
  public final static int NORMAL = 3;

  public static String nameOf(int value) {
    if (value == 4) return "IpConstLightbrightness.BRIGHT";
    if (value == 1) return "IpConstLightbrightness.DIM";
    if (value == 2) return "IpConstLightbrightness.LOW";
    if (value == 3) return "IpConstLightbrightness.NORMAL";
    return "IpConstLightbrightness.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstLightbrightness.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstLightbrightness.(not found: " + value + ")";
  }
}
