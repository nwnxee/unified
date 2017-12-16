package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "IP_CONST_SPELLSCHOOL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class IpConstSpellschool {
  private IpConstSpellschool() {}

  public final static int ABJURATION = 0;
  public final static int CONJURATION = 1;
  public final static int DIVINATION = 2;
  public final static int ENCHANTMENT = 3;
  public final static int EVOCATION = 4;
  public final static int ILLUSION = 5;
  public final static int NECROMANCY = 6;
  public final static int TRANSMUTATION = 7;

  public static String nameOf(int value) {
    if (value == 0) return "IpConstSpellschool.ABJURATION";
    if (value == 1) return "IpConstSpellschool.CONJURATION";
    if (value == 2) return "IpConstSpellschool.DIVINATION";
    if (value == 3) return "IpConstSpellschool.ENCHANTMENT";
    if (value == 4) return "IpConstSpellschool.EVOCATION";
    if (value == 5) return "IpConstSpellschool.ILLUSION";
    if (value == 6) return "IpConstSpellschool.NECROMANCY";
    if (value == 7) return "IpConstSpellschool.TRANSMUTATION";
    return "IpConstSpellschool.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "IpConstSpellschool.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "IpConstSpellschool.(not found: " + value + ")";
  }
}
