package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_WIND".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundWind {
  private AmbientSoundWind() {}

  public final static int FOREST = 33;
  public final static int MEDIUM = 31;
  public final static int SOFT = 30;
  public final static int STRONG = 32;

  public static String nameOf(int value) {
    if (value == 33) return "AmbientSoundWind.FOREST";
    if (value == 31) return "AmbientSoundWind.MEDIUM";
    if (value == 30) return "AmbientSoundWind.SOFT";
    if (value == 32) return "AmbientSoundWind.STRONG";
    return "AmbientSoundWind.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundWind.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundWind.(not found: " + value + ")";
  }
}
