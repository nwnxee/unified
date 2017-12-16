package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_WIZARD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageWizard {
  private PackageWizard() {}

  public final static int ABJURATION = 27;
  public final static int CONJURATION = 28;
  public final static int DIVINATION = 29;
  public final static int ENCHANTMENT = 30;
  public final static int EVOCATION = 31;
  public final static int ILLUSION = 32;
  public final static int NECROMANCY = 33;
  public final static int PALEMASTER = 100;
  public final static int PALEMASTER_2NDCLASS = 128;
  public final static int TRANSMUTATION = 34;

  public static String nameOf(int value) {
    if (value == 27) return "PackageWizard.ABJURATION";
    if (value == 28) return "PackageWizard.CONJURATION";
    if (value == 29) return "PackageWizard.DIVINATION";
    if (value == 30) return "PackageWizard.ENCHANTMENT";
    if (value == 31) return "PackageWizard.EVOCATION";
    if (value == 32) return "PackageWizard.ILLUSION";
    if (value == 33) return "PackageWizard.NECROMANCY";
    if (value == 100) return "PackageWizard.PALEMASTER";
    if (value == 128) return "PackageWizard.PALEMASTER_2NDCLASS";
    if (value == 34) return "PackageWizard.TRANSMUTATION";
    return "PackageWizard.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageWizard.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageWizard.(not found: " + value + ")";
  }
}
