package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PDK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPdk {
  private FeatPdk() {}

  public final static int FEAR = 1082;
  public final static int INSPIRE_1 = 1085;
  public final static int INSPIRE_2 = 1086;
  public final static int RALLY = 1080;
  public final static int SHIELD = 1081;
  public final static int STAND = 1084;
  public final static int WRATH = 1083;

  public static String nameOf(int value) {
    if (value == 1082) return "FeatPdk.FEAR";
    if (value == 1085) return "FeatPdk.INSPIRE_1";
    if (value == 1086) return "FeatPdk.INSPIRE_2";
    if (value == 1080) return "FeatPdk.RALLY";
    if (value == 1081) return "FeatPdk.SHIELD";
    if (value == 1084) return "FeatPdk.STAND";
    if (value == 1083) return "FeatPdk.WRATH";
    return "FeatPdk.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPdk.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPdk.(not found: " + value + ")";
  }
}
