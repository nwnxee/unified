package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PACKAGE_FIGHTER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PackageFighter {
  private PackageFighter() {}

  public final static int COMMANDER = 26;
  public final static int FINESSE = 23;
  public final static int GLADIATOR = 25;
  public final static int PACKAGE_FIGHTER = 4;
  public final static int PIRATE = 24;
  public final static int WEAPONMASTER = 94;
  public final static int WEAPONMASTER_2NDCLASS = 122;

  public static String nameOf(int value) {
    if (value == 26) return "PackageFighter.COMMANDER";
    if (value == 23) return "PackageFighter.FINESSE";
    if (value == 25) return "PackageFighter.GLADIATOR";
    if (value == 4) return "PackageFighter.PACKAGE_FIGHTER";
    if (value == 24) return "PackageFighter.PIRATE";
    if (value == 94) return "PackageFighter.WEAPONMASTER";
    if (value == 122) return "PackageFighter.WEAPONMASTER_2NDCLASS";
    return "PackageFighter.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PackageFighter.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PackageFighter.(not found: " + value + ")";
  }
}
