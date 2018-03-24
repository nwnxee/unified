package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_PLACEABLE_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptPlaceableOn {
  private EventScriptPlaceableOn() {}

  public final static int CLOSED = 9000;
  public final static int DAMAGED = 9001;
  public final static int DEATH = 9002;
  public final static int DIALOGUE = 9014;
  public final static int DISARM = 9003;
  public final static int HEARTBEAT = 9004;
  public final static int INVENTORYDISTURBED = 9005;
  public final static int LEFT_CLICK = 9015;
  public final static int LOCK = 9006;
  public final static int MELEEATTACKED = 9007;
  public final static int OPEN = 9008;
  public final static int SPELLCASTAT = 9009;
  public final static int TRAPTRIGGERED = 9010;
  public final static int UNLOCK = 9011;
  public final static int USED = 9012;
  public final static int USER_DEFINED_EVENT = 9013;

  public static String nameOf(int value) {
    if (value == 9000) return "EventScriptPlaceableOn.CLOSED";
    if (value == 9001) return "EventScriptPlaceableOn.DAMAGED";
    if (value == 9002) return "EventScriptPlaceableOn.DEATH";
    if (value == 9014) return "EventScriptPlaceableOn.DIALOGUE";
    if (value == 9003) return "EventScriptPlaceableOn.DISARM";
    if (value == 9004) return "EventScriptPlaceableOn.HEARTBEAT";
    if (value == 9005) return "EventScriptPlaceableOn.INVENTORYDISTURBED";
    if (value == 9015) return "EventScriptPlaceableOn.LEFT_CLICK";
    if (value == 9006) return "EventScriptPlaceableOn.LOCK";
    if (value == 9007) return "EventScriptPlaceableOn.MELEEATTACKED";
    if (value == 9008) return "EventScriptPlaceableOn.OPEN";
    if (value == 9009) return "EventScriptPlaceableOn.SPELLCASTAT";
    if (value == 9010) return "EventScriptPlaceableOn.TRAPTRIGGERED";
    if (value == 9011) return "EventScriptPlaceableOn.UNLOCK";
    if (value == 9012) return "EventScriptPlaceableOn.USED";
    if (value == 9013) return "EventScriptPlaceableOn.USER_DEFINED_EVENT";
    return "EventScriptPlaceableOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptPlaceableOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptPlaceableOn.(not found: " + value + ")";
  }
}
