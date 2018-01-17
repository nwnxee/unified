package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_GREATER_SHADOW".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellGreaterShadow {
  private SpellGreaterShadow() {}

  public final static int CONJURATION_ACID_ARROW = 350;
  public final static int CONJURATION_MINOR_GLOBE = 353;
  public final static int CONJURATION_MIRROR_IMAGE = 351;
  public final static int CONJURATION_SUMMON_SHADOW = 349;
  public final static int CONJURATION_WEB = 352;

  public static String nameOf(int value) {
    if (value == 350) return "SpellGreaterShadow.CONJURATION_ACID_ARROW";
    if (value == 353) return "SpellGreaterShadow.CONJURATION_MINOR_GLOBE";
    if (value == 351) return "SpellGreaterShadow.CONJURATION_MIRROR_IMAGE";
    if (value == 349) return "SpellGreaterShadow.CONJURATION_SUMMON_SHADOW";
    if (value == 352) return "SpellGreaterShadow.CONJURATION_WEB";
    return "SpellGreaterShadow.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellGreaterShadow.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellGreaterShadow.(not found: " + value + ")";
  }
}
