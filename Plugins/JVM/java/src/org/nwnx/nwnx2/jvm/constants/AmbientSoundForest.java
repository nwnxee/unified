package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_FOREST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundForest {
  private AmbientSoundForest() {}

  public final static int DAY_1 = 49;
  public final static int DAY_2 = 50;
  public final static int DAY_3 = 51;
  public final static int DAY_SCARY = 52;
  public final static int MAGICAL = 56;
  public final static int NIGHT_1 = 53;
  public final static int NIGHT_2 = 54;
  public final static int NIGHT_SCARY = 55;

  public static String nameOf(int value) {
    if (value == 49) return "AmbientSoundForest.DAY_1";
    if (value == 50) return "AmbientSoundForest.DAY_2";
    if (value == 51) return "AmbientSoundForest.DAY_3";
    if (value == 52) return "AmbientSoundForest.DAY_SCARY";
    if (value == 56) return "AmbientSoundForest.MAGICAL";
    if (value == 53) return "AmbientSoundForest.NIGHT_1";
    if (value == 54) return "AmbientSoundForest.NIGHT_2";
    if (value == 55) return "AmbientSoundForest.NIGHT_SCARY";
    return "AmbientSoundForest.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundForest.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundForest.(not found: " + value + ")";
  }
}
