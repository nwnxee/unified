package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_FEAT_PLAYER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstFeatPlayer {
  private IpConstFeatPlayer() {}

  public final static int TOOL_01 = 53;
  public final static int TOOL_02 = 54;
  public final static int TOOL_03 = 55;
  public final static int TOOL_04 = 56;
  public final static int TOOL_05 = 57;
  public final static int TOOL_06 = 58;
  public final static int TOOL_07 = 59;
  public final static int TOOL_08 = 60;
  public final static int TOOL_09 = 61;
  public final static int TOOL_10 = 62;

  public static String nameOf(int value) {
    if (value == 53) return "IpConstFeatPlayer.TOOL_01";
    if (value == 54) return "IpConstFeatPlayer.TOOL_02";
    if (value == 55) return "IpConstFeatPlayer.TOOL_03";
    if (value == 56) return "IpConstFeatPlayer.TOOL_04";
    if (value == 57) return "IpConstFeatPlayer.TOOL_05";
    if (value == 58) return "IpConstFeatPlayer.TOOL_06";
    if (value == 59) return "IpConstFeatPlayer.TOOL_07";
    if (value == 60) return "IpConstFeatPlayer.TOOL_08";
    if (value == 61) return "IpConstFeatPlayer.TOOL_09";
    if (value == 62) return "IpConstFeatPlayer.TOOL_10";
    return "IpConstFeatPlayer.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstFeatPlayer.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstFeatPlayer.(not found: " + value + ")";
  }
}
