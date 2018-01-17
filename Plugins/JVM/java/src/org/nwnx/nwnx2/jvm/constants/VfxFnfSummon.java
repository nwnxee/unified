package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_SUMMON".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfSummon {
  private VfxFnfSummon() {}

  public final static int CELESTIAL = 219;
  public final static int EPIC_UNDEAD = 496;
  public final static int GATE = 32 ;
  public final static int MONSTER_1 = 33 ;
  public final static int MONSTER_2 = 34 ;
  public final static int MONSTER_3 = 35 ;
  public final static int UNDEAD = 36 ;

  public static String nameOf(int value) {
    if (value == 219) return "VfxFnfSummon.CELESTIAL";
    if (value == 496) return "VfxFnfSummon.EPIC_UNDEAD";
    if (value == 32 ) return "VfxFnfSummon.GATE";
    if (value == 33 ) return "VfxFnfSummon.MONSTER_1";
    if (value == 34 ) return "VfxFnfSummon.MONSTER_2";
    if (value == 35 ) return "VfxFnfSummon.MONSTER_3";
    if (value == 36 ) return "VfxFnfSummon.UNDEAD";
    return "VfxFnfSummon.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfSummon.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfSummon.(not found: " + value + ")";
  }
}
