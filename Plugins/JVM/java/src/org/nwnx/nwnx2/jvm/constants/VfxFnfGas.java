package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_FNF_GAS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxFnfGas {
  private VfxFnfGas() {}

  public final static int EXPLOSION_ACID = 257;
  public final static int EXPLOSION_EVIL = 258;
  public final static int EXPLOSION_FIRE = 260;
  public final static int EXPLOSION_GREASE = 261;
  public final static int EXPLOSION_MIND = 262;
  public final static int EXPLOSION_NATURE = 259;

  public static String nameOf(int value) {
    if (value == 257) return "VfxFnfGas.EXPLOSION_ACID";
    if (value == 258) return "VfxFnfGas.EXPLOSION_EVIL";
    if (value == 260) return "VfxFnfGas.EXPLOSION_FIRE";
    if (value == 261) return "VfxFnfGas.EXPLOSION_GREASE";
    if (value == 262) return "VfxFnfGas.EXPLOSION_MIND";
    if (value == 259) return "VfxFnfGas.EXPLOSION_NATURE";
    return "VfxFnfGas.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxFnfGas.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxFnfGas.(not found: " + value + ")";
  }
}
