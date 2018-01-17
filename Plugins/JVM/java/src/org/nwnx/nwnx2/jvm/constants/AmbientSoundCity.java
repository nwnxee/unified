package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CITY".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCity {
  private AmbientSoundCity() {}

  public final static int DAY_CROWDED = 12;
  public final static int DAY_SPARSE = 13;
  public final static int MARKET = 15;
  public final static int NIGHT = 14;
  public final static int SLUMS_DAY_CROWDED = 9;
  public final static int SLUMS_DAY_SPARSE = 10;
  public final static int SLUMS_NIGHT = 11;
  public final static int TEMPLE_DISTRICT = 16;

  public static String nameOf(int value) {
    if (value == 12) return "AmbientSoundCity.DAY_CROWDED";
    if (value == 13) return "AmbientSoundCity.DAY_SPARSE";
    if (value == 15) return "AmbientSoundCity.MARKET";
    if (value == 14) return "AmbientSoundCity.NIGHT";
    if (value == 9) return "AmbientSoundCity.SLUMS_DAY_CROWDED";
    if (value == 10) return "AmbientSoundCity.SLUMS_DAY_SPARSE";
    if (value == 11) return "AmbientSoundCity.SLUMS_NIGHT";
    if (value == 16) return "AmbientSoundCity.TEMPLE_DISTRICT";
    return "AmbientSoundCity.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCity.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCity.(not found: " + value + ")";
  }
}
