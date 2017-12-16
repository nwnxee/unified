package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ACTION_MODE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ActionMode {
  private ActionMode() {}

  public final static int COUNTERSPELL = 5;
  public final static int DEFENSIVE_CAST = 10;
  public final static int DETECT = 0;
  public final static int DIRTY_FIGHTING = 11;
  public final static int EXPERTISE = 8;
  public final static int FLURRY_OF_BLOWS = 6;
  public final static int IMPROVED_EXPERTISE = 9;
  public final static int IMPROVED_POWER_ATTACK = 4;
  public final static int PARRY = 2;
  public final static int POWER_ATTACK = 3;
  public final static int RAPID_SHOT = 7;
  public final static int STEALTH = 1;

  public static String nameOf(int value) {
    if (value == 5) return "ActionMode.COUNTERSPELL";
    if (value == 10) return "ActionMode.DEFENSIVE_CAST";
    if (value == 0) return "ActionMode.DETECT";
    if (value == 11) return "ActionMode.DIRTY_FIGHTING";
    if (value == 8) return "ActionMode.EXPERTISE";
    if (value == 6) return "ActionMode.FLURRY_OF_BLOWS";
    if (value == 9) return "ActionMode.IMPROVED_EXPERTISE";
    if (value == 4) return "ActionMode.IMPROVED_POWER_ATTACK";
    if (value == 2) return "ActionMode.PARRY";
    if (value == 3) return "ActionMode.POWER_ATTACK";
    if (value == 7) return "ActionMode.RAPID_SHOT";
    if (value == 1) return "ActionMode.STEALTH";
    return "ActionMode.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ActionMode.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ActionMode.(not found: " + value + ")";
  }
}
