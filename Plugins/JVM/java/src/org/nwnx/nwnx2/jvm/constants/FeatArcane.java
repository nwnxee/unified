package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_ARCANE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatArcane {
  private FeatArcane() {}

  public final static int DEFENSE_ABJURATION = 415;
  public final static int DEFENSE_CONJURATION = 416;
  public final static int DEFENSE_DIVINATION = 417;
  public final static int DEFENSE_ENCHANTMENT = 418;
  public final static int DEFENSE_EVOCATION = 419;
  public final static int DEFENSE_ILLUSION = 420;
  public final static int DEFENSE_NECROMANCY = 421;
  public final static int DEFENSE_TRANSMUTATION = 422;

  public static String nameOf(int value) {
    if (value == 415) return "FeatArcane.DEFENSE_ABJURATION";
    if (value == 416) return "FeatArcane.DEFENSE_CONJURATION";
    if (value == 417) return "FeatArcane.DEFENSE_DIVINATION";
    if (value == 418) return "FeatArcane.DEFENSE_ENCHANTMENT";
    if (value == 419) return "FeatArcane.DEFENSE_EVOCATION";
    if (value == 420) return "FeatArcane.DEFENSE_ILLUSION";
    if (value == 421) return "FeatArcane.DEFENSE_NECROMANCY";
    if (value == 422) return "FeatArcane.DEFENSE_TRANSMUTATION";
    return "FeatArcane.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatArcane.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatArcane.(not found: " + value + ")";
  }
}
