package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PLACEABLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Placeable {
  private Placeable() {}

  public final static int ACTION_BASH = 2;
  public final static int ACTION_KNOCK = 4;
  public final static int ACTION_UNLOCK = 1;
  public final static int ACTION_USE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "Placeable.ACTION_BASH";
    if (value == 4) return "Placeable.ACTION_KNOCK";
    if (value == 1) return "Placeable.ACTION_UNLOCK";
    if (value == 0) return "Placeable.ACTION_USE";
    return "Placeable.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Placeable.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Placeable.(not found: " + value + ")";
  }
}
