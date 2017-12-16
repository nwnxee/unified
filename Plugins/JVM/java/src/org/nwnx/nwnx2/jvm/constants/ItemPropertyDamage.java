package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_DAMAGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyDamage {
  private ItemPropertyDamage() {}

  public final static int BONUS = 16 ;
  public final static int BONUS_VS_ALIGNMENT_GROUP = 17 ;
  public final static int BONUS_VS_RACIAL_GROUP = 18 ;
  public final static int BONUS_VS_SPECIFIC_ALIGNMENT = 19 ;
  public final static int REDUCTION = 22 ;
  public final static int RESISTANCE = 23 ;
  public final static int VULNERABILITY = 24 ;

  public static String nameOf(int value) {
    if (value == 16 ) return "ItemPropertyDamage.BONUS";
    if (value == 17 ) return "ItemPropertyDamage.BONUS_VS_ALIGNMENT_GROUP";
    if (value == 18 ) return "ItemPropertyDamage.BONUS_VS_RACIAL_GROUP";
    if (value == 19 ) return "ItemPropertyDamage.BONUS_VS_SPECIFIC_ALIGNMENT";
    if (value == 22 ) return "ItemPropertyDamage.REDUCTION";
    if (value == 23 ) return "ItemPropertyDamage.RESISTANCE";
    if (value == 24 ) return "ItemPropertyDamage.VULNERABILITY";
    return "ItemPropertyDamage.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyDamage.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyDamage.(not found: " + value + ")";
  }
}
