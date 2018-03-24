package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_AREA_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptAreaOn {
  private EventScriptAreaOn() {}

  public final static int ENTER = 4002;
  public final static int EXIT = 4003;
  public final static int HEARTBEAT = 4000;
  public final static int USER_DEFINED_EVENT = 4001;

  public static String nameOf(int value) {
    if (value == 4002) return "EventScriptAreaOn.ENTER";
    if (value == 4003) return "EventScriptAreaOn.EXIT";
    if (value == 4000) return "EventScriptAreaOn.HEARTBEAT";
    if (value == 4001) return "EventScriptAreaOn.USER_DEFINED_EVENT";
    return "EventScriptAreaOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptAreaOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptAreaOn.(not found: " + value + ")";
  }
}
