package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptCreature {
  private EventScriptCreature() {}

  public final static int ON_BLOCKED_BY_DOOR = 5012;
  public final static int ON_DAMAGED = 5004;
  public final static int ON_DEATH = 5010;
  public final static int ON_DIALOGUE = 5007;
  public final static int ON_DISTURBED = 5005;
  public final static int ON_END_COMBATROUND = 5006;
  public final static int ON_HEARTBEAT = 5000;
  public final static int ON_MELEE_ATTACKED = 5003;
  public final static int ON_NOTICE = 5001;
  public final static int ON_RESTED = 5009;
  public final static int ON_SPAWN_IN = 5008;
  public final static int ON_SPELLCASTAT = 5002;
  public final static int ON_USER_DEFINED_EVENT = 5011;

  public static String nameOf(int value) {
    if (value == 5012) return "EventScriptCreature.ON_BLOCKED_BY_DOOR";
    if (value == 5004) return "EventScriptCreature.ON_DAMAGED";
    if (value == 5010) return "EventScriptCreature.ON_DEATH";
    if (value == 5007) return "EventScriptCreature.ON_DIALOGUE";
    if (value == 5005) return "EventScriptCreature.ON_DISTURBED";
    if (value == 5006) return "EventScriptCreature.ON_END_COMBATROUND";
    if (value == 5000) return "EventScriptCreature.ON_HEARTBEAT";
    if (value == 5003) return "EventScriptCreature.ON_MELEE_ATTACKED";
    if (value == 5001) return "EventScriptCreature.ON_NOTICE";
    if (value == 5009) return "EventScriptCreature.ON_RESTED";
    if (value == 5008) return "EventScriptCreature.ON_SPAWN_IN";
    if (value == 5002) return "EventScriptCreature.ON_SPELLCASTAT";
    if (value == 5011) return "EventScriptCreature.ON_USER_DEFINED_EVENT";
    return "EventScriptCreature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptCreature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptCreature.(not found: " + value + ")";
  }
}
