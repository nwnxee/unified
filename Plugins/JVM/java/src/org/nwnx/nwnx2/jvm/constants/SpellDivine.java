package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_DIVINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellDivine {
  private SpellDivine() {}

  public final static int FAVOR = 414;
  public final static int MIGHT = 473;
  public final static int POWER = 42;
  public final static int SHIELD = 474;

  public static String nameOf(int value) {
    if (value == 414) return "SpellDivine.FAVOR";
    if (value == 473) return "SpellDivine.MIGHT";
    if (value == 42) return "SpellDivine.POWER";
    if (value == 474) return "SpellDivine.SHIELD";
    return "SpellDivine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellDivine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellDivine.(not found: " + value + ")";
  }
}
