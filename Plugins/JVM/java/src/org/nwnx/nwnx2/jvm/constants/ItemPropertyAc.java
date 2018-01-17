package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_AC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAc {
  private ItemPropertyAc() {}

  public final static int BONUS = 1 ;
  public final static int BONUS_VS_ALIGNMENT_GROUP = 2 ;
  public final static int BONUS_VS_DAMAGE_TYPE = 3 ;
  public final static int BONUS_VS_RACIAL_GROUP = 4 ;
  public final static int BONUS_VS_SPECIFIC_ALIGNMENT = 5 ;

  public static String nameOf(int value) {
    if (value == 1 ) return "ItemPropertyAc.BONUS";
    if (value == 2 ) return "ItemPropertyAc.BONUS_VS_ALIGNMENT_GROUP";
    if (value == 3 ) return "ItemPropertyAc.BONUS_VS_DAMAGE_TYPE";
    if (value == 4 ) return "ItemPropertyAc.BONUS_VS_RACIAL_GROUP";
    if (value == 5 ) return "ItemPropertyAc.BONUS_VS_SPECIFIC_ALIGNMENT";
    return "ItemPropertyAc.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAc.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAc.(not found: " + value + ")";
  }
}
