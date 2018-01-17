package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_AUTOMATIC_SILENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicAutomaticSilent {
  private FeatEpicAutomaticSilent() {}

  public final static int SPELL_1 = 860;
  public final static int SPELL_2 = 861;
  public final static int SPELL_3 = 862;

  public static String nameOf(int value) {
    if (value == 860) return "FeatEpicAutomaticSilent.SPELL_1";
    if (value == 861) return "FeatEpicAutomaticSilent.SPELL_2";
    if (value == 862) return "FeatEpicAutomaticSilent.SPELL_3";
    return "FeatEpicAutomaticSilent.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicAutomaticSilent.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicAutomaticSilent.(not found: " + value + ")";
  }
}
