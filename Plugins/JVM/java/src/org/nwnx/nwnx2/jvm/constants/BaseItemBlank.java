package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "BASE_ITEM_BLANK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class BaseItemBlank {
  private BaseItemBlank() {}

  public final static int POTION = 101;
  public final static int SCROLL = 102;
  public final static int WAND = 103;

  public static String nameOf(int value) {
    if (value == 101) return "BaseItemBlank.POTION";
    if (value == 102) return "BaseItemBlank.SCROLL";
    if (value == 103) return "BaseItemBlank.WAND";
    return "BaseItemBlank.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "BaseItemBlank.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "BaseItemBlank.(not found: " + value + ")";
  }
}
