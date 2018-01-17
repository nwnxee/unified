package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELLABILITY_CONE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellabilityCone {
  private SpellabilityCone() {}

  public final static int ACID = 229;
  public final static int COLD = 230;
  public final static int DISEASE = 231;
  public final static int FIRE = 232;
  public final static int LIGHTNING = 233;
  public final static int POISON = 234;
  public final static int SONIC = 235;

  public static String nameOf(int value) {
    if (value == 229) return "SpellabilityCone.ACID";
    if (value == 230) return "SpellabilityCone.COLD";
    if (value == 231) return "SpellabilityCone.DISEASE";
    if (value == 232) return "SpellabilityCone.FIRE";
    if (value == 233) return "SpellabilityCone.LIGHTNING";
    if (value == 234) return "SpellabilityCone.POISON";
    if (value == 235) return "SpellabilityCone.SONIC";
    return "SpellabilityCone.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellabilityCone.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellabilityCone.(not found: " + value + ")";
  }
}
