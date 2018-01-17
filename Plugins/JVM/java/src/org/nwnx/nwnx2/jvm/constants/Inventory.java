package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "INVENTORY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Inventory {
  private Inventory() {}

  public final static int DISTURB_TYPE_ADDED = 0;
  public final static int DISTURB_TYPE_REMOVED = 1;
  public final static int DISTURB_TYPE_STOLEN = 2;
  public final static int SLOT_ARMS = 3;
  public final static int SLOT_ARROWS = 11;
  public final static int SLOT_BELT = 10;
  public final static int SLOT_BOLTS = 13;
  public final static int SLOT_BOOTS = 2;
  public final static int SLOT_BULLETS = 12;
  public final static int SLOT_CARMOUR = 17;
  public final static int SLOT_CHEST = 1;
  public final static int SLOT_CLOAK = 6;
  public final static int SLOT_CWEAPON_B = 16;
  public final static int SLOT_CWEAPON_L = 14;
  public final static int SLOT_CWEAPON_R = 15;
  public final static int SLOT_HEAD = 0;
  public final static int SLOT_LEFTHAND = 5;
  public final static int SLOT_LEFTRING = 7;
  public final static int SLOT_NECK = 9;
  public final static int SLOT_RIGHTHAND = 4;
  public final static int SLOT_RIGHTRING = 8;

  public static String nameOf(int value) {
    if (value == 0) return "Inventory.DISTURB_TYPE_ADDED";
    if (value == 1) return "Inventory.DISTURB_TYPE_REMOVED";
    if (value == 2) return "Inventory.DISTURB_TYPE_STOLEN";
    if (value == 3) return "Inventory.SLOT_ARMS";
    if (value == 11) return "Inventory.SLOT_ARROWS";
    if (value == 10) return "Inventory.SLOT_BELT";
    if (value == 13) return "Inventory.SLOT_BOLTS";
    if (value == 2) return "Inventory.SLOT_BOOTS";
    if (value == 12) return "Inventory.SLOT_BULLETS";
    if (value == 17) return "Inventory.SLOT_CARMOUR";
    if (value == 1) return "Inventory.SLOT_CHEST";
    if (value == 6) return "Inventory.SLOT_CLOAK";
    if (value == 16) return "Inventory.SLOT_CWEAPON_B";
    if (value == 14) return "Inventory.SLOT_CWEAPON_L";
    if (value == 15) return "Inventory.SLOT_CWEAPON_R";
    if (value == 0) return "Inventory.SLOT_HEAD";
    if (value == 5) return "Inventory.SLOT_LEFTHAND";
    if (value == 7) return "Inventory.SLOT_LEFTRING";
    if (value == 9) return "Inventory.SLOT_NECK";
    if (value == 4) return "Inventory.SLOT_RIGHTHAND";
    if (value == 8) return "Inventory.SLOT_RIGHTRING";
    return "Inventory.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Inventory.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Inventory.(not found: " + value + ")";
  }
}
