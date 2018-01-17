package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_GRENADE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellGrenade {
  private SpellGrenade() {}

  public final static int ACID = 469;
  public final static int CALTROPS = 471;
  public final static int CHICKEN = 470;
  public final static int CHOKING = 467;
  public final static int FIRE = 464;
  public final static int HOLY = 466;
  public final static int TANGLE = 465;
  public final static int THUNDERSTONE = 468;

  public static String nameOf(int value) {
    if (value == 469) return "SpellGrenade.ACID";
    if (value == 471) return "SpellGrenade.CALTROPS";
    if (value == 470) return "SpellGrenade.CHICKEN";
    if (value == 467) return "SpellGrenade.CHOKING";
    if (value == 464) return "SpellGrenade.FIRE";
    if (value == 466) return "SpellGrenade.HOLY";
    if (value == 465) return "SpellGrenade.TANGLE";
    if (value == 468) return "SpellGrenade.THUNDERSTONE";
    return "SpellGrenade.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellGrenade.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellGrenade.(not found: " + value + ")";
  }
}
