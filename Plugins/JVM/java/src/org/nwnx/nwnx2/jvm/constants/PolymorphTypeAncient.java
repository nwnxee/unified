package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "POLYMORPH_TYPE_ANCIENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PolymorphTypeAncient {
  private PolymorphTypeAncient() {}

  public final static int BLUE_DRAGON = 71;
  public final static int GREEN_DRAGON = 73;
  public final static int RED_DRAGON = 72;

  public static String nameOf(int value) {
    if (value == 71) return "PolymorphTypeAncient.BLUE_DRAGON";
    if (value == 73) return "PolymorphTypeAncient.GREEN_DRAGON";
    if (value == 72) return "PolymorphTypeAncient.RED_DRAGON";
    return "PolymorphTypeAncient.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PolymorphTypeAncient.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PolymorphTypeAncient.(not found: " + value + ")";
  }
}
