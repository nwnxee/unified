package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_BEAM_SILENT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxBeamSilent {
  private VfxBeamSilent() {}

  public final static int COLD = 309;
  public final static int EVIL = 312;
  public final static int FIRE = 308;
  public final static int HOLY = 310;
  public final static int LIGHTNING = 307;
  public final static int MIND = 311;
  public final static int ODD = 313;

  public static String nameOf(int value) {
    if (value == 309) return "VfxBeamSilent.COLD";
    if (value == 312) return "VfxBeamSilent.EVIL";
    if (value == 308) return "VfxBeamSilent.FIRE";
    if (value == 310) return "VfxBeamSilent.HOLY";
    if (value == 307) return "VfxBeamSilent.LIGHTNING";
    if (value == 311) return "VfxBeamSilent.MIND";
    if (value == 313) return "VfxBeamSilent.ODD";
    return "VfxBeamSilent.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxBeamSilent.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxBeamSilent.(not found: " + value + ")";
  }
}
