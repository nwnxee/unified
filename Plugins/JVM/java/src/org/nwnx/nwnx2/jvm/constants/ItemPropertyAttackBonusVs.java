package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ATTACK_BONUS_VS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAttackBonusVs {
  private ItemPropertyAttackBonusVs() {}

  public final static int ALIGNMENT_GROUP = 57 ;
  public final static int RACIAL_GROUP = 58 ;
  public final static int SPECIFIC_ALIGNMENT = 59 ;

  public static String nameOf(int value) {
    if (value == 57 ) return "ItemPropertyAttackBonusVs.ALIGNMENT_GROUP";
    if (value == 58 ) return "ItemPropertyAttackBonusVs.RACIAL_GROUP";
    if (value == 59 ) return "ItemPropertyAttackBonusVs.SPECIFIC_ALIGNMENT";
    return "ItemPropertyAttackBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAttackBonusVs.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAttackBonusVs.(not found: " + value + ")";
  }
}
