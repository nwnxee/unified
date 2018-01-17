package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_MODEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureModel {
  private CreatureModel() {}

  public final static int TYPE_NONE = 0;
  public final static int TYPE_SKIN = 1;
  public final static int TYPE_TATTOO = 2;
  public final static int TYPE_UNDEAD = 255;

  public static String nameOf(int value) {
    if (value == 0) return "CreatureModel.TYPE_NONE";
    if (value == 1) return "CreatureModel.TYPE_SKIN";
    if (value == 2) return "CreatureModel.TYPE_TATTOO";
    if (value == 255) return "CreatureModel.TYPE_UNDEAD";
    return "CreatureModel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureModel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureModel.(not found: " + value + ")";
  }
}
