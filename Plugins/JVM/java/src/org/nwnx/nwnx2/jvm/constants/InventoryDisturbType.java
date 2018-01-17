package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVENTORY_DISTURB_TYPE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class InventoryDisturbType {
  private InventoryDisturbType() {}

  public final static int ADDED = 0;
  public final static int REMOVED = 1;
  public final static int STOLEN = 2;

  public static String nameOf(int value) {
    if (value == 0) return "InventoryDisturbType.ADDED";
    if (value == 1) return "InventoryDisturbType.REMOVED";
    if (value == 2) return "InventoryDisturbType.STOLEN";
    return "InventoryDisturbType.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "InventoryDisturbType.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "InventoryDisturbType.(not found: " + value + ")";
  }
}
