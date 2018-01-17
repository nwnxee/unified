package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ENHANCEMENT_BONUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyEnhancementBonus {
  private ItemPropertyEnhancementBonus() {}

  public final static int ITEM_PROPERTY_ENHANCEMENT_BONUS = 6 ;
  public final static int VS_ALIGNMENT_GROUP = 7 ;
  public final static int VS_RACIAL_GROUP = 8 ;
  public final static int VS_SPECIFIC_ALIGNEMENT = 9 ;

  public static String nameOf(int value) {
    if (value == 6 ) return "ItemPropertyEnhancementBonus.ITEM_PROPERTY_ENHANCEMENT_BONUS";
    if (value == 7 ) return "ItemPropertyEnhancementBonus.VS_ALIGNMENT_GROUP";
    if (value == 8 ) return "ItemPropertyEnhancementBonus.VS_RACIAL_GROUP";
    if (value == 9 ) return "ItemPropertyEnhancementBonus.VS_SPECIFIC_ALIGNEMENT";
    return "ItemPropertyEnhancementBonus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyEnhancementBonus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyEnhancementBonus.(not found: " + value + ")";
  }
}
