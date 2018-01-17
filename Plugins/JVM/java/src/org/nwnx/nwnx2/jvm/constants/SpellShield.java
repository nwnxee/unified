package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SHIELD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellShield {
  private SpellShield() {}

  public final static int OF_FAITH = 450;
  public final static int OF_LAW = 162;
  public final static int SPELL_SHIELD = 417;

  public static String nameOf(int value) {
    if (value == 450) return "SpellShield.OF_FAITH";
    if (value == 162) return "SpellShield.OF_LAW";
    if (value == 417) return "SpellShield.SPELL_SHIELD";
    return "SpellShield.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellShield.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellShield.(not found: " + value + ")";
  }
}
