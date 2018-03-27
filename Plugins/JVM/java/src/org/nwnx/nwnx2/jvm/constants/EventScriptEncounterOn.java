package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_ENCOUNTER_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptEncounterOn {
  private EventScriptEncounterOn() {}

  public final static int ENCOUNTER_EXHAUSTED = 13003;
  public final static int HEARTBEAT = 13002;
  public final static int OBJECT_ENTER = 13000;
  public final static int OBJECT_EXIT = 13001;
  public final static int USER_DEFINED_EVENT = 13004;

  public static String nameOf(int value) {
    if (value == 13003) return "EventScriptEncounterOn.ENCOUNTER_EXHAUSTED";
    if (value == 13002) return "EventScriptEncounterOn.HEARTBEAT";
    if (value == 13000) return "EventScriptEncounterOn.OBJECT_ENTER";
    if (value == 13001) return "EventScriptEncounterOn.OBJECT_EXIT";
    if (value == 13004) return "EventScriptEncounterOn.USER_DEFINED_EVENT";
    return "EventScriptEncounterOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptEncounterOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptEncounterOn.(not found: " + value + ")";
  }
}
