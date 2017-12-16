package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_VINE_MINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellVineMine {
  private SpellVineMine() {}

  public final static int CAMOUFLAGE = 532;
  public final static int ENTANGLE = 530;
  public final static int HAMPER_MOVEMENT = 531;
  public final static int SPELL_VINE_MINE = 529;

  public static String nameOf(int value) {
    if (value == 532) return "SpellVineMine.CAMOUFLAGE";
    if (value == 530) return "SpellVineMine.ENTANGLE";
    if (value == 531) return "SpellVineMine.HAMPER_MOVEMENT";
    if (value == 529) return "SpellVineMine.SPELL_VINE_MINE";
    return "SpellVineMine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellVineMine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellVineMine.(not found: " + value + ")";
  }
}
