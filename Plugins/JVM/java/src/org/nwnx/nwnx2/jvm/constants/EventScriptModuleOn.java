package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_MODULE_ON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptModuleOn {
  private EventScriptModuleOn() {}

  public final static int ACQUIRE_ITEM = 3007;
  public final static int ACTIVATE_ITEM = 3006;
  public final static int CLIENT_ENTER = 3004;
  public final static int CLIENT_EXIT = 3005;
  public final static int EQUIP_ITEM = 3015;
  public final static int HEARTBEAT = 3000;
  public final static int LOSE_ITEM = 3008;
  public final static int MODULE_LOAD = 3002;
  public final static int MODULE_START = 3003;
  public final static int PLAYER_CANCEL_CUTSCENE = 3014;
  public final static int PLAYER_CHAT = 3017;
  public final static int PLAYER_DEATH = 3009;
  public final static int PLAYER_DYING = 3010;
  public final static int PLAYER_LEVEL_UP = 3013;
  public final static int PLAYER_REST = 3012;
  public final static int RESPAWN_BUTTON_PRESSED = 3011;
  public final static int UNEQUIP_ITEM = 3016;
  public final static int USER_DEFINED_EVENT = 3001;

  public static String nameOf(int value) {
    if (value == 3007) return "EventScriptModuleOn.ACQUIRE_ITEM";
    if (value == 3006) return "EventScriptModuleOn.ACTIVATE_ITEM";
    if (value == 3004) return "EventScriptModuleOn.CLIENT_ENTER";
    if (value == 3005) return "EventScriptModuleOn.CLIENT_EXIT";
    if (value == 3015) return "EventScriptModuleOn.EQUIP_ITEM";
    if (value == 3000) return "EventScriptModuleOn.HEARTBEAT";
    if (value == 3008) return "EventScriptModuleOn.LOSE_ITEM";
    if (value == 3002) return "EventScriptModuleOn.MODULE_LOAD";
    if (value == 3003) return "EventScriptModuleOn.MODULE_START";
    if (value == 3014) return "EventScriptModuleOn.PLAYER_CANCEL_CUTSCENE";
    if (value == 3017) return "EventScriptModuleOn.PLAYER_CHAT";
    if (value == 3009) return "EventScriptModuleOn.PLAYER_DEATH";
    if (value == 3010) return "EventScriptModuleOn.PLAYER_DYING";
    if (value == 3013) return "EventScriptModuleOn.PLAYER_LEVEL_UP";
    if (value == 3012) return "EventScriptModuleOn.PLAYER_REST";
    if (value == 3011) return "EventScriptModuleOn.RESPAWN_BUTTON_PRESSED";
    if (value == 3016) return "EventScriptModuleOn.UNEQUIP_ITEM";
    if (value == 3001) return "EventScriptModuleOn.USER_DEFINED_EVENT";
    return "EventScriptModuleOn.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptModuleOn.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptModuleOn.(not found: " + value + ")";
  }
}
