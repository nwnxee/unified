package org.nwnx.nwnx2.jvm.constants;

/**
 * This class contains all unique constants beginning with "AMBIENT_SOUND_RUIN".
 * Non-distinct keys are filtered; only the LAST appearing was
 * kept.
*/
public final class AmbientSoundRuin {
  private AmbientSoundRuin() {}

  public final static int HAUNTED_XP1 = 98;
  public final static int RUMBLING_XP1 = 97;
  public final static int WET_XP1 = 96;

  public static String nameOf(int value) {
    if (value == 98) return "AmbientSoundRuin.HAUNTED_XP1";
    if (value == 97) return "AmbientSoundRuin.RUMBLING_XP1";
    if (value == 96) return "AmbientSoundRuin.WET_XP1";
    return "AmbientSoundRuin.(not found: " + value + ")";
  }

  public static String nameOf(float value) {
    return "AmbientSoundRuin.(not found: " + value + ")";
  }

  public static String nameOf(String value) {
    return "AmbientSoundRuin.(not found: " + value + ")";
  }
}
