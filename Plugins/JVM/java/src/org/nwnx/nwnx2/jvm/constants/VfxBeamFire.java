package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_BEAM_FIRE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxBeamFire {
  private VfxBeamFire() {}

  public final static int LASH = 216;
  public final static int VFX_BEAM_FIRE = 210;
  public final static int W = 482;
  public final static int W_SILENT = 483;

  public static String nameOf(int value) {
    if (value == 216) return "VfxBeamFire.LASH";
    if (value == 210) return "VfxBeamFire.VFX_BEAM_FIRE";
    if (value == 482) return "VfxBeamFire.W";
    if (value == 483) return "VfxBeamFire.W_SILENT";
    return "VfxBeamFire.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxBeamFire.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxBeamFire.(not found: " + value + ")";
  }
}
