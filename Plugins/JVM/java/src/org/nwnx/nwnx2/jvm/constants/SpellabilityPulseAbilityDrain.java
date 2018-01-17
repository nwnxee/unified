package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_PULSE_ABILITY_DRAIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityPulseAbilityDrain {
  private SpellabilityPulseAbilityDrain() {}

  public final static int CHARISMA = 292;
  public final static int CONSTITUTION = 293;
  public final static int DEXTERITY = 294;
  public final static int INTELLIGENCE = 291;
  public final static int STRENGTH = 295;
  public final static int WISDOM = 296;

  public static String nameOf(int value) {
    if (value == 292) return "SpellabilityPulseAbilityDrain.CHARISMA";
    if (value == 293) return "SpellabilityPulseAbilityDrain.CONSTITUTION";
    if (value == 294) return "SpellabilityPulseAbilityDrain.DEXTERITY";
    if (value == 291) return "SpellabilityPulseAbilityDrain.INTELLIGENCE";
    if (value == 295) return "SpellabilityPulseAbilityDrain.STRENGTH";
    if (value == 296) return "SpellabilityPulseAbilityDrain.WISDOM";
    return "SpellabilityPulseAbilityDrain.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityPulseAbilityDrain.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityPulseAbilityDrain.(not found: " + value + ")";
  }
}
