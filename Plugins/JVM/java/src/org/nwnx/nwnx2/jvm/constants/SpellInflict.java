package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_INFLICT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellInflict {
  private SpellInflict() {}

  public final static int CRITICAL_WOUNDS = 435;
  public final static int LIGHT_WOUNDS = 432;
  public final static int MINOR_WOUNDS = 431;
  public final static int MODERATE_WOUNDS = 433;
  public final static int SERIOUS_WOUNDS = 434;

  public static String nameOf(int value) {
    if (value == 435) return "SpellInflict.CRITICAL_WOUNDS";
    if (value == 432) return "SpellInflict.LIGHT_WOUNDS";
    if (value == 431) return "SpellInflict.MINOR_WOUNDS";
    if (value == 433) return "SpellInflict.MODERATE_WOUNDS";
    if (value == 434) return "SpellInflict.SERIOUS_WOUNDS";
    return "SpellInflict.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellInflict.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellInflict.(not found: " + value + ")";
  }
}
