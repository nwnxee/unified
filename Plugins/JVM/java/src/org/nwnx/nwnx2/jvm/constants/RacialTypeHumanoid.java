package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "RACIAL_TYPE_HUMANOID".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class RacialTypeHumanoid {
  private RacialTypeHumanoid() {}

  public final static int GOBLINOID = 12;
  public final static int MONSTROUS = 13;
  public final static int ORC = 14;
  public final static int REPTILIAN = 15;

  public static String nameOf(int value) {
    if (value == 12) return "RacialTypeHumanoid.GOBLINOID";
    if (value == 13) return "RacialTypeHumanoid.MONSTROUS";
    if (value == 14) return "RacialTypeHumanoid.ORC";
    if (value == 15) return "RacialTypeHumanoid.REPTILIAN";
    return "RacialTypeHumanoid.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "RacialTypeHumanoid.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "RacialTypeHumanoid.(not found: " + value + ")";
  }
}
