package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "EFFECT_TYPE_DAMAGE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class EffectTypeDamage {
  private EffectTypeDamage() {}

  public final static int DECREASE = 43;
  public final static int IMMUNITY_DECREASE = 45;
  public final static int IMMUNITY_INCREASE = 44;
  public final static int INCREASE = 42;
  public final static int REDUCTION = 7;
  public final static int RESISTANCE = 1;

  public static String nameOf(int value) {
    if (value == 43) return "EffectTypeDamage.DECREASE";
    if (value == 45) return "EffectTypeDamage.IMMUNITY_DECREASE";
    if (value == 44) return "EffectTypeDamage.IMMUNITY_INCREASE";
    if (value == 42) return "EffectTypeDamage.INCREASE";
    if (value == 7) return "EffectTypeDamage.REDUCTION";
    if (value == 1) return "EffectTypeDamage.RESISTANCE";
    return "EffectTypeDamage.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "EffectTypeDamage.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "EffectTypeDamage.(not found: " + value + ")";
  }
}
