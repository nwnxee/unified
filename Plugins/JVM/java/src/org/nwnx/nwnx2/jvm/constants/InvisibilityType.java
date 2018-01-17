package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVISIBILITY_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class InvisibilityType {
  private InvisibilityType() {}

  public final static int DARKNESS = 2;
  public final static int IMPROVED = 4;
  public final static int NORMAL = 1;

  public static String nameOf(int value) {
    if (value == 2) return "InvisibilityType.DARKNESS";
    if (value == 4) return "InvisibilityType.IMPROVED";
    if (value == 1) return "InvisibilityType.NORMAL";
    return "InvisibilityType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "InvisibilityType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "InvisibilityType.(not found: " + value + ")";
  }
}
