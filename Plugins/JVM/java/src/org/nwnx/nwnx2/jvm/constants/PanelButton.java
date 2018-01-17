package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PANEL_BUTTON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PanelButton {
  private PanelButton() {}

  public final static int CHARACTER = 3;
  public final static int INVENTORY = 1;
  public final static int JOURNAL = 2;
  public final static int MAP = 0;
  public final static int OPTIONS = 4;
  public final static int PLAYER_VERSUS_PLAYER = 7;
  public final static int REST = 6;
  public final static int SPELLS = 5;

  public static String nameOf(int value) {
    if (value == 3) return "PanelButton.CHARACTER";
    if (value == 1) return "PanelButton.INVENTORY";
    if (value == 2) return "PanelButton.JOURNAL";
    if (value == 0) return "PanelButton.MAP";
    if (value == 4) return "PanelButton.OPTIONS";
    if (value == 7) return "PanelButton.PLAYER_VERSUS_PLAYER";
    if (value == 6) return "PanelButton.REST";
    if (value == 5) return "PanelButton.SPELLS";
    return "PanelButton.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PanelButton.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PanelButton.(not found: " + value + ")";
  }
}
