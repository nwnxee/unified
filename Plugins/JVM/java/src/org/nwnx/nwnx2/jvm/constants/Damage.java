package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DAMAGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Damage {
  private Damage() {}

  public final static int BONUS_1 = 1;
  public final static int BONUS_10 = 20;
  public final static int BONUS_11 = 21;
  public final static int BONUS_12 = 22;
  public final static int BONUS_13 = 23;
  public final static int BONUS_14 = 24;
  public final static int BONUS_15 = 25;
  public final static int BONUS_16 = 26;
  public final static int BONUS_17 = 27;
  public final static int BONUS_18 = 28;
  public final static int BONUS_19 = 29;
  public final static int BONUS_2 = 2;
  public final static int BONUS_20 = 30;
  public final static int BONUS_3 = 3;
  public final static int BONUS_4 = 4;
  public final static int BONUS_5 = 5;
  public final static int BONUS_6 = 16;
  public final static int BONUS_7 = 17;
  public final static int BONUS_8 = 18;
  public final static int BONUS_9 = 19;
  public final static int POWER_ENERGY = 6;
  public final static int POWER_NORMAL = 0;
  public final static int POWER_PLUS_EIGHT = 9;
  public final static int POWER_PLUS_EIGHTEEN = 19;
  public final static int POWER_PLUS_ELEVEN = 12;
  public final static int POWER_PLUS_FIFTEEN = 16;
  public final static int POWER_PLUS_FIVE = 5;
  public final static int POWER_PLUS_FOUR = 4;
  public final static int POWER_PLUS_FOURTEEN = 15;
  public final static int POWER_PLUS_NINE = 10;
  public final static int POWER_PLUS_NINTEEN = 20;
  public final static int POWER_PLUS_ONE = 1;
  public final static int POWER_PLUS_SEVEN = 8;
  public final static int POWER_PLUS_SEVENTEEN = 18;
  public final static int POWER_PLUS_SIX = 7;
  public final static int POWER_PLUS_SIXTEEN = 17;
  public final static int POWER_PLUS_TEN = 11;
  public final static int POWER_PLUS_THIRTEEN = 14;
  public final static int POWER_PLUS_THREE = 3;
  public final static int POWER_PLUS_TWELVE = 13;
  public final static int POWER_PLUS_TWENTY = 21;
  public final static int POWER_PLUS_TWO = 2;
  public final static int TYPE_ACID = 16;
  public final static int TYPE_BASE_WEAPON = 4096;
  public final static int TYPE_BLUDGEONING = 1;
  public final static int TYPE_COLD = 32;
  public final static int TYPE_DIVINE = 64;
  public final static int TYPE_ELECTRICAL = 128;
  public final static int TYPE_FIRE = 256;
  public final static int TYPE_MAGICAL = 8;
  public final static int TYPE_NEGATIVE = 512;
  public final static int TYPE_PIERCING = 2;
  public final static int TYPE_POSITIVE = 1024;
  public final static int TYPE_SLASHING = 4;
  public final static int TYPE_SONIC = 2048;

  public static String nameOf(int value) {
    if (value == 1) return "Damage.BONUS_1";
    if (value == 20) return "Damage.BONUS_10";
    if (value == 21) return "Damage.BONUS_11";
    if (value == 22) return "Damage.BONUS_12";
    if (value == 23) return "Damage.BONUS_13";
    if (value == 24) return "Damage.BONUS_14";
    if (value == 25) return "Damage.BONUS_15";
    if (value == 26) return "Damage.BONUS_16";
    if (value == 27) return "Damage.BONUS_17";
    if (value == 28) return "Damage.BONUS_18";
    if (value == 29) return "Damage.BONUS_19";
    if (value == 2) return "Damage.BONUS_2";
    if (value == 30) return "Damage.BONUS_20";
    if (value == 3) return "Damage.BONUS_3";
    if (value == 4) return "Damage.BONUS_4";
    if (value == 5) return "Damage.BONUS_5";
    if (value == 16) return "Damage.BONUS_6";
    if (value == 17) return "Damage.BONUS_7";
    if (value == 18) return "Damage.BONUS_8";
    if (value == 19) return "Damage.BONUS_9";
    if (value == 6) return "Damage.POWER_ENERGY";
    if (value == 0) return "Damage.POWER_NORMAL";
    if (value == 9) return "Damage.POWER_PLUS_EIGHT";
    if (value == 19) return "Damage.POWER_PLUS_EIGHTEEN";
    if (value == 12) return "Damage.POWER_PLUS_ELEVEN";
    if (value == 16) return "Damage.POWER_PLUS_FIFTEEN";
    if (value == 5) return "Damage.POWER_PLUS_FIVE";
    if (value == 4) return "Damage.POWER_PLUS_FOUR";
    if (value == 15) return "Damage.POWER_PLUS_FOURTEEN";
    if (value == 10) return "Damage.POWER_PLUS_NINE";
    if (value == 20) return "Damage.POWER_PLUS_NINTEEN";
    if (value == 1) return "Damage.POWER_PLUS_ONE";
    if (value == 8) return "Damage.POWER_PLUS_SEVEN";
    if (value == 18) return "Damage.POWER_PLUS_SEVENTEEN";
    if (value == 7) return "Damage.POWER_PLUS_SIX";
    if (value == 17) return "Damage.POWER_PLUS_SIXTEEN";
    if (value == 11) return "Damage.POWER_PLUS_TEN";
    if (value == 14) return "Damage.POWER_PLUS_THIRTEEN";
    if (value == 3) return "Damage.POWER_PLUS_THREE";
    if (value == 13) return "Damage.POWER_PLUS_TWELVE";
    if (value == 21) return "Damage.POWER_PLUS_TWENTY";
    if (value == 2) return "Damage.POWER_PLUS_TWO";
    if (value == 16) return "Damage.TYPE_ACID";
    if (value == 4096) return "Damage.TYPE_BASE_WEAPON";
    if (value == 1) return "Damage.TYPE_BLUDGEONING";
    if (value == 32) return "Damage.TYPE_COLD";
    if (value == 64) return "Damage.TYPE_DIVINE";
    if (value == 128) return "Damage.TYPE_ELECTRICAL";
    if (value == 256) return "Damage.TYPE_FIRE";
    if (value == 8) return "Damage.TYPE_MAGICAL";
    if (value == 512) return "Damage.TYPE_NEGATIVE";
    if (value == 2) return "Damage.TYPE_PIERCING";
    if (value == 1024) return "Damage.TYPE_POSITIVE";
    if (value == 4) return "Damage.TYPE_SLASHING";
    if (value == 2048) return "Damage.TYPE_SONIC";
    return "Damage.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Damage.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Damage.(not found: " + value + ")";
  }
}
