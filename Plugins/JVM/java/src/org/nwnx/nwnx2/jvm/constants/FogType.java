package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FOG_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FogType {
  private FogType() {}

  public final static int ALL = 0;
  public final static int MOON = 2;
  public final static int SUN = 1;

  public static String nameOf(int value) {
    if (value == 0) return "FogType.ALL";
    if (value == 2) return "FogType.MOON";
    if (value == 1) return "FogType.SUN";
    return "FogType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FogType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FogType.(not found: " + value + ")";
  }
}
