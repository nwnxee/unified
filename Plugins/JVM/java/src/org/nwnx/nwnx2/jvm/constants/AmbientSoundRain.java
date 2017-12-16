package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_RAIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundRain {
  private AmbientSoundRain() {}

  public final static int HARD = 39;
  public final static int LIGHT = 38;
  public final static int STORM_BIG = 41;
  public final static int STORM_SMALL = 40;

  public static String nameOf(int value) {
    if (value == 39) return "AmbientSoundRain.HARD";
    if (value == 38) return "AmbientSoundRain.LIGHT";
    if (value == 41) return "AmbientSoundRain.STORM_BIG";
    if (value == 40) return "AmbientSoundRain.STORM_SMALL";
    return "AmbientSoundRain.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundRain.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundRain.(not found: " + value + ")";
  }
}
