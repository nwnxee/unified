package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "CREATURE_PART".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class CreaturePart {
  private CreaturePart() {}

  public final static int BELT = 8;
  public final static int HEAD = 20;
  public final static int LEFT_BICEP = 13;
  public final static int LEFT_FOOT = 1;
  public final static int LEFT_FOREARM = 11;
  public final static int LEFT_HAND = 17;
  public final static int LEFT_SHIN = 3;
  public final static int LEFT_SHOULDER = 15;
  public final static int LEFT_THIGH = 4;
  public final static int NECK = 9;
  public final static int PELVIS = 6;
  public final static int RIGHT_BICEP = 12;
  public final static int RIGHT_FOOT = 0;
  public final static int RIGHT_FOREARM = 10;
  public final static int RIGHT_HAND = 16;
  public final static int RIGHT_SHIN = 2;
  public final static int RIGHT_SHOULDER = 14;
  public final static int RIGHT_THIGH = 5;
  public final static int TORSO = 7;

  public static String nameOf(int value) {
    if (value == 8) return "CreaturePart.BELT";
    if (value == 20) return "CreaturePart.HEAD";
    if (value == 13) return "CreaturePart.LEFT_BICEP";
    if (value == 1) return "CreaturePart.LEFT_FOOT";
    if (value == 11) return "CreaturePart.LEFT_FOREARM";
    if (value == 17) return "CreaturePart.LEFT_HAND";
    if (value == 3) return "CreaturePart.LEFT_SHIN";
    if (value == 15) return "CreaturePart.LEFT_SHOULDER";
    if (value == 4) return "CreaturePart.LEFT_THIGH";
    if (value == 9) return "CreaturePart.NECK";
    if (value == 6) return "CreaturePart.PELVIS";
    if (value == 12) return "CreaturePart.RIGHT_BICEP";
    if (value == 0) return "CreaturePart.RIGHT_FOOT";
    if (value == 10) return "CreaturePart.RIGHT_FOREARM";
    if (value == 16) return "CreaturePart.RIGHT_HAND";
    if (value == 2) return "CreaturePart.RIGHT_SHIN";
    if (value == 14) return "CreaturePart.RIGHT_SHOULDER";
    if (value == 5) return "CreaturePart.RIGHT_THIGH";
    if (value == 7) return "CreaturePart.TORSO";
    return "CreaturePart.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "CreaturePart.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "CreaturePart.(not found: " + value + ")";
  }
}
