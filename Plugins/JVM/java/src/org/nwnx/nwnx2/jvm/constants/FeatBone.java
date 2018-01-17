package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_BONE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatBone {
  private FeatBone() {}

  public final static int SKIN_2 = 886;
  public final static int SKIN_4 = 887;
  public final static int SKIN_6 = 888;

  public static String nameOf(int value) {
    if (value == 886) return "FeatBone.SKIN_2";
    if (value == 887) return "FeatBone.SKIN_4";
    if (value == 888) return "FeatBone.SKIN_6";
    return "FeatBone.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatBone.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatBone.(not found: " + value + ")";
  }
}
