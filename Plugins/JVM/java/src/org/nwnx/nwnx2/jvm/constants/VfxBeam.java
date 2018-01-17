package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_BEAM".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxBeam {
  private VfxBeam() {}

  public final static int BLACK = 485;
  public final static int CHAIN = 484;
  public final static int COLD = 211;
  public final static int DISINTEGRATE = 447;
  public final static int EVIL = 214;
  public final static int FIRE = 210;
  public final static int FIRE_LASH = 216;
  public final static int FIRE_W = 482;
  public final static int FIRE_W_SILENT = 483;
  public final static int HOLY = 212;
  public final static int LIGHTNING = 73 ;
  public final static int MIND = 213;
  public final static int ODD = 215;
  public final static int SILENT_COLD = 309;
  public final static int SILENT_EVIL = 312;
  public final static int SILENT_FIRE = 308;
  public final static int SILENT_HOLY = 310;
  public final static int SILENT_LIGHTNING = 307;
  public final static int SILENT_MIND = 311;
  public final static int SILENT_ODD = 313;

  public static String nameOf(int value) {
    if (value == 485) return "VfxBeam.BLACK";
    if (value == 484) return "VfxBeam.CHAIN";
    if (value == 211) return "VfxBeam.COLD";
    if (value == 447) return "VfxBeam.DISINTEGRATE";
    if (value == 214) return "VfxBeam.EVIL";
    if (value == 210) return "VfxBeam.FIRE";
    if (value == 216) return "VfxBeam.FIRE_LASH";
    if (value == 482) return "VfxBeam.FIRE_W";
    if (value == 483) return "VfxBeam.FIRE_W_SILENT";
    if (value == 212) return "VfxBeam.HOLY";
    if (value == 73 ) return "VfxBeam.LIGHTNING";
    if (value == 213) return "VfxBeam.MIND";
    if (value == 215) return "VfxBeam.ODD";
    if (value == 309) return "VfxBeam.SILENT_COLD";
    if (value == 312) return "VfxBeam.SILENT_EVIL";
    if (value == 308) return "VfxBeam.SILENT_FIRE";
    if (value == 310) return "VfxBeam.SILENT_HOLY";
    if (value == 307) return "VfxBeam.SILENT_LIGHTNING";
    if (value == 311) return "VfxBeam.SILENT_MIND";
    if (value == 313) return "VfxBeam.SILENT_ODD";
    return "VfxBeam.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxBeam.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxBeam.(not found: " + value + ")";
  }
}
