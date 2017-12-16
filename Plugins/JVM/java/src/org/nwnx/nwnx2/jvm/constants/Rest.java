package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "REST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Rest {
  private Rest() {}

  public final static int EVENTTYPE_CANCELLED = 3;
  public final static int EVENTTYPE_FINISHED = 2;
  public final static int EVENTTYPE_INVALID = 0;
  public final static int EVENTTYPE_STARTED = 1;

  public static String nameOf(int value) {
    if (value == 3) return "Rest.EVENTTYPE_CANCELLED";
    if (value == 2) return "Rest.EVENTTYPE_FINISHED";
    if (value == 0) return "Rest.EVENTTYPE_INVALID";
    if (value == 1) return "Rest.EVENTTYPE_STARTED";
    return "Rest.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Rest.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Rest.(not found: " + value + ")";
  }
}
