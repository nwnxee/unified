package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_CREATURE_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptCreatureOn {
  private EventScriptCreatureOn() {}

  public final static int BLOCKED_BY_DOOR = 5012;
  public final static int DAMAGED = 5004;
  public final static int DEATH = 5010;
  public final static int DIALOGUE = 5007;
  public final static int DISTURBED = 5005;
  public final static int END_COMBATROUND = 5006;
  public final static int HEARTBEAT = 5000;
  public final static int MELEE_ATTACKED = 5003;
  public final static int NOTICE = 5001;
  public final static int RESTED = 5009;
  public final static int SPAWN_IN = 5008;
  public final static int SPELLCASTAT = 5002;
  public final static int USER_DEFINED_EVENT = 5011;

  public static String nameOf(int value) {
    if (value == 5012) return "EventScriptCreatureOn.BLOCKED_BY_DOOR";
    if (value == 5004) return "EventScriptCreatureOn.DAMAGED";
    if (value == 5010) return "EventScriptCreatureOn.DEATH";
    if (value == 5007) return "EventScriptCreatureOn.DIALOGUE";
    if (value == 5005) return "EventScriptCreatureOn.DISTURBED";
    if (value == 5006) return "EventScriptCreatureOn.END_COMBATROUND";
    if (value == 5000) return "EventScriptCreatureOn.HEARTBEAT";
    if (value == 5003) return "EventScriptCreatureOn.MELEE_ATTACKED";
    if (value == 5001) return "EventScriptCreatureOn.NOTICE";
    if (value == 5009) return "EventScriptCreatureOn.RESTED";
    if (value == 5008) return "EventScriptCreatureOn.SPAWN_IN";
    if (value == 5002) return "EventScriptCreatureOn.SPELLCASTAT";
    if (value == 5011) return "EventScriptCreatureOn.USER_DEFINED_EVENT";
    return "EventScriptCreatureOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptCreatureOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptCreatureOn.(not found: " + value + ")";
  }
}
