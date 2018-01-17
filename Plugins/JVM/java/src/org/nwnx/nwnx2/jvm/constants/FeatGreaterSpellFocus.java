package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_GREATER_SPELL_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatGreaterSpellFocus {
  private FeatGreaterSpellFocus() {}

  public final static int ABJURATION = 393;
  public final static int CONJURATION = 394;
  public final static int DIVINATION = 395;
  public final static int DIVINIATION = 395;
  public final static int ENCHANTMENT = 396;
  public final static int EVOCATION = 397;
  public final static int ILLUSION = 398;
  public final static int NECROMANCY = 399;
  public final static int TRANSMUTATION = 400;

  public static String nameOf(int value) {
    if (value == 393) return "FeatGreaterSpellFocus.ABJURATION";
    if (value == 394) return "FeatGreaterSpellFocus.CONJURATION";
    if (value == 395) return "FeatGreaterSpellFocus.DIVINATION";
    if (value == 395) return "FeatGreaterSpellFocus.DIVINIATION";
    if (value == 396) return "FeatGreaterSpellFocus.ENCHANTMENT";
    if (value == 397) return "FeatGreaterSpellFocus.EVOCATION";
    if (value == 398) return "FeatGreaterSpellFocus.ILLUSION";
    if (value == 399) return "FeatGreaterSpellFocus.NECROMANCY";
    if (value == 400) return "FeatGreaterSpellFocus.TRANSMUTATION";
    return "FeatGreaterSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatGreaterSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatGreaterSpellFocus.(not found: " + value + ")";
  }
}
