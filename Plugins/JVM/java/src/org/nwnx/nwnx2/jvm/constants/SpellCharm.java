package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_CHARM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellCharm {
  private SpellCharm() {}

  public final static int MONSTER = 15;
  public final static int PERSON = 16;
  public final static int PERSON_OR_ANIMAL = 17;

  public static String nameOf(int value) {
    if (value == 15) return "SpellCharm.MONSTER";
    if (value == 16) return "SpellCharm.PERSON";
    if (value == 17) return "SpellCharm.PERSON_OR_ANIMAL";
    return "SpellCharm.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellCharm.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellCharm.(not found: " + value + ")";
  }
}
