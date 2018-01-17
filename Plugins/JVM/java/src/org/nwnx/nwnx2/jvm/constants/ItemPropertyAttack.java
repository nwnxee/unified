package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_ATTACK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyAttack {
  private ItemPropertyAttack() {}

  public final static int BONUS = 56 ;
  public final static int BONUS_VS_ALIGNMENT_GROUP = 57 ;
  public final static int BONUS_VS_RACIAL_GROUP = 58 ;
  public final static int BONUS_VS_SPECIFIC_ALIGNMENT = 59 ;

  public static String nameOf(int value) {
    if (value == 56 ) return "ItemPropertyAttack.BONUS";
    if (value == 57 ) return "ItemPropertyAttack.BONUS_VS_ALIGNMENT_GROUP";
    if (value == 58 ) return "ItemPropertyAttack.BONUS_VS_RACIAL_GROUP";
    if (value == 59 ) return "ItemPropertyAttack.BONUS_VS_SPECIFIC_ALIGNMENT";
    return "ItemPropertyAttack.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyAttack.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyAttack.(not found: " + value + ")";
  }
}
