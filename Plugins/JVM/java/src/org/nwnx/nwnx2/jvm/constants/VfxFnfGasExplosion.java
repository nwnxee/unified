package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_GAS_EXPLOSION".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfGasExplosion {
  private VfxFnfGasExplosion() {}

  public final static int ACID = 257;
  public final static int EVIL = 258;
  public final static int FIRE = 260;
  public final static int GREASE = 261;
  public final static int MIND = 262;
  public final static int NATURE = 259;

  public static String nameOf(int value) {
    if (value == 257) return "VfxFnfGasExplosion.ACID";
    if (value == 258) return "VfxFnfGasExplosion.EVIL";
    if (value == 260) return "VfxFnfGasExplosion.FIRE";
    if (value == 261) return "VfxFnfGasExplosion.GREASE";
    if (value == 262) return "VfxFnfGasExplosion.MIND";
    if (value == 259) return "VfxFnfGasExplosion.NATURE";
    return "VfxFnfGasExplosion.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfGasExplosion.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfGasExplosion.(not found: " + value + ")";
  }
}
