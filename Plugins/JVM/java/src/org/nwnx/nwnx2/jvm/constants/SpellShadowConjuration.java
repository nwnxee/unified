package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SHADOW_CONJURATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellShadowConjuration {
  private SpellShadowConjuration() {}

  public final static int DARKNESS = 345;
  public final static int INIVSIBILITY = 346;
  public final static int MAGE_ARMOR = 347;
  public final static int MAGIC_MISSILE = 348;
  public final static int SUMMON_SHADOW = 344;

  public static String nameOf(int value) {
    if (value == 345) return "SpellShadowConjuration.DARKNESS";
    if (value == 346) return "SpellShadowConjuration.INIVSIBILITY";
    if (value == 347) return "SpellShadowConjuration.MAGE_ARMOR";
    if (value == 348) return "SpellShadowConjuration.MAGIC_MISSILE";
    if (value == 344) return "SpellShadowConjuration.SUMMON_SHADOW";
    return "SpellShadowConjuration.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellShadowConjuration.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellShadowConjuration.(not found: " + value + ")";
  }
}
