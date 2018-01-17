package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_SORCERER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageSorcerer {
  private PackageSorcerer() {}

  public final static int ABJURATION = 35;
  public final static int CONJURATION = 36;
  public final static int DIVINATION = 37;
  public final static int DRAGONDISCIPLE = 99;
  public final static int DRAGONDISCIPLE_2NDCLASS = 127;
  public final static int ENCHANTMENT = 38;
  public final static int EVOCATION = 39;
  public final static int ILLUSION = 40;
  public final static int NECROMANCY = 41;
  public final static int PACKAGE_SORCERER = 9;
  public final static int TRANSMUTATION = 42;

  public static String nameOf(int value) {
    if (value == 35) return "PackageSorcerer.ABJURATION";
    if (value == 36) return "PackageSorcerer.CONJURATION";
    if (value == 37) return "PackageSorcerer.DIVINATION";
    if (value == 99) return "PackageSorcerer.DRAGONDISCIPLE";
    if (value == 127) return "PackageSorcerer.DRAGONDISCIPLE_2NDCLASS";
    if (value == 38) return "PackageSorcerer.ENCHANTMENT";
    if (value == 39) return "PackageSorcerer.EVOCATION";
    if (value == 40) return "PackageSorcerer.ILLUSION";
    if (value == 41) return "PackageSorcerer.NECROMANCY";
    if (value == 9) return "PackageSorcerer.PACKAGE_SORCERER";
    if (value == 42) return "PackageSorcerer.TRANSMUTATION";
    return "PackageSorcerer.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageSorcerer.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageSorcerer.(not found: " + value + ")";
  }
}
