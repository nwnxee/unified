package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_SLAAD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeSlaad {
  private AppearanceTypeSlaad() {}

  public final static int BLACK = 426;
  public final static int BLUE = 151;
  public final static int DEATH = 152;
  public final static int GRAY = 153;
  public final static int GREEN = 154;
  public final static int RED = 155;
  public final static int WHITE = 427;

  public static String nameOf(int value) {
    if (value == 426) return "AppearanceTypeSlaad.BLACK";
    if (value == 151) return "AppearanceTypeSlaad.BLUE";
    if (value == 152) return "AppearanceTypeSlaad.DEATH";
    if (value == 153) return "AppearanceTypeSlaad.GRAY";
    if (value == 154) return "AppearanceTypeSlaad.GREEN";
    if (value == 155) return "AppearanceTypeSlaad.RED";
    if (value == 427) return "AppearanceTypeSlaad.WHITE";
    return "AppearanceTypeSlaad.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeSlaad.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeSlaad.(not found: " + value + ")";
  }
}
