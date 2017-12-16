package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_DRAGON_BREATH".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityDragonBreath {
  private SpellabilityDragonBreath() {}

  public final static int ACID = 236;
  public final static int COLD = 237;
  public final static int FEAR = 238;
  public final static int FIRE = 239;
  public final static int GAS = 240;
  public final static int LIGHTNING = 241;
  public final static int NEGATIVE = 698;
  public final static int PARALYZE = 242;
  public final static int SLEEP = 243;
  public final static int SLOW = 244;
  public final static int WEAKEN = 245;

  public static String nameOf(int value) {
    if (value == 236) return "SpellabilityDragonBreath.ACID";
    if (value == 237) return "SpellabilityDragonBreath.COLD";
    if (value == 238) return "SpellabilityDragonBreath.FEAR";
    if (value == 239) return "SpellabilityDragonBreath.FIRE";
    if (value == 240) return "SpellabilityDragonBreath.GAS";
    if (value == 241) return "SpellabilityDragonBreath.LIGHTNING";
    if (value == 698) return "SpellabilityDragonBreath.NEGATIVE";
    if (value == 242) return "SpellabilityDragonBreath.PARALYZE";
    if (value == 243) return "SpellabilityDragonBreath.SLEEP";
    if (value == 244) return "SpellabilityDragonBreath.SLOW";
    if (value == 245) return "SpellabilityDragonBreath.WEAKEN";
    return "SpellabilityDragonBreath.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityDragonBreath.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityDragonBreath.(not found: " + value + ")";
  }
}
