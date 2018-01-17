package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CITY_SLUMS".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCitySlums {
  private AmbientSoundCitySlums() {}

  public final static int DAY_CROWDED = 9;
  public final static int DAY_SPARSE = 10;
  public final static int NIGHT = 11;

  public static String nameOf(int value) {
    if (value == 9) return "AmbientSoundCitySlums.DAY_CROWDED";
    if (value == 10) return "AmbientSoundCitySlums.DAY_SPARSE";
    if (value == 11) return "AmbientSoundCitySlums.NIGHT";
    return "AmbientSoundCitySlums.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCitySlums.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCitySlums.(not found: " + value + ")";
  }
}
