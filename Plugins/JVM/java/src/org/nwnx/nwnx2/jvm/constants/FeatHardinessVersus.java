package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_HARDINESS_VERSUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatHardinessVersus {
  private FeatHardinessVersus() {}

  public final static int ENCHANTMENTS = 236;
  public final static int ILLUSIONS = 241;
  public final static int POISONS = 229;
  public final static int SPELLS = 230;

  public static String nameOf(int value) {
    if (value == 236) return "FeatHardinessVersus.ENCHANTMENTS";
    if (value == 241) return "FeatHardinessVersus.ILLUSIONS";
    if (value == 229) return "FeatHardinessVersus.POISONS";
    if (value == 230) return "FeatHardinessVersus.SPELLS";
    return "FeatHardinessVersus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatHardinessVersus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatHardinessVersus.(not found: " + value + ")";
  }
}
