package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_PART_RIGHT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreaturePartRight {
  private CreaturePartRight() {}

  public final static int BICEP = 12;
  public final static int FOOT = 0;
  public final static int FOREARM = 10;
  public final static int HAND = 16;
  public final static int SHIN = 2;
  public final static int SHOULDER = 14;
  public final static int THIGH = 5;

  public static String nameOf(int value) {
    if (value == 12) return "CreaturePartRight.BICEP";
    if (value == 0) return "CreaturePartRight.FOOT";
    if (value == 10) return "CreaturePartRight.FOREARM";
    if (value == 16) return "CreaturePartRight.HAND";
    if (value == 2) return "CreaturePartRight.SHIN";
    if (value == 14) return "CreaturePartRight.SHOULDER";
    if (value == 5) return "CreaturePartRight.THIGH";
    return "CreaturePartRight.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreaturePartRight.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreaturePartRight.(not found: " + value + ")";
  }
}
