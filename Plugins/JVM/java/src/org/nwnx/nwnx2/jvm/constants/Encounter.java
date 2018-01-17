package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ENCOUNTER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Encounter {
  private Encounter() {}

  public final static int DIFFICULTY_EASY = 1;
  public final static int DIFFICULTY_HARD = 3;
  public final static int DIFFICULTY_IMPOSSIBLE = 4;
  public final static int DIFFICULTY_NORMAL = 2;
  public final static int DIFFICULTY_VERY_EASY = 0;

  public static String nameOf(int value) {
    if (value == 1) return "Encounter.DIFFICULTY_EASY";
    if (value == 3) return "Encounter.DIFFICULTY_HARD";
    if (value == 4) return "Encounter.DIFFICULTY_IMPOSSIBLE";
    if (value == 2) return "Encounter.DIFFICULTY_NORMAL";
    if (value == 0) return "Encounter.DIFFICULTY_VERY_EASY";
    return "Encounter.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Encounter.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Encounter.(not found: " + value + ")";
  }
}
