package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_DECREASED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyDecreased {
  private ItemPropertyDecreased() {}

  public final static int ABILITY_SCORE = 27 ;
  public final static int AC = 28 ;
  public final static int ATTACK_MODIFIER = 60 ;
  public final static int DAMAGE = 21 ;
  public final static int ENHANCEMENT_MODIFIER = 10 ;
  public final static int SAVING_THROWS = 49 ;
  public final static int SAVING_THROWS_SPECIFIC = 50 ;
  public final static int SKILL_MODIFIER = 29 ;

  public static String nameOf(int value) {
    if (value == 27 ) return "ItemPropertyDecreased.ABILITY_SCORE";
    if (value == 28 ) return "ItemPropertyDecreased.AC";
    if (value == 60 ) return "ItemPropertyDecreased.ATTACK_MODIFIER";
    if (value == 21 ) return "ItemPropertyDecreased.DAMAGE";
    if (value == 10 ) return "ItemPropertyDecreased.ENHANCEMENT_MODIFIER";
    if (value == 49 ) return "ItemPropertyDecreased.SAVING_THROWS";
    if (value == 50 ) return "ItemPropertyDecreased.SAVING_THROWS_SPECIFIC";
    if (value == 29 ) return "ItemPropertyDecreased.SKILL_MODIFIER";
    return "ItemPropertyDecreased.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyDecreased.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyDecreased.(not found: " + value + ")";
  }
}
