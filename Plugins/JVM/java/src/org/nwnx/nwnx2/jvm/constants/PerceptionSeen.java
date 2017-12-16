package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PERCEPTION_SEEN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class PerceptionSeen {
  private PerceptionSeen() {}

  public final static int AND_HEARD = 0;
  public final static int AND_NOT_HEARD = 3;
  public final static int PERCEPTION_SEEN = 7;

  public static String nameOf(int value) {
    if (value == 0) return "PerceptionSeen.AND_HEARD";
    if (value == 3) return "PerceptionSeen.AND_NOT_HEARD";
    if (value == 7) return "PerceptionSeen.PERCEPTION_SEEN";
    return "PerceptionSeen.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "PerceptionSeen.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "PerceptionSeen.(not found: " + value + ")";
  }
}
