package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CAVE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCave {
  private AmbientSoundCave() {}

  public final static int EVIL_1_XP2 = 104;
  public final static int EVIL_2_XP2 = 105;
  public final static int EVIL_3_XP2 = 106;
  public final static int INSECTS_1 = 42;
  public final static int INSECTS_2 = 43;
  public final static int LARGE = 62;
  public final static int MEDIUM = 61;
  public final static int SMALL = 60;

  public static String nameOf(int value) {
    if (value == 104) return "AmbientSoundCave.EVIL_1_XP2";
    if (value == 105) return "AmbientSoundCave.EVIL_2_XP2";
    if (value == 106) return "AmbientSoundCave.EVIL_3_XP2";
    if (value == 42) return "AmbientSoundCave.INSECTS_1";
    if (value == 43) return "AmbientSoundCave.INSECTS_2";
    if (value == 62) return "AmbientSoundCave.LARGE";
    if (value == 61) return "AmbientSoundCave.MEDIUM";
    if (value == 60) return "AmbientSoundCave.SMALL";
    return "AmbientSoundCave.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCave.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCave.(not found: " + value + ")";
  }
}
