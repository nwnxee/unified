package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_IMPROVED_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicImprovedSpell {
  private FeatEpicImprovedSpell() {}

  public final static int RESISTANCE_1 = 699;
  public final static int RESISTANCE_10 = 708;
  public final static int RESISTANCE_2 = 700;
  public final static int RESISTANCE_3 = 701;
  public final static int RESISTANCE_4 = 702;
  public final static int RESISTANCE_5 = 703;
  public final static int RESISTANCE_6 = 704;
  public final static int RESISTANCE_7 = 705;
  public final static int RESISTANCE_8 = 706;
  public final static int RESISTANCE_9 = 707;

  public static String nameOf(int value) {
    if (value == 699) return "FeatEpicImprovedSpell.RESISTANCE_1";
    if (value == 708) return "FeatEpicImprovedSpell.RESISTANCE_10";
    if (value == 700) return "FeatEpicImprovedSpell.RESISTANCE_2";
    if (value == 701) return "FeatEpicImprovedSpell.RESISTANCE_3";
    if (value == 702) return "FeatEpicImprovedSpell.RESISTANCE_4";
    if (value == 703) return "FeatEpicImprovedSpell.RESISTANCE_5";
    if (value == 704) return "FeatEpicImprovedSpell.RESISTANCE_6";
    if (value == 705) return "FeatEpicImprovedSpell.RESISTANCE_7";
    if (value == 706) return "FeatEpicImprovedSpell.RESISTANCE_8";
    if (value == 707) return "FeatEpicImprovedSpell.RESISTANCE_9";
    return "FeatEpicImprovedSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicImprovedSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicImprovedSpell.(not found: " + value + ")";
  }
}
