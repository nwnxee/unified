package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "GAME_DIFFICULTY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class GameDifficulty {
  private GameDifficulty() {}

  public final static int CORE_RULES = 3;
  public final static int DIFFICULT = 4;
  public final static int EASY = 1;
  public final static int NORMAL = 2;
  public final static int VERY_EASY = 0;

  public static String nameOf(int value) {
    if (value == 3) return "GameDifficulty.CORE_RULES";
    if (value == 4) return "GameDifficulty.DIFFICULT";
    if (value == 1) return "GameDifficulty.EASY";
    if (value == 2) return "GameDifficulty.NORMAL";
    if (value == 0) return "GameDifficulty.VERY_EASY";
    return "GameDifficulty.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "GameDifficulty.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "GameDifficulty.(not found: " + value + ")";
  }
}
