package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_GREATER".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellGreater {
  private SpellGreater() {}

  public final static int BULLS_STRENGTH = 360;
  public final static int CATS_GRACE = 361;
  public final static int DISPELLING = 67;
  public final static int EAGLE_SPLENDOR = 357;
  public final static int ENDURANCE = 362;
  public final static int FOXS_CUNNING = 359;
  public final static int MAGIC_FANG = 453;
  public final static int MAGIC_WEAPON = 545;
  public final static int OWLS_WISDOM = 358;
  public final static int PLANAR_BINDING = 69;
  public final static int RESTORATION = 70;
  public final static int SHADOW_CONJURATION_ACID_ARROW = 350;
  public final static int SHADOW_CONJURATION_MINOR_GLOBE = 353;
  public final static int SHADOW_CONJURATION_MIRROR_IMAGE = 351;
  public final static int SHADOW_CONJURATION_SUMMON_SHADOW = 349;
  public final static int SHADOW_CONJURATION_WEB = 352;
  public final static int SPELL_BREACH = 72;
  public final static int SPELL_MANTLE = 73;
  public final static int STONESKIN = 74;

  public static String nameOf(int value) {
    if (value == 360) return "SpellGreater.BULLS_STRENGTH";
    if (value == 361) return "SpellGreater.CATS_GRACE";
    if (value == 67) return "SpellGreater.DISPELLING";
    if (value == 357) return "SpellGreater.EAGLE_SPLENDOR";
    if (value == 362) return "SpellGreater.ENDURANCE";
    if (value == 359) return "SpellGreater.FOXS_CUNNING";
    if (value == 453) return "SpellGreater.MAGIC_FANG";
    if (value == 545) return "SpellGreater.MAGIC_WEAPON";
    if (value == 358) return "SpellGreater.OWLS_WISDOM";
    if (value == 69) return "SpellGreater.PLANAR_BINDING";
    if (value == 70) return "SpellGreater.RESTORATION";
    if (value == 350) return "SpellGreater.SHADOW_CONJURATION_ACID_ARROW";
    if (value == 353) return "SpellGreater.SHADOW_CONJURATION_MINOR_GLOBE";
    if (value == 351) return "SpellGreater.SHADOW_CONJURATION_MIRROR_IMAGE";
    if (value == 349) return "SpellGreater.SHADOW_CONJURATION_SUMMON_SHADOW";
    if (value == 352) return "SpellGreater.SHADOW_CONJURATION_WEB";
    if (value == 72) return "SpellGreater.SPELL_BREACH";
    if (value == 73) return "SpellGreater.SPELL_MANTLE";
    if (value == 74) return "SpellGreater.STONESKIN";
    return "SpellGreater.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellGreater.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellGreater.(not found: " + value + ")";
  }
}
