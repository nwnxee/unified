package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_DAMAGE_BONUS_VS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyDamageBonusVs {
  private ItemPropertyDamageBonusVs() {}

  public final static int ALIGNMENT_GROUP = 17 ;
  public final static int RACIAL_GROUP = 18 ;
  public final static int SPECIFIC_ALIGNMENT = 19 ;

  public static String nameOf(int value) {
    if (value == 17 ) return "ItemPropertyDamageBonusVs.ALIGNMENT_GROUP";
    if (value == 18 ) return "ItemPropertyDamageBonusVs.RACIAL_GROUP";
    if (value == 19 ) return "ItemPropertyDamageBonusVs.SPECIFIC_ALIGNMENT";
    return "ItemPropertyDamageBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyDamageBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyDamageBonusVs.(not found: " + value + ")";
  }
}
