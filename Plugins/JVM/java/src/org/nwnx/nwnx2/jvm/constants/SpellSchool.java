package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SCHOOL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellSchool {
  private SpellSchool() {}

  public final static int ABJURATION = 1;
  public final static int CONJURATION = 2;
  public final static int DIVINATION = 3;
  public final static int ENCHANTMENT = 4;
  public final static int EVOCATION = 5;
  public final static int GENERAL = 0;
  public final static int ILLUSION = 6;
  public final static int NECROMANCY = 7;
  public final static int TRANSMUTATION = 8;

  public static String nameOf(int value) {
    if (value == 1) return "SpellSchool.ABJURATION";
    if (value == 2) return "SpellSchool.CONJURATION";
    if (value == 3) return "SpellSchool.DIVINATION";
    if (value == 4) return "SpellSchool.ENCHANTMENT";
    if (value == 5) return "SpellSchool.EVOCATION";
    if (value == 0) return "SpellSchool.GENERAL";
    if (value == 6) return "SpellSchool.ILLUSION";
    if (value == 7) return "SpellSchool.NECROMANCY";
    if (value == 8) return "SpellSchool.TRANSMUTATION";
    return "SpellSchool.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellSchool.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellSchool.(not found: " + value + ")";
  }
}
