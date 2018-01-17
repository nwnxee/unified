package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_IMP_AURA".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxImpAura {
  private VfxImpAura() {}

  public final static int FEAR = 275;
  public final static int HOLY = 273;
  public final static int NEGATIVE_ENERGY = 276;
  public final static int UNEARTHLY = 274;

  public static String nameOf(int value) {
    if (value == 275) return "VfxImpAura.FEAR";
    if (value == 273) return "VfxImpAura.HOLY";
    if (value == 276) return "VfxImpAura.NEGATIVE_ENERGY";
    if (value == 274) return "VfxImpAura.UNEARTHLY";
    return "VfxImpAura.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxImpAura.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxImpAura.(not found: " + value + ")";
  }
}
