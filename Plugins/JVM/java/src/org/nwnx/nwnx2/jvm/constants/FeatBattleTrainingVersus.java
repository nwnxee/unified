package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BATTLE_TRAINING_VERSUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBattleTrainingVersus {
  private FeatBattleTrainingVersus() {}

  public final static int GIANTS = 233;
  public final static int GOBLINS = 232;
  public final static int ORCS = 231;
  public final static int REPTILIANS = 242;

  public static String nameOf(int value) {
    if (value == 233) return "FeatBattleTrainingVersus.GIANTS";
    if (value == 232) return "FeatBattleTrainingVersus.GOBLINS";
    if (value == 231) return "FeatBattleTrainingVersus.ORCS";
    if (value == 242) return "FeatBattleTrainingVersus.REPTILIANS";
    return "FeatBattleTrainingVersus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBattleTrainingVersus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBattleTrainingVersus.(not found: " + value + ")";
  }
}
