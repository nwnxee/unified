package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_PULSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpPulse {
  private VfxImpPulse() {}

  public final static int COLD = 86 ;
  public final static int FIRE = 87 ;
  public final static int HOLY = 88 ;
  public final static int HOLY_SILENT = 461;
  public final static int NATURE = 266;
  public final static int NEGATIVE = 89 ;
  public final static int WATER = 264;
  public final static int WIND = 265;

  public static String nameOf(int value) {
    if (value == 86 ) return "VfxImpPulse.COLD";
    if (value == 87 ) return "VfxImpPulse.FIRE";
    if (value == 88 ) return "VfxImpPulse.HOLY";
    if (value == 461) return "VfxImpPulse.HOLY_SILENT";
    if (value == 266) return "VfxImpPulse.NATURE";
    if (value == 89 ) return "VfxImpPulse.NEGATIVE";
    if (value == 264) return "VfxImpPulse.WATER";
    if (value == 265) return "VfxImpPulse.WIND";
    return "VfxImpPulse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpPulse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpPulse.(not found: " + value + ")";
  }
}
