package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_LESSER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellLesser {
  private SpellLesser() {}

  public final static int DISPEL = 94;
  public final static int MIND_BLANK = 95;
  public final static int PLANAR_BINDING = 96;
  public final static int RESTORATION = 97;
  public final static int SPELL_BREACH = 98;
  public final static int SPELL_MANTLE = 99;

  public static String nameOf(int value) {
    if (value == 94) return "SpellLesser.DISPEL";
    if (value == 95) return "SpellLesser.MIND_BLANK";
    if (value == 96) return "SpellLesser.PLANAR_BINDING";
    if (value == 97) return "SpellLesser.RESTORATION";
    if (value == 98) return "SpellLesser.SPELL_BREACH";
    if (value == 99) return "SpellLesser.SPELL_MANTLE";
    return "SpellLesser.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellLesser.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellLesser.(not found: " + value + ")";
  }
}
