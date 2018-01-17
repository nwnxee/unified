package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EFFECT_TYPE_SPELL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EffectTypeSpell {
  private EffectTypeSpell() {}

  public final static int FAILURE = 82;
  public final static int IMMUNITY = 73;
  public final static int RESISTANCE_DECREASE = 53;
  public final static int RESISTANCE_INCREASE = 52;

  public static String nameOf(int value) {
    if (value == 82) return "EffectTypeSpell.FAILURE";
    if (value == 73) return "EffectTypeSpell.IMMUNITY";
    if (value == 53) return "EffectTypeSpell.RESISTANCE_DECREASE";
    if (value == 52) return "EffectTypeSpell.RESISTANCE_INCREASE";
    return "EffectTypeSpell.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EffectTypeSpell.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EffectTypeSpell.(not found: " + value + ")";
  }
}
