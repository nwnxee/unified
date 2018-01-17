package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_HAUNTED".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundHaunted {
  private AmbientSoundHaunted() {}

  public final static int INTERIOR_1 = 77;
  public final static int INTERIOR_2 = 78;
  public final static int INTERIOR_3 = 79;

  public static String nameOf(int value) {
    if (value == 77) return "AmbientSoundHaunted.INTERIOR_1";
    if (value == 78) return "AmbientSoundHaunted.INTERIOR_2";
    if (value == 79) return "AmbientSoundHaunted.INTERIOR_3";
    return "AmbientSoundHaunted.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundHaunted.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundHaunted.(not found: " + value + ")";
  }
}
