package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PERCEPTION_NOT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PerceptionNot {
  private PerceptionNot() {}

  public final static int HEARD = 4;
  public final static int SEEN = 6;
  public final static int SEEN_AND_NOT_HEARD = 1;

  public static String nameOf(int value) {
    if (value == 4) return "PerceptionNot.HEARD";
    if (value == 6) return "PerceptionNot.SEEN";
    if (value == 1) return "PerceptionNot.SEEN_AND_NOT_HEARD";
    return "PerceptionNot.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PerceptionNot.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PerceptionNot.(not found: " + value + ")";
  }
}
