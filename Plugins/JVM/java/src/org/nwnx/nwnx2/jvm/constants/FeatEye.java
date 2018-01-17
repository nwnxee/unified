package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EYE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEye {
  private FeatEye() {}

  public final static int OF_GRUUMSH_BLINDING_SPITTLE = 480;
  public final static int OF_GRUUMSH_BLINDING_SPITTLE_2 = 481;
  public final static int OF_GRUUMSH_COMMAND_THE_HORDE = 482;
  public final static int OF_GRUUMSH_RITUAL_SCARRING = 484;
  public final static int OF_GRUUMSH_SIGHT_OF_GRUUMSH = 487;
  public final static int OF_GRUUMSH_SWING_BLINDLY = 483;

  public static String nameOf(int value) {
    if (value == 480) return "FeatEye.OF_GRUUMSH_BLINDING_SPITTLE";
    if (value == 481) return "FeatEye.OF_GRUUMSH_BLINDING_SPITTLE_2";
    if (value == 482) return "FeatEye.OF_GRUUMSH_COMMAND_THE_HORDE";
    if (value == 484) return "FeatEye.OF_GRUUMSH_RITUAL_SCARRING";
    if (value == 487) return "FeatEye.OF_GRUUMSH_SIGHT_OF_GRUUMSH";
    if (value == 483) return "FeatEye.OF_GRUUMSH_SWING_BLINDLY";
    return "FeatEye.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEye.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEye.(not found: " + value + ")";
  }
}
