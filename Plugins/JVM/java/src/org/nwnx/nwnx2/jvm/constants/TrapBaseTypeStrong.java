package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE_STRONG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseTypeStrong {
  private TrapBaseTypeStrong() {}

  public final static int ACID = 14;
  public final static int ACID_SPLASH = 42;
  public final static int ELECTRICAL = 22;
  public final static int FIRE = 18;
  public final static int FROST = 30;
  public final static int GAS = 26;
  public final static int HOLY = 6;
  public final static int NEGATIVE = 34;
  public final static int SONIC = 38;
  public final static int SPIKE = 2;
  public final static int TANGLE = 10;

  public static String nameOf(int value) {
    if (value == 14) return "TrapBaseTypeStrong.ACID";
    if (value == 42) return "TrapBaseTypeStrong.ACID_SPLASH";
    if (value == 22) return "TrapBaseTypeStrong.ELECTRICAL";
    if (value == 18) return "TrapBaseTypeStrong.FIRE";
    if (value == 30) return "TrapBaseTypeStrong.FROST";
    if (value == 26) return "TrapBaseTypeStrong.GAS";
    if (value == 6) return "TrapBaseTypeStrong.HOLY";
    if (value == 34) return "TrapBaseTypeStrong.NEGATIVE";
    if (value == 38) return "TrapBaseTypeStrong.SONIC";
    if (value == 2) return "TrapBaseTypeStrong.SPIKE";
    if (value == 10) return "TrapBaseTypeStrong.TANGLE";
    return "TrapBaseTypeStrong.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseTypeStrong.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseTypeStrong.(not found: " + value + ")";
  }
}
