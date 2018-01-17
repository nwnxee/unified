package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "COLOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Color {
  private Color() {}

  public final static int CHANNEL_HAIR = 1;
  public final static int CHANNEL_SKIN = 0;
  public final static int CHANNEL_TATTOO_1 = 2;
  public final static int CHANNEL_TATTOO_2 = 3;

  public static String nameOf(int value) {
    if (value == 1) return "Color.CHANNEL_HAIR";
    if (value == 0) return "Color.CHANNEL_SKIN";
    if (value == 2) return "Color.CHANNEL_TATTOO_1";
    if (value == 3) return "Color.CHANNEL_TATTOO_2";
    return "Color.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Color.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Color.(not found: " + value + ")";
  }
}
