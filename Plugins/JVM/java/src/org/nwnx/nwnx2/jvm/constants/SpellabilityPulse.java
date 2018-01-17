package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_PULSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityPulse {
  private SpellabilityPulse() {}

  public final static int ABILITY_DRAIN_CHARISMA = 292;
  public final static int ABILITY_DRAIN_CONSTITUTION = 293;
  public final static int ABILITY_DRAIN_DEXTERITY = 294;
  public final static int ABILITY_DRAIN_INTELLIGENCE = 291;
  public final static int ABILITY_DRAIN_STRENGTH = 295;
  public final static int ABILITY_DRAIN_WISDOM = 296;
  public final static int COLD = 286;
  public final static int DEATH = 289;
  public final static int DISEASE = 298;
  public final static int DROWN = 281;
  public final static int FIRE = 284;
  public final static int HOLY = 288;
  public final static int LEVEL_DRAIN = 290;
  public final static int LIGHTNING = 285;
  public final static int NEGATIVE = 287;
  public final static int POISON = 297;
  public final static int SPORES = 282;
  public final static int WHIRLWIND = 283;

  public static String nameOf(int value) {
    if (value == 292) return "SpellabilityPulse.ABILITY_DRAIN_CHARISMA";
    if (value == 293) return "SpellabilityPulse.ABILITY_DRAIN_CONSTITUTION";
    if (value == 294) return "SpellabilityPulse.ABILITY_DRAIN_DEXTERITY";
    if (value == 291) return "SpellabilityPulse.ABILITY_DRAIN_INTELLIGENCE";
    if (value == 295) return "SpellabilityPulse.ABILITY_DRAIN_STRENGTH";
    if (value == 296) return "SpellabilityPulse.ABILITY_DRAIN_WISDOM";
    if (value == 286) return "SpellabilityPulse.COLD";
    if (value == 289) return "SpellabilityPulse.DEATH";
    if (value == 298) return "SpellabilityPulse.DISEASE";
    if (value == 281) return "SpellabilityPulse.DROWN";
    if (value == 284) return "SpellabilityPulse.FIRE";
    if (value == 288) return "SpellabilityPulse.HOLY";
    if (value == 290) return "SpellabilityPulse.LEVEL_DRAIN";
    if (value == 285) return "SpellabilityPulse.LIGHTNING";
    if (value == 287) return "SpellabilityPulse.NEGATIVE";
    if (value == 297) return "SpellabilityPulse.POISON";
    if (value == 282) return "SpellabilityPulse.SPORES";
    if (value == 283) return "SpellabilityPulse.WHIRLWIND";
    return "SpellabilityPulse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityPulse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityPulse.(not found: " + value + ")";
  }
}
