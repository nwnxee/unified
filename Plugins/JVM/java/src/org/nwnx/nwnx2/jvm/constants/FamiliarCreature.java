package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FAMILIAR_CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FamiliarCreature {
  private FamiliarCreature() {}

  public final static int TYPE_BAT = 0;
  public final static int TYPE_CRAGCAT = 1;
  public final static int TYPE_EYEBALL = 10;
  public final static int TYPE_FAIRY_DRAGON = 8;
  public final static int TYPE_FIREMEPHIT = 4;
  public final static int TYPE_HELLHOUND = 2;
  public final static int TYPE_ICEMEPHIT = 5;
  public final static int TYPE_IMP = 3;
  public final static int TYPE_NONE = 255;
  public final static int TYPE_PIXIE = 6;
  public final static int TYPE_PSEUDO_DRAGON = 9;
  public final static int TYPE_RAVEN = 7;

  public static String nameOf(int value) {
    if (value == 0) return "FamiliarCreature.TYPE_BAT";
    if (value == 1) return "FamiliarCreature.TYPE_CRAGCAT";
    if (value == 10) return "FamiliarCreature.TYPE_EYEBALL";
    if (value == 8) return "FamiliarCreature.TYPE_FAIRY_DRAGON";
    if (value == 4) return "FamiliarCreature.TYPE_FIREMEPHIT";
    if (value == 2) return "FamiliarCreature.TYPE_HELLHOUND";
    if (value == 5) return "FamiliarCreature.TYPE_ICEMEPHIT";
    if (value == 3) return "FamiliarCreature.TYPE_IMP";
    if (value == 255) return "FamiliarCreature.TYPE_NONE";
    if (value == 6) return "FamiliarCreature.TYPE_PIXIE";
    if (value == 9) return "FamiliarCreature.TYPE_PSEUDO_DRAGON";
    if (value == 7) return "FamiliarCreature.TYPE_RAVEN";
    return "FamiliarCreature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FamiliarCreature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FamiliarCreature.(not found: " + value + ")";
  }
}
