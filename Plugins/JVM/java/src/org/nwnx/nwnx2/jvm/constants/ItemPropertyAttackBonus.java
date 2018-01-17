package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ATTACK_BONUS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAttackBonus {
  private ItemPropertyAttackBonus() {}

  public final static int ITEM_PROPERTY_ATTACK_BONUS = 56 ;
  public final static int VS_ALIGNMENT_GROUP = 57 ;
  public final static int VS_RACIAL_GROUP = 58 ;
  public final static int VS_SPECIFIC_ALIGNMENT = 59 ;

  public static String nameOf(int value) {
    if (value == 56 ) return "ItemPropertyAttackBonus.ITEM_PROPERTY_ATTACK_BONUS";
    if (value == 57 ) return "ItemPropertyAttackBonus.VS_ALIGNMENT_GROUP";
    if (value == 58 ) return "ItemPropertyAttackBonus.VS_RACIAL_GROUP";
    if (value == 59 ) return "ItemPropertyAttackBonus.VS_SPECIFIC_ALIGNMENT";
    return "ItemPropertyAttackBonus.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAttackBonus.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAttackBonus.(not found: " + value + ")";
  }
}
