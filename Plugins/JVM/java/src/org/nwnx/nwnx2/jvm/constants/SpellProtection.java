package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_PROTECTION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellProtection {
  private SpellProtection() {}

  public final static int FROM_ELEMENTS = 137;
  public final static int FROM_EVIL = 138;
  public final static int FROM_GOOD = 139;
  public final static int FROM_LAW = 140;
  public final static int FROM_SPELLS = 141;
  public final static int _FROM_CHAOS = 136;

  public static String nameOf(int value) {
    if (value == 137) return "SpellProtection.FROM_ELEMENTS";
    if (value == 138) return "SpellProtection.FROM_EVIL";
    if (value == 139) return "SpellProtection.FROM_GOOD";
    if (value == 140) return "SpellProtection.FROM_LAW";
    if (value == 141) return "SpellProtection.FROM_SPELLS";
    if (value == 136) return "SpellProtection._FROM_CHAOS";
    return "SpellProtection.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellProtection.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellProtection.(not found: " + value + ")";
  }
}
