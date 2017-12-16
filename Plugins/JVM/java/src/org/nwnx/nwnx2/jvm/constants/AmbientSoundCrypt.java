package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_CRYPT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCrypt {
  private AmbientSoundCrypt() {}

  public final static int MEDIUM_1 = 70;
  public final static int MEDIUM_2 = 71;
  public final static int SMALL = 69;

  public static String nameOf(int value) {
    if (value == 70) return "AmbientSoundCrypt.MEDIUM_1";
    if (value == 71) return "AmbientSoundCrypt.MEDIUM_2";
    if (value == 69) return "AmbientSoundCrypt.SMALL";
    return "AmbientSoundCrypt.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCrypt.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCrypt.(not found: " + value + ")";
  }
}
