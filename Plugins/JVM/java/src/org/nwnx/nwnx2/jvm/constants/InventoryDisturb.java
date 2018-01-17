package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVENTORY_DISTURB".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class InventoryDisturb {
  private InventoryDisturb() {}

  public final static int TYPE_ADDED = 0;
  public final static int TYPE_REMOVED = 1;
  public final static int TYPE_STOLEN = 2;

  public static String nameOf(int value) {
    if (value == 0) return "InventoryDisturb.TYPE_ADDED";
    if (value == 1) return "InventoryDisturb.TYPE_REMOVED";
    if (value == 2) return "InventoryDisturb.TYPE_STOLEN";
    return "InventoryDisturb.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "InventoryDisturb.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "InventoryDisturb.(not found: " + value + ")";
  }
}
