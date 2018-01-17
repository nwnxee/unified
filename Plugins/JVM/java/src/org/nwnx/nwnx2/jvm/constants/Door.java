package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DOOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Door {
  private Door() {}

  public final static int ACTION_BASH = 2;
  public final static int ACTION_IGNORE = 3;
  public final static int ACTION_KNOCK = 4;
  public final static int ACTION_OPEN = 0;
  public final static int ACTION_UNLOCK = 1;

  public static String nameOf(int value) {
    if (value == 2) return "Door.ACTION_BASH";
    if (value == 3) return "Door.ACTION_IGNORE";
    if (value == 4) return "Door.ACTION_KNOCK";
    if (value == 0) return "Door.ACTION_OPEN";
    if (value == 1) return "Door.ACTION_UNLOCK";
    return "Door.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Door.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Door.(not found: " + value + ")";
  }
}
