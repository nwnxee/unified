package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_ARMOR_COLOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprArmorColor {
  private ItemApprArmorColor() {}

  public final static int CLOTH1 = 2;
  public final static int CLOTH2 = 3;
  public final static int LEATHER1 = 0;
  public final static int LEATHER2 = 1;
  public final static int METAL1 = 4;
  public final static int METAL2 = 5;

  public static String nameOf(int value) {
    if (value == 2) return "ItemApprArmorColor.CLOTH1";
    if (value == 3) return "ItemApprArmorColor.CLOTH2";
    if (value == 0) return "ItemApprArmorColor.LEATHER1";
    if (value == 1) return "ItemApprArmorColor.LEATHER2";
    if (value == 4) return "ItemApprArmorColor.METAL1";
    if (value == 5) return "ItemApprArmorColor.METAL2";
    return "ItemApprArmorColor.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprArmorColor.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprArmorColor.(not found: " + value + ")";
  }
}
