package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BATTLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBattle {
  private FeatBattle() {}

  public final static int TRAINING_VERSUS_GIANTS = 233;
  public final static int TRAINING_VERSUS_GOBLINS = 232;
  public final static int TRAINING_VERSUS_ORCS = 231;
  public final static int TRAINING_VERSUS_REPTILIANS = 242;

  public static String nameOf(int value) {
    if (value == 233) return "FeatBattle.TRAINING_VERSUS_GIANTS";
    if (value == 232) return "FeatBattle.TRAINING_VERSUS_GOBLINS";
    if (value == 231) return "FeatBattle.TRAINING_VERSUS_ORCS";
    if (value == 242) return "FeatBattle.TRAINING_VERSUS_REPTILIANS";
    return "FeatBattle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBattle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBattle.(not found: " + value + ")";
  }
}
