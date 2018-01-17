package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVENTORY_SLOT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class InventorySlot {
  private InventorySlot() {}

  public final static int ARMS = 3;
  public final static int ARROWS = 11;
  public final static int BELT = 10;
  public final static int BOLTS = 13;
  public final static int BOOTS = 2;
  public final static int BULLETS = 12;
  public final static int CARMOUR = 17;
  public final static int CHEST = 1;
  public final static int CLOAK = 6;
  public final static int CWEAPON_B = 16;
  public final static int CWEAPON_L = 14;
  public final static int CWEAPON_R = 15;
  public final static int HEAD = 0;
  public final static int LEFTHAND = 5;
  public final static int LEFTRING = 7;
  public final static int NECK = 9;
  public final static int RIGHTHAND = 4;
  public final static int RIGHTRING = 8;

  public static String nameOf(int value) {
    if (value == 3) return "InventorySlot.ARMS";
    if (value == 11) return "InventorySlot.ARROWS";
    if (value == 10) return "InventorySlot.BELT";
    if (value == 13) return "InventorySlot.BOLTS";
    if (value == 2) return "InventorySlot.BOOTS";
    if (value == 12) return "InventorySlot.BULLETS";
    if (value == 17) return "InventorySlot.CARMOUR";
    if (value == 1) return "InventorySlot.CHEST";
    if (value == 6) return "InventorySlot.CLOAK";
    if (value == 16) return "InventorySlot.CWEAPON_B";
    if (value == 14) return "InventorySlot.CWEAPON_L";
    if (value == 15) return "InventorySlot.CWEAPON_R";
    if (value == 0) return "InventorySlot.HEAD";
    if (value == 5) return "InventorySlot.LEFTHAND";
    if (value == 7) return "InventorySlot.LEFTRING";
    if (value == 9) return "InventorySlot.NECK";
    if (value == 4) return "InventorySlot.RIGHTHAND";
    if (value == 8) return "InventorySlot.RIGHTRING";
    return "InventorySlot.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "InventorySlot.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "InventorySlot.(not found: " + value + ")";
  }
}
