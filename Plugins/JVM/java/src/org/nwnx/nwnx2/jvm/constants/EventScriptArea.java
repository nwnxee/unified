package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_AREA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptArea {
  private EventScriptArea() {}

  public final static int ON_ENTER = 4002;
  public final static int ON_EXIT = 4003;
  public final static int ON_HEARTBEAT = 4000;
  public final static int ON_USER_DEFINED_EVENT = 4001;

  public static String nameOf(int value) {
    if (value == 4002) return "EventScriptArea.ON_ENTER";
    if (value == 4003) return "EventScriptArea.ON_EXIT";
    if (value == 4000) return "EventScriptArea.ON_HEARTBEAT";
    if (value == 4001) return "EventScriptArea.ON_USER_DEFINED_EVENT";
    return "EventScriptArea.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptArea.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptArea.(not found: " + value + ")";
  }
}
