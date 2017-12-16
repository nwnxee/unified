package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DURATION_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class DurationType {
  private DurationType() {}

  public final static int INSTANT = 0;
  public final static int PERMANENT = 2;
  public final static int TEMPORARY = 1;

  public static String nameOf(int value) {
    if (value == 0) return "DurationType.INSTANT";
    if (value == 2) return "DurationType.PERMANENT";
    if (value == 1) return "DurationType.TEMPORARY";
    return "DurationType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "DurationType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "DurationType.(not found: " + value + ")";
  }
}
