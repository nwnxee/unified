package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_TOWN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundTown {
  private AmbientSoundTown() {}

  public final static int DAY_CROWDED = 17;
  public final static int DAY_SPARSE = 18;
  public final static int NIGHT = 19;

  public static String nameOf(int value) {
    if (value == 17) return "AmbientSoundTown.DAY_CROWDED";
    if (value == 18) return "AmbientSoundTown.DAY_SPARSE";
    if (value == 19) return "AmbientSoundTown.NIGHT";
    return "AmbientSoundTown.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundTown.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundTown.(not found: " + value + ")";
  }
}
