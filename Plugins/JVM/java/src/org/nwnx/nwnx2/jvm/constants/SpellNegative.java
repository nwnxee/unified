package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_NEGATIVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellNegative {
  private SpellNegative() {}

  public final static int ENERGY_BURST = 370;
  public final static int ENERGY_PROTECTION = 125;
  public final static int ENERGY_RAY = 371;

  public static String nameOf(int value) {
    if (value == 370) return "SpellNegative.ENERGY_BURST";
    if (value == 125) return "SpellNegative.ENERGY_PROTECTION";
    if (value == 371) return "SpellNegative.ENERGY_RAY";
    return "SpellNegative.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellNegative.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellNegative.(not found: " + value + ")";
  }
}
