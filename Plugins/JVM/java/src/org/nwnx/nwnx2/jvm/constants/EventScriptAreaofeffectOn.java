package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_AREAOFEFFECT_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptAreaofeffectOn {
  private EventScriptAreaofeffectOn() {}

  public final static int HEARTBEAT = 11000;
  public final static int OBJECT_ENTER = 11002;
  public final static int OBJECT_EXIT = 11003;
  public final static int USER_DEFINED_EVENT = 11001;

  public static String nameOf(int value) {
    if (value == 11000) return "EventScriptAreaofeffectOn.HEARTBEAT";
    if (value == 11002) return "EventScriptAreaofeffectOn.OBJECT_ENTER";
    if (value == 11003) return "EventScriptAreaofeffectOn.OBJECT_EXIT";
    if (value == 11001) return "EventScriptAreaofeffectOn.USER_DEFINED_EVENT";
    return "EventScriptAreaofeffectOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptAreaofeffectOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptAreaofeffectOn.(not found: " + value + ")";
  }
}
