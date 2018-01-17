package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_USE_LIMITATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyUseLimitation {
  private ItemPropertyUseLimitation() {}

  public final static int ALIGNMENT_GROUP = 62 ;
  public final static int CLASS = 63 ;
  public final static int RACIAL_TYPE = 64 ;
  public final static int SPECIFIC_ALIGNMENT = 65 ;
  public final static int TILESET = 66 ;

  public static String nameOf(int value) {
    if (value == 62 ) return "ItemPropertyUseLimitation.ALIGNMENT_GROUP";
    if (value == 63 ) return "ItemPropertyUseLimitation.CLASS";
    if (value == 64 ) return "ItemPropertyUseLimitation.RACIAL_TYPE";
    if (value == 65 ) return "ItemPropertyUseLimitation.SPECIFIC_ALIGNMENT";
    if (value == 66 ) return "ItemPropertyUseLimitation.TILESET";
    return "ItemPropertyUseLimitation.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyUseLimitation.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyUseLimitation.(not found: " + value + ")";
  }
}
