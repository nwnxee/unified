package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_AC_BONUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAcBonus {
  private ItemPropertyAcBonus() {}

  public final static int ITEM_PROPERTY_AC_BONUS = 1 ;
  public final static int VS_ALIGNMENT_GROUP = 2 ;
  public final static int VS_DAMAGE_TYPE = 3 ;
  public final static int VS_RACIAL_GROUP = 4 ;
  public final static int VS_SPECIFIC_ALIGNMENT = 5 ;

  public static String nameOf(int value) {
    if (value == 1 ) return "ItemPropertyAcBonus.ITEM_PROPERTY_AC_BONUS";
    if (value == 2 ) return "ItemPropertyAcBonus.VS_ALIGNMENT_GROUP";
    if (value == 3 ) return "ItemPropertyAcBonus.VS_DAMAGE_TYPE";
    if (value == 4 ) return "ItemPropertyAcBonus.VS_RACIAL_GROUP";
    if (value == 5 ) return "ItemPropertyAcBonus.VS_SPECIFIC_ALIGNMENT";
    return "ItemPropertyAcBonus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAcBonus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAcBonus.(not found: " + value + ")";
  }
}
