package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_DRAGON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityDragon {
  private SpellabilityDragon() {}

  public final static int BREATH_ACID = 236;
  public final static int BREATH_COLD = 237;
  public final static int BREATH_FEAR = 238;
  public final static int BREATH_FIRE = 239;
  public final static int BREATH_GAS = 240;
  public final static int BREATH_LIGHTNING = 241;
  public final static int BREATH_NEGATIVE = 698;
  public final static int BREATH_PARALYZE = 242;
  public final static int BREATH_SLEEP = 243;
  public final static int BREATH_SLOW = 244;
  public final static int BREATH_WEAKEN = 245;
  public final static int FEAR = 412;
  public final static int WING_BUFFET = 246;

  public static String nameOf(int value) {
    if (value == 236) return "SpellabilityDragon.BREATH_ACID";
    if (value == 237) return "SpellabilityDragon.BREATH_COLD";
    if (value == 238) return "SpellabilityDragon.BREATH_FEAR";
    if (value == 239) return "SpellabilityDragon.BREATH_FIRE";
    if (value == 240) return "SpellabilityDragon.BREATH_GAS";
    if (value == 241) return "SpellabilityDragon.BREATH_LIGHTNING";
    if (value == 698) return "SpellabilityDragon.BREATH_NEGATIVE";
    if (value == 242) return "SpellabilityDragon.BREATH_PARALYZE";
    if (value == 243) return "SpellabilityDragon.BREATH_SLEEP";
    if (value == 244) return "SpellabilityDragon.BREATH_SLOW";
    if (value == 245) return "SpellabilityDragon.BREATH_WEAKEN";
    if (value == 412) return "SpellabilityDragon.FEAR";
    if (value == 246) return "SpellabilityDragon.WING_BUFFET";
    return "SpellabilityDragon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityDragon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityDragon.(not found: " + value + ")";
  }
}
