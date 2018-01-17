package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprType {
  private ItemApprType() {}

  public final static int ARMOR_COLOR = 4;
  public final static int ARMOR_MODEL = 3;
  public final static int SIMPLE_MODEL = 0;
  public final static int WEAPON_COLOR = 1;
  public final static int WEAPON_MODEL = 2;

  public static String nameOf(int value) {
    if (value == 4) return "ItemApprType.ARMOR_COLOR";
    if (value == 3) return "ItemApprType.ARMOR_MODEL";
    if (value == 0) return "ItemApprType.SIMPLE_MODEL";
    if (value == 1) return "ItemApprType.WEAPON_COLOR";
    if (value == 2) return "ItemApprType.WEAPON_MODEL";
    return "ItemApprType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprType.(not found: " + value + ")";
  }
}
