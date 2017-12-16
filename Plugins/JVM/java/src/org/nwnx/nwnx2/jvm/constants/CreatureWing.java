package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_WING".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreatureWing {
  private CreatureWing() {}

  public final static int TYPE_ANGEL = 2;
  public final static int TYPE_BAT = 3;
  public final static int TYPE_BIRD = 6;
  public final static int TYPE_BUTTERFLY = 5;
  public final static int TYPE_DEMON = 1;
  public final static int TYPE_DRAGON = 4;
  public final static int TYPE_NONE = 0;

  public static String nameOf(int value) {
    if (value == 2) return "CreatureWing.TYPE_ANGEL";
    if (value == 3) return "CreatureWing.TYPE_BAT";
    if (value == 6) return "CreatureWing.TYPE_BIRD";
    if (value == 5) return "CreatureWing.TYPE_BUTTERFLY";
    if (value == 1) return "CreatureWing.TYPE_DEMON";
    if (value == 4) return "CreatureWing.TYPE_DRAGON";
    if (value == 0) return "CreatureWing.TYPE_NONE";
    return "CreatureWing.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreatureWing.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreatureWing.(not found: " + value + ")";
  }
}
