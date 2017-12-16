package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_DAMAGE_BONUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyDamageBonus {
  private ItemPropertyDamageBonus() {}

  public final static int ITEM_PROPERTY_DAMAGE_BONUS = 16 ;
  public final static int VS_ALIGNMENT_GROUP = 17 ;
  public final static int VS_RACIAL_GROUP = 18 ;
  public final static int VS_SPECIFIC_ALIGNMENT = 19 ;

  public static String nameOf(int value) {
    if (value == 16 ) return "ItemPropertyDamageBonus.ITEM_PROPERTY_DAMAGE_BONUS";
    if (value == 17 ) return "ItemPropertyDamageBonus.VS_ALIGNMENT_GROUP";
    if (value == 18 ) return "ItemPropertyDamageBonus.VS_RACIAL_GROUP";
    if (value == 19 ) return "ItemPropertyDamageBonus.VS_SPECIFIC_ALIGNMENT";
    return "ItemPropertyDamageBonus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyDamageBonus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyDamageBonus.(not found: " + value + ")";
  }
}
