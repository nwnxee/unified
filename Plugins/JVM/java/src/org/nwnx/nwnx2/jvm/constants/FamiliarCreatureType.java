package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FAMILIAR_CREATURE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FamiliarCreatureType {
  private FamiliarCreatureType() {}

  public final static int BAT = 0;
  public final static int CRAGCAT = 1;
  public final static int EYEBALL = 10;
  public final static int FAIRY_DRAGON = 8;
  public final static int FIREMEPHIT = 4;
  public final static int HELLHOUND = 2;
  public final static int ICEMEPHIT = 5;
  public final static int IMP = 3;
  public final static int NONE = 255;
  public final static int PIXIE = 6;
  public final static int PSEUDO_DRAGON = 9;
  public final static int RAVEN = 7;

  public static String nameOf(int value) {
    if (value == 0) return "FamiliarCreatureType.BAT";
    if (value == 1) return "FamiliarCreatureType.CRAGCAT";
    if (value == 10) return "FamiliarCreatureType.EYEBALL";
    if (value == 8) return "FamiliarCreatureType.FAIRY_DRAGON";
    if (value == 4) return "FamiliarCreatureType.FIREMEPHIT";
    if (value == 2) return "FamiliarCreatureType.HELLHOUND";
    if (value == 5) return "FamiliarCreatureType.ICEMEPHIT";
    if (value == 3) return "FamiliarCreatureType.IMP";
    if (value == 255) return "FamiliarCreatureType.NONE";
    if (value == 6) return "FamiliarCreatureType.PIXIE";
    if (value == 9) return "FamiliarCreatureType.PSEUDO_DRAGON";
    if (value == 7) return "FamiliarCreatureType.RAVEN";
    return "FamiliarCreatureType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FamiliarCreatureType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FamiliarCreatureType.(not found: " + value + ")";
  }
}
