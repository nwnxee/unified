package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE_MINOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseTypeMinor {
  private TrapBaseTypeMinor() {}

  public final static int ACID = 12;
  public final static int ACID_SPLASH = 40;
  public final static int ELECTRICAL = 20;
  public final static int FIRE = 16;
  public final static int FROST = 28;
  public final static int GAS = 24;
  public final static int HOLY = 4;
  public final static int NEGATIVE = 32;
  public final static int SONIC = 36;
  public final static int SPIKE = 0;
  public final static int TANGLE = 8;

  public static String nameOf(int value) {
    if (value == 12) return "TrapBaseTypeMinor.ACID";
    if (value == 40) return "TrapBaseTypeMinor.ACID_SPLASH";
    if (value == 20) return "TrapBaseTypeMinor.ELECTRICAL";
    if (value == 16) return "TrapBaseTypeMinor.FIRE";
    if (value == 28) return "TrapBaseTypeMinor.FROST";
    if (value == 24) return "TrapBaseTypeMinor.GAS";
    if (value == 4) return "TrapBaseTypeMinor.HOLY";
    if (value == 32) return "TrapBaseTypeMinor.NEGATIVE";
    if (value == 36) return "TrapBaseTypeMinor.SONIC";
    if (value == 0) return "TrapBaseTypeMinor.SPIKE";
    if (value == 8) return "TrapBaseTypeMinor.TANGLE";
    return "TrapBaseTypeMinor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseTypeMinor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseTypeMinor.(not found: " + value + ")";
  }
}
