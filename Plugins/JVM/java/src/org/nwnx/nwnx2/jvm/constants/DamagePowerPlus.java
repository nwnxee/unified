package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DAMAGE_POWER_PLUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class DamagePowerPlus {
  private DamagePowerPlus() {}

  public final static int EIGHT = 9;
  public final static int EIGHTEEN = 19;
  public final static int ELEVEN = 12;
  public final static int FIFTEEN = 16;
  public final static int FIVE = 5;
  public final static int FOUR = 4;
  public final static int FOURTEEN = 15;
  public final static int NINE = 10;
  public final static int NINTEEN = 20;
  public final static int ONE = 1;
  public final static int SEVEN = 8;
  public final static int SEVENTEEN = 18;
  public final static int SIX = 7;
  public final static int SIXTEEN = 17;
  public final static int TEN = 11;
  public final static int THIRTEEN = 14;
  public final static int THREE = 3;
  public final static int TWELVE = 13;
  public final static int TWENTY = 21;
  public final static int TWO = 2;

  public static String nameOf(int value) {
    if (value == 9) return "DamagePowerPlus.EIGHT";
    if (value == 19) return "DamagePowerPlus.EIGHTEEN";
    if (value == 12) return "DamagePowerPlus.ELEVEN";
    if (value == 16) return "DamagePowerPlus.FIFTEEN";
    if (value == 5) return "DamagePowerPlus.FIVE";
    if (value == 4) return "DamagePowerPlus.FOUR";
    if (value == 15) return "DamagePowerPlus.FOURTEEN";
    if (value == 10) return "DamagePowerPlus.NINE";
    if (value == 20) return "DamagePowerPlus.NINTEEN";
    if (value == 1) return "DamagePowerPlus.ONE";
    if (value == 8) return "DamagePowerPlus.SEVEN";
    if (value == 18) return "DamagePowerPlus.SEVENTEEN";
    if (value == 7) return "DamagePowerPlus.SIX";
    if (value == 17) return "DamagePowerPlus.SIXTEEN";
    if (value == 11) return "DamagePowerPlus.TEN";
    if (value == 14) return "DamagePowerPlus.THIRTEEN";
    if (value == 3) return "DamagePowerPlus.THREE";
    if (value == 13) return "DamagePowerPlus.TWELVE";
    if (value == 21) return "DamagePowerPlus.TWENTY";
    if (value == 2) return "DamagePowerPlus.TWO";
    return "DamagePowerPlus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "DamagePowerPlus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "DamagePowerPlus.(not found: " + value + ")";
  }
}
