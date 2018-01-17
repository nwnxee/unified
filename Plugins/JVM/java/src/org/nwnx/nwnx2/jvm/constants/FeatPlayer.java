package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PLAYER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPlayer {
  private FeatPlayer() {}

  public final static int TOOL_01 = 1106;
  public final static int TOOL_02 = 1107;
  public final static int TOOL_03 = 1108;
  public final static int TOOL_04 = 1109;
  public final static int TOOL_05 = 1110;
  public final static int TOOL_06 = 1111;
  public final static int TOOL_07 = 1112;
  public final static int TOOL_08 = 1113;
  public final static int TOOL_09 = 1114;
  public final static int TOOL_10 = 1115;

  public static String nameOf(int value) {
    if (value == 1106) return "FeatPlayer.TOOL_01";
    if (value == 1107) return "FeatPlayer.TOOL_02";
    if (value == 1108) return "FeatPlayer.TOOL_03";
    if (value == 1109) return "FeatPlayer.TOOL_04";
    if (value == 1110) return "FeatPlayer.TOOL_05";
    if (value == 1111) return "FeatPlayer.TOOL_06";
    if (value == 1112) return "FeatPlayer.TOOL_07";
    if (value == 1113) return "FeatPlayer.TOOL_08";
    if (value == 1114) return "FeatPlayer.TOOL_09";
    if (value == 1115) return "FeatPlayer.TOOL_10";
    return "FeatPlayer.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPlayer.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPlayer.(not found: " + value + ")";
  }
}
