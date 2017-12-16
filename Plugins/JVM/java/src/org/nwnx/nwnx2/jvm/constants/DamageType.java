package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "DAMAGE_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class DamageType {
  private DamageType() {}

  public final static int ACID = 16;
  public final static int BASE_WEAPON = 4096;
  public final static int BLUDGEONING = 1;
  public final static int COLD = 32;
  public final static int DIVINE = 64;
  public final static int ELECTRICAL = 128;
  public final static int FIRE = 256;
  public final static int MAGICAL = 8;
  public final static int NEGATIVE = 512;
  public final static int PIERCING = 2;
  public final static int POSITIVE = 1024;
  public final static int SLASHING = 4;
  public final static int SONIC = 2048;

  public static String nameOf(int value) {
    if (value == 16) return "DamageType.ACID";
    if (value == 4096) return "DamageType.BASE_WEAPON";
    if (value == 1) return "DamageType.BLUDGEONING";
    if (value == 32) return "DamageType.COLD";
    if (value == 64) return "DamageType.DIVINE";
    if (value == 128) return "DamageType.ELECTRICAL";
    if (value == 256) return "DamageType.FIRE";
    if (value == 8) return "DamageType.MAGICAL";
    if (value == 512) return "DamageType.NEGATIVE";
    if (value == 2) return "DamageType.PIERCING";
    if (value == 1024) return "DamageType.POSITIVE";
    if (value == 4) return "DamageType.SLASHING";
    if (value == 2048) return "DamageType.SONIC";
    return "DamageType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "DamageType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "DamageType.(not found: " + value + ")";
  }
}
