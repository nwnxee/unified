package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "PERCEPTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Perception {
  private Perception() {}

  public final static int HEARD = 5;
  public final static int HEARD_AND_NOT_SEEN = 2;
  public final static int NOT_HEARD = 4;
  public final static int NOT_SEEN = 6;
  public final static int NOT_SEEN_AND_NOT_HEARD = 1;
  public final static int SEEN = 7;
  public final static int SEEN_AND_HEARD = 0;
  public final static int SEEN_AND_NOT_HEARD = 3;

  public static String nameOf(int value) {
    if (value == 5) return "Perception.HEARD";
    if (value == 2) return "Perception.HEARD_AND_NOT_SEEN";
    if (value == 4) return "Perception.NOT_HEARD";
    if (value == 6) return "Perception.NOT_SEEN";
    if (value == 1) return "Perception.NOT_SEEN_AND_NOT_HEARD";
    if (value == 7) return "Perception.SEEN";
    if (value == 0) return "Perception.SEEN_AND_HEARD";
    if (value == 3) return "Perception.SEEN_AND_NOT_HEARD";
    return "Perception.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Perception.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Perception.(not found: " + value + ")";
  }
}
