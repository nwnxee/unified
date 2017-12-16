package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_AURA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityAura {
  private SpellabilityAura() {}

  public final static int BLINDING = 195;
  public final static int COLD = 196;
  public final static int ELECTRICITY = 197;
  public final static int FEAR = 198;
  public final static int FIRE = 199;
  public final static int HORRIFICAPPEARANCE = 804;
  public final static int MENACE = 200;
  public final static int OF_COURAGE = 314;
  public final static int PROTECTION = 201;
  public final static int STUN = 202;
  public final static int UNEARTHLY_VISAGE = 203;
  public final static int UNNATURAL = 204;

  public static String nameOf(int value) {
    if (value == 195) return "SpellabilityAura.BLINDING";
    if (value == 196) return "SpellabilityAura.COLD";
    if (value == 197) return "SpellabilityAura.ELECTRICITY";
    if (value == 198) return "SpellabilityAura.FEAR";
    if (value == 199) return "SpellabilityAura.FIRE";
    if (value == 804) return "SpellabilityAura.HORRIFICAPPEARANCE";
    if (value == 200) return "SpellabilityAura.MENACE";
    if (value == 314) return "SpellabilityAura.OF_COURAGE";
    if (value == 201) return "SpellabilityAura.PROTECTION";
    if (value == 202) return "SpellabilityAura.STUN";
    if (value == 203) return "SpellabilityAura.UNEARTHLY_VISAGE";
    if (value == 204) return "SpellabilityAura.UNNATURAL";
    return "SpellabilityAura.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityAura.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityAura.(not found: " + value + ")";
  }
}
