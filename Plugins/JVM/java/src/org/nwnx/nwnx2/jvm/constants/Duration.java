package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DURATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Duration {
  private Duration() {}

  public final static int TYPE_INSTANT = 0;
  public final static int TYPE_PERMANENT = 2;
  public final static int TYPE_TEMPORARY = 1;

  public static String nameOf(int value) {
    if (value == 0) return "Duration.TYPE_INSTANT";
    if (value == 2) return "Duration.TYPE_PERMANENT";
    if (value == 1) return "Duration.TYPE_TEMPORARY";
    return "Duration.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Duration.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Duration.(not found: " + value + ")";
  }
}
