package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_TAIL_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureTailType {
  private CreatureTailType() {}

  public final static int BONE = 2;
  public final static int DEVIL = 3;
  public final static int LIZARD = 1;
  public final static int NONE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "CreatureTailType.BONE";
    if (value == 3) return "CreatureTailType.DEVIL";
    if (value == 1) return "CreatureTailType.LIZARD";
    if (value == 0) return "CreatureTailType.NONE";
    return "CreatureTailType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureTailType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureTailType.(not found: " + value + ")";
  }
}
