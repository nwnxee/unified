package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPECIAL_ATTACK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpecialAttack {
  private SpecialAttack() {}

  public final static int CALLED_SHOT_ARM = 2;
  public final static int CALLED_SHOT_LEG = 1;
  public final static int DISARM = 4;
  public final static int FLURRY_OF_BLOWS = 9;
  public final static int IMPROVED_DISARM = 5;
  public final static int IMPROVED_KNOCKDOWN = 7;
  public final static int INVALID = 0;
  public final static int KNOCKDOWN = 6;
  public final static int RAPID_SHOT = 10;
  public final static int SAP = 3;
  public final static int STUNNING_FIST = 8;

  public static String nameOf(int value) {
    if (value == 2) return "SpecialAttack.CALLED_SHOT_ARM";
    if (value == 1) return "SpecialAttack.CALLED_SHOT_LEG";
    if (value == 4) return "SpecialAttack.DISARM";
    if (value == 9) return "SpecialAttack.FLURRY_OF_BLOWS";
    if (value == 5) return "SpecialAttack.IMPROVED_DISARM";
    if (value == 7) return "SpecialAttack.IMPROVED_KNOCKDOWN";
    if (value == 0) return "SpecialAttack.INVALID";
    if (value == 6) return "SpecialAttack.KNOCKDOWN";
    if (value == 10) return "SpecialAttack.RAPID_SHOT";
    if (value == 3) return "SpecialAttack.SAP";
    if (value == 8) return "SpecialAttack.STUNNING_FIST";
    return "SpecialAttack.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpecialAttack.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpecialAttack.(not found: " + value + ")";
  }
}
