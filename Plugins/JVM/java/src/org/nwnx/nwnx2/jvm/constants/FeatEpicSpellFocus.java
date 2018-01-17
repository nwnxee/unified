package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_SPELL_FOCUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicSpellFocus {
  private FeatEpicSpellFocus() {}

  public final static int ABJURATION = 610;
  public final static int CONJURATION = 611;
  public final static int DIVINATION = 612;
  public final static int ENCHANTMENT = 613;
  public final static int EVOCATION = 614;
  public final static int ILLUSION = 615;
  public final static int NECROMANCY = 616;
  public final static int TRANSMUTATION = 617;

  public static String nameOf(int value) {
    if (value == 610) return "FeatEpicSpellFocus.ABJURATION";
    if (value == 611) return "FeatEpicSpellFocus.CONJURATION";
    if (value == 612) return "FeatEpicSpellFocus.DIVINATION";
    if (value == 613) return "FeatEpicSpellFocus.ENCHANTMENT";
    if (value == 614) return "FeatEpicSpellFocus.EVOCATION";
    if (value == 615) return "FeatEpicSpellFocus.ILLUSION";
    if (value == 616) return "FeatEpicSpellFocus.NECROMANCY";
    if (value == 617) return "FeatEpicSpellFocus.TRANSMUTATION";
    return "FeatEpicSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicSpellFocus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicSpellFocus.(not found: " + value + ")";
  }
}
