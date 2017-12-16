package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_PROTECTION_FROM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellProtectionFrom {
  private SpellProtectionFrom() {}

  public final static int ELEMENTS = 137;
  public final static int EVIL = 138;
  public final static int GOOD = 139;
  public final static int LAW = 140;
  public final static int SPELLS = 141;

  public static String nameOf(int value) {
    if (value == 137) return "SpellProtectionFrom.ELEMENTS";
    if (value == 138) return "SpellProtectionFrom.EVIL";
    if (value == 139) return "SpellProtectionFrom.GOOD";
    if (value == 140) return "SpellProtectionFrom.LAW";
    if (value == 141) return "SpellProtectionFrom.SPELLS";
    return "SpellProtectionFrom.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellProtectionFrom.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellProtectionFrom.(not found: " + value + ")";
  }
}
