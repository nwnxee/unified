package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CASTLE_INTERIOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCastleInterior {
  private AmbientSoundCastleInterior() {}

  public final static int LARGE = 68;
  public final static int MEDIUM = 67;
  public final static int SMALL = 66;

  public static String nameOf(int value) {
    if (value == 68) return "AmbientSoundCastleInterior.LARGE";
    if (value == 67) return "AmbientSoundCastleInterior.MEDIUM";
    if (value == 66) return "AmbientSoundCastleInterior.SMALL";
    return "AmbientSoundCastleInterior.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCastleInterior.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCastleInterior.(not found: " + value + ")";
  }
}
