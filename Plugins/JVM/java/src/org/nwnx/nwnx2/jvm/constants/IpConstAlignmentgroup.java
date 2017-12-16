package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_ALIGNMENTGROUP".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstAlignmentgroup {
  private IpConstAlignmentgroup() {}

  public final static int ALL = 0;
  public final static int CHAOTIC = 3;
  public final static int EVIL = 5;
  public final static int GOOD = 4;
  public final static int LAWFUL = 2;
  public final static int NEUTRAL = 1;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstAlignmentgroup.ALL";
    if (value == 3) return "IpConstAlignmentgroup.CHAOTIC";
    if (value == 5) return "IpConstAlignmentgroup.EVIL";
    if (value == 4) return "IpConstAlignmentgroup.GOOD";
    if (value == 2) return "IpConstAlignmentgroup.LAWFUL";
    if (value == 1) return "IpConstAlignmentgroup.NEUTRAL";
    return "IpConstAlignmentgroup.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstAlignmentgroup.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstAlignmentgroup.(not found: " + value + ")";
  }
}
