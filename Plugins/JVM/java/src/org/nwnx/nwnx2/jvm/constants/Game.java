package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "GAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Game {
  private Game() {}

  public final static int DIFFICULTY_CORE_RULES = 3;
  public final static int DIFFICULTY_DIFFICULT = 4;
  public final static int DIFFICULTY_EASY = 1;
  public final static int DIFFICULTY_NORMAL = 2;
  public final static int DIFFICULTY_VERY_EASY = 0;

  public static String nameOf(int value) {
    if (value == 3) return "Game.DIFFICULTY_CORE_RULES";
    if (value == 4) return "Game.DIFFICULTY_DIFFICULT";
    if (value == 1) return "Game.DIFFICULTY_EASY";
    if (value == 2) return "Game.DIFFICULTY_NORMAL";
    if (value == 0) return "Game.DIFFICULTY_VERY_EASY";
    return "Game.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Game.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Game.(not found: " + value + ")";
  }
}
