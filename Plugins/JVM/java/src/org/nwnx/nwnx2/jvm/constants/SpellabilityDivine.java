package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_DIVINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityDivine {
  private SpellabilityDivine() {}

  public final static int PROTECTION = 382;
  public final static int STRENGTH = 381;
  public final static int TRICKERY = 384;

  public static String nameOf(int value) {
    if (value == 382) return "SpellabilityDivine.PROTECTION";
    if (value == 381) return "SpellabilityDivine.STRENGTH";
    if (value == 384) return "SpellabilityDivine.TRICKERY";
    return "SpellabilityDivine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityDivine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityDivine.(not found: " + value + ")";
  }
}
