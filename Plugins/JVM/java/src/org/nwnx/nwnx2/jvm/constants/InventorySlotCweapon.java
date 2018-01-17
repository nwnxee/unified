package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVENTORY_SLOT_CWEAPON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class InventorySlotCweapon {
  private InventorySlotCweapon() {}

  public final static int B = 16;
  public final static int L = 14;
  public final static int R = 15;

  public static String nameOf(int value) {
    if (value == 16) return "InventorySlotCweapon.B";
    if (value == 14) return "InventorySlotCweapon.L";
    if (value == 15) return "InventorySlotCweapon.R";
    return "InventorySlotCweapon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "InventorySlotCweapon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "InventorySlotCweapon.(not found: " + value + ")";
  }
}
