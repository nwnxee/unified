package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FAMILIAR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Familiar {
  private Familiar() {}

  public final static int CREATURE_TYPE_BAT = 0;
  public final static int CREATURE_TYPE_CRAGCAT = 1;
  public final static int CREATURE_TYPE_EYEBALL = 10;
  public final static int CREATURE_TYPE_FAIRY_DRAGON = 8;
  public final static int CREATURE_TYPE_FIREMEPHIT = 4;
  public final static int CREATURE_TYPE_HELLHOUND = 2;
  public final static int CREATURE_TYPE_ICEMEPHIT = 5;
  public final static int CREATURE_TYPE_IMP = 3;
  public final static int CREATURE_TYPE_NONE = 255;
  public final static int CREATURE_TYPE_PIXIE = 6;
  public final static int CREATURE_TYPE_PSEUDO_DRAGON = 9;
  public final static int CREATURE_TYPE_RAVEN = 7;

  public static String nameOf(int value) {
    if (value == 0) return "Familiar.CREATURE_TYPE_BAT";
    if (value == 1) return "Familiar.CREATURE_TYPE_CRAGCAT";
    if (value == 10) return "Familiar.CREATURE_TYPE_EYEBALL";
    if (value == 8) return "Familiar.CREATURE_TYPE_FAIRY_DRAGON";
    if (value == 4) return "Familiar.CREATURE_TYPE_FIREMEPHIT";
    if (value == 2) return "Familiar.CREATURE_TYPE_HELLHOUND";
    if (value == 5) return "Familiar.CREATURE_TYPE_ICEMEPHIT";
    if (value == 3) return "Familiar.CREATURE_TYPE_IMP";
    if (value == 255) return "Familiar.CREATURE_TYPE_NONE";
    if (value == 6) return "Familiar.CREATURE_TYPE_PIXIE";
    if (value == 9) return "Familiar.CREATURE_TYPE_PSEUDO_DRAGON";
    if (value == 7) return "Familiar.CREATURE_TYPE_RAVEN";
    return "Familiar.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Familiar.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Familiar.(not found: " + value + ")";
  }
}
