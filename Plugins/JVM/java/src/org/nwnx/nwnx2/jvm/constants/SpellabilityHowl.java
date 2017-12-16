package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_HOWL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityHowl {
  private SpellabilityHowl() {}

  public final static int CONFUSE = 265;
  public final static int DAZE = 266;
  public final static int DEATH = 267;
  public final static int DOOM = 268;
  public final static int FEAR = 269;
  public final static int PARALYSIS = 270;
  public final static int SONIC = 271;
  public final static int STUN = 272;

  public static String nameOf(int value) {
    if (value == 265) return "SpellabilityHowl.CONFUSE";
    if (value == 266) return "SpellabilityHowl.DAZE";
    if (value == 267) return "SpellabilityHowl.DEATH";
    if (value == 268) return "SpellabilityHowl.DOOM";
    if (value == 269) return "SpellabilityHowl.FEAR";
    if (value == 270) return "SpellabilityHowl.PARALYSIS";
    if (value == 271) return "SpellabilityHowl.SONIC";
    if (value == 272) return "SpellabilityHowl.STUN";
    return "SpellabilityHowl.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityHowl.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityHowl.(not found: " + value + ")";
  }
}
