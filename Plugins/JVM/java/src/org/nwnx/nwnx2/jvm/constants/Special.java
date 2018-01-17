package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPECIAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Special {
  private Special() {}

  public final static int ATTACK_CALLED_SHOT_ARM = 2;
  public final static int ATTACK_CALLED_SHOT_LEG = 1;
  public final static int ATTACK_DISARM = 4;
  public final static int ATTACK_FLURRY_OF_BLOWS = 9;
  public final static int ATTACK_IMPROVED_DISARM = 5;
  public final static int ATTACK_IMPROVED_KNOCKDOWN = 7;
  public final static int ATTACK_INVALID = 0;
  public final static int ATTACK_KNOCKDOWN = 6;
  public final static int ATTACK_RAPID_SHOT = 10;
  public final static int ATTACK_SAP = 3;
  public final static int ATTACK_STUNNING_FIST = 8;

  public static String nameOf(int value) {
    if (value == 2) return "Special.ATTACK_CALLED_SHOT_ARM";
    if (value == 1) return "Special.ATTACK_CALLED_SHOT_LEG";
    if (value == 4) return "Special.ATTACK_DISARM";
    if (value == 9) return "Special.ATTACK_FLURRY_OF_BLOWS";
    if (value == 5) return "Special.ATTACK_IMPROVED_DISARM";
    if (value == 7) return "Special.ATTACK_IMPROVED_KNOCKDOWN";
    if (value == 0) return "Special.ATTACK_INVALID";
    if (value == 6) return "Special.ATTACK_KNOCKDOWN";
    if (value == 10) return "Special.ATTACK_RAPID_SHOT";
    if (value == 3) return "Special.ATTACK_SAP";
    if (value == 8) return "Special.ATTACK_STUNNING_FIST";
    return "Special.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Special.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Special.(not found: " + value + ")";
  }
}
