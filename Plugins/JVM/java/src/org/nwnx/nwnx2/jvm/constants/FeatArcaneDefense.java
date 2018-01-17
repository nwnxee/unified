package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_ARCANE_DEFENSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatArcaneDefense {
  private FeatArcaneDefense() {}

  public final static int ABJURATION = 415;
  public final static int CONJURATION = 416;
  public final static int DIVINATION = 417;
  public final static int ENCHANTMENT = 418;
  public final static int EVOCATION = 419;
  public final static int ILLUSION = 420;
  public final static int NECROMANCY = 421;
  public final static int TRANSMUTATION = 422;

  public static String nameOf(int value) {
    if (value == 415) return "FeatArcaneDefense.ABJURATION";
    if (value == 416) return "FeatArcaneDefense.CONJURATION";
    if (value == 417) return "FeatArcaneDefense.DIVINATION";
    if (value == 418) return "FeatArcaneDefense.ENCHANTMENT";
    if (value == 419) return "FeatArcaneDefense.EVOCATION";
    if (value == 420) return "FeatArcaneDefense.ILLUSION";
    if (value == 421) return "FeatArcaneDefense.NECROMANCY";
    if (value == 422) return "FeatArcaneDefense.TRANSMUTATION";
    return "FeatArcaneDefense.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatArcaneDefense.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatArcaneDefense.(not found: " + value + ")";
  }
}
