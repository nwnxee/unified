package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_DECK".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellDeck {
  private SpellDeck() {}

  public final static int AVATAR = 503;
  public final static int BUTTERFLYSPRAY = 505;
  public final static int GEMSPRAY = 504;
  public final static int OF_MANY_THINGS = 500;

  public static String nameOf(int value) {
    if (value == 503) return "SpellDeck.AVATAR";
    if (value == 505) return "SpellDeck.BUTTERFLYSPRAY";
    if (value == 504) return "SpellDeck.GEMSPRAY";
    if (value == 500) return "SpellDeck.OF_MANY_THINGS";
    return "SpellDeck.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellDeck.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellDeck.(not found: " + value + ")";
  }
}
