package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_PALADIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackagePaladin {
  private PackagePaladin() {}

  public final static int CHAMPION = 54;
  public final static int DIVINE = 96;
  public final static int DIVINE_2NDCLASS = 124;
  public final static int ERRANT = 51;
  public final static int INQUISITOR = 53;
  public final static int PACKAGE_PALADIN = 6;
  public final static int UNDEAD = 52;

  public static String nameOf(int value) {
    if (value == 54) return "PackagePaladin.CHAMPION";
    if (value == 96) return "PackagePaladin.DIVINE";
    if (value == 124) return "PackagePaladin.DIVINE_2NDCLASS";
    if (value == 51) return "PackagePaladin.ERRANT";
    if (value == 53) return "PackagePaladin.INQUISITOR";
    if (value == 6) return "PackagePaladin.PACKAGE_PALADIN";
    if (value == 52) return "PackagePaladin.UNDEAD";
    return "PackagePaladin.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackagePaladin.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackagePaladin.(not found: " + value + ")";
  }
}
