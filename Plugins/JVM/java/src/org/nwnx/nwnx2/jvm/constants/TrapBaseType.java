package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "TRAP_BASE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class TrapBaseType {
  private TrapBaseType() {}

  public final static int AVERAGE_ACID = 13;
  public final static int AVERAGE_ACID_SPLASH = 41;
  public final static int AVERAGE_ELECTRICAL = 21;
  public final static int AVERAGE_FIRE = 17;
  public final static int AVERAGE_FROST = 29;
  public final static int AVERAGE_GAS = 25;
  public final static int AVERAGE_HOLY = 5;
  public final static int AVERAGE_NEGATIVE = 33;
  public final static int AVERAGE_SONIC = 37;
  public final static int AVERAGE_SPIKE = 1;
  public final static int AVERAGE_TANGLE = 9;
  public final static int DEADLY_ACID = 15;
  public final static int DEADLY_ACID_SPLASH = 43;
  public final static int DEADLY_ELECTRICAL = 23;
  public final static int DEADLY_FIRE = 19;
  public final static int DEADLY_FROST = 31;
  public final static int DEADLY_GAS = 27;
  public final static int DEADLY_HOLY = 7;
  public final static int DEADLY_NEGATIVE = 35;
  public final static int DEADLY_SONIC = 39;
  public final static int DEADLY_SPIKE = 3;
  public final static int DEADLY_TANGLE = 11;
  public final static int EPIC_ELECTRICAL = 44;
  public final static int EPIC_FIRE = 45;
  public final static int EPIC_FROST = 46;
  public final static int EPIC_SONIC = 47;
  public final static int MINOR_ACID = 12;
  public final static int MINOR_ACID_SPLASH = 40;
  public final static int MINOR_ELECTRICAL = 20;
  public final static int MINOR_FIRE = 16;
  public final static int MINOR_FROST = 28;
  public final static int MINOR_GAS = 24;
  public final static int MINOR_HOLY = 4;
  public final static int MINOR_NEGATIVE = 32;
  public final static int MINOR_SONIC = 36;
  public final static int MINOR_SPIKE = 0;
  public final static int MINOR_TANGLE = 8;
  public final static int STRONG_ACID = 14;
  public final static int STRONG_ACID_SPLASH = 42;
  public final static int STRONG_ELECTRICAL = 22;
  public final static int STRONG_FIRE = 18;
  public final static int STRONG_FROST = 30;
  public final static int STRONG_GAS = 26;
  public final static int STRONG_HOLY = 6;
  public final static int STRONG_NEGATIVE = 34;
  public final static int STRONG_SONIC = 38;
  public final static int STRONG_SPIKE = 2;
  public final static int STRONG_TANGLE = 10;

  public static String nameOf(int value) {
    if (value == 13) return "TrapBaseType.AVERAGE_ACID";
    if (value == 41) return "TrapBaseType.AVERAGE_ACID_SPLASH";
    if (value == 21) return "TrapBaseType.AVERAGE_ELECTRICAL";
    if (value == 17) return "TrapBaseType.AVERAGE_FIRE";
    if (value == 29) return "TrapBaseType.AVERAGE_FROST";
    if (value == 25) return "TrapBaseType.AVERAGE_GAS";
    if (value == 5) return "TrapBaseType.AVERAGE_HOLY";
    if (value == 33) return "TrapBaseType.AVERAGE_NEGATIVE";
    if (value == 37) return "TrapBaseType.AVERAGE_SONIC";
    if (value == 1) return "TrapBaseType.AVERAGE_SPIKE";
    if (value == 9) return "TrapBaseType.AVERAGE_TANGLE";
    if (value == 15) return "TrapBaseType.DEADLY_ACID";
    if (value == 43) return "TrapBaseType.DEADLY_ACID_SPLASH";
    if (value == 23) return "TrapBaseType.DEADLY_ELECTRICAL";
    if (value == 19) return "TrapBaseType.DEADLY_FIRE";
    if (value == 31) return "TrapBaseType.DEADLY_FROST";
    if (value == 27) return "TrapBaseType.DEADLY_GAS";
    if (value == 7) return "TrapBaseType.DEADLY_HOLY";
    if (value == 35) return "TrapBaseType.DEADLY_NEGATIVE";
    if (value == 39) return "TrapBaseType.DEADLY_SONIC";
    if (value == 3) return "TrapBaseType.DEADLY_SPIKE";
    if (value == 11) return "TrapBaseType.DEADLY_TANGLE";
    if (value == 44) return "TrapBaseType.EPIC_ELECTRICAL";
    if (value == 45) return "TrapBaseType.EPIC_FIRE";
    if (value == 46) return "TrapBaseType.EPIC_FROST";
    if (value == 47) return "TrapBaseType.EPIC_SONIC";
    if (value == 12) return "TrapBaseType.MINOR_ACID";
    if (value == 40) return "TrapBaseType.MINOR_ACID_SPLASH";
    if (value == 20) return "TrapBaseType.MINOR_ELECTRICAL";
    if (value == 16) return "TrapBaseType.MINOR_FIRE";
    if (value == 28) return "TrapBaseType.MINOR_FROST";
    if (value == 24) return "TrapBaseType.MINOR_GAS";
    if (value == 4) return "TrapBaseType.MINOR_HOLY";
    if (value == 32) return "TrapBaseType.MINOR_NEGATIVE";
    if (value == 36) return "TrapBaseType.MINOR_SONIC";
    if (value == 0) return "TrapBaseType.MINOR_SPIKE";
    if (value == 8) return "TrapBaseType.MINOR_TANGLE";
    if (value == 14) return "TrapBaseType.STRONG_ACID";
    if (value == 42) return "TrapBaseType.STRONG_ACID_SPLASH";
    if (value == 22) return "TrapBaseType.STRONG_ELECTRICAL";
    if (value == 18) return "TrapBaseType.STRONG_FIRE";
    if (value == 30) return "TrapBaseType.STRONG_FROST";
    if (value == 26) return "TrapBaseType.STRONG_GAS";
    if (value == 6) return "TrapBaseType.STRONG_HOLY";
    if (value == 34) return "TrapBaseType.STRONG_NEGATIVE";
    if (value == 38) return "TrapBaseType.STRONG_SONIC";
    if (value == 2) return "TrapBaseType.STRONG_SPIKE";
    if (value == 10) return "TrapBaseType.STRONG_TANGLE";
    return "TrapBaseType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "TrapBaseType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "TrapBaseType.(not found: " + value + ")";
  }
}
