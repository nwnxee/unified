package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_UNCANNY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatUncanny {
  private FeatUncanny() {}

  public final static int DODGE_1 = 195;
  public final static int DODGE_2 = 251;
  public final static int DODGE_3 = 252;
  public final static int DODGE_4 = 253;
  public final static int DODGE_5 = 254;
  public final static int DODGE_6 = 255;
  public final static int REFLEX = 226;

  public static String nameOf(int value) {
    if (value == 195) return "FeatUncanny.DODGE_1";
    if (value == 251) return "FeatUncanny.DODGE_2";
    if (value == 252) return "FeatUncanny.DODGE_3";
    if (value == 253) return "FeatUncanny.DODGE_4";
    if (value == 254) return "FeatUncanny.DODGE_5";
    if (value == 255) return "FeatUncanny.DODGE_6";
    if (value == 226) return "FeatUncanny.REFLEX";
    return "FeatUncanny.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatUncanny.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatUncanny.(not found: " + value + ")";
  }
}
