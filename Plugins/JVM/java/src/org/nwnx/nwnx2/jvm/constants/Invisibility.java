package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVISIBILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Invisibility {
  private Invisibility() {}

  public final static int TYPE_DARKNESS = 2;
  public final static int TYPE_IMPROVED = 4;
  public final static int TYPE_NORMAL = 1;

  public static String nameOf(int value) {
    if (value == 2) return "Invisibility.TYPE_DARKNESS";
    if (value == 4) return "Invisibility.TYPE_IMPROVED";
    if (value == 1) return "Invisibility.TYPE_NORMAL";
    return "Invisibility.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Invisibility.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Invisibility.(not found: " + value + ")";
  }
}
