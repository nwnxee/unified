package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_MASS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellMass {
  private SpellMass() {}

  public final static int BLINDNESS_AND_DEAFNESS = 110;
  public final static int CAMOFLAGE = 455;
  public final static int CHARM = 111;
  public final static int HASTE = 113;
  public final static int HEAL = 114;

  public static String nameOf(int value) {
    if (value == 110) return "SpellMass.BLINDNESS_AND_DEAFNESS";
    if (value == 455) return "SpellMass.CAMOFLAGE";
    if (value == 111) return "SpellMass.CHARM";
    if (value == 113) return "SpellMass.HASTE";
    if (value == 114) return "SpellMass.HEAL";
    return "SpellMass.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellMass.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellMass.(not found: " + value + ")";
  }
}
