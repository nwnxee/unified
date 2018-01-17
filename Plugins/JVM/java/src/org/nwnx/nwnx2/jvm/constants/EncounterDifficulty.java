package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ENCOUNTER_DIFFICULTY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EncounterDifficulty {
  private EncounterDifficulty() {}

  public final static int EASY = 1;
  public final static int HARD = 3;
  public final static int IMPOSSIBLE = 4;
  public final static int NORMAL = 2;
  public final static int VERY_EASY = 0;

  public static String nameOf(int value) {
    if (value == 1) return "EncounterDifficulty.EASY";
    if (value == 3) return "EncounterDifficulty.HARD";
    if (value == 4) return "EncounterDifficulty.IMPOSSIBLE";
    if (value == 2) return "EncounterDifficulty.NORMAL";
    if (value == 0) return "EncounterDifficulty.VERY_EASY";
    return "EncounterDifficulty.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EncounterDifficulty.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EncounterDifficulty.(not found: " + value + ")";
  }
}
