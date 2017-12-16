package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_INVISIBILITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellInvisibility {
  private SpellInvisibility() {}

  public final static int PURGE = 91;
  public final static int SPELL_INVISIBILITY = 90;
  public final static int SPHERE = 92;

  public static String nameOf(int value) {
    if (value == 91) return "SpellInvisibility.PURGE";
    if (value == 90) return "SpellInvisibility.SPELL_INVISIBILITY";
    if (value == 92) return "SpellInvisibility.SPHERE";
    return "SpellInvisibility.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellInvisibility.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellInvisibility.(not found: " + value + ")";
  }
}
