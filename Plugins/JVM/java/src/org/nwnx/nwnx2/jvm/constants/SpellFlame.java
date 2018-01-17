package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_FLAME".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellFlame {
  private SpellFlame() {}

  public final static int ARROW = 59;
  public final static int LASH = 60;
  public final static int STRIKE = 61;
  public final static int WEAPON = 542;

  public static String nameOf(int value) {
    if (value == 59) return "SpellFlame.ARROW";
    if (value == 60) return "SpellFlame.LASH";
    if (value == 61) return "SpellFlame.STRIKE";
    if (value == 542) return "SpellFlame.WEAPON";
    return "SpellFlame.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellFlame.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellFlame.(not found: " + value + ")";
  }
}
