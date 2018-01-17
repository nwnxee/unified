package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_TROLL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeTroll {
  private AppearanceTypeTroll() {}

  public final static int APPEARANCE_TYPE_TROLL = 167;
  public final static int CHIEFTAIN = 164;
  public final static int SHAMAN = 165;

  public static String nameOf(int value) {
    if (value == 167) return "AppearanceTypeTroll.APPEARANCE_TYPE_TROLL";
    if (value == 164) return "AppearanceTypeTroll.CHIEFTAIN";
    if (value == 165) return "AppearanceTypeTroll.SHAMAN";
    return "AppearanceTypeTroll.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeTroll.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeTroll.(not found: " + value + ")";
  }
}
