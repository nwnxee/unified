package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_ENCOUNTER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptEncounter {
  private EventScriptEncounter() {}

  public final static int ON_ENCOUNTER_EXHAUSTED = 13003;
  public final static int ON_HEARTBEAT = 13002;
  public final static int ON_OBJECT_ENTER = 13000;
  public final static int ON_OBJECT_EXIT = 13001;
  public final static int ON_USER_DEFINED_EVENT = 13004;

  public static String nameOf(int value) {
    if (value == 13003) return "EventScriptEncounter.ON_ENCOUNTER_EXHAUSTED";
    if (value == 13002) return "EventScriptEncounter.ON_HEARTBEAT";
    if (value == 13000) return "EventScriptEncounter.ON_OBJECT_ENTER";
    if (value == 13001) return "EventScriptEncounter.ON_OBJECT_EXIT";
    if (value == 13004) return "EventScriptEncounter.ON_USER_DEFINED_EVENT";
    return "EventScriptEncounter.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptEncounter.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptEncounter.(not found: " + value + ")";
  }
}
