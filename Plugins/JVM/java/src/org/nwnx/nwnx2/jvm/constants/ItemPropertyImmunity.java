package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY_IMMUNITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemPropertyImmunity {
  private ItemPropertyImmunity() {}

  public final static int DAMAGE_TYPE = 20 ;
  public final static int MISCELLANEOUS = 37 ;
  public final static int SPECIFIC_SPELL = 53 ;
  public final static int SPELLS_BY_LEVEL = 78 ;
  public final static int SPELL_SCHOOL = 54 ;

  public static String nameOf(int value) {
    if (value == 20 ) return "ItemPropertyImmunity.DAMAGE_TYPE";
    if (value == 37 ) return "ItemPropertyImmunity.MISCELLANEOUS";
    if (value == 53 ) return "ItemPropertyImmunity.SPECIFIC_SPELL";
    if (value == 78 ) return "ItemPropertyImmunity.SPELLS_BY_LEVEL";
    if (value == 54 ) return "ItemPropertyImmunity.SPELL_SCHOOL";
    return "ItemPropertyImmunity.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemPropertyImmunity.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemPropertyImmunity.(not found: " + value + ")";
  }
}
