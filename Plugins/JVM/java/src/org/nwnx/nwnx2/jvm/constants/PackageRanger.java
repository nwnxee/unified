package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_RANGER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageRanger {
  private PackageRanger() {}

  public final static int ARCANEARCHER = 97;
  public final static int ARCANEARCHER_2NDCLASS = 125;
  public final static int GIANTKILLER = 58;
  public final static int MARKSMAN = 55;
  public final static int PACKAGE_RANGER = 7;
  public final static int STALKER = 57;
  public final static int WARDEN = 56;

  public static String nameOf(int value) {
    if (value == 97) return "PackageRanger.ARCANEARCHER";
    if (value == 125) return "PackageRanger.ARCANEARCHER_2NDCLASS";
    if (value == 58) return "PackageRanger.GIANTKILLER";
    if (value == 55) return "PackageRanger.MARKSMAN";
    if (value == 7) return "PackageRanger.PACKAGE_RANGER";
    if (value == 57) return "PackageRanger.STALKER";
    if (value == 56) return "PackageRanger.WARDEN";
    return "PackageRanger.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageRanger.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageRanger.(not found: " + value + ")";
  }
}
