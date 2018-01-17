package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_HARDINESS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatHardiness {
  private FeatHardiness() {}

  public final static int VERSUS_ENCHANTMENTS = 236;
  public final static int VERSUS_ILLUSIONS = 241;
  public final static int VERSUS_POISONS = 229;
  public final static int VERSUS_SPELLS = 230;

  public static String nameOf(int value) {
    if (value == 236) return "FeatHardiness.VERSUS_ENCHANTMENTS";
    if (value == 241) return "FeatHardiness.VERSUS_ILLUSIONS";
    if (value == 229) return "FeatHardiness.VERSUS_POISONS";
    if (value == 230) return "FeatHardiness.VERSUS_SPELLS";
    return "FeatHardiness.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatHardiness.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatHardiness.(not found: " + value + ")";
  }
}
