package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_BARBARIAN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageBarbarian {
  private PackageBarbarian() {}

  public final static int BLACKGUARD = 90;
  public final static int BLACKGUARD_2NDCLASS = 118;
  public final static int BRUTE = 15;
  public final static int ORCBLOOD = 18;
  public final static int PACKAGE_BARBARIAN = 0;
  public final static int SAVAGE = 17;
  public final static int SLAYER = 16;

  public static String nameOf(int value) {
    if (value == 90) return "PackageBarbarian.BLACKGUARD";
    if (value == 118) return "PackageBarbarian.BLACKGUARD_2NDCLASS";
    if (value == 15) return "PackageBarbarian.BRUTE";
    if (value == 18) return "PackageBarbarian.ORCBLOOD";
    if (value == 0) return "PackageBarbarian.PACKAGE_BARBARIAN";
    if (value == 17) return "PackageBarbarian.SAVAGE";
    if (value == 16) return "PackageBarbarian.SLAYER";
    return "PackageBarbarian.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageBarbarian.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageBarbarian.(not found: " + value + ")";
  }
}
