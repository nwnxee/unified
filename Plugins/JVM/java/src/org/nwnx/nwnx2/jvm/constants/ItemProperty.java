package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "ITEM_PROPERTY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class ItemProperty {
  private ItemProperty() {}

  public final static int ABILITY_BONUS = 0 ;
  public final static int AC_BONUS = 1 ;
  public final static int AC_BONUS_VS_ALIGNMENT_GROUP = 2 ;
  public final static int AC_BONUS_VS_DAMAGE_TYPE = 3 ;
  public final static int AC_BONUS_VS_RACIAL_GROUP = 4 ;
  public final static int AC_BONUS_VS_SPECIFIC_ALIGNMENT = 5 ;
  public final static int ADDITIONAL = 87;
  public final static int ARCANE_SPELL_FAILURE = 84;
  public final static int ATTACK_BONUS = 56 ;
  public final static int ATTACK_BONUS_VS_ALIGNMENT_GROUP = 57 ;
  public final static int ATTACK_BONUS_VS_RACIAL_GROUP = 58 ;
  public final static int ATTACK_BONUS_VS_SPECIFIC_ALIGNMENT = 59 ;
  public final static int BASE_ITEM_WEIGHT_REDUCTION = 11 ;
  public final static int BONUS_FEAT = 12 ;
  public final static int BONUS_SPELL_SLOT_OF_LEVEL_N = 13 ;
  public final static int CAST_SPELL = 15 ;
  public final static int DAMAGE_BONUS = 16 ;
  public final static int DAMAGE_BONUS_VS_ALIGNMENT_GROUP = 17 ;
  public final static int DAMAGE_BONUS_VS_RACIAL_GROUP = 18 ;
  public final static int DAMAGE_BONUS_VS_SPECIFIC_ALIGNMENT = 19 ;
  public final static int DAMAGE_REDUCTION = 22 ;
  public final static int DAMAGE_RESISTANCE = 23 ;
  public final static int DAMAGE_VULNERABILITY = 24 ;
  public final static int DARKVISION = 26 ;
  public final static int DECREASED_ABILITY_SCORE = 27 ;
  public final static int DECREASED_AC = 28 ;
  public final static int DECREASED_ATTACK_MODIFIER = 60 ;
  public final static int DECREASED_DAMAGE = 21 ;
  public final static int DECREASED_ENHANCEMENT_MODIFIER = 10 ;
  public final static int DECREASED_SAVING_THROWS = 49 ;
  public final static int DECREASED_SAVING_THROWS_SPECIFIC = 50 ;
  public final static int DECREASED_SKILL_MODIFIER = 29 ;
  public final static int ENHANCED_CONTAINER_REDUCED_WEIGHT = 32 ;
  public final static int ENHANCEMENT_BONUS = 6 ;
  public final static int ENHANCEMENT_BONUS_VS_ALIGNMENT_GROUP = 7 ;
  public final static int ENHANCEMENT_BONUS_VS_RACIAL_GROUP = 8 ;
  public final static int ENHANCEMENT_BONUS_VS_SPECIFIC_ALIGNEMENT = 9 ;
  public final static int EXTRA_MELEE_DAMAGE_TYPE = 33 ;
  public final static int EXTRA_RANGED_DAMAGE_TYPE = 34 ;
  public final static int FREEDOM_OF_MOVEMENT = 75 ;
  public final static int HASTE = 35 ;
  public final static int HEALERS_KIT = 80;
  public final static int HOLY_AVENGER = 36 ;
  public final static int IMMUNITY_DAMAGE_TYPE = 20 ;
  public final static int IMMUNITY_MISCELLANEOUS = 37 ;
  public final static int IMMUNITY_SPECIFIC_SPELL = 53 ;
  public final static int IMMUNITY_SPELLS_BY_LEVEL = 78 ;
  public final static int IMMUNITY_SPELL_SCHOOL = 54 ;
  public final static int IMPROVED_EVASION = 38 ;
  public final static int KEEN = 43 ;
  public final static int LIGHT = 44 ;
  public final static int MASSIVE_CRITICALS = 74 ;
  public final static int MATERIAL = 85;
  public final static int MIGHTY = 45 ;
  public final static int MIND_BLANK = 46 ;
  public final static int MONSTER_DAMAGE = 77 ;
  public final static int NO_DAMAGE = 47 ;
  public final static int ONHITCASTSPELL = 82;
  public final static int ON_HIT_PROPERTIES = 48 ;
  public final static int ON_MONSTER_HIT = 72 ;
  public final static int POISON = 76 ;
  public final static int QUALITY = 86;
  public final static int REGENERATION = 51 ;
  public final static int REGENERATION_VAMPIRIC = 67 ;
  public final static int SAVING_THROW_BONUS = 40 ;
  public final static int SAVING_THROW_BONUS_SPECIFIC = 41 ;
  public final static int SKILL_BONUS = 52 ;
  public final static int SPECIAL_WALK = 79;
  public final static int SPELL_RESISTANCE = 39 ;
  public final static int THIEVES_TOOLS = 55 ;
  public final static int TRAP = 70 ;
  public final static int TRUE_SEEING = 71 ;
  public final static int TURN_RESISTANCE = 73 ;
  public final static int UNLIMITED_AMMUNITION = 61 ;
  public final static int USE_LIMITATION_ALIGNMENT_GROUP = 62 ;
  public final static int USE_LIMITATION_CLASS = 63 ;
  public final static int USE_LIMITATION_RACIAL_TYPE = 64 ;
  public final static int USE_LIMITATION_SPECIFIC_ALIGNMENT = 65 ;
  public final static int USE_LIMITATION_TILESET = 66 ;
  public final static int VISUALEFFECT = 83;
  public final static int WEIGHT_INCREASE = 81;

  public static String nameOf(int value) {
    if (value == 0 ) return "ItemProperty.ABILITY_BONUS";
    if (value == 1 ) return "ItemProperty.AC_BONUS";
    if (value == 2 ) return "ItemProperty.AC_BONUS_VS_ALIGNMENT_GROUP";
    if (value == 3 ) return "ItemProperty.AC_BONUS_VS_DAMAGE_TYPE";
    if (value == 4 ) return "ItemProperty.AC_BONUS_VS_RACIAL_GROUP";
    if (value == 5 ) return "ItemProperty.AC_BONUS_VS_SPECIFIC_ALIGNMENT";
    if (value == 87) return "ItemProperty.ADDITIONAL";
    if (value == 84) return "ItemProperty.ARCANE_SPELL_FAILURE";
    if (value == 56 ) return "ItemProperty.ATTACK_BONUS";
    if (value == 57 ) return "ItemProperty.ATTACK_BONUS_VS_ALIGNMENT_GROUP";
    if (value == 58 ) return "ItemProperty.ATTACK_BONUS_VS_RACIAL_GROUP";
    if (value == 59 ) return "ItemProperty.ATTACK_BONUS_VS_SPECIFIC_ALIGNMENT";
    if (value == 11 ) return "ItemProperty.BASE_ITEM_WEIGHT_REDUCTION";
    if (value == 12 ) return "ItemProperty.BONUS_FEAT";
    if (value == 13 ) return "ItemProperty.BONUS_SPELL_SLOT_OF_LEVEL_N";
    if (value == 15 ) return "ItemProperty.CAST_SPELL";
    if (value == 16 ) return "ItemProperty.DAMAGE_BONUS";
    if (value == 17 ) return "ItemProperty.DAMAGE_BONUS_VS_ALIGNMENT_GROUP";
    if (value == 18 ) return "ItemProperty.DAMAGE_BONUS_VS_RACIAL_GROUP";
    if (value == 19 ) return "ItemProperty.DAMAGE_BONUS_VS_SPECIFIC_ALIGNMENT";
    if (value == 22 ) return "ItemProperty.DAMAGE_REDUCTION";
    if (value == 23 ) return "ItemProperty.DAMAGE_RESISTANCE";
    if (value == 24 ) return "ItemProperty.DAMAGE_VULNERABILITY";
    if (value == 26 ) return "ItemProperty.DARKVISION";
    if (value == 27 ) return "ItemProperty.DECREASED_ABILITY_SCORE";
    if (value == 28 ) return "ItemProperty.DECREASED_AC";
    if (value == 60 ) return "ItemProperty.DECREASED_ATTACK_MODIFIER";
    if (value == 21 ) return "ItemProperty.DECREASED_DAMAGE";
    if (value == 10 ) return "ItemProperty.DECREASED_ENHANCEMENT_MODIFIER";
    if (value == 49 ) return "ItemProperty.DECREASED_SAVING_THROWS";
    if (value == 50 ) return "ItemProperty.DECREASED_SAVING_THROWS_SPECIFIC";
    if (value == 29 ) return "ItemProperty.DECREASED_SKILL_MODIFIER";
    if (value == 32 ) return "ItemProperty.ENHANCED_CONTAINER_REDUCED_WEIGHT";
    if (value == 6 ) return "ItemProperty.ENHANCEMENT_BONUS";
    if (value == 7 ) return "ItemProperty.ENHANCEMENT_BONUS_VS_ALIGNMENT_GROUP";
    if (value == 8 ) return "ItemProperty.ENHANCEMENT_BONUS_VS_RACIAL_GROUP";
    if (value == 9 ) return "ItemProperty.ENHANCEMENT_BONUS_VS_SPECIFIC_ALIGNEMENT";
    if (value == 33 ) return "ItemProperty.EXTRA_MELEE_DAMAGE_TYPE";
    if (value == 34 ) return "ItemProperty.EXTRA_RANGED_DAMAGE_TYPE";
    if (value == 75 ) return "ItemProperty.FREEDOM_OF_MOVEMENT";
    if (value == 35 ) return "ItemProperty.HASTE";
    if (value == 80) return "ItemProperty.HEALERS_KIT";
    if (value == 36 ) return "ItemProperty.HOLY_AVENGER";
    if (value == 20 ) return "ItemProperty.IMMUNITY_DAMAGE_TYPE";
    if (value == 37 ) return "ItemProperty.IMMUNITY_MISCELLANEOUS";
    if (value == 53 ) return "ItemProperty.IMMUNITY_SPECIFIC_SPELL";
    if (value == 78 ) return "ItemProperty.IMMUNITY_SPELLS_BY_LEVEL";
    if (value == 54 ) return "ItemProperty.IMMUNITY_SPELL_SCHOOL";
    if (value == 38 ) return "ItemProperty.IMPROVED_EVASION";
    if (value == 43 ) return "ItemProperty.KEEN";
    if (value == 44 ) return "ItemProperty.LIGHT";
    if (value == 74 ) return "ItemProperty.MASSIVE_CRITICALS";
    if (value == 85) return "ItemProperty.MATERIAL";
    if (value == 45 ) return "ItemProperty.MIGHTY";
    if (value == 46 ) return "ItemProperty.MIND_BLANK";
    if (value == 77 ) return "ItemProperty.MONSTER_DAMAGE";
    if (value == 47 ) return "ItemProperty.NO_DAMAGE";
    if (value == 82) return "ItemProperty.ONHITCASTSPELL";
    if (value == 48 ) return "ItemProperty.ON_HIT_PROPERTIES";
    if (value == 72 ) return "ItemProperty.ON_MONSTER_HIT";
    if (value == 76 ) return "ItemProperty.POISON";
    if (value == 86) return "ItemProperty.QUALITY";
    if (value == 51 ) return "ItemProperty.REGENERATION";
    if (value == 67 ) return "ItemProperty.REGENERATION_VAMPIRIC";
    if (value == 40 ) return "ItemProperty.SAVING_THROW_BONUS";
    if (value == 41 ) return "ItemProperty.SAVING_THROW_BONUS_SPECIFIC";
    if (value == 52 ) return "ItemProperty.SKILL_BONUS";
    if (value == 79) return "ItemProperty.SPECIAL_WALK";
    if (value == 39 ) return "ItemProperty.SPELL_RESISTANCE";
    if (value == 55 ) return "ItemProperty.THIEVES_TOOLS";
    if (value == 70 ) return "ItemProperty.TRAP";
    if (value == 71 ) return "ItemProperty.TRUE_SEEING";
    if (value == 73 ) return "ItemProperty.TURN_RESISTANCE";
    if (value == 61 ) return "ItemProperty.UNLIMITED_AMMUNITION";
    if (value == 62 ) return "ItemProperty.USE_LIMITATION_ALIGNMENT_GROUP";
    if (value == 63 ) return "ItemProperty.USE_LIMITATION_CLASS";
    if (value == 64 ) return "ItemProperty.USE_LIMITATION_RACIAL_TYPE";
    if (value == 65 ) return "ItemProperty.USE_LIMITATION_SPECIFIC_ALIGNMENT";
    if (value == 66 ) return "ItemProperty.USE_LIMITATION_TILESET";
    if (value == 83) return "ItemProperty.VISUALEFFECT";
    if (value == 81) return "ItemProperty.WEIGHT_INCREASE";
    return "ItemProperty.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "ItemProperty.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "ItemProperty.(not found: " + value + ")";
  }
}
