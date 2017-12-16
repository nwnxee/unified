package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_MAGICAL".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundMagical {
  private AmbientSoundMagical() {}

  public final static int INTERIOR_AIRLAB = 88;
  public final static int INTERIOR_EARTHLAB = 87;
  public final static int INTERIOR_FIRELAB = 86;
  public final static int INTERIOR_WATERLAB = 89;

  public static String nameOf(int value) {
    if (value == 88) return "AmbientSoundMagical.INTERIOR_AIRLAB";
    if (value == 87) return "AmbientSoundMagical.INTERIOR_EARTHLAB";
    if (value == 86) return "AmbientSoundMagical.INTERIOR_FIRELAB";
    if (value == 89) return "AmbientSoundMagical.INTERIOR_WATERLAB";
    return "AmbientSoundMagical.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundMagical.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundMagical.(not found: " + value + ")";
  }
}
