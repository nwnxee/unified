package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_MODULE_ON_PLAYER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptModuleOnPlayer {
  private EventScriptModuleOnPlayer() {}

  public final static int CANCEL_CUTSCENE = 3014;
  public final static int CHAT = 3017;
  public final static int DEATH = 3009;
  public final static int DYING = 3010;
  public final static int LEVEL_UP = 3013;
  public final static int REST = 3012;

  public static String nameOf(int value) {
    if (value == 3014) return "EventScriptModuleOnPlayer.CANCEL_CUTSCENE";
    if (value == 3017) return "EventScriptModuleOnPlayer.CHAT";
    if (value == 3009) return "EventScriptModuleOnPlayer.DEATH";
    if (value == 3010) return "EventScriptModuleOnPlayer.DYING";
    if (value == 3013) return "EventScriptModuleOnPlayer.LEVEL_UP";
    if (value == 3012) return "EventScriptModuleOnPlayer.REST";
    return "EventScriptModuleOnPlayer.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptModuleOnPlayer.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptModuleOnPlayer.(not found: " + value + ")";
  }
}
