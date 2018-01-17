package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "REST_EVENTTYPE_REST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class RestEventtypeRest {
  private RestEventtypeRest() {}

  public final static int CANCELLED = 3;
  public final static int FINISHED = 2;
  public final static int INVALID = 0;
  public final static int STARTED = 1;

  public static String nameOf(int value) {
    if (value == 3) return "RestEventtypeRest.CANCELLED";
    if (value == 2) return "RestEventtypeRest.FINISHED";
    if (value == 0) return "RestEventtypeRest.INVALID";
    if (value == 1) return "RestEventtypeRest.STARTED";
    return "RestEventtypeRest.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "RestEventtypeRest.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "RestEventtypeRest.(not found: " + value + ")";
  }
}
