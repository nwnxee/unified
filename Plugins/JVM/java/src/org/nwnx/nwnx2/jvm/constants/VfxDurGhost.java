package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "VFX_DUR_GHOST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class VfxDurGhost {
  private VfxDurGhost() {}

  public final static int SMOKE = 425;
  public final static int SMOKE_2 = 479;
  public final static int TRANSPARENT = 424;

  public static String nameOf(int value) {
    if (value == 425) return "VfxDurGhost.SMOKE";
    if (value == 479) return "VfxDurGhost.SMOKE_2";
    if (value == 424) return "VfxDurGhost.TRANSPARENT";
    return "VfxDurGhost.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "VfxDurGhost.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "VfxDurGhost.(not found: " + value + ")";
  }
}
