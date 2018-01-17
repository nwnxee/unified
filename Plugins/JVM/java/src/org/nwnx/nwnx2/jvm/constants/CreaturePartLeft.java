package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_PART_LEFT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreaturePartLeft {
  private CreaturePartLeft() {}

  public final static int BICEP = 13;
  public final static int FOOT = 1;
  public final static int FOREARM = 11;
  public final static int HAND = 17;
  public final static int SHIN = 3;
  public final static int SHOULDER = 15;
  public final static int THIGH = 4;

  public static String nameOf(int value) {
    if (value == 13) return "CreaturePartLeft.BICEP";
    if (value == 1) return "CreaturePartLeft.FOOT";
    if (value == 11) return "CreaturePartLeft.FOREARM";
    if (value == 17) return "CreaturePartLeft.HAND";
    if (value == 3) return "CreaturePartLeft.SHIN";
    if (value == 15) return "CreaturePartLeft.SHOULDER";
    if (value == 4) return "CreaturePartLeft.THIGH";
    return "CreaturePartLeft.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreaturePartLeft.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreaturePartLeft.(not found: " + value + ")";
  }
}
