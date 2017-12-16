package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_CLERIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageCleric {
  private PackageCleric() {}

  public final static int BATTLE_PRIEST = 22;
  public final static int DEADWALKER = 20;
  public final static int DIVINE = 92;
  public final static int DIVINE_2NDCLASS = 120;
  public final static int ELEMENTALIST = 21;
  public final static int PACKAGE_CLERIC = 2;
  public final static int SHAMAN = 19;

  public static String nameOf(int value) {
    if (value == 22) return "PackageCleric.BATTLE_PRIEST";
    if (value == 20) return "PackageCleric.DEADWALKER";
    if (value == 92) return "PackageCleric.DIVINE";
    if (value == 120) return "PackageCleric.DIVINE_2NDCLASS";
    if (value == 21) return "PackageCleric.ELEMENTALIST";
    if (value == 2) return "PackageCleric.PACKAGE_CLERIC";
    if (value == 19) return "PackageCleric.SHAMAN";
    return "PackageCleric.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageCleric.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageCleric.(not found: " + value + ")";
  }
}
