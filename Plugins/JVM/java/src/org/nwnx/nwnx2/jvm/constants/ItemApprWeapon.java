package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_WEAPON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprWeapon {
  private ItemApprWeapon() {}

  public final static int COLOR_BOTTOM = 0;
  public final static int COLOR_MIDDLE = 1;
  public final static int COLOR_TOP = 2;
  public final static int MODEL_BOTTOM = 0;
  public final static int MODEL_MIDDLE = 1;
  public final static int MODEL_TOP = 2;

  public static String nameOf(int value) {
    if (value == 0) return "ItemApprWeapon.COLOR_BOTTOM";
    if (value == 1) return "ItemApprWeapon.COLOR_MIDDLE";
    if (value == 2) return "ItemApprWeapon.COLOR_TOP";
    if (value == 0) return "ItemApprWeapon.MODEL_BOTTOM";
    if (value == 1) return "ItemApprWeapon.MODEL_MIDDLE";
    if (value == 2) return "ItemApprWeapon.MODEL_TOP";
    return "ItemApprWeapon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprWeapon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprWeapon.(not found: " + value + ")";
  }
}
