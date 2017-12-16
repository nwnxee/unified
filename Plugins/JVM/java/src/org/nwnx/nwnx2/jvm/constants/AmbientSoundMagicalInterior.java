package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_MAGICAL_INTERIOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundMagicalInterior {
  private AmbientSoundMagicalInterior() {}

  public final static int AIRLAB = 88;
  public final static int EARTHLAB = 87;
  public final static int FIRELAB = 86;
  public final static int WATERLAB = 89;

  public static String nameOf(int value) {
    if (value == 88) return "AmbientSoundMagicalInterior.AIRLAB";
    if (value == 87) return "AmbientSoundMagicalInterior.EARTHLAB";
    if (value == 86) return "AmbientSoundMagicalInterior.FIRELAB";
    if (value == 89) return "AmbientSoundMagicalInterior.WATERLAB";
    return "AmbientSoundMagicalInterior.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundMagicalInterior.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundMagicalInterior.(not found: " + value + ")";
  }
}
