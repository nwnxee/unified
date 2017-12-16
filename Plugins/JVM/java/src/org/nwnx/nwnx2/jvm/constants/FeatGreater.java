package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_GREATER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatGreater {
  private FeatGreater() {}

  public final static int SPELL_FOCUS_ABJURATION = 393;
  public final static int SPELL_FOCUS_CONJURATION = 394;
  public final static int SPELL_FOCUS_DIVINATION = 395;
  public final static int SPELL_FOCUS_DIVINIATION = 395;
  public final static int SPELL_FOCUS_ENCHANTMENT = 396;
  public final static int SPELL_FOCUS_EVOCATION = 397;
  public final static int SPELL_FOCUS_ILLUSION = 398;
  public final static int SPELL_FOCUS_NECROMANCY = 399;
  public final static int SPELL_FOCUS_TRANSMUTATION = 400;
  public final static int SPELL_PENETRATION = 401;
  public final static int WILDSHAPE_1 = 898;
  public final static int WILDSHAPE_2 = 900;
  public final static int WILDSHAPE_3 = 901;
  public final static int WILDSHAPE_4 = 903;

  public static String nameOf(int value) {
    if (value == 393) return "FeatGreater.SPELL_FOCUS_ABJURATION";
    if (value == 394) return "FeatGreater.SPELL_FOCUS_CONJURATION";
    if (value == 395) return "FeatGreater.SPELL_FOCUS_DIVINATION";
    if (value == 395) return "FeatGreater.SPELL_FOCUS_DIVINIATION";
    if (value == 396) return "FeatGreater.SPELL_FOCUS_ENCHANTMENT";
    if (value == 397) return "FeatGreater.SPELL_FOCUS_EVOCATION";
    if (value == 398) return "FeatGreater.SPELL_FOCUS_ILLUSION";
    if (value == 399) return "FeatGreater.SPELL_FOCUS_NECROMANCY";
    if (value == 400) return "FeatGreater.SPELL_FOCUS_TRANSMUTATION";
    if (value == 401) return "FeatGreater.SPELL_PENETRATION";
    if (value == 898) return "FeatGreater.WILDSHAPE_1";
    if (value == 900) return "FeatGreater.WILDSHAPE_2";
    if (value == 901) return "FeatGreater.WILDSHAPE_3";
    if (value == 903) return "FeatGreater.WILDSHAPE_4";
    return "FeatGreater.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatGreater.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatGreater.(not found: " + value + ")";
  }
}
