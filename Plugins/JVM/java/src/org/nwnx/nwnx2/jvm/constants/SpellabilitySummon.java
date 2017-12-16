package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_SUMMON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilitySummon {
  private SpellabilitySummon() {}

  public final static int ANIMAL_COMPANION = 317;
  public final static int CELESTIAL = 379;
  public final static int FAMILIAR = 318;
  public final static int MEPHIT = 378;
  public final static int SLAAD = 303;
  public final static int TANARRI = 304;

  public static String nameOf(int value) {
    if (value == 317) return "SpellabilitySummon.ANIMAL_COMPANION";
    if (value == 379) return "SpellabilitySummon.CELESTIAL";
    if (value == 318) return "SpellabilitySummon.FAMILIAR";
    if (value == 378) return "SpellabilitySummon.MEPHIT";
    if (value == 303) return "SpellabilitySummon.SLAAD";
    if (value == 304) return "SpellabilitySummon.TANARRI";
    return "SpellabilitySummon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilitySummon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilitySummon.(not found: " + value + ")";
  }
}
