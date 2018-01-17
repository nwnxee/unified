package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EXTRA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatExtra {
  private FeatExtra() {}

  public final static int MUSIC = 423;
  public final static int SMITING = 910;
  public final static int STUNNING_ATTACK = 410;
  public final static int TURNING = 13;

  public static String nameOf(int value) {
    if (value == 423) return "FeatExtra.MUSIC";
    if (value == 910) return "FeatExtra.SMITING";
    if (value == 410) return "FeatExtra.STUNNING_ATTACK";
    if (value == 13) return "FeatExtra.TURNING";
    return "FeatExtra.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatExtra.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatExtra.(not found: " + value + ")";
  }
}
