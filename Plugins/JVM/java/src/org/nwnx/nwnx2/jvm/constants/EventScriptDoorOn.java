package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_DOOR_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptDoorOn {
  private EventScriptDoorOn() {}

  public final static int CLICKED = 10012;
  public final static int CLOSE = 10001;
  public final static int DAMAGE = 10002;
  public final static int DEATH = 10003;
  public final static int DIALOGUE = 10013;
  public final static int DISARM = 10004;
  public final static int FAIL_TO_OPEN = 10014;
  public final static int HEARTBEAT = 10005;
  public final static int LOCK = 10006;
  public final static int MELEE_ATTACKED = 10007;
  public final static int OPEN = 10000;
  public final static int SPELLCASTAT = 10008;
  public final static int TRAPTRIGGERED = 10009;
  public final static int UNLOCK = 10010;
  public final static int USERDEFINED = 10011;

  public static String nameOf(int value) {
    if (value == 10012) return "EventScriptDoorOn.CLICKED";
    if (value == 10001) return "EventScriptDoorOn.CLOSE";
    if (value == 10002) return "EventScriptDoorOn.DAMAGE";
    if (value == 10003) return "EventScriptDoorOn.DEATH";
    if (value == 10013) return "EventScriptDoorOn.DIALOGUE";
    if (value == 10004) return "EventScriptDoorOn.DISARM";
    if (value == 10014) return "EventScriptDoorOn.FAIL_TO_OPEN";
    if (value == 10005) return "EventScriptDoorOn.HEARTBEAT";
    if (value == 10006) return "EventScriptDoorOn.LOCK";
    if (value == 10007) return "EventScriptDoorOn.MELEE_ATTACKED";
    if (value == 10000) return "EventScriptDoorOn.OPEN";
    if (value == 10008) return "EventScriptDoorOn.SPELLCASTAT";
    if (value == 10009) return "EventScriptDoorOn.TRAPTRIGGERED";
    if (value == 10010) return "EventScriptDoorOn.UNLOCK";
    if (value == 10011) return "EventScriptDoorOn.USERDEFINED";
    return "EventScriptDoorOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptDoorOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptDoorOn.(not found: " + value + ")";
  }
}
