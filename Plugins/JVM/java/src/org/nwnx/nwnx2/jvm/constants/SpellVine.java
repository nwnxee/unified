package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_VINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellVine {
  private SpellVine() {}

  public final static int MINE = 529;
  public final static int MINE_CAMOUFLAGE = 532;
  public final static int MINE_ENTANGLE = 530;
  public final static int MINE_HAMPER_MOVEMENT = 531;

  public static String nameOf(int value) {
    if (value == 529) return "SpellVine.MINE";
    if (value == 532) return "SpellVine.MINE_CAMOUFLAGE";
    if (value == 530) return "SpellVine.MINE_ENTANGLE";
    if (value == 531) return "SpellVine.MINE_HAMPER_MOVEMENT";
    return "SpellVine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellVine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellVine.(not found: " + value + ")";
  }
}
