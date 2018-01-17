package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SHADOW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellShadow {
  private SpellShadow() {}

  public final static int CONJURATION_DARKNESS = 345;
  public final static int CONJURATION_INIVSIBILITY = 346;
  public final static int CONJURATION_MAGE_ARMOR = 347;
  public final static int CONJURATION_MAGIC_MISSILE = 348;
  public final static int CONJURATION_SUMMON_SHADOW = 344;
  public final static int DAZE = 475;
  public final static int EVADE = 477;
  public final static int SHIELD = 160;

  public static String nameOf(int value) {
    if (value == 345) return "SpellShadow.CONJURATION_DARKNESS";
    if (value == 346) return "SpellShadow.CONJURATION_INIVSIBILITY";
    if (value == 347) return "SpellShadow.CONJURATION_MAGE_ARMOR";
    if (value == 348) return "SpellShadow.CONJURATION_MAGIC_MISSILE";
    if (value == 344) return "SpellShadow.CONJURATION_SUMMON_SHADOW";
    if (value == 475) return "SpellShadow.DAZE";
    if (value == 477) return "SpellShadow.EVADE";
    if (value == 160) return "SpellShadow.SHIELD";
    return "SpellShadow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellShadow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellShadow.(not found: " + value + ")";
  }
}
