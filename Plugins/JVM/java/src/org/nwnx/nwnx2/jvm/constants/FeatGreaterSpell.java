package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_GREATER_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatGreaterSpell {
  private FeatGreaterSpell() {}

  public final static int FOCUS_ABJURATION = 393;
  public final static int FOCUS_CONJURATION = 394;
  public final static int FOCUS_DIVINATION = 395;
  public final static int FOCUS_DIVINIATION = 395;
  public final static int FOCUS_ENCHANTMENT = 396;
  public final static int FOCUS_EVOCATION = 397;
  public final static int FOCUS_ILLUSION = 398;
  public final static int FOCUS_NECROMANCY = 399;
  public final static int FOCUS_TRANSMUTATION = 400;
  public final static int PENETRATION = 401;

  public static String nameOf(int value) {
    if (value == 393) return "FeatGreaterSpell.FOCUS_ABJURATION";
    if (value == 394) return "FeatGreaterSpell.FOCUS_CONJURATION";
    if (value == 395) return "FeatGreaterSpell.FOCUS_DIVINATION";
    if (value == 395) return "FeatGreaterSpell.FOCUS_DIVINIATION";
    if (value == 396) return "FeatGreaterSpell.FOCUS_ENCHANTMENT";
    if (value == 397) return "FeatGreaterSpell.FOCUS_EVOCATION";
    if (value == 398) return "FeatGreaterSpell.FOCUS_ILLUSION";
    if (value == 399) return "FeatGreaterSpell.FOCUS_NECROMANCY";
    if (value == 400) return "FeatGreaterSpell.FOCUS_TRANSMUTATION";
    if (value == 401) return "FeatGreaterSpell.PENETRATION";
    return "FeatGreaterSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatGreaterSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatGreaterSpell.(not found: " + value + ")";
  }
}
