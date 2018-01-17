package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_CLASS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstClass {
  private IpConstClass() {}

  public final static int BARBARIAN = 0;
  public final static int BARD = 1;
  public final static int CLERIC = 2;
  public final static int DRUID = 3;
  public final static int FIGHTER = 4;
  public final static int MONK = 5;
  public final static int PALADIN = 6;
  public final static int RANGER = 7;
  public final static int ROGUE = 8;
  public final static int SORCERER = 9;
  public final static int WIZARD = 10;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstClass.BARBARIAN";
    if (value == 1) return "IpConstClass.BARD";
    if (value == 2) return "IpConstClass.CLERIC";
    if (value == 3) return "IpConstClass.DRUID";
    if (value == 4) return "IpConstClass.FIGHTER";
    if (value == 5) return "IpConstClass.MONK";
    if (value == 6) return "IpConstClass.PALADIN";
    if (value == 7) return "IpConstClass.RANGER";
    if (value == 8) return "IpConstClass.ROGUE";
    if (value == 9) return "IpConstClass.SORCERER";
    if (value == 10) return "IpConstClass.WIZARD";
    return "IpConstClass.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstClass.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstClass.(not found: " + value + ")";
  }
}
