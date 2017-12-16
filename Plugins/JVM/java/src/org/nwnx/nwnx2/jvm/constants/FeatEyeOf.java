package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EYE_OF".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEyeOf {
  private FeatEyeOf() {}

  public final static int GRUUMSH_BLINDING_SPITTLE = 480;
  public final static int GRUUMSH_BLINDING_SPITTLE_2 = 481;
  public final static int GRUUMSH_COMMAND_THE_HORDE = 482;
  public final static int GRUUMSH_RITUAL_SCARRING = 484;
  public final static int GRUUMSH_SIGHT_OF_GRUUMSH = 487;
  public final static int GRUUMSH_SWING_BLINDLY = 483;

  public static String nameOf(int value) {
    if (value == 480) return "FeatEyeOf.GRUUMSH_BLINDING_SPITTLE";
    if (value == 481) return "FeatEyeOf.GRUUMSH_BLINDING_SPITTLE_2";
    if (value == 482) return "FeatEyeOf.GRUUMSH_COMMAND_THE_HORDE";
    if (value == 484) return "FeatEyeOf.GRUUMSH_RITUAL_SCARRING";
    if (value == 487) return "FeatEyeOf.GRUUMSH_SIGHT_OF_GRUUMSH";
    if (value == 483) return "FeatEyeOf.GRUUMSH_SWING_BLINDLY";
    return "FeatEyeOf.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEyeOf.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEyeOf.(not found: " + value + ")";
  }
}
