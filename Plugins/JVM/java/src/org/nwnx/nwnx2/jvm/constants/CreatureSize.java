package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_SIZE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureSize {
  private CreatureSize() {}

  public final static int HUGE = 5;
  public final static int INVALID = 0;
  public final static int LARGE = 4;
  public final static int MEDIUM = 3;
  public final static int SMALL = 2;
  public final static int TINY = 1;

  public static String nameOf(int value) {
    if (value == 5) return "CreatureSize.HUGE";
    if (value == 0) return "CreatureSize.INVALID";
    if (value == 4) return "CreatureSize.LARGE";
    if (value == 3) return "CreatureSize.MEDIUM";
    if (value == 2) return "CreatureSize.SMALL";
    if (value == 1) return "CreatureSize.TINY";
    return "CreatureSize.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureSize.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureSize.(not found: " + value + ")";
  }
}
