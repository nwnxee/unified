package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_MAGIC".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundMagic {
  private AmbientSoundMagic() {}

  public final static int INTERIOR_EVIL = 85;
  public final static int INTERIOR_LARGE = 84;
  public final static int INTERIOR_MEDIUM = 83;
  public final static int INTERIOR_SMALL = 82;

  public static String nameOf(int value) {
    if (value == 85) return "AmbientSoundMagic.INTERIOR_EVIL";
    if (value == 84) return "AmbientSoundMagic.INTERIOR_LARGE";
    if (value == 83) return "AmbientSoundMagic.INTERIOR_MEDIUM";
    if (value == 82) return "AmbientSoundMagic.INTERIOR_SMALL";
    return "AmbientSoundMagic.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundMagic.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundMagic.(not found: " + value + ")";
  }
}
