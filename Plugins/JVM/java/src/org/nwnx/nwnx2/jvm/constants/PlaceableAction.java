package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PLACEABLE_ACTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PlaceableAction {
  private PlaceableAction() {}

  public final static int BASH = 2;
  public final static int KNOCK = 4;
  public final static int UNLOCK = 1;
  public final static int USE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "PlaceableAction.BASH";
    if (value == 4) return "PlaceableAction.KNOCK";
    if (value == 1) return "PlaceableAction.UNLOCK";
    if (value == 0) return "PlaceableAction.USE";
    return "PlaceableAction.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PlaceableAction.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PlaceableAction.(not found: " + value + ")";
  }
}
