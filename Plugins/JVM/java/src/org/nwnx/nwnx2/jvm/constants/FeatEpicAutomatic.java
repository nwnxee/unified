package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "FEAT_EPIC_AUTOMATIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class FeatEpicAutomatic {
  private FeatEpicAutomatic() {}

  public final static int QUICKEN_1 = 857;
  public final static int QUICKEN_2 = 858;
  public final static int QUICKEN_3 = 859;
  public final static int SILENT_SPELL_1 = 860;
  public final static int SILENT_SPELL_2 = 861;
  public final static int SILENT_SPELL_3 = 862;
  public final static int STILL_SPELL_1 = 863;
  public final static int STILL_SPELL_2 = 864;
  public final static int STILL_SPELL_3 = 865;

  public static String nameOf(int value) {
    if (value == 857) return "FeatEpicAutomatic.QUICKEN_1";
    if (value == 858) return "FeatEpicAutomatic.QUICKEN_2";
    if (value == 859) return "FeatEpicAutomatic.QUICKEN_3";
    if (value == 860) return "FeatEpicAutomatic.SILENT_SPELL_1";
    if (value == 861) return "FeatEpicAutomatic.SILENT_SPELL_2";
    if (value == 862) return "FeatEpicAutomatic.SILENT_SPELL_3";
    if (value == 863) return "FeatEpicAutomatic.STILL_SPELL_1";
    if (value == 864) return "FeatEpicAutomatic.STILL_SPELL_2";
    if (value == 865) return "FeatEpicAutomatic.STILL_SPELL_3";
    return "FeatEpicAutomatic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "FeatEpicAutomatic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "FeatEpicAutomatic.(not found: " + value + ")";
  }
}
