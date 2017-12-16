package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_HOLD".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellHold {
  private SpellHold() {}

  public final static int ANIMAL = 81;
  public final static int MONSTER = 82;
  public final static int PERSON = 83;

  public static String nameOf(int value) {
    if (value == 81) return "SpellHold.ANIMAL";
    if (value == 82) return "SpellHold.MONSTER";
    if (value == 83) return "SpellHold.PERSON";
    return "SpellHold.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellHold.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellHold.(not found: " + value + ")";
  }
}
