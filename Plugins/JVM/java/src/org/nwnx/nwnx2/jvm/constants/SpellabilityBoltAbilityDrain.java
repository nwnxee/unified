package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_BOLT_ABILITY_DRAIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityBoltAbilityDrain {
  private SpellabilityBoltAbilityDrain() {}

  public final static int CHARISMA = 205;
  public final static int CONSTITUTION = 206;
  public final static int DEXTERITY = 207;
  public final static int INTELLIGENCE = 208;
  public final static int STRENGTH = 209;
  public final static int WISDOM = 210;

  public static String nameOf(int value) {
    if (value == 205) return "SpellabilityBoltAbilityDrain.CHARISMA";
    if (value == 206) return "SpellabilityBoltAbilityDrain.CONSTITUTION";
    if (value == 207) return "SpellabilityBoltAbilityDrain.DEXTERITY";
    if (value == 208) return "SpellabilityBoltAbilityDrain.INTELLIGENCE";
    if (value == 209) return "SpellabilityBoltAbilityDrain.STRENGTH";
    if (value == 210) return "SpellabilityBoltAbilityDrain.WISDOM";
    return "SpellabilityBoltAbilityDrain.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityBoltAbilityDrain.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityBoltAbilityDrain.(not found: " + value + ")";
  }
}
