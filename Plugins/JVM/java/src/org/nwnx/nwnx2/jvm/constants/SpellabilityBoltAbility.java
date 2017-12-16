package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_BOLT_ABILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityBoltAbility {
  private SpellabilityBoltAbility() {}

  public final static int DRAIN_CHARISMA = 205;
  public final static int DRAIN_CONSTITUTION = 206;
  public final static int DRAIN_DEXTERITY = 207;
  public final static int DRAIN_INTELLIGENCE = 208;
  public final static int DRAIN_STRENGTH = 209;
  public final static int DRAIN_WISDOM = 210;

  public static String nameOf(int value) {
    if (value == 205) return "SpellabilityBoltAbility.DRAIN_CHARISMA";
    if (value == 206) return "SpellabilityBoltAbility.DRAIN_CONSTITUTION";
    if (value == 207) return "SpellabilityBoltAbility.DRAIN_DEXTERITY";
    if (value == 208) return "SpellabilityBoltAbility.DRAIN_INTELLIGENCE";
    if (value == 209) return "SpellabilityBoltAbility.DRAIN_STRENGTH";
    if (value == 210) return "SpellabilityBoltAbility.DRAIN_WISDOM";
    return "SpellabilityBoltAbility.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityBoltAbility.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityBoltAbility.(not found: " + value + ")";
  }
}
