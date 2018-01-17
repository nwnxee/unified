package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "APPEARANCE_TYPE_BEAR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AppearanceTypeBear {
  private AppearanceTypeBear() {}

  public final static int BLACK = 12;
  public final static int BROWN = 13;
  public final static int DIRE = 15;
  public final static int KODIAK = 204;
  public final static int POLAR = 14;

  public static String nameOf(int value) {
    if (value == 12) return "AppearanceTypeBear.BLACK";
    if (value == 13) return "AppearanceTypeBear.BROWN";
    if (value == 15) return "AppearanceTypeBear.DIRE";
    if (value == 204) return "AppearanceTypeBear.KODIAK";
    if (value == 14) return "AppearanceTypeBear.POLAR";
    return "AppearanceTypeBear.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AppearanceTypeBear.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AppearanceTypeBear.(not found: " + value + ")";
  }
}
