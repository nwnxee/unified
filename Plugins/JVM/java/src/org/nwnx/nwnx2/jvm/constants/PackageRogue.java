package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_ROGUE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageRogue {
  private PackageRogue() {}

  public final static int BANDIT = 60;
  public final static int GYPSY = 59;
  public final static int PACKAGE_ROGUE = 8;
  public final static int SCOUT = 61;
  public final static int SHADOWDANCER = 98;
  public final static int SHADOWDANCER_2NDCLASS = 126;
  public final static int SWASHBUCKLER = 62;

  public static String nameOf(int value) {
    if (value == 60) return "PackageRogue.BANDIT";
    if (value == 59) return "PackageRogue.GYPSY";
    if (value == 8) return "PackageRogue.PACKAGE_ROGUE";
    if (value == 61) return "PackageRogue.SCOUT";
    if (value == 98) return "PackageRogue.SHADOWDANCER";
    if (value == 126) return "PackageRogue.SHADOWDANCER_2NDCLASS";
    if (value == 62) return "PackageRogue.SWASHBUCKLER";
    return "PackageRogue.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageRogue.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageRogue.(not found: " + value + ")";
  }
}
