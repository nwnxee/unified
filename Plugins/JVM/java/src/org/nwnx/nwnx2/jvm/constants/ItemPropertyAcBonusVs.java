package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_AC_BONUS_VS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAcBonusVs {
  private ItemPropertyAcBonusVs() {}

  public final static int ALIGNMENT_GROUP = 2 ;
  public final static int DAMAGE_TYPE = 3 ;
  public final static int RACIAL_GROUP = 4 ;
  public final static int SPECIFIC_ALIGNMENT = 5 ;

  public static String nameOf(int value) {
    if (value == 2 ) return "ItemPropertyAcBonusVs.ALIGNMENT_GROUP";
    if (value == 3 ) return "ItemPropertyAcBonusVs.DAMAGE_TYPE";
    if (value == 4 ) return "ItemPropertyAcBonusVs.RACIAL_GROUP";
    if (value == 5 ) return "ItemPropertyAcBonusVs.SPECIFIC_ALIGNMENT";
    return "ItemPropertyAcBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAcBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAcBonusVs.(not found: " + value + ")";
  }
}
