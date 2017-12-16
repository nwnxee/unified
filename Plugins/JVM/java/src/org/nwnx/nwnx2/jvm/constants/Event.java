package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Event {
  private Event() {}

  public final static int ATTACKED = 1005;
  public final static int DAMAGED = 1006;
  public final static int DIALOGUE = 1004;
  public final static int DISTURBED = 1008;
  public final static int END_COMBAT_ROUND = 1003;
  public final static int HEARTBEAT = 1001;
  public final static int PERCEIVE = 1002;
  public final static int SPELL_CAST_AT = 1011;

  public static String nameOf(int value) {
    if (value == 1005) return "Event.ATTACKED";
    if (value == 1006) return "Event.DAMAGED";
    if (value == 1004) return "Event.DIALOGUE";
    if (value == 1008) return "Event.DISTURBED";
    if (value == 1003) return "Event.END_COMBAT_ROUND";
    if (value == 1001) return "Event.HEARTBEAT";
    if (value == 1002) return "Event.PERCEIVE";
    if (value == 1011) return "Event.SPELL_CAST_AT";
    return "Event.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Event.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Event.(not found: " + value + ")";
  }
}
