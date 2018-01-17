package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatSpell {
  private FeatSpell() {}

  public final static int FOCUS_ABJURATION = 35;
  public final static int FOCUS_CONJURATION = 166;
  public final static int FOCUS_DIVINATION = 167;
  public final static int FOCUS_ENCHANTMENT = 168;
  public final static int FOCUS_EVOCATION = 169;
  public final static int FOCUS_ILLUSION = 170;
  public final static int FOCUS_NECROMANCY = 171;
  public final static int FOCUS_TRANSMUTATION = 172;
  public final static int PENETRATION = 36;

  public static String nameOf(int value) {
    if (value == 35) return "FeatSpell.FOCUS_ABJURATION";
    if (value == 166) return "FeatSpell.FOCUS_CONJURATION";
    if (value == 167) return "FeatSpell.FOCUS_DIVINATION";
    if (value == 168) return "FeatSpell.FOCUS_ENCHANTMENT";
    if (value == 169) return "FeatSpell.FOCUS_EVOCATION";
    if (value == 170) return "FeatSpell.FOCUS_ILLUSION";
    if (value == 171) return "FeatSpell.FOCUS_NECROMANCY";
    if (value == 172) return "FeatSpell.FOCUS_TRANSMUTATION";
    if (value == 36) return "FeatSpell.PENETRATION";
    return "FeatSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatSpell.(not found: " + value + ")";
  }
}
