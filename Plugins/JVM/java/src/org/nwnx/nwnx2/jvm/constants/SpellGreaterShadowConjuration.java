package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_GREATER_SHADOW_CONJURATION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellGreaterShadowConjuration {
  private SpellGreaterShadowConjuration() {}

  public final static int ACID_ARROW = 350;
  public final static int MINOR_GLOBE = 353;
  public final static int MIRROR_IMAGE = 351;
  public final static int SUMMON_SHADOW = 349;
  public final static int WEB = 352;

  public static String nameOf(int value) {
    if (value == 350) return "SpellGreaterShadowConjuration.ACID_ARROW";
    if (value == 353) return "SpellGreaterShadowConjuration.MINOR_GLOBE";
    if (value == 351) return "SpellGreaterShadowConjuration.MIRROR_IMAGE";
    if (value == 349) return "SpellGreaterShadowConjuration.SUMMON_SHADOW";
    if (value == 352) return "SpellGreaterShadowConjuration.WEB";
    return "SpellGreaterShadowConjuration.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellGreaterShadowConjuration.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellGreaterShadowConjuration.(not found: " + value + ")";
  }
}
