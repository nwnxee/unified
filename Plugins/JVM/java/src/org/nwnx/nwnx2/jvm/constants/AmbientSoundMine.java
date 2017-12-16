package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_MINE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundMine {
  private AmbientSoundMine() {}

  public final static int LARGE = 65;
  public final static int MEDIUM = 64;
  public final static int SMALL = 63;

  public static String nameOf(int value) {
    if (value == 65) return "AmbientSoundMine.LARGE";
    if (value == 64) return "AmbientSoundMine.MEDIUM";
    if (value == 63) return "AmbientSoundMine.SMALL";
    return "AmbientSoundMine.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundMine.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundMine.(not found: " + value + ")";
  }
}
