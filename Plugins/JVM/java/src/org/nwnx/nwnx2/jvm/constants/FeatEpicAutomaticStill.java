package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_AUTOMATIC_STILL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicAutomaticStill {
  private FeatEpicAutomaticStill() {}

  public final static int SPELL_1 = 863;
  public final static int SPELL_2 = 864;
  public final static int SPELL_3 = 865;

  public static String nameOf(int value) {
    if (value == 863) return "FeatEpicAutomaticStill.SPELL_1";
    if (value == 864) return "FeatEpicAutomaticStill.SPELL_2";
    if (value == 865) return "FeatEpicAutomaticStill.SPELL_3";
    return "FeatEpicAutomaticStill.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicAutomaticStill.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicAutomaticStill.(not found: " + value + ")";
  }
}
