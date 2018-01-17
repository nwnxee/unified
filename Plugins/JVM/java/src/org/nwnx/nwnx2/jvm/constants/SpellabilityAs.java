package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_AS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityAs {
  private SpellabilityAs() {}

  public final static int DARKNESS = 606;
  public final static int GHOSTLY_VISAGE = 605;
  public final static int IMPROVED_INVISIBLITY = 608;
  public final static int INVISIBILITY = 607;

  public static String nameOf(int value) {
    if (value == 606) return "SpellabilityAs.DARKNESS";
    if (value == 605) return "SpellabilityAs.GHOSTLY_VISAGE";
    if (value == 608) return "SpellabilityAs.IMPROVED_INVISIBLITY";
    if (value == 607) return "SpellabilityAs.INVISIBILITY";
    return "SpellabilityAs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityAs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityAs.(not found: " + value + ")";
  }
}
