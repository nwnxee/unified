package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_MAGIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellMagic {
  private SpellMagic() {}

  public final static int CIRCLE_AGAINST_CHAOS = 103;
  public final static int CIRCLE_AGAINST_EVIL = 104;
  public final static int CIRCLE_AGAINST_GOOD = 105;
  public final static int CIRCLE_AGAINST_LAW = 106;
  public final static int FANG = 452;
  public final static int MISSILE = 107;
  public final static int VESTMENT = 546;
  public final static int WEAPON = 544;

  public static String nameOf(int value) {
    if (value == 103) return "SpellMagic.CIRCLE_AGAINST_CHAOS";
    if (value == 104) return "SpellMagic.CIRCLE_AGAINST_EVIL";
    if (value == 105) return "SpellMagic.CIRCLE_AGAINST_GOOD";
    if (value == 106) return "SpellMagic.CIRCLE_AGAINST_LAW";
    if (value == 452) return "SpellMagic.FANG";
    if (value == 107) return "SpellMagic.MISSILE";
    if (value == 546) return "SpellMagic.VESTMENT";
    if (value == 544) return "SpellMagic.WEAPON";
    return "SpellMagic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellMagic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellMagic.(not found: " + value + ")";
  }
}
