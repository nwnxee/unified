package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SHADES".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellShades {
  private SpellShades() {}

  public final static int CONE_OF_COLD = 340;
  public final static int FIREBALL = 341;
  public final static int STONESKIN = 342;
  public final static int SUMMON_SHADOW = 324;
  public final static int WALL_OF_FIRE = 343;

  public static String nameOf(int value) {
    if (value == 340) return "SpellShades.CONE_OF_COLD";
    if (value == 341) return "SpellShades.FIREBALL";
    if (value == 342) return "SpellShades.STONESKIN";
    if (value == 324) return "SpellShades.SUMMON_SHADOW";
    if (value == 343) return "SpellShades.WALL_OF_FIRE";
    return "SpellShades.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellShades.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellShades.(not found: " + value + ")";
  }
}
