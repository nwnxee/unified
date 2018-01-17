package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "REST_EVENTTYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class RestEventtype {
  private RestEventtype() {}

  public final static int REST_CANCELLED = 3;
  public final static int REST_FINISHED = 2;
  public final static int REST_INVALID = 0;
  public final static int REST_STARTED = 1;

  public static String nameOf(int value) {
    if (value == 3) return "RestEventtype.REST_CANCELLED";
    if (value == 2) return "RestEventtype.REST_FINISHED";
    if (value == 0) return "RestEventtype.REST_INVALID";
    if (value == 1) return "RestEventtype.REST_STARTED";
    return "RestEventtype.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "RestEventtype.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "RestEventtype.(not found: " + value + ")";
  }
}
