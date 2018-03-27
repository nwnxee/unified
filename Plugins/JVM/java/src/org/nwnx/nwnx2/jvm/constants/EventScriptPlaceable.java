package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_PLACEABLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptPlaceable {
  private EventScriptPlaceable() {}

  public final static int ON_CLOSED = 9000;
  public final static int ON_DAMAGED = 9001;
  public final static int ON_DEATH = 9002;
  public final static int ON_DIALOGUE = 9014;
  public final static int ON_DISARM = 9003;
  public final static int ON_HEARTBEAT = 9004;
  public final static int ON_INVENTORYDISTURBED = 9005;
  public final static int ON_LEFT_CLICK = 9015;
  public final static int ON_LOCK = 9006;
  public final static int ON_MELEEATTACKED = 9007;
  public final static int ON_OPEN = 9008;
  public final static int ON_SPELLCASTAT = 9009;
  public final static int ON_TRAPTRIGGERED = 9010;
  public final static int ON_UNLOCK = 9011;
  public final static int ON_USED = 9012;
  public final static int ON_USER_DEFINED_EVENT = 9013;

  public static String nameOf(int value) {
    if (value == 9000) return "EventScriptPlaceable.ON_CLOSED";
    if (value == 9001) return "EventScriptPlaceable.ON_DAMAGED";
    if (value == 9002) return "EventScriptPlaceable.ON_DEATH";
    if (value == 9014) return "EventScriptPlaceable.ON_DIALOGUE";
    if (value == 9003) return "EventScriptPlaceable.ON_DISARM";
    if (value == 9004) return "EventScriptPlaceable.ON_HEARTBEAT";
    if (value == 9005) return "EventScriptPlaceable.ON_INVENTORYDISTURBED";
    if (value == 9015) return "EventScriptPlaceable.ON_LEFT_CLICK";
    if (value == 9006) return "EventScriptPlaceable.ON_LOCK";
    if (value == 9007) return "EventScriptPlaceable.ON_MELEEATTACKED";
    if (value == 9008) return "EventScriptPlaceable.ON_OPEN";
    if (value == 9009) return "EventScriptPlaceable.ON_SPELLCASTAT";
    if (value == 9010) return "EventScriptPlaceable.ON_TRAPTRIGGERED";
    if (value == 9011) return "EventScriptPlaceable.ON_UNLOCK";
    if (value == 9012) return "EventScriptPlaceable.ON_USED";
    if (value == 9013) return "EventScriptPlaceable.ON_USER_DEFINED_EVENT";
    return "EventScriptPlaceable.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptPlaceable.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptPlaceable.(not found: " + value + ")";
  }
}
