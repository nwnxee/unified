package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_TRAP".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellTrap {
  private SpellTrap() {}

  public final static int ARROW = 487;
  public final static int BOLT = 488;
  public final static int DART = 493;
  public final static int SHURIKEN = 494;

  public static String nameOf(int value) {
    if (value == 487) return "SpellTrap.ARROW";
    if (value == 488) return "SpellTrap.BOLT";
    if (value == 493) return "SpellTrap.DART";
    if (value == 494) return "SpellTrap.SHURIKEN";
    return "SpellTrap.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellTrap.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellTrap.(not found: " + value + ")";
  }
}
