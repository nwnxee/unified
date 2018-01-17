package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BATTLE_TRAINING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBattleTraining {
  private FeatBattleTraining() {}

  public final static int VERSUS_GIANTS = 233;
  public final static int VERSUS_GOBLINS = 232;
  public final static int VERSUS_ORCS = 231;
  public final static int VERSUS_REPTILIANS = 242;

  public static String nameOf(int value) {
    if (value == 233) return "FeatBattleTraining.VERSUS_GIANTS";
    if (value == 232) return "FeatBattleTraining.VERSUS_GOBLINS";
    if (value == 231) return "FeatBattleTraining.VERSUS_ORCS";
    if (value == 242) return "FeatBattleTraining.VERSUS_REPTILIANS";
    return "FeatBattleTraining.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBattleTraining.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBattleTraining.(not found: " + value + ")";
  }
}
