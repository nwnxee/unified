package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_AREAOFEFFECT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptAreaofeffect {
  private EventScriptAreaofeffect() {}

  public final static int ON_HEARTBEAT = 11000;
  public final static int ON_OBJECT_ENTER = 11002;
  public final static int ON_OBJECT_EXIT = 11003;
  public final static int ON_USER_DEFINED_EVENT = 11001;

  public static String nameOf(int value) {
    if (value == 11000) return "EventScriptAreaofeffect.ON_HEARTBEAT";
    if (value == 11002) return "EventScriptAreaofeffect.ON_OBJECT_ENTER";
    if (value == 11003) return "EventScriptAreaofeffect.ON_OBJECT_EXIT";
    if (value == 11001) return "EventScriptAreaofeffect.ON_USER_DEFINED_EVENT";
    return "EventScriptAreaofeffect.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptAreaofeffect.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptAreaofeffect.(not found: " + value + ")";
  }
}
