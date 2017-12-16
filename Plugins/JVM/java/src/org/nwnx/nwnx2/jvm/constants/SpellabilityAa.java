package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_AA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityAa {
  private SpellabilityAa() {}

  public final static int ARROW_OF_DEATH = 604;
  public final static int HAIL_OF_ARROWS = 603;
  public final static int IMBUE_ARROW = 600;
  public final static int SEEKER_ARROW_1 = 601;
  public final static int SEEKER_ARROW_2 = 602;

  public static String nameOf(int value) {
    if (value == 604) return "SpellabilityAa.ARROW_OF_DEATH";
    if (value == 603) return "SpellabilityAa.HAIL_OF_ARROWS";
    if (value == 600) return "SpellabilityAa.IMBUE_ARROW";
    if (value == 601) return "SpellabilityAa.SEEKER_ARROW_1";
    if (value == 602) return "SpellabilityAa.SEEKER_ARROW_2";
    return "SpellabilityAa.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityAa.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityAa.(not found: " + value + ")";
  }
}
