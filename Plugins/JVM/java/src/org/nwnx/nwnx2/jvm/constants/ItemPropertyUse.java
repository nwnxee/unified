package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_USE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyUse {
  private ItemPropertyUse() {}

  public final static int LIMITATION_ALIGNMENT_GROUP = 62 ;
  public final static int LIMITATION_CLASS = 63 ;
  public final static int LIMITATION_RACIAL_TYPE = 64 ;
  public final static int LIMITATION_SPECIFIC_ALIGNMENT = 65 ;
  public final static int LIMITATION_TILESET = 66 ;

  public static String nameOf(int value) {
    if (value == 62 ) return "ItemPropertyUse.LIMITATION_ALIGNMENT_GROUP";
    if (value == 63 ) return "ItemPropertyUse.LIMITATION_CLASS";
    if (value == 64 ) return "ItemPropertyUse.LIMITATION_RACIAL_TYPE";
    if (value == 65 ) return "ItemPropertyUse.LIMITATION_SPECIFIC_ALIGNMENT";
    if (value == 66 ) return "ItemPropertyUse.LIMITATION_TILESET";
    return "ItemPropertyUse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyUse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyUse.(not found: " + value + ")";
  }
}
