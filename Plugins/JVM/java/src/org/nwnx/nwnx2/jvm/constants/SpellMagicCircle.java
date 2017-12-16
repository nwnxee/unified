package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_MAGIC_CIRCLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellMagicCircle {
  private SpellMagicCircle() {}

  public final static int AGAINST_CHAOS = 103;
  public final static int AGAINST_EVIL = 104;
  public final static int AGAINST_GOOD = 105;
  public final static int AGAINST_LAW = 106;

  public static String nameOf(int value) {
    if (value == 103) return "SpellMagicCircle.AGAINST_CHAOS";
    if (value == 104) return "SpellMagicCircle.AGAINST_EVIL";
    if (value == 105) return "SpellMagicCircle.AGAINST_GOOD";
    if (value == 106) return "SpellMagicCircle.AGAINST_LAW";
    return "SpellMagicCircle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellMagicCircle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellMagicCircle.(not found: " + value + ")";
  }
}
