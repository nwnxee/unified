package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_DRUID".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageDruid {
  private PackageDruid() {}

  public final static int DEATH = 13;
  public final static int GRAY = 12;
  public final static int HAWKMASTER = 14;
  public final static int INTERLOPER = 11;
  public final static int PACKAGE_DRUID = 3;
  public final static int SHIFTER = 93;
  public final static int SHIFTER_2NDCLASS = 121;

  public static String nameOf(int value) {
    if (value == 13) return "PackageDruid.DEATH";
    if (value == 12) return "PackageDruid.GRAY";
    if (value == 14) return "PackageDruid.HAWKMASTER";
    if (value == 11) return "PackageDruid.INTERLOPER";
    if (value == 3) return "PackageDruid.PACKAGE_DRUID";
    if (value == 93) return "PackageDruid.SHIFTER";
    if (value == 121) return "PackageDruid.SHIFTER_2NDCLASS";
    return "PackageDruid.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageDruid.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageDruid.(not found: " + value + ")";
  }
}
