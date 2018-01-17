package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_COMBAT".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundCombat {
  private AmbientSoundCombat() {}

  public final static int MUFFLED_1 = 26;
  public final static int MUFFLED_2 = 27;
  public final static int OUTSIDE_1 = 24;
  public final static int OUTSIDE_2 = 25;

  public static String nameOf(int value) {
    if (value == 26) return "AmbientSoundCombat.MUFFLED_1";
    if (value == 27) return "AmbientSoundCombat.MUFFLED_2";
    if (value == 24) return "AmbientSoundCombat.OUTSIDE_1";
    if (value == 25) return "AmbientSoundCombat.OUTSIDE_2";
    return "AmbientSoundCombat.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundCombat.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundCombat.(not found: " + value + ")";
  }
}
