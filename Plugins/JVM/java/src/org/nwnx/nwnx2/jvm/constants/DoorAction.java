package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DOOR_ACTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class DoorAction {
  private DoorAction() {}

  public final static int BASH = 2;
  public final static int IGNORE = 3;
  public final static int KNOCK = 4;
  public final static int OPEN = 0;
  public final static int UNLOCK = 1;

  public static String nameOf(int value) {
    if (value == 2) return "DoorAction.BASH";
    if (value == 3) return "DoorAction.IGNORE";
    if (value == 4) return "DoorAction.KNOCK";
    if (value == 0) return "DoorAction.OPEN";
    if (value == 1) return "DoorAction.UNLOCK";
    return "DoorAction.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "DoorAction.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "DoorAction.(not found: " + value + ")";
  }
}
