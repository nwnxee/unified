package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_BG".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityBg {
  private SpellabilityBg() {}

  public final static int BULLS_STRENGTH = 614;
  public final static int CONTAGION = 613;
  public final static int CREATEDEAD = 609;
  public final static int FIENDISH_SERVANT = 610;
  public final static int INFLICT_CRITICAL_WOUNDS = 612;
  public final static int INFLICT_SERIOUS_WOUNDS = 611;

  public static String nameOf(int value) {
    if (value == 614) return "SpellabilityBg.BULLS_STRENGTH";
    if (value == 613) return "SpellabilityBg.CONTAGION";
    if (value == 609) return "SpellabilityBg.CREATEDEAD";
    if (value == 610) return "SpellabilityBg.FIENDISH_SERVANT";
    if (value == 612) return "SpellabilityBg.INFLICT_CRITICAL_WOUNDS";
    if (value == 611) return "SpellabilityBg.INFLICT_SERIOUS_WOUNDS";
    return "SpellabilityBg.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityBg.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityBg.(not found: " + value + ")";
  }
}
