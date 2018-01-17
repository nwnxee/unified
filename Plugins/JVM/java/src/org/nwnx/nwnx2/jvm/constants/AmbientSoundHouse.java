package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_HOUSE".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundHouse {
  private AmbientSoundHouse() {}

  public final static int INTERIOR_1 = 72;
  public final static int INTERIOR_2 = 73;
  public final static int INTERIOR_3 = 74;

  public static String nameOf(int value) {
    if (value == 72) return "AmbientSoundHouse.INTERIOR_1";
    if (value == 73) return "AmbientSoundHouse.INTERIOR_2";
    if (value == 74) return "AmbientSoundHouse.INTERIOR_3";
    return "AmbientSoundHouse.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundHouse.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundHouse.(not found: " + value + ")";
  }
}
