package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "BASE_ITEM_ENCHANTED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class BaseItemEnchanted {
  private BaseItemEnchanted() {}

  public final static int POTION = 104;
  public final static int SCROLL = 105;
  public final static int WAND = 106;

  public static String nameOf(int value) {
    if (value == 104) return "BaseItemEnchanted.POTION";
    if (value == 105) return "BaseItemEnchanted.SCROLL";
    if (value == 106) return "BaseItemEnchanted.WAND";
    return "BaseItemEnchanted.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "BaseItemEnchanted.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "BaseItemEnchanted.(not found: " + value + ")";
  }
}
