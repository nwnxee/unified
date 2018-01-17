package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE_DEADLY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseTypeDeadly {
  private TrapBaseTypeDeadly() {}

  public final static int ACID = 15;
  public final static int ACID_SPLASH = 43;
  public final static int ELECTRICAL = 23;
  public final static int FIRE = 19;
  public final static int FROST = 31;
  public final static int GAS = 27;
  public final static int HOLY = 7;
  public final static int NEGATIVE = 35;
  public final static int SONIC = 39;
  public final static int SPIKE = 3;
  public final static int TANGLE = 11;

  public static String nameOf(int value) {
    if (value == 15) return "TrapBaseTypeDeadly.ACID";
    if (value == 43) return "TrapBaseTypeDeadly.ACID_SPLASH";
    if (value == 23) return "TrapBaseTypeDeadly.ELECTRICAL";
    if (value == 19) return "TrapBaseTypeDeadly.FIRE";
    if (value == 31) return "TrapBaseTypeDeadly.FROST";
    if (value == 27) return "TrapBaseTypeDeadly.GAS";
    if (value == 7) return "TrapBaseTypeDeadly.HOLY";
    if (value == 35) return "TrapBaseTypeDeadly.NEGATIVE";
    if (value == 39) return "TrapBaseTypeDeadly.SONIC";
    if (value == 3) return "TrapBaseTypeDeadly.SPIKE";
    if (value == 11) return "TrapBaseTypeDeadly.TANGLE";
    return "TrapBaseTypeDeadly.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseTypeDeadly.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseTypeDeadly.(not found: " + value + ")";
  }
}
