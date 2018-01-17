package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DAMAGE_POWER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class DamagePower {
  private DamagePower() {}

  public final static int ENERGY = 6;
  public final static int NORMAL = 0;
  public final static int PLUS_EIGHT = 9;
  public final static int PLUS_EIGHTEEN = 19;
  public final static int PLUS_ELEVEN = 12;
  public final static int PLUS_FIFTEEN = 16;
  public final static int PLUS_FIVE = 5;
  public final static int PLUS_FOUR = 4;
  public final static int PLUS_FOURTEEN = 15;
  public final static int PLUS_NINE = 10;
  public final static int PLUS_NINTEEN = 20;
  public final static int PLUS_ONE = 1;
  public final static int PLUS_SEVEN = 8;
  public final static int PLUS_SEVENTEEN = 18;
  public final static int PLUS_SIX = 7;
  public final static int PLUS_SIXTEEN = 17;
  public final static int PLUS_TEN = 11;
  public final static int PLUS_THIRTEEN = 14;
  public final static int PLUS_THREE = 3;
  public final static int PLUS_TWELVE = 13;
  public final static int PLUS_TWENTY = 21;
  public final static int PLUS_TWO = 2;

  public static String nameOf(int value) {
    if (value == 6) return "DamagePower.ENERGY";
    if (value == 0) return "DamagePower.NORMAL";
    if (value == 9) return "DamagePower.PLUS_EIGHT";
    if (value == 19) return "DamagePower.PLUS_EIGHTEEN";
    if (value == 12) return "DamagePower.PLUS_ELEVEN";
    if (value == 16) return "DamagePower.PLUS_FIFTEEN";
    if (value == 5) return "DamagePower.PLUS_FIVE";
    if (value == 4) return "DamagePower.PLUS_FOUR";
    if (value == 15) return "DamagePower.PLUS_FOURTEEN";
    if (value == 10) return "DamagePower.PLUS_NINE";
    if (value == 20) return "DamagePower.PLUS_NINTEEN";
    if (value == 1) return "DamagePower.PLUS_ONE";
    if (value == 8) return "DamagePower.PLUS_SEVEN";
    if (value == 18) return "DamagePower.PLUS_SEVENTEEN";
    if (value == 7) return "DamagePower.PLUS_SIX";
    if (value == 17) return "DamagePower.PLUS_SIXTEEN";
    if (value == 11) return "DamagePower.PLUS_TEN";
    if (value == 14) return "DamagePower.PLUS_THIRTEEN";
    if (value == 3) return "DamagePower.PLUS_THREE";
    if (value == 13) return "DamagePower.PLUS_TWELVE";
    if (value == 21) return "DamagePower.PLUS_TWENTY";
    if (value == 2) return "DamagePower.PLUS_TWO";
    return "DamagePower.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "DamagePower.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "DamagePower.(not found: " + value + ")";
  }
}
