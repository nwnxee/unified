package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EYE_OF_GRUUMSH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEyeOfGruumsh {
  private FeatEyeOfGruumsh() {}

  public final static int BLINDING_SPITTLE = 480;
  public final static int BLINDING_SPITTLE_2 = 481;
  public final static int COMMAND_THE_HORDE = 482;
  public final static int RITUAL_SCARRING = 484;
  public final static int SIGHT_OF_GRUUMSH = 487;
  public final static int SWING_BLINDLY = 483;

  public static String nameOf(int value) {
    if (value == 480) return "FeatEyeOfGruumsh.BLINDING_SPITTLE";
    if (value == 481) return "FeatEyeOfGruumsh.BLINDING_SPITTLE_2";
    if (value == 482) return "FeatEyeOfGruumsh.COMMAND_THE_HORDE";
    if (value == 484) return "FeatEyeOfGruumsh.RITUAL_SCARRING";
    if (value == 487) return "FeatEyeOfGruumsh.SIGHT_OF_GRUUMSH";
    if (value == 483) return "FeatEyeOfGruumsh.SWING_BLINDLY";
    return "FeatEyeOfGruumsh.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEyeOfGruumsh.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEyeOfGruumsh.(not found: " + value + ")";
  }
}
