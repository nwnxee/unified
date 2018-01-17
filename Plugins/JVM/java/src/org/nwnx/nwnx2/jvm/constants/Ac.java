package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class Ac {
  private Ac() {}

  public final static int ARMOUR_ENCHANTMENT_BONUS = 2;
  public final static int DEFLECTION_BONUS = 4;
  public final static int DODGE_BONUS = 0;
  public final static int NATURAL_BONUS = 1;
  public final static int SHIELD_ENCHANTMENT_BONUS = 3;
  public final static int VS_DAMAGE_TYPE_ALL = 4103;

  public static String nameOf(int value) {
    if (value == 2) return "Ac.ARMOUR_ENCHANTMENT_BONUS";
    if (value == 4) return "Ac.DEFLECTION_BONUS";
    if (value == 0) return "Ac.DODGE_BONUS";
    if (value == 1) return "Ac.NATURAL_BONUS";
    if (value == 3) return "Ac.SHIELD_ENCHANTMENT_BONUS";
    if (value == 4103) return "Ac.VS_DAMAGE_TYPE_ALL";
    return "Ac.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "Ac.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "Ac.(not found: " + value + ")";
  }
}
