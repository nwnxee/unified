package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_SAVEBASETYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstSavebasetype {
  private IpConstSavebasetype() {}

  public final static int FORTITUDE = 1;
  public final static int REFLEX = 3;
  public final static int WILL = 2;

  public static String nameOf(int value) {
    if (value == 1) return "IpConstSavebasetype.FORTITUDE";
    if (value == 3) return "IpConstSavebasetype.REFLEX";
    if (value == 2) return "IpConstSavebasetype.WILL";
    return "IpConstSavebasetype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstSavebasetype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstSavebasetype.(not found: " + value + ")";
  }
}
