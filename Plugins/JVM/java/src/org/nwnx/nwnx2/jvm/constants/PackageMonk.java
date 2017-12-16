package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_MONK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageMonk {
  private PackageMonk() {}

  public final static int ASSASSIN = 95;
  public final static int ASSASSIN_2NDCLASS = 123;
  public final static int DEVOUT = 49;
  public final static int GIFTED = 48;
  public final static int PACKAGE_MONK = 5;
  public final static int PEASANT = 50;
  public final static int SPIRIT = 47;

  public static String nameOf(int value) {
    if (value == 95) return "PackageMonk.ASSASSIN";
    if (value == 123) return "PackageMonk.ASSASSIN_2NDCLASS";
    if (value == 49) return "PackageMonk.DEVOUT";
    if (value == 48) return "PackageMonk.GIFTED";
    if (value == 5) return "PackageMonk.PACKAGE_MONK";
    if (value == 50) return "PackageMonk.PEASANT";
    if (value == 47) return "PackageMonk.SPIRIT";
    return "PackageMonk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageMonk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageMonk.(not found: " + value + ")";
  }
}
