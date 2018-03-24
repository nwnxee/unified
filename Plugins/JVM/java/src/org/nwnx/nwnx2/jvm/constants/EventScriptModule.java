package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EVENT_SCRIPT_MODULE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EventScriptModule {
  private EventScriptModule() {}

  public final static int ON_ACQUIRE_ITEM = 3007;
  public final static int ON_ACTIVATE_ITEM = 3006;
  public final static int ON_CLIENT_ENTER = 3004;
  public final static int ON_CLIENT_EXIT = 3005;
  public final static int ON_EQUIP_ITEM = 3015;
  public final static int ON_HEARTBEAT = 3000;
  public final static int ON_LOSE_ITEM = 3008;
  public final static int ON_MODULE_LOAD = 3002;
  public final static int ON_MODULE_START = 3003;
  public final static int ON_PLAYER_CANCEL_CUTSCENE = 3014;
  public final static int ON_PLAYER_CHAT = 3017;
  public final static int ON_PLAYER_DEATH = 3009;
  public final static int ON_PLAYER_DYING = 3010;
  public final static int ON_PLAYER_LEVEL_UP = 3013;
  public final static int ON_PLAYER_REST = 3012;
  public final static int ON_RESPAWN_BUTTON_PRESSED = 3011;
  public final static int ON_UNEQUIP_ITEM = 3016;
  public final static int ON_USER_DEFINED_EVENT = 3001;

  public static String nameOf(int value) {
    if (value == 3007) return "EventScriptModule.ON_ACQUIRE_ITEM";
    if (value == 3006) return "EventScriptModule.ON_ACTIVATE_ITEM";
    if (value == 3004) return "EventScriptModule.ON_CLIENT_ENTER";
    if (value == 3005) return "EventScriptModule.ON_CLIENT_EXIT";
    if (value == 3015) return "EventScriptModule.ON_EQUIP_ITEM";
    if (value == 3000) return "EventScriptModule.ON_HEARTBEAT";
    if (value == 3008) return "EventScriptModule.ON_LOSE_ITEM";
    if (value == 3002) return "EventScriptModule.ON_MODULE_LOAD";
    if (value == 3003) return "EventScriptModule.ON_MODULE_START";
    if (value == 3014) return "EventScriptModule.ON_PLAYER_CANCEL_CUTSCENE";
    if (value == 3017) return "EventScriptModule.ON_PLAYER_CHAT";
    if (value == 3009) return "EventScriptModule.ON_PLAYER_DEATH";
    if (value == 3010) return "EventScriptModule.ON_PLAYER_DYING";
    if (value == 3013) return "EventScriptModule.ON_PLAYER_LEVEL_UP";
    if (value == 3012) return "EventScriptModule.ON_PLAYER_REST";
    if (value == 3011) return "EventScriptModule.ON_RESPAWN_BUTTON_PRESSED";
    if (value == 3016) return "EventScriptModule.ON_UNEQUIP_ITEM";
    if (value == 3001) return "EventScriptModule.ON_USER_DEFINED_EVENT";
    return "EventScriptModule.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EventScriptModule.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EventScriptModule.(not found: " + value + ")";
  }
}
