package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_WING_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureWingType {
  private CreatureWingType() {}

  public final static int ANGEL = 2;
  public final static int BAT = 3;
  public final static int BIRD = 6;
  public final static int BUTTERFLY = 5;
  public final static int DEMON = 1;
  public final static int DRAGON = 4;
  public final static int NONE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "CreatureWingType.ANGEL";
    if (value == 3) return "CreatureWingType.BAT";
    if (value == 6) return "CreatureWingType.BIRD";
    if (value == 5) return "CreatureWingType.BUTTERFLY";
    if (value == 1) return "CreatureWingType.DEMON";
    if (value == 4) return "CreatureWingType.DRAGON";
    if (value == 0) return "CreatureWingType.NONE";
    return "CreatureWingType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureWingType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureWingType.(not found: " + value + ")";
  }
}
