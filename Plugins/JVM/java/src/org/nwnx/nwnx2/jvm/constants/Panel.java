package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PANEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Panel {
  private Panel() {}

  public final static int BUTTON_CHARACTER = 3;
  public final static int BUTTON_INVENTORY = 1;
  public final static int BUTTON_JOURNAL = 2;
  public final static int BUTTON_MAP = 0;
  public final static int BUTTON_OPTIONS = 4;
  public final static int BUTTON_PLAYER_VERSUS_PLAYER = 7;
  public final static int BUTTON_REST = 6;
  public final static int BUTTON_SPELLS = 5;

  public static String nameOf(int value) {
    if (value == 3) return "Panel.BUTTON_CHARACTER";
    if (value == 1) return "Panel.BUTTON_INVENTORY";
    if (value == 2) return "Panel.BUTTON_JOURNAL";
    if (value == 0) return "Panel.BUTTON_MAP";
    if (value == 4) return "Panel.BUTTON_OPTIONS";
    if (value == 7) return "Panel.BUTTON_PLAYER_VERSUS_PLAYER";
    if (value == 6) return "Panel.BUTTON_REST";
    if (value == 5) return "Panel.BUTTON_SPELLS";
    return "Panel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Panel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Panel.(not found: " + value + ")";
  }
}
