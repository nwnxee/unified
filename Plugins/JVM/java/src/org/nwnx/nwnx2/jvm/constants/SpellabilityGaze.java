package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_GAZE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityGaze {
  private SpellabilityGaze() {}

  public final static int CHARM = 250;
  public final static int CONFUSION = 251;
  public final static int DAZE = 252;
  public final static int DEATH = 253;
  public final static int DESTROY_CHAOS = 254;
  public final static int DESTROY_EVIL = 255;
  public final static int DESTROY_GOOD = 256;
  public final static int DESTROY_LAW = 257;
  public final static int DOMINATE = 258;
  public final static int DOOM = 259;
  public final static int FEAR = 260;
  public final static int PARALYSIS = 261;
  public final static int PETRIFY = 497;
  public final static int STUNNED = 262;

  public static String nameOf(int value) {
    if (value == 250) return "SpellabilityGaze.CHARM";
    if (value == 251) return "SpellabilityGaze.CONFUSION";
    if (value == 252) return "SpellabilityGaze.DAZE";
    if (value == 253) return "SpellabilityGaze.DEATH";
    if (value == 254) return "SpellabilityGaze.DESTROY_CHAOS";
    if (value == 255) return "SpellabilityGaze.DESTROY_EVIL";
    if (value == 256) return "SpellabilityGaze.DESTROY_GOOD";
    if (value == 257) return "SpellabilityGaze.DESTROY_LAW";
    if (value == 258) return "SpellabilityGaze.DOMINATE";
    if (value == 259) return "SpellabilityGaze.DOOM";
    if (value == 260) return "SpellabilityGaze.FEAR";
    if (value == 261) return "SpellabilityGaze.PARALYSIS";
    if (value == 497) return "SpellabilityGaze.PETRIFY";
    if (value == 262) return "SpellabilityGaze.STUNNED";
    return "SpellabilityGaze.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityGaze.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityGaze.(not found: " + value + ")";
  }
}
