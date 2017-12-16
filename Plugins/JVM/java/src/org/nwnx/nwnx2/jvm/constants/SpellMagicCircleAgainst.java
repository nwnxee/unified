package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_MAGIC_CIRCLE_AGAINST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellMagicCircleAgainst {
  private SpellMagicCircleAgainst() {}

  public final static int CHAOS = 103;
  public final static int EVIL = 104;
  public final static int GOOD = 105;
  public final static int LAW = 106;

  public static String nameOf(int value) {
    if (value == 103) return "SpellMagicCircleAgainst.CHAOS";
    if (value == 104) return "SpellMagicCircleAgainst.EVIL";
    if (value == 105) return "SpellMagicCircleAgainst.GOOD";
    if (value == 106) return "SpellMagicCircleAgainst.LAW";
    return "SpellMagicCircleAgainst.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellMagicCircleAgainst.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellMagicCircleAgainst.(not found: " + value + ")";
  }
}
