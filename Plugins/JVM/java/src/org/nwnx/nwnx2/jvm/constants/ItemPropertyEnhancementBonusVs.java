package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ENHANCEMENT_BONUS_VS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyEnhancementBonusVs {
  private ItemPropertyEnhancementBonusVs() {}

  public final static int ALIGNMENT_GROUP = 7 ;
  public final static int RACIAL_GROUP = 8 ;
  public final static int SPECIFIC_ALIGNEMENT = 9 ;

  public static String nameOf(int value) {
    if (value == 7 ) return "ItemPropertyEnhancementBonusVs.ALIGNMENT_GROUP";
    if (value == 8 ) return "ItemPropertyEnhancementBonusVs.RACIAL_GROUP";
    if (value == 9 ) return "ItemPropertyEnhancementBonusVs.SPECIFIC_ALIGNEMENT";
    return "ItemPropertyEnhancementBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyEnhancementBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyEnhancementBonusVs.(not found: " + value + ")";
  }
}
