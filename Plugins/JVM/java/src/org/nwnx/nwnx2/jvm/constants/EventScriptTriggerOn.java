package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_TRIGGER_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptTriggerOn {
  private EventScriptTriggerOn() {}

  public final static int CLICKED = 7006;
  public final static int DISARMED = 7005;
  public final static int HEARTBEAT = 7000;
  public final static int OBJECT_ENTER = 7001;
  public final static int OBJECT_EXIT = 7002;
  public final static int TRAPTRIGGERED = 7004;
  public final static int USER_DEFINED_EVENT = 7003;

  public static String nameOf(int value) {
    if (value == 7006) return "EventScriptTriggerOn.CLICKED";
    if (value == 7005) return "EventScriptTriggerOn.DISARMED";
    if (value == 7000) return "EventScriptTriggerOn.HEARTBEAT";
    if (value == 7001) return "EventScriptTriggerOn.OBJECT_ENTER";
    if (value == 7002) return "EventScriptTriggerOn.OBJECT_EXIT";
    if (value == 7004) return "EventScriptTriggerOn.TRAPTRIGGERED";
    if (value == 7003) return "EventScriptTriggerOn.USER_DEFINED_EVENT";
    return "EventScriptTriggerOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptTriggerOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptTriggerOn.(not found: " + value + ")";
  }
}
