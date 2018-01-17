package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_ELEMENTAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellElemental {
  private SpellElemental() {}

  public final static int SHIELD = 47;
  public final static int SUMMONING_ITEM = 502;
  public final static int SWARM = 48;

  public static String nameOf(int value) {
    if (value == 47) return "SpellElemental.SHIELD";
    if (value == 502) return "SpellElemental.SUMMONING_ITEM";
    if (value == 48) return "SpellElemental.SWARM";
    return "SpellElemental.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellElemental.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellElemental.(not found: " + value + ")";
  }
}
