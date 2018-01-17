package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE_AVERAGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseTypeAverage {
  private TrapBaseTypeAverage() {}

  public final static int ACID = 13;
  public final static int ACID_SPLASH = 41;
  public final static int ELECTRICAL = 21;
  public final static int FIRE = 17;
  public final static int FROST = 29;
  public final static int GAS = 25;
  public final static int HOLY = 5;
  public final static int NEGATIVE = 33;
  public final static int SONIC = 37;
  public final static int SPIKE = 1;
  public final static int TANGLE = 9;

  public static String nameOf(int value) {
    if (value == 13) return "TrapBaseTypeAverage.ACID";
    if (value == 41) return "TrapBaseTypeAverage.ACID_SPLASH";
    if (value == 21) return "TrapBaseTypeAverage.ELECTRICAL";
    if (value == 17) return "TrapBaseTypeAverage.FIRE";
    if (value == 29) return "TrapBaseTypeAverage.FROST";
    if (value == 25) return "TrapBaseTypeAverage.GAS";
    if (value == 5) return "TrapBaseTypeAverage.HOLY";
    if (value == 33) return "TrapBaseTypeAverage.NEGATIVE";
    if (value == 37) return "TrapBaseTypeAverage.SONIC";
    if (value == 1) return "TrapBaseTypeAverage.SPIKE";
    if (value == 9) return "TrapBaseTypeAverage.TANGLE";
    return "TrapBaseTypeAverage.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseTypeAverage.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseTypeAverage.(not found: " + value + ")";
  }
}
