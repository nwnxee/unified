package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_DOMINATE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellDominate {
  private SpellDominate() {}

  public final static int ANIMAL = 43;
  public final static int MONSTER = 44;
  public final static int PERSON = 45;

  public static String nameOf(int value) {
    if (value == 43) return "SpellDominate.ANIMAL";
    if (value == 44) return "SpellDominate.MONSTER";
    if (value == 45) return "SpellDominate.PERSON";
    return "SpellDominate.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellDominate.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellDominate.(not found: " + value + ")";
  }
}
