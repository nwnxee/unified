package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_GUST".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundGust {
  private AmbientSoundGust() {}

  public final static int CAVERN = 35;
  public final static int CHASM = 34;
  public final static int DRAFT = 37;
  public final static int GRASS = 36;

  public static String nameOf(int value) {
    if (value == 35) return "AmbientSoundGust.CAVERN";
    if (value == 34) return "AmbientSoundGust.CHASM";
    if (value == 37) return "AmbientSoundGust.DRAFT";
    if (value == 36) return "AmbientSoundGust.GRASS";
    return "AmbientSoundGust.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundGust.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundGust.(not found: " + value + ")";
  }
}
