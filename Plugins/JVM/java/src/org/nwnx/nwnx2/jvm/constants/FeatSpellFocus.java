package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SPELL_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSpellFocus {
  private FeatSpellFocus() {}

  public final static int ABJURATION = 35;
  public final static int CONJURATION = 166;
  public final static int DIVINATION = 167;
  public final static int ENCHANTMENT = 168;
  public final static int EVOCATION = 169;
  public final static int ILLUSION = 170;
  public final static int NECROMANCY = 171;
  public final static int TRANSMUTATION = 172;

  public static String nameOf(int value) {
    if (value == 35) return "FeatSpellFocus.ABJURATION";
    if (value == 166) return "FeatSpellFocus.CONJURATION";
    if (value == 167) return "FeatSpellFocus.DIVINATION";
    if (value == 168) return "FeatSpellFocus.ENCHANTMENT";
    if (value == 169) return "FeatSpellFocus.EVOCATION";
    if (value == 170) return "FeatSpellFocus.ILLUSION";
    if (value == 171) return "FeatSpellFocus.NECROMANCY";
    if (value == 172) return "FeatSpellFocus.TRANSMUTATION";
    return "FeatSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSpellFocus.(not found: " + value + ")";
  }
}
