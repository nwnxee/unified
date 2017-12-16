package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_RESIST_ENERGY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatResistEnergy {
  private FeatResistEnergy() {}

  public final static int ACID = 428;
  public final static int COLD = 427;
  public final static int ELECTRICAL = 430;
  public final static int FIRE = 429;
  public final static int SONIC = 431;

  public static String nameOf(int value) {
    if (value == 428) return "FeatResistEnergy.ACID";
    if (value == 427) return "FeatResistEnergy.COLD";
    if (value == 430) return "FeatResistEnergy.ELECTRICAL";
    if (value == 429) return "FeatResistEnergy.FIRE";
    if (value == 431) return "FeatResistEnergy.SONIC";
    return "FeatResistEnergy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatResistEnergy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatResistEnergy.(not found: " + value + ")";
  }
}
