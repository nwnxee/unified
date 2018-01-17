package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_NEGATIVE_ENERGY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellNegativeEnergy {
  private SpellNegativeEnergy() {}

  public final static int BURST = 370;
  public final static int PROTECTION = 125;
  public final static int RAY = 371;

  public static String nameOf(int value) {
    if (value == 370) return "SpellNegativeEnergy.BURST";
    if (value == 125) return "SpellNegativeEnergy.PROTECTION";
    if (value == 371) return "SpellNegativeEnergy.RAY";
    return "SpellNegativeEnergy.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellNegativeEnergy.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellNegativeEnergy.(not found: " + value + ")";
  }
}
