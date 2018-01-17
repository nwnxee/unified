package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SUMMON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellSummon {
  private SpellSummon() {}

  public final static int CREATURE_I = 174;
  public final static int CREATURE_II = 175;
  public final static int CREATURE_III = 176;
  public final static int CREATURE_IV = 177;
  public final static int CREATURE_IX = 178;
  public final static int CREATURE_V = 179;
  public final static int CREATURE_VI = 180;
  public final static int CREATURE_VII = 181;
  public final static int CREATURE_VIII = 182;
  public final static int SHADOW = 476;

  public static String nameOf(int value) {
    if (value == 174) return "SpellSummon.CREATURE_I";
    if (value == 175) return "SpellSummon.CREATURE_II";
    if (value == 176) return "SpellSummon.CREATURE_III";
    if (value == 177) return "SpellSummon.CREATURE_IV";
    if (value == 178) return "SpellSummon.CREATURE_IX";
    if (value == 179) return "SpellSummon.CREATURE_V";
    if (value == 180) return "SpellSummon.CREATURE_VI";
    if (value == 181) return "SpellSummon.CREATURE_VII";
    if (value == 182) return "SpellSummon.CREATURE_VIII";
    if (value == 476) return "SpellSummon.SHADOW";
    return "SpellSummon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellSummon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellSummon.(not found: " + value + ")";
  }
}
