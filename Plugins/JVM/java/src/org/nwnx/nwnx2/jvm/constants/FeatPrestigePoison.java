package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_PRESTIGE_POISON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatPrestigePoison {
  private FeatPrestigePoison() {}

  public final static int SAVE_1 = 463;
  public final static int SAVE_2 = 464;
  public final static int SAVE_3 = 465;
  public final static int SAVE_4 = 466;
  public final static int SAVE_5 = 467;
  public final static int SAVE_EPIC = 1070;

  public static String nameOf(int value) {
    if (value == 463) return "FeatPrestigePoison.SAVE_1";
    if (value == 464) return "FeatPrestigePoison.SAVE_2";
    if (value == 465) return "FeatPrestigePoison.SAVE_3";
    if (value == 466) return "FeatPrestigePoison.SAVE_4";
    if (value == 467) return "FeatPrestigePoison.SAVE_5";
    if (value == 1070) return "FeatPrestigePoison.SAVE_EPIC";
    return "FeatPrestigePoison.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatPrestigePoison.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatPrestigePoison.(not found: " + value + ")";
  }
}
