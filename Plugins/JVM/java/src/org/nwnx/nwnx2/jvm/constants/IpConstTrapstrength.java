package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_TRAPSTRENGTH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstTrapstrength {
  private IpConstTrapstrength() {}

  public final static int AVERAGE = 1;
  public final static int DEADLY = 3;
  public final static int MINOR = 0;
  public final static int STRONG = 2;

  public static String nameOf(int value) {
    if (value == 1) return "IpConstTrapstrength.AVERAGE";
    if (value == 3) return "IpConstTrapstrength.DEADLY";
    if (value == 0) return "IpConstTrapstrength.MINOR";
    if (value == 2) return "IpConstTrapstrength.STRONG";
    return "IpConstTrapstrength.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstTrapstrength.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstTrapstrength.(not found: " + value + ")";
  }
}
