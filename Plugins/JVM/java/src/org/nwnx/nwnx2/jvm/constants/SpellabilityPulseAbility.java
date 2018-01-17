package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_PULSE_ABILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityPulseAbility {
  private SpellabilityPulseAbility() {}

  public final static int DRAIN_CHARISMA = 292;
  public final static int DRAIN_CONSTITUTION = 293;
  public final static int DRAIN_DEXTERITY = 294;
  public final static int DRAIN_INTELLIGENCE = 291;
  public final static int DRAIN_STRENGTH = 295;
  public final static int DRAIN_WISDOM = 296;

  public static String nameOf(int value) {
    if (value == 292) return "SpellabilityPulseAbility.DRAIN_CHARISMA";
    if (value == 293) return "SpellabilityPulseAbility.DRAIN_CONSTITUTION";
    if (value == 294) return "SpellabilityPulseAbility.DRAIN_DEXTERITY";
    if (value == 291) return "SpellabilityPulseAbility.DRAIN_INTELLIGENCE";
    if (value == 295) return "SpellabilityPulseAbility.DRAIN_STRENGTH";
    if (value == 296) return "SpellabilityPulseAbility.DRAIN_WISDOM";
    return "SpellabilityPulseAbility.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityPulseAbility.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityPulseAbility.(not found: " + value + ")";
  }
}
