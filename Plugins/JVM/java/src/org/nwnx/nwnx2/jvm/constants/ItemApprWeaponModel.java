package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_APPR_WEAPON_MODEL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemApprWeaponModel {
  private ItemApprWeaponModel() {}

  public final static int BOTTOM = 0;
  public final static int MIDDLE = 1;
  public final static int TOP = 2;

  public static String nameOf(int value) {
    if (value == 0) return "ItemApprWeaponModel.BOTTOM";
    if (value == 1) return "ItemApprWeaponModel.MIDDLE";
    if (value == 2) return "ItemApprWeaponModel.TOP";
    return "ItemApprWeaponModel.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemApprWeaponModel.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemApprWeaponModel.(not found: " + value + ")";
  }
}
