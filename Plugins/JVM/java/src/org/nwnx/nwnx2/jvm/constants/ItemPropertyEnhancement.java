package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ENHANCEMENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyEnhancement {
  private ItemPropertyEnhancement() {}

  public final static int BONUS = 6 ;
  public final static int BONUS_VS_ALIGNMENT_GROUP = 7 ;
  public final static int BONUS_VS_RACIAL_GROUP = 8 ;
  public final static int BONUS_VS_SPECIFIC_ALIGNEMENT = 9 ;

  public static String nameOf(int value) {
    if (value == 6 ) return "ItemPropertyEnhancement.BONUS";
    if (value == 7 ) return "ItemPropertyEnhancement.BONUS_VS_ALIGNMENT_GROUP";
    if (value == 8 ) return "ItemPropertyEnhancement.BONUS_VS_RACIAL_GROUP";
    if (value == 9 ) return "ItemPropertyEnhancement.BONUS_VS_SPECIFIC_ALIGNEMENT";
    return "ItemPropertyEnhancement.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyEnhancement.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyEnhancement.(not found: " + value + ")";
  }
}
