package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_MAGIC_INTERIOR".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundMagicInterior {
  private AmbientSoundMagicInterior() {}

  public final static int EVIL = 85;
  public final static int LARGE = 84;
  public final static int MEDIUM = 83;
  public final static int SMALL = 82;

  public static String nameOf(int value) {
    if (value == 85) return "AmbientSoundMagicInterior.EVIL";
    if (value == 84) return "AmbientSoundMagicInterior.LARGE";
    if (value == 83) return "AmbientSoundMagicInterior.MEDIUM";
    if (value == 82) return "AmbientSoundMagicInterior.SMALL";
    return "AmbientSoundMagicInterior.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundMagicInterior.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundMagicInterior.(not found: " + value + ")";
  }
}
