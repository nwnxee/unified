package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "SPELL_SUMMON_CREATURE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class SpellSummonCreature {
  private SpellSummonCreature() {}

  public final static int I = 174;
  public final static int II = 175;
  public final static int III = 176;
  public final static int IV = 177;
  public final static int IX = 178;
  public final static int V = 179;
  public final static int VI = 180;
  public final static int VII = 181;
  public final static int VIII = 182;

  public static String nameOf(int value) {
    if (value == 174) return "SpellSummonCreature.I";
    if (value == 175) return "SpellSummonCreature.II";
    if (value == 176) return "SpellSummonCreature.III";
    if (value == 177) return "SpellSummonCreature.IV";
    if (value == 178) return "SpellSummonCreature.IX";
    if (value == 179) return "SpellSummonCreature.V";
    if (value == 180) return "SpellSummonCreature.VI";
    if (value == 181) return "SpellSummonCreature.VII";
    if (value == 182) return "SpellSummonCreature.VIII";
    return "SpellSummonCreature.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "SpellSummonCreature.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "SpellSummonCreature.(not found: " + value + ")";
  }
}
