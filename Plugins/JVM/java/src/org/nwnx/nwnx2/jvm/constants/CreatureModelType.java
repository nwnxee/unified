package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_MODEL_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureModelType {
  private CreatureModelType() {}

  public final static int NONE = 0;
  public final static int SKIN = 1;
  public final static int TATTOO = 2;
  public final static int UNDEAD = 255;

  public static String nameOf(int value) {
    if (value == 0) return "CreatureModelType.NONE";
    if (value == 1) return "CreatureModelType.SKIN";
    if (value == 2) return "CreatureModelType.TATTOO";
    if (value == 255) return "CreatureModelType.UNDEAD";
    return "CreatureModelType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureModelType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureModelType.(not found: " + value + ")";
  }
}
