package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_TRIGGER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptTrigger {
  private EventScriptTrigger() {}

  public final static int ON_CLICKED = 7006;
  public final static int ON_DISARMED = 7005;
  public final static int ON_HEARTBEAT = 7000;
  public final static int ON_OBJECT_ENTER = 7001;
  public final static int ON_OBJECT_EXIT = 7002;
  public final static int ON_TRAPTRIGGERED = 7004;
  public final static int ON_USER_DEFINED_EVENT = 7003;

  public static String nameOf(int value) {
    if (value == 7006) return "EventScriptTrigger.ON_CLICKED";
    if (value == 7005) return "EventScriptTrigger.ON_DISARMED";
    if (value == 7000) return "EventScriptTrigger.ON_HEARTBEAT";
    if (value == 7001) return "EventScriptTrigger.ON_OBJECT_ENTER";
    if (value == 7002) return "EventScriptTrigger.ON_OBJECT_EXIT";
    if (value == 7004) return "EventScriptTrigger.ON_TRAPTRIGGERED";
    if (value == 7003) return "EventScriptTrigger.ON_USER_DEFINED_EVENT";
    return "EventScriptTrigger.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptTrigger.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptTrigger.(not found: " + value + ")";
  }
}
