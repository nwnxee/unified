package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "COLOR_CHANNEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ColorChannel {
  private ColorChannel() {}

  public final static int HAIR = 1;
  public final static int SKIN = 0;
  public final static int TATTOO_1 = 2;
  public final static int TATTOO_2 = 3;

  public static String nameOf(int value) {
    if (value == 1) return "ColorChannel.HAIR";
    if (value == 0) return "ColorChannel.SKIN";
    if (value == 2) return "ColorChannel.TATTOO_1";
    if (value == 3) return "ColorChannel.TATTOO_2";
    return "ColorChannel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ColorChannel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ColorChannel.(not found: " + value + ")";
  }
}
