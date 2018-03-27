package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_DOOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptDoor {
  private EventScriptDoor() {}

  public final static int ON_CLICKED = 10012;
  public final static int ON_CLOSE = 10001;
  public final static int ON_DAMAGE = 10002;
  public final static int ON_DEATH = 10003;
  public final static int ON_DIALOGUE = 10013;
  public final static int ON_DISARM = 10004;
  public final static int ON_FAIL_TO_OPEN = 10014;
  public final static int ON_HEARTBEAT = 10005;
  public final static int ON_LOCK = 10006;
  public final static int ON_MELEE_ATTACKED = 10007;
  public final static int ON_OPEN = 10000;
  public final static int ON_SPELLCASTAT = 10008;
  public final static int ON_TRAPTRIGGERED = 10009;
  public final static int ON_UNLOCK = 10010;
  public final static int ON_USERDEFINED = 10011;

  public static String nameOf(int value) {
    if (value == 10012) return "EventScriptDoor.ON_CLICKED";
    if (value == 10001) return "EventScriptDoor.ON_CLOSE";
    if (value == 10002) return "EventScriptDoor.ON_DAMAGE";
    if (value == 10003) return "EventScriptDoor.ON_DEATH";
    if (value == 10013) return "EventScriptDoor.ON_DIALOGUE";
    if (value == 10004) return "EventScriptDoor.ON_DISARM";
    if (value == 10014) return "EventScriptDoor.ON_FAIL_TO_OPEN";
    if (value == 10005) return "EventScriptDoor.ON_HEARTBEAT";
    if (value == 10006) return "EventScriptDoor.ON_LOCK";
    if (value == 10007) return "EventScriptDoor.ON_MELEE_ATTACKED";
    if (value == 10000) return "EventScriptDoor.ON_OPEN";
    if (value == 10008) return "EventScriptDoor.ON_SPELLCASTAT";
    if (value == 10009) return "EventScriptDoor.ON_TRAPTRIGGERED";
    if (value == 10010) return "EventScriptDoor.ON_UNLOCK";
    if (value == 10011) return "EventScriptDoor.ON_USERDEFINED";
    return "EventScriptDoor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptDoor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptDoor.(not found: " + value + ")";
  }
}
