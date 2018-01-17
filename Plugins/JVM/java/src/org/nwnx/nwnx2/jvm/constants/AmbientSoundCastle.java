package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CASTLE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCastle {
  private AmbientSoundCastle() {}

  public final static int INTERIOR_LARGE = 68;
  public final static int INTERIOR_MEDIUM = 67;
  public final static int INTERIOR_SMALL = 66;

  public static String nameOf(int value) {
    if (value == 68) return "AmbientSoundCastle.INTERIOR_LARGE";
    if (value == 67) return "AmbientSoundCastle.INTERIOR_MEDIUM";
    if (value == 66) return "AmbientSoundCastle.INTERIOR_SMALL";
    return "AmbientSoundCastle.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCastle.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCastle.(not found: " + value + ")";
  }
}
