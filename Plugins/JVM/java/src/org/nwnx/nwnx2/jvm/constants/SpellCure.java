package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_CURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellCure {
  private SpellCure() {}

  public final static int CRITICAL_WOUNDS = 31;
  public final static int LIGHT_WOUNDS = 32;
  public final static int MINOR_WOUNDS = 33;
  public final static int MODERATE_WOUNDS = 34;
  public final static int SERIOUS_WOUNDS = 35;

  public static String nameOf(int value) {
    if (value == 31) return "SpellCure.CRITICAL_WOUNDS";
    if (value == 32) return "SpellCure.LIGHT_WOUNDS";
    if (value == 33) return "SpellCure.MINOR_WOUNDS";
    if (value == 34) return "SpellCure.MODERATE_WOUNDS";
    if (value == 35) return "SpellCure.SERIOUS_WOUNDS";
    return "SpellCure.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellCure.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellCure.(not found: " + value + ")";
  }
}
